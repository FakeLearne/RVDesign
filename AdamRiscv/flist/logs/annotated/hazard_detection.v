	// verilator_coverage annotation
	module hazard_detection(
%000000	    input  wire      ex_mem_read,
 013215	    input  wire[4:0] id_rs1,
 032972	    input  wire[4:0] id_rs2,
 000041	    input  wire[4:0] ex_rd,
 006588	    input  wire      br_ctrl,
	
 158306	    input  wire[31:0] if_inst, 
 026593	    input  wire[31:0] ex_inst,
 026589	    input  wire[31:0] me_inst,
 026581	    input  wire[31:0] wb_inst,
	
%000000	    output wire      load_stall,
 006588	    output wire      flush
	);
	
	// assign load_stall = ex_mem_read && (ex_rd == id_rs1 || ex_rd == id_rs2);
	assign load_stall = ex_mem_read && (ex_rd == id_rs1 || ex_rd == id_rs2) || 
	                    {if_inst[14:12], if_inst[6:0]} == `MtypePA && {me_inst[14:12], me_inst[6:0]} == `MtypeM2 || 
	                    {if_inst[14:12], if_inst[6:0]} == `MtypeS && {ex_inst[14:12], ex_inst[6:0]} == `MtypePA || 
	                    {if_inst[14:12], if_inst[6:0]} == `MtypeS && {me_inst[14:12], me_inst[6:0]} == `MtypePA || 
	                    {if_inst[14:12], if_inst[6:0]} == `MtypeS && {wb_inst[14:12], wb_inst[6:0]} == `MtypePA;
	
	assign flush      = br_ctrl;
	
	
	endmodule
