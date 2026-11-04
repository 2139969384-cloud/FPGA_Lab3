`timescale 1ns / 1ns

module VGA_ctrl_tb();
    reg vga_clk;
    reg sys_rst_n;
    reg [15:0] pix_data;
    wire [9:0] pix_x;
    wire [9:0] pix_y;
    wire hsync;
    wire vsync;
    wire [15:0] rgb;

    VGA_ctrl dut (
        .vga_clk   (vga_clk),
        .sys_rst_n (sys_rst_n),
        .pix_data  (pix_data),
        .pix_x     (pix_x),
        .pix_y     (pix_y),
        .hsync     (hsync),
        .vsync     (vsync),
        .rgb       (rgb)
    );

    initial begin
        vga_clk = 0;
        forever #20 vga_clk = ~vga_clk; 
    end

    always @(*) begin
        if (pix_x < 10'd640 && pix_y < 10'd480) begin
            pix_data = 16'hF800; //red
        end 
        else begin
            pix_data = 16'h0000; //black
        end
    end

    initial begin
        $dumpfile("VGA_ctrl_tb.vcd");
        $dumpvars(0, VGA_ctrl_tb);
    end

    initial begin
        sys_rst_n = 0;
        #100 sys_rst_n = 1;
    end

    initial begin
        #1500000 $finish;
    end

endmodule