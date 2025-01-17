module reg_ex_mem(
    input  wire clk,
    input  wire rst,
    input  wire[31:0] ex_regs_data1,
    input  wire[31:0] ex_regs_data2,
    input  wire[31:0] ex_alu_o,
    input  wire[31:0] ex_matrix_mul_o[3:0],

    input  wire[4:0]  ex_rd,
    input  wire       ex_mem_read,
    input  wire       ex_mem2reg,
    input  wire       ex_mem_write,
    input  wire       ex_regs_write,
    input  wire[2:0]  ex_func3_code,
    input  wire[1:0]  ex_matrix_index,
    input  wire[31:0] ex_inst,
    input  wire       ex_mem2matrix,
    input  wire       ex_matrix_write,
    input  wire       ex_matrix_write_mopa,
    input  wire[1:0]  ex_mem_matrix2reg,
    input  wire[31:0] ex_matrix_line_data,
    input  wire       ex_mem_reg2matrix,
    input  wire       ex_matrix2mem,

    //forwarding
    input wire[4:0]   ex_rs2,
    output reg[4:0]   me_rs2,

    output reg[31:0]  me_regs_data1,
    output reg[31:0]  me_regs_data2,
    output reg[31:0]  me_alu_o,
    output reg[31:0]  me_matrix_mul_o[3:0],
    output reg[4:0]   me_rd,
    output reg        me_mem_read,
    output reg        me_mem2reg,
    output reg        me_mem_write,
    output reg        me_regs_write,
    output reg[2:0]   me_func3_code,
    output reg[1:0]   me_matrix_index,
    output reg[31:0]  me_inst,
    output reg        me_mem2matrix,
    output reg        me_matrix_write,
    output reg        me_matrix_write_mopa,
    output reg[1:0]   me_mem_matrix2reg,
    output reg[31:0]  me_matrix_line_data,
    output reg        me_mem_reg2matrix,
    output reg        me_matrix2mem
);

always @(posedge clk) begin
    //$display("------------------------- EX : MEM Stage -------------------------");
    if (!rst)begin
        me_regs_data1  <= 0;
        me_regs_data2  <= 0;         
        me_alu_o       <= 0;     
        me_rd          <= 0; 
        me_mem_read    <= 0;     
        me_mem2reg     <= 0;     
        me_mem_write   <= 0;         
        me_regs_write  <= 0;  
        me_rs2         <= 0;   
        me_func3_code  <= 0;
        me_matrix_index<= 0;
        me_inst <= 0; 
        me_mem2matrix <= 0;
        me_matrix_write <= 0;
        me_matrix_write_mopa <= 0;
        me_mem_matrix2reg <= 0;
        me_matrix_line_data <= 0;
        me_mem_reg2matrix <= 0;
        me_matrix2mem <= 0;
        me_matrix_mul_o[0] <= 0;
        me_matrix_mul_o[1] <= 0;
        me_matrix_mul_o[2] <= 0;
        me_matrix_mul_o[3] <= 0;
    end 
    else begin  
        me_regs_data1  <= ex_regs_data1;
        me_regs_data2  <= ex_regs_data2;         
        me_alu_o       <= ex_alu_o;     
        me_rd          <= ex_rd; 
        me_mem_read    <= ex_mem_read;     
        me_mem2reg     <= ex_mem2reg;     
        me_mem_write   <= ex_mem_write;         
        me_regs_write  <= ex_regs_write;
        me_rs2         <= ex_rs2;    
        me_func3_code  <= ex_func3_code;
        me_matrix_index <= ex_matrix_index;
        me_inst         <= ex_inst;
        me_mem2matrix   <= ex_mem2matrix;
        me_matrix_write <= ex_matrix_write;
        me_matrix_write_mopa <= ex_matrix_write_mopa;
        me_mem_matrix2reg <= ex_mem_matrix2reg;
        me_matrix_line_data <= ex_matrix_line_data;
        me_mem_reg2matrix   <= ex_mem_reg2matrix;
        me_matrix2mem <= ex_matrix2mem;
        me_matrix_mul_o[0] <= ex_matrix_mul_o[0];
        me_matrix_mul_o[1] <= ex_matrix_mul_o[1];
        me_matrix_mul_o[2] <= ex_matrix_mul_o[2];
        me_matrix_mul_o[3] <= ex_matrix_mul_o[3];

    end

    $display("me_alu_o: %h",me_alu_o);

end
endmodule