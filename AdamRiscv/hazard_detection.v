module hazard_detection(
    input  wire      ex_mem_read,
    input  wire[4:0] id_rs1,
    input  wire[4:0] id_rs2,
    input  wire[4:0] ex_rd,
    input  wire      br_ctrl,

    input  wire[31:0] if_inst, 
    input  wire[31:0] ex_inst,
    input  wire[31:0] me_inst,
    input  wire[31:0] wb_inst,

    output wire      load_stall,
    output wire      flush
);

// assign load_stall = ex_mem_read && (ex_rd == id_rs1 || ex_rd == id_rs2);
assign load_stall = ex_mem_read && (ex_rd == id_rs1 || ex_rd == id_rs2) || 
                    {if_inst[14:12], if_inst[6:0]} == `MtypePA && {me_inst[14:12], me_inst[6:0]} == `MtypeM2 || 
                    {if_inst[14:12], if_inst[6:0]} == `MtypeS && {ex_inst[14:12], ex_inst[6:0]} == `MtypePA || 
                    {if_inst[14:12], if_inst[6:0]} == `MtypeS && {me_inst[14:12], me_inst[6:0]} == `MtypePA || 
                    {if_inst[14:12], if_inst[6:0]} == `MtypeS && {wb_inst[14:12], wb_inst[6:0]} == `MtypePA;

assign flush      = br_ctrl;


endmodule