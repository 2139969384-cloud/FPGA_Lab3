`timescale 1ns / 1ns

module VGA_pic(
    input vga_clk, 
    input sys_rst_n,
    input [9:0] pix_x,
    input [9:0] pix_y,
    output reg [15:0] pix_data
);

    localparam BLUE   = 16'h001F;
    localparam YELLOW = 16'hFFE0;

    // M
    parameter [15:0] M_ROW_0  = 16'b1111000000111000;
    parameter [15:0] M_ROW_1  = 16'b1111100001111000;
    parameter [15:0] M_ROW_2  = 16'b1111100011111000;
    parameter [15:0] M_ROW_3  = 16'b1111100011111000;
    parameter [15:0] M_ROW_4  = 16'b1111110011111000;
    parameter [15:0] M_ROW_5  = 16'b1111110111111000;
    parameter [15:0] M_ROW_6  = 16'b1111110111111000;
    parameter [15:0] M_ROW_7  = 16'b1110111110111000;
    parameter [15:0] M_ROW_8  = 16'b1110111110111000;
    parameter [15:0] M_ROW_9  = 16'b1110111110111000;
    parameter [15:0] M_ROW_10 = 16'b1110011100111000;
    parameter [15:0] M_ROW_11 = 16'b1110011100111000;
    parameter [15:0] M_ROW_12 = 16'b0000000000000000;
    parameter [15:0] M_ROW_13 = 16'b0000000000000000;
    parameter [15:0] M_ROW_14 = 16'b0000000000000000;
    parameter [15:0] M_ROW_15 = 16'b0000000000000000;

    // U
    parameter [15:0] U_ROW_0  = 16'b0111000011100000;
    parameter [15:0] U_ROW_1  = 16'b0111000011100000;
    parameter [15:0] U_ROW_2  = 16'b0111000011100000;
    parameter [15:0] U_ROW_3  = 16'b0111000011100000;
    parameter [15:0] U_ROW_4  = 16'b0111000011100000;
    parameter [15:0] U_ROW_5  = 16'b0111000011100000;
    parameter [15:0] U_ROW_6  = 16'b0111000011100000;
    parameter [15:0] U_ROW_7  = 16'b0111000011100000;
    parameter [15:0] U_ROW_8  = 16'b0111000011100000;
    parameter [15:0] U_ROW_9  = 16'b0111000011100000;
    parameter [15:0] U_ROW_10 = 16'b0111100111000000;
    parameter [15:0] U_ROW_11 = 16'b0001111110000000;
    parameter [15:0] U_ROW_12 = 16'b0000000000000000;
    parameter [15:0] U_ROW_13 = 16'b0000000000000000;
    parameter [15:0] U_ROW_14 = 16'b0000000000000000;
    parameter [15:0] U_ROW_15 = 16'b0000000000000000;

    // S
    parameter [15:0] S_ROW_0  = 16'b0011111110000000;
    parameter [15:0] S_ROW_1  = 16'b0111000111000000;
    parameter [15:0] S_ROW_2  = 16'b0110000111000000;
    parameter [15:0] S_ROW_3  = 16'b1110000000000000;
    parameter [15:0] S_ROW_4  = 16'b0111100000000000;
    parameter [15:0] S_ROW_5  = 16'b0011111100000000;
    parameter [15:0] S_ROW_6  = 16'b0000111111000000;
    parameter [15:0] S_ROW_7  = 16'b0000000111000000;
    parameter [15:0] S_ROW_8  = 16'b0000000011100000;
    parameter [15:0] S_ROW_9  = 16'b1110000011000000;
    parameter [15:0] S_ROW_10 = 16'b0111000111000000;
    parameter [15:0] S_ROW_11 = 16'b0011111110000000;
    parameter [15:0] S_ROW_12 = 16'b0000000000000000;
    parameter [15:0] S_ROW_13 = 16'b0000000000000000;
    parameter [15:0] S_ROW_14 = 16'b0000000000000000;
    parameter [15:0] S_ROW_15 = 16'b0000000000000000;

    // T
    parameter [15:0] T_ROW_0  = 16'b1111111111000000;
    parameter [15:0] T_ROW_1  = 16'b0001110000000000;
    parameter [15:0] T_ROW_2  = 16'b0001110000000000;
    parameter [15:0] T_ROW_3  = 16'b0001110000000000;
    parameter [15:0] T_ROW_4  = 16'b0001110000000000;
    parameter [15:0] T_ROW_5  = 16'b0001110000000000;
    parameter [15:0] T_ROW_6  = 16'b0001110000000000;
    parameter [15:0] T_ROW_7  = 16'b0001110000000000;
    parameter [15:0] T_ROW_8  = 16'b0001110000000000;
    parameter [15:0] T_ROW_9  = 16'b0001110000000000;
    parameter [15:0] T_ROW_10 = 16'b0001110000000000;
    parameter [15:0] T_ROW_11 = 16'b0001110000000000;
    parameter [15:0] T_ROW_12 = 16'b0000000000000000;
    parameter [15:0] T_ROW_13 = 16'b0000000000000000;
    parameter [15:0] T_ROW_14 = 16'b0000000000000000;
    parameter [15:0] T_ROW_15 = 16'b0000000000000000;

    localparam M_X_START = 10'd100;
    localparam M_Y_START = 10'd208;

    localparam U_X_START = 10'd200;
    localparam U_Y_START = 10'd208;

    localparam S_X_START = 10'd300;
    localparam S_Y_START = 10'd208;

    localparam T_X_START = 10'd400;
    localparam T_Y_START = 10'd208;

    localparam BOX_WIDTH  = 10'd64;
    localparam BOX_HEIGHT = 10'd64;

    wire in_m_box = (pix_x >= M_X_START) && (pix_x < M_X_START + BOX_WIDTH) &&
                    (pix_y >= M_Y_START) && (pix_y < M_Y_START + BOX_HEIGHT);
    
    wire in_u_box = (pix_x >= U_X_START) && (pix_x < U_X_START + BOX_WIDTH) &&
                    (pix_y >= U_Y_START) && (pix_y < U_Y_START + BOX_HEIGHT);

    wire in_s_box = (pix_x >= S_X_START) && (pix_x < S_X_START + BOX_WIDTH) &&
                    (pix_y >= S_Y_START) && (pix_y < S_Y_START + BOX_HEIGHT);

    wire in_t_box = (pix_x >= T_X_START) && (pix_x < T_X_START + BOX_WIDTH) &&
                    (pix_y >= T_Y_START) && (pix_y < T_Y_START + BOX_HEIGHT);


    wire [3:0] m_char_y = (pix_y - M_Y_START) >> 2;
    wire [3:0] m_char_x = 4'd15 - ((pix_x - M_X_START) >> 2);
    
    wire [3:0] u_char_y = (pix_y - U_Y_START) >> 2;
    wire [3:0] u_char_x = 4'd15 - ((pix_x - U_X_START) >> 2);

    wire [3:0] s_char_y = (pix_y - S_Y_START) >> 2;
    wire [3:0] s_char_x = 4'd15 - ((pix_x - S_X_START) >> 2);

    wire [3:0] t_char_y = (pix_y - T_Y_START) >> 2;
    wire [3:0] t_char_x = 4'd15 - ((pix_x - T_X_START) >> 2);

    // color
    always @(posedge vga_clk or negedge sys_rst_n) begin
        if (!sys_rst_n) begin
            pix_data <= YELLOW;
        end 
        else if (in_m_box) begin
            case (m_char_y)
                4'd0: pix_data <= M_ROW_0[m_char_x] ? BLUE : YELLOW;
                4'd1: pix_data <= M_ROW_1[m_char_x] ? BLUE : YELLOW;
                4'd2: pix_data <= M_ROW_2[m_char_x] ? BLUE : YELLOW;
                4'd3: pix_data <= M_ROW_3[m_char_x] ? BLUE : YELLOW;
                4'd4: pix_data <= M_ROW_4[m_char_x] ? BLUE : YELLOW;
                4'd5: pix_data <= M_ROW_5[m_char_x] ? BLUE : YELLOW;
                4'd6: pix_data <= M_ROW_6[m_char_x] ? BLUE : YELLOW;
                4'd7: pix_data <= M_ROW_7[m_char_x] ? BLUE : YELLOW;
                4'd8: pix_data <= M_ROW_8[m_char_x] ? BLUE : YELLOW;
                4'd9: pix_data <= M_ROW_9[m_char_x] ? BLUE : YELLOW;
                4'd10: pix_data <= M_ROW_10[m_char_x] ? BLUE : YELLOW;
                4'd11: pix_data <= M_ROW_11[m_char_x] ? BLUE : YELLOW;
                4'd12: pix_data <= M_ROW_12[m_char_x] ? BLUE : YELLOW;
                4'd13: pix_data <= M_ROW_13[m_char_x] ? BLUE : YELLOW;
                4'd14: pix_data <= M_ROW_14[m_char_x] ? BLUE : YELLOW;
                4'd15: pix_data <= M_ROW_15[m_char_x] ? BLUE : YELLOW;
                default: pix_data <= YELLOW;
            endcase
        end 
        else if (in_u_box) begin
            case (u_char_y)
                4'd0: pix_data <= U_ROW_0[u_char_x] ? BLUE : YELLOW;
                4'd1: pix_data <= U_ROW_1[u_char_x] ? BLUE : YELLOW;
                4'd2: pix_data <= U_ROW_2[u_char_x] ? BLUE : YELLOW;
                4'd3: pix_data <= U_ROW_3[u_char_x] ? BLUE : YELLOW;
                4'd4: pix_data <= U_ROW_4[u_char_x] ? BLUE : YELLOW;
                4'd5: pix_data <= U_ROW_5[u_char_x] ? BLUE : YELLOW;
                4'd6: pix_data <= U_ROW_6[u_char_x] ? BLUE : YELLOW;
                4'd7: pix_data <= U_ROW_7[u_char_x] ? BLUE : YELLOW;
                4'd8: pix_data <= U_ROW_8[u_char_x] ? BLUE : YELLOW;
                4'd9: pix_data <= U_ROW_9[u_char_x] ? BLUE : YELLOW;
                4'd10: pix_data <= U_ROW_10[u_char_x] ? BLUE : YELLOW;
                4'd11: pix_data <= U_ROW_11[u_char_x] ? BLUE : YELLOW;
                4'd12: pix_data <= U_ROW_12[u_char_x] ? BLUE : YELLOW;
                4'd13: pix_data <= U_ROW_13[u_char_x] ? BLUE : YELLOW;
                4'd14: pix_data <= U_ROW_14[u_char_x] ? BLUE : YELLOW;
                4'd15: pix_data <= U_ROW_15[u_char_x] ? BLUE : YELLOW;
                default: pix_data <= YELLOW;
            endcase
        end
        else if (in_s_box) begin
            case (s_char_y)
                4'd0: pix_data <= S_ROW_0[s_char_x] ? BLUE : YELLOW;
                4'd1: pix_data <= S_ROW_1[s_char_x] ? BLUE : YELLOW;
                4'd2: pix_data <= S_ROW_2[s_char_x] ? BLUE : YELLOW;
                4'd3: pix_data <= S_ROW_3[s_char_x] ? BLUE : YELLOW;
                4'd4: pix_data <= S_ROW_4[s_char_x] ? BLUE : YELLOW;
                4'd5: pix_data <= S_ROW_5[s_char_x] ? BLUE : YELLOW;
                4'd6: pix_data <= S_ROW_6[s_char_x] ? BLUE : YELLOW;
                4'd7: pix_data <= S_ROW_7[s_char_x] ? BLUE : YELLOW;
                4'd8: pix_data <= S_ROW_8[s_char_x] ? BLUE : YELLOW;
                4'd9: pix_data <= S_ROW_9[s_char_x] ? BLUE : YELLOW;
                4'd10: pix_data <= S_ROW_10[s_char_x] ? BLUE : YELLOW;
                4'd11: pix_data <= S_ROW_11[s_char_x] ? BLUE : YELLOW;
                4'd12: pix_data <= S_ROW_12[s_char_x] ? BLUE : YELLOW;
                4'd13: pix_data <= S_ROW_13[s_char_x] ? BLUE : YELLOW;
                4'd14: pix_data <= S_ROW_14[s_char_x] ? BLUE : YELLOW;
                4'd15: pix_data <= S_ROW_15[s_char_x] ? BLUE : YELLOW;
                default: pix_data <= YELLOW;
            endcase
        end
        else if (in_t_box) begin
            case (t_char_y)
                4'd0: pix_data <= T_ROW_0[t_char_x] ? BLUE : YELLOW;
                4'd1: pix_data <= T_ROW_1[t_char_x] ? BLUE : YELLOW;
                4'd2: pix_data <= T_ROW_2[t_char_x] ? BLUE : YELLOW;
                4'd3: pix_data <= T_ROW_3[t_char_x] ? BLUE : YELLOW;
                4'd4: pix_data <= T_ROW_4[t_char_x] ? BLUE : YELLOW;
                4'd5: pix_data <= T_ROW_5[t_char_x] ? BLUE : YELLOW;
                4'd6: pix_data <= T_ROW_6[t_char_x] ? BLUE : YELLOW;
                4'd7: pix_data <= T_ROW_7[t_char_x] ? BLUE : YELLOW;
                4'd8: pix_data <= T_ROW_8[t_char_x] ? BLUE : YELLOW;
                4'd9: pix_data <= T_ROW_9[t_char_x] ? BLUE : YELLOW;
                4'd10: pix_data <= T_ROW_10[t_char_x] ? BLUE : YELLOW;
                4'd11: pix_data <= T_ROW_11[t_char_x] ? BLUE : YELLOW;
                4'd12: pix_data <= T_ROW_12[t_char_x] ? BLUE : YELLOW;
                4'd13: pix_data <= T_ROW_13[t_char_x] ? BLUE : YELLOW;
                4'd14: pix_data <= T_ROW_14[t_char_x] ? BLUE : YELLOW;
                4'd15: pix_data <= T_ROW_15[t_char_x] ? BLUE : YELLOW;
                default: pix_data <= YELLOW;
            endcase
        end
        else pix_data <= YELLOW;
    end

endmodule