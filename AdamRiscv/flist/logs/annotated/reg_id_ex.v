	// verilator_coverage annotation
	module reg_id_ex(
 020001	    input  wire clk,
%000001	    input  wire rst,
 019839	    input  wire[31:0] id_pc,
 105680	    input  wire[31:0] id_regs_data1,
 105616	    input  wire[31:0] id_regs_data2,
 000205	    input  wire[31:0] id_imm,
 013201	    input  wire[2:0]  id_func3_code, 
%000005	    input  wire       id_func7_code,
 026385	    input  wire[4:0]  id_rd,
 006594	    input  wire       id_br,
%000000	    input  wire       id_mem_read,
%000001	    input  wire       id_mem2reg,
 013209	    input  wire[2:0]  id_alu_op,
%000000	    input  wire       id_mem_write,
 000029	    input  wire[1:0]  id_alu_src1,
%000012	    input  wire[1:0]  id_alu_src2,
%000001	    input  wire       id_br_addr_mode,
 000011	    input  wire       id_regs_write,
	
 006588	    input  wire       id_ex_flush,
	
	    //forwarding
 013215	    input wire[4:0] id_rs1,
 032972	    input wire[4:0] id_rs2,
	
%000010	    input wire[1:0] id_matrix_index,
 145137	    input wire[31:0] id_inst,
%000001	    input wire id_mem2matrix,
%000001	    input wire id_matrix_write,
%000001	    input wire id_matrix_write_mopa,
%000008	    input wire[1:0] id_mem_matrix2reg,
%000162	    input wire[31:0] id_matrix_line_data,
%000001	    input wire id_mem_reg2matrix,
%000001	    input wire id_matrix2mem,
%000132	    input wire[31:0] id_M[3:0],
	
 000044	    output reg[4:0] ex_rs1,
 000040	    output reg[4:0] ex_rs2,
	
 013234	    output reg[31:0]  ex_pc,
 000317	    output reg[31:0]  ex_regs_data1,
 000248	    output reg[31:0]  ex_regs_data2,
 000222	    output reg[31:0]  ex_imm,
 000029	    output reg[2:0]   ex_func3_code, 
%000004	    output reg        ex_func7_code,
 000041	    output reg[4:0]   ex_rd,
 006594	    output reg        ex_br,
%000000	    output reg        ex_mem_read,
%000000	    output reg        ex_mem2reg,
 019797	    output reg[2:0]   ex_alu_op,
%000001	    output reg        ex_mem_write,
 000030	    output reg[1:0]   ex_alu_src1,
%000013	    output reg[1:0]   ex_alu_src2,
 006589	    output reg        ex_br_addr_mode,
 000011	    output reg        ex_regs_write,
	
%000011	    output reg[1:0]  ex_matrix_index,
 026593	    output reg[31:0] ex_inst,
%000001	    output reg       ex_mem2matrix,
%000001	    output reg       ex_matrix_write,
%000000	    output reg       ex_matrix_write_mopa,
%000011	    output reg[1:0]  ex_mem_matrix2reg,
 105565	    output reg[31:0] ex_matrix_line_data,
%000002	    output reg       ex_mem_reg2matrix,
%000002	    output reg       ex_matrix2mem,
 421774	    output reg[31:0] ex_M[3:0]
	);
	always @(posedge clk) begin
 003394	    if (!rst || id_ex_flush)begin
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
 006606	    else begin
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
