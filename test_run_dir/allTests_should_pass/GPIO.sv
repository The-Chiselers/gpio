module GPIO(
  input         clock,
  input         reset,
  input         io_apb_PSEL, // @[src/main/scala/GPIO.scala 13:14]
  input         io_apb_PENABLE, // @[src/main/scala/GPIO.scala 13:14]
  input         io_apb_PWRITE, // @[src/main/scala/GPIO.scala 13:14]
  input  [7:0]  io_apb_PADDR, // @[src/main/scala/GPIO.scala 13:14]
  input  [15:0] io_apb_PWDATA, // @[src/main/scala/GPIO.scala 13:14]
  output [15:0] io_apb_PRDATA, // @[src/main/scala/GPIO.scala 13:14]
  output        io_apb_PREADY, // @[src/main/scala/GPIO.scala 13:14]
  output        io_apb_PSLVERR, // @[src/main/scala/GPIO.scala 13:14]
  input  [15:0] io_pins_gpioInput, // @[src/main/scala/GPIO.scala 13:14]
  output [15:0] io_pins_gpioOutput, // @[src/main/scala/GPIO.scala 13:14]
  output [15:0] io_pins_gpioOutputEnable, // @[src/main/scala/GPIO.scala 13:14]
  output        io_pins_irqOutput // @[src/main/scala/GPIO.scala 13:14]
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
  reg [31:0] _RAND_15;
  reg [31:0] _RAND_16;
  reg [31:0] _RAND_17;
  reg [31:0] _RAND_18;
  reg [31:0] _RAND_19;
  reg [31:0] _RAND_20;
  reg [31:0] _RAND_21;
  reg [31:0] _RAND_22;
  reg [31:0] _RAND_23;
  reg [31:0] _RAND_24;
`endif // RANDOMIZE_REG_INIT
  reg [15:0] regs_DIRECTION; // @[src/main/scala/GPIORegs.scala 34:26]
  reg [15:0] regs_OUTPUT; // @[src/main/scala/GPIORegs.scala 35:23]
  reg [15:0] regs_INPUT; // @[src/main/scala/GPIORegs.scala 36:22]
  reg [15:0] regs_MODE; // @[src/main/scala/GPIORegs.scala 37:21]
  reg [3:0] regs_ATOMIC_OPERATION; // @[src/main/scala/GPIORegs.scala 40:33]
  reg [15:0] regs_ATOMIC_MASK; // @[src/main/scala/GPIORegs.scala 41:28]
  reg  regs_ATOMIC_SET; // @[src/main/scala/GPIORegs.scala 42:27]
  reg [7:0] regs_virtualPortOutput; // @[src/main/scala/GPIORegs.scala 45:34]
  reg [4:0] regs_virtualToPhysicalMap_0; // @[src/main/scala/GPIORegs.scala 48:12]
  reg [4:0] regs_virtualToPhysicalMap_1; // @[src/main/scala/GPIORegs.scala 48:12]
  reg [4:0] regs_virtualToPhysicalMap_2; // @[src/main/scala/GPIORegs.scala 48:12]
  reg [4:0] regs_virtualToPhysicalMap_3; // @[src/main/scala/GPIORegs.scala 48:12]
  reg [4:0] regs_virtualToPhysicalMap_4; // @[src/main/scala/GPIORegs.scala 48:12]
  reg [4:0] regs_virtualToPhysicalMap_5; // @[src/main/scala/GPIORegs.scala 48:12]
  reg [4:0] regs_virtualToPhysicalMap_6; // @[src/main/scala/GPIORegs.scala 48:12]
  reg [4:0] regs_virtualToPhysicalMap_7; // @[src/main/scala/GPIORegs.scala 48:12]
  reg  regs_virtualPortEnable; // @[src/main/scala/GPIORegs.scala 52:34]
  reg [15:0] regs_TRIGGER_TYPE; // @[src/main/scala/GPIORegs.scala 55:29]
  reg [15:0] regs_TRIGGER_LO; // @[src/main/scala/GPIORegs.scala 56:27]
  reg [15:0] regs_TRIGGER_HI; // @[src/main/scala/GPIORegs.scala 57:27]
  reg [15:0] regs_TRIGGER_STATUS; // @[src/main/scala/GPIORegs.scala 58:31]
  reg [15:0] regs_IRQ_ENABLE; // @[src/main/scala/GPIORegs.scala 59:27]
  reg [15:0] gpioInputSyncPrev; // @[src/main/scala/GPIO.scala 29:34]
  reg [15:0] gpioInputSync_REG; // @[src/main/scala/GPIO.scala 31:38]
  reg [15:0] gpioInputSync; // @[src/main/scala/GPIO.scala 31:30]
  wire [15:0] _OUTPUT_T_1 = regs_OUTPUT | 16'h1; // @[src/main/scala/GPIO.scala 40:40]
  wire [15:0] _OUTPUT_T_4 = regs_OUTPUT & 16'h2; // @[src/main/scala/GPIO.scala 41:50]
  wire [15:0] _GEN_0 = regs_virtualPortOutput[7] ? _OUTPUT_T_1 : _OUTPUT_T_4; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _virtualPortOutput_T_1 = regs_virtualPortOutput | 8'h80; // @[src/main/scala/GPIO.scala 44:62]
  wire [7:0] _virtualPortOutput_T_4 = regs_virtualPortOutput & 8'h7f; // @[src/main/scala/GPIO.scala 46:62]
  wire [7:0] _GEN_1 = regs_INPUT[0] ? _virtualPortOutput_T_1 : _virtualPortOutput_T_4; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_2 = regs_DIRECTION[0] ? _GEN_0 : regs_OUTPUT; // @[src/main/scala/GPIO.scala 38:41 src/main/scala/GPIORegs.scala 35:23]
  wire [7:0] _GEN_3 = regs_DIRECTION[0] ? regs_virtualPortOutput : _GEN_1; // @[src/main/scala/GPIO.scala 38:41 src/main/scala/GPIORegs.scala 45:34]
  wire [15:0] _GEN_4 = regs_virtualToPhysicalMap_7 == 5'h0 ? _GEN_2 : regs_OUTPUT; // @[src/main/scala/GPIO.scala 36:50 src/main/scala/GPIORegs.scala 35:23]
  wire [7:0] _GEN_5 = regs_virtualToPhysicalMap_7 == 5'h0 ? _GEN_3 : regs_virtualPortOutput; // @[src/main/scala/GPIO.scala 36:50 src/main/scala/GPIORegs.scala 45:34]
  wire [15:0] _GEN_6 = regs_virtualPortOutput[6] ? _OUTPUT_T_1 : _OUTPUT_T_4; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _virtualPortOutput_T_6 = regs_virtualPortOutput | 8'h40; // @[src/main/scala/GPIO.scala 44:62]
  wire [7:0] _virtualPortOutput_T_9 = regs_virtualPortOutput & 8'h3f; // @[src/main/scala/GPIO.scala 46:62]
  wire [7:0] _GEN_7 = regs_INPUT[0] ? _virtualPortOutput_T_6 : _virtualPortOutput_T_9; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_8 = regs_DIRECTION[0] ? _GEN_6 : _GEN_4; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_9 = regs_DIRECTION[0] ? _GEN_5 : _GEN_7; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_10 = regs_virtualToPhysicalMap_6 == 5'h0 ? _GEN_8 : _GEN_4; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_11 = regs_virtualToPhysicalMap_6 == 5'h0 ? _GEN_9 : _GEN_5; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_12 = regs_virtualPortOutput[5] ? _OUTPUT_T_1 : _OUTPUT_T_4; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _virtualPortOutput_T_11 = regs_virtualPortOutput | 8'h20; // @[src/main/scala/GPIO.scala 44:62]
  wire [7:0] _virtualPortOutput_T_14 = regs_virtualPortOutput & 8'h1f; // @[src/main/scala/GPIO.scala 46:62]
  wire [7:0] _GEN_13 = regs_INPUT[0] ? _virtualPortOutput_T_11 : _virtualPortOutput_T_14; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_14 = regs_DIRECTION[0] ? _GEN_12 : _GEN_10; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_15 = regs_DIRECTION[0] ? _GEN_11 : _GEN_13; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_16 = regs_virtualToPhysicalMap_5 == 5'h0 ? _GEN_14 : _GEN_10; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_17 = regs_virtualToPhysicalMap_5 == 5'h0 ? _GEN_15 : _GEN_11; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_18 = regs_virtualPortOutput[4] ? _OUTPUT_T_1 : _OUTPUT_T_4; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _virtualPortOutput_T_16 = regs_virtualPortOutput | 8'h10; // @[src/main/scala/GPIO.scala 44:62]
  wire [7:0] _virtualPortOutput_T_19 = regs_virtualPortOutput & 8'hf; // @[src/main/scala/GPIO.scala 46:62]
  wire [7:0] _GEN_19 = regs_INPUT[0] ? _virtualPortOutput_T_16 : _virtualPortOutput_T_19; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_20 = regs_DIRECTION[0] ? _GEN_18 : _GEN_16; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_21 = regs_DIRECTION[0] ? _GEN_17 : _GEN_19; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_22 = regs_virtualToPhysicalMap_4 == 5'h0 ? _GEN_20 : _GEN_16; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_23 = regs_virtualToPhysicalMap_4 == 5'h0 ? _GEN_21 : _GEN_17; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_24 = regs_virtualPortOutput[3] ? _OUTPUT_T_1 : _OUTPUT_T_4; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _virtualPortOutput_T_21 = regs_virtualPortOutput | 8'h8; // @[src/main/scala/GPIO.scala 44:62]
  wire [7:0] _virtualPortOutput_T_24 = regs_virtualPortOutput & 8'h7; // @[src/main/scala/GPIO.scala 46:62]
  wire [7:0] _GEN_25 = regs_INPUT[0] ? _virtualPortOutput_T_21 : _virtualPortOutput_T_24; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_26 = regs_DIRECTION[0] ? _GEN_24 : _GEN_22; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_27 = regs_DIRECTION[0] ? _GEN_23 : _GEN_25; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_28 = regs_virtualToPhysicalMap_3 == 5'h0 ? _GEN_26 : _GEN_22; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_29 = regs_virtualToPhysicalMap_3 == 5'h0 ? _GEN_27 : _GEN_23; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_30 = regs_virtualPortOutput[2] ? _OUTPUT_T_1 : _OUTPUT_T_4; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _virtualPortOutput_T_26 = regs_virtualPortOutput | 8'h4; // @[src/main/scala/GPIO.scala 44:62]
  wire [7:0] _virtualPortOutput_T_29 = regs_virtualPortOutput & 8'h3; // @[src/main/scala/GPIO.scala 46:62]
  wire [7:0] _GEN_31 = regs_INPUT[0] ? _virtualPortOutput_T_26 : _virtualPortOutput_T_29; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_32 = regs_DIRECTION[0] ? _GEN_30 : _GEN_28; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_33 = regs_DIRECTION[0] ? _GEN_29 : _GEN_31; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_34 = regs_virtualToPhysicalMap_2 == 5'h0 ? _GEN_32 : _GEN_28; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_35 = regs_virtualToPhysicalMap_2 == 5'h0 ? _GEN_33 : _GEN_29; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_36 = regs_virtualPortOutput[1] ? _OUTPUT_T_1 : _OUTPUT_T_4; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _virtualPortOutput_T_31 = regs_virtualPortOutput | 8'h2; // @[src/main/scala/GPIO.scala 44:62]
  wire [7:0] _virtualPortOutput_T_34 = regs_virtualPortOutput & 8'h1; // @[src/main/scala/GPIO.scala 46:62]
  wire [7:0] _GEN_37 = regs_INPUT[0] ? _virtualPortOutput_T_31 : _virtualPortOutput_T_34; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_38 = regs_DIRECTION[0] ? _GEN_36 : _GEN_34; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_39 = regs_DIRECTION[0] ? _GEN_35 : _GEN_37; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_40 = regs_virtualToPhysicalMap_1 == 5'h0 ? _GEN_38 : _GEN_34; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_41 = regs_virtualToPhysicalMap_1 == 5'h0 ? _GEN_39 : _GEN_35; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_42 = regs_virtualPortOutput[0] ? _OUTPUT_T_1 : _OUTPUT_T_4; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _virtualPortOutput_T_36 = regs_virtualPortOutput | 8'h1; // @[src/main/scala/GPIO.scala 44:62]
  wire [7:0] _GEN_43 = regs_INPUT[0] ? _virtualPortOutput_T_36 : 8'h0; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_44 = regs_DIRECTION[0] ? _GEN_42 : _GEN_40; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_45 = regs_DIRECTION[0] ? _GEN_41 : _GEN_43; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_46 = regs_virtualToPhysicalMap_0 == 5'h0 ? _GEN_44 : _GEN_40; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_47 = regs_virtualToPhysicalMap_0 == 5'h0 ? _GEN_45 : _GEN_41; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_48 = regs_virtualPortEnable ? _GEN_46 : regs_OUTPUT; // @[src/main/scala/GPIO.scala 34:71 src/main/scala/GPIORegs.scala 35:23]
  wire [7:0] _GEN_49 = regs_virtualPortEnable ? _GEN_47 : regs_virtualPortOutput; // @[src/main/scala/GPIO.scala 34:71 src/main/scala/GPIORegs.scala 45:34]
  wire [15:0] _OUTPUT_T_41 = regs_OUTPUT | 16'h2; // @[src/main/scala/GPIO.scala 40:40]
  wire [15:0] _OUTPUT_T_44 = regs_OUTPUT & 16'h1; // @[src/main/scala/GPIO.scala 41:50]
  wire [15:0] _GEN_50 = regs_virtualPortOutput[7] ? _OUTPUT_T_41 : _OUTPUT_T_44; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_51 = regs_INPUT[1] ? _virtualPortOutput_T_1 : _virtualPortOutput_T_4; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_52 = regs_DIRECTION[1] ? _GEN_50 : _GEN_48; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_53 = regs_DIRECTION[1] ? _GEN_49 : _GEN_51; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_54 = regs_virtualToPhysicalMap_7 == 5'h1 ? _GEN_52 : _GEN_48; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_55 = regs_virtualToPhysicalMap_7 == 5'h1 ? _GEN_53 : _GEN_49; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_56 = regs_virtualPortOutput[6] ? _OUTPUT_T_41 : _OUTPUT_T_44; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_57 = regs_INPUT[1] ? _virtualPortOutput_T_6 : _virtualPortOutput_T_9; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_58 = regs_DIRECTION[1] ? _GEN_56 : _GEN_54; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_59 = regs_DIRECTION[1] ? _GEN_55 : _GEN_57; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_60 = regs_virtualToPhysicalMap_6 == 5'h1 ? _GEN_58 : _GEN_54; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_61 = regs_virtualToPhysicalMap_6 == 5'h1 ? _GEN_59 : _GEN_55; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_62 = regs_virtualPortOutput[5] ? _OUTPUT_T_41 : _OUTPUT_T_44; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_63 = regs_INPUT[1] ? _virtualPortOutput_T_11 : _virtualPortOutput_T_14; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_64 = regs_DIRECTION[1] ? _GEN_62 : _GEN_60; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_65 = regs_DIRECTION[1] ? _GEN_61 : _GEN_63; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_66 = regs_virtualToPhysicalMap_5 == 5'h1 ? _GEN_64 : _GEN_60; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_67 = regs_virtualToPhysicalMap_5 == 5'h1 ? _GEN_65 : _GEN_61; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_68 = regs_virtualPortOutput[4] ? _OUTPUT_T_41 : _OUTPUT_T_44; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_69 = regs_INPUT[1] ? _virtualPortOutput_T_16 : _virtualPortOutput_T_19; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_70 = regs_DIRECTION[1] ? _GEN_68 : _GEN_66; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_71 = regs_DIRECTION[1] ? _GEN_67 : _GEN_69; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_72 = regs_virtualToPhysicalMap_4 == 5'h1 ? _GEN_70 : _GEN_66; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_73 = regs_virtualToPhysicalMap_4 == 5'h1 ? _GEN_71 : _GEN_67; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_74 = regs_virtualPortOutput[3] ? _OUTPUT_T_41 : _OUTPUT_T_44; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_75 = regs_INPUT[1] ? _virtualPortOutput_T_21 : _virtualPortOutput_T_24; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_76 = regs_DIRECTION[1] ? _GEN_74 : _GEN_72; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_77 = regs_DIRECTION[1] ? _GEN_73 : _GEN_75; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_78 = regs_virtualToPhysicalMap_3 == 5'h1 ? _GEN_76 : _GEN_72; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_79 = regs_virtualToPhysicalMap_3 == 5'h1 ? _GEN_77 : _GEN_73; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_80 = regs_virtualPortOutput[2] ? _OUTPUT_T_41 : _OUTPUT_T_44; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_81 = regs_INPUT[1] ? _virtualPortOutput_T_26 : _virtualPortOutput_T_29; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_82 = regs_DIRECTION[1] ? _GEN_80 : _GEN_78; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_83 = regs_DIRECTION[1] ? _GEN_79 : _GEN_81; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_84 = regs_virtualToPhysicalMap_2 == 5'h1 ? _GEN_82 : _GEN_78; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_85 = regs_virtualToPhysicalMap_2 == 5'h1 ? _GEN_83 : _GEN_79; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_86 = regs_virtualPortOutput[1] ? _OUTPUT_T_41 : _OUTPUT_T_44; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_87 = regs_INPUT[1] ? _virtualPortOutput_T_31 : _virtualPortOutput_T_34; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_88 = regs_DIRECTION[1] ? _GEN_86 : _GEN_84; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_89 = regs_DIRECTION[1] ? _GEN_85 : _GEN_87; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_90 = regs_virtualToPhysicalMap_1 == 5'h1 ? _GEN_88 : _GEN_84; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_91 = regs_virtualToPhysicalMap_1 == 5'h1 ? _GEN_89 : _GEN_85; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_92 = regs_virtualPortOutput[0] ? _OUTPUT_T_41 : _OUTPUT_T_44; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_93 = regs_INPUT[1] ? _virtualPortOutput_T_36 : 8'h0; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_94 = regs_DIRECTION[1] ? _GEN_92 : _GEN_90; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_95 = regs_DIRECTION[1] ? _GEN_91 : _GEN_93; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_96 = regs_virtualToPhysicalMap_0 == 5'h1 ? _GEN_94 : _GEN_90; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_97 = regs_virtualToPhysicalMap_0 == 5'h1 ? _GEN_95 : _GEN_91; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_98 = regs_virtualPortEnable ? _GEN_96 : _GEN_48; // @[src/main/scala/GPIO.scala 34:71]
  wire [7:0] _GEN_99 = regs_virtualPortEnable ? _GEN_97 : _GEN_49; // @[src/main/scala/GPIO.scala 34:71]
  wire [15:0] _OUTPUT_T_81 = regs_OUTPUT | 16'h4; // @[src/main/scala/GPIO.scala 40:40]
  wire [15:0] _OUTPUT_T_84 = regs_OUTPUT & 16'hb; // @[src/main/scala/GPIO.scala 41:50]
  wire [15:0] _GEN_100 = regs_virtualPortOutput[7] ? _OUTPUT_T_81 : _OUTPUT_T_84; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_101 = regs_INPUT[2] ? _virtualPortOutput_T_1 : _virtualPortOutput_T_4; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_102 = regs_DIRECTION[2] ? _GEN_100 : _GEN_98; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_103 = regs_DIRECTION[2] ? _GEN_99 : _GEN_101; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_104 = regs_virtualToPhysicalMap_7 == 5'h2 ? _GEN_102 : _GEN_98; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_105 = regs_virtualToPhysicalMap_7 == 5'h2 ? _GEN_103 : _GEN_99; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_106 = regs_virtualPortOutput[6] ? _OUTPUT_T_81 : _OUTPUT_T_84; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_107 = regs_INPUT[2] ? _virtualPortOutput_T_6 : _virtualPortOutput_T_9; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_108 = regs_DIRECTION[2] ? _GEN_106 : _GEN_104; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_109 = regs_DIRECTION[2] ? _GEN_105 : _GEN_107; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_110 = regs_virtualToPhysicalMap_6 == 5'h2 ? _GEN_108 : _GEN_104; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_111 = regs_virtualToPhysicalMap_6 == 5'h2 ? _GEN_109 : _GEN_105; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_112 = regs_virtualPortOutput[5] ? _OUTPUT_T_81 : _OUTPUT_T_84; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_113 = regs_INPUT[2] ? _virtualPortOutput_T_11 : _virtualPortOutput_T_14; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_114 = regs_DIRECTION[2] ? _GEN_112 : _GEN_110; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_115 = regs_DIRECTION[2] ? _GEN_111 : _GEN_113; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_116 = regs_virtualToPhysicalMap_5 == 5'h2 ? _GEN_114 : _GEN_110; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_117 = regs_virtualToPhysicalMap_5 == 5'h2 ? _GEN_115 : _GEN_111; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_118 = regs_virtualPortOutput[4] ? _OUTPUT_T_81 : _OUTPUT_T_84; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_119 = regs_INPUT[2] ? _virtualPortOutput_T_16 : _virtualPortOutput_T_19; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_120 = regs_DIRECTION[2] ? _GEN_118 : _GEN_116; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_121 = regs_DIRECTION[2] ? _GEN_117 : _GEN_119; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_122 = regs_virtualToPhysicalMap_4 == 5'h2 ? _GEN_120 : _GEN_116; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_123 = regs_virtualToPhysicalMap_4 == 5'h2 ? _GEN_121 : _GEN_117; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_124 = regs_virtualPortOutput[3] ? _OUTPUT_T_81 : _OUTPUT_T_84; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_125 = regs_INPUT[2] ? _virtualPortOutput_T_21 : _virtualPortOutput_T_24; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_126 = regs_DIRECTION[2] ? _GEN_124 : _GEN_122; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_127 = regs_DIRECTION[2] ? _GEN_123 : _GEN_125; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_128 = regs_virtualToPhysicalMap_3 == 5'h2 ? _GEN_126 : _GEN_122; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_129 = regs_virtualToPhysicalMap_3 == 5'h2 ? _GEN_127 : _GEN_123; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_130 = regs_virtualPortOutput[2] ? _OUTPUT_T_81 : _OUTPUT_T_84; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_131 = regs_INPUT[2] ? _virtualPortOutput_T_26 : _virtualPortOutput_T_29; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_132 = regs_DIRECTION[2] ? _GEN_130 : _GEN_128; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_133 = regs_DIRECTION[2] ? _GEN_129 : _GEN_131; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_134 = regs_virtualToPhysicalMap_2 == 5'h2 ? _GEN_132 : _GEN_128; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_135 = regs_virtualToPhysicalMap_2 == 5'h2 ? _GEN_133 : _GEN_129; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_136 = regs_virtualPortOutput[1] ? _OUTPUT_T_81 : _OUTPUT_T_84; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_137 = regs_INPUT[2] ? _virtualPortOutput_T_31 : _virtualPortOutput_T_34; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_138 = regs_DIRECTION[2] ? _GEN_136 : _GEN_134; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_139 = regs_DIRECTION[2] ? _GEN_135 : _GEN_137; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_140 = regs_virtualToPhysicalMap_1 == 5'h2 ? _GEN_138 : _GEN_134; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_141 = regs_virtualToPhysicalMap_1 == 5'h2 ? _GEN_139 : _GEN_135; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_142 = regs_virtualPortOutput[0] ? _OUTPUT_T_81 : _OUTPUT_T_84; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_143 = regs_INPUT[2] ? _virtualPortOutput_T_36 : 8'h0; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_144 = regs_DIRECTION[2] ? _GEN_142 : _GEN_140; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_145 = regs_DIRECTION[2] ? _GEN_141 : _GEN_143; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_146 = regs_virtualToPhysicalMap_0 == 5'h2 ? _GEN_144 : _GEN_140; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_147 = regs_virtualToPhysicalMap_0 == 5'h2 ? _GEN_145 : _GEN_141; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_148 = regs_virtualPortEnable ? _GEN_146 : _GEN_98; // @[src/main/scala/GPIO.scala 34:71]
  wire [7:0] _GEN_149 = regs_virtualPortEnable ? _GEN_147 : _GEN_99; // @[src/main/scala/GPIO.scala 34:71]
  wire [15:0] _OUTPUT_T_121 = regs_OUTPUT | 16'h8; // @[src/main/scala/GPIO.scala 40:40]
  wire [15:0] _OUTPUT_T_124 = regs_OUTPUT & 16'h7; // @[src/main/scala/GPIO.scala 41:50]
  wire [15:0] _GEN_150 = regs_virtualPortOutput[7] ? _OUTPUT_T_121 : _OUTPUT_T_124; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_151 = regs_INPUT[3] ? _virtualPortOutput_T_1 : _virtualPortOutput_T_4; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_152 = regs_DIRECTION[3] ? _GEN_150 : _GEN_148; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_153 = regs_DIRECTION[3] ? _GEN_149 : _GEN_151; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_154 = regs_virtualToPhysicalMap_7 == 5'h3 ? _GEN_152 : _GEN_148; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_155 = regs_virtualToPhysicalMap_7 == 5'h3 ? _GEN_153 : _GEN_149; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_156 = regs_virtualPortOutput[6] ? _OUTPUT_T_121 : _OUTPUT_T_124; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_157 = regs_INPUT[3] ? _virtualPortOutput_T_6 : _virtualPortOutput_T_9; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_158 = regs_DIRECTION[3] ? _GEN_156 : _GEN_154; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_159 = regs_DIRECTION[3] ? _GEN_155 : _GEN_157; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_160 = regs_virtualToPhysicalMap_6 == 5'h3 ? _GEN_158 : _GEN_154; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_161 = regs_virtualToPhysicalMap_6 == 5'h3 ? _GEN_159 : _GEN_155; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_162 = regs_virtualPortOutput[5] ? _OUTPUT_T_121 : _OUTPUT_T_124; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_163 = regs_INPUT[3] ? _virtualPortOutput_T_11 : _virtualPortOutput_T_14; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_164 = regs_DIRECTION[3] ? _GEN_162 : _GEN_160; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_165 = regs_DIRECTION[3] ? _GEN_161 : _GEN_163; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_166 = regs_virtualToPhysicalMap_5 == 5'h3 ? _GEN_164 : _GEN_160; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_167 = regs_virtualToPhysicalMap_5 == 5'h3 ? _GEN_165 : _GEN_161; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_168 = regs_virtualPortOutput[4] ? _OUTPUT_T_121 : _OUTPUT_T_124; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_169 = regs_INPUT[3] ? _virtualPortOutput_T_16 : _virtualPortOutput_T_19; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_170 = regs_DIRECTION[3] ? _GEN_168 : _GEN_166; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_171 = regs_DIRECTION[3] ? _GEN_167 : _GEN_169; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_172 = regs_virtualToPhysicalMap_4 == 5'h3 ? _GEN_170 : _GEN_166; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_173 = regs_virtualToPhysicalMap_4 == 5'h3 ? _GEN_171 : _GEN_167; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_174 = regs_virtualPortOutput[3] ? _OUTPUT_T_121 : _OUTPUT_T_124; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_175 = regs_INPUT[3] ? _virtualPortOutput_T_21 : _virtualPortOutput_T_24; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_176 = regs_DIRECTION[3] ? _GEN_174 : _GEN_172; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_177 = regs_DIRECTION[3] ? _GEN_173 : _GEN_175; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_178 = regs_virtualToPhysicalMap_3 == 5'h3 ? _GEN_176 : _GEN_172; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_179 = regs_virtualToPhysicalMap_3 == 5'h3 ? _GEN_177 : _GEN_173; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_180 = regs_virtualPortOutput[2] ? _OUTPUT_T_121 : _OUTPUT_T_124; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_181 = regs_INPUT[3] ? _virtualPortOutput_T_26 : _virtualPortOutput_T_29; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_182 = regs_DIRECTION[3] ? _GEN_180 : _GEN_178; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_183 = regs_DIRECTION[3] ? _GEN_179 : _GEN_181; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_184 = regs_virtualToPhysicalMap_2 == 5'h3 ? _GEN_182 : _GEN_178; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_185 = regs_virtualToPhysicalMap_2 == 5'h3 ? _GEN_183 : _GEN_179; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_186 = regs_virtualPortOutput[1] ? _OUTPUT_T_121 : _OUTPUT_T_124; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_187 = regs_INPUT[3] ? _virtualPortOutput_T_31 : _virtualPortOutput_T_34; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_188 = regs_DIRECTION[3] ? _GEN_186 : _GEN_184; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_189 = regs_DIRECTION[3] ? _GEN_185 : _GEN_187; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_190 = regs_virtualToPhysicalMap_1 == 5'h3 ? _GEN_188 : _GEN_184; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_191 = regs_virtualToPhysicalMap_1 == 5'h3 ? _GEN_189 : _GEN_185; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_192 = regs_virtualPortOutput[0] ? _OUTPUT_T_121 : _OUTPUT_T_124; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_193 = regs_INPUT[3] ? _virtualPortOutput_T_36 : 8'h0; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_194 = regs_DIRECTION[3] ? _GEN_192 : _GEN_190; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_195 = regs_DIRECTION[3] ? _GEN_191 : _GEN_193; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_196 = regs_virtualToPhysicalMap_0 == 5'h3 ? _GEN_194 : _GEN_190; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_197 = regs_virtualToPhysicalMap_0 == 5'h3 ? _GEN_195 : _GEN_191; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_198 = regs_virtualPortEnable ? _GEN_196 : _GEN_148; // @[src/main/scala/GPIO.scala 34:71]
  wire [7:0] _GEN_199 = regs_virtualPortEnable ? _GEN_197 : _GEN_149; // @[src/main/scala/GPIO.scala 34:71]
  wire [15:0] _OUTPUT_T_161 = regs_OUTPUT | 16'h10; // @[src/main/scala/GPIO.scala 40:40]
  wire [15:0] _OUTPUT_T_164 = regs_OUTPUT & 16'hef; // @[src/main/scala/GPIO.scala 41:50]
  wire [15:0] _GEN_200 = regs_virtualPortOutput[7] ? _OUTPUT_T_161 : _OUTPUT_T_164; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_201 = regs_INPUT[4] ? _virtualPortOutput_T_1 : _virtualPortOutput_T_4; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_202 = regs_DIRECTION[4] ? _GEN_200 : _GEN_198; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_203 = regs_DIRECTION[4] ? _GEN_199 : _GEN_201; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_204 = regs_virtualToPhysicalMap_7 == 5'h4 ? _GEN_202 : _GEN_198; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_205 = regs_virtualToPhysicalMap_7 == 5'h4 ? _GEN_203 : _GEN_199; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_206 = regs_virtualPortOutput[6] ? _OUTPUT_T_161 : _OUTPUT_T_164; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_207 = regs_INPUT[4] ? _virtualPortOutput_T_6 : _virtualPortOutput_T_9; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_208 = regs_DIRECTION[4] ? _GEN_206 : _GEN_204; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_209 = regs_DIRECTION[4] ? _GEN_205 : _GEN_207; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_210 = regs_virtualToPhysicalMap_6 == 5'h4 ? _GEN_208 : _GEN_204; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_211 = regs_virtualToPhysicalMap_6 == 5'h4 ? _GEN_209 : _GEN_205; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_212 = regs_virtualPortOutput[5] ? _OUTPUT_T_161 : _OUTPUT_T_164; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_213 = regs_INPUT[4] ? _virtualPortOutput_T_11 : _virtualPortOutput_T_14; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_214 = regs_DIRECTION[4] ? _GEN_212 : _GEN_210; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_215 = regs_DIRECTION[4] ? _GEN_211 : _GEN_213; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_216 = regs_virtualToPhysicalMap_5 == 5'h4 ? _GEN_214 : _GEN_210; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_217 = regs_virtualToPhysicalMap_5 == 5'h4 ? _GEN_215 : _GEN_211; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_218 = regs_virtualPortOutput[4] ? _OUTPUT_T_161 : _OUTPUT_T_164; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_219 = regs_INPUT[4] ? _virtualPortOutput_T_16 : _virtualPortOutput_T_19; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_220 = regs_DIRECTION[4] ? _GEN_218 : _GEN_216; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_221 = regs_DIRECTION[4] ? _GEN_217 : _GEN_219; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_222 = regs_virtualToPhysicalMap_4 == 5'h4 ? _GEN_220 : _GEN_216; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_223 = regs_virtualToPhysicalMap_4 == 5'h4 ? _GEN_221 : _GEN_217; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_224 = regs_virtualPortOutput[3] ? _OUTPUT_T_161 : _OUTPUT_T_164; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_225 = regs_INPUT[4] ? _virtualPortOutput_T_21 : _virtualPortOutput_T_24; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_226 = regs_DIRECTION[4] ? _GEN_224 : _GEN_222; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_227 = regs_DIRECTION[4] ? _GEN_223 : _GEN_225; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_228 = regs_virtualToPhysicalMap_3 == 5'h4 ? _GEN_226 : _GEN_222; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_229 = regs_virtualToPhysicalMap_3 == 5'h4 ? _GEN_227 : _GEN_223; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_230 = regs_virtualPortOutput[2] ? _OUTPUT_T_161 : _OUTPUT_T_164; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_231 = regs_INPUT[4] ? _virtualPortOutput_T_26 : _virtualPortOutput_T_29; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_232 = regs_DIRECTION[4] ? _GEN_230 : _GEN_228; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_233 = regs_DIRECTION[4] ? _GEN_229 : _GEN_231; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_234 = regs_virtualToPhysicalMap_2 == 5'h4 ? _GEN_232 : _GEN_228; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_235 = regs_virtualToPhysicalMap_2 == 5'h4 ? _GEN_233 : _GEN_229; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_236 = regs_virtualPortOutput[1] ? _OUTPUT_T_161 : _OUTPUT_T_164; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_237 = regs_INPUT[4] ? _virtualPortOutput_T_31 : _virtualPortOutput_T_34; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_238 = regs_DIRECTION[4] ? _GEN_236 : _GEN_234; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_239 = regs_DIRECTION[4] ? _GEN_235 : _GEN_237; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_240 = regs_virtualToPhysicalMap_1 == 5'h4 ? _GEN_238 : _GEN_234; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_241 = regs_virtualToPhysicalMap_1 == 5'h4 ? _GEN_239 : _GEN_235; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_242 = regs_virtualPortOutput[0] ? _OUTPUT_T_161 : _OUTPUT_T_164; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_243 = regs_INPUT[4] ? _virtualPortOutput_T_36 : 8'h0; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_244 = regs_DIRECTION[4] ? _GEN_242 : _GEN_240; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_245 = regs_DIRECTION[4] ? _GEN_241 : _GEN_243; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_246 = regs_virtualToPhysicalMap_0 == 5'h4 ? _GEN_244 : _GEN_240; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_247 = regs_virtualToPhysicalMap_0 == 5'h4 ? _GEN_245 : _GEN_241; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_248 = regs_virtualPortEnable ? _GEN_246 : _GEN_198; // @[src/main/scala/GPIO.scala 34:71]
  wire [7:0] _GEN_249 = regs_virtualPortEnable ? _GEN_247 : _GEN_199; // @[src/main/scala/GPIO.scala 34:71]
  wire [15:0] _OUTPUT_T_201 = regs_OUTPUT | 16'h20; // @[src/main/scala/GPIO.scala 40:40]
  wire [15:0] _OUTPUT_T_204 = regs_OUTPUT & 16'hdf; // @[src/main/scala/GPIO.scala 41:50]
  wire [15:0] _GEN_250 = regs_virtualPortOutput[7] ? _OUTPUT_T_201 : _OUTPUT_T_204; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_251 = regs_INPUT[5] ? _virtualPortOutput_T_1 : _virtualPortOutput_T_4; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_252 = regs_DIRECTION[5] ? _GEN_250 : _GEN_248; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_253 = regs_DIRECTION[5] ? _GEN_249 : _GEN_251; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_254 = regs_virtualToPhysicalMap_7 == 5'h5 ? _GEN_252 : _GEN_248; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_255 = regs_virtualToPhysicalMap_7 == 5'h5 ? _GEN_253 : _GEN_249; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_256 = regs_virtualPortOutput[6] ? _OUTPUT_T_201 : _OUTPUT_T_204; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_257 = regs_INPUT[5] ? _virtualPortOutput_T_6 : _virtualPortOutput_T_9; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_258 = regs_DIRECTION[5] ? _GEN_256 : _GEN_254; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_259 = regs_DIRECTION[5] ? _GEN_255 : _GEN_257; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_260 = regs_virtualToPhysicalMap_6 == 5'h5 ? _GEN_258 : _GEN_254; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_261 = regs_virtualToPhysicalMap_6 == 5'h5 ? _GEN_259 : _GEN_255; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_262 = regs_virtualPortOutput[5] ? _OUTPUT_T_201 : _OUTPUT_T_204; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_263 = regs_INPUT[5] ? _virtualPortOutput_T_11 : _virtualPortOutput_T_14; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_264 = regs_DIRECTION[5] ? _GEN_262 : _GEN_260; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_265 = regs_DIRECTION[5] ? _GEN_261 : _GEN_263; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_266 = regs_virtualToPhysicalMap_5 == 5'h5 ? _GEN_264 : _GEN_260; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_267 = regs_virtualToPhysicalMap_5 == 5'h5 ? _GEN_265 : _GEN_261; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_268 = regs_virtualPortOutput[4] ? _OUTPUT_T_201 : _OUTPUT_T_204; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_269 = regs_INPUT[5] ? _virtualPortOutput_T_16 : _virtualPortOutput_T_19; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_270 = regs_DIRECTION[5] ? _GEN_268 : _GEN_266; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_271 = regs_DIRECTION[5] ? _GEN_267 : _GEN_269; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_272 = regs_virtualToPhysicalMap_4 == 5'h5 ? _GEN_270 : _GEN_266; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_273 = regs_virtualToPhysicalMap_4 == 5'h5 ? _GEN_271 : _GEN_267; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_274 = regs_virtualPortOutput[3] ? _OUTPUT_T_201 : _OUTPUT_T_204; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_275 = regs_INPUT[5] ? _virtualPortOutput_T_21 : _virtualPortOutput_T_24; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_276 = regs_DIRECTION[5] ? _GEN_274 : _GEN_272; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_277 = regs_DIRECTION[5] ? _GEN_273 : _GEN_275; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_278 = regs_virtualToPhysicalMap_3 == 5'h5 ? _GEN_276 : _GEN_272; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_279 = regs_virtualToPhysicalMap_3 == 5'h5 ? _GEN_277 : _GEN_273; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_280 = regs_virtualPortOutput[2] ? _OUTPUT_T_201 : _OUTPUT_T_204; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_281 = regs_INPUT[5] ? _virtualPortOutput_T_26 : _virtualPortOutput_T_29; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_282 = regs_DIRECTION[5] ? _GEN_280 : _GEN_278; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_283 = regs_DIRECTION[5] ? _GEN_279 : _GEN_281; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_284 = regs_virtualToPhysicalMap_2 == 5'h5 ? _GEN_282 : _GEN_278; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_285 = regs_virtualToPhysicalMap_2 == 5'h5 ? _GEN_283 : _GEN_279; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_286 = regs_virtualPortOutput[1] ? _OUTPUT_T_201 : _OUTPUT_T_204; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_287 = regs_INPUT[5] ? _virtualPortOutput_T_31 : _virtualPortOutput_T_34; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_288 = regs_DIRECTION[5] ? _GEN_286 : _GEN_284; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_289 = regs_DIRECTION[5] ? _GEN_285 : _GEN_287; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_290 = regs_virtualToPhysicalMap_1 == 5'h5 ? _GEN_288 : _GEN_284; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_291 = regs_virtualToPhysicalMap_1 == 5'h5 ? _GEN_289 : _GEN_285; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_292 = regs_virtualPortOutput[0] ? _OUTPUT_T_201 : _OUTPUT_T_204; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_293 = regs_INPUT[5] ? _virtualPortOutput_T_36 : 8'h0; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_294 = regs_DIRECTION[5] ? _GEN_292 : _GEN_290; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_295 = regs_DIRECTION[5] ? _GEN_291 : _GEN_293; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_296 = regs_virtualToPhysicalMap_0 == 5'h5 ? _GEN_294 : _GEN_290; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_297 = regs_virtualToPhysicalMap_0 == 5'h5 ? _GEN_295 : _GEN_291; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_298 = regs_virtualPortEnable ? _GEN_296 : _GEN_248; // @[src/main/scala/GPIO.scala 34:71]
  wire [7:0] _GEN_299 = regs_virtualPortEnable ? _GEN_297 : _GEN_249; // @[src/main/scala/GPIO.scala 34:71]
  wire [15:0] _OUTPUT_T_241 = regs_OUTPUT | 16'h40; // @[src/main/scala/GPIO.scala 40:40]
  wire [15:0] _OUTPUT_T_244 = regs_OUTPUT & 16'hbf; // @[src/main/scala/GPIO.scala 41:50]
  wire [15:0] _GEN_300 = regs_virtualPortOutput[7] ? _OUTPUT_T_241 : _OUTPUT_T_244; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_301 = regs_INPUT[6] ? _virtualPortOutput_T_1 : _virtualPortOutput_T_4; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_302 = regs_DIRECTION[6] ? _GEN_300 : _GEN_298; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_303 = regs_DIRECTION[6] ? _GEN_299 : _GEN_301; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_304 = regs_virtualToPhysicalMap_7 == 5'h6 ? _GEN_302 : _GEN_298; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_305 = regs_virtualToPhysicalMap_7 == 5'h6 ? _GEN_303 : _GEN_299; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_306 = regs_virtualPortOutput[6] ? _OUTPUT_T_241 : _OUTPUT_T_244; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_307 = regs_INPUT[6] ? _virtualPortOutput_T_6 : _virtualPortOutput_T_9; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_308 = regs_DIRECTION[6] ? _GEN_306 : _GEN_304; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_309 = regs_DIRECTION[6] ? _GEN_305 : _GEN_307; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_310 = regs_virtualToPhysicalMap_6 == 5'h6 ? _GEN_308 : _GEN_304; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_311 = regs_virtualToPhysicalMap_6 == 5'h6 ? _GEN_309 : _GEN_305; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_312 = regs_virtualPortOutput[5] ? _OUTPUT_T_241 : _OUTPUT_T_244; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_313 = regs_INPUT[6] ? _virtualPortOutput_T_11 : _virtualPortOutput_T_14; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_314 = regs_DIRECTION[6] ? _GEN_312 : _GEN_310; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_315 = regs_DIRECTION[6] ? _GEN_311 : _GEN_313; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_316 = regs_virtualToPhysicalMap_5 == 5'h6 ? _GEN_314 : _GEN_310; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_317 = regs_virtualToPhysicalMap_5 == 5'h6 ? _GEN_315 : _GEN_311; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_318 = regs_virtualPortOutput[4] ? _OUTPUT_T_241 : _OUTPUT_T_244; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_319 = regs_INPUT[6] ? _virtualPortOutput_T_16 : _virtualPortOutput_T_19; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_320 = regs_DIRECTION[6] ? _GEN_318 : _GEN_316; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_321 = regs_DIRECTION[6] ? _GEN_317 : _GEN_319; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_322 = regs_virtualToPhysicalMap_4 == 5'h6 ? _GEN_320 : _GEN_316; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_323 = regs_virtualToPhysicalMap_4 == 5'h6 ? _GEN_321 : _GEN_317; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_324 = regs_virtualPortOutput[3] ? _OUTPUT_T_241 : _OUTPUT_T_244; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_325 = regs_INPUT[6] ? _virtualPortOutput_T_21 : _virtualPortOutput_T_24; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_326 = regs_DIRECTION[6] ? _GEN_324 : _GEN_322; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_327 = regs_DIRECTION[6] ? _GEN_323 : _GEN_325; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_328 = regs_virtualToPhysicalMap_3 == 5'h6 ? _GEN_326 : _GEN_322; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_329 = regs_virtualToPhysicalMap_3 == 5'h6 ? _GEN_327 : _GEN_323; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_330 = regs_virtualPortOutput[2] ? _OUTPUT_T_241 : _OUTPUT_T_244; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_331 = regs_INPUT[6] ? _virtualPortOutput_T_26 : _virtualPortOutput_T_29; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_332 = regs_DIRECTION[6] ? _GEN_330 : _GEN_328; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_333 = regs_DIRECTION[6] ? _GEN_329 : _GEN_331; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_334 = regs_virtualToPhysicalMap_2 == 5'h6 ? _GEN_332 : _GEN_328; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_335 = regs_virtualToPhysicalMap_2 == 5'h6 ? _GEN_333 : _GEN_329; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_336 = regs_virtualPortOutput[1] ? _OUTPUT_T_241 : _OUTPUT_T_244; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_337 = regs_INPUT[6] ? _virtualPortOutput_T_31 : _virtualPortOutput_T_34; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_338 = regs_DIRECTION[6] ? _GEN_336 : _GEN_334; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_339 = regs_DIRECTION[6] ? _GEN_335 : _GEN_337; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_340 = regs_virtualToPhysicalMap_1 == 5'h6 ? _GEN_338 : _GEN_334; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_341 = regs_virtualToPhysicalMap_1 == 5'h6 ? _GEN_339 : _GEN_335; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_342 = regs_virtualPortOutput[0] ? _OUTPUT_T_241 : _OUTPUT_T_244; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_343 = regs_INPUT[6] ? _virtualPortOutput_T_36 : 8'h0; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_344 = regs_DIRECTION[6] ? _GEN_342 : _GEN_340; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_345 = regs_DIRECTION[6] ? _GEN_341 : _GEN_343; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_346 = regs_virtualToPhysicalMap_0 == 5'h6 ? _GEN_344 : _GEN_340; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_347 = regs_virtualToPhysicalMap_0 == 5'h6 ? _GEN_345 : _GEN_341; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_348 = regs_virtualPortEnable ? _GEN_346 : _GEN_298; // @[src/main/scala/GPIO.scala 34:71]
  wire [7:0] _GEN_349 = regs_virtualPortEnable ? _GEN_347 : _GEN_299; // @[src/main/scala/GPIO.scala 34:71]
  wire [15:0] _OUTPUT_T_281 = regs_OUTPUT | 16'h80; // @[src/main/scala/GPIO.scala 40:40]
  wire [15:0] _OUTPUT_T_284 = regs_OUTPUT & 16'h7f; // @[src/main/scala/GPIO.scala 41:50]
  wire [15:0] _GEN_350 = regs_virtualPortOutput[7] ? _OUTPUT_T_281 : _OUTPUT_T_284; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_351 = regs_INPUT[7] ? _virtualPortOutput_T_1 : _virtualPortOutput_T_4; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_352 = regs_DIRECTION[7] ? _GEN_350 : _GEN_348; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_353 = regs_DIRECTION[7] ? _GEN_349 : _GEN_351; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_354 = regs_virtualToPhysicalMap_7 == 5'h7 ? _GEN_352 : _GEN_348; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_355 = regs_virtualToPhysicalMap_7 == 5'h7 ? _GEN_353 : _GEN_349; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_356 = regs_virtualPortOutput[6] ? _OUTPUT_T_281 : _OUTPUT_T_284; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_357 = regs_INPUT[7] ? _virtualPortOutput_T_6 : _virtualPortOutput_T_9; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_358 = regs_DIRECTION[7] ? _GEN_356 : _GEN_354; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_359 = regs_DIRECTION[7] ? _GEN_355 : _GEN_357; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_360 = regs_virtualToPhysicalMap_6 == 5'h7 ? _GEN_358 : _GEN_354; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_361 = regs_virtualToPhysicalMap_6 == 5'h7 ? _GEN_359 : _GEN_355; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_362 = regs_virtualPortOutput[5] ? _OUTPUT_T_281 : _OUTPUT_T_284; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_363 = regs_INPUT[7] ? _virtualPortOutput_T_11 : _virtualPortOutput_T_14; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_364 = regs_DIRECTION[7] ? _GEN_362 : _GEN_360; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_365 = regs_DIRECTION[7] ? _GEN_361 : _GEN_363; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_366 = regs_virtualToPhysicalMap_5 == 5'h7 ? _GEN_364 : _GEN_360; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_367 = regs_virtualToPhysicalMap_5 == 5'h7 ? _GEN_365 : _GEN_361; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_368 = regs_virtualPortOutput[4] ? _OUTPUT_T_281 : _OUTPUT_T_284; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_369 = regs_INPUT[7] ? _virtualPortOutput_T_16 : _virtualPortOutput_T_19; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_370 = regs_DIRECTION[7] ? _GEN_368 : _GEN_366; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_371 = regs_DIRECTION[7] ? _GEN_367 : _GEN_369; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_372 = regs_virtualToPhysicalMap_4 == 5'h7 ? _GEN_370 : _GEN_366; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_373 = regs_virtualToPhysicalMap_4 == 5'h7 ? _GEN_371 : _GEN_367; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_374 = regs_virtualPortOutput[3] ? _OUTPUT_T_281 : _OUTPUT_T_284; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_375 = regs_INPUT[7] ? _virtualPortOutput_T_21 : _virtualPortOutput_T_24; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_376 = regs_DIRECTION[7] ? _GEN_374 : _GEN_372; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_377 = regs_DIRECTION[7] ? _GEN_373 : _GEN_375; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_378 = regs_virtualToPhysicalMap_3 == 5'h7 ? _GEN_376 : _GEN_372; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_379 = regs_virtualToPhysicalMap_3 == 5'h7 ? _GEN_377 : _GEN_373; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_380 = regs_virtualPortOutput[2] ? _OUTPUT_T_281 : _OUTPUT_T_284; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_381 = regs_INPUT[7] ? _virtualPortOutput_T_26 : _virtualPortOutput_T_29; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_382 = regs_DIRECTION[7] ? _GEN_380 : _GEN_378; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_383 = regs_DIRECTION[7] ? _GEN_379 : _GEN_381; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_384 = regs_virtualToPhysicalMap_2 == 5'h7 ? _GEN_382 : _GEN_378; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_385 = regs_virtualToPhysicalMap_2 == 5'h7 ? _GEN_383 : _GEN_379; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_386 = regs_virtualPortOutput[1] ? _OUTPUT_T_281 : _OUTPUT_T_284; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_387 = regs_INPUT[7] ? _virtualPortOutput_T_31 : _virtualPortOutput_T_34; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_388 = regs_DIRECTION[7] ? _GEN_386 : _GEN_384; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_389 = regs_DIRECTION[7] ? _GEN_385 : _GEN_387; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_390 = regs_virtualToPhysicalMap_1 == 5'h7 ? _GEN_388 : _GEN_384; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_391 = regs_virtualToPhysicalMap_1 == 5'h7 ? _GEN_389 : _GEN_385; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_392 = regs_virtualPortOutput[0] ? _OUTPUT_T_281 : _OUTPUT_T_284; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_393 = regs_INPUT[7] ? _virtualPortOutput_T_36 : 8'h0; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_394 = regs_DIRECTION[7] ? _GEN_392 : _GEN_390; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_395 = regs_DIRECTION[7] ? _GEN_391 : _GEN_393; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_396 = regs_virtualToPhysicalMap_0 == 5'h7 ? _GEN_394 : _GEN_390; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_397 = regs_virtualToPhysicalMap_0 == 5'h7 ? _GEN_395 : _GEN_391; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_398 = regs_virtualPortEnable ? _GEN_396 : _GEN_348; // @[src/main/scala/GPIO.scala 34:71]
  wire [7:0] _GEN_399 = regs_virtualPortEnable ? _GEN_397 : _GEN_349; // @[src/main/scala/GPIO.scala 34:71]
  wire [15:0] _OUTPUT_T_321 = regs_OUTPUT | 16'h100; // @[src/main/scala/GPIO.scala 40:40]
  wire [15:0] _OUTPUT_T_324 = regs_OUTPUT & 16'hfeff; // @[src/main/scala/GPIO.scala 41:50]
  wire [15:0] _GEN_400 = regs_virtualPortOutput[7] ? _OUTPUT_T_321 : _OUTPUT_T_324; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_401 = regs_INPUT[8] ? _virtualPortOutput_T_1 : _virtualPortOutput_T_4; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_402 = regs_DIRECTION[8] ? _GEN_400 : _GEN_398; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_403 = regs_DIRECTION[8] ? _GEN_399 : _GEN_401; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_404 = regs_virtualToPhysicalMap_7 == 5'h8 ? _GEN_402 : _GEN_398; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_405 = regs_virtualToPhysicalMap_7 == 5'h8 ? _GEN_403 : _GEN_399; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_406 = regs_virtualPortOutput[6] ? _OUTPUT_T_321 : _OUTPUT_T_324; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_407 = regs_INPUT[8] ? _virtualPortOutput_T_6 : _virtualPortOutput_T_9; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_408 = regs_DIRECTION[8] ? _GEN_406 : _GEN_404; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_409 = regs_DIRECTION[8] ? _GEN_405 : _GEN_407; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_410 = regs_virtualToPhysicalMap_6 == 5'h8 ? _GEN_408 : _GEN_404; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_411 = regs_virtualToPhysicalMap_6 == 5'h8 ? _GEN_409 : _GEN_405; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_412 = regs_virtualPortOutput[5] ? _OUTPUT_T_321 : _OUTPUT_T_324; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_413 = regs_INPUT[8] ? _virtualPortOutput_T_11 : _virtualPortOutput_T_14; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_414 = regs_DIRECTION[8] ? _GEN_412 : _GEN_410; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_415 = regs_DIRECTION[8] ? _GEN_411 : _GEN_413; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_416 = regs_virtualToPhysicalMap_5 == 5'h8 ? _GEN_414 : _GEN_410; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_417 = regs_virtualToPhysicalMap_5 == 5'h8 ? _GEN_415 : _GEN_411; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_418 = regs_virtualPortOutput[4] ? _OUTPUT_T_321 : _OUTPUT_T_324; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_419 = regs_INPUT[8] ? _virtualPortOutput_T_16 : _virtualPortOutput_T_19; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_420 = regs_DIRECTION[8] ? _GEN_418 : _GEN_416; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_421 = regs_DIRECTION[8] ? _GEN_417 : _GEN_419; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_422 = regs_virtualToPhysicalMap_4 == 5'h8 ? _GEN_420 : _GEN_416; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_423 = regs_virtualToPhysicalMap_4 == 5'h8 ? _GEN_421 : _GEN_417; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_424 = regs_virtualPortOutput[3] ? _OUTPUT_T_321 : _OUTPUT_T_324; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_425 = regs_INPUT[8] ? _virtualPortOutput_T_21 : _virtualPortOutput_T_24; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_426 = regs_DIRECTION[8] ? _GEN_424 : _GEN_422; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_427 = regs_DIRECTION[8] ? _GEN_423 : _GEN_425; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_428 = regs_virtualToPhysicalMap_3 == 5'h8 ? _GEN_426 : _GEN_422; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_429 = regs_virtualToPhysicalMap_3 == 5'h8 ? _GEN_427 : _GEN_423; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_430 = regs_virtualPortOutput[2] ? _OUTPUT_T_321 : _OUTPUT_T_324; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_431 = regs_INPUT[8] ? _virtualPortOutput_T_26 : _virtualPortOutput_T_29; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_432 = regs_DIRECTION[8] ? _GEN_430 : _GEN_428; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_433 = regs_DIRECTION[8] ? _GEN_429 : _GEN_431; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_434 = regs_virtualToPhysicalMap_2 == 5'h8 ? _GEN_432 : _GEN_428; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_435 = regs_virtualToPhysicalMap_2 == 5'h8 ? _GEN_433 : _GEN_429; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_436 = regs_virtualPortOutput[1] ? _OUTPUT_T_321 : _OUTPUT_T_324; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_437 = regs_INPUT[8] ? _virtualPortOutput_T_31 : _virtualPortOutput_T_34; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_438 = regs_DIRECTION[8] ? _GEN_436 : _GEN_434; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_439 = regs_DIRECTION[8] ? _GEN_435 : _GEN_437; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_440 = regs_virtualToPhysicalMap_1 == 5'h8 ? _GEN_438 : _GEN_434; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_441 = regs_virtualToPhysicalMap_1 == 5'h8 ? _GEN_439 : _GEN_435; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_442 = regs_virtualPortOutput[0] ? _OUTPUT_T_321 : _OUTPUT_T_324; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_443 = regs_INPUT[8] ? _virtualPortOutput_T_36 : 8'h0; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_444 = regs_DIRECTION[8] ? _GEN_442 : _GEN_440; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_445 = regs_DIRECTION[8] ? _GEN_441 : _GEN_443; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_446 = regs_virtualToPhysicalMap_0 == 5'h8 ? _GEN_444 : _GEN_440; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_447 = regs_virtualToPhysicalMap_0 == 5'h8 ? _GEN_445 : _GEN_441; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_448 = regs_virtualPortEnable ? _GEN_446 : _GEN_398; // @[src/main/scala/GPIO.scala 34:71]
  wire [7:0] _GEN_449 = regs_virtualPortEnable ? _GEN_447 : _GEN_399; // @[src/main/scala/GPIO.scala 34:71]
  wire [15:0] _OUTPUT_T_361 = regs_OUTPUT | 16'h200; // @[src/main/scala/GPIO.scala 40:40]
  wire [15:0] _OUTPUT_T_364 = regs_OUTPUT & 16'hfdff; // @[src/main/scala/GPIO.scala 41:50]
  wire [15:0] _GEN_450 = regs_virtualPortOutput[7] ? _OUTPUT_T_361 : _OUTPUT_T_364; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_451 = regs_INPUT[9] ? _virtualPortOutput_T_1 : _virtualPortOutput_T_4; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_452 = regs_DIRECTION[9] ? _GEN_450 : _GEN_448; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_453 = regs_DIRECTION[9] ? _GEN_449 : _GEN_451; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_454 = regs_virtualToPhysicalMap_7 == 5'h9 ? _GEN_452 : _GEN_448; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_455 = regs_virtualToPhysicalMap_7 == 5'h9 ? _GEN_453 : _GEN_449; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_456 = regs_virtualPortOutput[6] ? _OUTPUT_T_361 : _OUTPUT_T_364; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_457 = regs_INPUT[9] ? _virtualPortOutput_T_6 : _virtualPortOutput_T_9; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_458 = regs_DIRECTION[9] ? _GEN_456 : _GEN_454; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_459 = regs_DIRECTION[9] ? _GEN_455 : _GEN_457; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_460 = regs_virtualToPhysicalMap_6 == 5'h9 ? _GEN_458 : _GEN_454; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_461 = regs_virtualToPhysicalMap_6 == 5'h9 ? _GEN_459 : _GEN_455; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_462 = regs_virtualPortOutput[5] ? _OUTPUT_T_361 : _OUTPUT_T_364; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_463 = regs_INPUT[9] ? _virtualPortOutput_T_11 : _virtualPortOutput_T_14; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_464 = regs_DIRECTION[9] ? _GEN_462 : _GEN_460; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_465 = regs_DIRECTION[9] ? _GEN_461 : _GEN_463; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_466 = regs_virtualToPhysicalMap_5 == 5'h9 ? _GEN_464 : _GEN_460; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_467 = regs_virtualToPhysicalMap_5 == 5'h9 ? _GEN_465 : _GEN_461; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_468 = regs_virtualPortOutput[4] ? _OUTPUT_T_361 : _OUTPUT_T_364; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_469 = regs_INPUT[9] ? _virtualPortOutput_T_16 : _virtualPortOutput_T_19; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_470 = regs_DIRECTION[9] ? _GEN_468 : _GEN_466; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_471 = regs_DIRECTION[9] ? _GEN_467 : _GEN_469; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_472 = regs_virtualToPhysicalMap_4 == 5'h9 ? _GEN_470 : _GEN_466; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_473 = regs_virtualToPhysicalMap_4 == 5'h9 ? _GEN_471 : _GEN_467; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_474 = regs_virtualPortOutput[3] ? _OUTPUT_T_361 : _OUTPUT_T_364; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_475 = regs_INPUT[9] ? _virtualPortOutput_T_21 : _virtualPortOutput_T_24; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_476 = regs_DIRECTION[9] ? _GEN_474 : _GEN_472; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_477 = regs_DIRECTION[9] ? _GEN_473 : _GEN_475; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_478 = regs_virtualToPhysicalMap_3 == 5'h9 ? _GEN_476 : _GEN_472; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_479 = regs_virtualToPhysicalMap_3 == 5'h9 ? _GEN_477 : _GEN_473; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_480 = regs_virtualPortOutput[2] ? _OUTPUT_T_361 : _OUTPUT_T_364; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_481 = regs_INPUT[9] ? _virtualPortOutput_T_26 : _virtualPortOutput_T_29; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_482 = regs_DIRECTION[9] ? _GEN_480 : _GEN_478; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_483 = regs_DIRECTION[9] ? _GEN_479 : _GEN_481; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_484 = regs_virtualToPhysicalMap_2 == 5'h9 ? _GEN_482 : _GEN_478; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_485 = regs_virtualToPhysicalMap_2 == 5'h9 ? _GEN_483 : _GEN_479; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_486 = regs_virtualPortOutput[1] ? _OUTPUT_T_361 : _OUTPUT_T_364; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_487 = regs_INPUT[9] ? _virtualPortOutput_T_31 : _virtualPortOutput_T_34; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_488 = regs_DIRECTION[9] ? _GEN_486 : _GEN_484; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_489 = regs_DIRECTION[9] ? _GEN_485 : _GEN_487; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_490 = regs_virtualToPhysicalMap_1 == 5'h9 ? _GEN_488 : _GEN_484; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_491 = regs_virtualToPhysicalMap_1 == 5'h9 ? _GEN_489 : _GEN_485; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_492 = regs_virtualPortOutput[0] ? _OUTPUT_T_361 : _OUTPUT_T_364; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_493 = regs_INPUT[9] ? _virtualPortOutput_T_36 : 8'h0; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_494 = regs_DIRECTION[9] ? _GEN_492 : _GEN_490; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_495 = regs_DIRECTION[9] ? _GEN_491 : _GEN_493; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_496 = regs_virtualToPhysicalMap_0 == 5'h9 ? _GEN_494 : _GEN_490; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_497 = regs_virtualToPhysicalMap_0 == 5'h9 ? _GEN_495 : _GEN_491; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_498 = regs_virtualPortEnable ? _GEN_496 : _GEN_448; // @[src/main/scala/GPIO.scala 34:71]
  wire [7:0] _GEN_499 = regs_virtualPortEnable ? _GEN_497 : _GEN_449; // @[src/main/scala/GPIO.scala 34:71]
  wire [15:0] _OUTPUT_T_401 = regs_OUTPUT | 16'h400; // @[src/main/scala/GPIO.scala 40:40]
  wire [15:0] _OUTPUT_T_404 = regs_OUTPUT & 16'hfbff; // @[src/main/scala/GPIO.scala 41:50]
  wire [15:0] _GEN_500 = regs_virtualPortOutput[7] ? _OUTPUT_T_401 : _OUTPUT_T_404; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_501 = regs_INPUT[10] ? _virtualPortOutput_T_1 : _virtualPortOutput_T_4; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_502 = regs_DIRECTION[10] ? _GEN_500 : _GEN_498; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_503 = regs_DIRECTION[10] ? _GEN_499 : _GEN_501; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_504 = regs_virtualToPhysicalMap_7 == 5'ha ? _GEN_502 : _GEN_498; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_505 = regs_virtualToPhysicalMap_7 == 5'ha ? _GEN_503 : _GEN_499; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_506 = regs_virtualPortOutput[6] ? _OUTPUT_T_401 : _OUTPUT_T_404; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_507 = regs_INPUT[10] ? _virtualPortOutput_T_6 : _virtualPortOutput_T_9; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_508 = regs_DIRECTION[10] ? _GEN_506 : _GEN_504; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_509 = regs_DIRECTION[10] ? _GEN_505 : _GEN_507; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_510 = regs_virtualToPhysicalMap_6 == 5'ha ? _GEN_508 : _GEN_504; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_511 = regs_virtualToPhysicalMap_6 == 5'ha ? _GEN_509 : _GEN_505; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_512 = regs_virtualPortOutput[5] ? _OUTPUT_T_401 : _OUTPUT_T_404; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_513 = regs_INPUT[10] ? _virtualPortOutput_T_11 : _virtualPortOutput_T_14; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_514 = regs_DIRECTION[10] ? _GEN_512 : _GEN_510; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_515 = regs_DIRECTION[10] ? _GEN_511 : _GEN_513; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_516 = regs_virtualToPhysicalMap_5 == 5'ha ? _GEN_514 : _GEN_510; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_517 = regs_virtualToPhysicalMap_5 == 5'ha ? _GEN_515 : _GEN_511; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_518 = regs_virtualPortOutput[4] ? _OUTPUT_T_401 : _OUTPUT_T_404; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_519 = regs_INPUT[10] ? _virtualPortOutput_T_16 : _virtualPortOutput_T_19; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_520 = regs_DIRECTION[10] ? _GEN_518 : _GEN_516; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_521 = regs_DIRECTION[10] ? _GEN_517 : _GEN_519; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_522 = regs_virtualToPhysicalMap_4 == 5'ha ? _GEN_520 : _GEN_516; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_523 = regs_virtualToPhysicalMap_4 == 5'ha ? _GEN_521 : _GEN_517; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_524 = regs_virtualPortOutput[3] ? _OUTPUT_T_401 : _OUTPUT_T_404; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_525 = regs_INPUT[10] ? _virtualPortOutput_T_21 : _virtualPortOutput_T_24; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_526 = regs_DIRECTION[10] ? _GEN_524 : _GEN_522; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_527 = regs_DIRECTION[10] ? _GEN_523 : _GEN_525; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_528 = regs_virtualToPhysicalMap_3 == 5'ha ? _GEN_526 : _GEN_522; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_529 = regs_virtualToPhysicalMap_3 == 5'ha ? _GEN_527 : _GEN_523; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_530 = regs_virtualPortOutput[2] ? _OUTPUT_T_401 : _OUTPUT_T_404; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_531 = regs_INPUT[10] ? _virtualPortOutput_T_26 : _virtualPortOutput_T_29; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_532 = regs_DIRECTION[10] ? _GEN_530 : _GEN_528; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_533 = regs_DIRECTION[10] ? _GEN_529 : _GEN_531; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_534 = regs_virtualToPhysicalMap_2 == 5'ha ? _GEN_532 : _GEN_528; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_535 = regs_virtualToPhysicalMap_2 == 5'ha ? _GEN_533 : _GEN_529; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_536 = regs_virtualPortOutput[1] ? _OUTPUT_T_401 : _OUTPUT_T_404; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_537 = regs_INPUT[10] ? _virtualPortOutput_T_31 : _virtualPortOutput_T_34; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_538 = regs_DIRECTION[10] ? _GEN_536 : _GEN_534; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_539 = regs_DIRECTION[10] ? _GEN_535 : _GEN_537; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_540 = regs_virtualToPhysicalMap_1 == 5'ha ? _GEN_538 : _GEN_534; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_541 = regs_virtualToPhysicalMap_1 == 5'ha ? _GEN_539 : _GEN_535; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_542 = regs_virtualPortOutput[0] ? _OUTPUT_T_401 : _OUTPUT_T_404; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_543 = regs_INPUT[10] ? _virtualPortOutput_T_36 : 8'h0; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_544 = regs_DIRECTION[10] ? _GEN_542 : _GEN_540; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_545 = regs_DIRECTION[10] ? _GEN_541 : _GEN_543; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_546 = regs_virtualToPhysicalMap_0 == 5'ha ? _GEN_544 : _GEN_540; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_547 = regs_virtualToPhysicalMap_0 == 5'ha ? _GEN_545 : _GEN_541; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_548 = regs_virtualPortEnable ? _GEN_546 : _GEN_498; // @[src/main/scala/GPIO.scala 34:71]
  wire [7:0] _GEN_549 = regs_virtualPortEnable ? _GEN_547 : _GEN_499; // @[src/main/scala/GPIO.scala 34:71]
  wire [15:0] _OUTPUT_T_441 = regs_OUTPUT | 16'h800; // @[src/main/scala/GPIO.scala 40:40]
  wire [15:0] _OUTPUT_T_444 = regs_OUTPUT & 16'hf7ff; // @[src/main/scala/GPIO.scala 41:50]
  wire [15:0] _GEN_550 = regs_virtualPortOutput[7] ? _OUTPUT_T_441 : _OUTPUT_T_444; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_551 = regs_INPUT[11] ? _virtualPortOutput_T_1 : _virtualPortOutput_T_4; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_552 = regs_DIRECTION[11] ? _GEN_550 : _GEN_548; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_553 = regs_DIRECTION[11] ? _GEN_549 : _GEN_551; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_554 = regs_virtualToPhysicalMap_7 == 5'hb ? _GEN_552 : _GEN_548; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_555 = regs_virtualToPhysicalMap_7 == 5'hb ? _GEN_553 : _GEN_549; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_556 = regs_virtualPortOutput[6] ? _OUTPUT_T_441 : _OUTPUT_T_444; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_557 = regs_INPUT[11] ? _virtualPortOutput_T_6 : _virtualPortOutput_T_9; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_558 = regs_DIRECTION[11] ? _GEN_556 : _GEN_554; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_559 = regs_DIRECTION[11] ? _GEN_555 : _GEN_557; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_560 = regs_virtualToPhysicalMap_6 == 5'hb ? _GEN_558 : _GEN_554; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_561 = regs_virtualToPhysicalMap_6 == 5'hb ? _GEN_559 : _GEN_555; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_562 = regs_virtualPortOutput[5] ? _OUTPUT_T_441 : _OUTPUT_T_444; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_563 = regs_INPUT[11] ? _virtualPortOutput_T_11 : _virtualPortOutput_T_14; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_564 = regs_DIRECTION[11] ? _GEN_562 : _GEN_560; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_565 = regs_DIRECTION[11] ? _GEN_561 : _GEN_563; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_566 = regs_virtualToPhysicalMap_5 == 5'hb ? _GEN_564 : _GEN_560; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_567 = regs_virtualToPhysicalMap_5 == 5'hb ? _GEN_565 : _GEN_561; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_568 = regs_virtualPortOutput[4] ? _OUTPUT_T_441 : _OUTPUT_T_444; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_569 = regs_INPUT[11] ? _virtualPortOutput_T_16 : _virtualPortOutput_T_19; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_570 = regs_DIRECTION[11] ? _GEN_568 : _GEN_566; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_571 = regs_DIRECTION[11] ? _GEN_567 : _GEN_569; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_572 = regs_virtualToPhysicalMap_4 == 5'hb ? _GEN_570 : _GEN_566; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_573 = regs_virtualToPhysicalMap_4 == 5'hb ? _GEN_571 : _GEN_567; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_574 = regs_virtualPortOutput[3] ? _OUTPUT_T_441 : _OUTPUT_T_444; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_575 = regs_INPUT[11] ? _virtualPortOutput_T_21 : _virtualPortOutput_T_24; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_576 = regs_DIRECTION[11] ? _GEN_574 : _GEN_572; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_577 = regs_DIRECTION[11] ? _GEN_573 : _GEN_575; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_578 = regs_virtualToPhysicalMap_3 == 5'hb ? _GEN_576 : _GEN_572; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_579 = regs_virtualToPhysicalMap_3 == 5'hb ? _GEN_577 : _GEN_573; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_580 = regs_virtualPortOutput[2] ? _OUTPUT_T_441 : _OUTPUT_T_444; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_581 = regs_INPUT[11] ? _virtualPortOutput_T_26 : _virtualPortOutput_T_29; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_582 = regs_DIRECTION[11] ? _GEN_580 : _GEN_578; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_583 = regs_DIRECTION[11] ? _GEN_579 : _GEN_581; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_584 = regs_virtualToPhysicalMap_2 == 5'hb ? _GEN_582 : _GEN_578; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_585 = regs_virtualToPhysicalMap_2 == 5'hb ? _GEN_583 : _GEN_579; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_586 = regs_virtualPortOutput[1] ? _OUTPUT_T_441 : _OUTPUT_T_444; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_587 = regs_INPUT[11] ? _virtualPortOutput_T_31 : _virtualPortOutput_T_34; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_588 = regs_DIRECTION[11] ? _GEN_586 : _GEN_584; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_589 = regs_DIRECTION[11] ? _GEN_585 : _GEN_587; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_590 = regs_virtualToPhysicalMap_1 == 5'hb ? _GEN_588 : _GEN_584; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_591 = regs_virtualToPhysicalMap_1 == 5'hb ? _GEN_589 : _GEN_585; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_592 = regs_virtualPortOutput[0] ? _OUTPUT_T_441 : _OUTPUT_T_444; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_593 = regs_INPUT[11] ? _virtualPortOutput_T_36 : 8'h0; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_594 = regs_DIRECTION[11] ? _GEN_592 : _GEN_590; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_595 = regs_DIRECTION[11] ? _GEN_591 : _GEN_593; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_596 = regs_virtualToPhysicalMap_0 == 5'hb ? _GEN_594 : _GEN_590; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_597 = regs_virtualToPhysicalMap_0 == 5'hb ? _GEN_595 : _GEN_591; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_598 = regs_virtualPortEnable ? _GEN_596 : _GEN_548; // @[src/main/scala/GPIO.scala 34:71]
  wire [7:0] _GEN_599 = regs_virtualPortEnable ? _GEN_597 : _GEN_549; // @[src/main/scala/GPIO.scala 34:71]
  wire [15:0] _OUTPUT_T_481 = regs_OUTPUT | 16'h1000; // @[src/main/scala/GPIO.scala 40:40]
  wire [15:0] _OUTPUT_T_484 = regs_OUTPUT & 16'hefff; // @[src/main/scala/GPIO.scala 41:50]
  wire [15:0] _GEN_600 = regs_virtualPortOutput[7] ? _OUTPUT_T_481 : _OUTPUT_T_484; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_601 = regs_INPUT[12] ? _virtualPortOutput_T_1 : _virtualPortOutput_T_4; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_602 = regs_DIRECTION[12] ? _GEN_600 : _GEN_598; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_603 = regs_DIRECTION[12] ? _GEN_599 : _GEN_601; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_604 = regs_virtualToPhysicalMap_7 == 5'hc ? _GEN_602 : _GEN_598; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_605 = regs_virtualToPhysicalMap_7 == 5'hc ? _GEN_603 : _GEN_599; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_606 = regs_virtualPortOutput[6] ? _OUTPUT_T_481 : _OUTPUT_T_484; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_607 = regs_INPUT[12] ? _virtualPortOutput_T_6 : _virtualPortOutput_T_9; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_608 = regs_DIRECTION[12] ? _GEN_606 : _GEN_604; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_609 = regs_DIRECTION[12] ? _GEN_605 : _GEN_607; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_610 = regs_virtualToPhysicalMap_6 == 5'hc ? _GEN_608 : _GEN_604; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_611 = regs_virtualToPhysicalMap_6 == 5'hc ? _GEN_609 : _GEN_605; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_612 = regs_virtualPortOutput[5] ? _OUTPUT_T_481 : _OUTPUT_T_484; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_613 = regs_INPUT[12] ? _virtualPortOutput_T_11 : _virtualPortOutput_T_14; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_614 = regs_DIRECTION[12] ? _GEN_612 : _GEN_610; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_615 = regs_DIRECTION[12] ? _GEN_611 : _GEN_613; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_616 = regs_virtualToPhysicalMap_5 == 5'hc ? _GEN_614 : _GEN_610; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_617 = regs_virtualToPhysicalMap_5 == 5'hc ? _GEN_615 : _GEN_611; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_618 = regs_virtualPortOutput[4] ? _OUTPUT_T_481 : _OUTPUT_T_484; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_619 = regs_INPUT[12] ? _virtualPortOutput_T_16 : _virtualPortOutput_T_19; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_620 = regs_DIRECTION[12] ? _GEN_618 : _GEN_616; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_621 = regs_DIRECTION[12] ? _GEN_617 : _GEN_619; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_622 = regs_virtualToPhysicalMap_4 == 5'hc ? _GEN_620 : _GEN_616; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_623 = regs_virtualToPhysicalMap_4 == 5'hc ? _GEN_621 : _GEN_617; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_624 = regs_virtualPortOutput[3] ? _OUTPUT_T_481 : _OUTPUT_T_484; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_625 = regs_INPUT[12] ? _virtualPortOutput_T_21 : _virtualPortOutput_T_24; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_626 = regs_DIRECTION[12] ? _GEN_624 : _GEN_622; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_627 = regs_DIRECTION[12] ? _GEN_623 : _GEN_625; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_628 = regs_virtualToPhysicalMap_3 == 5'hc ? _GEN_626 : _GEN_622; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_629 = regs_virtualToPhysicalMap_3 == 5'hc ? _GEN_627 : _GEN_623; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_630 = regs_virtualPortOutput[2] ? _OUTPUT_T_481 : _OUTPUT_T_484; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_631 = regs_INPUT[12] ? _virtualPortOutput_T_26 : _virtualPortOutput_T_29; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_632 = regs_DIRECTION[12] ? _GEN_630 : _GEN_628; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_633 = regs_DIRECTION[12] ? _GEN_629 : _GEN_631; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_634 = regs_virtualToPhysicalMap_2 == 5'hc ? _GEN_632 : _GEN_628; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_635 = regs_virtualToPhysicalMap_2 == 5'hc ? _GEN_633 : _GEN_629; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_636 = regs_virtualPortOutput[1] ? _OUTPUT_T_481 : _OUTPUT_T_484; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_637 = regs_INPUT[12] ? _virtualPortOutput_T_31 : _virtualPortOutput_T_34; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_638 = regs_DIRECTION[12] ? _GEN_636 : _GEN_634; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_639 = regs_DIRECTION[12] ? _GEN_635 : _GEN_637; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_640 = regs_virtualToPhysicalMap_1 == 5'hc ? _GEN_638 : _GEN_634; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_641 = regs_virtualToPhysicalMap_1 == 5'hc ? _GEN_639 : _GEN_635; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_642 = regs_virtualPortOutput[0] ? _OUTPUT_T_481 : _OUTPUT_T_484; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_643 = regs_INPUT[12] ? _virtualPortOutput_T_36 : 8'h0; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_644 = regs_DIRECTION[12] ? _GEN_642 : _GEN_640; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_645 = regs_DIRECTION[12] ? _GEN_641 : _GEN_643; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_646 = regs_virtualToPhysicalMap_0 == 5'hc ? _GEN_644 : _GEN_640; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_647 = regs_virtualToPhysicalMap_0 == 5'hc ? _GEN_645 : _GEN_641; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_648 = regs_virtualPortEnable ? _GEN_646 : _GEN_598; // @[src/main/scala/GPIO.scala 34:71]
  wire [7:0] _GEN_649 = regs_virtualPortEnable ? _GEN_647 : _GEN_599; // @[src/main/scala/GPIO.scala 34:71]
  wire [15:0] _OUTPUT_T_521 = regs_OUTPUT | 16'h2000; // @[src/main/scala/GPIO.scala 40:40]
  wire [15:0] _OUTPUT_T_524 = regs_OUTPUT & 16'hdfff; // @[src/main/scala/GPIO.scala 41:50]
  wire [15:0] _GEN_650 = regs_virtualPortOutput[7] ? _OUTPUT_T_521 : _OUTPUT_T_524; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_651 = regs_INPUT[13] ? _virtualPortOutput_T_1 : _virtualPortOutput_T_4; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_652 = regs_DIRECTION[13] ? _GEN_650 : _GEN_648; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_653 = regs_DIRECTION[13] ? _GEN_649 : _GEN_651; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_654 = regs_virtualToPhysicalMap_7 == 5'hd ? _GEN_652 : _GEN_648; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_655 = regs_virtualToPhysicalMap_7 == 5'hd ? _GEN_653 : _GEN_649; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_656 = regs_virtualPortOutput[6] ? _OUTPUT_T_521 : _OUTPUT_T_524; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_657 = regs_INPUT[13] ? _virtualPortOutput_T_6 : _virtualPortOutput_T_9; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_658 = regs_DIRECTION[13] ? _GEN_656 : _GEN_654; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_659 = regs_DIRECTION[13] ? _GEN_655 : _GEN_657; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_660 = regs_virtualToPhysicalMap_6 == 5'hd ? _GEN_658 : _GEN_654; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_661 = regs_virtualToPhysicalMap_6 == 5'hd ? _GEN_659 : _GEN_655; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_662 = regs_virtualPortOutput[5] ? _OUTPUT_T_521 : _OUTPUT_T_524; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_663 = regs_INPUT[13] ? _virtualPortOutput_T_11 : _virtualPortOutput_T_14; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_664 = regs_DIRECTION[13] ? _GEN_662 : _GEN_660; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_665 = regs_DIRECTION[13] ? _GEN_661 : _GEN_663; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_666 = regs_virtualToPhysicalMap_5 == 5'hd ? _GEN_664 : _GEN_660; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_667 = regs_virtualToPhysicalMap_5 == 5'hd ? _GEN_665 : _GEN_661; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_668 = regs_virtualPortOutput[4] ? _OUTPUT_T_521 : _OUTPUT_T_524; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_669 = regs_INPUT[13] ? _virtualPortOutput_T_16 : _virtualPortOutput_T_19; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_670 = regs_DIRECTION[13] ? _GEN_668 : _GEN_666; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_671 = regs_DIRECTION[13] ? _GEN_667 : _GEN_669; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_672 = regs_virtualToPhysicalMap_4 == 5'hd ? _GEN_670 : _GEN_666; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_673 = regs_virtualToPhysicalMap_4 == 5'hd ? _GEN_671 : _GEN_667; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_674 = regs_virtualPortOutput[3] ? _OUTPUT_T_521 : _OUTPUT_T_524; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_675 = regs_INPUT[13] ? _virtualPortOutput_T_21 : _virtualPortOutput_T_24; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_676 = regs_DIRECTION[13] ? _GEN_674 : _GEN_672; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_677 = regs_DIRECTION[13] ? _GEN_673 : _GEN_675; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_678 = regs_virtualToPhysicalMap_3 == 5'hd ? _GEN_676 : _GEN_672; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_679 = regs_virtualToPhysicalMap_3 == 5'hd ? _GEN_677 : _GEN_673; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_680 = regs_virtualPortOutput[2] ? _OUTPUT_T_521 : _OUTPUT_T_524; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_681 = regs_INPUT[13] ? _virtualPortOutput_T_26 : _virtualPortOutput_T_29; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_682 = regs_DIRECTION[13] ? _GEN_680 : _GEN_678; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_683 = regs_DIRECTION[13] ? _GEN_679 : _GEN_681; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_684 = regs_virtualToPhysicalMap_2 == 5'hd ? _GEN_682 : _GEN_678; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_685 = regs_virtualToPhysicalMap_2 == 5'hd ? _GEN_683 : _GEN_679; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_686 = regs_virtualPortOutput[1] ? _OUTPUT_T_521 : _OUTPUT_T_524; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_687 = regs_INPUT[13] ? _virtualPortOutput_T_31 : _virtualPortOutput_T_34; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_688 = regs_DIRECTION[13] ? _GEN_686 : _GEN_684; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_689 = regs_DIRECTION[13] ? _GEN_685 : _GEN_687; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_690 = regs_virtualToPhysicalMap_1 == 5'hd ? _GEN_688 : _GEN_684; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_691 = regs_virtualToPhysicalMap_1 == 5'hd ? _GEN_689 : _GEN_685; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_692 = regs_virtualPortOutput[0] ? _OUTPUT_T_521 : _OUTPUT_T_524; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_693 = regs_INPUT[13] ? _virtualPortOutput_T_36 : 8'h0; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_694 = regs_DIRECTION[13] ? _GEN_692 : _GEN_690; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_695 = regs_DIRECTION[13] ? _GEN_691 : _GEN_693; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_696 = regs_virtualToPhysicalMap_0 == 5'hd ? _GEN_694 : _GEN_690; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_697 = regs_virtualToPhysicalMap_0 == 5'hd ? _GEN_695 : _GEN_691; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_698 = regs_virtualPortEnable ? _GEN_696 : _GEN_648; // @[src/main/scala/GPIO.scala 34:71]
  wire [7:0] _GEN_699 = regs_virtualPortEnable ? _GEN_697 : _GEN_649; // @[src/main/scala/GPIO.scala 34:71]
  wire [15:0] _OUTPUT_T_561 = regs_OUTPUT | 16'h4000; // @[src/main/scala/GPIO.scala 40:40]
  wire [15:0] _OUTPUT_T_564 = regs_OUTPUT & 16'hbfff; // @[src/main/scala/GPIO.scala 41:50]
  wire [15:0] _GEN_700 = regs_virtualPortOutput[7] ? _OUTPUT_T_561 : _OUTPUT_T_564; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_701 = regs_INPUT[14] ? _virtualPortOutput_T_1 : _virtualPortOutput_T_4; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_702 = regs_DIRECTION[14] ? _GEN_700 : _GEN_698; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_703 = regs_DIRECTION[14] ? _GEN_699 : _GEN_701; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_704 = regs_virtualToPhysicalMap_7 == 5'he ? _GEN_702 : _GEN_698; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_705 = regs_virtualToPhysicalMap_7 == 5'he ? _GEN_703 : _GEN_699; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_706 = regs_virtualPortOutput[6] ? _OUTPUT_T_561 : _OUTPUT_T_564; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_707 = regs_INPUT[14] ? _virtualPortOutput_T_6 : _virtualPortOutput_T_9; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_708 = regs_DIRECTION[14] ? _GEN_706 : _GEN_704; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_709 = regs_DIRECTION[14] ? _GEN_705 : _GEN_707; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_710 = regs_virtualToPhysicalMap_6 == 5'he ? _GEN_708 : _GEN_704; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_711 = regs_virtualToPhysicalMap_6 == 5'he ? _GEN_709 : _GEN_705; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_712 = regs_virtualPortOutput[5] ? _OUTPUT_T_561 : _OUTPUT_T_564; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_713 = regs_INPUT[14] ? _virtualPortOutput_T_11 : _virtualPortOutput_T_14; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_714 = regs_DIRECTION[14] ? _GEN_712 : _GEN_710; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_715 = regs_DIRECTION[14] ? _GEN_711 : _GEN_713; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_716 = regs_virtualToPhysicalMap_5 == 5'he ? _GEN_714 : _GEN_710; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_717 = regs_virtualToPhysicalMap_5 == 5'he ? _GEN_715 : _GEN_711; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_718 = regs_virtualPortOutput[4] ? _OUTPUT_T_561 : _OUTPUT_T_564; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_719 = regs_INPUT[14] ? _virtualPortOutput_T_16 : _virtualPortOutput_T_19; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_720 = regs_DIRECTION[14] ? _GEN_718 : _GEN_716; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_721 = regs_DIRECTION[14] ? _GEN_717 : _GEN_719; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_722 = regs_virtualToPhysicalMap_4 == 5'he ? _GEN_720 : _GEN_716; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_723 = regs_virtualToPhysicalMap_4 == 5'he ? _GEN_721 : _GEN_717; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_724 = regs_virtualPortOutput[3] ? _OUTPUT_T_561 : _OUTPUT_T_564; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_725 = regs_INPUT[14] ? _virtualPortOutput_T_21 : _virtualPortOutput_T_24; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_726 = regs_DIRECTION[14] ? _GEN_724 : _GEN_722; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_727 = regs_DIRECTION[14] ? _GEN_723 : _GEN_725; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_728 = regs_virtualToPhysicalMap_3 == 5'he ? _GEN_726 : _GEN_722; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_729 = regs_virtualToPhysicalMap_3 == 5'he ? _GEN_727 : _GEN_723; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_730 = regs_virtualPortOutput[2] ? _OUTPUT_T_561 : _OUTPUT_T_564; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_731 = regs_INPUT[14] ? _virtualPortOutput_T_26 : _virtualPortOutput_T_29; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_732 = regs_DIRECTION[14] ? _GEN_730 : _GEN_728; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_733 = regs_DIRECTION[14] ? _GEN_729 : _GEN_731; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_734 = regs_virtualToPhysicalMap_2 == 5'he ? _GEN_732 : _GEN_728; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_735 = regs_virtualToPhysicalMap_2 == 5'he ? _GEN_733 : _GEN_729; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_736 = regs_virtualPortOutput[1] ? _OUTPUT_T_561 : _OUTPUT_T_564; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_737 = regs_INPUT[14] ? _virtualPortOutput_T_31 : _virtualPortOutput_T_34; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_738 = regs_DIRECTION[14] ? _GEN_736 : _GEN_734; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_739 = regs_DIRECTION[14] ? _GEN_735 : _GEN_737; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_740 = regs_virtualToPhysicalMap_1 == 5'he ? _GEN_738 : _GEN_734; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_741 = regs_virtualToPhysicalMap_1 == 5'he ? _GEN_739 : _GEN_735; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_742 = regs_virtualPortOutput[0] ? _OUTPUT_T_561 : _OUTPUT_T_564; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_743 = regs_INPUT[14] ? _virtualPortOutput_T_36 : 8'h0; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_744 = regs_DIRECTION[14] ? _GEN_742 : _GEN_740; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_745 = regs_DIRECTION[14] ? _GEN_741 : _GEN_743; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_746 = regs_virtualToPhysicalMap_0 == 5'he ? _GEN_744 : _GEN_740; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_747 = regs_virtualToPhysicalMap_0 == 5'he ? _GEN_745 : _GEN_741; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_748 = regs_virtualPortEnable ? _GEN_746 : _GEN_698; // @[src/main/scala/GPIO.scala 34:71]
  wire [7:0] _GEN_749 = regs_virtualPortEnable ? _GEN_747 : _GEN_699; // @[src/main/scala/GPIO.scala 34:71]
  wire [15:0] _OUTPUT_T_601 = regs_OUTPUT | 16'h8000; // @[src/main/scala/GPIO.scala 40:40]
  wire [15:0] _OUTPUT_T_604 = regs_OUTPUT & 16'h7fff; // @[src/main/scala/GPIO.scala 41:50]
  wire [15:0] _GEN_750 = regs_virtualPortOutput[7] ? _OUTPUT_T_601 : _OUTPUT_T_604; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_751 = regs_INPUT[15] ? _virtualPortOutput_T_1 : _virtualPortOutput_T_4; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_752 = regs_DIRECTION[15] ? _GEN_750 : _GEN_748; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_753 = regs_DIRECTION[15] ? _GEN_749 : _GEN_751; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_754 = regs_virtualToPhysicalMap_7 == 5'hf ? _GEN_752 : _GEN_748; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_755 = regs_virtualToPhysicalMap_7 == 5'hf ? _GEN_753 : _GEN_749; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_756 = regs_virtualPortOutput[6] ? _OUTPUT_T_601 : _OUTPUT_T_604; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_757 = regs_INPUT[15] ? _virtualPortOutput_T_6 : _virtualPortOutput_T_9; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_758 = regs_DIRECTION[15] ? _GEN_756 : _GEN_754; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_759 = regs_DIRECTION[15] ? _GEN_755 : _GEN_757; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_760 = regs_virtualToPhysicalMap_6 == 5'hf ? _GEN_758 : _GEN_754; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_761 = regs_virtualToPhysicalMap_6 == 5'hf ? _GEN_759 : _GEN_755; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_762 = regs_virtualPortOutput[5] ? _OUTPUT_T_601 : _OUTPUT_T_604; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_763 = regs_INPUT[15] ? _virtualPortOutput_T_11 : _virtualPortOutput_T_14; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_764 = regs_DIRECTION[15] ? _GEN_762 : _GEN_760; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_765 = regs_DIRECTION[15] ? _GEN_761 : _GEN_763; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_766 = regs_virtualToPhysicalMap_5 == 5'hf ? _GEN_764 : _GEN_760; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_767 = regs_virtualToPhysicalMap_5 == 5'hf ? _GEN_765 : _GEN_761; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_768 = regs_virtualPortOutput[4] ? _OUTPUT_T_601 : _OUTPUT_T_604; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_769 = regs_INPUT[15] ? _virtualPortOutput_T_16 : _virtualPortOutput_T_19; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_770 = regs_DIRECTION[15] ? _GEN_768 : _GEN_766; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_771 = regs_DIRECTION[15] ? _GEN_767 : _GEN_769; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_772 = regs_virtualToPhysicalMap_4 == 5'hf ? _GEN_770 : _GEN_766; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_773 = regs_virtualToPhysicalMap_4 == 5'hf ? _GEN_771 : _GEN_767; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_774 = regs_virtualPortOutput[3] ? _OUTPUT_T_601 : _OUTPUT_T_604; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_775 = regs_INPUT[15] ? _virtualPortOutput_T_21 : _virtualPortOutput_T_24; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_776 = regs_DIRECTION[15] ? _GEN_774 : _GEN_772; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_777 = regs_DIRECTION[15] ? _GEN_773 : _GEN_775; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_778 = regs_virtualToPhysicalMap_3 == 5'hf ? _GEN_776 : _GEN_772; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_779 = regs_virtualToPhysicalMap_3 == 5'hf ? _GEN_777 : _GEN_773; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_780 = regs_virtualPortOutput[2] ? _OUTPUT_T_601 : _OUTPUT_T_604; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_781 = regs_INPUT[15] ? _virtualPortOutput_T_26 : _virtualPortOutput_T_29; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_782 = regs_DIRECTION[15] ? _GEN_780 : _GEN_778; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_783 = regs_DIRECTION[15] ? _GEN_779 : _GEN_781; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_784 = regs_virtualToPhysicalMap_2 == 5'hf ? _GEN_782 : _GEN_778; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_785 = regs_virtualToPhysicalMap_2 == 5'hf ? _GEN_783 : _GEN_779; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_786 = regs_virtualPortOutput[1] ? _OUTPUT_T_601 : _OUTPUT_T_604; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_787 = regs_INPUT[15] ? _virtualPortOutput_T_31 : _virtualPortOutput_T_34; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_788 = regs_DIRECTION[15] ? _GEN_786 : _GEN_784; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_789 = regs_DIRECTION[15] ? _GEN_785 : _GEN_787; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_790 = regs_virtualToPhysicalMap_1 == 5'hf ? _GEN_788 : _GEN_784; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_791 = regs_virtualToPhysicalMap_1 == 5'hf ? _GEN_789 : _GEN_785; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_792 = regs_virtualPortOutput[0] ? _OUTPUT_T_601 : _OUTPUT_T_604; // @[src/main/scala/GPIO.scala 39:51 40:25 41:35]
  wire [7:0] _GEN_793 = regs_INPUT[15] ? _virtualPortOutput_T_36 : 8'h0; // @[src/main/scala/GPIO.scala 43:39 44:36 46:36]
  wire [15:0] _GEN_794 = regs_DIRECTION[15] ? _GEN_792 : _GEN_790; // @[src/main/scala/GPIO.scala 38:41]
  wire [7:0] _GEN_795 = regs_DIRECTION[15] ? _GEN_791 : _GEN_793; // @[src/main/scala/GPIO.scala 38:41]
  wire [15:0] _GEN_796 = regs_virtualToPhysicalMap_0 == 5'hf ? _GEN_794 : _GEN_790; // @[src/main/scala/GPIO.scala 36:50]
  wire [7:0] _GEN_797 = regs_virtualToPhysicalMap_0 == 5'hf ? _GEN_795 : _GEN_791; // @[src/main/scala/GPIO.scala 36:50]
  wire [15:0] _GEN_798 = regs_virtualPortEnable ? _GEN_796 : _GEN_748; // @[src/main/scala/GPIO.scala 34:71]
  wire [7:0] _GEN_799 = regs_virtualPortEnable ? _GEN_797 : _GEN_749; // @[src/main/scala/GPIO.scala 34:71]
  wire  _T_912 = io_apb_PSEL & io_apb_PENABLE; // @[src/main/scala/GPIO.scala 53:20]
  wire  _T_914 = io_apb_PADDR <= 8'h1; // @[src/main/scala/GPIO.scala 174:48]
  wire  _T_916 = ~reset; // @[src/main/scala/GPIO.scala 175:13]
  wire [7:0] shiftAddr = io_apb_PADDR - 8'h0; // @[src/main/scala/GPIO.scala 180:28]
  wire [5:0] _DIRECTION_T_2 = shiftAddr[1:0] * 4'h8; // @[src/main/scala/GPIO.scala 183:54]
  wire [78:0] _GEN_801 = {{63'd0}, io_apb_PWDATA}; // @[src/main/scala/GPIO.scala 182:52]
  wire [78:0] _DIRECTION_T_3 = _GEN_801 << _DIRECTION_T_2; // @[src/main/scala/GPIO.scala 182:52]
  wire [78:0] _GEN_800 = io_apb_PADDR <= 8'h1 ? _DIRECTION_T_3 : {{63'd0}, regs_DIRECTION}; // @[src/main/scala/GPIO.scala 174:78 181:22 src/main/scala/GPIORegs.scala 34:26]
  wire  _T_919 = io_apb_PADDR >= 8'h4 & io_apb_PADDR <= 8'h5; // @[src/main/scala/GPIO.scala 185:36]
  wire  _T_923 = io_apb_PADDR >= 8'h2 & io_apb_PADDR <= 8'h3; // @[src/main/scala/GPIO.scala 192:37]
  wire [7:0] shiftAddr_2 = io_apb_PADDR - 8'h2; // @[src/main/scala/GPIO.scala 198:28]
  wire [5:0] _OUTPUT_T_642 = shiftAddr_2[1:0] * 4'h8; // @[src/main/scala/GPIO.scala 201:51]
  wire [78:0] _GEN_828 = {{63'd0}, io_apb_PWDATA}; // @[src/main/scala/GPIO.scala 200:49]
  wire [78:0] _OUTPUT_T_643 = _GEN_828 << _OUTPUT_T_642; // @[src/main/scala/GPIO.scala 200:49]
  wire [78:0] _GEN_802 = io_apb_PADDR >= 8'h2 & io_apb_PADDR <= 8'h3 ? _OUTPUT_T_643 : {{63'd0}, _GEN_798}; // @[src/main/scala/GPIO.scala 192:72 199:19]
  wire  _T_927 = io_apb_PADDR >= 8'h6 & io_apb_PADDR <= 8'h7; // @[src/main/scala/GPIO.scala 203:35]
  wire [7:0] shiftAddr_3 = io_apb_PADDR - 8'h6; // @[src/main/scala/GPIO.scala 205:28]
  wire [5:0] _MODE_T_2 = shiftAddr_3[1:0] * 4'h8; // @[src/main/scala/GPIO.scala 208:49]
  wire [78:0] _GEN_837 = {{63'd0}, io_apb_PWDATA}; // @[src/main/scala/GPIO.scala 207:47]
  wire [78:0] _MODE_T_3 = _GEN_837 << _MODE_T_2; // @[src/main/scala/GPIO.scala 207:47]
  wire [78:0] _GEN_803 = io_apb_PADDR >= 8'h6 & io_apb_PADDR <= 8'h7 ? _MODE_T_3 : {{63'd0}, regs_MODE}; // @[src/main/scala/GPIO.scala 203:68 206:17 src/main/scala/GPIORegs.scala 37:21]
  wire  _T_930 = io_apb_PADDR <= 8'h8; // @[src/main/scala/GPIO.scala 212:14]
  wire  _T_931 = io_apb_PADDR >= 8'h8 & _T_930; // @[src/main/scala/GPIO.scala 211:44]
  wire [7:0] shiftAddr_4 = io_apb_PADDR - 8'h8; // @[src/main/scala/GPIO.scala 219:28]
  wire [4:0] _ATOMIC_OPERATION_T_2 = shiftAddr_4[0] * 4'h8; // @[src/main/scala/GPIO.scala 222:61]
  wire [34:0] _GEN_845 = {{31'd0}, io_apb_PWDATA[3:0]}; // @[src/main/scala/GPIO.scala 221:59]
  wire [34:0] _ATOMIC_OPERATION_T_3 = _GEN_845 << _ATOMIC_OPERATION_T_2; // @[src/main/scala/GPIO.scala 221:59]
  wire [34:0] _GEN_804 = _T_931 ? _ATOMIC_OPERATION_T_3 : {{31'd0}, regs_ATOMIC_OPERATION}; // @[src/main/scala/GPIO.scala 213:7 220:29 src/main/scala/GPIORegs.scala 40:33]
  wire  _T_935 = io_apb_PADDR >= 8'h9 & io_apb_PADDR <= 8'ha; // @[src/main/scala/GPIO.scala 224:42]
  wire [7:0] shiftAddr_5 = io_apb_PADDR - 8'h9; // @[src/main/scala/GPIO.scala 230:28]
  wire [5:0] _ATOMIC_MASK_T_2 = shiftAddr_5[1:0] * 4'h8; // @[src/main/scala/GPIO.scala 233:56]
  wire [78:0] _GEN_846 = {{63'd0}, io_apb_PWDATA}; // @[src/main/scala/GPIO.scala 232:54]
  wire [78:0] _ATOMIC_MASK_T_3 = _GEN_846 << _ATOMIC_MASK_T_2; // @[src/main/scala/GPIO.scala 232:54]
  wire [78:0] _GEN_805 = io_apb_PADDR >= 8'h9 & io_apb_PADDR <= 8'ha ? _ATOMIC_MASK_T_3 : {{63'd0}, regs_ATOMIC_MASK}; // @[src/main/scala/GPIO.scala 224:82 231:24 src/main/scala/GPIORegs.scala 41:28]
  wire  _T_939 = io_apb_PADDR >= 8'hb & io_apb_PADDR <= 8'hb; // @[src/main/scala/GPIO.scala 235:41]
  wire [7:0] shiftAddr_6 = io_apb_PADDR - 8'hb; // @[src/main/scala/GPIO.scala 241:28]
  wire [4:0] _ATOMIC_SET_T_2 = shiftAddr_6[0] * 4'h8; // @[src/main/scala/GPIO.scala 244:55]
  wire [31:0] _GEN_847 = {{31'd0}, io_apb_PWDATA[0]}; // @[src/main/scala/GPIO.scala 243:53]
  wire [31:0] _ATOMIC_SET_T_3 = _GEN_847 << _ATOMIC_SET_T_2; // @[src/main/scala/GPIO.scala 243:53]
  wire [31:0] _GEN_806 = io_apb_PADDR >= 8'hb & io_apb_PADDR <= 8'hb ? _ATOMIC_SET_T_3 : {{31'd0}, regs_ATOMIC_SET}; // @[src/main/scala/GPIO.scala 235:80 242:23 src/main/scala/GPIORegs.scala 42:27]
  wire  _T_942 = io_apb_PADDR <= 8'h13; // @[src/main/scala/GPIO.scala 248:14]
  wire  _T_943 = io_apb_PADDR >= 8'hc & _T_942; // @[src/main/scala/GPIO.scala 247:44]
  wire [7:0] _index_T_1 = io_apb_PADDR - 8'hc; // @[src/main/scala/GPIO.scala 257:15]
  wire [7:0] index = _index_T_1 / 1'h1; // @[src/main/scala/GPIO.scala 257:47]
  wire [4:0] _GEN_807 = 3'h0 == index[2:0] ? io_apb_PWDATA[4:0] : regs_virtualToPhysicalMap_0; // @[src/main/scala/GPIO.scala 258:{40,40} src/main/scala/GPIORegs.scala 48:12]
  wire [4:0] _GEN_808 = 3'h1 == index[2:0] ? io_apb_PWDATA[4:0] : regs_virtualToPhysicalMap_1; // @[src/main/scala/GPIO.scala 258:{40,40} src/main/scala/GPIORegs.scala 48:12]
  wire [4:0] _GEN_809 = 3'h2 == index[2:0] ? io_apb_PWDATA[4:0] : regs_virtualToPhysicalMap_2; // @[src/main/scala/GPIO.scala 258:{40,40} src/main/scala/GPIORegs.scala 48:12]
  wire [4:0] _GEN_810 = 3'h3 == index[2:0] ? io_apb_PWDATA[4:0] : regs_virtualToPhysicalMap_3; // @[src/main/scala/GPIO.scala 258:{40,40} src/main/scala/GPIORegs.scala 48:12]
  wire [4:0] _GEN_811 = 3'h4 == index[2:0] ? io_apb_PWDATA[4:0] : regs_virtualToPhysicalMap_4; // @[src/main/scala/GPIO.scala 258:{40,40} src/main/scala/GPIORegs.scala 48:12]
  wire [4:0] _GEN_812 = 3'h5 == index[2:0] ? io_apb_PWDATA[4:0] : regs_virtualToPhysicalMap_5; // @[src/main/scala/GPIO.scala 258:{40,40} src/main/scala/GPIORegs.scala 48:12]
  wire [4:0] _GEN_813 = 3'h6 == index[2:0] ? io_apb_PWDATA[4:0] : regs_virtualToPhysicalMap_6; // @[src/main/scala/GPIO.scala 258:{40,40} src/main/scala/GPIORegs.scala 48:12]
  wire [4:0] _GEN_814 = 3'h7 == index[2:0] ? io_apb_PWDATA[4:0] : regs_virtualToPhysicalMap_7; // @[src/main/scala/GPIO.scala 258:{40,40} src/main/scala/GPIORegs.scala 48:12]
  wire  _T_947 = io_apb_PADDR <= 8'h14; // @[src/main/scala/GPIO.scala 263:14]
  wire  _T_948 = io_apb_PADDR >= 8'h14 & _T_947; // @[src/main/scala/GPIO.scala 262:47]
  wire [7:0] shiftAddr_7 = io_apb_PADDR - 8'h14; // @[src/main/scala/GPIO.scala 270:28]
  wire [4:0] _virtualPortOutput_T_642 = shiftAddr_7[0] * 4'h8; // @[src/main/scala/GPIO.scala 273:64]
  wire [38:0] _GEN_848 = {{31'd0}, io_apb_PWDATA[7:0]}; // @[src/main/scala/GPIO.scala 272:62]
  wire [38:0] _virtualPortOutput_T_643 = _GEN_848 << _virtualPortOutput_T_642; // @[src/main/scala/GPIO.scala 272:62]
  wire [38:0] _GEN_823 = _T_948 ? _virtualPortOutput_T_643 : {{31'd0}, _GEN_799}; // @[src/main/scala/GPIO.scala 264:7 271:30]
  wire  _T_951 = io_apb_PADDR <= 8'h15; // @[src/main/scala/GPIO.scala 277:14]
  wire  _T_952 = io_apb_PADDR >= 8'h15 & _T_951; // @[src/main/scala/GPIO.scala 276:47]
  wire [7:0] shiftAddr_8 = io_apb_PADDR - 8'h15; // @[src/main/scala/GPIO.scala 284:28]
  wire [4:0] _virtualPortEnable_T_2 = shiftAddr_8[0] * 4'h8; // @[src/main/scala/GPIO.scala 287:64]
  wire [31:0] _GEN_849 = {{31'd0}, io_apb_PWDATA[0]}; // @[src/main/scala/GPIO.scala 286:62]
  wire [31:0] _virtualPortEnable_T_3 = _GEN_849 << _virtualPortEnable_T_2; // @[src/main/scala/GPIO.scala 286:62]
  wire [31:0] _GEN_824 = _T_952 ? _virtualPortEnable_T_3 : {{31'd0}, regs_virtualPortEnable}; // @[src/main/scala/GPIO.scala 278:7 285:30 src/main/scala/GPIORegs.scala 52:34]
  wire  _T_956 = io_apb_PADDR >= 8'h16 & io_apb_PADDR <= 8'h17; // @[src/main/scala/GPIO.scala 290:40]
  wire [7:0] shiftAddr_9 = io_apb_PADDR - 8'h16; // @[src/main/scala/GPIO.scala 297:28]
  wire [5:0] _TRIGGER_TYPE_T_2 = shiftAddr_9[1:0] * 4'h8; // @[src/main/scala/GPIO.scala 300:57]
  wire [78:0] _GEN_850 = {{63'd0}, io_apb_PWDATA}; // @[src/main/scala/GPIO.scala 299:55]
  wire [78:0] _TRIGGER_TYPE_T_3 = _GEN_850 << _TRIGGER_TYPE_T_2; // @[src/main/scala/GPIO.scala 299:55]
  wire [78:0] _GEN_825 = _T_956 ? _TRIGGER_TYPE_T_3 : {{63'd0}, regs_TRIGGER_TYPE}; // @[src/main/scala/GPIO.scala 291:7 298:25 src/main/scala/GPIORegs.scala 55:29]
  wire  _T_960 = io_apb_PADDR >= 8'h18 & io_apb_PADDR <= 8'h19; // @[src/main/scala/GPIO.scala 302:41]
  wire [7:0] shiftAddr_10 = io_apb_PADDR - 8'h18; // @[src/main/scala/GPIO.scala 308:28]
  wire [5:0] _TRIGGER_LO_T_2 = shiftAddr_10[1:0] * 4'h8; // @[src/main/scala/GPIO.scala 311:55]
  wire [78:0] _GEN_851 = {{63'd0}, io_apb_PWDATA}; // @[src/main/scala/GPIO.scala 310:53]
  wire [78:0] _TRIGGER_LO_T_3 = _GEN_851 << _TRIGGER_LO_T_2; // @[src/main/scala/GPIO.scala 310:53]
  wire [78:0] _GEN_826 = io_apb_PADDR >= 8'h18 & io_apb_PADDR <= 8'h19 ? _TRIGGER_LO_T_3 : {{63'd0}, regs_TRIGGER_LO}; // @[src/main/scala/GPIO.scala 302:80 309:23 src/main/scala/GPIORegs.scala 56:27]
  wire  _T_964 = io_apb_PADDR >= 8'h1a & io_apb_PADDR <= 8'h1b; // @[src/main/scala/GPIO.scala 313:41]
  wire [7:0] shiftAddr_11 = io_apb_PADDR - 8'h1a; // @[src/main/scala/GPIO.scala 319:28]
  wire [5:0] _TRIGGER_HI_T_2 = shiftAddr_11[1:0] * 4'h8; // @[src/main/scala/GPIO.scala 322:55]
  wire [78:0] _GEN_852 = {{63'd0}, io_apb_PWDATA}; // @[src/main/scala/GPIO.scala 321:53]
  wire [78:0] _TRIGGER_HI_T_3 = _GEN_852 << _TRIGGER_HI_T_2; // @[src/main/scala/GPIO.scala 321:53]
  wire [78:0] _GEN_827 = io_apb_PADDR >= 8'h1a & io_apb_PADDR <= 8'h1b ? _TRIGGER_HI_T_3 : {{63'd0}, regs_TRIGGER_HI}; // @[src/main/scala/GPIO.scala 313:80 320:23 src/main/scala/GPIORegs.scala 57:27]
  wire  _T_967 = io_apb_PADDR <= 8'h1d; // @[src/main/scala/GPIO.scala 326:14]
  wire  _T_968 = io_apb_PADDR >= 8'h1c & _T_967; // @[src/main/scala/GPIO.scala 325:42]
  wire  _T_972 = io_apb_PADDR >= 8'h1e & io_apb_PADDR <= 8'h1f; // @[src/main/scala/GPIO.scala 338:41]
  wire [7:0] shiftAddr_13 = io_apb_PADDR - 8'h1e; // @[src/main/scala/GPIO.scala 344:28]
  wire [5:0] _IRQ_ENABLE_T_2 = shiftAddr_13[1:0] * 4'h8; // @[src/main/scala/GPIO.scala 347:55]
  wire [78:0] _GEN_862 = {{63'd0}, io_apb_PWDATA}; // @[src/main/scala/GPIO.scala 346:53]
  wire [78:0] _IRQ_ENABLE_T_3 = _GEN_862 << _IRQ_ENABLE_T_2; // @[src/main/scala/GPIO.scala 346:53]
  wire [78:0] _GEN_829 = io_apb_PADDR >= 8'h1e & io_apb_PADDR <= 8'h1f ? _IRQ_ENABLE_T_3 : {{63'd0}, regs_IRQ_ENABLE}; // @[src/main/scala/GPIO.scala 338:80 345:23 src/main/scala/GPIORegs.scala 59:27]
  wire [15:0] _GEN_830 = _T_914 ? regs_DIRECTION : 16'h0; // @[src/main/scala/GPIO.scala 354:78 360:21 52:17]
  wire [15:0] _GEN_831 = _T_923 ? regs_OUTPUT : _GEN_830; // @[src/main/scala/GPIO.scala 362:72 364:21]
  wire [15:0] _GEN_832 = _T_919 ? regs_INPUT : _GEN_831; // @[src/main/scala/GPIO.scala 366:70 368:21]
  wire [15:0] _GEN_833 = _T_927 ? regs_MODE : _GEN_832; // @[src/main/scala/GPIO.scala 370:68 372:21]
  wire [15:0] _GEN_834 = _T_931 ? {{12'd0}, regs_ATOMIC_OPERATION} : _GEN_833; // @[src/main/scala/GPIO.scala 377:7 388:21]
  wire [15:0] _GEN_835 = _T_935 ? regs_ATOMIC_MASK : _GEN_834; // @[src/main/scala/GPIO.scala 390:82 396:21]
  wire [15:0] _GEN_836 = _T_939 ? {{15'd0}, regs_ATOMIC_SET} : _GEN_835; // @[src/main/scala/GPIO.scala 398:80 404:21]
  wire [4:0] _GEN_838 = 3'h1 == index[2:0] ? regs_virtualToPhysicalMap_1 : regs_virtualToPhysicalMap_0; // @[src/main/scala/GPIO.scala 410:{13,13}]
  wire [4:0] _GEN_839 = 3'h2 == index[2:0] ? regs_virtualToPhysicalMap_2 : _GEN_838; // @[src/main/scala/GPIO.scala 410:{13,13}]
  wire [4:0] _GEN_840 = 3'h3 == index[2:0] ? regs_virtualToPhysicalMap_3 : _GEN_839; // @[src/main/scala/GPIO.scala 410:{13,13}]
  wire [4:0] _GEN_841 = 3'h4 == index[2:0] ? regs_virtualToPhysicalMap_4 : _GEN_840; // @[src/main/scala/GPIO.scala 410:{13,13}]
  wire [4:0] _GEN_842 = 3'h5 == index[2:0] ? regs_virtualToPhysicalMap_5 : _GEN_841; // @[src/main/scala/GPIO.scala 410:{13,13}]
  wire [4:0] _GEN_843 = 3'h6 == index[2:0] ? regs_virtualToPhysicalMap_6 : _GEN_842; // @[src/main/scala/GPIO.scala 410:{13,13}]
  wire [4:0] _GEN_844 = 3'h7 == index[2:0] ? regs_virtualToPhysicalMap_7 : _GEN_843; // @[src/main/scala/GPIO.scala 410:{13,13}]
  wire [15:0] _GEN_853 = _T_943 ? {{11'd0}, _GEN_844} : _GEN_836; // @[src/main/scala/GPIO.scala 409:7 418:21]
  wire [15:0] _GEN_854 = _T_948 ? {{8'd0}, regs_virtualPortOutput} : _GEN_853; // @[src/main/scala/GPIO.scala 425:7 431:21]
  wire [15:0] _GEN_855 = _T_952 ? {{15'd0}, regs_virtualPortEnable} : _GEN_854; // @[src/main/scala/GPIO.scala 436:7 442:21]
  wire [15:0] _GEN_856 = _T_956 ? regs_TRIGGER_TYPE : _GEN_855; // @[src/main/scala/GPIO.scala 446:7 452:21]
  wire [15:0] _GEN_857 = _T_960 ? regs_TRIGGER_LO : _GEN_856; // @[src/main/scala/GPIO.scala 456:7 462:21]
  wire [15:0] _GEN_858 = _T_964 ? regs_TRIGGER_HI : _GEN_857; // @[src/main/scala/GPIO.scala 464:80 470:21]
  wire [15:0] _GEN_859 = _T_968 ? regs_TRIGGER_STATUS : _GEN_858; // @[src/main/scala/GPIO.scala 475:7 481:21]
  wire [15:0] _GEN_860 = _T_972 ? regs_IRQ_ENABLE : _GEN_859; // @[src/main/scala/GPIO.scala 483:80 489:21]
  wire [78:0] _GEN_861 = io_apb_PWRITE ? _GEN_800 : {{63'd0}, regs_DIRECTION}; // @[src/main/scala/GPIO.scala 54:25 src/main/scala/GPIORegs.scala 34:26]
  wire [78:0] _GEN_863 = io_apb_PWRITE ? _GEN_802 : {{63'd0}, _GEN_798}; // @[src/main/scala/GPIO.scala 54:25]
  wire [78:0] _GEN_864 = io_apb_PWRITE ? _GEN_803 : {{63'd0}, regs_MODE}; // @[src/main/scala/GPIO.scala 54:25 src/main/scala/GPIORegs.scala 37:21]
  wire [34:0] _GEN_865 = io_apb_PWRITE ? _GEN_804 : {{31'd0}, regs_ATOMIC_OPERATION}; // @[src/main/scala/GPIO.scala 54:25 src/main/scala/GPIORegs.scala 40:33]
  wire [78:0] _GEN_866 = io_apb_PWRITE ? _GEN_805 : {{63'd0}, regs_ATOMIC_MASK}; // @[src/main/scala/GPIO.scala 54:25 src/main/scala/GPIORegs.scala 41:28]
  wire [31:0] _GEN_867 = io_apb_PWRITE ? _GEN_806 : {{31'd0}, regs_ATOMIC_SET}; // @[src/main/scala/GPIO.scala 54:25 src/main/scala/GPIORegs.scala 42:27]
  wire [38:0] _GEN_876 = io_apb_PWRITE ? _GEN_823 : {{31'd0}, _GEN_799}; // @[src/main/scala/GPIO.scala 54:25]
  wire [31:0] _GEN_877 = io_apb_PWRITE ? _GEN_824 : {{31'd0}, regs_virtualPortEnable}; // @[src/main/scala/GPIO.scala 54:25 src/main/scala/GPIORegs.scala 52:34]
  wire [78:0] _GEN_878 = io_apb_PWRITE ? _GEN_825 : {{63'd0}, regs_TRIGGER_TYPE}; // @[src/main/scala/GPIO.scala 54:25 src/main/scala/GPIORegs.scala 55:29]
  wire [78:0] _GEN_879 = io_apb_PWRITE ? _GEN_826 : {{63'd0}, regs_TRIGGER_LO}; // @[src/main/scala/GPIO.scala 54:25 src/main/scala/GPIORegs.scala 56:27]
  wire [78:0] _GEN_880 = io_apb_PWRITE ? _GEN_827 : {{63'd0}, regs_TRIGGER_HI}; // @[src/main/scala/GPIO.scala 54:25 src/main/scala/GPIORegs.scala 57:27]
  wire [78:0] _GEN_882 = io_apb_PWRITE ? _GEN_829 : {{63'd0}, regs_IRQ_ENABLE}; // @[src/main/scala/GPIO.scala 54:25 src/main/scala/GPIORegs.scala 59:27]
  wire [15:0] _GEN_884 = io_apb_PWRITE ? 16'h0 : _GEN_860; // @[src/main/scala/GPIO.scala 52:17 54:25]
  wire [78:0] _GEN_885 = io_apb_PSEL & io_apb_PENABLE ? _GEN_861 : {{63'd0}, regs_DIRECTION}; // @[src/main/scala/GPIO.scala 53:39 src/main/scala/GPIORegs.scala 34:26]
  wire [78:0] _GEN_887 = io_apb_PSEL & io_apb_PENABLE ? _GEN_863 : {{63'd0}, _GEN_798}; // @[src/main/scala/GPIO.scala 53:39]
  wire [78:0] _GEN_888 = io_apb_PSEL & io_apb_PENABLE ? _GEN_864 : {{63'd0}, regs_MODE}; // @[src/main/scala/GPIO.scala 53:39 src/main/scala/GPIORegs.scala 37:21]
  wire [34:0] _GEN_889 = io_apb_PSEL & io_apb_PENABLE ? _GEN_865 : {{31'd0}, regs_ATOMIC_OPERATION}; // @[src/main/scala/GPIO.scala 53:39 src/main/scala/GPIORegs.scala 40:33]
  wire [78:0] _GEN_890 = io_apb_PSEL & io_apb_PENABLE ? _GEN_866 : {{63'd0}, regs_ATOMIC_MASK}; // @[src/main/scala/GPIO.scala 53:39 src/main/scala/GPIORegs.scala 41:28]
  wire [31:0] _GEN_891 = io_apb_PSEL & io_apb_PENABLE ? _GEN_867 : {{31'd0}, regs_ATOMIC_SET}; // @[src/main/scala/GPIO.scala 53:39 src/main/scala/GPIORegs.scala 42:27]
  wire [38:0] _GEN_900 = io_apb_PSEL & io_apb_PENABLE ? _GEN_876 : {{31'd0}, _GEN_799}; // @[src/main/scala/GPIO.scala 53:39]
  wire [31:0] _GEN_901 = io_apb_PSEL & io_apb_PENABLE ? _GEN_877 : {{31'd0}, regs_virtualPortEnable}; // @[src/main/scala/GPIO.scala 53:39 src/main/scala/GPIORegs.scala 52:34]
  wire [78:0] _GEN_902 = io_apb_PSEL & io_apb_PENABLE ? _GEN_878 : {{63'd0}, regs_TRIGGER_TYPE}; // @[src/main/scala/GPIO.scala 53:39 src/main/scala/GPIORegs.scala 55:29]
  wire [78:0] _GEN_903 = io_apb_PSEL & io_apb_PENABLE ? _GEN_879 : {{63'd0}, regs_TRIGGER_LO}; // @[src/main/scala/GPIO.scala 53:39 src/main/scala/GPIORegs.scala 56:27]
  wire [78:0] _GEN_904 = io_apb_PSEL & io_apb_PENABLE ? _GEN_880 : {{63'd0}, regs_TRIGGER_HI}; // @[src/main/scala/GPIO.scala 53:39 src/main/scala/GPIORegs.scala 57:27]
  wire [78:0] _GEN_906 = io_apb_PSEL & io_apb_PENABLE ? _GEN_882 : {{63'd0}, regs_IRQ_ENABLE}; // @[src/main/scala/GPIO.scala 53:39 src/main/scala/GPIORegs.scala 59:27]
  wire [2:0] condition = {regs_TRIGGER_TYPE[0],regs_TRIGGER_LO[0],regs_TRIGGER_HI[0]}; // @[src/main/scala/GPIO.scala 66:10]
  wire  _T_1045 = ~gpioInputSync[0]; // @[src/main/scala/GPIO.scala 74:31]
  wire  _T_1051 = gpioInputSync[0] & ~gpioInputSyncPrev[0]; // @[src/main/scala/GPIO.scala 80:31]
  wire  _T_1056 = _T_1045 & gpioInputSyncPrev[0]; // @[src/main/scala/GPIO.scala 85:32]
  wire  _T_1060 = gpioInputSync[0] != gpioInputSyncPrev[0]; // @[src/main/scala/GPIO.scala 90:31]
  wire  _GEN_914 = 3'h7 == condition & _T_1060; // @[src/main/scala/GPIO.scala 69:23 67:25]
  wire  _GEN_915 = 3'h6 == condition ? _T_1056 : _GEN_914; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_916 = 3'h5 == condition ? _T_1051 : _GEN_915; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_917 = 3'h3 == condition | _GEN_916; // @[src/main/scala/GPIO.scala 69:23 77:29]
  wire  _GEN_918 = 3'h2 == condition ? _T_1045 : _GEN_917; // @[src/main/scala/GPIO.scala 69:23]
  wire  triggerStatusVec_0 = 3'h1 == condition ? gpioInputSync[0] : _GEN_918; // @[src/main/scala/GPIO.scala 69:23]
  wire [2:0] condition_1 = {regs_TRIGGER_TYPE[1],regs_TRIGGER_LO[1],regs_TRIGGER_HI[1]}; // @[src/main/scala/GPIO.scala 66:10]
  wire  _T_1066 = ~gpioInputSync[1]; // @[src/main/scala/GPIO.scala 74:31]
  wire  _T_1072 = gpioInputSync[1] & ~gpioInputSyncPrev[1]; // @[src/main/scala/GPIO.scala 80:31]
  wire  _T_1077 = _T_1066 & gpioInputSyncPrev[1]; // @[src/main/scala/GPIO.scala 85:32]
  wire  _T_1081 = gpioInputSync[1] != gpioInputSyncPrev[1]; // @[src/main/scala/GPIO.scala 90:31]
  wire  _GEN_925 = 3'h7 == condition_1 & _T_1081; // @[src/main/scala/GPIO.scala 69:23 67:25]
  wire  _GEN_926 = 3'h6 == condition_1 ? _T_1077 : _GEN_925; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_927 = 3'h5 == condition_1 ? _T_1072 : _GEN_926; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_928 = 3'h3 == condition_1 | _GEN_927; // @[src/main/scala/GPIO.scala 69:23 77:29]
  wire  _GEN_929 = 3'h2 == condition_1 ? _T_1066 : _GEN_928; // @[src/main/scala/GPIO.scala 69:23]
  wire  triggerStatusVec_1 = 3'h1 == condition_1 ? gpioInputSync[1] : _GEN_929; // @[src/main/scala/GPIO.scala 69:23]
  wire [2:0] condition_2 = {regs_TRIGGER_TYPE[2],regs_TRIGGER_LO[2],regs_TRIGGER_HI[2]}; // @[src/main/scala/GPIO.scala 66:10]
  wire  _T_1087 = ~gpioInputSync[2]; // @[src/main/scala/GPIO.scala 74:31]
  wire  _T_1093 = gpioInputSync[2] & ~gpioInputSyncPrev[2]; // @[src/main/scala/GPIO.scala 80:31]
  wire  _T_1098 = _T_1087 & gpioInputSyncPrev[2]; // @[src/main/scala/GPIO.scala 85:32]
  wire  _T_1102 = gpioInputSync[2] != gpioInputSyncPrev[2]; // @[src/main/scala/GPIO.scala 90:31]
  wire  _GEN_936 = 3'h7 == condition_2 & _T_1102; // @[src/main/scala/GPIO.scala 69:23 67:25]
  wire  _GEN_937 = 3'h6 == condition_2 ? _T_1098 : _GEN_936; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_938 = 3'h5 == condition_2 ? _T_1093 : _GEN_937; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_939 = 3'h3 == condition_2 | _GEN_938; // @[src/main/scala/GPIO.scala 69:23 77:29]
  wire  _GEN_940 = 3'h2 == condition_2 ? _T_1087 : _GEN_939; // @[src/main/scala/GPIO.scala 69:23]
  wire  triggerStatusVec_2 = 3'h1 == condition_2 ? gpioInputSync[2] : _GEN_940; // @[src/main/scala/GPIO.scala 69:23]
  wire [2:0] condition_3 = {regs_TRIGGER_TYPE[3],regs_TRIGGER_LO[3],regs_TRIGGER_HI[3]}; // @[src/main/scala/GPIO.scala 66:10]
  wire  _T_1108 = ~gpioInputSync[3]; // @[src/main/scala/GPIO.scala 74:31]
  wire  _T_1114 = gpioInputSync[3] & ~gpioInputSyncPrev[3]; // @[src/main/scala/GPIO.scala 80:31]
  wire  _T_1119 = _T_1108 & gpioInputSyncPrev[3]; // @[src/main/scala/GPIO.scala 85:32]
  wire  _T_1123 = gpioInputSync[3] != gpioInputSyncPrev[3]; // @[src/main/scala/GPIO.scala 90:31]
  wire  _GEN_947 = 3'h7 == condition_3 & _T_1123; // @[src/main/scala/GPIO.scala 69:23 67:25]
  wire  _GEN_948 = 3'h6 == condition_3 ? _T_1119 : _GEN_947; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_949 = 3'h5 == condition_3 ? _T_1114 : _GEN_948; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_950 = 3'h3 == condition_3 | _GEN_949; // @[src/main/scala/GPIO.scala 69:23 77:29]
  wire  _GEN_951 = 3'h2 == condition_3 ? _T_1108 : _GEN_950; // @[src/main/scala/GPIO.scala 69:23]
  wire  triggerStatusVec_3 = 3'h1 == condition_3 ? gpioInputSync[3] : _GEN_951; // @[src/main/scala/GPIO.scala 69:23]
  wire [2:0] condition_4 = {regs_TRIGGER_TYPE[4],regs_TRIGGER_LO[4],regs_TRIGGER_HI[4]}; // @[src/main/scala/GPIO.scala 66:10]
  wire  _T_1129 = ~gpioInputSync[4]; // @[src/main/scala/GPIO.scala 74:31]
  wire  _T_1135 = gpioInputSync[4] & ~gpioInputSyncPrev[4]; // @[src/main/scala/GPIO.scala 80:31]
  wire  _T_1140 = _T_1129 & gpioInputSyncPrev[4]; // @[src/main/scala/GPIO.scala 85:32]
  wire  _T_1144 = gpioInputSync[4] != gpioInputSyncPrev[4]; // @[src/main/scala/GPIO.scala 90:31]
  wire  _GEN_958 = 3'h7 == condition_4 & _T_1144; // @[src/main/scala/GPIO.scala 69:23 67:25]
  wire  _GEN_959 = 3'h6 == condition_4 ? _T_1140 : _GEN_958; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_960 = 3'h5 == condition_4 ? _T_1135 : _GEN_959; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_961 = 3'h3 == condition_4 | _GEN_960; // @[src/main/scala/GPIO.scala 69:23 77:29]
  wire  _GEN_962 = 3'h2 == condition_4 ? _T_1129 : _GEN_961; // @[src/main/scala/GPIO.scala 69:23]
  wire  triggerStatusVec_4 = 3'h1 == condition_4 ? gpioInputSync[4] : _GEN_962; // @[src/main/scala/GPIO.scala 69:23]
  wire [2:0] condition_5 = {regs_TRIGGER_TYPE[5],regs_TRIGGER_LO[5],regs_TRIGGER_HI[5]}; // @[src/main/scala/GPIO.scala 66:10]
  wire  _T_1150 = ~gpioInputSync[5]; // @[src/main/scala/GPIO.scala 74:31]
  wire  _T_1156 = gpioInputSync[5] & ~gpioInputSyncPrev[5]; // @[src/main/scala/GPIO.scala 80:31]
  wire  _T_1161 = _T_1150 & gpioInputSyncPrev[5]; // @[src/main/scala/GPIO.scala 85:32]
  wire  _T_1165 = gpioInputSync[5] != gpioInputSyncPrev[5]; // @[src/main/scala/GPIO.scala 90:31]
  wire  _GEN_969 = 3'h7 == condition_5 & _T_1165; // @[src/main/scala/GPIO.scala 69:23 67:25]
  wire  _GEN_970 = 3'h6 == condition_5 ? _T_1161 : _GEN_969; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_971 = 3'h5 == condition_5 ? _T_1156 : _GEN_970; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_972 = 3'h3 == condition_5 | _GEN_971; // @[src/main/scala/GPIO.scala 69:23 77:29]
  wire  _GEN_973 = 3'h2 == condition_5 ? _T_1150 : _GEN_972; // @[src/main/scala/GPIO.scala 69:23]
  wire  triggerStatusVec_5 = 3'h1 == condition_5 ? gpioInputSync[5] : _GEN_973; // @[src/main/scala/GPIO.scala 69:23]
  wire [2:0] condition_6 = {regs_TRIGGER_TYPE[6],regs_TRIGGER_LO[6],regs_TRIGGER_HI[6]}; // @[src/main/scala/GPIO.scala 66:10]
  wire  _T_1171 = ~gpioInputSync[6]; // @[src/main/scala/GPIO.scala 74:31]
  wire  _T_1177 = gpioInputSync[6] & ~gpioInputSyncPrev[6]; // @[src/main/scala/GPIO.scala 80:31]
  wire  _T_1182 = _T_1171 & gpioInputSyncPrev[6]; // @[src/main/scala/GPIO.scala 85:32]
  wire  _T_1186 = gpioInputSync[6] != gpioInputSyncPrev[6]; // @[src/main/scala/GPIO.scala 90:31]
  wire  _GEN_980 = 3'h7 == condition_6 & _T_1186; // @[src/main/scala/GPIO.scala 69:23 67:25]
  wire  _GEN_981 = 3'h6 == condition_6 ? _T_1182 : _GEN_980; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_982 = 3'h5 == condition_6 ? _T_1177 : _GEN_981; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_983 = 3'h3 == condition_6 | _GEN_982; // @[src/main/scala/GPIO.scala 69:23 77:29]
  wire  _GEN_984 = 3'h2 == condition_6 ? _T_1171 : _GEN_983; // @[src/main/scala/GPIO.scala 69:23]
  wire  triggerStatusVec_6 = 3'h1 == condition_6 ? gpioInputSync[6] : _GEN_984; // @[src/main/scala/GPIO.scala 69:23]
  wire [2:0] condition_7 = {regs_TRIGGER_TYPE[7],regs_TRIGGER_LO[7],regs_TRIGGER_HI[7]}; // @[src/main/scala/GPIO.scala 66:10]
  wire  _T_1192 = ~gpioInputSync[7]; // @[src/main/scala/GPIO.scala 74:31]
  wire  _T_1198 = gpioInputSync[7] & ~gpioInputSyncPrev[7]; // @[src/main/scala/GPIO.scala 80:31]
  wire  _T_1203 = _T_1192 & gpioInputSyncPrev[7]; // @[src/main/scala/GPIO.scala 85:32]
  wire  _T_1207 = gpioInputSync[7] != gpioInputSyncPrev[7]; // @[src/main/scala/GPIO.scala 90:31]
  wire  _GEN_991 = 3'h7 == condition_7 & _T_1207; // @[src/main/scala/GPIO.scala 69:23 67:25]
  wire  _GEN_992 = 3'h6 == condition_7 ? _T_1203 : _GEN_991; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_993 = 3'h5 == condition_7 ? _T_1198 : _GEN_992; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_994 = 3'h3 == condition_7 | _GEN_993; // @[src/main/scala/GPIO.scala 69:23 77:29]
  wire  _GEN_995 = 3'h2 == condition_7 ? _T_1192 : _GEN_994; // @[src/main/scala/GPIO.scala 69:23]
  wire  triggerStatusVec_7 = 3'h1 == condition_7 ? gpioInputSync[7] : _GEN_995; // @[src/main/scala/GPIO.scala 69:23]
  wire [2:0] condition_8 = {regs_TRIGGER_TYPE[8],regs_TRIGGER_LO[8],regs_TRIGGER_HI[8]}; // @[src/main/scala/GPIO.scala 66:10]
  wire  _T_1213 = ~gpioInputSync[8]; // @[src/main/scala/GPIO.scala 74:31]
  wire  _T_1219 = gpioInputSync[8] & ~gpioInputSyncPrev[8]; // @[src/main/scala/GPIO.scala 80:31]
  wire  _T_1224 = _T_1213 & gpioInputSyncPrev[8]; // @[src/main/scala/GPIO.scala 85:32]
  wire  _T_1228 = gpioInputSync[8] != gpioInputSyncPrev[8]; // @[src/main/scala/GPIO.scala 90:31]
  wire  _GEN_1002 = 3'h7 == condition_8 & _T_1228; // @[src/main/scala/GPIO.scala 69:23 67:25]
  wire  _GEN_1003 = 3'h6 == condition_8 ? _T_1224 : _GEN_1002; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_1004 = 3'h5 == condition_8 ? _T_1219 : _GEN_1003; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_1005 = 3'h3 == condition_8 | _GEN_1004; // @[src/main/scala/GPIO.scala 69:23 77:29]
  wire  _GEN_1006 = 3'h2 == condition_8 ? _T_1213 : _GEN_1005; // @[src/main/scala/GPIO.scala 69:23]
  wire  triggerStatusVec_8 = 3'h1 == condition_8 ? gpioInputSync[8] : _GEN_1006; // @[src/main/scala/GPIO.scala 69:23]
  wire [2:0] condition_9 = {regs_TRIGGER_TYPE[9],regs_TRIGGER_LO[9],regs_TRIGGER_HI[9]}; // @[src/main/scala/GPIO.scala 66:10]
  wire  _T_1234 = ~gpioInputSync[9]; // @[src/main/scala/GPIO.scala 74:31]
  wire  _T_1240 = gpioInputSync[9] & ~gpioInputSyncPrev[9]; // @[src/main/scala/GPIO.scala 80:31]
  wire  _T_1245 = _T_1234 & gpioInputSyncPrev[9]; // @[src/main/scala/GPIO.scala 85:32]
  wire  _T_1249 = gpioInputSync[9] != gpioInputSyncPrev[9]; // @[src/main/scala/GPIO.scala 90:31]
  wire  _GEN_1013 = 3'h7 == condition_9 & _T_1249; // @[src/main/scala/GPIO.scala 69:23 67:25]
  wire  _GEN_1014 = 3'h6 == condition_9 ? _T_1245 : _GEN_1013; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_1015 = 3'h5 == condition_9 ? _T_1240 : _GEN_1014; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_1016 = 3'h3 == condition_9 | _GEN_1015; // @[src/main/scala/GPIO.scala 69:23 77:29]
  wire  _GEN_1017 = 3'h2 == condition_9 ? _T_1234 : _GEN_1016; // @[src/main/scala/GPIO.scala 69:23]
  wire  triggerStatusVec_9 = 3'h1 == condition_9 ? gpioInputSync[9] : _GEN_1017; // @[src/main/scala/GPIO.scala 69:23]
  wire [2:0] condition_10 = {regs_TRIGGER_TYPE[10],regs_TRIGGER_LO[10],regs_TRIGGER_HI[10]}; // @[src/main/scala/GPIO.scala 66:10]
  wire  _T_1255 = ~gpioInputSync[10]; // @[src/main/scala/GPIO.scala 74:31]
  wire  _T_1261 = gpioInputSync[10] & ~gpioInputSyncPrev[10]; // @[src/main/scala/GPIO.scala 80:31]
  wire  _T_1266 = _T_1255 & gpioInputSyncPrev[10]; // @[src/main/scala/GPIO.scala 85:32]
  wire  _T_1270 = gpioInputSync[10] != gpioInputSyncPrev[10]; // @[src/main/scala/GPIO.scala 90:31]
  wire  _GEN_1024 = 3'h7 == condition_10 & _T_1270; // @[src/main/scala/GPIO.scala 69:23 67:25]
  wire  _GEN_1025 = 3'h6 == condition_10 ? _T_1266 : _GEN_1024; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_1026 = 3'h5 == condition_10 ? _T_1261 : _GEN_1025; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_1027 = 3'h3 == condition_10 | _GEN_1026; // @[src/main/scala/GPIO.scala 69:23 77:29]
  wire  _GEN_1028 = 3'h2 == condition_10 ? _T_1255 : _GEN_1027; // @[src/main/scala/GPIO.scala 69:23]
  wire  triggerStatusVec_10 = 3'h1 == condition_10 ? gpioInputSync[10] : _GEN_1028; // @[src/main/scala/GPIO.scala 69:23]
  wire [2:0] condition_11 = {regs_TRIGGER_TYPE[11],regs_TRIGGER_LO[11],regs_TRIGGER_HI[11]}; // @[src/main/scala/GPIO.scala 66:10]
  wire  _T_1276 = ~gpioInputSync[11]; // @[src/main/scala/GPIO.scala 74:31]
  wire  _T_1282 = gpioInputSync[11] & ~gpioInputSyncPrev[11]; // @[src/main/scala/GPIO.scala 80:31]
  wire  _T_1287 = _T_1276 & gpioInputSyncPrev[11]; // @[src/main/scala/GPIO.scala 85:32]
  wire  _T_1291 = gpioInputSync[11] != gpioInputSyncPrev[11]; // @[src/main/scala/GPIO.scala 90:31]
  wire  _GEN_1035 = 3'h7 == condition_11 & _T_1291; // @[src/main/scala/GPIO.scala 69:23 67:25]
  wire  _GEN_1036 = 3'h6 == condition_11 ? _T_1287 : _GEN_1035; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_1037 = 3'h5 == condition_11 ? _T_1282 : _GEN_1036; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_1038 = 3'h3 == condition_11 | _GEN_1037; // @[src/main/scala/GPIO.scala 69:23 77:29]
  wire  _GEN_1039 = 3'h2 == condition_11 ? _T_1276 : _GEN_1038; // @[src/main/scala/GPIO.scala 69:23]
  wire  triggerStatusVec_11 = 3'h1 == condition_11 ? gpioInputSync[11] : _GEN_1039; // @[src/main/scala/GPIO.scala 69:23]
  wire [2:0] condition_12 = {regs_TRIGGER_TYPE[12],regs_TRIGGER_LO[12],regs_TRIGGER_HI[12]}; // @[src/main/scala/GPIO.scala 66:10]
  wire  _T_1297 = ~gpioInputSync[12]; // @[src/main/scala/GPIO.scala 74:31]
  wire  _T_1303 = gpioInputSync[12] & ~gpioInputSyncPrev[12]; // @[src/main/scala/GPIO.scala 80:31]
  wire  _T_1308 = _T_1297 & gpioInputSyncPrev[12]; // @[src/main/scala/GPIO.scala 85:32]
  wire  _T_1312 = gpioInputSync[12] != gpioInputSyncPrev[12]; // @[src/main/scala/GPIO.scala 90:31]
  wire  _GEN_1046 = 3'h7 == condition_12 & _T_1312; // @[src/main/scala/GPIO.scala 69:23 67:25]
  wire  _GEN_1047 = 3'h6 == condition_12 ? _T_1308 : _GEN_1046; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_1048 = 3'h5 == condition_12 ? _T_1303 : _GEN_1047; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_1049 = 3'h3 == condition_12 | _GEN_1048; // @[src/main/scala/GPIO.scala 69:23 77:29]
  wire  _GEN_1050 = 3'h2 == condition_12 ? _T_1297 : _GEN_1049; // @[src/main/scala/GPIO.scala 69:23]
  wire  triggerStatusVec_12 = 3'h1 == condition_12 ? gpioInputSync[12] : _GEN_1050; // @[src/main/scala/GPIO.scala 69:23]
  wire [2:0] condition_13 = {regs_TRIGGER_TYPE[13],regs_TRIGGER_LO[13],regs_TRIGGER_HI[13]}; // @[src/main/scala/GPIO.scala 66:10]
  wire  _T_1318 = ~gpioInputSync[13]; // @[src/main/scala/GPIO.scala 74:31]
  wire  _T_1324 = gpioInputSync[13] & ~gpioInputSyncPrev[13]; // @[src/main/scala/GPIO.scala 80:31]
  wire  _T_1329 = _T_1318 & gpioInputSyncPrev[13]; // @[src/main/scala/GPIO.scala 85:32]
  wire  _T_1333 = gpioInputSync[13] != gpioInputSyncPrev[13]; // @[src/main/scala/GPIO.scala 90:31]
  wire  _GEN_1057 = 3'h7 == condition_13 & _T_1333; // @[src/main/scala/GPIO.scala 69:23 67:25]
  wire  _GEN_1058 = 3'h6 == condition_13 ? _T_1329 : _GEN_1057; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_1059 = 3'h5 == condition_13 ? _T_1324 : _GEN_1058; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_1060 = 3'h3 == condition_13 | _GEN_1059; // @[src/main/scala/GPIO.scala 69:23 77:29]
  wire  _GEN_1061 = 3'h2 == condition_13 ? _T_1318 : _GEN_1060; // @[src/main/scala/GPIO.scala 69:23]
  wire  triggerStatusVec_13 = 3'h1 == condition_13 ? gpioInputSync[13] : _GEN_1061; // @[src/main/scala/GPIO.scala 69:23]
  wire [2:0] condition_14 = {regs_TRIGGER_TYPE[14],regs_TRIGGER_LO[14],regs_TRIGGER_HI[14]}; // @[src/main/scala/GPIO.scala 66:10]
  wire  _T_1339 = ~gpioInputSync[14]; // @[src/main/scala/GPIO.scala 74:31]
  wire  _T_1345 = gpioInputSync[14] & ~gpioInputSyncPrev[14]; // @[src/main/scala/GPIO.scala 80:31]
  wire  _T_1350 = _T_1339 & gpioInputSyncPrev[14]; // @[src/main/scala/GPIO.scala 85:32]
  wire  _T_1354 = gpioInputSync[14] != gpioInputSyncPrev[14]; // @[src/main/scala/GPIO.scala 90:31]
  wire  _GEN_1068 = 3'h7 == condition_14 & _T_1354; // @[src/main/scala/GPIO.scala 69:23 67:25]
  wire  _GEN_1069 = 3'h6 == condition_14 ? _T_1350 : _GEN_1068; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_1070 = 3'h5 == condition_14 ? _T_1345 : _GEN_1069; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_1071 = 3'h3 == condition_14 | _GEN_1070; // @[src/main/scala/GPIO.scala 69:23 77:29]
  wire  _GEN_1072 = 3'h2 == condition_14 ? _T_1339 : _GEN_1071; // @[src/main/scala/GPIO.scala 69:23]
  wire  triggerStatusVec_14 = 3'h1 == condition_14 ? gpioInputSync[14] : _GEN_1072; // @[src/main/scala/GPIO.scala 69:23]
  wire [2:0] condition_15 = {regs_TRIGGER_TYPE[15],regs_TRIGGER_LO[15],regs_TRIGGER_HI[15]}; // @[src/main/scala/GPIO.scala 66:10]
  wire  _T_1360 = ~gpioInputSync[15]; // @[src/main/scala/GPIO.scala 74:31]
  wire  _T_1366 = gpioInputSync[15] & ~gpioInputSyncPrev[15]; // @[src/main/scala/GPIO.scala 80:31]
  wire  _T_1371 = _T_1360 & gpioInputSyncPrev[15]; // @[src/main/scala/GPIO.scala 85:32]
  wire  _T_1375 = gpioInputSync[15] != gpioInputSyncPrev[15]; // @[src/main/scala/GPIO.scala 90:31]
  wire  _GEN_1079 = 3'h7 == condition_15 & _T_1375; // @[src/main/scala/GPIO.scala 69:23 67:25]
  wire  _GEN_1080 = 3'h6 == condition_15 ? _T_1371 : _GEN_1079; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_1081 = 3'h5 == condition_15 ? _T_1366 : _GEN_1080; // @[src/main/scala/GPIO.scala 69:23]
  wire  _GEN_1082 = 3'h3 == condition_15 | _GEN_1081; // @[src/main/scala/GPIO.scala 69:23 77:29]
  wire  _GEN_1083 = 3'h2 == condition_15 ? _T_1360 : _GEN_1082; // @[src/main/scala/GPIO.scala 69:23]
  wire  triggerStatusVec_15 = 3'h1 == condition_15 ? gpioInputSync[15] : _GEN_1083; // @[src/main/scala/GPIO.scala 69:23]
  wire [15:0] _T_1376 = regs_TRIGGER_STATUS & regs_IRQ_ENABLE; // @[src/main/scala/GPIO.scala 96:29]
  wire [7:0] TRIGGER_STATUS_lo = {triggerStatusVec_8,triggerStatusVec_9,triggerStatusVec_10,triggerStatusVec_11,
    triggerStatusVec_12,triggerStatusVec_13,triggerStatusVec_14,triggerStatusVec_15}; // @[src/main/scala/GPIO.scala 99:37]
  wire [15:0] _TRIGGER_STATUS_T_6 = {triggerStatusVec_0,triggerStatusVec_1,triggerStatusVec_2,triggerStatusVec_3,
    triggerStatusVec_4,triggerStatusVec_5,triggerStatusVec_6,triggerStatusVec_7,TRIGGER_STATUS_lo}; // @[src/main/scala/GPIO.scala 99:37]
  wire [15:0] _GEN_1185 = {{8'd0}, _TRIGGER_STATUS_T_6[15:8]}; // @[src/main/scala/GPIO.scala 99:33]
  wire [15:0] _TRIGGER_STATUS_T_10 = _GEN_1185 & 16'hff; // @[src/main/scala/GPIO.scala 99:33]
  wire [15:0] _TRIGGER_STATUS_T_12 = {_TRIGGER_STATUS_T_6[7:0], 8'h0}; // @[src/main/scala/GPIO.scala 99:33]
  wire [15:0] _TRIGGER_STATUS_T_14 = _TRIGGER_STATUS_T_12 & 16'hff00; // @[src/main/scala/GPIO.scala 99:33]
  wire [15:0] _TRIGGER_STATUS_T_15 = _TRIGGER_STATUS_T_10 | _TRIGGER_STATUS_T_14; // @[src/main/scala/GPIO.scala 99:33]
  wire [15:0] _GEN_1186 = {{4'd0}, _TRIGGER_STATUS_T_15[15:4]}; // @[src/main/scala/GPIO.scala 99:33]
  wire [15:0] _TRIGGER_STATUS_T_20 = _GEN_1186 & 16'hf0f; // @[src/main/scala/GPIO.scala 99:33]
  wire [15:0] _TRIGGER_STATUS_T_22 = {_TRIGGER_STATUS_T_15[11:0], 4'h0}; // @[src/main/scala/GPIO.scala 99:33]
  wire [15:0] _TRIGGER_STATUS_T_24 = _TRIGGER_STATUS_T_22 & 16'hf0f0; // @[src/main/scala/GPIO.scala 99:33]
  wire [15:0] _TRIGGER_STATUS_T_25 = _TRIGGER_STATUS_T_20 | _TRIGGER_STATUS_T_24; // @[src/main/scala/GPIO.scala 99:33]
  wire [15:0] _GEN_1187 = {{2'd0}, _TRIGGER_STATUS_T_25[15:2]}; // @[src/main/scala/GPIO.scala 99:33]
  wire [15:0] _TRIGGER_STATUS_T_30 = _GEN_1187 & 16'h3333; // @[src/main/scala/GPIO.scala 99:33]
  wire [15:0] _TRIGGER_STATUS_T_32 = {_TRIGGER_STATUS_T_25[13:0], 2'h0}; // @[src/main/scala/GPIO.scala 99:33]
  wire [15:0] _TRIGGER_STATUS_T_34 = _TRIGGER_STATUS_T_32 & 16'hcccc; // @[src/main/scala/GPIO.scala 99:33]
  wire [15:0] _TRIGGER_STATUS_T_35 = _TRIGGER_STATUS_T_30 | _TRIGGER_STATUS_T_34; // @[src/main/scala/GPIO.scala 99:33]
  wire [15:0] _GEN_1188 = {{1'd0}, _TRIGGER_STATUS_T_35[15:1]}; // @[src/main/scala/GPIO.scala 99:33]
  wire [15:0] _TRIGGER_STATUS_T_40 = _GEN_1188 & 16'h5555; // @[src/main/scala/GPIO.scala 99:33]
  wire [15:0] _TRIGGER_STATUS_T_42 = {_TRIGGER_STATUS_T_35[14:0], 1'h0}; // @[src/main/scala/GPIO.scala 99:33]
  wire [15:0] _TRIGGER_STATUS_T_44 = _TRIGGER_STATUS_T_42 & 16'haaaa; // @[src/main/scala/GPIO.scala 99:33]
  wire [15:0] _TRIGGER_STATUS_T_45 = _TRIGGER_STATUS_T_40 | _TRIGGER_STATUS_T_44; // @[src/main/scala/GPIO.scala 99:33]
  wire  atomicOperationTruthTable_0_0 = regs_ATOMIC_OPERATION[1]; // @[src/main/scala/GPIO.scala 103:59]
  wire  atomicOperationTruthTable_0_1 = regs_ATOMIC_OPERATION[0]; // @[src/main/scala/GPIO.scala 104:59]
  wire  atomicOperationTruthTable_1_0 = regs_ATOMIC_OPERATION[3]; // @[src/main/scala/GPIO.scala 105:59]
  wire  atomicOperationTruthTable_1_1 = regs_ATOMIC_OPERATION[2]; // @[src/main/scala/GPIO.scala 106:59]
  wire  _GEN_1087 = ~regs_ATOMIC_MASK[0] & regs_OUTPUT[0] ? atomicOperationTruthTable_0_1 :
    atomicOperationTruthTable_0_0; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1190 = ~regs_OUTPUT[0]; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1088 = regs_ATOMIC_MASK[0] & ~regs_OUTPUT[0] ? atomicOperationTruthTable_1_0 : _GEN_1087; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  output_inner_0 = regs_ATOMIC_MASK[0] & regs_OUTPUT[0] ? atomicOperationTruthTable_1_1 : _GEN_1088; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1091 = ~regs_ATOMIC_MASK[1] & regs_OUTPUT[1] ? atomicOperationTruthTable_0_1 :
    atomicOperationTruthTable_0_0; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1192 = ~regs_OUTPUT[1]; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1092 = regs_ATOMIC_MASK[1] & ~regs_OUTPUT[1] ? atomicOperationTruthTable_1_0 : _GEN_1091; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  output_inner_1 = regs_ATOMIC_MASK[1] & regs_OUTPUT[1] ? atomicOperationTruthTable_1_1 : _GEN_1092; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1095 = ~regs_ATOMIC_MASK[2] & regs_OUTPUT[2] ? atomicOperationTruthTable_0_1 :
    atomicOperationTruthTable_0_0; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1194 = ~regs_OUTPUT[2]; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1096 = regs_ATOMIC_MASK[2] & ~regs_OUTPUT[2] ? atomicOperationTruthTable_1_0 : _GEN_1095; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  output_inner_2 = regs_ATOMIC_MASK[2] & regs_OUTPUT[2] ? atomicOperationTruthTable_1_1 : _GEN_1096; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1099 = ~regs_ATOMIC_MASK[3] & regs_OUTPUT[3] ? atomicOperationTruthTable_0_1 :
    atomicOperationTruthTable_0_0; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1196 = ~regs_OUTPUT[3]; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1100 = regs_ATOMIC_MASK[3] & ~regs_OUTPUT[3] ? atomicOperationTruthTable_1_0 : _GEN_1099; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  output_inner_3 = regs_ATOMIC_MASK[3] & regs_OUTPUT[3] ? atomicOperationTruthTable_1_1 : _GEN_1100; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1103 = ~regs_ATOMIC_MASK[4] & regs_OUTPUT[4] ? atomicOperationTruthTable_0_1 :
    atomicOperationTruthTable_0_0; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1198 = ~regs_OUTPUT[4]; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1104 = regs_ATOMIC_MASK[4] & ~regs_OUTPUT[4] ? atomicOperationTruthTable_1_0 : _GEN_1103; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  output_inner_4 = regs_ATOMIC_MASK[4] & regs_OUTPUT[4] ? atomicOperationTruthTable_1_1 : _GEN_1104; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1107 = ~regs_ATOMIC_MASK[5] & regs_OUTPUT[5] ? atomicOperationTruthTable_0_1 :
    atomicOperationTruthTable_0_0; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1200 = ~regs_OUTPUT[5]; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1108 = regs_ATOMIC_MASK[5] & ~regs_OUTPUT[5] ? atomicOperationTruthTable_1_0 : _GEN_1107; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  output_inner_5 = regs_ATOMIC_MASK[5] & regs_OUTPUT[5] ? atomicOperationTruthTable_1_1 : _GEN_1108; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1111 = ~regs_ATOMIC_MASK[6] & regs_OUTPUT[6] ? atomicOperationTruthTable_0_1 :
    atomicOperationTruthTable_0_0; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1202 = ~regs_OUTPUT[6]; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1112 = regs_ATOMIC_MASK[6] & ~regs_OUTPUT[6] ? atomicOperationTruthTable_1_0 : _GEN_1111; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  output_inner_6 = regs_ATOMIC_MASK[6] & regs_OUTPUT[6] ? atomicOperationTruthTable_1_1 : _GEN_1112; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1115 = ~regs_ATOMIC_MASK[7] & regs_OUTPUT[7] ? atomicOperationTruthTable_0_1 :
    atomicOperationTruthTable_0_0; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1204 = ~regs_OUTPUT[7]; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1116 = regs_ATOMIC_MASK[7] & ~regs_OUTPUT[7] ? atomicOperationTruthTable_1_0 : _GEN_1115; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  output_inner_7 = regs_ATOMIC_MASK[7] & regs_OUTPUT[7] ? atomicOperationTruthTable_1_1 : _GEN_1116; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1119 = ~regs_ATOMIC_MASK[8] & regs_OUTPUT[8] ? atomicOperationTruthTable_0_1 :
    atomicOperationTruthTable_0_0; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1206 = ~regs_OUTPUT[8]; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1120 = regs_ATOMIC_MASK[8] & ~regs_OUTPUT[8] ? atomicOperationTruthTable_1_0 : _GEN_1119; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  output_inner_8 = regs_ATOMIC_MASK[8] & regs_OUTPUT[8] ? atomicOperationTruthTable_1_1 : _GEN_1120; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1123 = ~regs_ATOMIC_MASK[9] & regs_OUTPUT[9] ? atomicOperationTruthTable_0_1 :
    atomicOperationTruthTable_0_0; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1208 = ~regs_OUTPUT[9]; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1124 = regs_ATOMIC_MASK[9] & ~regs_OUTPUT[9] ? atomicOperationTruthTable_1_0 : _GEN_1123; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  output_inner_9 = regs_ATOMIC_MASK[9] & regs_OUTPUT[9] ? atomicOperationTruthTable_1_1 : _GEN_1124; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1127 = ~regs_ATOMIC_MASK[10] & regs_OUTPUT[10] ? atomicOperationTruthTable_0_1 :
    atomicOperationTruthTable_0_0; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1210 = ~regs_OUTPUT[10]; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1128 = regs_ATOMIC_MASK[10] & ~regs_OUTPUT[10] ? atomicOperationTruthTable_1_0 : _GEN_1127; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  output_inner_10 = regs_ATOMIC_MASK[10] & regs_OUTPUT[10] ? atomicOperationTruthTable_1_1 : _GEN_1128; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1131 = ~regs_ATOMIC_MASK[11] & regs_OUTPUT[11] ? atomicOperationTruthTable_0_1 :
    atomicOperationTruthTable_0_0; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1212 = ~regs_OUTPUT[11]; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1132 = regs_ATOMIC_MASK[11] & ~regs_OUTPUT[11] ? atomicOperationTruthTable_1_0 : _GEN_1131; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  output_inner_11 = regs_ATOMIC_MASK[11] & regs_OUTPUT[11] ? atomicOperationTruthTable_1_1 : _GEN_1132; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1135 = ~regs_ATOMIC_MASK[12] & regs_OUTPUT[12] ? atomicOperationTruthTable_0_1 :
    atomicOperationTruthTable_0_0; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1214 = ~regs_OUTPUT[12]; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1136 = regs_ATOMIC_MASK[12] & ~regs_OUTPUT[12] ? atomicOperationTruthTable_1_0 : _GEN_1135; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  output_inner_12 = regs_ATOMIC_MASK[12] & regs_OUTPUT[12] ? atomicOperationTruthTable_1_1 : _GEN_1136; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1139 = ~regs_ATOMIC_MASK[13] & regs_OUTPUT[13] ? atomicOperationTruthTable_0_1 :
    atomicOperationTruthTable_0_0; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1216 = ~regs_OUTPUT[13]; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1140 = regs_ATOMIC_MASK[13] & ~regs_OUTPUT[13] ? atomicOperationTruthTable_1_0 : _GEN_1139; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  output_inner_13 = regs_ATOMIC_MASK[13] & regs_OUTPUT[13] ? atomicOperationTruthTable_1_1 : _GEN_1140; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1143 = ~regs_ATOMIC_MASK[14] & regs_OUTPUT[14] ? atomicOperationTruthTable_0_1 :
    atomicOperationTruthTable_0_0; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1218 = ~regs_OUTPUT[14]; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1144 = regs_ATOMIC_MASK[14] & ~regs_OUTPUT[14] ? atomicOperationTruthTable_1_0 : _GEN_1143; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  output_inner_14 = regs_ATOMIC_MASK[14] & regs_OUTPUT[14] ? atomicOperationTruthTable_1_1 : _GEN_1144; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1147 = ~regs_ATOMIC_MASK[15] & regs_OUTPUT[15] ? atomicOperationTruthTable_0_1 :
    atomicOperationTruthTable_0_0; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1220 = ~regs_OUTPUT[15]; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  _GEN_1148 = regs_ATOMIC_MASK[15] & ~regs_OUTPUT[15] ? atomicOperationTruthTable_1_0 : _GEN_1147; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire  output_inner_15 = regs_ATOMIC_MASK[15] & regs_OUTPUT[15] ? atomicOperationTruthTable_1_1 : _GEN_1148; // @[src/main/scala/GPIO.scala 116:{52,52}]
  wire [7:0] OUTPUT_lo = {output_inner_8,output_inner_9,output_inner_10,output_inner_11,output_inner_12,output_inner_13,
    output_inner_14,output_inner_15}; // @[src/main/scala/GPIO.scala 119:31]
  wire [15:0] _OUTPUT_T_644 = {output_inner_0,output_inner_1,output_inner_2,output_inner_3,output_inner_4,output_inner_5
    ,output_inner_6,output_inner_7,OUTPUT_lo}; // @[src/main/scala/GPIO.scala 119:31]
  wire [15:0] _GEN_1221 = {{8'd0}, _OUTPUT_T_644[15:8]}; // @[src/main/scala/GPIO.scala 119:27]
  wire [15:0] _OUTPUT_T_648 = _GEN_1221 & 16'hff; // @[src/main/scala/GPIO.scala 119:27]
  wire [15:0] _OUTPUT_T_650 = {_OUTPUT_T_644[7:0], 8'h0}; // @[src/main/scala/GPIO.scala 119:27]
  wire [15:0] _OUTPUT_T_652 = _OUTPUT_T_650 & 16'hff00; // @[src/main/scala/GPIO.scala 119:27]
  wire [15:0] _OUTPUT_T_653 = _OUTPUT_T_648 | _OUTPUT_T_652; // @[src/main/scala/GPIO.scala 119:27]
  wire [15:0] _GEN_1222 = {{4'd0}, _OUTPUT_T_653[15:4]}; // @[src/main/scala/GPIO.scala 119:27]
  wire [15:0] _OUTPUT_T_658 = _GEN_1222 & 16'hf0f; // @[src/main/scala/GPIO.scala 119:27]
  wire [15:0] _OUTPUT_T_660 = {_OUTPUT_T_653[11:0], 4'h0}; // @[src/main/scala/GPIO.scala 119:27]
  wire [15:0] _OUTPUT_T_662 = _OUTPUT_T_660 & 16'hf0f0; // @[src/main/scala/GPIO.scala 119:27]
  wire [15:0] _OUTPUT_T_663 = _OUTPUT_T_658 | _OUTPUT_T_662; // @[src/main/scala/GPIO.scala 119:27]
  wire [15:0] _GEN_1223 = {{2'd0}, _OUTPUT_T_663[15:2]}; // @[src/main/scala/GPIO.scala 119:27]
  wire [15:0] _OUTPUT_T_668 = _GEN_1223 & 16'h3333; // @[src/main/scala/GPIO.scala 119:27]
  wire [15:0] _OUTPUT_T_670 = {_OUTPUT_T_663[13:0], 2'h0}; // @[src/main/scala/GPIO.scala 119:27]
  wire [15:0] _OUTPUT_T_672 = _OUTPUT_T_670 & 16'hcccc; // @[src/main/scala/GPIO.scala 119:27]
  wire [15:0] _OUTPUT_T_673 = _OUTPUT_T_668 | _OUTPUT_T_672; // @[src/main/scala/GPIO.scala 119:27]
  wire [15:0] _GEN_1224 = {{1'd0}, _OUTPUT_T_673[15:1]}; // @[src/main/scala/GPIO.scala 119:27]
  wire [15:0] _OUTPUT_T_678 = _GEN_1224 & 16'h5555; // @[src/main/scala/GPIO.scala 119:27]
  wire [15:0] _OUTPUT_T_680 = {_OUTPUT_T_673[14:0], 1'h0}; // @[src/main/scala/GPIO.scala 119:27]
  wire [15:0] _OUTPUT_T_682 = _OUTPUT_T_680 & 16'haaaa; // @[src/main/scala/GPIO.scala 119:27]
  wire [15:0] _OUTPUT_T_683 = _OUTPUT_T_678 | _OUTPUT_T_682; // @[src/main/scala/GPIO.scala 119:27]
  wire [78:0] _GEN_1150 = regs_ATOMIC_SET ? {{63'd0}, _OUTPUT_T_683} : _GEN_887; // @[src/main/scala/GPIO.scala 107:33 119:17]
  wire  gpioOutputVec_15 = ~regs_MODE[0] & (regs_OUTPUT[0] & regs_DIRECTION[0]); // @[src/main/scala/GPIO.scala 123:61 124:40 127:40]
  wire  gpioOutputEnableVec_15 = ~regs_MODE[0] ? regs_DIRECTION[0] : _GEN_1190 & regs_DIRECTION[0]; // @[src/main/scala/GPIO.scala 123:61 125:46 128:46]
  wire  gpioOutputVec_14 = ~regs_MODE[1] & (regs_OUTPUT[1] & regs_DIRECTION[1]); // @[src/main/scala/GPIO.scala 123:61 124:40 127:40]
  wire  gpioOutputEnableVec_14 = ~regs_MODE[1] ? regs_DIRECTION[1] : _GEN_1192 & regs_DIRECTION[1]; // @[src/main/scala/GPIO.scala 123:61 125:46 128:46]
  wire  gpioOutputVec_13 = ~regs_MODE[2] & (regs_OUTPUT[2] & regs_DIRECTION[2]); // @[src/main/scala/GPIO.scala 123:61 124:40 127:40]
  wire  gpioOutputEnableVec_13 = ~regs_MODE[2] ? regs_DIRECTION[2] : _GEN_1194 & regs_DIRECTION[2]; // @[src/main/scala/GPIO.scala 123:61 125:46 128:46]
  wire  gpioOutputVec_12 = ~regs_MODE[3] & (regs_OUTPUT[3] & regs_DIRECTION[3]); // @[src/main/scala/GPIO.scala 123:61 124:40 127:40]
  wire  gpioOutputEnableVec_12 = ~regs_MODE[3] ? regs_DIRECTION[3] : _GEN_1196 & regs_DIRECTION[3]; // @[src/main/scala/GPIO.scala 123:61 125:46 128:46]
  wire  gpioOutputVec_11 = ~regs_MODE[4] & (regs_OUTPUT[4] & regs_DIRECTION[4]); // @[src/main/scala/GPIO.scala 123:61 124:40 127:40]
  wire  gpioOutputEnableVec_11 = ~regs_MODE[4] ? regs_DIRECTION[4] : _GEN_1198 & regs_DIRECTION[4]; // @[src/main/scala/GPIO.scala 123:61 125:46 128:46]
  wire  gpioOutputVec_10 = ~regs_MODE[5] & (regs_OUTPUT[5] & regs_DIRECTION[5]); // @[src/main/scala/GPIO.scala 123:61 124:40 127:40]
  wire  gpioOutputEnableVec_10 = ~regs_MODE[5] ? regs_DIRECTION[5] : _GEN_1200 & regs_DIRECTION[5]; // @[src/main/scala/GPIO.scala 123:61 125:46 128:46]
  wire  gpioOutputVec_9 = ~regs_MODE[6] & (regs_OUTPUT[6] & regs_DIRECTION[6]); // @[src/main/scala/GPIO.scala 123:61 124:40 127:40]
  wire  gpioOutputEnableVec_9 = ~regs_MODE[6] ? regs_DIRECTION[6] : _GEN_1202 & regs_DIRECTION[6]; // @[src/main/scala/GPIO.scala 123:61 125:46 128:46]
  wire  gpioOutputVec_8 = ~regs_MODE[7] & (regs_OUTPUT[7] & regs_DIRECTION[7]); // @[src/main/scala/GPIO.scala 123:61 124:40 127:40]
  wire  gpioOutputEnableVec_8 = ~regs_MODE[7] ? regs_DIRECTION[7] : _GEN_1204 & regs_DIRECTION[7]; // @[src/main/scala/GPIO.scala 123:61 125:46 128:46]
  wire  gpioOutputVec_7 = ~regs_MODE[8] & (regs_OUTPUT[8] & regs_DIRECTION[8]); // @[src/main/scala/GPIO.scala 123:61 124:40 127:40]
  wire  gpioOutputEnableVec_7 = ~regs_MODE[8] ? regs_DIRECTION[8] : _GEN_1206 & regs_DIRECTION[8]; // @[src/main/scala/GPIO.scala 123:61 125:46 128:46]
  wire  gpioOutputVec_6 = ~regs_MODE[9] & (regs_OUTPUT[9] & regs_DIRECTION[9]); // @[src/main/scala/GPIO.scala 123:61 124:40 127:40]
  wire  gpioOutputEnableVec_6 = ~regs_MODE[9] ? regs_DIRECTION[9] : _GEN_1208 & regs_DIRECTION[9]; // @[src/main/scala/GPIO.scala 123:61 125:46 128:46]
  wire  gpioOutputVec_5 = ~regs_MODE[10] & (regs_OUTPUT[10] & regs_DIRECTION[10]); // @[src/main/scala/GPIO.scala 123:61 124:40 127:40]
  wire  gpioOutputEnableVec_5 = ~regs_MODE[10] ? regs_DIRECTION[10] : _GEN_1210 & regs_DIRECTION[10]; // @[src/main/scala/GPIO.scala 123:61 125:46 128:46]
  wire  gpioOutputVec_4 = ~regs_MODE[11] & (regs_OUTPUT[11] & regs_DIRECTION[11]); // @[src/main/scala/GPIO.scala 123:61 124:40 127:40]
  wire  gpioOutputEnableVec_4 = ~regs_MODE[11] ? regs_DIRECTION[11] : _GEN_1212 & regs_DIRECTION[11]; // @[src/main/scala/GPIO.scala 123:61 125:46 128:46]
  wire  gpioOutputVec_3 = ~regs_MODE[12] & (regs_OUTPUT[12] & regs_DIRECTION[12]); // @[src/main/scala/GPIO.scala 123:61 124:40 127:40]
  wire  gpioOutputEnableVec_3 = ~regs_MODE[12] ? regs_DIRECTION[12] : _GEN_1214 & regs_DIRECTION[12]; // @[src/main/scala/GPIO.scala 123:61 125:46 128:46]
  wire  gpioOutputVec_2 = ~regs_MODE[13] & (regs_OUTPUT[13] & regs_DIRECTION[13]); // @[src/main/scala/GPIO.scala 123:61 124:40 127:40]
  wire  gpioOutputEnableVec_2 = ~regs_MODE[13] ? regs_DIRECTION[13] : _GEN_1216 & regs_DIRECTION[13]; // @[src/main/scala/GPIO.scala 123:61 125:46 128:46]
  wire  gpioOutputVec_1 = ~regs_MODE[14] & (regs_OUTPUT[14] & regs_DIRECTION[14]); // @[src/main/scala/GPIO.scala 123:61 124:40 127:40]
  wire  gpioOutputEnableVec_1 = ~regs_MODE[14] ? regs_DIRECTION[14] : _GEN_1218 & regs_DIRECTION[14]; // @[src/main/scala/GPIO.scala 123:61 125:46 128:46]
  wire  gpioOutputVec_0 = ~regs_MODE[15] & (regs_OUTPUT[15] & regs_DIRECTION[15]); // @[src/main/scala/GPIO.scala 123:61 124:40 127:40]
  wire  gpioOutputEnableVec_0 = ~regs_MODE[15] ? regs_DIRECTION[15] : _GEN_1220 & regs_DIRECTION[15]; // @[src/main/scala/GPIO.scala 123:61 125:46 128:46]
  wire [7:0] io_pins_gpioOutput_lo = {gpioOutputVec_8,gpioOutputVec_9,gpioOutputVec_10,gpioOutputVec_11,gpioOutputVec_12
    ,gpioOutputVec_13,gpioOutputVec_14,gpioOutputVec_15}; // @[src/main/scala/GPIO.scala 133:28]
  wire [7:0] io_pins_gpioOutput_hi = {gpioOutputVec_0,gpioOutputVec_1,gpioOutputVec_2,gpioOutputVec_3,gpioOutputVec_4,
    gpioOutputVec_5,gpioOutputVec_6,gpioOutputVec_7}; // @[src/main/scala/GPIO.scala 133:28]
  wire [7:0] io_pins_gpioOutputEnable_lo = {gpioOutputEnableVec_8,gpioOutputEnableVec_9,gpioOutputEnableVec_10,
    gpioOutputEnableVec_11,gpioOutputEnableVec_12,gpioOutputEnableVec_13,gpioOutputEnableVec_14,gpioOutputEnableVec_15}; // @[src/main/scala/GPIO.scala 134:34]
  wire [7:0] io_pins_gpioOutputEnable_hi = {gpioOutputEnableVec_0,gpioOutputEnableVec_1,gpioOutputEnableVec_2,
    gpioOutputEnableVec_3,gpioOutputEnableVec_4,gpioOutputEnableVec_5,gpioOutputEnableVec_6,gpioOutputEnableVec_7}; // @[src/main/scala/GPIO.scala 134:34]
  wire [78:0] _GEN_1225 = reset ? 79'h0 : _GEN_885; // @[src/main/scala/GPIORegs.scala 34:{26,26}]
  wire [78:0] _GEN_1226 = reset ? 79'h0 : _GEN_1150; // @[src/main/scala/GPIORegs.scala 35:{23,23}]
  wire [78:0] _GEN_1227 = reset ? 79'h0 : _GEN_888; // @[src/main/scala/GPIORegs.scala 37:{21,21}]
  wire [34:0] _GEN_1228 = reset ? 35'h0 : _GEN_889; // @[src/main/scala/GPIORegs.scala 40:{33,33}]
  wire [78:0] _GEN_1229 = reset ? 79'h0 : _GEN_890; // @[src/main/scala/GPIORegs.scala 41:{28,28}]
  wire [31:0] _GEN_1230 = reset ? 32'h0 : _GEN_891; // @[src/main/scala/GPIORegs.scala 42:{27,27}]
  wire [38:0] _GEN_1231 = reset ? 39'h0 : _GEN_900; // @[src/main/scala/GPIORegs.scala 45:{34,34}]
  wire [31:0] _GEN_1232 = reset ? 32'h0 : _GEN_901; // @[src/main/scala/GPIORegs.scala 52:{34,34}]
  wire [78:0] _GEN_1233 = reset ? 79'h0 : _GEN_902; // @[src/main/scala/GPIORegs.scala 55:{29,29}]
  wire [78:0] _GEN_1234 = reset ? 79'h0 : _GEN_903; // @[src/main/scala/GPIORegs.scala 56:{27,27}]
  wire [78:0] _GEN_1235 = reset ? 79'h0 : _GEN_904; // @[src/main/scala/GPIORegs.scala 57:{27,27}]
  wire [78:0] _GEN_1236 = reset ? 79'h0 : _GEN_906; // @[src/main/scala/GPIORegs.scala 59:{27,27}]
  wire  _GEN_1237 = _T_912 & io_apb_PWRITE; // @[src/main/scala/GPIO.scala 175:13]
  wire  _GEN_1268 = _T_912 & ~io_apb_PWRITE; // @[src/main/scala/GPIO.scala 353:11]
  wire  _GEN_1283 = _GEN_1268 & _T_931; // @[src/main/scala/GPIO.scala 378:13]
  assign io_apb_PRDATA = io_apb_PSEL & io_apb_PENABLE ? _GEN_884 : 16'h0; // @[src/main/scala/GPIO.scala 52:17 53:39]
  assign io_apb_PREADY = io_apb_PSEL & io_apb_PENABLE; // @[src/main/scala/GPIO.scala 53:20]
  assign io_apb_PSLVERR = io_apb_PADDR > 8'h1f; // @[src/main/scala/GPIO.scala 139:21]
  assign io_pins_gpioOutput = {io_pins_gpioOutput_hi,io_pins_gpioOutput_lo}; // @[src/main/scala/GPIO.scala 133:28]
  assign io_pins_gpioOutputEnable = {io_pins_gpioOutputEnable_hi,io_pins_gpioOutputEnable_lo}; // @[src/main/scala/GPIO.scala 134:34]
  assign io_pins_irqOutput = _T_1376 >= 16'h1; // @[src/main/scala/GPIO.scala 96:48]
  always @(posedge clock) begin
    regs_DIRECTION <= _GEN_1225[15:0]; // @[src/main/scala/GPIORegs.scala 34:{26,26}]
    regs_OUTPUT <= _GEN_1226[15:0]; // @[src/main/scala/GPIORegs.scala 35:{23,23}]
    if (reset) begin // @[src/main/scala/GPIORegs.scala 36:22]
      regs_INPUT <= 16'h0; // @[src/main/scala/GPIORegs.scala 36:22]
    end else begin
      regs_INPUT <= gpioInputSync; // @[src/main/scala/GPIO.scala 132:14]
    end
    regs_MODE <= _GEN_1227[15:0]; // @[src/main/scala/GPIORegs.scala 37:{21,21}]
    regs_ATOMIC_OPERATION <= _GEN_1228[3:0]; // @[src/main/scala/GPIORegs.scala 40:{33,33}]
    regs_ATOMIC_MASK <= _GEN_1229[15:0]; // @[src/main/scala/GPIORegs.scala 41:{28,28}]
    regs_ATOMIC_SET <= _GEN_1230[0]; // @[src/main/scala/GPIORegs.scala 42:{27,27}]
    regs_virtualPortOutput <= _GEN_1231[7:0]; // @[src/main/scala/GPIORegs.scala 45:{34,34}]
    if (reset) begin // @[src/main/scala/GPIORegs.scala 48:12]
      regs_virtualToPhysicalMap_0 <= 5'h0; // @[src/main/scala/GPIORegs.scala 48:12]
    end else if (io_apb_PSEL & io_apb_PENABLE) begin // @[src/main/scala/GPIO.scala 53:39]
      if (io_apb_PWRITE) begin // @[src/main/scala/GPIO.scala 54:25]
        if (_T_943) begin // @[src/main/scala/GPIO.scala 249:7]
          regs_virtualToPhysicalMap_0 <= _GEN_807;
        end
      end
    end
    if (reset) begin // @[src/main/scala/GPIORegs.scala 48:12]
      regs_virtualToPhysicalMap_1 <= 5'h0; // @[src/main/scala/GPIORegs.scala 48:12]
    end else if (io_apb_PSEL & io_apb_PENABLE) begin // @[src/main/scala/GPIO.scala 53:39]
      if (io_apb_PWRITE) begin // @[src/main/scala/GPIO.scala 54:25]
        if (_T_943) begin // @[src/main/scala/GPIO.scala 249:7]
          regs_virtualToPhysicalMap_1 <= _GEN_808;
        end
      end
    end
    if (reset) begin // @[src/main/scala/GPIORegs.scala 48:12]
      regs_virtualToPhysicalMap_2 <= 5'h0; // @[src/main/scala/GPIORegs.scala 48:12]
    end else if (io_apb_PSEL & io_apb_PENABLE) begin // @[src/main/scala/GPIO.scala 53:39]
      if (io_apb_PWRITE) begin // @[src/main/scala/GPIO.scala 54:25]
        if (_T_943) begin // @[src/main/scala/GPIO.scala 249:7]
          regs_virtualToPhysicalMap_2 <= _GEN_809;
        end
      end
    end
    if (reset) begin // @[src/main/scala/GPIORegs.scala 48:12]
      regs_virtualToPhysicalMap_3 <= 5'h0; // @[src/main/scala/GPIORegs.scala 48:12]
    end else if (io_apb_PSEL & io_apb_PENABLE) begin // @[src/main/scala/GPIO.scala 53:39]
      if (io_apb_PWRITE) begin // @[src/main/scala/GPIO.scala 54:25]
        if (_T_943) begin // @[src/main/scala/GPIO.scala 249:7]
          regs_virtualToPhysicalMap_3 <= _GEN_810;
        end
      end
    end
    if (reset) begin // @[src/main/scala/GPIORegs.scala 48:12]
      regs_virtualToPhysicalMap_4 <= 5'h0; // @[src/main/scala/GPIORegs.scala 48:12]
    end else if (io_apb_PSEL & io_apb_PENABLE) begin // @[src/main/scala/GPIO.scala 53:39]
      if (io_apb_PWRITE) begin // @[src/main/scala/GPIO.scala 54:25]
        if (_T_943) begin // @[src/main/scala/GPIO.scala 249:7]
          regs_virtualToPhysicalMap_4 <= _GEN_811;
        end
      end
    end
    if (reset) begin // @[src/main/scala/GPIORegs.scala 48:12]
      regs_virtualToPhysicalMap_5 <= 5'h0; // @[src/main/scala/GPIORegs.scala 48:12]
    end else if (io_apb_PSEL & io_apb_PENABLE) begin // @[src/main/scala/GPIO.scala 53:39]
      if (io_apb_PWRITE) begin // @[src/main/scala/GPIO.scala 54:25]
        if (_T_943) begin // @[src/main/scala/GPIO.scala 249:7]
          regs_virtualToPhysicalMap_5 <= _GEN_812;
        end
      end
    end
    if (reset) begin // @[src/main/scala/GPIORegs.scala 48:12]
      regs_virtualToPhysicalMap_6 <= 5'h0; // @[src/main/scala/GPIORegs.scala 48:12]
    end else if (io_apb_PSEL & io_apb_PENABLE) begin // @[src/main/scala/GPIO.scala 53:39]
      if (io_apb_PWRITE) begin // @[src/main/scala/GPIO.scala 54:25]
        if (_T_943) begin // @[src/main/scala/GPIO.scala 249:7]
          regs_virtualToPhysicalMap_6 <= _GEN_813;
        end
      end
    end
    if (reset) begin // @[src/main/scala/GPIORegs.scala 48:12]
      regs_virtualToPhysicalMap_7 <= 5'h0; // @[src/main/scala/GPIORegs.scala 48:12]
    end else if (io_apb_PSEL & io_apb_PENABLE) begin // @[src/main/scala/GPIO.scala 53:39]
      if (io_apb_PWRITE) begin // @[src/main/scala/GPIO.scala 54:25]
        if (_T_943) begin // @[src/main/scala/GPIO.scala 249:7]
          regs_virtualToPhysicalMap_7 <= _GEN_814;
        end
      end
    end
    regs_virtualPortEnable <= _GEN_1232[0]; // @[src/main/scala/GPIORegs.scala 52:{34,34}]
    regs_TRIGGER_TYPE <= _GEN_1233[15:0]; // @[src/main/scala/GPIORegs.scala 55:{29,29}]
    regs_TRIGGER_LO <= _GEN_1234[15:0]; // @[src/main/scala/GPIORegs.scala 56:{27,27}]
    regs_TRIGGER_HI <= _GEN_1235[15:0]; // @[src/main/scala/GPIORegs.scala 57:{27,27}]
    if (reset) begin // @[src/main/scala/GPIORegs.scala 58:31]
      regs_TRIGGER_STATUS <= 16'h0; // @[src/main/scala/GPIORegs.scala 58:31]
    end else begin
      regs_TRIGGER_STATUS <= _TRIGGER_STATUS_T_45; // @[src/main/scala/GPIO.scala 99:23]
    end
    regs_IRQ_ENABLE <= _GEN_1236[15:0]; // @[src/main/scala/GPIORegs.scala 59:{27,27}]
    if (reset) begin // @[src/main/scala/GPIO.scala 29:34]
      gpioInputSyncPrev <= 16'h0; // @[src/main/scala/GPIO.scala 29:34]
    end else begin
      gpioInputSyncPrev <= gpioInputSync; // @[src/main/scala/GPIO.scala 68:23]
    end
    gpioInputSync_REG <= io_pins_gpioInput; // @[src/main/scala/GPIO.scala 31:38]
    gpioInputSync <= gpioInputSync_REG; // @[src/main/scala/GPIO.scala 31:30]
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_912 & io_apb_PWRITE & _T_914 & ~reset) begin
          $fwrite(32'h80000002,"Writing DIRECTION Register, data: %x, addr: %x\n",io_apb_PWDATA,io_apb_PADDR); // @[src/main/scala/GPIO.scala 175:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1237 & _T_919 & _T_916) begin
          $fwrite(32'h80000002,"Writing INPUT Register, data: %x, addr: %x\n",io_apb_PWDATA,io_apb_PADDR); // @[src/main/scala/GPIO.scala 186:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1237 & _T_923 & _T_916) begin
          $fwrite(32'h80000002,"Writing OUTPUT Register, data: %x, addr: %x\n",io_apb_PWDATA,io_apb_PADDR); // @[src/main/scala/GPIO.scala 193:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1237 & _T_927 & _T_916) begin
          $fwrite(32'h80000002,"Writing MODE Register, data: %x, addr: %x\n",io_apb_PWDATA,io_apb_PADDR); // @[src/main/scala/GPIO.scala 204:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1237 & _T_931 & _T_916) begin
          $fwrite(32'h80000002,"Writing ATOMIC_OPERATION Register, data: %x, addr: %x\n",io_apb_PWDATA,io_apb_PADDR); // @[src/main/scala/GPIO.scala 214:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1237 & _T_935 & _T_916) begin
          $fwrite(32'h80000002,"Writing ATOMIC_MASK Register, data: %x, addr: %x\n",io_apb_PWDATA,io_apb_PADDR); // @[src/main/scala/GPIO.scala 225:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1237 & _T_939 & _T_916) begin
          $fwrite(32'h80000002,"Writing ATOMIC_SET Register, data: %x, addr: %x\n",io_apb_PWDATA,io_apb_PADDR); // @[src/main/scala/GPIO.scala 236:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1237 & _T_943 & _T_916) begin
          $fwrite(32'h80000002,"Writing VIRTUAL_PORT_MAP Register, data: %x, addr: %x\n",io_apb_PWDATA,io_apb_PADDR); // @[src/main/scala/GPIO.scala 250:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1237 & _T_948 & _T_916) begin
          $fwrite(32'h80000002,"Writing VIRTUAL_PORT_OUTPUT Register, data: %x, addr: %x\n",io_apb_PWDATA,io_apb_PADDR); // @[src/main/scala/GPIO.scala 265:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1237 & _T_952 & _T_916) begin
          $fwrite(32'h80000002,"Writing VIRTUAL_PORT_ENABLE Register, data: %x, addr: %x\n",io_apb_PWDATA,io_apb_PADDR); // @[src/main/scala/GPIO.scala 279:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1237 & _T_956 & _T_916) begin
          $fwrite(32'h80000002,"Writing TRIGGER_TYPE Register, data: %x, addr: %x\n",io_apb_PWDATA,io_apb_PADDR); // @[src/main/scala/GPIO.scala 292:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1237 & _T_960 & _T_916) begin
          $fwrite(32'h80000002,"Writing TRIGGER_LO Register, data: %x, addr: %x\n",io_apb_PWDATA,io_apb_PADDR); // @[src/main/scala/GPIO.scala 303:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1237 & _T_964 & _T_916) begin
          $fwrite(32'h80000002,"Writing TRIGGER_HI Register, data: %x, addr: %x\n",io_apb_PWDATA,io_apb_PADDR); // @[src/main/scala/GPIO.scala 314:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1237 & _T_968 & _T_916) begin
          $fwrite(32'h80000002,"Writing TRIGGER_STATUS Register, data: %x, addr: %x\n",io_apb_PWDATA,io_apb_PADDR); // @[src/main/scala/GPIO.scala 328:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1237 & _T_972 & _T_916) begin
          $fwrite(32'h80000002,"Writing IRQ_ENABLE Register, data: %x, addr: %x\n",io_apb_PWDATA,io_apb_PADDR); // @[src/main/scala/GPIO.scala 339:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_912 & ~io_apb_PWRITE & _T_916) begin
          $fwrite(32'h80000002,"Reading Register, addr: %x\n",io_apb_PADDR); // @[src/main/scala/GPIO.scala 353:11]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1268 & _T_914 & _T_916) begin
          $fwrite(32'h80000002,"Reading DIRECTION Register, data: %x, addr: %x\n",regs_DIRECTION,io_apb_PADDR); // @[src/main/scala/GPIO.scala 355:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1268 & _T_923 & _T_916) begin
          $fwrite(32'h80000002,"Reading OUTPUT Register, data: %x, addr: %x\n",regs_OUTPUT,io_apb_PADDR); // @[src/main/scala/GPIO.scala 363:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1268 & _T_919 & _T_916) begin
          $fwrite(32'h80000002,"Reading INPUT Register, data: %x, addr: %x\n",regs_INPUT,io_apb_PADDR); // @[src/main/scala/GPIO.scala 367:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1268 & _T_927 & _T_916) begin
          $fwrite(32'h80000002,"Reading MODE Register, data: %x, addr: %x\n",regs_MODE,io_apb_PADDR); // @[src/main/scala/GPIO.scala 371:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1268 & _T_931 & _T_916) begin
          $fwrite(32'h80000002,"Reading ATOMIC_OPERATION Register, data: %x, addr: %x\n",regs_ATOMIC_OPERATION,
            io_apb_PADDR); // @[src/main/scala/GPIO.scala 378:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1283 & _T_916) begin
          $fwrite(32'h80000002,"ATOMIC_OPERATION_MIN: %x\nATOMIC_OPERATION_MAX: %x\n",4'h8,4'h8); // @[src/main/scala/GPIO.scala 383:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1268 & _T_935 & _T_916) begin
          $fwrite(32'h80000002,"Reading ATOMIC_MASK Register, data: %x, addr: %x\n",regs_ATOMIC_MASK,io_apb_PADDR); // @[src/main/scala/GPIO.scala 391:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1268 & _T_939 & _T_916) begin
          $fwrite(32'h80000002,"Reading ATOMIC_SET Register, data: %x, addr: %x\n",regs_ATOMIC_SET,io_apb_PADDR); // @[src/main/scala/GPIO.scala 399:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1268 & _T_943 & _T_916) begin
          $fwrite(32'h80000002,"Reading VIRTUAL_PORT_MAP Register, data: %x, addr: %x\n",3'h7 == index[2:0] ?
            regs_virtualToPhysicalMap_7 : _GEN_843,io_apb_PADDR); // @[src/main/scala/GPIO.scala 410:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1268 & _T_948 & _T_916) begin
          $fwrite(32'h80000002,"Reading VIRTUAL_PORT_OUTPUT Register, data: %x, addr: %x\n",regs_virtualPortOutput,
            io_apb_PADDR); // @[src/main/scala/GPIO.scala 426:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1268 & _T_952 & _T_916) begin
          $fwrite(32'h80000002,"Reading VIRTUAL_PORT_ENABLE Register, data: %x, addr: %x\n",regs_virtualPortEnable,
            io_apb_PADDR); // @[src/main/scala/GPIO.scala 437:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1268 & _T_956 & _T_916) begin
          $fwrite(32'h80000002,"READING TRIGGER_TYPE Register, data: %x, addr: %x\n",regs_TRIGGER_TYPE,io_apb_PADDR); // @[src/main/scala/GPIO.scala 447:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1268 & _T_960 & _T_916) begin
          $fwrite(32'h80000002,"READING TRIGGER_LO Register, data: %x, addr: %x\n",regs_TRIGGER_LO,io_apb_PADDR); // @[src/main/scala/GPIO.scala 457:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1268 & _T_964 & _T_916) begin
          $fwrite(32'h80000002,"READING TRIGGER_HI Register, data: %x, addr: %x\n",regs_TRIGGER_HI,io_apb_PADDR); // @[src/main/scala/GPIO.scala 465:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1268 & _T_968 & _T_916) begin
          $fwrite(32'h80000002,"READING TRIGGER_STATUS Register, data: %x, addr: %x\n",regs_TRIGGER_STATUS,io_apb_PADDR
            ); // @[src/main/scala/GPIO.scala 476:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_GEN_1268 & _T_972 & _T_916) begin
          $fwrite(32'h80000002,"READING IRQ_ENABLE Register, data: %x, addr: %x\n",regs_IRQ_ENABLE,io_apb_PADDR); // @[src/main/scala/GPIO.scala 484:13]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  regs_DIRECTION = _RAND_0[15:0];
  _RAND_1 = {1{`RANDOM}};
  regs_OUTPUT = _RAND_1[15:0];
  _RAND_2 = {1{`RANDOM}};
  regs_INPUT = _RAND_2[15:0];
  _RAND_3 = {1{`RANDOM}};
  regs_MODE = _RAND_3[15:0];
  _RAND_4 = {1{`RANDOM}};
  regs_ATOMIC_OPERATION = _RAND_4[3:0];
  _RAND_5 = {1{`RANDOM}};
  regs_ATOMIC_MASK = _RAND_5[15:0];
  _RAND_6 = {1{`RANDOM}};
  regs_ATOMIC_SET = _RAND_6[0:0];
  _RAND_7 = {1{`RANDOM}};
  regs_virtualPortOutput = _RAND_7[7:0];
  _RAND_8 = {1{`RANDOM}};
  regs_virtualToPhysicalMap_0 = _RAND_8[4:0];
  _RAND_9 = {1{`RANDOM}};
  regs_virtualToPhysicalMap_1 = _RAND_9[4:0];
  _RAND_10 = {1{`RANDOM}};
  regs_virtualToPhysicalMap_2 = _RAND_10[4:0];
  _RAND_11 = {1{`RANDOM}};
  regs_virtualToPhysicalMap_3 = _RAND_11[4:0];
  _RAND_12 = {1{`RANDOM}};
  regs_virtualToPhysicalMap_4 = _RAND_12[4:0];
  _RAND_13 = {1{`RANDOM}};
  regs_virtualToPhysicalMap_5 = _RAND_13[4:0];
  _RAND_14 = {1{`RANDOM}};
  regs_virtualToPhysicalMap_6 = _RAND_14[4:0];
  _RAND_15 = {1{`RANDOM}};
  regs_virtualToPhysicalMap_7 = _RAND_15[4:0];
  _RAND_16 = {1{`RANDOM}};
  regs_virtualPortEnable = _RAND_16[0:0];
  _RAND_17 = {1{`RANDOM}};
  regs_TRIGGER_TYPE = _RAND_17[15:0];
  _RAND_18 = {1{`RANDOM}};
  regs_TRIGGER_LO = _RAND_18[15:0];
  _RAND_19 = {1{`RANDOM}};
  regs_TRIGGER_HI = _RAND_19[15:0];
  _RAND_20 = {1{`RANDOM}};
  regs_TRIGGER_STATUS = _RAND_20[15:0];
  _RAND_21 = {1{`RANDOM}};
  regs_IRQ_ENABLE = _RAND_21[15:0];
  _RAND_22 = {1{`RANDOM}};
  gpioInputSyncPrev = _RAND_22[15:0];
  _RAND_23 = {1{`RANDOM}};
  gpioInputSync_REG = _RAND_23[15:0];
  _RAND_24 = {1{`RANDOM}};
  gpioInputSync = _RAND_24[15:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
  always @(posedge clock) begin
    //
    if (_T_916) begin
      cover(io_pins_gpioInput[0]); // @[src/main/scala/GPIO.scala 152:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutput[0]); // @[src/main/scala/GPIO.scala 153:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutputEnable[0]); // @[src/main/scala/GPIO.scala 154:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PRDATA[0]); // @[src/main/scala/GPIO.scala 156:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PWDATA[0]); // @[src/main/scala/GPIO.scala 157:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioInput[1]); // @[src/main/scala/GPIO.scala 152:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutput[1]); // @[src/main/scala/GPIO.scala 153:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutputEnable[1]); // @[src/main/scala/GPIO.scala 154:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PRDATA[1]); // @[src/main/scala/GPIO.scala 156:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PWDATA[1]); // @[src/main/scala/GPIO.scala 157:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioInput[2]); // @[src/main/scala/GPIO.scala 152:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutput[2]); // @[src/main/scala/GPIO.scala 153:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutputEnable[2]); // @[src/main/scala/GPIO.scala 154:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PRDATA[2]); // @[src/main/scala/GPIO.scala 156:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PWDATA[2]); // @[src/main/scala/GPIO.scala 157:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioInput[3]); // @[src/main/scala/GPIO.scala 152:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutput[3]); // @[src/main/scala/GPIO.scala 153:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutputEnable[3]); // @[src/main/scala/GPIO.scala 154:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PRDATA[3]); // @[src/main/scala/GPIO.scala 156:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PWDATA[3]); // @[src/main/scala/GPIO.scala 157:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioInput[4]); // @[src/main/scala/GPIO.scala 152:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutput[4]); // @[src/main/scala/GPIO.scala 153:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutputEnable[4]); // @[src/main/scala/GPIO.scala 154:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PRDATA[4]); // @[src/main/scala/GPIO.scala 156:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PWDATA[4]); // @[src/main/scala/GPIO.scala 157:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioInput[5]); // @[src/main/scala/GPIO.scala 152:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutput[5]); // @[src/main/scala/GPIO.scala 153:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutputEnable[5]); // @[src/main/scala/GPIO.scala 154:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PRDATA[5]); // @[src/main/scala/GPIO.scala 156:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PWDATA[5]); // @[src/main/scala/GPIO.scala 157:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioInput[6]); // @[src/main/scala/GPIO.scala 152:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutput[6]); // @[src/main/scala/GPIO.scala 153:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutputEnable[6]); // @[src/main/scala/GPIO.scala 154:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PRDATA[6]); // @[src/main/scala/GPIO.scala 156:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PWDATA[6]); // @[src/main/scala/GPIO.scala 157:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioInput[7]); // @[src/main/scala/GPIO.scala 152:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutput[7]); // @[src/main/scala/GPIO.scala 153:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutputEnable[7]); // @[src/main/scala/GPIO.scala 154:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PRDATA[7]); // @[src/main/scala/GPIO.scala 156:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PWDATA[7]); // @[src/main/scala/GPIO.scala 157:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioInput[8]); // @[src/main/scala/GPIO.scala 152:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutput[8]); // @[src/main/scala/GPIO.scala 153:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutputEnable[8]); // @[src/main/scala/GPIO.scala 154:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PRDATA[8]); // @[src/main/scala/GPIO.scala 156:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PWDATA[8]); // @[src/main/scala/GPIO.scala 157:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioInput[9]); // @[src/main/scala/GPIO.scala 152:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutput[9]); // @[src/main/scala/GPIO.scala 153:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutputEnable[9]); // @[src/main/scala/GPIO.scala 154:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PRDATA[9]); // @[src/main/scala/GPIO.scala 156:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PWDATA[9]); // @[src/main/scala/GPIO.scala 157:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioInput[10]); // @[src/main/scala/GPIO.scala 152:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutput[10]); // @[src/main/scala/GPIO.scala 153:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutputEnable[10]); // @[src/main/scala/GPIO.scala 154:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PRDATA[10]); // @[src/main/scala/GPIO.scala 156:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PWDATA[10]); // @[src/main/scala/GPIO.scala 157:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioInput[11]); // @[src/main/scala/GPIO.scala 152:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutput[11]); // @[src/main/scala/GPIO.scala 153:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutputEnable[11]); // @[src/main/scala/GPIO.scala 154:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PRDATA[11]); // @[src/main/scala/GPIO.scala 156:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PWDATA[11]); // @[src/main/scala/GPIO.scala 157:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioInput[12]); // @[src/main/scala/GPIO.scala 152:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutput[12]); // @[src/main/scala/GPIO.scala 153:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutputEnable[12]); // @[src/main/scala/GPIO.scala 154:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PRDATA[12]); // @[src/main/scala/GPIO.scala 156:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PWDATA[12]); // @[src/main/scala/GPIO.scala 157:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioInput[13]); // @[src/main/scala/GPIO.scala 152:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutput[13]); // @[src/main/scala/GPIO.scala 153:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutputEnable[13]); // @[src/main/scala/GPIO.scala 154:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PRDATA[13]); // @[src/main/scala/GPIO.scala 156:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PWDATA[13]); // @[src/main/scala/GPIO.scala 157:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioInput[14]); // @[src/main/scala/GPIO.scala 152:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutput[14]); // @[src/main/scala/GPIO.scala 153:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutputEnable[14]); // @[src/main/scala/GPIO.scala 154:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PRDATA[14]); // @[src/main/scala/GPIO.scala 156:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PWDATA[14]); // @[src/main/scala/GPIO.scala 157:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioInput[15]); // @[src/main/scala/GPIO.scala 152:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutput[15]); // @[src/main/scala/GPIO.scala 153:12]
    end
    //
    if (_T_916) begin
      cover(io_pins_gpioOutputEnable[15]); // @[src/main/scala/GPIO.scala 154:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PRDATA[15]); // @[src/main/scala/GPIO.scala 156:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PWDATA[15]); // @[src/main/scala/GPIO.scala 157:12]
    end
    //
    if (_T_916) begin
      cover(io_apb_PADDR[0]); // @[src/main/scala/GPIO.scala 160:44]
    end
    //
    if (_T_916) begin
      cover(io_apb_PADDR[1]); // @[src/main/scala/GPIO.scala 160:44]
    end
    //
    if (_T_916) begin
      cover(io_apb_PADDR[2]); // @[src/main/scala/GPIO.scala 160:44]
    end
    //
    if (_T_916) begin
      cover(io_apb_PADDR[3]); // @[src/main/scala/GPIO.scala 160:44]
    end
    //
    if (_T_916) begin
      cover(io_apb_PADDR[4]); // @[src/main/scala/GPIO.scala 160:44]
    end
    //
    if (_T_916) begin
      cover(io_apb_PADDR[5]); // @[src/main/scala/GPIO.scala 160:44]
    end
    //
    if (_T_916) begin
      cover(io_apb_PADDR[6]); // @[src/main/scala/GPIO.scala 160:44]
    end
    //
    if (_T_916) begin
      cover(io_apb_PADDR[7]); // @[src/main/scala/GPIO.scala 160:44]
    end
    //
    if (_T_916) begin
      cover(1'h1); // @[src/main/scala/GPIO.scala 163:10]
    end
    //
    if (_T_916) begin
      cover(io_apb_PSEL); // @[src/main/scala/GPIO.scala 164:10]
    end
    //
    if (_T_916) begin
      cover(io_apb_PENABLE); // @[src/main/scala/GPIO.scala 165:10]
    end
    //
    if (_T_916) begin
      cover(io_apb_PWRITE); // @[src/main/scala/GPIO.scala 166:10]
    end
    //
    if (_T_916) begin
      cover(io_apb_PREADY); // @[src/main/scala/GPIO.scala 167:10]
    end
    //
    if (_T_916) begin
      cover(io_apb_PSLVERR); // @[src/main/scala/GPIO.scala 168:10]
    end
  end
endmodule
