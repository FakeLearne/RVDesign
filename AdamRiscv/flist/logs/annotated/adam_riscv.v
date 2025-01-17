	// verilator_coverage annotation
	// author       : adam_wu
	// course       : Microprocessor Architecture and Design
	// ID           : 21033075
	// project_name : AdamRiscv(Five-stage Pipelined Processor Based on RV32I)
	
	module adam_riscv(
 020001	    input wire clk,
%000001	    input wire rst
	);
	
 006588	wire          br_ctrl;
 013405	wire[31:0]    br_addr;
%000000	wire          stall;
 013243	wire[31:0]    if_pc;
 158306	wire[31:0]    if_inst;
 006588	wire          flush;
 145137	wire[31:0]    id_inst;
 019839	wire[31:0]    id_pc;
	
 000012	wire          w_regs_en;
 000042	wire[4:0]     w_regs_addr;
%000168	wire[31:0]    w_regs_data;
%000176	wire[31:0]    w_matrix_data;
%000123	wire[31:0]    w_matrix_data_mopa[3:0];
	
 105680	wire[31:0]    id_regs_data1;
 105616	wire[31:0]    id_regs_data2;
 000205	wire[31:0]    id_imm;
 013201	wire[2:0]     id_func3_code; 
%000005	wire          id_func7_code;
 026385	wire[4:0]     id_rd;
 006594	wire          id_br;
%000000	wire          id_mem_read;
%000001	wire          id_mem2reg;
 013209	wire[2:0]     id_alu_op;
%000000	wire          id_mem_write;
 000029	wire[1:0]     id_alu_src1;
%000012	wire[1:0]     id_alu_src2;
%000001	wire          id_br_addr_mode;
 000011	wire          id_regs_write;
 013215	wire[4:0]     id_rs1;
 032972	wire[4:0]     id_rs2;
	
%000010	wire[1:0]     id_matrix_index;
%000001	wire          id_mem2matrix;
%000001	wire          id_matrix_write;
%000001	wire          id_matrix_write_mopa;
%000008	wire[1:0]     id_mem_matrix2reg;
%000162	wire[31:0]    id_matrix_line_data;
%000001	wire          id_mem_reg2matrix;
%000001	wire          id_matrix2mem;
%000134	wire[31:0]    id_M[3:0];
	
 000044	wire[4:0]     ex_rs1;
 000040	wire[4:0]     ex_rs2;
 013234	wire[31:0]    ex_pc;
 000317	wire[31:0]    ex_regs_data1;
 000248	wire[31:0]    ex_regs_data2;
 000222	wire[31:0]    ex_imm;
 000029	wire[2:0]     ex_func3_code; 
%000004	wire          ex_func7_code;
 000041	wire[4:0]     ex_rd;
 006594	wire          ex_br;
%000000	wire          ex_mem_read;
%000000	wire          ex_mem2reg;
 019797	wire[2:0]     ex_alu_op;
%000001	wire          ex_mem_write;
 000030	wire[1:0]     ex_alu_src1;
%000013	wire[1:0]     ex_alu_src2;
 006589	wire          ex_br_addr_mode;
 000011	wire          ex_regs_write;
%000171	wire[31:0]    ex_alu_o;
	
%000058	wire[31:0]    ex_matrix_mul_o [3:0];
%000011	wire[1:0]     ex_matrix_index;
 026593	wire[31:0]    ex_inst;
%000001	wire          ex_mem2matrix;
%000001	wire          ex_matrix_write;
%000000	wire          ex_matrix_write_mopa;
%000011	wire[1:0]     ex_mem_matrix2reg;
 105565	wire[31:0]    ex_matrix_line_data;
%000002	wire          ex_mem_reg2matrix;
%000002	wire          ex_matrix2mem;
 421763	wire[31:0]    ex_M[3:0];
	
 000019	wire[1:0]     forwardA;
%000010	wire[1:0]     forwardB;
	
 000043	wire [4:0]    me_rs2;
 000248	wire [31:0]   me_regs_data2;
