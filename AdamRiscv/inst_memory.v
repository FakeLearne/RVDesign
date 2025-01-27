module inst_memory #(
    parameter IROM_SPACE = 1024 //1024*8bit
)(
    input  wire[31:0] inst_addr,
    output wire[31:0] inst_o
);

reg [7:0] inst [IROM_SPACE-1:0];
initial $readmemh ("../rom/test_program.hex",inst);
//initial $readmemh ("./AdamRiscv/rom/test2_program.txt",inst);

assign inst_o[7:0]   = inst[inst_addr];
assign inst_o[15:8]  = inst[inst_addr+1];
assign inst_o[23:16] = inst[inst_addr+2];
assign inst_o[31:24] = inst[inst_addr+3];

endmodule
