	// verilator_coverage annotation
	`include "../define.vh"
	
	module stage_ex(
 013234	    input  wire[31:0]  ex_pc,  //pc_now
 000317	    input  wire[31:0]  ex_regs_data1,
 000248	    input  wire[31:0]  ex_regs_data2,
 000222	    input  wire[31:0]  ex_imm,
 000029	    input  wire[2:0]   ex_func3_code, 
%000004	    input  wire        ex_func7_code,
 019797	    input  wire[2:0]   ex_alu_op,
 000030	    input  wire[1:0]   ex_alu_src1,
%000013	    input  wire[1:0]   ex_alu_src2,
 006589	    input  wire        ex_br_addr_mode,
 006594	    input  wire        ex_br,
 421755	    input  wire[31:0]  ex_M[3:0],
	    //forwarding
 000019	    input  wire[1:0]   forwardA,
%000010	    input  wire[1:0]   forwardB,
%000177	    input  wire[31:0]  me_alu_o,
%000168	    input  wire[31:0]  w_regs_data,
 105565	    input  wire[31:0]  ex_matrix_line_data,
 105557	    input  wire[31:0]  me_matrix_line_data,
	
%000171	    output wire[31:0]  ex_alu_o,
%000065	    output wire[31:0]  ex_matrix_mul_o [3:0],
 013405	    output wire[31:0]  br_pc, //branch address
 006588	    output wire        br_ctrl
	);
	
 026373	wire [3:0]  alu_ctrl;
%000145	wire [31:0] op_A;
 000282	wire [31:0] op_A_pre;
 000316	wire [31:0] op_B;
 000256	wire [31:0] op_B_pre;
%000004	wire        br_mark;
 013239	wire [31:0] br_addr_op_A; 
	
	alu_control u_alu_control(
	    .alu_op     (ex_alu_op     ),
	    .func3_code (ex_func3_code ),
	    .func7_code (ex_func7_code ),
	    .alu_ctrl_r (alu_ctrl      )
	);
	
	
	alu u_alu(
	    .alu_ctrl (alu_ctrl      ),
	    .op_A     (op_A          ),
	    .op_B     (op_B          ),
	    .alu_o    (ex_alu_o      ),
	    .br_mark  (br_mark       )
	);
	
	matrix_mul u_matrix_mul(
	    .mul_ctrl    (alu_ctrl),
	    .op_A        (op_A),
	    .op_B        (op_B),
	    .M           (ex_M),
	    .matrix_mul_o(ex_matrix_mul_o)
	);
	
	assign br_addr_op_A = (ex_br_addr_mode == `J_REG) ? ex_regs_data1 : ex_pc;
	assign br_pc        = br_addr_op_A + ex_imm;
	
	// assign op_B         = (ex_alu_src2 == `PC_PLUS4)? 32'd4 : (ex_alu_src2 == `IMM)? ex_imm : op_B_pre;
	// assign op_A         = (ex_alu_src1 == `NULL)? 32'd0 : (ex_alu_src1 == `PC)? ex_pc : op_A_pre;
	// assign op_B_pre     = (forwardB == `EX_MEM_B)? me_alu_o : (forwardB == `MEM_WB_B)? w_regs_data : ex_regs_data2;
	// assign op_A_pre     = (forwardA == `EX_MEM_A)? me_alu_o : (forwardA == `MEM_WB_A)? w_regs_data : ex_regs_data1;
	
	always@(*) begin
%000005	    if(ex_alu_src1 == `NULL)
	        op_A = 32'd0;
%000002	    else if(ex_alu_src1 == `PC)
	        op_A = ex_pc;
%000004	    else if(ex_alu_src1 == `MATRIX_M1)
	        op_A = ex_matrix_line_data;
	    else
 009990	        op_A = op_A_pre;
	end
	
	always@(*) begin
%000001	    if(ex_alu_src2 == `PC_PLUS4)
	        op_B = 32'd4;
 000014	    else if(ex_alu_src2 == `IMM)
	        op_B = ex_imm;
%000000	    else if(ex_alu_src2 == `NULL)
	        op_B = 32'd0;
	    else
 009986	        op_B = op_B_pre;
	end
	
	always@(*) begin
%000005	    if(forwardA == `EX_MEM_A)
	        op_A_pre = me_alu_o;
%000004	    else if(forwardA == `MEM_WB_A)
	        op_A_pre = w_regs_data;
	    else
 009992	        op_A_pre = ex_regs_data1;
	end
	
	always@(*) begin
%000005	    if(forwardB == `EX_MEM_B)
	        op_B_pre = me_alu_o;
%000000	    else if(forwardB == `MEM_WB_B)
	        op_B_pre = w_regs_data;
	    else
 009996	        op_B_pre = ex_regs_data2;
	end
	
	assign br_ctrl      = br_mark && ex_br;
	
	always @(*) begin
%000009	    if (|forwardA)
	        $display("forwardA! OP_A: %h",op_A);
%000001	    else if (|forwardB)
	        $display("forwardB! OP_B: %h",op_B);
	end
	
	endmodule
	