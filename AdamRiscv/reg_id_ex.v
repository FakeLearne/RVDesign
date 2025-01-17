module reg_id_ex(
    input  wire clk,
    input  wire rst,
    input  wire[31:0] id_pc,
    input  wire[31:0] id_regs_data1,
    input  wire[31:0] id_regs_data2,
    input  wire[31:0] id_imm,
    input  wire[2:0]  id_func3_code, 
    input  wire       id_func7_code,
    input  wire[4:0]  id_rd,
    input  wire       id_br,
    input  wire       id_mem_read,
    input  wire       id_mem2reg,
    input  wire[2:0]  id_alu_op,
    input  wire       id_mem_write,
    input  wire[1:0]  id_alu_src1,
    input  wire[1:0]  id_alu_src2,
    input  wire       id_br_addr_mode,
    input  wire       id_regs_write,

    input  wire       id_ex_flush,

    //forwarding
    input wire[4:0] id_rs1,
    input wire[4:0] id_rs2,

    input wire[1:0] id_matrix_index,
    input wire[31:0] id_inst,
    input wire id_mem2matrix,
    input wire id_matrix_write,
    input wire id_matrix_write_mopa,
    input wire[1:0] id_mem_matrix2reg,
    input wire[31:0] id_matrix_line_data,
    input wire id_mem_reg2matrix,
    input wire id_matrix2mem,
    input wire[31:0] id_M[3:0],

    output reg[4:0] ex_rs1,
    output reg[4:0] ex_rs2,

    output reg[31:0]  ex_pc,
    output reg[31:0]  ex_regs_data1,
    output reg[31:0]  ex_regs_data2,
    output reg[31:0]  ex_imm,
    output reg[2:0]   ex_func3_code, 
    output reg        ex_func7_code,
    output reg[4:0]   ex_rd,
    output reg        ex_br,
    output reg        ex_mem_read,
    output reg        ex_mem2reg,
    output reg[2:0]   ex_alu_op,
    output reg        ex_mem_write,
    output reg[1:0]   ex_alu_src1,
    output reg[1:0]   ex_alu_src2,
    output reg        ex_br_addr_mode,
    output reg        ex_regs_write,

    output reg[1:0]  ex_matrix_index,
    output reg[31:0] ex_inst,
    output reg       ex_mem2matrix,
    output reg       ex_matrix_write,
    output reg       ex_matrix_write_mopa,
    output reg[1:0]  ex_mem_matrix2reg,
    output reg[31:0] ex_matrix_line_data,
    output reg       ex_mem_reg2matrix,
    output reg       ex_matrix2mem,
    output reg[31:0] ex_M[3:0]
);
always @(posedge clk) begin
    if (!rst || id_ex_flush)begin
        ex_pc           <= 0;
        ex_regs_data1   <= 0;
        ex_regs_data2   <= 0;
        ex_imm          <= 0;
        ex_func3_code   <= 0;
        ex_func7_code   <= 0;
        ex_rd           <= 0;
        ex_br           <= 0;
        ex_mem_read     <= 0;
        ex_mem2reg      <= 0;
        ex_alu_op       <= 0;
        ex_mem_write    <= 0;
        ex_alu_src1     <= 0;
        ex_alu_src2     <= 0;
        ex_br_addr_mode <= 0;
        ex_regs_write   <= 0;

        ex_rs1          <= 0;
        ex_rs2          <= 0;

        ex_matrix_index <= 0;
        ex_inst <= 0;
        ex_mem2matrix <= 0;
        ex_matrix_write <= 0;
        ex_matrix_write_mopa <= 0;
        ex_mem_matrix2reg <= 0;
        ex_matrix_line_data <= 0;
        ex_mem_matrix2reg <= 0;
        ex_matrix2mem <= 0;
        ex_M[0] <= 0;
        ex_M[1] <= 0;
        ex_M[2] <= 0;
        ex_M[3] <= 0;
    end 
    else begin
        ex_pc           <= id_pc;
        ex_regs_data1   <= id_regs_data1;
        ex_regs_data2   <= id_regs_data2;
        ex_imm          <= id_imm;
        ex_func3_code   <= id_func3_code;
        ex_func7_code   <= id_func7_code;
        ex_rd           <= id_rd;
        ex_br           <= id_br;
        ex_mem_read     <= id_mem_read;
        ex_mem2reg      <= id_mem2reg;
        ex_alu_op       <= id_alu_op;
        ex_mem_write    <= id_mem_write;
        ex_alu_src1     <= id_alu_src1;
        ex_alu_src2     <= id_alu_src2;
        ex_br_addr_mode <= id_br_addr_mode;
        ex_regs_write   <= id_regs_write;

        ex_rs1          <= id_rs1;
        ex_rs2          <= id_rs2;

        ex_matrix_index <= id_matrix_index;
        ex_inst <= id_inst;
        ex_mem2matrix <= id_mem2matrix;
        ex_matrix_write <= id_matrix_write;
        ex_matrix_write_mopa <= id_matrix_write_mopa;
        ex_mem_matrix2reg <= id_mem_matrix2reg;
        ex_matrix_line_data <= id_matrix_line_data;
        ex_mem_reg2matrix <= id_mem_reg2matrix;
        ex_matrix2mem <= id_matrix2mem;
        ex_M <= id_M;
    end
    $display("ex_regs_data1: %h",ex_regs_data1 );
    $display("ex_regs_data2: %h",ex_regs_data2 );
    $display("ex_imm: %h",ex_imm );
    $display("ex_alu_op: %h",ex_alu_op );
end
endmodule