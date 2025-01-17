module reg_mem_wb(
    input  wire clk,
    input  wire rst,
    input  wire[31:0] me_mem_data,
    input  wire[31:0] me_alu_o,
    input  wire[4:0]  me_rd,
    input  wire       me_mem2reg,
    input  wire       me_regs_write,
    input  wire[1:0]  me_matrix_index,
    input  wire       me_mem2matrix,
    input  wire       me_matrix_write,
    input  wire       me_matrix_write_mopa,
    input  wire[1:0]  me_mem_matrix2reg,
    input  wire[31:0] me_matrix_line_data,
    input  wire       me_mem_reg2matrix,
    input  wire[31:0] me_regs_data1,
    input  wire[31:0] me_matrix_mul_o[3:0],
    input  wire[31:0] me_inst,

    output reg[31:0]  wb_mem_data,
    output reg[31:0]  wb_alu_o,
    output reg[4:0]   wb_rd,
    output reg        wb_mem2reg,
    output reg        wb_regs_write,
    output reg[1:0]   wb_matrix_index,
    output reg        wb_mem2matrix,
    output reg        wb_matrix_write,
    output reg        wb_matrix_write_mopa,
    output reg[1:0]   wb_mem_matrix2reg,
    output reg[31:0]  wb_matrix_line_data,
    output reg        wb_mem_reg2matrix,
    output reg[31:0]  wb_regs_data1,
    output reg[31:0]  wb_matrix_mul_o[3:0],
    output reg[31:0]  wb_inst
);

always @(posedge clk) begin
    if (!rst)begin
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
    else begin
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