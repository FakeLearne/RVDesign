	// verilator_coverage annotation
	module stage_id(
 020001	    input wire         clk,
%000001	    input wire         rst,
 145137	    input wire[31:0]   id_inst,
 000012	    input wire         w_regs_en,
 000042	    input wire[4:0]    w_regs_addr,
%000168	    input wire[31:0]   w_regs_data,
%000000	    input wire         ctrl_stall,
	
%000001	    input wire w_matrix_en,
%000002	    input wire w_matrix_en_mopa,
%000011	    input wire[1:0] w_matrix_index,
%000176	    input wire[31:0] w_matrix_data,
%000118	    input wire[31:0] w_matrix_data_mopa[3:0],
	
 105680	    output  wire[31:0] id_regs_data1,
 105616	    output  wire[31:0] id_regs_data2,
 000205	    output  wire[31:0] id_imm,
 013201	    output  wire[2:0]  id_func3_code, 
%000005	    output  wire       id_func7_code,
 026385	    output  wire[4:0]  id_rd,
 006594	    output  wire       id_br,
%000000	    output  wire       id_mem_read,
%000001	    output  wire       id_mem2reg,
 013209	    output  wire[2:0]  id_alu_op,
%000000	    output  wire       id_mem_write,
 000029	    output  wire[1:0]  id_alu_src1,
%000012	    output  wire[1:0]  id_alu_src2,
%000001	    output  wire       id_br_addr_mode,
 000011	    output  wire       id_regs_write,
	    //forwarding
 013215	    output  wire[4:0]  id_rs1,
 032972	    output  wire[4:0]  id_rs2,
	
	    // matrix
%000010	    output wire[1:0] id_matrix_index,
%000001	    output wire id_mem2matrix,
%000001	    output wire id_matrix_write,
%000001	    output wire id_matrix_write_mopa,
%000008	    output wire[1:0] id_mem_matrix2reg,
%000162	    output wire[31:0] id_matrix_line_data,
%000001	    output wire id_mem_reg2matrix,
%000001	    output wire id_matrix2mem,
%000137	    output wire[31:0] id_M[3:0]
	);
	
 006595	wire        br          ;
%000001	wire        mem_read    ;
%000001	wire        mem2reg     ;
 013209	wire[2:0]   alu_op      ;
%000000	wire        mem_write   ;
 000029	wire[1:0]   alu_src1    ;
%000012	wire[1:0]   alu_src2    ;
%000000	wire        br_addr_mode;
 000010	wire        regs_write  ;
	
	matrix_data u_matrix(
	    .clk(clk),
	    .rst(rst),
	    .r_matrix_index(id_matrix_index),
	    .w_matrix_index(w_matrix_index),
	    .w_matrix_data(w_matrix_data),
	    .w_matrix_data_mopa(w_matrix_data_mopa),
	
	    .w_matrix_en(w_matrix_en),
	    .w_matrix_en_mopa(w_matrix_en_mopa),
	    .r_matrix_o(id_matrix_line_data),
	    .M_out(id_M)
	);
	
	regs u_regs(
	    .clk          (clk              ),
	    .rst          (rst              ),
	    .r_regs_addr1 (id_inst[19:15]   ),
	    .r_regs_addr2 (id_inst[24:20]   ),
	    .w_regs_addr  (w_regs_addr      ),
	    .w_regs_data  (w_regs_data      ),
	    .w_regs_en    (w_regs_en        ),
	    .r_regs_o1    (id_regs_data1    ),
	    .r_regs_o2    (id_regs_data2    )
	);
	
	ctrl u_ctrl(
	    .inst           (id_inst),
	    .inst_op        (id_inst[6:0] ),
	    .br             (br           ),
	    .mem_read       (mem_read     ),
	    .mem2reg        (mem2reg      ),
	    .alu_op         (alu_op       ),
	    .mem_write      (mem_write    ),
	    .alu_src1       (alu_src1     ),
	    .alu_src2       (alu_src2     ),
	    .br_addr_mode   (br_addr_mode ),
	    .regs_write     (regs_write   ),
	    .mem2matrix     (id_mem2matrix),
	    .matrix_write   (id_matrix_write),
	    .matrix_write_mopa(id_matrix_write_mopa),
	    .mem_matrix2reg (id_mem_matrix2reg),
	    .mem_reg2matrix (id_mem_reg2matrix)
	);
	
	imm_gen u_imm_gen(
	    .inst  (id_inst  ),
	    .imm_o (id_imm   )
	);
	
	assign id_rd         = id_inst[11:7];
	assign id_func3_code = {id_inst[14:12], id_inst[6:0]} == `MtypeS ? 3'b010 : id_inst[14:12];
	assign id_func7_code = id_inst[30];
	
	assign id_rs1 = id_inst[19:15];
	assign id_rs2 = id_inst[24:20];
	assign id_matrix_index = ({id_inst[14:12], id_inst[6:0]} == `MtypeL || {id_inst[14:12], id_inst[6:0]} == `MtypeM2) ? id_inst[8:7] : 
	                         ({id_inst[14:12], id_inst[6:0]} == `MtypeM1|| {id_inst[14:12], id_inst[6:0]} == `MtypeS) ? id_inst[21:20] : 2'b00;
	
	assign id_matrix2mem = {id_inst[14:12], id_inst[6:0]} == `MtypeS ? 1'b1 : 1'b0; 
	
	//stall
	assign id_br           = (ctrl_stall == 1) ? 0 : br             ;
	assign id_mem_read     = (ctrl_stall == 1) ? 0 : mem_read       ;       
	assign id_mem2reg      = (ctrl_stall == 1) ? 0 : mem2reg        ;      
	assign id_alu_op       = (ctrl_stall == 1) ? 0 : alu_op         ;     
	assign id_mem_write    = (ctrl_stall == 1) ? 0 : mem_write      ;            
	assign id_alu_src1     = (ctrl_stall == 1) ? 0 : alu_src1       ;
	assign id_alu_src2     = (ctrl_stall == 1) ? 0 : alu_src2       ; 
	assign id_br_addr_mode = (ctrl_stall == 1) ? 0 : br_addr_mode   ;       
	assign id_regs_write   = (ctrl_stall == 1) ? 0 : regs_write     ;             
	
	endmodule
