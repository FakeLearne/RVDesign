`include "../define.vh"

module ctrl(   
    input  wire[31:0]   inst,
    input  wire[6:0]    inst_op,
    output wire         br,
    output wire         mem_read,
    output wire         mem2reg,
    output wire[2:0]    alu_op,
    output wire         mem_write,
    output wire[1:0]    alu_src1,
    output wire[1:0]    alu_src2,
    output wire         br_addr_mode,
    output wire         regs_write,

    // matrix
    output wire         mem2matrix,
    output wire         matrix_write,
    output wire         matrix_write_mopa,
    output wire[1:0]    mem_matrix2reg,
    output wire         mem_reg2matrix
);

assign alu_op = (inst_op == `ItypeL || inst_op == `Stype || inst_op == `UtypeL || inst_op == `UtypeU || {inst[14:12], inst_op} == `MtypeL) || {inst[14:12], inst_op} == `MtypeM1 || {inst[14:12], inst_op} == `MtypeM2 || {inst[14:12], inst_op} == `MtypeS ? 3'b000 :
                (inst_op == `Btype)? 3'b001:
                (inst_op == `Rtype)? 3'b010:
                (inst_op == `ItypeA) ? 3'b011:
                (inst_op == `ItypeJ || inst_op == `Jtype)? 3'b100:
                ({inst[14:12], inst_op} == `MtypePA)? 3'b101 : 3'b111;

assign alu_src1 = (inst_op == `ItypeJ || inst_op == `Jtype || inst_op == `UtypeU) ? `PC : 
                  (inst_op == `UtypeL) ? `NULL : ({inst[14:12], inst_op} == `MtypeM1) ? `MATRIX_M1: `REG;
assign alu_src2 = (inst_op == `ItypeL || inst_op == `Stype || inst_op == `UtypeU || inst_op == `ItypeA || inst_op == `UtypeL || {inst[14:12], inst_op} == `MtypeL || {inst[14:12], inst_op} == `MtypeS) ? `IMM :
                  (inst_op == `ItypeJ || inst_op == `Jtype) ? `PC_PLUS4 : ({inst[14:12], inst_op} == `MtypeM1 || {inst[14:12], inst_op} == `MtypeM2) ? `NULL : `REG;
assign br_addr_mode = (inst_op == `ItypeJ)? `J_REG : `B_PC;


assign br = (inst_op == `Btype || inst_op == `ItypeJ || inst_op == `Jtype)? 1:0;
assign mem_write = ( inst_op == `Stype || {inst[14:12], inst_op} == `MtypeS)? 1:0;
assign mem_read = ( inst_op == `ItypeL || {inst[14:12], inst_op} == `MtypeL)? 1:0;
assign regs_write = (inst_op == `ItypeL || inst_op == `Rtype || inst_op == `UtypeU || inst_op == `ItypeA || inst_op == `ItypeJ || inst_op == `UtypeL || inst_op == `Jtype || {inst[14:12], inst_op}==`MtypeM1)? 1:0;

assign matrix_write = ({inst[14:12], inst_op} == `MtypeL || {inst[14:12], inst_op} == `MtypeM2);
assign matrix_write_mopa = {inst[14:12], inst_op} == `MtypePA;

assign mem2reg = (regs_write && (inst_op == `ItypeL)) ? 1 : 0;

assign mem_matrix2reg = (regs_write && (inst_op == `ItypeL)) ? 2'b11 :
                        (regs_write && ({inst[14:12], inst_op} == `MtypeM1)) ? 2'b10: 2'b00;


assign mem_reg2matrix = (matrix_write && inst[14:12] == 3'b000) ? 1'b1 : 1'b0;

assign mem2matrix = (matrix_write && ({inst[14:12], inst_op} == `MtypeL)) ? 1 : 0;


endmodule
