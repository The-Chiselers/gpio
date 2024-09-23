FIRRTL version 1.2.0
circuit GPIO :
  module GPIO :
    input clock : Clock
    input reset : UInt<1>
    input io_apb_PSEL : UInt<1> @[src/main/scala/GPIO.scala 11:14]
    input io_apb_PENABLE : UInt<1> @[src/main/scala/GPIO.scala 11:14]
    input io_apb_PWRITE : UInt<1> @[src/main/scala/GPIO.scala 11:14]
    input io_apb_PADDR : UInt<32> @[src/main/scala/GPIO.scala 11:14]
    input io_apb_PWDATA : UInt<32> @[src/main/scala/GPIO.scala 11:14]
    output io_apb_PRDATA : UInt<32> @[src/main/scala/GPIO.scala 11:14]
    output io_apb_PREADY : UInt<1> @[src/main/scala/GPIO.scala 11:14]
    output io_apb_PSLVERR : UInt<1> @[src/main/scala/GPIO.scala 11:14]
    input io_pins_GPIO_I : UInt<32> @[src/main/scala/GPIO.scala 11:14]
    output io_pins_GPIO_O : UInt<32> @[src/main/scala/GPIO.scala 11:14]
    output io_pins_GPIO_OE : UInt<32> @[src/main/scala/GPIO.scala 11:14]

    reg DIRECTION : UInt<32>, clock with :
      reset => (UInt<1>("h0"), DIRECTION) @[src/main/scala/GPIO.scala 21:26]
    reg OUTPUT : UInt<32>, clock with :
      reset => (UInt<1>("h0"), OUTPUT) @[src/main/scala/GPIO.scala 22:23]
    reg INPUT : UInt<32>, clock with :
      reset => (UInt<1>("h0"), INPUT) @[src/main/scala/GPIO.scala 23:22]
    node _T = and(io_apb_PSEL, io_apb_PENABLE) @[src/main/scala/GPIO.scala 26:20]
    node _T_1 = eq(UInt<1>("h0"), io_apb_PADDR) @[src/main/scala/GPIO.scala 28:28]
    node _T_2 = eq(UInt<3>("h4"), io_apb_PADDR) @[src/main/scala/GPIO.scala 28:28]
    node _GEN_0 = mux(_T_2, io_apb_PWDATA, DIRECTION) @[src/main/scala/GPIO.scala 28:28 33:21 21:26]
    node _GEN_1 = mux(_T_1, io_apb_PWDATA, OUTPUT) @[src/main/scala/GPIO.scala 28:28 30:18 22:23]
    node _GEN_2 = mux(_T_1, DIRECTION, _GEN_0) @[src/main/scala/GPIO.scala 21:26 28:28]
    node _T_3 = eq(UInt<1>("h0"), io_apb_PADDR) @[src/main/scala/GPIO.scala 38:28]
    node _T_4 = eq(UInt<3>("h4"), io_apb_PADDR) @[src/main/scala/GPIO.scala 38:28]
    node _T_5 = eq(UInt<4>("h8"), io_apb_PADDR) @[src/main/scala/GPIO.scala 38:28]
    node _GEN_3 = mux(_T_5, INPUT, UInt<1>("h0")) @[src/main/scala/GPIO.scala 25:17 38:28 46:25]
    node _GEN_4 = mux(_T_4, DIRECTION, _GEN_3) @[src/main/scala/GPIO.scala 38:28 43:25]
    node _GEN_5 = mux(_T_3, OUTPUT, _GEN_4) @[src/main/scala/GPIO.scala 38:28 40:25]
    node _GEN_6 = mux(io_apb_PWRITE, _GEN_1, OUTPUT) @[src/main/scala/GPIO.scala 22:23 27:25]
    node _GEN_7 = mux(io_apb_PWRITE, _GEN_2, DIRECTION) @[src/main/scala/GPIO.scala 27:25 21:26]
    node _GEN_8 = mux(io_apb_PWRITE, UInt<1>("h1"), UInt<1>("h1")) @[src/main/scala/GPIO.scala 27:25 36:21 49:21]
    node _GEN_9 = mux(io_apb_PWRITE, UInt<1>("h0"), _GEN_5) @[src/main/scala/GPIO.scala 25:17 27:25]
    node _GEN_10 = mux(_T, _GEN_6, OUTPUT) @[src/main/scala/GPIO.scala 22:23 26:39]
    node _GEN_11 = mux(_T, _GEN_7, DIRECTION) @[src/main/scala/GPIO.scala 21:26 26:39]
    node _GEN_12 = mux(_T, _GEN_8, UInt<1>("h0")) @[src/main/scala/GPIO.scala 26:39 52:19]
    node _GEN_13 = mux(_T, _GEN_9, UInt<1>("h0")) @[src/main/scala/GPIO.scala 25:17 26:39]
    node _io_pins_GPIO_O_T = and(OUTPUT, DIRECTION) @[src/main/scala/GPIO.scala 55:28]
    node _T_6 = neq(io_apb_PADDR, UInt<1>("h0")) @[src/main/scala/GPIO.scala 60:21]
    node _T_7 = neq(io_apb_PADDR, UInt<3>("h4")) @[src/main/scala/GPIO.scala 60:45]
    node _T_8 = and(_T_6, _T_7) @[src/main/scala/GPIO.scala 60:29]
    node _T_9 = neq(io_apb_PADDR, UInt<4>("h8")) @[src/main/scala/GPIO.scala 60:69]
    node _T_10 = and(_T_8, _T_9) @[src/main/scala/GPIO.scala 60:53]
    node _GEN_14 = mux(_T_10, UInt<1>("h1"), UInt<1>("h0")) @[src/main/scala/GPIO.scala 60:78 61:20 63:20]
    io_apb_PRDATA <= _GEN_13
    io_apb_PREADY <= _GEN_12
    io_apb_PSLVERR <= _GEN_14
    io_pins_GPIO_O <= _io_pins_GPIO_O_T @[src/main/scala/GPIO.scala 55:18]
    io_pins_GPIO_OE <= DIRECTION @[src/main/scala/GPIO.scala 56:19]
    DIRECTION <= mux(reset, UInt<32>("h0"), _GEN_11) @[src/main/scala/GPIO.scala 21:{26,26}]
    OUTPUT <= mux(reset, UInt<32>("h0"), _GEN_10) @[src/main/scala/GPIO.scala 22:{23,23}]
    INPUT <= mux(reset, UInt<32>("h0"), io_pins_GPIO_I) @[src/main/scala/GPIO.scala 23:{22,22} 57:9]
