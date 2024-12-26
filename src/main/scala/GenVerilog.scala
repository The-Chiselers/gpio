//> using scala "2.13.12"
//> using dep "org.chipsalliance::chisel:6.5.0"
//> using plugin "org.chipsalliance:::chisel-plugin:6.5.0"
//> using options "-unchecked", "-deprecation", "-language:reflectiveCalls", "-feature", "-Xcheckinit", "-Xfatal-warnings", "-Ywarn-dead-code", "-Ymacro-annotations"
package tech.rocksavage.chiselware.Gpio

import _root_.circt.stage.ChiselStage
import _root_.circt.stage.FirtoolOption
// third-party imports
import chisel3._

object Main extends App {

  // ######### Getting Setup #########
  // get build root, if not set use null
  var output = sys.env.get("BUILD_ROOT")
  if (output == null) {
    println("BUILD_ROOT not set, please set and run again")
    System.exit(1)
  }
  // set output directory
  val outputUnwrapped = output.get
  val outputDir = s"$outputUnwrapped/verilog"

  // firtool options for generating verilog
  // val firtoolOpts = Array("-disable-all-randomization", "-strip-debug-info")
  val myParams =
    BaseParams(wordWidth = 8, gpioWidth = 32, PDATA_WIDTH = 32, PADDR_WIDTH = 32, coverage = false)
  // if output dir does not exist, make path
  val javaOutputDir = new java.io.File(outputDir)
  if (!javaOutputDir.exists) javaOutputDir.mkdirs

  val config = Map(
    // name  -> externalRam, dataWidth, fifoDepth
    "8_8_8"      -> BaseParams(gpioWidth = 8,  numVirtualPorts = 8, sizeOfVirtualPorts = 8, wordWidth = 8, PDATA_WIDTH = 32, PADDR_WIDTH = 32),
    "16_8_8"     -> BaseParams(gpioWidth = 16, numVirtualPorts = 8, sizeOfVirtualPorts = 8, wordWidth = 8, PDATA_WIDTH = 32, PADDR_WIDTH = 32),
    "32_8_8"     -> BaseParams(gpioWidth = 32, numVirtualPorts = 8, sizeOfVirtualPorts = 8, wordWidth = 8, PDATA_WIDTH = 32, PADDR_WIDTH = 32),
  )

  // ######### Set Up Top Module HERE #########
  config.foreach { case (testName, param) =>

    println(
      s"Generating Verilog config: $testName\t"
    )

    // Generate basic Verilog (suppress SV features with lowering, etc)
    val top_name = s"${testName}.sv"
    ChiselStage.emitSystemVerilog(
      new Gpio(param),
      firtoolOpts = Array(
        "--lowering-options=disallowLocalVariables,disallowPackedArrays",
        "--disable-all-randomization",
        "--strip-debug-info",
        "--split-verilog",
        s"-o=$outputDir/$testName/",
      ),
    )
  }

  // ##########################################
  System.exit(0)
}
