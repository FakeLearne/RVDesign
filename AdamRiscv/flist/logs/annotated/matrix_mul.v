	// verilator_coverage annotation
	`include "../define.vh"
	
	module matrix_mul(
 026373	    input  wire[3:0]     mul_ctrl,
%000145	    input  wire[31:0]    op_A,
 000316	    input  wire[31:0]    op_B,
 421776	    input  wire[31:0]    M[3:0],
%000063	    output reg[31:0]     matrix_mul_o [3:0]   
	);
	
%000013	wire[31:0] matrix_line_0;
%000012	wire[31:0] matrix_line_1;
%000016	wire[31:0] matrix_line_2;
%000010	wire[31:0] matrix_line_3;
	
	always @(mul_ctrl, op_A, op_B) begin
	    case (mul_ctrl)
%000000	        `MATRIX_MUL : begin
	            matrix_line_3 = {
	                M[3][31:24] + op_A[31:24] * op_B[31:24],
	                M[3][23:16] + op_A[23:16] * op_B[31:24],
	                M[3][15:8]  + op_A[15:8]  * op_B[31:24],
	                M[3][7:0]   + op_A[7:0]   * op_B[31:24]
	            };
	            matrix_line_2 = {
	                M[2][31:24] + op_A[31:24] * op_B[23:16],
	                M[2][23:16] + op_A[23:16] * op_B[23:16],
	                M[2][15:8]  + op_A[15:8]  * op_B[23:16], 
	                M[2][7:0]   + op_A[7:0]   * op_B[23:16]
	            };
	            matrix_line_1 = {
	                M[1][31:24] + op_A[31:24] * op_B[15:8],
	                M[1][23:16] + op_A[23:16] * op_B[15:8],
	                M[1][15:8]  + op_A[15:8]  * op_B[15:8],
	                M[1][7:0]   + op_A[7:0]   * op_B[15:8]
	            };
	            matrix_line_0 = {
	                M[0][31:24] + op_A[31:24] * op_B[7:0],
	                M[0][23:16] + op_A[23:16] * op_B[7:0],
	                M[0][15:8]  + op_A[15:8]  * op_B[7:0],
	                M[0][7:0]   + op_A[7:0]   * op_B[7:0]
	            };
	        end
 010001	        default: begin
	            matrix_line_3 = 32'b0;
	            matrix_line_2 = 32'b0;
	            matrix_line_1 = 32'b0;
	            matrix_line_0 = 32'b0;
	        end
	    endcase
	end
	
	assign matrix_mul_o[3] = matrix_line_3;
	assign matrix_mul_o[2] = matrix_line_2;
	assign matrix_mul_o[1] = matrix_line_1;
	assign matrix_mul_o[0] = matrix_line_0;
	
	endmodule
	
