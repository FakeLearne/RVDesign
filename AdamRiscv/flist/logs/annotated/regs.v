	// verilator_coverage annotation
	module regs(
 020001	    input wire clk,
%000001	    input wire rst,
	
 013215	    input wire[4:0]     r_regs_addr1,
 032972	    input wire[4:0]     r_regs_addr2,
 000042	    input wire[4:0]     w_regs_addr,
%000168	    input wire[31:0]    w_regs_data,
 000012	    input wire          w_regs_en,
	
 105680	    output wire[31:0]   r_regs_o1,
 105616	    output wire[31:0]   r_regs_o2
	);
	
	reg [31:0] regs_file [31:0]; //  32 32-bit registers
%000009	wire wb_hazard_a;
%000001	wire wb_hazard_b;
	
	/*------------------------Write RegisterFile---------------*/
	always @(posedge clk) begin
 000100	    if (!rst)begin
	        regs_file[0] <= 0;
	    end
 000014	    else if (w_regs_en && w_regs_addr != 5'b0) begin //forbit write x0
	        $display("WRITE REGISTER FILE: x%d = %h", w_regs_addr, w_regs_data);
	        regs_file[w_regs_addr] <= w_regs_data;
	    end
	end
	
	/*------------------------hazard check & forwarding-------------*/
	assign wb_hazard_a = w_regs_en && (w_regs_addr != 0) && (w_regs_addr == r_regs_addr1); //me_rd != 0 : don't forward the result when rd is x0
	assign wb_hazard_b = w_regs_en && (w_regs_addr != 0) && (w_regs_addr == r_regs_addr2);
	
	/*------------------------Read RegisterFile---------------*/
	assign r_regs_o1 = wb_hazard_a ? w_regs_data : regs_file[r_regs_addr1];
	assign r_regs_o2 = wb_hazard_b ? w_regs_data : regs_file[r_regs_addr2];
	
	endmodule
	
