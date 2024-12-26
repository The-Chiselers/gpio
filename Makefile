MAKEFLAGS += --silent
	
SBT = sbt

# The Following Vars are set by the development flake:
# - BUILD_ROOT_RELATIVE
# - BUILD_ROOT
# - PROJECT_ROOT
# - FIRTOOL_REV

	
# Run everything and scan for errors
# list:
# 	@grep '^[^#[:space:]].*:' Makefile

# all: clean publish docs cov yosys check

# Validates the environment to see if it is possible to run
validate: 
	@if [ -z $(BUILD_ROOT) ]; then echo "BUILD_ROOT is not set"; exit 1; fi
	@if [ -z $(PROJECT_ROOT) ]; then echo "PROJECT_ROOT is not set"; exit 1; fi
	@if [ -z $(TOP) ]; then echo "TOP is not set"; exit 1; fi
	@if [ -z $(FIRTOOL_REV) ]; then echo "FIRTOOL_REV is not set"; exit 1; fi

# check: 
# 	@echo 
# 	@echo Checking for errors
# 	grep error */*.rpt */*/*/*.rpt */*/*/*.log | tee error.rpt
# 	grep Error */*.rpt */*/*/*.rpt */*/*/*.log | tee -a error.rpt
# 	grep fail */*.rpt */*/*/*.rpt */*/*/*.log | grep -v "failed 0" | tee -a error.rpt
# 	@echo; 
# 	if [ ! -s error.rpt ]; \
# 	then echo "\e[1;32mALL TESTS PASSED WITH NO ERRORS \e[0m"; \
# 	else echo "\e[1;31mTESTS COMPLETED WITH ERRORS \e[0m"; \
# 	fi; 
# 	@echo

# Start with a fresh directory
clean: 
	@echo Cleaning
	rm -rf generated target *anno.json ./*.rpt doc/*.rpt syn/*.rpt syn.log out test_run_dir
	rm -rf project/build.properties project/project project/target
	
	# filter all files with bad extensions:
	find . -type f -name "*.aux" -delete
	find . -type f -name "*.toc" -delete
	find . -type f -name "*.out" -delete
	find . -type f -name "*.log" -delete
	find . -type f -name "*.fdb_latexmk" -delete
	find . -type f -name "*.fls" -delete
	find . -type f -name "*.synctex.gz" -delete
	find . -type f -name "*.pdf" -delete

# Publish the documentation (locally)
# publish: 
# 	@echo Publishing local
# 	rm -rf /home/tws/.ivy2/local/tech.rocksavage/$(TOP)_2.13
# 	$(SBT) "publishLocal" | tee doc/publish.rpt

wavedrom_diag:
	@echo Generating wavedrom diagrams
	wavedrom-cli --input doc/user-guide/wavedrom/timing.json --svg out/doc/timing.svg

# Generate the documentation
docs: validate
	@echo Generating docs
	mkdir -p $(BUILD_ROOT)/doc
	cd doc/user-guide && pdflatex -output-directory=$(BUILD_ROOT)/doc $(TOP).tex | tee -a $(BUILD_ROOT)/doc/doc.rpt

# Generate Verilog and synthesize
verilog: validate
	@echo Generate Verilog for synthesis
	mkdir -p $(BUILD_ROOT)/verilog
	$(SBT) "run" | tee $(BUILD_ROOT)/verilog/verilog.rpt
	# grep -r -l "Generated by CIRCT unknown git version" | grep ".sv" | xargs sed -i 's/Generated by CIRCT unknown git version/Generated by CIRCT firtool-$(FIRTOOL_VER), rev: $(FIRTOOL_REV)/g'
	rm -f *.anno.json

# Run the tests
test: validate
	@echo Running tests
	mkdir -p $(BUILD_ROOT)/test
	mkdir -p $(BUILD_ROOT)/cov/verilog
	mkdir -p $(BUILD_ROOT)/cov/scala
	$(SBT) -DtestName="allTests" -DuseVerilator="true" test | tee $(BUILD_ROOT)/test/test.rpt

# Run the tests with Scala code coverage enables
cov: validate
	@echo Running tests with coverage enabled
	mkdir -p $(BUILD_ROOT)/test
	mkdir -p $(BUILD_ROOT)/cov/scala
	mkdir -p $(BUILD_ROOT)/cov/verilog
	$(SBT) clean \
	coverageOn \
	test \
	"runMain tech.rocksavage.chiselware.$(TOP).GenVerilog" \
	"runMain tech.rocksavage.chiselware.$(TOP).Main" \
	coverageReport | tee $(BUILD_ROOT)/cov/scala/test.rpt
	google-chrome --new-window $(BUILD_ROOT)/cov/scala/scoverage-report/index.html &

# Synthesize the design
synth: verilog
	@echo Synthesizing
	sh $(PROJECT_ROOT)/synth/synth.sh

# Generate timing analysis
#sta: synth
sta:
	# Uses a python script to generate the SDC file
	mkdir -p $(BUILD_ROOT)/sta
	sh $(PROJECT_ROOT)/synth/sta.sh

