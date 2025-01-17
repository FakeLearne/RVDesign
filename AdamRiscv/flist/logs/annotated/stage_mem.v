	// verilator_coverage annotation
	`include "../define.vh"
	
	module stage_mem(
 020001	    input  wire        clk,
%000001	    input  wire        rst,
 000248	    input  wire[31:0]  me_regs_data2,
%000177	    input  wire[31:0]  me_alu_o,
%000001	    input  wire        me_mem_read,
%000000	    input  wire        me_mem_write,
 000030	    input  wire[2:0]   me_func3_code,
	    //forwarding
%000000	    input wire         forward_data,
%000168	    input wire[31:0]   w_regs_data,
 026589	    input wire[31:0]   me_inst,
 105557	    input wire[31:0]   me_matrix_line_data,
%000002	    input wire         me_matrix2mem,
	
%000016	    output wire[31:0]  me_mem_data
	);
	
 000245	wire[31:0]  w_data_mem;
%000023	wire[31:0]  r_data_mem;
	
	data_memory 
	#(
	    .DROM_SPACE (1024       )
	)
	u_data_memory(
	    .clk        (clk               ),
	    .rst        (rst               ),
	    .data_addr  (me_alu_o          ),
	    .w_data_mem (w_data_mem        ),
	    .r_en_mem   (me_mem_read       ),
	    .w_en_mem   (me_mem_write      ),
	    .byte_sel   (me_func3_code[1:0]),
	    .r_data_mem (r_data_mem        )
	);
	
	assign w_data_mem  = me_matrix2mem ? me_matrix_line_data : forward_data ? w_regs_data : me_regs_data2;
	
	assign me_mem_data = ({me_inst[14:12], me_inst[6:0]} == `MtypeL) ? r_data_mem:
	                     (me_func3_code == `LB) ? {{24{r_data_mem[7]}},r_data_mem[7:0]}:
	                     (me_func3_code == `LH) ? {{16{r_data_mem[7]}},r_data_mem[15:0]}:
	                     (me_func3_code == `LBU)? {24'b0,r_data_mem[7:0]}:
	                     (me_func3_code == `LHU)? {16'b0,r_data_mem[15:0]}:
	                     r_data_mem;
	
	endmodule
	
