	// verilator_coverage annotation
	`include "../define.vh"
	
	module alu(
 026373	    input  wire[3:0]     alu_ctrl,
%000145	    input  wire[31:0]    op_A,
 000316	    input  wire[31:0]    op_B,
%000171	    output reg[31:0]     alu_o,
%000004	    output wire          br_mark     
	);
	
	assign br_mark = (alu_ctrl == `JUMP)? 1 :
	                 (alu_ctrl == `NOTEQ || alu_ctrl == `SLT || alu_ctrl == `SLTU)?
	                 (alu_o != 0) : (alu_o == 0);
	 
	always @(alu_ctrl, op_A, op_B) begin
	    case (alu_ctrl)
%000000	        `AND        : alu_o = op_A & op_B;           
%000000	        `OR         : alu_o = op_A | op_B;           
 003410	        `ADD,`JUMP  : alu_o = op_A + op_B;           
 003297	        `SUB,`NOTEQ : alu_o = op_A - op_B;           
%000000	        `XOR        : alu_o = op_A ^ op_B;           
%000000	        `SLT,`SGE   : alu_o = ($signed(op_A)) < ($signed(op_B)) ? 32'b1 : 32'b0;   
%000000	        `SLTU,`SGEU : alu_o = op_A < op_B ? 32'b1 : 32'b0;   
%000000	        `SLL        : alu_o = op_A << op_B[4:0];
%000000	        `SRL        : alu_o = op_A >> op_B[4:0];
%000000	        `SRA        : alu_o = ($signed(op_A)) >>> op_B[4:0];
%000000	        `MATRIX_MUL : alu_o = 0;
 003294	        default: alu_o = 0;
	    endcase
	end
	
	endmodule
	