%000177	wire [31:0]   me_alu_o;
%000041	wire [4:0]    me_rd;
%000001	wire          me_mem_read;
%000001	wire          me_mem2reg;
%000000	wire          me_mem_write;
 000010	wire          me_regs_write;
%000016	wire[31:0]    me_mem_data;
 000030	wire[2:0]     me_func3_code;  
	
%000010	wire[1:0]     me_matrix_index;
 026589	wire[31:0]    me_inst;
%000000	wire          me_mem2matrix;
%000001	wire          me_matrix_write;
%000001	wire          me_matrix_write_mopa;
%000010	wire[1:0]     me_mem_matrix2reg;
 105557	wire[31:0]    me_matrix_line_data;
%000003	wire          me_mem_reg2matrix;
 000310	wire[31:0]    me_regs_data1;
%000002	wire          me_matrix2mem;
%000129	wire[31:0]    me_matrix_mul_o[3:0];
	
%000000	wire          forward_data;
	
%000031	wire[31:0]    wb_mem_data;
%000179	wire[31:0]    wb_alu_o;
%000002	wire          wb_mem2reg;
	
%000011	wire[1:0]     wb_matrix_index;
%000002	wire          wb_mem2matrix;
%000001	wire          wb_matrix_write;
%000002	wire          wb_matrix_write_mopa;
 000012	wire[1:0]     wb_mem_matrix2reg;
 105553	wire[31:0]    wb_matrix_line_data;
%000003	wire          wb_mem_reg2matrix;
 000312	wire[31:0]    wb_regs_data1;
