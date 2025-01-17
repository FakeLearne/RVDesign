// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vadam_riscv__Syms.h"


//======================

void Vadam_riscv::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vadam_riscv* t=(Vadam_riscv*)userthis;
    Vadam_riscv__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis (vlSymsp, vcdp, code);
    }
}

//======================


void Vadam_riscv::traceChgThis(Vadam_riscv__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vadam_riscv* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 1U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vadam_riscv::traceChgThis__2(Vadam_riscv__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vadam_riscv* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+1,(vlTOPp->adam_riscv__DOT__br_ctrl));
	vcdp->chgBus  (c+2,(vlTOPp->adam_riscv__DOT__br_addr),32);
	vcdp->chgBit  (c+3,(vlTOPp->adam_riscv__DOT__stall));
	vcdp->chgBus  (c+4,(vlTOPp->adam_riscv__DOT__if_inst),32);
	vcdp->chgBus  (c+5,(vlTOPp->adam_riscv__DOT__w_regs_data),32);
	vcdp->chgBus  (c+6,(vlTOPp->adam_riscv__DOT__w_matrix_data),32);
	vcdp->chgBus  (c+7,(vlTOPp->adam_riscv__DOT__w_matrix_data_mopa[0]),32);
	vcdp->chgBus  (c+8,(vlTOPp->adam_riscv__DOT__w_matrix_data_mopa[1]),32);
	vcdp->chgBus  (c+9,(vlTOPp->adam_riscv__DOT__w_matrix_data_mopa[2]),32);
	vcdp->chgBus  (c+10,(vlTOPp->adam_riscv__DOT__w_matrix_data_mopa[3]),32);
	vcdp->chgBus  (c+11,(vlTOPp->adam_riscv__DOT__id_regs_data1),32);
	vcdp->chgBus  (c+12,(vlTOPp->adam_riscv__DOT__id_regs_data2),32);
	vcdp->chgBus  (c+13,(vlTOPp->adam_riscv__DOT__id_imm),32);
	vcdp->chgBus  (c+14,(vlTOPp->adam_riscv__DOT__id_func3_code),3);
	vcdp->chgBit  (c+15,(vlTOPp->adam_riscv__DOT__id_br));
	vcdp->chgBit  (c+16,(vlTOPp->adam_riscv__DOT__id_mem_read));
	vcdp->chgBit  (c+17,(vlTOPp->adam_riscv__DOT__id_mem2reg));
	vcdp->chgBus  (c+18,(vlTOPp->adam_riscv__DOT__id_alu_op),3);
	vcdp->chgBit  (c+19,(vlTOPp->adam_riscv__DOT__id_mem_write));
	vcdp->chgBus  (c+20,(vlTOPp->adam_riscv__DOT__id_alu_src1),2);
	vcdp->chgBus  (c+21,(vlTOPp->adam_riscv__DOT__id_alu_src2),2);
	vcdp->chgBit  (c+22,(vlTOPp->adam_riscv__DOT__id_br_addr_mode));
	vcdp->chgBit  (c+23,(vlTOPp->adam_riscv__DOT__id_regs_write));
	vcdp->chgBus  (c+24,(vlTOPp->adam_riscv__DOT__id_matrix_index),2);
	vcdp->chgBit  (c+25,(vlTOPp->adam_riscv__DOT__id_mem2matrix));
	vcdp->chgBit  (c+26,(vlTOPp->adam_riscv__DOT__id_matrix_write));
	vcdp->chgBit  (c+27,(vlTOPp->adam_riscv__DOT__id_matrix_write_mopa));
	vcdp->chgBus  (c+28,(vlTOPp->adam_riscv__DOT__id_mem_matrix2reg),2);
	vcdp->chgBus  (c+29,(vlTOPp->adam_riscv__DOT__id_matrix_line_data),32);
	vcdp->chgBit  (c+30,(vlTOPp->adam_riscv__DOT__id_mem_reg2matrix));
	vcdp->chgBit  (c+31,(vlTOPp->adam_riscv__DOT__id_matrix2mem));
	vcdp->chgBus  (c+32,(vlTOPp->adam_riscv__DOT__id_M[0]),32);
	vcdp->chgBus  (c+33,(vlTOPp->adam_riscv__DOT__id_M[1]),32);
	vcdp->chgBus  (c+34,(vlTOPp->adam_riscv__DOT__id_M[2]),32);
	vcdp->chgBus  (c+35,(vlTOPp->adam_riscv__DOT__id_M[3]),32);
	vcdp->chgBus  (c+36,(vlTOPp->adam_riscv__DOT__ex_alu_o),32);
	vcdp->chgBus  (c+37,(vlTOPp->adam_riscv__DOT__ex_matrix_mul_o[0]),32);
	vcdp->chgBus  (c+38,(vlTOPp->adam_riscv__DOT__ex_matrix_mul_o[1]),32);
	vcdp->chgBus  (c+39,(vlTOPp->adam_riscv__DOT__ex_matrix_mul_o[2]),32);
	vcdp->chgBus  (c+40,(vlTOPp->adam_riscv__DOT__ex_matrix_mul_o[3]),32);
	vcdp->chgBus  (c+41,(vlTOPp->adam_riscv__DOT__ex_M[0]),32);
	vcdp->chgBus  (c+42,(vlTOPp->adam_riscv__DOT__ex_M[1]),32);
	vcdp->chgBus  (c+43,(vlTOPp->adam_riscv__DOT__ex_M[2]),32);
	vcdp->chgBus  (c+44,(vlTOPp->adam_riscv__DOT__ex_M[3]),32);
	vcdp->chgBus  (c+45,(vlTOPp->adam_riscv__DOT__forwardA),2);
	vcdp->chgBus  (c+46,(vlTOPp->adam_riscv__DOT__forwardB),2);
	vcdp->chgBus  (c+47,(vlTOPp->adam_riscv__DOT__me_mem_data),32);
	vcdp->chgBus  (c+48,(vlTOPp->adam_riscv__DOT__me_matrix_mul_o[0]),32);
	vcdp->chgBus  (c+49,(vlTOPp->adam_riscv__DOT__me_matrix_mul_o[1]),32);
	vcdp->chgBus  (c+50,(vlTOPp->adam_riscv__DOT__me_matrix_mul_o[2]),32);
	vcdp->chgBus  (c+51,(vlTOPp->adam_riscv__DOT__me_matrix_mul_o[3]),32);
	vcdp->chgBit  (c+52,((1U & ((IData)(vlTOPp->adam_riscv__DOT__u_forwarding__DOT__hazard_data_w)
				     ? 1U : 0U))));
	vcdp->chgBus  (c+53,(vlTOPp->adam_riscv__DOT__wb_matrix_mul_o[0]),32);
	vcdp->chgBus  (c+54,(vlTOPp->adam_riscv__DOT__wb_matrix_mul_o[1]),32);
	vcdp->chgBus  (c+55,(vlTOPp->adam_riscv__DOT__wb_matrix_mul_o[2]),32);
	vcdp->chgBus  (c+56,(vlTOPp->adam_riscv__DOT__wb_matrix_mul_o[3]),32);
	vcdp->chgBus  (c+57,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_id__w_matrix_data_mopa[0]),32);
	vcdp->chgBus  (c+58,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_id__w_matrix_data_mopa[1]),32);
	vcdp->chgBus  (c+59,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_id__w_matrix_data_mopa[2]),32);
	vcdp->chgBus  (c+60,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_id__w_matrix_data_mopa[3]),32);
	vcdp->chgBus  (c+61,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_id__id_M[0]),32);
	vcdp->chgBus  (c+62,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_id__id_M[1]),32);
	vcdp->chgBus  (c+63,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_id__id_M[2]),32);
	vcdp->chgBus  (c+64,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_id__id_M[3]),32);
	vcdp->chgBit  (c+65,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__br));
	vcdp->chgBit  (c+66,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__mem_read));
	vcdp->chgBit  (c+67,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__mem2reg));
	vcdp->chgBus  (c+68,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__alu_op),3);
	vcdp->chgBit  (c+69,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__mem_write));
	vcdp->chgBus  (c+70,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__alu_src1),2);
	vcdp->chgBus  (c+71,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__alu_src2),2);
	vcdp->chgBit  (c+72,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__regs_write));
	vcdp->chgBus  (c+73,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT____Vcellinp__u_matrix__w_matrix_data_mopa[0]),32);
	vcdp->chgBus  (c+74,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT____Vcellinp__u_matrix__w_matrix_data_mopa[1]),32);
	vcdp->chgBus  (c+75,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT____Vcellinp__u_matrix__w_matrix_data_mopa[2]),32);
	vcdp->chgBus  (c+76,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT____Vcellinp__u_matrix__w_matrix_data_mopa[3]),32);
	vcdp->chgBus  (c+77,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT____Vcellout__u_matrix__M_out[0]),32);
	vcdp->chgBus  (c+78,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT____Vcellout__u_matrix__M_out[1]),32);
	vcdp->chgBus  (c+79,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT____Vcellout__u_matrix__M_out[2]),32);
	vcdp->chgBus  (c+80,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT____Vcellout__u_matrix__M_out[3]),32);
	vcdp->chgBit  (c+81,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__wb_hazard_a));
	vcdp->chgBit  (c+82,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__wb_hazard_b));
	vcdp->chgBus  (c+83,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_id_ex__id_M[0]),32);
	vcdp->chgBus  (c+84,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_id_ex__id_M[1]),32);
	vcdp->chgBus  (c+85,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_id_ex__id_M[2]),32);
	vcdp->chgBus  (c+86,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_id_ex__id_M[3]),32);
	vcdp->chgBus  (c+87,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_ex__ex_M[0]),32);
	vcdp->chgBus  (c+88,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_ex__ex_M[1]),32);
	vcdp->chgBus  (c+89,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_ex__ex_M[2]),32);
	vcdp->chgBus  (c+90,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_ex__ex_M[3]),32);
	vcdp->chgBus  (c+91,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_ex__ex_matrix_mul_o[0]),32);
	vcdp->chgBus  (c+92,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_ex__ex_matrix_mul_o[1]),32);
	vcdp->chgBus  (c+93,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_ex__ex_matrix_mul_o[2]),32);
	vcdp->chgBus  (c+94,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_ex__ex_matrix_mul_o[3]),32);
	vcdp->chgBus  (c+95,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__alu_ctrl),4);
	vcdp->chgBus  (c+96,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__op_A),32);
	vcdp->chgBus  (c+97,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__op_A_pre),32);
	vcdp->chgBus  (c+98,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__op_B),32);
	vcdp->chgBus  (c+99,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__op_B_pre),32);
	vcdp->chgBit  (c+100,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__br_mark));
	vcdp->chgBus  (c+101,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__br_addr_op_A),32);
	vcdp->chgBus  (c+102,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT____Vcellinp__u_matrix_mul__M[0]),32);
	vcdp->chgBus  (c+103,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT____Vcellinp__u_matrix_mul__M[1]),32);
	vcdp->chgBus  (c+104,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT____Vcellinp__u_matrix_mul__M[2]),32);
	vcdp->chgBus  (c+105,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT____Vcellinp__u_matrix_mul__M[3]),32);
	vcdp->chgBus  (c+106,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT____Vcellout__u_matrix_mul__matrix_mul_o[0]),32);
	vcdp->chgBus  (c+107,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT____Vcellout__u_matrix_mul__matrix_mul_o[1]),32);
	vcdp->chgBus  (c+108,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT____Vcellout__u_matrix_mul__matrix_mul_o[2]),32);
	vcdp->chgBus  (c+109,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT____Vcellout__u_matrix_mul__matrix_mul_o[3]),32);
	vcdp->chgBus  (c+110,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__u_matrix_mul__DOT__matrix_line_0),32);
	vcdp->chgBus  (c+111,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__u_matrix_mul__DOT__matrix_line_1),32);
	vcdp->chgBus  (c+112,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__u_matrix_mul__DOT__matrix_line_2),32);
	vcdp->chgBus  (c+113,(vlTOPp->adam_riscv__DOT__u_stage_ex__DOT__u_matrix_mul__DOT__matrix_line_3),32);
	vcdp->chgBus  (c+114,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_ex_mem__ex_matrix_mul_o[0]),32);
	vcdp->chgBus  (c+115,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_ex_mem__ex_matrix_mul_o[1]),32);
	vcdp->chgBus  (c+116,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_ex_mem__ex_matrix_mul_o[2]),32);
	vcdp->chgBus  (c+117,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_ex_mem__ex_matrix_mul_o[3]),32);
	vcdp->chgBus  (c+118,(vlTOPp->adam_riscv__DOT__u_stage_mem__DOT__w_data_mem),32);
	vcdp->chgBus  (c+119,(vlTOPp->adam_riscv__DOT__u_stage_mem__DOT__r_data_mem),32);
	vcdp->chgBus  (c+120,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_mem_wb__me_matrix_mul_o[0]),32);
	vcdp->chgBus  (c+121,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_mem_wb__me_matrix_mul_o[1]),32);
	vcdp->chgBus  (c+122,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_mem_wb__me_matrix_mul_o[2]),32);
	vcdp->chgBus  (c+123,(vlTOPp->adam_riscv__DOT____Vcellinp__u_reg_mem_wb__me_matrix_mul_o[3]),32);
	vcdp->chgBus  (c+124,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_wb__wb_matrix_mul_o[0]),32);
	vcdp->chgBus  (c+125,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_wb__wb_matrix_mul_o[1]),32);
	vcdp->chgBus  (c+126,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_wb__wb_matrix_mul_o[2]),32);
	vcdp->chgBus  (c+127,(vlTOPp->adam_riscv__DOT____Vcellinp__u_stage_wb__wb_matrix_mul_o[3]),32);
	vcdp->chgBus  (c+128,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_wb__w_matrix_data_mopa[0]),32);
	vcdp->chgBus  (c+129,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_wb__w_matrix_data_mopa[1]),32);
	vcdp->chgBus  (c+130,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_wb__w_matrix_data_mopa[2]),32);
	vcdp->chgBus  (c+131,(vlTOPp->adam_riscv__DOT____Vcellout__u_stage_wb__w_matrix_data_mopa[3]),32);
	vcdp->chgBit  (c+132,(vlTOPp->adam_riscv__DOT__u_forwarding__DOT__ex_hazard_a));
	vcdp->chgBit  (c+133,(vlTOPp->adam_riscv__DOT__u_forwarding__DOT__ex_hazard_b));
	vcdp->chgBit  (c+134,(vlTOPp->adam_riscv__DOT__u_forwarding__DOT__mem_hazard_a));
	vcdp->chgBit  (c+135,(vlTOPp->adam_riscv__DOT__u_forwarding__DOT__mem_hazard_b));
	vcdp->chgBit  (c+136,(vlTOPp->adam_riscv__DOT__u_forwarding__DOT__hazard_data_w));
    }
}

