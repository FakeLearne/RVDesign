// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadam_riscv__Syms.h"


//======================

void Vadam_riscv::trace (VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback (&Vadam_riscv::traceInit, &Vadam_riscv::traceFull, &Vadam_riscv::traceChg, this);
}
void Vadam_riscv::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vadam_riscv* t=(Vadam_riscv*)userthis;
    Vadam_riscv__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    vcdp->scopeEscape(' ');
    t->traceInitThis (vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vadam_riscv::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vadam_riscv* t=(Vadam_riscv*)userthis;
    Vadam_riscv__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis (vlSymsp, vcdp, code);
}

//======================


void Vadam_riscv::traceInitThis(Vadam_riscv__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vadam_riscv* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vadam_riscv::traceFullThis(Vadam_riscv__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vadam_riscv* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vadam_riscv::traceInitThis__1(Vadam_riscv__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vadam_riscv* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit  (c+256,"clk",-1);
	vcdp->declBit  (c+257,"rst",-1);
	vcdp->declBit  (c+256,"adam_riscv clk",-1);
	vcdp->declBit  (c+257,"adam_riscv rst",-1);
	vcdp->declBit  (c+1,"adam_riscv br_ctrl",-1);
	vcdp->declBus  (c+2,"adam_riscv br_addr",-1,31,0);
	vcdp->declBit  (c+3,"adam_riscv stall",-1);
	vcdp->declBus  (c+137,"adam_riscv if_pc",-1,31,0);
	vcdp->declBus  (c+4,"adam_riscv if_inst",-1,31,0);
	vcdp->declBit  (c+1,"adam_riscv flush",-1);
	vcdp->declBus  (c+138,"adam_riscv id_inst",-1,31,0);
	vcdp->declBus  (c+139,"adam_riscv id_pc",-1,31,0);
	vcdp->declBit  (c+140,"adam_riscv w_regs_en",-1);
	vcdp->declBus  (c+141,"adam_riscv w_regs_addr",-1,4,0);
	vcdp->declBus  (c+5,"adam_riscv w_regs_data",-1,31,0);
	vcdp->declBus  (c+6,"adam_riscv w_matrix_data",-1,31,0);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+7+i*1,"adam_riscv w_matrix_data_mopa",(i+0),31,0);}}
	vcdp->declBus  (c+11,"adam_riscv id_regs_data1",-1,31,0);
	vcdp->declBus  (c+12,"adam_riscv id_regs_data2",-1,31,0);
	vcdp->declBus  (c+13,"adam_riscv id_imm",-1,31,0);
	vcdp->declBus  (c+14,"adam_riscv id_func3_code",-1,2,0);
	vcdp->declBit  (c+142,"adam_riscv id_func7_code",-1);
	vcdp->declBus  (c+143,"adam_riscv id_rd",-1,4,0);
	vcdp->declBit  (c+15,"adam_riscv id_br",-1);
	vcdp->declBit  (c+16,"adam_riscv id_mem_read",-1);
	vcdp->declBit  (c+17,"adam_riscv id_mem2reg",-1);
	vcdp->declBus  (c+18,"adam_riscv id_alu_op",-1,2,0);
	vcdp->declBit  (c+19,"adam_riscv id_mem_write",-1);
	vcdp->declBus  (c+20,"adam_riscv id_alu_src1",-1,1,0);
	vcdp->declBus  (c+21,"adam_riscv id_alu_src2",-1,1,0);
	vcdp->declBit  (c+22,"adam_riscv id_br_addr_mode",-1);
	vcdp->declBit  (c+23,"adam_riscv id_regs_write",-1);
	vcdp->declBus  (c+144,"adam_riscv id_rs1",-1,4,0);
	vcdp->declBus  (c+145,"adam_riscv id_rs2",-1,4,0);
	vcdp->declBus  (c+24,"adam_riscv id_matrix_index",-1,1,0);
	vcdp->declBit  (c+25,"adam_riscv id_mem2matrix",-1);
	vcdp->declBit  (c+26,"adam_riscv id_matrix_write",-1);
	vcdp->declBit  (c+27,"adam_riscv id_matrix_write_mopa",-1);
	vcdp->declBus  (c+28,"adam_riscv id_mem_matrix2reg",-1,1,0);
	vcdp->declBus  (c+29,"adam_riscv id_matrix_line_data",-1,31,0);
	vcdp->declBit  (c+30,"adam_riscv id_mem_reg2matrix",-1);
	vcdp->declBit  (c+31,"adam_riscv id_matrix2mem",-1);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+32+i*1,"adam_riscv id_M",(i+0),31,0);}}
	vcdp->declBus  (c+146,"adam_riscv ex_rs1",-1,4,0);
	vcdp->declBus  (c+147,"adam_riscv ex_rs2",-1,4,0);
	vcdp->declBus  (c+148,"adam_riscv ex_pc",-1,31,0);
	vcdp->declBus  (c+149,"adam_riscv ex_regs_data1",-1,31,0);
	vcdp->declBus  (c+150,"adam_riscv ex_regs_data2",-1,31,0);
	vcdp->declBus  (c+151,"adam_riscv ex_imm",-1,31,0);
	vcdp->declBus  (c+152,"adam_riscv ex_func3_code",-1,2,0);
	vcdp->declBit  (c+153,"adam_riscv ex_func7_code",-1);
	vcdp->declBus  (c+154,"adam_riscv ex_rd",-1,4,0);
	vcdp->declBit  (c+155,"adam_riscv ex_br",-1);
	vcdp->declBit  (c+156,"adam_riscv ex_mem_read",-1);
	vcdp->declBit  (c+157,"adam_riscv ex_mem2reg",-1);
	vcdp->declBus  (c+158,"adam_riscv ex_alu_op",-1,2,0);
	vcdp->declBit  (c+159,"adam_riscv ex_mem_write",-1);
	vcdp->declBus  (c+160,"adam_riscv ex_alu_src1",-1,1,0);
	vcdp->declBus  (c+161,"adam_riscv ex_alu_src2",-1,1,0);
	vcdp->declBit  (c+162,"adam_riscv ex_br_addr_mode",-1);
	vcdp->declBit  (c+163,"adam_riscv ex_regs_write",-1);
	vcdp->declBus  (c+36,"adam_riscv ex_alu_o",-1,31,0);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+37+i*1,"adam_riscv ex_matrix_mul_o",(i+0),31,0);}}
	vcdp->declBus  (c+164,"adam_riscv ex_matrix_index",-1,1,0);
	vcdp->declBus  (c+165,"adam_riscv ex_inst",-1,31,0);
	vcdp->declBit  (c+166,"adam_riscv ex_mem2matrix",-1);
	vcdp->declBit  (c+167,"adam_riscv ex_matrix_write",-1);
	vcdp->declBit  (c+168,"adam_riscv ex_matrix_write_mopa",-1);
	vcdp->declBus  (c+169,"adam_riscv ex_mem_matrix2reg",-1,1,0);
	vcdp->declBus  (c+170,"adam_riscv ex_matrix_line_data",-1,31,0);
	vcdp->declBit  (c+171,"adam_riscv ex_mem_reg2matrix",-1);
	vcdp->declBit  (c+172,"adam_riscv ex_matrix2mem",-1);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+41+i*1,"adam_riscv ex_M",(i+0),31,0);}}
	vcdp->declBus  (c+45,"adam_riscv forwardA",-1,1,0);
	vcdp->declBus  (c+46,"adam_riscv forwardB",-1,1,0);
	vcdp->declBus  (c+173,"adam_riscv me_rs2",-1,4,0);
	vcdp->declBus  (c+174,"adam_riscv me_regs_data2",-1,31,0);
	vcdp->declBus  (c+175,"adam_riscv me_alu_o",-1,31,0);
	vcdp->declBus  (c+176,"adam_riscv me_rd",-1,4,0);
	vcdp->declBit  (c+177,"adam_riscv me_mem_read",-1);
	vcdp->declBit  (c+178,"adam_riscv me_mem2reg",-1);
	vcdp->declBit  (c+179,"adam_riscv me_mem_write",-1);
	vcdp->declBit  (c+180,"adam_riscv me_regs_write",-1);
	vcdp->declBus  (c+47,"adam_riscv me_mem_data",-1,31,0);
	vcdp->declBus  (c+181,"adam_riscv me_func3_code",-1,2,0);
	vcdp->declBus  (c+182,"adam_riscv me_matrix_index",-1,1,0);
	vcdp->declBus  (c+183,"adam_riscv me_inst",-1,31,0);
	vcdp->declBit  (c+184,"adam_riscv me_mem2matrix",-1);
	vcdp->declBit  (c+185,"adam_riscv me_matrix_write",-1);
	vcdp->declBit  (c+186,"adam_riscv me_matrix_write_mopa",-1);
	vcdp->declBus  (c+187,"adam_riscv me_mem_matrix2reg",-1,1,0);
	vcdp->declBus  (c+188,"adam_riscv me_matrix_line_data",-1,31,0);
	vcdp->declBit  (c+189,"adam_riscv me_mem_reg2matrix",-1);
	vcdp->declBus  (c+190,"adam_riscv me_regs_data1",-1,31,0);
	vcdp->declBit  (c+191,"adam_riscv me_matrix2mem",-1);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+48+i*1,"adam_riscv me_matrix_mul_o",(i+0),31,0);}}
	vcdp->declBit  (c+52,"adam_riscv forward_data",-1);
	vcdp->declBus  (c+192,"adam_riscv wb_mem_data",-1,31,0);
	vcdp->declBus  (c+193,"adam_riscv wb_alu_o",-1,31,0);
	vcdp->declBit  (c+194,"adam_riscv wb_mem2reg",-1);
	vcdp->declBus  (c+195,"adam_riscv wb_matrix_index",-1,1,0);
	vcdp->declBit  (c+196,"adam_riscv wb_mem2matrix",-1);
	vcdp->declBit  (c+197,"adam_riscv wb_matrix_write",-1);
	vcdp->declBit  (c+198,"adam_riscv wb_matrix_write_mopa",-1);
	vcdp->declBus  (c+199,"adam_riscv wb_mem_matrix2reg",-1,1,0);
	vcdp->declBus  (c+200,"adam_riscv wb_matrix_line_data",-1,31,0);
	vcdp->declBit  (c+201,"adam_riscv wb_mem_reg2matrix",-1);
	vcdp->declBus  (c+202,"adam_riscv wb_regs_data1",-1,31,0);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+53+i*1,"adam_riscv wb_matrix_mul_o",(i+0),31,0);}}
	vcdp->declBus  (c+203,"adam_riscv wb_inst",-1,31,0);
	vcdp->declBit  (c+256,"adam_riscv u_stage_if clk",-1);
	vcdp->declBit  (c+257,"adam_riscv u_stage_if rst",-1);
	vcdp->declBit  (c+3,"adam_riscv u_stage_if pc_stall",-1);
	vcdp->declBus  (c+2,"adam_riscv u_stage_if br_addr",-1,31,0);
	vcdp->declBit  (c+1,"adam_riscv u_stage_if br_ctrl",-1);
	vcdp->declBus  (c+4,"adam_riscv u_stage_if if_inst",-1,31,0);
	vcdp->declBus  (c+137,"adam_riscv u_stage_if if_pc",-1,31,0);
	vcdp->declBit  (c+256,"adam_riscv u_stage_if u_pc clk",-1);
	vcdp->declBit  (c+1,"adam_riscv u_stage_if u_pc br_ctrl",-1);
	vcdp->declBus  (c+2,"adam_riscv u_stage_if u_pc br_addr",-1,31,0);
	vcdp->declBit  (c+257,"adam_riscv u_stage_if u_pc rst",-1);
	vcdp->declBus  (c+137,"adam_riscv u_stage_if u_pc pc_o",-1,31,0);
	vcdp->declBit  (c+3,"adam_riscv u_stage_if u_pc pc_stall",-1);
	vcdp->declBus  (c+204,"adam_riscv u_stage_if u_pc pc_next",-1,31,0);
	vcdp->declBus  (c+258,"adam_riscv u_stage_if inst_memory IROM_SPACE",-1,31,0);
	vcdp->declBus  (c+137,"adam_riscv u_stage_if inst_memory inst_addr",-1,31,0);
	vcdp->declBus  (c+4,"adam_riscv u_stage_if inst_memory inst_o",-1,31,0);
	// Tracing: adam_riscv u_stage_if inst_memory inst // Ignored: Wide memory > --trace-max-array ents at ../inst_memory.v:8
	vcdp->declBit  (c+256,"adam_riscv u_reg_if_id clk",-1);
	vcdp->declBit  (c+257,"adam_riscv u_reg_if_id rst",-1);
	vcdp->declBus  (c+137,"adam_riscv u_reg_if_id if_pc",-1,31,0);
	vcdp->declBus  (c+4,"adam_riscv u_reg_if_id if_inst",-1,31,0);
	vcdp->declBus  (c+138,"adam_riscv u_reg_if_id id_inst",-1,31,0);
	vcdp->declBus  (c+139,"adam_riscv u_reg_if_id id_pc",-1,31,0);
	vcdp->declBit  (c+1,"adam_riscv u_reg_if_id if_id_flush",-1);
	vcdp->declBit  (c+3,"adam_riscv u_reg_if_id if_id_stall",-1);
	vcdp->declBit  (c+256,"adam_riscv u_stage_id clk",-1);
	vcdp->declBit  (c+257,"adam_riscv u_stage_id rst",-1);
	vcdp->declBus  (c+138,"adam_riscv u_stage_id id_inst",-1,31,0);
	vcdp->declBit  (c+140,"adam_riscv u_stage_id w_regs_en",-1);
	vcdp->declBus  (c+141,"adam_riscv u_stage_id w_regs_addr",-1,4,0);
	vcdp->declBus  (c+5,"adam_riscv u_stage_id w_regs_data",-1,31,0);
	vcdp->declBit  (c+3,"adam_riscv u_stage_id ctrl_stall",-1);
	vcdp->declBit  (c+197,"adam_riscv u_stage_id w_matrix_en",-1);
	vcdp->declBit  (c+198,"adam_riscv u_stage_id w_matrix_en_mopa",-1);
	vcdp->declBus  (c+195,"adam_riscv u_stage_id w_matrix_index",-1,1,0);
	vcdp->declBus  (c+6,"adam_riscv u_stage_id w_matrix_data",-1,31,0);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+57+i*1,"adam_riscv u_stage_id w_matrix_data_mopa",(i+0),31,0);}}
	vcdp->declBus  (c+11,"adam_riscv u_stage_id id_regs_data1",-1,31,0);
	vcdp->declBus  (c+12,"adam_riscv u_stage_id id_regs_data2",-1,31,0);
	vcdp->declBus  (c+13,"adam_riscv u_stage_id id_imm",-1,31,0);
	vcdp->declBus  (c+14,"adam_riscv u_stage_id id_func3_code",-1,2,0);
	vcdp->declBit  (c+142,"adam_riscv u_stage_id id_func7_code",-1);
	vcdp->declBus  (c+143,"adam_riscv u_stage_id id_rd",-1,4,0);
	vcdp->declBit  (c+15,"adam_riscv u_stage_id id_br",-1);
	vcdp->declBit  (c+16,"adam_riscv u_stage_id id_mem_read",-1);
	vcdp->declBit  (c+17,"adam_riscv u_stage_id id_mem2reg",-1);
	vcdp->declBus  (c+18,"adam_riscv u_stage_id id_alu_op",-1,2,0);
	vcdp->declBit  (c+19,"adam_riscv u_stage_id id_mem_write",-1);
	vcdp->declBus  (c+20,"adam_riscv u_stage_id id_alu_src1",-1,1,0);
	vcdp->declBus  (c+21,"adam_riscv u_stage_id id_alu_src2",-1,1,0);
	vcdp->declBit  (c+22,"adam_riscv u_stage_id id_br_addr_mode",-1);
	vcdp->declBit  (c+23,"adam_riscv u_stage_id id_regs_write",-1);
	vcdp->declBus  (c+144,"adam_riscv u_stage_id id_rs1",-1,4,0);
	vcdp->declBus  (c+145,"adam_riscv u_stage_id id_rs2",-1,4,0);
	vcdp->declBus  (c+24,"adam_riscv u_stage_id id_matrix_index",-1,1,0);
	vcdp->declBit  (c+25,"adam_riscv u_stage_id id_mem2matrix",-1);
	vcdp->declBit  (c+26,"adam_riscv u_stage_id id_matrix_write",-1);
	vcdp->declBit  (c+27,"adam_riscv u_stage_id id_matrix_write_mopa",-1);
	vcdp->declBus  (c+28,"adam_riscv u_stage_id id_mem_matrix2reg",-1,1,0);
	vcdp->declBus  (c+29,"adam_riscv u_stage_id id_matrix_line_data",-1,31,0);
	vcdp->declBit  (c+30,"adam_riscv u_stage_id id_mem_reg2matrix",-1);
	vcdp->declBit  (c+31,"adam_riscv u_stage_id id_matrix2mem",-1);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+61+i*1,"adam_riscv u_stage_id id_M",(i+0),31,0);}}
	vcdp->declBit  (c+65,"adam_riscv u_stage_id br",-1);
	vcdp->declBit  (c+66,"adam_riscv u_stage_id mem_read",-1);
	vcdp->declBit  (c+67,"adam_riscv u_stage_id mem2reg",-1);
	vcdp->declBus  (c+68,"adam_riscv u_stage_id alu_op",-1,2,0);
	vcdp->declBit  (c+69,"adam_riscv u_stage_id mem_write",-1);
	vcdp->declBus  (c+70,"adam_riscv u_stage_id alu_src1",-1,1,0);
	vcdp->declBus  (c+71,"adam_riscv u_stage_id alu_src2",-1,1,0);
	vcdp->declBit  (c+205,"adam_riscv u_stage_id br_addr_mode",-1);
	vcdp->declBit  (c+72,"adam_riscv u_stage_id regs_write",-1);
	vcdp->declBit  (c+256,"adam_riscv u_stage_id u_matrix clk",-1);
	vcdp->declBit  (c+257,"adam_riscv u_stage_id u_matrix rst",-1);
	vcdp->declBus  (c+24,"adam_riscv u_stage_id u_matrix r_matrix_index",-1,1,0);
	vcdp->declBus  (c+195,"adam_riscv u_stage_id u_matrix w_matrix_index",-1,1,0);
	vcdp->declBus  (c+6,"adam_riscv u_stage_id u_matrix w_matrix_data",-1,31,0);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+73+i*1,"adam_riscv u_stage_id u_matrix w_matrix_data_mopa",(i+0),31,0);}}
	vcdp->declBit  (c+197,"adam_riscv u_stage_id u_matrix w_matrix_en",-1);
	vcdp->declBit  (c+198,"adam_riscv u_stage_id u_matrix w_matrix_en_mopa",-1);
	vcdp->declBus  (c+29,"adam_riscv u_stage_id u_matrix r_matrix_o",-1,31,0);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+77+i*1,"adam_riscv u_stage_id u_matrix M_out",(i+0),31,0);}}
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+206+i*1,"adam_riscv u_stage_id u_matrix M",(i+0),31,0);}}
	vcdp->declBit  (c+256,"adam_riscv u_stage_id u_regs clk",-1);
	vcdp->declBit  (c+257,"adam_riscv u_stage_id u_regs rst",-1);
	vcdp->declBus  (c+144,"adam_riscv u_stage_id u_regs r_regs_addr1",-1,4,0);
	vcdp->declBus  (c+145,"adam_riscv u_stage_id u_regs r_regs_addr2",-1,4,0);
	vcdp->declBus  (c+141,"adam_riscv u_stage_id u_regs w_regs_addr",-1,4,0);
	vcdp->declBus  (c+5,"adam_riscv u_stage_id u_regs w_regs_data",-1,31,0);
	vcdp->declBit  (c+140,"adam_riscv u_stage_id u_regs w_regs_en",-1);
	vcdp->declBus  (c+11,"adam_riscv u_stage_id u_regs r_regs_o1",-1,31,0);
	vcdp->declBus  (c+12,"adam_riscv u_stage_id u_regs r_regs_o2",-1,31,0);
	{int i; for (i=0; i<32; i++) {
		vcdp->declBus  (c+210+i*1,"adam_riscv u_stage_id u_regs regs_file",(i+0),31,0);}}
	vcdp->declBit  (c+81,"adam_riscv u_stage_id u_regs wb_hazard_a",-1);
	vcdp->declBit  (c+82,"adam_riscv u_stage_id u_regs wb_hazard_b",-1);
	vcdp->declBus  (c+138,"adam_riscv u_stage_id u_ctrl inst",-1,31,0);
	vcdp->declBus  (c+242,"adam_riscv u_stage_id u_ctrl inst_op",-1,6,0);
	vcdp->declBit  (c+65,"adam_riscv u_stage_id u_ctrl br",-1);
	vcdp->declBit  (c+66,"adam_riscv u_stage_id u_ctrl mem_read",-1);
	vcdp->declBit  (c+67,"adam_riscv u_stage_id u_ctrl mem2reg",-1);
	vcdp->declBus  (c+68,"adam_riscv u_stage_id u_ctrl alu_op",-1,2,0);
	vcdp->declBit  (c+69,"adam_riscv u_stage_id u_ctrl mem_write",-1);
	vcdp->declBus  (c+70,"adam_riscv u_stage_id u_ctrl alu_src1",-1,1,0);
	vcdp->declBus  (c+71,"adam_riscv u_stage_id u_ctrl alu_src2",-1,1,0);
	vcdp->declBit  (c+205,"adam_riscv u_stage_id u_ctrl br_addr_mode",-1);
	vcdp->declBit  (c+72,"adam_riscv u_stage_id u_ctrl regs_write",-1);
	vcdp->declBit  (c+25,"adam_riscv u_stage_id u_ctrl mem2matrix",-1);
	vcdp->declBit  (c+26,"adam_riscv u_stage_id u_ctrl matrix_write",-1);
	vcdp->declBit  (c+27,"adam_riscv u_stage_id u_ctrl matrix_write_mopa",-1);
	vcdp->declBus  (c+28,"adam_riscv u_stage_id u_ctrl mem_matrix2reg",-1,1,0);
	vcdp->declBit  (c+30,"adam_riscv u_stage_id u_ctrl mem_reg2matrix",-1);
	vcdp->declBus  (c+138,"adam_riscv u_stage_id u_imm_gen inst",-1,31,0);
	vcdp->declBus  (c+13,"adam_riscv u_stage_id u_imm_gen imm_o",-1,31,0);
	vcdp->declBit  (c+256,"adam_riscv u_reg_id_ex clk",-1);
	vcdp->declBit  (c+257,"adam_riscv u_reg_id_ex rst",-1);
	vcdp->declBus  (c+139,"adam_riscv u_reg_id_ex id_pc",-1,31,0);
	vcdp->declBus  (c+11,"adam_riscv u_reg_id_ex id_regs_data1",-1,31,0);
	vcdp->declBus  (c+12,"adam_riscv u_reg_id_ex id_regs_data2",-1,31,0);
	vcdp->declBus  (c+13,"adam_riscv u_reg_id_ex id_imm",-1,31,0);
	vcdp->declBus  (c+14,"adam_riscv u_reg_id_ex id_func3_code",-1,2,0);
	vcdp->declBit  (c+142,"adam_riscv u_reg_id_ex id_func7_code",-1);
	vcdp->declBus  (c+143,"adam_riscv u_reg_id_ex id_rd",-1,4,0);
	vcdp->declBit  (c+15,"adam_riscv u_reg_id_ex id_br",-1);
	vcdp->declBit  (c+16,"adam_riscv u_reg_id_ex id_mem_read",-1);
	vcdp->declBit  (c+17,"adam_riscv u_reg_id_ex id_mem2reg",-1);
	vcdp->declBus  (c+18,"adam_riscv u_reg_id_ex id_alu_op",-1,2,0);
	vcdp->declBit  (c+19,"adam_riscv u_reg_id_ex id_mem_write",-1);
	vcdp->declBus  (c+20,"adam_riscv u_reg_id_ex id_alu_src1",-1,1,0);
	vcdp->declBus  (c+21,"adam_riscv u_reg_id_ex id_alu_src2",-1,1,0);
	vcdp->declBit  (c+22,"adam_riscv u_reg_id_ex id_br_addr_mode",-1);
	vcdp->declBit  (c+23,"adam_riscv u_reg_id_ex id_regs_write",-1);
	vcdp->declBit  (c+1,"adam_riscv u_reg_id_ex id_ex_flush",-1);
	vcdp->declBus  (c+144,"adam_riscv u_reg_id_ex id_rs1",-1,4,0);
	vcdp->declBus  (c+145,"adam_riscv u_reg_id_ex id_rs2",-1,4,0);
	vcdp->declBus  (c+24,"adam_riscv u_reg_id_ex id_matrix_index",-1,1,0);
	vcdp->declBus  (c+138,"adam_riscv u_reg_id_ex id_inst",-1,31,0);
	vcdp->declBit  (c+25,"adam_riscv u_reg_id_ex id_mem2matrix",-1);
	vcdp->declBit  (c+26,"adam_riscv u_reg_id_ex id_matrix_write",-1);
	vcdp->declBit  (c+27,"adam_riscv u_reg_id_ex id_matrix_write_mopa",-1);
	vcdp->declBus  (c+28,"adam_riscv u_reg_id_ex id_mem_matrix2reg",-1,1,0);
	vcdp->declBus  (c+29,"adam_riscv u_reg_id_ex id_matrix_line_data",-1,31,0);
	vcdp->declBit  (c+30,"adam_riscv u_reg_id_ex id_mem_reg2matrix",-1);
	vcdp->declBit  (c+31,"adam_riscv u_reg_id_ex id_matrix2mem",-1);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+83+i*1,"adam_riscv u_reg_id_ex id_M",(i+0),31,0);}}
	vcdp->declBus  (c+146,"adam_riscv u_reg_id_ex ex_rs1",-1,4,0);
	vcdp->declBus  (c+147,"adam_riscv u_reg_id_ex ex_rs2",-1,4,0);
	vcdp->declBus  (c+148,"adam_riscv u_reg_id_ex ex_pc",-1,31,0);
	vcdp->declBus  (c+149,"adam_riscv u_reg_id_ex ex_regs_data1",-1,31,0);
	vcdp->declBus  (c+150,"adam_riscv u_reg_id_ex ex_regs_data2",-1,31,0);
	vcdp->declBus  (c+151,"adam_riscv u_reg_id_ex ex_imm",-1,31,0);
	vcdp->declBus  (c+152,"adam_riscv u_reg_id_ex ex_func3_code",-1,2,0);
	vcdp->declBit  (c+153,"adam_riscv u_reg_id_ex ex_func7_code",-1);
	vcdp->declBus  (c+154,"adam_riscv u_reg_id_ex ex_rd",-1,4,0);
	vcdp->declBit  (c+155,"adam_riscv u_reg_id_ex ex_br",-1);
	vcdp->declBit  (c+156,"adam_riscv u_reg_id_ex ex_mem_read",-1);
	vcdp->declBit  (c+157,"adam_riscv u_reg_id_ex ex_mem2reg",-1);
	vcdp->declBus  (c+158,"adam_riscv u_reg_id_ex ex_alu_op",-1,2,0);
	vcdp->declBit  (c+159,"adam_riscv u_reg_id_ex ex_mem_write",-1);
	vcdp->declBus  (c+160,"adam_riscv u_reg_id_ex ex_alu_src1",-1,1,0);
	vcdp->declBus  (c+161,"adam_riscv u_reg_id_ex ex_alu_src2",-1,1,0);
	vcdp->declBit  (c+162,"adam_riscv u_reg_id_ex ex_br_addr_mode",-1);
	vcdp->declBit  (c+163,"adam_riscv u_reg_id_ex ex_regs_write",-1);
	vcdp->declBus  (c+164,"adam_riscv u_reg_id_ex ex_matrix_index",-1,1,0);
	vcdp->declBus  (c+165,"adam_riscv u_reg_id_ex ex_inst",-1,31,0);
	vcdp->declBit  (c+166,"adam_riscv u_reg_id_ex ex_mem2matrix",-1);
	vcdp->declBit  (c+167,"adam_riscv u_reg_id_ex ex_matrix_write",-1);
	vcdp->declBit  (c+168,"adam_riscv u_reg_id_ex ex_matrix_write_mopa",-1);
	vcdp->declBus  (c+169,"adam_riscv u_reg_id_ex ex_mem_matrix2reg",-1,1,0);
	vcdp->declBus  (c+170,"adam_riscv u_reg_id_ex ex_matrix_line_data",-1,31,0);
	vcdp->declBit  (c+171,"adam_riscv u_reg_id_ex ex_mem_reg2matrix",-1);
	vcdp->declBit  (c+172,"adam_riscv u_reg_id_ex ex_matrix2mem",-1);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+243+i*1,"adam_riscv u_reg_id_ex ex_M",(i+0),31,0);}}
	vcdp->declBus  (c+148,"adam_riscv u_stage_ex ex_pc",-1,31,0);
	vcdp->declBus  (c+149,"adam_riscv u_stage_ex ex_regs_data1",-1,31,0);
	vcdp->declBus  (c+150,"adam_riscv u_stage_ex ex_regs_data2",-1,31,0);
	vcdp->declBus  (c+151,"adam_riscv u_stage_ex ex_imm",-1,31,0);
	vcdp->declBus  (c+152,"adam_riscv u_stage_ex ex_func3_code",-1,2,0);
	vcdp->declBit  (c+153,"adam_riscv u_stage_ex ex_func7_code",-1);
	vcdp->declBus  (c+158,"adam_riscv u_stage_ex ex_alu_op",-1,2,0);
	vcdp->declBus  (c+160,"adam_riscv u_stage_ex ex_alu_src1",-1,1,0);
	vcdp->declBus  (c+161,"adam_riscv u_stage_ex ex_alu_src2",-1,1,0);
	vcdp->declBit  (c+162,"adam_riscv u_stage_ex ex_br_addr_mode",-1);
	vcdp->declBit  (c+155,"adam_riscv u_stage_ex ex_br",-1);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+87+i*1,"adam_riscv u_stage_ex ex_M",(i+0),31,0);}}
	vcdp->declBus  (c+45,"adam_riscv u_stage_ex forwardA",-1,1,0);
	vcdp->declBus  (c+46,"adam_riscv u_stage_ex forwardB",-1,1,0);
	vcdp->declBus  (c+175,"adam_riscv u_stage_ex me_alu_o",-1,31,0);
	vcdp->declBus  (c+5,"adam_riscv u_stage_ex w_regs_data",-1,31,0);
	vcdp->declBus  (c+170,"adam_riscv u_stage_ex ex_matrix_line_data",-1,31,0);
	vcdp->declBus  (c+188,"adam_riscv u_stage_ex me_matrix_line_data",-1,31,0);
	vcdp->declBus  (c+36,"adam_riscv u_stage_ex ex_alu_o",-1,31,0);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+91+i*1,"adam_riscv u_stage_ex ex_matrix_mul_o",(i+0),31,0);}}
	vcdp->declBus  (c+2,"adam_riscv u_stage_ex br_pc",-1,31,0);
	vcdp->declBit  (c+1,"adam_riscv u_stage_ex br_ctrl",-1);
	vcdp->declBus  (c+95,"adam_riscv u_stage_ex alu_ctrl",-1,3,0);
	vcdp->declBus  (c+96,"adam_riscv u_stage_ex op_A",-1,31,0);
	vcdp->declBus  (c+97,"adam_riscv u_stage_ex op_A_pre",-1,31,0);
	vcdp->declBus  (c+98,"adam_riscv u_stage_ex op_B",-1,31,0);
	vcdp->declBus  (c+99,"adam_riscv u_stage_ex op_B_pre",-1,31,0);
	vcdp->declBit  (c+100,"adam_riscv u_stage_ex br_mark",-1);
	vcdp->declBus  (c+101,"adam_riscv u_stage_ex br_addr_op_A",-1,31,0);
	vcdp->declBus  (c+158,"adam_riscv u_stage_ex u_alu_control alu_op",-1,2,0);
	vcdp->declBus  (c+152,"adam_riscv u_stage_ex u_alu_control func3_code",-1,2,0);
	vcdp->declBit  (c+153,"adam_riscv u_stage_ex u_alu_control func7_code",-1);
	vcdp->declBus  (c+95,"adam_riscv u_stage_ex u_alu_control alu_ctrl_r",-1,3,0);
	vcdp->declBus  (c+95,"adam_riscv u_stage_ex u_alu alu_ctrl",-1,3,0);
	vcdp->declBus  (c+96,"adam_riscv u_stage_ex u_alu op_A",-1,31,0);
	vcdp->declBus  (c+98,"adam_riscv u_stage_ex u_alu op_B",-1,31,0);
	vcdp->declBus  (c+36,"adam_riscv u_stage_ex u_alu alu_o",-1,31,0);
	vcdp->declBit  (c+100,"adam_riscv u_stage_ex u_alu br_mark",-1);
	vcdp->declBus  (c+95,"adam_riscv u_stage_ex u_matrix_mul mul_ctrl",-1,3,0);
	vcdp->declBus  (c+96,"adam_riscv u_stage_ex u_matrix_mul op_A",-1,31,0);
	vcdp->declBus  (c+98,"adam_riscv u_stage_ex u_matrix_mul op_B",-1,31,0);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+102+i*1,"adam_riscv u_stage_ex u_matrix_mul M",(i+0),31,0);}}
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+106+i*1,"adam_riscv u_stage_ex u_matrix_mul matrix_mul_o",(i+0),31,0);}}
	vcdp->declBus  (c+110,"adam_riscv u_stage_ex u_matrix_mul matrix_line_0",-1,31,0);
	vcdp->declBus  (c+111,"adam_riscv u_stage_ex u_matrix_mul matrix_line_1",-1,31,0);
	vcdp->declBus  (c+112,"adam_riscv u_stage_ex u_matrix_mul matrix_line_2",-1,31,0);
	vcdp->declBus  (c+113,"adam_riscv u_stage_ex u_matrix_mul matrix_line_3",-1,31,0);
	vcdp->declBit  (c+256,"adam_riscv u_reg_ex_mem clk",-1);
	vcdp->declBit  (c+257,"adam_riscv u_reg_ex_mem rst",-1);
	vcdp->declBus  (c+149,"adam_riscv u_reg_ex_mem ex_regs_data1",-1,31,0);
	vcdp->declBus  (c+150,"adam_riscv u_reg_ex_mem ex_regs_data2",-1,31,0);
	vcdp->declBus  (c+36,"adam_riscv u_reg_ex_mem ex_alu_o",-1,31,0);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+114+i*1,"adam_riscv u_reg_ex_mem ex_matrix_mul_o",(i+0),31,0);}}
	vcdp->declBus  (c+154,"adam_riscv u_reg_ex_mem ex_rd",-1,4,0);
	vcdp->declBit  (c+156,"adam_riscv u_reg_ex_mem ex_mem_read",-1);
	vcdp->declBit  (c+157,"adam_riscv u_reg_ex_mem ex_mem2reg",-1);
	vcdp->declBit  (c+159,"adam_riscv u_reg_ex_mem ex_mem_write",-1);
	vcdp->declBit  (c+163,"adam_riscv u_reg_ex_mem ex_regs_write",-1);
	vcdp->declBus  (c+152,"adam_riscv u_reg_ex_mem ex_func3_code",-1,2,0);
	vcdp->declBus  (c+164,"adam_riscv u_reg_ex_mem ex_matrix_index",-1,1,0);
	vcdp->declBus  (c+165,"adam_riscv u_reg_ex_mem ex_inst",-1,31,0);
	vcdp->declBit  (c+166,"adam_riscv u_reg_ex_mem ex_mem2matrix",-1);
	vcdp->declBit  (c+167,"adam_riscv u_reg_ex_mem ex_matrix_write",-1);
	vcdp->declBit  (c+168,"adam_riscv u_reg_ex_mem ex_matrix_write_mopa",-1);
	vcdp->declBus  (c+169,"adam_riscv u_reg_ex_mem ex_mem_matrix2reg",-1,1,0);
	vcdp->declBus  (c+170,"adam_riscv u_reg_ex_mem ex_matrix_line_data",-1,31,0);
	vcdp->declBit  (c+171,"adam_riscv u_reg_ex_mem ex_mem_reg2matrix",-1);
	vcdp->declBit  (c+172,"adam_riscv u_reg_ex_mem ex_matrix2mem",-1);
	vcdp->declBus  (c+147,"adam_riscv u_reg_ex_mem ex_rs2",-1,4,0);
	vcdp->declBus  (c+173,"adam_riscv u_reg_ex_mem me_rs2",-1,4,0);
	vcdp->declBus  (c+190,"adam_riscv u_reg_ex_mem me_regs_data1",-1,31,0);
	vcdp->declBus  (c+174,"adam_riscv u_reg_ex_mem me_regs_data2",-1,31,0);
	vcdp->declBus  (c+175,"adam_riscv u_reg_ex_mem me_alu_o",-1,31,0);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+247+i*1,"adam_riscv u_reg_ex_mem me_matrix_mul_o",(i+0),31,0);}}
	vcdp->declBus  (c+176,"adam_riscv u_reg_ex_mem me_rd",-1,4,0);
	vcdp->declBit  (c+177,"adam_riscv u_reg_ex_mem me_mem_read",-1);
	vcdp->declBit  (c+178,"adam_riscv u_reg_ex_mem me_mem2reg",-1);
	vcdp->declBit  (c+179,"adam_riscv u_reg_ex_mem me_mem_write",-1);
	vcdp->declBit  (c+180,"adam_riscv u_reg_ex_mem me_regs_write",-1);
	vcdp->declBus  (c+181,"adam_riscv u_reg_ex_mem me_func3_code",-1,2,0);
	vcdp->declBus  (c+182,"adam_riscv u_reg_ex_mem me_matrix_index",-1,1,0);
	vcdp->declBus  (c+183,"adam_riscv u_reg_ex_mem me_inst",-1,31,0);
	vcdp->declBit  (c+184,"adam_riscv u_reg_ex_mem me_mem2matrix",-1);
	vcdp->declBit  (c+185,"adam_riscv u_reg_ex_mem me_matrix_write",-1);
	vcdp->declBit  (c+186,"adam_riscv u_reg_ex_mem me_matrix_write_mopa",-1);
	vcdp->declBus  (c+187,"adam_riscv u_reg_ex_mem me_mem_matrix2reg",-1,1,0);
	vcdp->declBus  (c+188,"adam_riscv u_reg_ex_mem me_matrix_line_data",-1,31,0);
	vcdp->declBit  (c+189,"adam_riscv u_reg_ex_mem me_mem_reg2matrix",-1);
	vcdp->declBit  (c+191,"adam_riscv u_reg_ex_mem me_matrix2mem",-1);
	vcdp->declBit  (c+256,"adam_riscv u_stage_mem clk",-1);
	vcdp->declBit  (c+257,"adam_riscv u_stage_mem rst",-1);
	vcdp->declBus  (c+174,"adam_riscv u_stage_mem me_regs_data2",-1,31,0);
	vcdp->declBus  (c+175,"adam_riscv u_stage_mem me_alu_o",-1,31,0);
	vcdp->declBit  (c+177,"adam_riscv u_stage_mem me_mem_read",-1);
	vcdp->declBit  (c+179,"adam_riscv u_stage_mem me_mem_write",-1);
	vcdp->declBus  (c+181,"adam_riscv u_stage_mem me_func3_code",-1,2,0);
	vcdp->declBit  (c+52,"adam_riscv u_stage_mem forward_data",-1);
	vcdp->declBus  (c+5,"adam_riscv u_stage_mem w_regs_data",-1,31,0);
	vcdp->declBus  (c+183,"adam_riscv u_stage_mem me_inst",-1,31,0);
	vcdp->declBus  (c+188,"adam_riscv u_stage_mem me_matrix_line_data",-1,31,0);
	vcdp->declBit  (c+191,"adam_riscv u_stage_mem me_matrix2mem",-1);
	vcdp->declBus  (c+47,"adam_riscv u_stage_mem me_mem_data",-1,31,0);
	vcdp->declBus  (c+118,"adam_riscv u_stage_mem w_data_mem",-1,31,0);
	vcdp->declBus  (c+119,"adam_riscv u_stage_mem r_data_mem",-1,31,0);
	vcdp->declBus  (c+258,"adam_riscv u_stage_mem u_data_memory DROM_SPACE",-1,31,0);
	vcdp->declBit  (c+256,"adam_riscv u_stage_mem u_data_memory clk",-1);
	vcdp->declBit  (c+257,"adam_riscv u_stage_mem u_data_memory rst",-1);
	vcdp->declBus  (c+175,"adam_riscv u_stage_mem u_data_memory data_addr",-1,31,0);
	vcdp->declBus  (c+118,"adam_riscv u_stage_mem u_data_memory w_data_mem",-1,31,0);
	vcdp->declBit  (c+177,"adam_riscv u_stage_mem u_data_memory r_en_mem",-1);
	vcdp->declBit  (c+179,"adam_riscv u_stage_mem u_data_memory w_en_mem",-1);
	vcdp->declBus  (c+251,"adam_riscv u_stage_mem u_data_memory byte_sel",-1,1,0);
	vcdp->declBus  (c+119,"adam_riscv u_stage_mem u_data_memory r_data_mem",-1,31,0);
	// Tracing: adam_riscv u_stage_mem u_data_memory data // Ignored: Wide memory > --trace-max-array ents at ../data_memory.v:14
	vcdp->declBit  (c+256,"adam_riscv u_reg_mem_wb clk",-1);
	vcdp->declBit  (c+257,"adam_riscv u_reg_mem_wb rst",-1);
	vcdp->declBus  (c+47,"adam_riscv u_reg_mem_wb me_mem_data",-1,31,0);
	vcdp->declBus  (c+175,"adam_riscv u_reg_mem_wb me_alu_o",-1,31,0);
	vcdp->declBus  (c+176,"adam_riscv u_reg_mem_wb me_rd",-1,4,0);
	vcdp->declBit  (c+178,"adam_riscv u_reg_mem_wb me_mem2reg",-1);
	vcdp->declBit  (c+180,"adam_riscv u_reg_mem_wb me_regs_write",-1);
	vcdp->declBus  (c+182,"adam_riscv u_reg_mem_wb me_matrix_index",-1,1,0);
	vcdp->declBit  (c+184,"adam_riscv u_reg_mem_wb me_mem2matrix",-1);
	vcdp->declBit  (c+185,"adam_riscv u_reg_mem_wb me_matrix_write",-1);
	vcdp->declBit  (c+186,"adam_riscv u_reg_mem_wb me_matrix_write_mopa",-1);
	vcdp->declBus  (c+187,"adam_riscv u_reg_mem_wb me_mem_matrix2reg",-1,1,0);
	vcdp->declBus  (c+188,"adam_riscv u_reg_mem_wb me_matrix_line_data",-1,31,0);
	vcdp->declBit  (c+189,"adam_riscv u_reg_mem_wb me_mem_reg2matrix",-1);
	vcdp->declBus  (c+190,"adam_riscv u_reg_mem_wb me_regs_data1",-1,31,0);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+120+i*1,"adam_riscv u_reg_mem_wb me_matrix_mul_o",(i+0),31,0);}}
	vcdp->declBus  (c+183,"adam_riscv u_reg_mem_wb me_inst",-1,31,0);
	vcdp->declBus  (c+192,"adam_riscv u_reg_mem_wb wb_mem_data",-1,31,0);
	vcdp->declBus  (c+193,"adam_riscv u_reg_mem_wb wb_alu_o",-1,31,0);
	vcdp->declBus  (c+141,"adam_riscv u_reg_mem_wb wb_rd",-1,4,0);
	vcdp->declBit  (c+194,"adam_riscv u_reg_mem_wb wb_mem2reg",-1);
	vcdp->declBit  (c+140,"adam_riscv u_reg_mem_wb wb_regs_write",-1);
	vcdp->declBus  (c+195,"adam_riscv u_reg_mem_wb wb_matrix_index",-1,1,0);
	vcdp->declBit  (c+196,"adam_riscv u_reg_mem_wb wb_mem2matrix",-1);
	vcdp->declBit  (c+197,"adam_riscv u_reg_mem_wb wb_matrix_write",-1);
	vcdp->declBit  (c+198,"adam_riscv u_reg_mem_wb wb_matrix_write_mopa",-1);
	vcdp->declBus  (c+199,"adam_riscv u_reg_mem_wb wb_mem_matrix2reg",-1,1,0);
	vcdp->declBus  (c+200,"adam_riscv u_reg_mem_wb wb_matrix_line_data",-1,31,0);
	vcdp->declBit  (c+201,"adam_riscv u_reg_mem_wb wb_mem_reg2matrix",-1);
	vcdp->declBus  (c+202,"adam_riscv u_reg_mem_wb wb_regs_data1",-1,31,0);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+252+i*1,"adam_riscv u_reg_mem_wb wb_matrix_mul_o",(i+0),31,0);}}
	vcdp->declBus  (c+203,"adam_riscv u_reg_mem_wb wb_inst",-1,31,0);
	vcdp->declBus  (c+192,"adam_riscv u_stage_wb wb_mem_data",-1,31,0);
	vcdp->declBus  (c+193,"adam_riscv u_stage_wb wb_alu_o",-1,31,0);
	vcdp->declBit  (c+194,"adam_riscv u_stage_wb wb_mem2reg",-1);
	vcdp->declBus  (c+195,"adam_riscv u_stage_wb wb_matrix_index",-1,1,0);
	vcdp->declBus  (c+199,"adam_riscv u_stage_wb wb_mem_matrix2reg",-1,1,0);
	vcdp->declBus  (c+200,"adam_riscv u_stage_wb wb_matrix_line_data",-1,31,0);
	vcdp->declBit  (c+201,"adam_riscv u_stage_wb wb_mem_reg2matrix",-1);
	vcdp->declBus  (c+202,"adam_riscv u_stage_wb wb_regs_data1",-1,31,0);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+124+i*1,"adam_riscv u_stage_wb wb_matrix_mul_o",(i+0),31,0);}}
	vcdp->declBus  (c+5,"adam_riscv u_stage_wb w_regs_data",-1,31,0);
	vcdp->declBus  (c+6,"adam_riscv u_stage_wb w_matrix_data",-1,31,0);
	{int i; for (i=0; i<4; i++) {
		vcdp->declBus  (c+128+i*1,"adam_riscv u_stage_wb w_matrix_data_mopa",(i+0),31,0);}}
	vcdp->declBus  (c+146,"adam_riscv u_forwarding ex_rs1",-1,4,0);
	vcdp->declBus  (c+147,"adam_riscv u_forwarding ex_rs2",-1,4,0);
	vcdp->declBus  (c+176,"adam_riscv u_forwarding me_rd",-1,4,0);
	vcdp->declBus  (c+141,"adam_riscv u_forwarding wb_rd",-1,4,0);
	vcdp->declBus  (c+173,"adam_riscv u_forwarding me_rs2",-1,4,0);
	vcdp->declBit  (c+179,"adam_riscv u_forwarding me_mem_write",-1);
	vcdp->declBit  (c+180,"adam_riscv u_forwarding me_regs_write",-1);
	vcdp->declBit  (c+140,"adam_riscv u_forwarding wb_regs_write",-1);
	vcdp->declBus  (c+45,"adam_riscv u_forwarding forwardA",-1,1,0);
	vcdp->declBus  (c+46,"adam_riscv u_forwarding forwardB",-1,1,0);
	vcdp->declBit  (c+52,"adam_riscv u_forwarding forward_data",-1);
	vcdp->declBit  (c+132,"adam_riscv u_forwarding ex_hazard_a",-1);
	vcdp->declBit  (c+133,"adam_riscv u_forwarding ex_hazard_b",-1);
	vcdp->declBit  (c+134,"adam_riscv u_forwarding mem_hazard_a",-1);
	vcdp->declBit  (c+135,"adam_riscv u_forwarding mem_hazard_b",-1);
	vcdp->declBit  (c+136,"adam_riscv u_forwarding hazard_data_w",-1);
	vcdp->declBit  (c+156,"adam_riscv u_hazard_detection ex_mem_read",-1);
	vcdp->declBus  (c+144,"adam_riscv u_hazard_detection id_rs1",-1,4,0);
	vcdp->declBus  (c+145,"adam_riscv u_hazard_detection id_rs2",-1,4,0);
	vcdp->declBus  (c+154,"adam_riscv u_hazard_detection ex_rd",-1,4,0);
	vcdp->declBit  (c+1,"adam_riscv u_hazard_detection br_ctrl",-1);
	vcdp->declBus  (c+4,"adam_riscv u_hazard_detection if_inst",-1,31,0);
	vcdp->declBus  (c+165,"adam_riscv u_hazard_detection ex_inst",-1,31,0);
	vcdp->declBus  (c+183,"adam_riscv u_hazard_detection me_inst",-1,31,0);
	vcdp->declBus  (c+203,"adam_riscv u_hazard_detection wb_inst",-1,31,0);
	vcdp->declBit  (c+3,"adam_riscv u_hazard_detection load_stall",-1);
	vcdp->declBit  (c+1,"adam_riscv u_hazard_detection flush",-1);
    }
}

