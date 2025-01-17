module stage_wb(
    input  wire[31:0]  wb_mem_data,
    input  wire[31:0]  wb_alu_o,
    input  wire        wb_mem2reg,
    input  wire[1:0]   wb_matrix_index,
    input  wire[1:0]   wb_mem_matrix2reg,
    input  wire[31:0]  wb_matrix_line_data,
    input  wire        wb_mem_reg2matrix,
    input  wire[31:0]  wb_regs_data1,
    input  wire[31:0]  wb_matrix_mul_o[3:0],

    output wire[31:0]  w_regs_data,
    output wire[31:0]  w_matrix_data,
    output wire[31:0]  w_matrix_data_mopa[3:0]
);

always@(*) begin
    if(wb_mem_matrix2reg == 2'b11)
        w_regs_data = wb_mem_data; // 从内存中读取的值
    else
        w_regs_data = wb_alu_o;    // ALU 计算出的值
end

always@(*) begin
    if(wb_mem_reg2matrix == 1'b1)
        w_matrix_data = wb_mem_data; // 从内存中读取的值
    else
        w_matrix_data = wb_alu_o;    // ALU 计算出的值
end

assign w_matrix_data_mopa = wb_matrix_mul_o;

endmodule
