// author       : adam_wu
// course       : Microprocessor Architecture and Design
// ID           : 21033075
// project_name : AdamRiscv(Five-stage Pipelined Processor Based on RV32I)

module adam_riscv(
    input wire clk,
    input wire rst
);

wire          br_ctrl;
wire[31:0]    br_addr;
wire          stall;
wire[31:0]    if_pc;
wire[31:0]    if_inst;
wire          flush;
wire[31:0]    id_inst;
wire[31:0]    id_pc;

wire          w_regs_en;
wire[4:0]     w_regs_addr;
wire[31:0]    w_regs_data;
wire[31:0]    w_matrix_data;
wire[31:0]    w_matrix_data_mopa[3:0];

wire[31:0]    id_regs_data1;
wire[31:0]    id_regs_data2;
wire[31:0]    id_imm;
wire[2:0]     id_func3_code; 
wire          id_func7_code;
wire[4:0]     id_rd;
wire          id_br;
wire          id_mem_read;
wire          id_mem2reg;
wire[2:0]     id_alu_op;
wire          id_mem_write;
wire[1:0]     id_alu_src1;
wire[1:0]     id_alu_src2;
wire          id_br_addr_mode;
wire          id_regs_write;
wire[4:0]     id_rs1;
wire[4:0]     id_rs2;

wire[1:0]     id_matrix_index;
wire          id_mem2matrix;
wire          id_matrix_write;
wire          id_matrix_write_mopa;
wire[1:0]     id_mem_matrix2reg;
wire[31:0]    id_matrix_line_data;
wire          id_mem_reg2matrix;
wire          id_matrix2mem;
wire[31:0]    id_M[3:0];

wire[4:0]     ex_rs1;
wire[4:0]     ex_rs2;
wire[31:0]    ex_pc;
wire[31:0]    ex_regs_data1;
wire[31:0]    ex_regs_data2;
wire[31:0]    ex_imm;
wire[2:0]     ex_func3_code; 
wire          ex_func7_code;
wire[4:0]     ex_rd;
wire          ex_br;
wire          ex_mem_read;
wire          ex_mem2reg;
wire[2:0]     ex_alu_op;
wire          ex_mem_write;
wire[1:0]     ex_alu_src1;
wire[1:0]     ex_alu_src2;
wire          ex_br_addr_mode;
wire          ex_regs_write;
wire[31:0]    ex_alu_o;

wire[31:0]    ex_matrix_mul_o [3:0];
wire[1:0]     ex_matrix_index;
wire[31:0]    ex_inst;
wire          ex_mem2matrix;
wire          ex_matrix_write;
wire          ex_matrix_write_mopa;
wire[1:0]     ex_mem_matrix2reg;
wire[31:0]    ex_matrix_line_data;
wire          ex_mem_reg2matrix;
wire          ex_matrix2mem;
wire[31:0]    ex_M[3:0];

wire[1:0]     forwardA;
wire[1:0]     forwardB;

wire [4:0]    me_rs2;
wire [31:0]   me_regs_data2;
wire [31:0]   me_alu_o;
wire [4:0]    me_rd;
wire          me_mem_read;
wire          me_mem2reg;
wire          me_mem_write;
wire          me_regs_write;
wire[31:0]    me_mem_data;
wire[2:0]     me_func3_code;  

wire[1:0]     me_matrix_index;
wire[31:0]    me_inst;
wire          me_mem2matrix;
wire          me_matrix_write;
wire          me_matrix_write_mopa;
wire[1:0]     me_mem_matrix2reg;
wire[31:0]    me_matrix_line_data;
wire          me_mem_reg2matrix;
wire[31:0]    me_regs_data1;
wire          me_matrix2mem;
wire[31:0]    me_matrix_mul_o[3:0];

wire          forward_data;

wire[31:0]    wb_mem_data;
wire[31:0]    wb_alu_o;
wire          wb_mem2reg;

wire[1:0]     wb_matrix_index;
wire          wb_mem2matrix;
wire          wb_matrix_write;
wire          wb_matrix_write_mopa;
wire[1:0]     wb_mem_matrix2reg;
wire[31:0]    wb_matrix_line_data;
wire          wb_mem_reg2matrix;
wire[31:0]    wb_regs_data1;
wire[31:0]    wb_matrix_mul_o[3:0];
wire[31:0]    wb_inst;

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