%000127	wire[31:0]    wb_matrix_mul_o[3:0];
 026581	wire[31:0]    wb_inst;
	
	stage_if u_stage_if(
	    .clk      (clk      ),
	    .rst      (rst      ),
	    .pc_stall (stall    ),
	    .br_addr  (br_addr  ),
	    .br_ctrl  (br_ctrl  ),
	    .if_inst  (if_inst  ),
	    .if_pc    (if_pc    )
	);
	
	
	reg_if_id u_reg_if_id(
	    .clk         (clk         ),
	    .rst         (rst         ),
	    .if_pc       (if_pc       ),
	    .if_inst     (if_inst     ),
	    .id_inst     (id_inst     ),
	    .id_pc       (id_pc       ),
	    .if_id_flush (flush       ),
	    .if_id_stall (stall       )
	);
	
	stage_id u_stage_id(
	    .clk             (clk             ),
	    .rst             (rst             ),
	    .id_inst         (id_inst         ),
	    .w_regs_en       (w_regs_en       ),
	    .w_regs_addr     (w_regs_addr     ),
	    .w_regs_data     (w_regs_data     ),
	    .ctrl_stall      (stall           ),
	
	    .w_matrix_en(wb_matrix_write),
	    .w_matrix_en_mopa(wb_matrix_write_mopa),
	    .w_matrix_index(wb_matrix_index),
	    .w_matrix_data(w_matrix_data),
	    .w_matrix_data_mopa(w_matrix_data_mopa),
	
	    .id_regs_data1   (id_regs_data1   ),
	    .id_regs_data2   (id_regs_data2   ),
	    .id_imm          (id_imm          ),
	    .id_func3_code   (id_func3_code   ),
	    .id_func7_code   (id_func7_code   ),
	    .id_rd           (id_rd           ),
	    .id_br           (id_br           ),
	    .id_mem_read     (id_mem_read     ),
	    .id_mem2reg      (id_mem2reg      ),
	    .id_alu_op       (id_alu_op       ),
	    .id_mem_write    (id_mem_write    ),
	    .id_alu_src1     (id_alu_src1     ),
	    .id_alu_src2     (id_alu_src2     ),
	    .id_br_addr_mode (id_br_addr_mode ),
	    .id_regs_write   (id_regs_write   ),
	    .id_rs1          (id_rs1          ),
	    .id_rs2          (id_rs2          ),
	
	    .id_matrix_index    (id_matrix_index),
	    .id_mem2matrix      (id_mem2matrix),
	    .id_matrix_write    (id_matrix_write),
	    .id_matrix_write_mopa(id_matrix_write_mopa),
	    .id_mem_matrix2reg  (id_mem_matrix2reg),
	    .id_matrix_line_data(id_matrix_line_data),
	    .id_mem_reg2matrix  (id_mem_reg2matrix),
	    .id_matrix2mem      (id_matrix2mem),
	    .id_M(id_M)
	);
	
	
	reg_id_ex u_reg_id_ex(
	    .clk              (clk             ),
	    .rst              (rst             ),
	    .id_pc            (id_pc           ),
	    .id_regs_data1    (id_regs_data1   ),
	    .id_regs_data2    (id_regs_data2   ),
	    .id_imm           (id_imm          ),
	    .id_func3_code    (id_func3_code   ),
	    .id_func7_code    (id_func7_code   ),
	    .id_rd            (id_rd           ),
	    .id_br            (id_br           ),
	    .id_mem_read      (id_mem_read     ),
	    .id_mem2reg       (id_mem2reg      ),
	    .id_alu_op        (id_alu_op       ),
	    .id_mem_write     (id_mem_write    ),
	    .id_alu_src1      (id_alu_src1     ),
	    .id_alu_src2      (id_alu_src2     ),
	    .id_br_addr_mode  (id_br_addr_mode ),
	    .id_regs_write    (id_regs_write   ),
	    .id_ex_flush      (flush           ),
	    .id_rs1           (id_rs1          ),
	    .id_rs2           (id_rs2          ),
	    .id_matrix_index  (id_matrix_index ),
	    .id_inst          (id_inst),
	    .id_mem2matrix    (id_mem2matrix),
	    .id_matrix_write  (id_matrix_write),
	    .id_matrix_write_mopa(id_matrix_write_mopa),
	    .id_mem_matrix2reg(id_mem_matrix2reg),
	    .id_matrix_line_data(id_matrix_line_data),
	    .id_mem_reg2matrix(id_mem_reg2matrix),
	    .id_matrix2mem(id_matrix2mem),
	    .id_M(id_M),
	
	    .ex_rs1          (ex_rs1          ),
	    .ex_rs2          (ex_rs2          ),
	    .ex_pc           (ex_pc           ),
	    .ex_regs_data1   (ex_regs_data1   ),
	    .ex_regs_data2   (ex_regs_data2   ),
	    .ex_imm          (ex_imm          ),
	    .ex_func3_code   (ex_func3_code   ),
	    .ex_func7_code   (ex_func7_code   ),
	    .ex_rd           (ex_rd           ),
	    .ex_br           (ex_br           ),
	    .ex_mem_read     (ex_mem_read     ),
	    .ex_mem2reg      (ex_mem2reg      ),
	    .ex_alu_op       (ex_alu_op       ),
	    .ex_mem_write    (ex_mem_write    ),
	    .ex_alu_src1     (ex_alu_src1     ),
	    .ex_alu_src2     (ex_alu_src2     ),
	    .ex_br_addr_mode (ex_br_addr_mode ),
	    .ex_regs_write   (ex_regs_write   ),
	    .ex_matrix_index (ex_matrix_index),
	    .ex_inst         (ex_inst),
	    .ex_mem2matrix   (ex_mem2matrix),
	    .ex_matrix_write (ex_matrix_write),
	    .ex_matrix_write_mopa(ex_matrix_write_mopa),
	    .ex_mem_matrix2reg(ex_mem_matrix2reg),
	    .ex_matrix_line_data(ex_matrix_line_data),
	    .ex_mem_reg2matrix(ex_mem_reg2matrix),
	    .ex_matrix2mem(ex_matrix2mem),
	    .ex_M(ex_M)
	);
	
	
	
	stage_ex u_stage_ex(
	    .ex_pc           (ex_pc           ),
	    .ex_regs_data1   (ex_regs_data1   ),
	    .ex_regs_data2   (ex_regs_data2   ),
	    .ex_imm          (ex_imm          ),
	    .ex_func3_code   (ex_func3_code   ),
	    .ex_func7_code   (ex_func7_code   ),
	    .ex_alu_op       (ex_alu_op       ),
	    .ex_alu_src1     (ex_alu_src1     ),
	    .ex_alu_src2     (ex_alu_src2     ),
	    .ex_br_addr_mode (ex_br_addr_mode ),
	    .ex_br           (ex_br           ),
	    .ex_M(ex_M),
	    .forwardA        (forwardA        ),
	    .forwardB        (forwardB        ),
	    .me_alu_o        (me_alu_o        ),
	    .w_regs_data     (w_regs_data     ),
	    .ex_matrix_line_data(ex_matrix_line_data),
	    .me_matrix_line_data(me_matrix_line_data),
	    .ex_alu_o        (ex_alu_o        ),
	    .ex_matrix_mul_o (ex_matrix_mul_o),
	    .br_pc           (br_addr         ),
	    .br_ctrl         (br_ctrl         )
	);
	
	reg_ex_mem u_reg_ex_mem(
	    .clk           (clk           ),
	    .rst           (rst           ),
	    .ex_regs_data1 (ex_regs_data1 ), 
	    .ex_regs_data2 (ex_regs_data2 ),
	    .ex_alu_o      (ex_alu_o      ),
	    .ex_rd         (ex_rd         ),
	    .ex_mem_read   (ex_mem_read   ),
	    .ex_mem2reg    (ex_mem2reg    ),
	    .ex_mem_write  (ex_mem_write  ),
	    .ex_regs_write (ex_regs_write ),
	    .ex_func3_code (ex_func3_code ),
	    .ex_rs2        (ex_rs2        ),
	    .ex_matrix_index(ex_matrix_index),
	    .ex_inst(ex_inst),
	    .ex_mem2matrix(ex_mem2matrix),
	    .ex_matrix_write(ex_matrix_write),
	    .ex_matrix_write_mopa(ex_matrix_write_mopa),
	    .ex_mem_matrix2reg(ex_mem_matrix2reg),
	    .ex_matrix_line_data(ex_matrix_line_data),
	    .ex_mem_reg2matrix(ex_mem_reg2matrix),
	    .ex_matrix2mem(ex_matrix2mem),
	    .ex_matrix_mul_o(ex_matrix_mul_o),
	
	    .me_rs2        (me_rs2        ),
	    .me_regs_data1 (me_regs_data1 ),
	    .me_regs_data2 (me_regs_data2 ),
	    .me_alu_o      (me_alu_o      ),
	    .me_rd         (me_rd         ),
	    .me_mem_read   (me_mem_read   ),
	    .me_mem2reg    (me_mem2reg    ),
	    .me_mem_write  (me_mem_write  ),
	    .me_regs_write (me_regs_write ),
	    .me_func3_code (me_func3_code ),
	    .me_matrix_index(me_matrix_index),
	    .me_inst(me_inst),
	    .me_mem2matrix(me_mem2matrix),
	    .me_matrix_write(me_matrix_write),
	    .me_matrix_write_mopa(me_matrix_write_mopa),
	    .me_mem_matrix2reg(me_mem_matrix2reg),
	    .me_matrix_line_data(me_matrix_line_data),
	    .me_mem_reg2matrix(me_mem_reg2matrix),
	    .me_matrix2mem(me_matrix2mem),
	    .me_matrix_mul_o(me_matrix_mul_o)
	);
	
	stage_mem u_stage_mem(
	    .clk           (clk           ),
	    .rst           (rst           ),
	    .me_regs_data2 (me_regs_data2 ),
	    .me_alu_o      (me_alu_o      ),
	    .me_mem_read   (me_mem_read   ),
	    .me_mem_write  (me_mem_write  ),
	    .me_func3_code (me_func3_code ),
	    .forward_data  (forward_data  ),
	    .w_regs_data   (w_regs_data   ),
	    .me_inst       (me_inst),
	    .me_matrix_line_data(me_matrix_line_data),
	    .me_matrix2mem(me_matrix2mem),
	    .me_mem_data   (me_mem_data   )
	);
	
	
	reg_mem_wb u_reg_mem_wb(
	    .clk           (clk           ),
	    .rst           (rst           ),
	    .me_mem_data   (me_mem_data   ),
	    .me_alu_o      (me_alu_o      ),
	    .me_rd         (me_rd         ),
	    .me_mem2reg    (me_mem2reg    ),
	    .me_regs_write (me_regs_write ),
	    .me_matrix_index(me_matrix_index),
	    .me_mem2matrix(me_mem2matrix),
	    .me_matrix_write(me_matrix_write),
	    .me_matrix_write_mopa(me_matrix_write_mopa),
	    .me_mem_matrix2reg(me_mem_matrix2reg),
	    .me_matrix_line_data(me_matrix_line_data),
	    .me_mem_reg2matrix(me_mem_reg2matrix),
	    .me_regs_data1(me_regs_data1),
	    .me_matrix_mul_o(me_matrix_mul_o),
	    .me_inst(me_inst),
	
	    .wb_mem_data   (wb_mem_data   ),
	    .wb_alu_o      (wb_alu_o      ),
	    .wb_rd         (w_regs_addr   ),
	    .wb_mem2reg    (wb_mem2reg    ),
	    .wb_regs_write (w_regs_en     ),
	    .wb_matrix_index(wb_matrix_index),
	    .wb_mem2matrix(wb_mem2matrix),
	    .wb_matrix_write(wb_matrix_write),
	    .wb_matrix_write_mopa(wb_matrix_write_mopa),
	    .wb_mem_matrix2reg(wb_mem_matrix2reg),
	    .wb_matrix_line_data(wb_matrix_line_data),
	    .wb_mem_reg2matrix(wb_mem_reg2matrix),
	    .wb_regs_data1(wb_regs_data1),
	    .wb_matrix_mul_o(wb_matrix_mul_o),
	    .wb_inst(wb_inst)
	);
	
	
	stage_wb u_stage_wb(
	    .wb_mem_data (wb_mem_data ),
	    .wb_alu_o    (wb_alu_o    ),
	    .wb_mem2reg  (wb_mem2reg  ),
	    .wb_matrix_index(wb_matrix_index),
	    .wb_mem_matrix2reg(wb_mem_matrix2reg),
	    .wb_matrix_line_data(wb_matrix_line_data),
	    .wb_mem_reg2matrix(wb_mem_reg2matrix),
	    .wb_regs_data1(wb_regs_data1),
	    .wb_matrix_mul_o(wb_matrix_mul_o),
	
	    .w_regs_data (w_regs_data ),
	    .w_matrix_data(w_matrix_data),
	    .w_matrix_data_mopa(w_matrix_data_mopa)
	);
	
	forwarding u_forwarding(
	    .ex_rs1        (ex_rs1        ),
	    .ex_rs2        (ex_rs2        ),
	    .me_rd         (me_rd         ),
	    .wb_rd         (w_regs_addr   ),
	    .me_rs2        (me_rs2        ),
	    .me_mem_write  (me_mem_write  ),
	    .me_regs_write (me_regs_write ),
	    .wb_regs_write (w_regs_en     ),
	    .forwardA      (forwardA      ),
	    .forwardB      (forwardB      ),
	    .forward_data  (forward_data  )
	);
	
	hazard_detection u_hazard_detection(
	    .ex_mem_read (ex_mem_read ),
	    .id_rs1      (id_rs1      ),
	    .id_rs2      (id_rs2      ),
	    .ex_rd       (ex_rd       ),
	    .br_ctrl     (br_ctrl     ),
	    .if_inst     (if_inst),
	    .ex_inst     (ex_inst),
	    .me_inst     (me_inst),
	    .wb_inst     (wb_inst),
	    .load_stall  (stall       ),
	    .flush       (flush       )
	);
	
	
	endmodule
