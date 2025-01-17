	// verilator_coverage annotation
	module reg_mem_wb(
 020001	    input  wire clk,
%000001	    input  wire rst,
%000016	    input  wire[31:0] me_mem_data,
%000177	    input  wire[31:0] me_alu_o,
%000041	    input  wire[4:0]  me_rd,
%000001	    input  wire       me_mem2reg,
 000010	    input  wire       me_regs_write,
%000010	    input  wire[1:0]  me_matrix_index,
%000000	    input  wire       me_mem2matrix,
%000001	    input  wire       me_matrix_write,
%000001	    input  wire       me_matrix_write_mopa,
%000010	    input  wire[1:0]  me_mem_matrix2reg,
 105557	    input  wire[31:0] me_matrix_line_data,
%000003	    input  wire       me_mem_reg2matrix,
 000310	    input  wire[31:0] me_regs_data1,
%000134	    input  wire[31:0] me_matrix_mul_o[3:0],
 026589	    input  wire[31:0] me_inst,
	
%000031	    output reg[31:0]  wb_mem_data,
%000179	    output reg[31:0]  wb_alu_o,
 000042	    output reg[4:0]   wb_rd,
%000002	    output reg        wb_mem2reg,
 000012	    output reg        wb_regs_write,
%000011	    output reg[1:0]   wb_matrix_index,
%000002	    output reg        wb_mem2matrix,
%000001	    output reg        wb_matrix_write,
%000002	    output reg        wb_matrix_write_mopa,
 000012	    output reg[1:0]   wb_mem_matrix2reg,
 105553	    output reg[31:0]  wb_matrix_line_data,
%000003	    output reg        wb_mem_reg2matrix,
 000312	    output reg[31:0]  wb_regs_data1,
%000123	    output reg[31:0]  wb_matrix_mul_o[3:0],
 026581	    output reg[31:0]  wb_inst
	);
	
	always @(posedge clk) begin
 000100	    if (!rst)begin
	        wb_mem_data    <= 0;     
	        wb_alu_o       <= 0;     
	        wb_rd          <= 0; 
	        wb_mem2reg     <= 0;     
	        wb_regs_write  <= 0;         
	        wb_matrix_index <=0;     
	        wb_mem2matrix  <= 0;
	        wb_matrix_write <= 0;
	        wb_matrix_write_mopa <= 0;
	        wb_mem_matrix2reg <= 0;
	        wb_matrix_line_data <= 0;
	        wb_mem_reg2matrix <= 0;
	        wb_regs_data1 <= 0;
	        wb_matrix_mul_o[0] <= 0;
	        wb_matrix_mul_o[1] <= 0;
	        wb_matrix_mul_o[2] <= 0;
	        wb_matrix_mul_o[3] <= 0;
	        wb_inst <= 0;
	    end 
 009900	    else begin
	        wb_mem_data    <= me_mem_data;     
	        wb_alu_o       <= me_alu_o;     
	        wb_rd          <= me_rd; 
	        wb_mem2reg     <= me_mem2reg;     
	        wb_regs_write  <= me_regs_write;   
	        wb_matrix_index<= me_matrix_index;
	        wb_mem2matrix  <= me_mem2matrix;
	        wb_matrix_write <= me_matrix_write;
	        wb_matrix_write_mopa <= me_matrix_write_mopa;
	        wb_mem_matrix2reg <= me_mem_matrix2reg;
	        wb_matrix_line_data <= me_matrix_line_data;
	        wb_mem_reg2matrix   <= me_mem_reg2matrix;
	        wb_regs_data1       <= me_regs_data1;
	        wb_matrix_mul_o[0] <= me_matrix_mul_o[0];
	        wb_matrix_mul_o[1] <= me_matrix_mul_o[1];
	        wb_matrix_mul_o[2] <= me_matrix_mul_o[2];
	        wb_matrix_mul_o[3] <= me_matrix_mul_o[3];
	        wb_inst <= me_inst;
	    end
	end
	
	endmodule