void Vadam_riscv::traceChgThis__3(Vadam_riscv__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vadam_riscv* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus  (c+137,(vlTOPp->adam_riscv__DOT__if_pc),32);
	vcdp->chgBus  (c+138,(vlTOPp->adam_riscv__DOT__id_inst),32);
	vcdp->chgBus  (c+139,(vlTOPp->adam_riscv__DOT__id_pc),32);
	vcdp->chgBit  (c+140,(vlTOPp->adam_riscv__DOT__w_regs_en));
	vcdp->chgBus  (c+141,(vlTOPp->adam_riscv__DOT__w_regs_addr),5);
	vcdp->chgBit  (c+142,((1U & (vlTOPp->adam_riscv__DOT__id_inst 
				     >> 0x1eU))));
	vcdp->chgBus  (c+143,((0x1fU & (vlTOPp->adam_riscv__DOT__id_inst 
					>> 7U))),5);
	vcdp->chgBus  (c+144,((0x1fU & (vlTOPp->adam_riscv__DOT__id_inst 
					>> 0xfU))),5);
	vcdp->chgBus  (c+145,((0x1fU & (vlTOPp->adam_riscv__DOT__id_inst 
					>> 0x14U))),5);
	vcdp->chgBus  (c+146,(vlTOPp->adam_riscv__DOT__ex_rs1),5);
	vcdp->chgBus  (c+147,(vlTOPp->adam_riscv__DOT__ex_rs2),5);
	vcdp->chgBus  (c+148,(vlTOPp->adam_riscv__DOT__ex_pc),32);
	vcdp->chgBus  (c+149,(vlTOPp->adam_riscv__DOT__ex_regs_data1),32);
	vcdp->chgBus  (c+150,(vlTOPp->adam_riscv__DOT__ex_regs_data2),32);
	vcdp->chgBus  (c+151,(vlTOPp->adam_riscv__DOT__ex_imm),32);
	vcdp->chgBus  (c+152,(vlTOPp->adam_riscv__DOT__ex_func3_code),3);
	vcdp->chgBit  (c+153,(vlTOPp->adam_riscv__DOT__ex_func7_code));
	vcdp->chgBus  (c+154,(vlTOPp->adam_riscv__DOT__ex_rd),5);
	vcdp->chgBit  (c+155,(vlTOPp->adam_riscv__DOT__ex_br));
	vcdp->chgBit  (c+156,(vlTOPp->adam_riscv__DOT__ex_mem_read));
	vcdp->chgBit  (c+157,(vlTOPp->adam_riscv__DOT__ex_mem2reg));
	vcdp->chgBus  (c+158,(vlTOPp->adam_riscv__DOT__ex_alu_op),3);
	vcdp->chgBit  (c+159,(vlTOPp->adam_riscv__DOT__ex_mem_write));
	vcdp->chgBus  (c+160,(vlTOPp->adam_riscv__DOT__ex_alu_src1),2);
	vcdp->chgBus  (c+161,(vlTOPp->adam_riscv__DOT__ex_alu_src2),2);
	vcdp->chgBit  (c+162,(vlTOPp->adam_riscv__DOT__ex_br_addr_mode));
	vcdp->chgBit  (c+163,(vlTOPp->adam_riscv__DOT__ex_regs_write));
	vcdp->chgBus  (c+164,(vlTOPp->adam_riscv__DOT__ex_matrix_index),2);
	vcdp->chgBus  (c+165,(vlTOPp->adam_riscv__DOT__ex_inst),32);
	vcdp->chgBit  (c+166,(vlTOPp->adam_riscv__DOT__ex_mem2matrix));
	vcdp->chgBit  (c+167,(vlTOPp->adam_riscv__DOT__ex_matrix_write));
	vcdp->chgBit  (c+168,(vlTOPp->adam_riscv__DOT__ex_matrix_write_mopa));
	vcdp->chgBus  (c+169,(vlTOPp->adam_riscv__DOT__ex_mem_matrix2reg),2);
	vcdp->chgBus  (c+170,(vlTOPp->adam_riscv__DOT__ex_matrix_line_data),32);
	vcdp->chgBit  (c+171,(vlTOPp->adam_riscv__DOT__ex_mem_reg2matrix));
	vcdp->chgBit  (c+172,(vlTOPp->adam_riscv__DOT__ex_matrix2mem));
	vcdp->chgBus  (c+173,(vlTOPp->adam_riscv__DOT__me_rs2),5);
	vcdp->chgBus  (c+174,(vlTOPp->adam_riscv__DOT__me_regs_data2),32);
	vcdp->chgBus  (c+175,(vlTOPp->adam_riscv__DOT__me_alu_o),32);
	vcdp->chgBus  (c+176,(vlTOPp->adam_riscv__DOT__me_rd),5);
	vcdp->chgBit  (c+177,(vlTOPp->adam_riscv__DOT__me_mem_read));
	vcdp->chgBit  (c+178,(vlTOPp->adam_riscv__DOT__me_mem2reg));
	vcdp->chgBit  (c+179,(vlTOPp->adam_riscv__DOT__me_mem_write));
	vcdp->chgBit  (c+180,(vlTOPp->adam_riscv__DOT__me_regs_write));
	vcdp->chgBus  (c+181,(vlTOPp->adam_riscv__DOT__me_func3_code),3);
	vcdp->chgBus  (c+182,(vlTOPp->adam_riscv__DOT__me_matrix_index),2);
	vcdp->chgBus  (c+183,(vlTOPp->adam_riscv__DOT__me_inst),32);
	vcdp->chgBit  (c+184,(vlTOPp->adam_riscv__DOT__me_mem2matrix));
	vcdp->chgBit  (c+185,(vlTOPp->adam_riscv__DOT__me_matrix_write));
	vcdp->chgBit  (c+186,(vlTOPp->adam_riscv__DOT__me_matrix_write_mopa));
	vcdp->chgBus  (c+187,(vlTOPp->adam_riscv__DOT__me_mem_matrix2reg),2);
	vcdp->chgBus  (c+188,(vlTOPp->adam_riscv__DOT__me_matrix_line_data),32);
	vcdp->chgBit  (c+189,(vlTOPp->adam_riscv__DOT__me_mem_reg2matrix));
	vcdp->chgBus  (c+190,(vlTOPp->adam_riscv__DOT__me_regs_data1),32);
	vcdp->chgBit  (c+191,(vlTOPp->adam_riscv__DOT__me_matrix2mem));
	vcdp->chgBus  (c+192,(vlTOPp->adam_riscv__DOT__wb_mem_data),32);
	vcdp->chgBus  (c+193,(vlTOPp->adam_riscv__DOT__wb_alu_o),32);
	vcdp->chgBit  (c+194,(vlTOPp->adam_riscv__DOT__wb_mem2reg));
	vcdp->chgBus  (c+195,(vlTOPp->adam_riscv__DOT__wb_matrix_index),2);
	vcdp->chgBit  (c+196,(vlTOPp->adam_riscv__DOT__wb_mem2matrix));
	vcdp->chgBit  (c+197,(vlTOPp->adam_riscv__DOT__wb_matrix_write));
	vcdp->chgBit  (c+198,(vlTOPp->adam_riscv__DOT__wb_matrix_write_mopa));
	vcdp->chgBus  (c+199,(vlTOPp->adam_riscv__DOT__wb_mem_matrix2reg),2);
	vcdp->chgBus  (c+200,(vlTOPp->adam_riscv__DOT__wb_matrix_line_data),32);
	vcdp->chgBit  (c+201,(vlTOPp->adam_riscv__DOT__wb_mem_reg2matrix));
	vcdp->chgBus  (c+202,(vlTOPp->adam_riscv__DOT__wb_regs_data1),32);
	vcdp->chgBus  (c+203,(vlTOPp->adam_riscv__DOT__wb_inst),32);
	vcdp->chgBus  (c+204,(vlTOPp->adam_riscv__DOT__u_stage_if__DOT__u_pc__DOT__pc_next),32);
	vcdp->chgBit  (c+205,((0x67U != (0x7fU & vlTOPp->adam_riscv__DOT__id_inst))));
	vcdp->chgBus  (c+206,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_matrix__DOT__M[0]),32);
	vcdp->chgBus  (c+207,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_matrix__DOT__M[1]),32);
	vcdp->chgBus  (c+208,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_matrix__DOT__M[2]),32);
	vcdp->chgBus  (c+209,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_matrix__DOT__M[3]),32);
	vcdp->chgBus  (c+210,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[0]),32);
	vcdp->chgBus  (c+211,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[1]),32);
	vcdp->chgBus  (c+212,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[2]),32);
	vcdp->chgBus  (c+213,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[3]),32);
	vcdp->chgBus  (c+214,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[4]),32);
	vcdp->chgBus  (c+215,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[5]),32);
	vcdp->chgBus  (c+216,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[6]),32);
	vcdp->chgBus  (c+217,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[7]),32);
	vcdp->chgBus  (c+218,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[8]),32);
	vcdp->chgBus  (c+219,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[9]),32);
	vcdp->chgBus  (c+220,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[10]),32);
	vcdp->chgBus  (c+221,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[11]),32);
	vcdp->chgBus  (c+222,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[12]),32);
	vcdp->chgBus  (c+223,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[13]),32);
	vcdp->chgBus  (c+224,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[14]),32);
	vcdp->chgBus  (c+225,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[15]),32);
	vcdp->chgBus  (c+226,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[16]),32);
	vcdp->chgBus  (c+227,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[17]),32);
	vcdp->chgBus  (c+228,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[18]),32);
	vcdp->chgBus  (c+229,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[19]),32);
	vcdp->chgBus  (c+230,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[20]),32);
	vcdp->chgBus  (c+231,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[21]),32);
	vcdp->chgBus  (c+232,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[22]),32);
	vcdp->chgBus  (c+233,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[23]),32);
	vcdp->chgBus  (c+234,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[24]),32);
	vcdp->chgBus  (c+235,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[25]),32);
	vcdp->chgBus  (c+236,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[26]),32);
	vcdp->chgBus  (c+237,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[27]),32);
	vcdp->chgBus  (c+238,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[28]),32);
	vcdp->chgBus  (c+239,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[29]),32);
	vcdp->chgBus  (c+240,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[30]),32);
	vcdp->chgBus  (c+241,(vlTOPp->adam_riscv__DOT__u_stage_id__DOT__u_regs__DOT__regs_file[31]),32);
	vcdp->chgBus  (c+242,((0x7fU & vlTOPp->adam_riscv__DOT__id_inst)),7);
	vcdp->chgBus  (c+243,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_id_ex__ex_M[0]),32);
	vcdp->chgBus  (c+244,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_id_ex__ex_M[1]),32);
	vcdp->chgBus  (c+245,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_id_ex__ex_M[2]),32);
	vcdp->chgBus  (c+246,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_id_ex__ex_M[3]),32);
	vcdp->chgBus  (c+247,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_ex_mem__me_matrix_mul_o[0]),32);
	vcdp->chgBus  (c+248,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_ex_mem__me_matrix_mul_o[1]),32);
	vcdp->chgBus  (c+249,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_ex_mem__me_matrix_mul_o[2]),32);
	vcdp->chgBus  (c+250,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_ex_mem__me_matrix_mul_o[3]),32);
	vcdp->chgBus  (c+251,((3U & (IData)(vlTOPp->adam_riscv__DOT__me_func3_code))),2);
	vcdp->chgBus  (c+252,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_mem_wb__wb_matrix_mul_o[0]),32);
	vcdp->chgBus  (c+253,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_mem_wb__wb_matrix_mul_o[1]),32);
	vcdp->chgBus  (c+254,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_mem_wb__wb_matrix_mul_o[2]),32);
	vcdp->chgBus  (c+255,(vlTOPp->adam_riscv__DOT____Vcellout__u_reg_mem_wb__wb_matrix_mul_o[3]),32);
    }
}

void Vadam_riscv::traceChgThis__4(Vadam_riscv__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vadam_riscv* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit  (c+256,(vlTOPp->clk));
	vcdp->chgBit  (c+257,(vlTOPp->rst));
    }
}
