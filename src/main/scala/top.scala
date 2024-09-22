//> using scala "2.13.12"
//> using dep "org.chipsalliance::chisel:6.5.0"
//> using plugin "org.chipsalliance:::chisel-plugin:6.5.0"
//> using options "-unchecked", "-deprecation", "-language:reflectiveCalls", "-feature", "-Xcheckinit", "-Xfatal-warnings", "-Ywarn-dead-code", "-Ymacro-annotations"


// first-party imports
import com.chisel.ip.FirFilter

import _root_.circt.stage.ChiselStage
import _root_.circt.stage.FirtoolOption
// third-party imports
import chisel3._

object Main extends App {

  // ######### Getting Setup #########
  // setting file output directory
  var output = System.getProperty("output")
  if (output == null) output = "out"
  val outputDir = s"$output/generated"

  // firtool options for generating verilog
  val firtoolOpts = Array("-disable-all-randomization", "-strip-debug-info")

  // if output dir does not exist, make path
  val javaOutputDir = new java.io.File(outputDir)
  if (!javaOutputDir.exists) javaOutputDir.mkdirs

  // ######### Set Up Top Module HERE #########
  val top_name = "FirFilter.sv"
  val verilog = ChiselStage.emitSystemVerilog(
    gen = new FirFilter(8, Seq(1.U, 1.U, 3.U)),
    firtoolOpts = firtoolOpts,
  )
  // ##########################################

  // print verilog to console
  println(verilog)

  // write verilog to file
  val writer = new java.io.PrintWriter(new java.io.File(s"$outputDir/$top_name"))
  writer.write(verilog)

  // close writer
  writer.close()

  // exit
  System.exit(0)
}
