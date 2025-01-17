	// verilator_coverage annotation
	module matrix_data(
 020001	    input wire clk,
%000001	    input wire rst,
%000010	    input wire[1:0]     r_matrix_index,
%000011	    input wire[1:0]     w_matrix_index,
%000176	    input wire[31:0]    w_matrix_data,
%000110	    input wire[31:0]    w_matrix_data_mopa[3:0],
%000001	    input wire          w_matrix_en,
%000002	    input wire          w_matrix_en_mopa,
	
%000162	    output wire[31:0]   r_matrix_o,
%000138	    output wire[31:0]   M_out[3:0]
	);
	
%000136	reg [31:0] M [3:0]; //  4 32-bit registers matrix
	
	/*------------------------Write Matrix---------------*/
	always @(posedge clk) begin
 000100	    if (!rst) begin
	        M[0] <= 32'h55555555;
	        M[1] <= 32'haaaaaaaa;
	        M[2] <= 32'h33333333;
	        M[3] <= 32'hcccccccc;
	    end
%000000	    else if (w_matrix_en && !w_matrix_en_mopa) begin
	        M[w_matrix_index] <= w_matrix_data;
	    end
%000000	    else if (w_matrix_en_mopa) begin
	        M[0] <= w_matrix_data_mopa[0];
	        M[1] <= w_matrix_data_mopa[1];
	        M[2] <= w_matrix_data_mopa[2];
	        M[3] <= w_matrix_data_mopa[3];
	    end
 009900	    else begin
	        M[0] <= M[0];
	        M[1] <= M[1];
	        M[2] <= M[2];
	        M[3] <= M[3];
	    end
	end
	
	assign M_out[0] = M[0];
	assign M_out[1] = M[1];
	assign M_out[2] = M[2];
	assign M_out[3] = M[3];
	
	/*------------------------Read Matrix---------------*/
	assign r_matrix_o = M[r_matrix_index];
	endmodule
