module matrix_data(
    input wire clk,
    input wire rst,
    input wire[1:0]     r_matrix_index,
    input wire[1:0]     w_matrix_index,
    input wire[31:0]    w_matrix_data,
    input wire[31:0]    w_matrix_data_mopa[3:0],
    input wire          w_matrix_en,
    input wire          w_matrix_en_mopa,

    output wire[31:0]   r_matrix_o,
    output wire[31:0]   M_out[3:0]
);

reg [31:0] M [3:0]; //  4 32-bit registers matrix

/*------------------------Write Matrix---------------*/
always @(posedge clk) begin
    if (!rst) begin
        M[0] <= 32'h55555555;
        M[1] <= 32'haaaaaaaa;
        M[2] <= 32'h33333333;
        M[3] <= 32'hcccccccc;
    end
    else if (w_matrix_en && !w_matrix_en_mopa) begin
        M[w_matrix_index] <= w_matrix_data;
    end
    else if (w_matrix_en_mopa) begin
        M[0] <= w_matrix_data_mopa[0];
        M[1] <= w_matrix_data_mopa[1];
        M[2] <= w_matrix_data_mopa[2];
        M[3] <= w_matrix_data_mopa[3];
    end
    else begin
        M[0] <= M[0];
        M[1] <= M[1];
        M[2] <= M[2];
        M[3] <= M[3];
    end
end

assign M_out[0] = M[0];
assign M_out[1] = M[1];
assign M_out[2] = M[2];
assign M_out[3] = M[3];

/*------------------------Read Matrix---------------*/
assign r_matrix_o = M[r_matrix_index];
endmodule