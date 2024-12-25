package tech.rocksavage.chiselware.Gpio

import java.io.{File, PrintWriter}
import scala.collection.mutable
import firrtl2.AnnotationSeq
import firrtl2.annotations.Annotation // Correct Annotation type for firrtl2
import firrtl2.options.TargetDirAnnotation
import TestUtils.checkCoverage
import TestUtils.randData
import chisel3._
import chisel3.util._
import chiseltest._
import chiseltest.coverage._
import chiseltest.simulator._

object coverageCollector {
  private val cumulativeCoverage: mutable.Map[String, BigInt] = mutable.Map()

  def collectCoverage(
      cov: Seq[Annotation],
      myParams: BaseParams,
      testName: String
  ): Unit = {
    if (myParams.coverage) {
      // Convert coverage counts to BigInt to match expected types and ensure it's a Map
      val coverage: Map[String, BigInt] = cov
        .collectFirst { case a: TestCoverage => a.counts }
        .getOrElse(Map.empty)
        .map { case (key, value) => key -> BigInt(value) }
        .toMap // Ensure the result is a Map

      // Merge the test coverage into the cumulative coverage
      for ((key, value) <- coverage) {
        cumulativeCoverage.update(key, cumulativeCoverage.getOrElse(key, BigInt(0)) + value)
      }

      val testConfig =
        s"${myParams.gpioWidth}_${myParams.PDATA_WIDTH}_${myParams.PADDR_WIDTH}"

      val buildRoot = sys.env.get("BUILD_ROOT")
      if (buildRoot.isEmpty) {
        println("BUILD_ROOT not set, please set and run again")
        System.exit(1)
      }

      val verCoverageDir = new File(s"${buildRoot.get}/cov/verilog")
      verCoverageDir.mkdirs()
      val coverageFile = s"$verCoverageDir/${testName}_$testConfig.cov"

      // Save individual test coverage
      saveCoverageToFile(coverage, coverageFile)

      val stuckAtFault = checkCoverage(coverage, coverageFile)
      if (stuckAtFault) {
        println(
          s"WARNING: At least one IO port did not toggle -- see $coverageFile"
        )
      }
      info(s"Verilog Coverage report written to $coverageFile")
    }
  }

  def saveCumulativeCoverage(myParams: BaseParams): Unit = {
    if (myParams.coverage) {
      val buildRoot = sys.env.get("BUILD_ROOT")
      if (buildRoot.isEmpty) {
        println("BUILD_ROOT not set, please set and run again")
        System.exit(1)
      }

      val verCoverageDir = new File(s"${buildRoot.get}/cov/verilog")
      verCoverageDir.mkdirs()
      val cumulativeFile = s"$verCoverageDir/cumulative_coverage.cov"

      // Write the cumulative coverage to a file
      saveCoverageToFile(cumulativeCoverage.toMap, cumulativeFile)
      info(s"Cumulative coverage report written to $cumulativeFile")
    }
  }

  private def saveCoverageToFile(coverage: Map[String, BigInt], filePath: String): Unit = {
    val writer = new PrintWriter(new File(filePath))
    try {
      for ((key, value) <- coverage) {
        writer.println(s"$key: $value")
      }
    } finally {
      writer.close()
    }
  }

  private def info(message: String): Unit = {
    println(message)
  }

  private def checkCoverage(coverage: Map[String, BigInt], filePath: String): Boolean = {
    // Stub: Implement your logic to check for stuck-at faults in coverage
    false
  }
}


