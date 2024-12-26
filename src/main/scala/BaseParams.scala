// (c) 2024 Rocksavage Technology, Inc.
// This code is licensed under the Apache Software License 2.0 (see LICENSE.MD)

package tech.rocksavage.chiselware.Gpio

import chisel3._
import chisel3.util._

/** Default parameter settings for Dynamic FIFO
  *
  * @constructor
  *   default parameter settings
  * @param dataWidth
  *
  * specifies the width of the FIFO data
  * @param fifoDepth
  *   specifices the depth of the FIFO
  * @param externalRam
  *   specifies whether to use an external SRAM or generate internal FFs
  * @param coverage
  *   specifies whether to calculate port coverage during simulation
  * @author
  *   Warren Savage
  * @version 1.0
  *
  * @see
  *   [[http://www.rocksavage.tech]] for more information
  */
case class BaseParams(
    wordWidth: Int = 8,
    gpioWidth: Int = 32,
    PDATA_WIDTH: Int = 32,
    PADDR_WIDTH: Int = 32,
    numVirtualPorts: Int = 8,
    sizeOfVirtualPorts: Int = log2Ceil(32),
    coverage: Boolean = false,
    verbose: Boolean = true
) {

  require(wordWidth == 8, "wordWidth must be 8")
  require(
    PDATA_WIDTH == 8 || PDATA_WIDTH == 16 || PDATA_WIDTH == 32,
    "PDATA_WIDTH must be 8, 16, or 32"
  )
  require(
    gpioWidth <= PDATA_WIDTH,
    "gpioWidth must be less than or equal to PDATA_WIDTH"
  )
  require(PADDR_WIDTH <= 32, "PADDR_WIDTH must be less than or equal to 32")
}