void Vadam_riscv::traceFullThis__1(Vadam_riscv__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vadam_riscv* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBit  (c+1,(vlTOPp->adam_riscv__DOT__br_ctrl));
	vcdp->fullBus  (c+2,(vlTOPp->adam_riscv__DOT__br_addr),32);
	vcdp->fullBit  (c+3,(vlTOPp->adam_riscv__DOT__stall));
	vcdp->fullBus  (c+4,(vlTOPp->adam_riscv__DOT__if_inst),32);
	vcdp->fullBus  (c+5,(vlTOPp->adam_riscv__DOT__w_regs_data),32);
	vcdp->fullBus  (c+6,(vlTOPp->adam_riscv__DOT__w_matrix_data),32);
	vcdp->fullBus  (c+7,(vlTOPp->adam_riscv__DOT__w_matrix_data_mopa[0]),32);
	vcdp->fullBus  (c+8,(vlTOPp->adam_riscv__DOT__w_matrix_data_mopa[1]),32);
	vcdp->fullBus  (c+9,(vlTOPp->adam_riscv__DOT__w_matrix_data_mopa[2]),32);
	vcdp->fullBus  (c+10,(vlTOPp->adam_riscv__DOT__w_matrix_data_mopa[3]),32);
	vcdp->fullBus  (c+11,(vlTOPp->adam_riscv__DOT__id_regs_data1),32);
	vcdp->fullBus  (c+12,(vlTOPp->adam_riscv__DOT__id_regs_data2),32);
	vcdp->fullBus  (c+13,(vlTOPp->adam_riscv__DOT__id_imm),32);
	vcdp->fullBus  (c+14,(vlTOPp->adam_riscv__DOT__id_func3_code),3);
	vcdp->fullBit  (c+15,(vlTOPp->adam_riscv__DOT__id_br));
	vcdp->fullBit  (c+16,(vlTOPp->adam_riscv__DOT__id_mem_read));
	vcdp->fullBit  (c+17,(vlTOPp->adam_riscv__DOT__id_mem2reg));
	vcdp->fullBus  (c+18,(vlTOPp->adam_riscv__DOT__id_alu_op),3);
	vcdp->fullBit  (c+19,(vlTOPp->adam_riscv__DOT__id_mem_write));
	vcdp->fullBus  (c+20,(vlTOPp->adam_riscv__DOT__id_alu_src1),2);
	vcdp->fullBus  (c+21,(vlTOPp->adam_riscv__DOT__id_alu_src2),2);
	vcdp->fullBit  (c+22,(vlTOPp->adam_riscv__DOT__id_br_addr_mode));
	vcdp->fullBit  (c+23,(vlTOPp->adam_riscv__DOT__id_regs_write));
	vcdp->fullBus  (c+24,(vlTOPp->adam_riscv__DOT__id_matrix_index),2);
	vcdp->fullBit  (c+25,(vlTOPp->adam_riscv__DOT__id_mem2matrix));
	vcdp->fullBit  (c+26,(vlTOPp->adam_riscv__DOT__id_matrix_write));
	vcdp->fullBit  (c+27,(vlTOPp->adam_riscv__DOT__id_matrix_write_mopa));
	vcdp->fullBus  (c+28,(vlTOPp->adam_riscv__DOT__id_mem_matrix2reg),2);
	vcdp->fullBus  (c+29,(vlTOPp->adam_riscv__DOT__id_matrix_line_data),32);
	vcdp->fullBit  (c+30,(vlTOPp->adam_riscv__DOT__id_mem_reg2matrix));
	vcdp->fullBit  (c+31,(vlTOPp->adam_riscv__DOT__id_matrix2mem));
	vcdp->fullBus  (c+32,(vlTOPp->adam_riscv__DOT__id_M[0]),32);
	vcdp->fullBus  (c+33,(vlTOPp->adam_riscv__DOT__id_M[1]),32);
	vcdp->fullBus  (c+34,(vlTOPp->adam_riscv__DOT__id_M[2]),32);
	vcdp->fullBus  (c+35,(vlTOPp->adam_riscv__DOT__id_M[3]),32);
	vcdp->fullBus  (c+36,(vlTOPp->adam_riscv__DOT__ex_alu_o),32);
	vcdp->fullBus  (c+37,(vlTOPp->adam_riscv__DOT__ex_matrix_mul_o[0]),32);
	vcdp->fullBus  (c+38,(vlTOPp->adam_riscv__DOT__ex_matrix_mul_o[1]),32);
	vcdp->fullBus  (c+39,(vlTOPp->adam_riscv__DOT__ex_matrix_mul_o[2]),32);
	vcdp->fullBus  (c+40,(vlTOPp->adam_riscv__DOT__ex_matrix_mul_o[3]),32);
	vcdp->fullBus  (c+41,(vlTOPp->adam_riscv__DOT__ex_M[0]),32);
	vcdp->fullBus  (c+42,(vlTOPp->adam_riscv__DOT__ex_M[1]),32);
	vcdp->fullBus  (c+43,(vlTOPp->adam_riscv__DOT__ex_M[2]),32);
	vcdp->fullBus  (c+44,(vlTOPp->adam_riscv__DOT__ex_M[3]),32);
	vcdp->fullBus  (c+45,(vlTOPp->adam_riscv__DOT__forwardA),2);
	vcdp->fullBus  (c+46,(vlTOPp->adam_riscv__DOT__forwardB),2);
	vcdp->fullBus  (c+47,(vlTOPp->adam_riscv__DOT__me_mem_data),32);
	vcdp->fullBus  (c+48,(vlTOPp->adam_riscv__DOT__me_matrix_mul_o[0]),32);
	vcdp->fullBus  (c+49,(vlTOPp->adam_riscv__DOT__me_matrix_mul_o[1]),32);
	vcdp->fullBus  (c+50,(vlTOPp->adam_riscv__DOT__me_matrix_mul_o[2]),32);
	vcdp->fullBus  (c+51,(vlTOPp->adam_riscv__DOT__me_matrix_mul_o[3]),32);
	vcdp->fullBit  (c+52,((1U & ((IData)(vlTOPp->adam_riscv__DOT__u_forwarding__DOT__hazard_data_w)
				      ? 1U : 0U))));
	vcdp->fullBus  (c+53,(vlTOPp->adam_riscv__DOT__wb_matrix_mul_o[0]),32);
	vcdp->fullBus  (c+54,(vlTOPp->adam_riscv__DOT__wb_matrix_mul_o[1]),32);
	vcdp->fullBus  (c+55,(vlTOPp->adam_riscv__DOT__wb_matrix_mul_o[2]),32);
	vcdp->fullBus  (c+56,(vlTOPp->adam_riscv__DOT__wb_matrix_mul_o[3]),32);
	vcdp->fullBus  (c+57,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_id__w_matrix_data_mopa[0]),32);
	vcdp->fullBus  (c+58,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_id__w_matrix_data_mopa[1]),32);
	vcdp->fullBus  (c+59,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_id__w_matrix_data_mopa[2]),32);
	vcdp->fullBus  (c+60,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_id__w_matrix_data_mopa[3]),32);
	vcdp->fullBus  (c+61,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_id__id_M[0]),32);
	vcdp->fullBus  (c+62,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_id__id_M[1]),32);
	vcdp->fullBus  (c+63,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_id__id_M[2]),32);
	vcdp->fullBus  (c+64,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_id__id_M[3]),32);
	vcdp->fullBit  (c+65,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__br));
	vcdp->fullBit  (c+66,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__mem_read));
	vcdp->fullBit  (c+67,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__mem2reg));
	vcdp->fullBus  (c+68,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__alu_op),3);
	vcdp->fullBit  (c+69,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__mem_write));
	vcdp->fullBus  (c+70,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__alu_src1),2);
	vcdp->fullBus  (c+71,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__alu_src2),2);
	vcdp->fullBit  (c+72,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__regs_write));
	vcdp->fullBus  (c+73,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT____Vcellinp__u_matrix__w_matrix_data_mopa[0]),32);
	vcdp->fullBus  (c+74,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT____Vcellinp__u_matrix__w_matrix_data_mopa[1]),32);
	vcdp->fullBus  (c+75,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT____Vcellinp__u_matrix__w_matrix_data_mopa[2]),32);
	vcdp->fullBus  (c+76,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT____Vcellinp__u_matrix__w_matrix_data_mopa[3]),32);
	vcdp->fullBus  (c+77,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT____Vcellout__u_matrix__M_out[0]),32);
	vcdp->fullBus  (c+78,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT____Vcellout__u_matrix__M_out[1]),32);
	vcdp->fullBus  (c+79,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT____Vcellout__u_matrix__M_out[2]),32);
	vcdp->fullBus  (c+80,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT____Vcellout__u_matrix__M_out[3]),32);
	vcdp->fullBit  (c+81,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__wb_hazard_a));
	vcdp->fullBit  (c+82,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__wb_hazard_b));
	vcdp->fullBus  (c+83,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_id_ex__id_M[0]),32);
	vcdp->fullBus  (c+84,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_id_ex__id_M[1]),32);
	vcdp->fullBus  (c+85,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_id_ex__id_M[2]),32);
	vcdp->fullBus  (c+86,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_id_ex__id_M[3]),32);
	vcdp->fullBus  (c+87,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_ex__ex_M[0]),32);
	vcdp->fullBus  (c+88,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_ex__ex_M[1]),32);
	vcdp->fullBus  (c+89,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_ex__ex_M[2]),32);
	vcdp->fullBus  (c+90,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_ex__ex_M[3]),32);
	vcdp->fullBus  (c+91,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_ex__ex_matrix_mul_o[0]),32);
	vcdp->fullBus  (c+92,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_ex__ex_matrix_mul_o[1]),32);
	vcdp->fullBus  (c+93,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_ex__ex_matrix_mul_o[2]),32);
	vcdp->fullBus  (c+94,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_ex__ex_matrix_mul_o[3]),32);
	vcdp->fullBus  (c+95,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__alu_ctrl),4);
	vcdp->fullBus  (c+96,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__op_A),32);
	vcdp->fullBus  (c+97,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__op_A_pre),32);
	vcdp->fullBus  (c+98,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__op_B),32);
	vcdp->fullBus  (c+99,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__op_B_pre),32);
	vcdp->fullBit  (c+100,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__br_mark));
	vcdp->fullBus  (c+101,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__br_addr_op_A),32);
	vcdp->fullBus  (c+102,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT____Vcellinp__u_matrix_mul__M[0]),32);
	vcdp->fullBus  (c+103,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT____Vcellinp__u_matrix_mul__M[1]),32);
	vcdp->fullBus  (c+104,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT____Vcellinp__u_matrix_mul__M[2]),32);
	vcdp->fullBus  (c+105,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT____Vcellinp__u_matrix_mul__M[3]),32);
	vcdp->fullBus  (c+106,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT____Vcellout__u_matrix_mul__matrix_mul_o[0]),32);
	vcdp->fullBus  (c+107,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT____Vcellout__u_matrix_mul__matrix_mul_o[1]),32);
	vcdp->fullBus  (c+108,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT____Vcellout__u_matrix_mul__matrix_mul_o[2]),32);
	vcdp->fullBus  (c+109,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT____Vcellout__u_matrix_mul__matrix_mul_o[3]),32);
	vcdp->fullBus  (c+110,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__u_matrix_mul__DOT__matrix_line_0),32);
	vcdp->fullBus  (c+111,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__u_matrix_mul__DOT__matrix_line_1),32);
	vcdp->fullBus  (c+112,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__u_matrix_mul__DOT__matrix_line_2),32);
	vcdp->fullBus  (c+113,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__u_matrix_mul__DOT__matrix_line_3),32);
	vcdp->fullBus  (c+114,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_ex_mem__ex_matrix_mul_o[0]),32);
	vcdp->fullBus  (c+115,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_ex_mem__ex_matrix_mul_o[1]),32);
	vcdp->fullBus  (c+116,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_ex_mem__ex_matrix_mul_o[2]),32);
	vcdp->fullBus  (c+117,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_ex_mem__ex_matrix_mul_o[3]),32);
	vcdp->fullBus  (c+118,(vlTOPp->adam_riscv__DOT__u_stage_mem__DOT__w_data_mem),32);
	vcdp->fullBus  (c+119,(vlTOPp->adam_riscv__DOT__u_stage_mem__DOT__r_data_mem),32);
	vcdp->fullBus  (c+120,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_mem_wb__me_matrix_mul_o[0]),32);
	vcdp->fullBus  (c+121,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_mem_wb__me_matrix_mul_o[1]),32);
	vcdp->fullBus  (c+122,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_mem_wb__me_matrix_mul_o[2]),32);
	vcdp->fullBus  (c+123,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_mem_wb__me_matrix_mul_o[3]),32);
	vcdp->fullBus  (c+124,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_wb__wb_matrix_mul_o[0]),32);
	vcdp->fullBus  (c+125,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_wb__wb_matrix_mul_o[1]),32);
	vcdp->fullBus  (c+126,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_wb__wb_matrix_mul_o[2]),32);
	vcdp->fullBus  (c+127,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_wb__wb_matrix_mul_o[3]),32);
	vcdp->fullBus  (c+128,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_wb__w_matrix_data_mopa[0]),32);
	vcdp->fullBus  (c+129,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_wb__w_matrix_data_mopa[1]),32);
	vcdp->fullBus  (c+130,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_wb__w_matrix_data_mopa[2]),32);
	vcdp->fullBus  (c+131,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_wb__w_matrix_data_mopa[3]),32);
	vcdp->fullBit  (c+132,(vlTOPp->adam_riscv__DOT__u_forwarding__DOT__ex_hazard_a));
	vcdp->fullBit  (c+133,(vlTOPp->adam_riscv__DOT__u_forwarding__DOT__ex_hazard_b));
	vcdp->fullBit  (c+134,(vlTOPp->adam_riscv__DOT__u_forwarding__DOT__mem_hazard_a));
	vcdp->fullBit  (c+135,(vlTOPp->adam_riscv__DOT__u_forwarding__DOT__mem_hazard_b));
	vcdp->fullBit  (c+136,(vlTOPp->adam_riscv__DOT__u_forwarding__DOT__hazard_data_w));
	vcdp->fullBus  (c+137,(vlTOPp->adam_riscv__DOT__if_pc),32);
	vcdp->fullBus  (c+138,(vlTOPp->adam_riscv__DOT__id_inst),32);
	vcdp->fullBus  (c+139,(vlTOPp->adam_riscv__DOT__id_pc),32);
	vcdp->fullBit  (c+140,(vlTOPp->adam_riscv__DOT__w_regs_en));
	vcdp->fullBus  (c+141,(vlTOPp->adam_riscv__DOT__w_regs_addr),5);
	vcdp->fullBit  (c+142,((1U & (vlTOPp->adam_riscv__DOT__id_inst 
				      >> 0x1eU))));
	vcdp->fullBus  (c+143,((0x1fU & (vlTOPp->adam_riscv__DOT__id_inst 
					 >> 7U))),5);
	vcdp->fullBus  (c+144,((0x1fU & (vlTOPp->adam_riscv__DOT__id_inst 
					 >> 0xfU))),5);
	vcdp->fullBus  (c+145,((0x1fU & (vlTOPp->adam_riscv__DOT__id_inst 
					 >> 0x14U))),5);
	vcdp->fullBus  (c+146,(vlTOPp->adam_riscv__DOT__ex_rs1),5);
	vcdp->fullBus  (c+147,(vlTOPp->adam_riscv__DOT__ex_rs2),5);
	vcdp->fullBus  (c+148,(vlTOPp->adam_riscv__DOT__ex_pc),32);
	vcdp->fullBus  (c+149,(vlTOPp->adam_riscv__DOT__ex_regs_data1),32);
	vcdp->fullBus  (c+150,(vlTOPp->adam_riscv__DOT__ex_regs_data2),32);
	vcdp->fullBus  (c+151,(vlTOPp->adam_riscv__DOT__ex_imm),32);
	vcdp->fullBus  (c+152,(vlTOPp->adam_riscv__DOT__ex_func3_code),3);
	vcdp->fullBit  (c+153,(vlTOPp->adam_riscv__DOT__ex_func7_code));
	vcdp->fullBus  (c+154,(vlTOPp->adam_riscv__DOT__ex_rd),5);
	vcdp->fullBit  (c+155,(vlTOPp->adam_riscv__DOT__ex_br));
	vcdp->fullBit  (c+156,(vlTOPp->adam_riscv__DOT__ex_mem_read));
	vcdp->fullBit  (c+157,(vlTOPp->adam_riscv__DOT__ex_mem2reg));
	vcdp->fullBus  (c+158,(vlTOPp->adam_riscv__DOT__ex_alu_op),3);
	vcdp->fullBit  (c+159,(vlTOPp->adam_riscv__DOT__ex_mem_write));
	vcdp->fullBus  (c+160,(vlTOPp->adam_riscv__DOT__ex_alu_src1),2);
	vcdp->fullBus  (c+161,(vlTOPp->adam_riscv__DOT__ex_alu_src2),2);
	vcdp->fullBit  (c+162,(vlTOPp->adam_riscv__DOT__ex_br_addr_mode));
	vcdp->fullBit  (c+163,(vlTOPp->adam_riscv__DOT__ex_regs_write));
	vcdp->fullBus  (c+164,(vlTOPp->adam_riscv__DOT__ex_matrix_index),2);
	vcdp->fullBus  (c+165,(vlTOPp->adam_riscv__DOT__ex_inst),32);
	vcdp->fullBit  (c+166,(vlTOPp->adam_riscv__DOT__ex_mem2matrix));
	vcdp->fullBit  (c+167,(vlTOPp->adam_riscv__DOT__ex_matrix_write));
	vcdp->fullBit  (c+168,(vlTOPp->adam_riscv__DOT__ex_matrix_write_mopa));
	vcdp->fullBus  (c+169,(vlTOPp->adam_riscv__DOT__ex_mem_matrix2reg),2);
	vcdp->fullBus  (c+170,(vlTOPp->adam_riscv__DOT__ex_matrix_line_data),32);
	vcdp->fullBit  (c+171,(vlTOPp->adam_riscv__DOT__ex_mem_reg2matrix));
	vcdp->fullBit  (c+172,(vlTOPp->adam_riscv__DOT__ex_matrix2mem));
	vcdp->fullBus  (c+173,(vlTOPp->adam_riscv__DOT__me_rs2),5);
	vcdp->fullBus  (c+174,(vlTOPp->adam_riscv__DOT__me_regs_data2),32);
	vcdp->fullBus  (c+175,(vlTOPp->adam_riscv__DOT__me_alu_o),32);
	vcdp->fullBus  (c+176,(vlTOPp->adam_riscv__DOT__me_rd),5);
	vcdp->fullBit  (c+177,(vlTOPp->adam_riscv__DOT__me_mem_read));
	vcdp->fullBit  (c+178,(vlTOPp->adam_riscv__DOT__me_mem2reg));
	vcdp->fullBit  (c+179,(vlTOPp->adam_riscv__DOT__me_mem_write));
	vcdp->fullBit  (c+180,(vlTOPp->adam_riscv__DOT__me_regs_write));
	vcdp->fullBus  (c+181,(vlTOPp->adam_riscv__DOT__me_func3_code),3);
	vcdp->fullBus  (c+182,(vlTOPp->adam_riscv__DOT__me_matrix_index),2);
	vcdp->fullBus  (c+183,(vlTOPp->adam_riscv__DOT__me_inst),32);
	vcdp->fullBit  (c+184,(vlTOPp->adam_riscv__DOT__me_mem2matrix));
	vcdp->fullBit  (c+185,(vlTOPp->adam_riscv__DOT__me_matrix_write));
	vcdp->fullBit  (c+186,(vlTOPp->adam_riscv__DOT__me_matrix_write_mopa));
	vcdp->fullBus  (c+187,(vlTOPp->adam_riscv__DOT__me_mem_matrix2reg),2);
	vcdp->fullBus  (c+188,(vlTOPp->adam_riscv__DOT__me_matrix_line_data),32);
	vcdp->fullBit  (c+189,(vlTOPp->adam_riscv__DOT__me_mem_reg2matrix));
	vcdp->fullBus  (c+190,(vlTOPp->adam_riscv__DOT__me_regs_data1),32);
	vcdp->fullBit  (c+191,(vlTOPp->adam_riscv__DOT__me_matrix2mem));
	vcdp->fullBus  (c+192,(vlTOPp->adam_riscv__DOT__wb_mem_data),32);
	vcdp->fullBus  (c+193,(vlTOPp->adam_riscv__DOT__wb_alu_o),32);
	vcdp->fullBit  (c+194,(vlTOPp->adam_riscv__DOT__wb_mem2reg));
	vcdp->fullBus  (c+195,(vlTOPp->adam_riscv__DOT__wb_matrix_index),2);
	vcdp->fullBit  (c+196,(vlTOPp->adam_riscv__DOT__wb_mem2matrix));
	vcdp->fullBit  (c+197,(vlTOPp->adam_riscv__DOT__wb_matrix_write));
	vcdp->fullBit  (c+198,(vlTOPp->adam_riscv__DOT__wb_matrix_write_mopa));
	vcdp->fullBus  (c+199,(vlTOPp->adam_riscv__DOT__wb_mem_matrix2reg),2);
	vcdp->fullBus  (c+200,(vlTOPp->adam_riscv__DOT__wb_matrix_line_data),32);
	vcdp->fullBit  (c+201,(vlTOPp->adam_riscv__DOT__wb_mem_reg2matrix));
	vcdp->fullBus  (c+202,(vlTOPp->adam_riscv__DOT__wb_regs_data1),32);
	vcdp->fullBus  (c+203,(vlTOPp->adam_riscv__DOT__wb_inst),32);
	vcdp->fullBus  (c+204,(vlTOPp->adam_riscv__DOT__u_stage_if__DOT__u_pc__DOT__pc_next),32);
	vcdp->fullBit  (c+205,((0x67U != (0x7fU & vlTOPp->adam_riscv__DOT__id_inst))));
	vcdp->fullBus  (c+206,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_matrix__DOT__M[0]),32);
	vcdp->fullBus  (c+207,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_matrix__DOT__M[1]),32);
	vcdp->fullBus  (c+208,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_matrix__DOT__M[2]),32);
	vcdp->fullBus  (c+209,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_matrix__DOT__M[3]),32);
	vcdp->fullBus  (c+210,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[0]),32);
	vcdp->fullBus  (c+211,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[1]),32);
	vcdp->fullBus  (c+212,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[2]),32);
	vcdp->fullBus  (c+213,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[3]),32);
	vcdp->fullBus  (c+214,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[4]),32);
	vcdp->fullBus  (c+215,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[5]),32);
	vcdp->fullBus  (c+216,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[6]),32);
	vcdp->fullBus  (c+217,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[7]),32);
	vcdp->fullBus  (c+218,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[8]),32);
	vcdp->fullBus  (c+219,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[9]),32);
	vcdp->fullBus  (c+220,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[10]),32);
	vcdp->fullBus  (c+221,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[11]),32);
	vcdp->fullBus  (c+222,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[12]),32);
	vcdp->fullBus  (c+223,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[13]),32);
	vcdp->fullBus  (c+224,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[14]),32);
	vcdp->fullBus  (c+225,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[15]),32);
	vcdp->fullBus  (c+226,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[16]),32);
	vcdp->fullBus  (c+227,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[17]),32);
	vcdp->fullBus  (c+228,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[18]),32);
	vcdp->fullBus  (c+229,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[19]),32);
	vcdp->fullBus  (c+230,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[20]),32);
	vcdp->fullBus  (c+231,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[21]),32);
	vcdp->fullBus  (c+232,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[22]),32);
	vcdp->fullBus  (c+233,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[23]),32);
	vcdp->fullBus  (c+234,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[24]),32);
	vcdp->fullBus  (c+235,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[25]),32);
	vcdp->fullBus  (c+236,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[26]),32);
	vcdp->fullBus  (c+237,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[27]),32);
	vcdp->fullBus  (c+238,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[28]),32);
	vcdp->fullBus  (c+239,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[29]),32);
	vcdp->fullBus  (c+240,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[30]),32);
	vcdp->fullBus  (c+241,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[31]),32);
	vcdp->fullBus  (c+242,((0x7fU & vlTOPp->adam_riscv__DOT__id_inst)),7);
	vcdp->fullBus  (c+243,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_id_ex__ex_M[0]),32);
	vcdp->fullBus  (c+244,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_id_ex__ex_M[1]),32);
	vcdp->fullBus  (c+245,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_id_ex__ex_M[2]),32);
	vcdp->fullBus  (c+246,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_id_ex__ex_M[3]),32);
	vcdp->fullBus  (c+247,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_ex_mem__me_matrix_mul_o[0]),32);
	vcdp->fullBus  (c+248,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_ex_mem__me_matrix_mul_o[1]),32);
	vcdp->fullBus  (c+249,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_ex_mem__me_matrix_mul_o[2]),32);
	vcdp->fullBus  (c+250,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_ex_mem__me_matrix_mul_o[3]),32);
	vcdp->fullBus  (c+251,((3U & (IData)(vlTOPp->adam_riscv__DOT__me_func3_code))),2);
	vcdp->fullBus  (c+252,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_mem_wb__wb_matrix_mul_o[0]),32);
	vcdp->fullBus  (c+253,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_mem_wb__wb_matrix_mul_o[1]),32);
	vcdp->fullBus  (c+254,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_mem_wb__wb_matrix_mul_o[2]),32);
	vcdp->fullBus  (c+255,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_mem_wb__wb_matrix_mul_o[3]),32);
	vcdp->fullBit  (c+256,(vlTOPp->clk));
	vcdp->fullBit  (c+257,(vlTOPp->rst));
	vcdp->fullBus  (c+258,(0x400U),32);
    }
}
