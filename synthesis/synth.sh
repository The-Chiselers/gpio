
#!/bin/sh

set -e
if [ ! -e synthesis ]; then 
    rm synthesis/synth.ys
fi

touch synthesis/synth.ys
echo "read -sv generated/GPIO.sv" > synthesis/synth.ys
echo "synth" >> synthesis/synth.ys
echo "write_verilog synthesis/GPIO.v" >> synthesis/synth.ys

yosys synthesis/synth.ys
