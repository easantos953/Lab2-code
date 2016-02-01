module hexto7segment(hex,display);
    input  [3:0] hex;
    output [6:0] display;
    reg [6:0] display;

	always@(hex)
		case(hex)
			4'h0: display = 7'b1000000;
			4'h1: display = 7'b1111001;
			4'h2: display = 7'b0100100;
			4'h3: display = 7'b0110000;
			4'h4: display = 7'b0011001;
			4'h5: display = 7'b0010010;
			4'h6: display = 7'b0000010;
			4'h7: display = 7'b1111000;
			4'h8: display = 7'b0000000;
			4'h9: display = 7'b0011000;
			4'hA: display = 7'b0001000;
			4'hB: display = 7'b0000011;
			4'hC: display = 7'b1000110;
			4'hD: display = 7'b0100001;
			4'hE: display = 7'b0000110;
			4'hF: display = 7'b0001110;
		endcase
endmodule

module lab2(
//Clock pins

CLOCK_50,

DRAM_CLK,
DRAM_CKE,
DRAM_ADDR,
DRAM_BA,
DRAM_CS_N,
DRAM_CAS_N,
DRAM_RAS_N,
DRAM_WE_N,
DRAM_DQ,
DRAM_UDQM,
DRAM_LDQM,

HEX0,
HEX1,
HEX2,
HEX3,
HEX4,
HEX5,

KEY,
LEDR,
SW,

HPS_DDR3_ADDR,
HPS_DDR3_BA,
HPS_DDR3_CAS_N,
HPS_DDR3_CKE,
HPS_DDR3_CK_N,
HPS_DDR3_CK_P,
HPS_DDR3_CS_N,
HPS_DDR3_DM,
HPS_DDR3_DQ,
HPS_DDR3_DQS_N,
HPS_DDR3_DQS_P,
HPS_DDR3_ODT,
HPS_DDR3_RAS_N,
HPS_DDR3_RESET_N,
HPS_DDR3_RZQ,
HPS_DDR3_WE_N,


);



input CLOCK_50;

input DRAM_CLK;
input DRAM_CKE;
input [12:0]DRAM_ADDR;
input [1:0]DRAM_BA;
input DRAM_CS_N;
input DRAM_CAS_N;
input DRAM_RAS_N;
input DRAM_WE_N;
inout [15:0]DRAM_DQ;
input DRAM_UDQM;
input DRAM_LDQM;


output [6:0] HEX0, HEX1, HEX2, HEX3, HEX4, HEX5;
input[3:0] KEY;
output [9:0] LEDR;
input [9:0] SW;

output [14:0] HPS_DDR3_ADDR;
output [2:0] HPS_DDR3_BA;
output HPS_DDR3_CAS_N;
output HPS_DDR3_CKE;
output HPS_DDR3_CK_N;
output HPS_DDR3_CK_P;
output HPS_DDR3_CS_N;
output [3:0] HPS_DDR3_DM;
inout [31:0] HPS_DDR3_DQ;
inout [3:0] HPS_DDR3_DQS_N;
inout [3:0] HPS_DDR3_DQS_P;
output HPS_DDR3_ODT;
output HPS_DDR3_RAS_N;
output HPS_DDR3_RESET_N;
input HPS_DDR3_RZQ;
output HPS_DDR3_WE_N;


wire [31:0] hex3_hex0;
wire [15:0] hex5_hex4;
//wire [8:0] ledr;

//assign HEX0 = ~hex3_hex0[6:0];
//assign HEX1 = ~hex3_hex0[14:8];
//assign HEX2 = ~hex3_hex0[22:16];
//assign HEX3 = ~hex3_hex0[30:24];
//assign HEX4 = ~hex5_hex4[6:0];
//assign HEX5 = ~hex5_hex4[14:8];

    mysystem u0 (
        .system_ref_clk_clk            (CLOCK_50),            //         clk.clk
        .system_ref_reset_reset      (~KEY[0]),      //       reset.reset_n
		  .sdram_clk_clk          (DRAM_CLK),
		  
        .memory_mem_a       (HPS_DDR3_ADDR),       //      memory.mem_a
        .memory_mem_ba      (HPS_DDR3_BA),      //            .mem_ba
        .memory_mem_ck      (HPS_DDR3_CK_P),      //            .mem_ck
        .memory_mem_ck_n    (HPS_DDR3_CK_N),    //            .mem_ck_n
        .memory_mem_cke     (HPS_DDR3_CKE),     //            .mem_cke
        .memory_mem_cs_n    (HPS_DDR3_CS_N),    //            .mem_cs_n
        .memory_mem_ras_n   (HPS_DDR3_RAS_N),   //            .mem_ras_n
        .memory_mem_cas_n   (HPS_DDR3_CAS_N),   //            .mem_cas_n
        .memory_mem_we_n    (HPS_DDR3_WE_N),    //            .mem_we_n
        .memory_mem_reset_n (HPS_DDR3_RESET_N), //            .mem_reset_n
        .memory_mem_dq      (HPS_DDR3_DQ),      //            .mem_dq
        .memory_mem_dqs     (HPS_DDR3_DQS_P),     //            .mem_dqs
        .memory_mem_dqs_n   (HPS_DDR3_DQS_N),   //            .mem_dqs_n
        .memory_mem_odt     (HPS_DDR3_ODT),     //            .mem_odt
        .memory_mem_dm      (HPS_DDR3_DM),      //            .mem_dm
        .memory_oct_rzqin   (HPS_DDR3_RZQ),   //            .oct_rzqin
		  
       // .rled_export        (LEDR),        //        rled.export
		 // .switches_export    (SW),    //    switches.export
		  
        .hex3_hex0_export   (hex3_hex0),   //   hex3_hex0.export
        .hex5_hex4_export   (hex5_hex4),   //   hex5_hex4.export
        .pushbutton_export (~KEY[3:1]),  // pushbuttons.export
		  .to_hex_to_led_readdata (LEDR),  //    to_hex_to_led.readdata
		  
		  .sdram_wire_addr        (DRAM_ADDR),        //       sdram_wire.addr
        .sdram_wire_ba          (DRAM_BA),          //                 .ba
        .sdram_wire_cas_n       (DRAM_CAS_N),       //                 .cas_n
        .sdram_wire_cke         (DRAM_CKE),         //                 .cke
        .sdram_wire_cs_n        (DRAM_CS_N),        //                 .cs_n
        .sdram_wire_dq          (DRAM_DQ),          //                 .dq
        .sdram_wire_dqm         ({DRAM_UDQM,DRAM_LDQM}),         //                 .dqm
        .sdram_wire_ras_n       (DRAM_RAS_N),       //                 .ras_n
        .sdram_wire_we_n        (DRAM_WE_N)         //                 .we_n
		  );
		  
		  hexto7segment h0(hex3_hex0[3:0],HEX0);
		  hexto7segment h1(hex3_hex0[7:4],HEX1);
		  hexto7segment h2(hex3_hex0[11:8],HEX2);
		  hexto7segment h3(hex3_hex0[15:12],HEX3);
		  hexto7segment h4(hex5_hex4[3:0],HEX4);
		  hexto7segment h5(hex5_hex4[7:4],HEX5);
	//	  hexto7segment h6(ledr[3:0] ,LEDR[5:0]);
	//	  hexto7segment h7(ledr[7:4] ,LEDR[8:6]);
		  
		  
endmodule




