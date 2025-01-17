	// verilator_coverage annotation
	module stage_wb(
%000031	    input  wire[31:0]  wb_mem_data,
%000179	    input  wire[31:0]  wb_alu_o,
%000002	    input  wire        wb_mem2reg,
%000011	    input  wire[1:0]   wb_matrix_index,
 000012	    input  wire[1:0]   wb_mem_matrix2reg,
 105553	    input  wire[31:0]  wb_matrix_line_data,
%000003	    input  wire        wb_mem_reg2matrix,
 000312	    input  wire[31:0]  wb_regs_data1,
%000127	    input  wire[31:0]  wb_matrix_mul_o[3:0],
	
%000168	    output wire[31:0]  w_regs_data,
%000176	    output wire[31:0]  w_matrix_data,
%000122	    output wire[31:0]  w_matrix_data_mopa[3:0]
	);
	
	always@(*) begin
%000001	    if(wb_mem_matrix2reg == 2'b11)
	        w_regs_data = wb_mem_data; // 从内存中读取的值
	    else
 010000	        w_regs_data = wb_alu_o;    // ALU 计算出的值
	end
	
	always@(*) begin
%000001	    if(wb_mem_reg2matrix == 1'b1)
	        w_matrix_data = wb_mem_data; // 从内存中读取的值
	    else
 010000	        w_matrix_data = wb_alu_o;    // ALU 计算出的值
	end
	
	assign w_matrix_data_mopa = wb_matrix_mul_o;
	
	endmodule
	
