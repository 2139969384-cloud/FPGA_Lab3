`timescale 1ns / 1ns

module VGA_pic_tb();
    reg vga_clk;
    reg sys_rst_n;
    reg [9:0] pix_x;
    reg [9:0] pix_y;
    
    wire [15:0] pix_data;

    VGA_pic dut (.vga_clk(vga_clk), .sys_rst_n(sys_rst_n), .pix_x(pix_x), .pix_y(pix_y), .pix_data  (pix_data));

    initial begin
        $dumpfile("VGA_pic_tb.vcd");
        $dumpvars(0, VGA_pic_tb);
    end

    initial begin
        vga_clk = 0;
        forever #20 vga_clk = ~vga_clk; 
    end

    initial begin
        sys_rst_n = 1;
        pix_x = 10'd0;
        pix_y = 10'd0;
        #20 sys_rst_n = 0;
        #20 sys_rst_n = 1;
    
        pix_x = 10'd99;
        pix_y = 10'd207; // outside M  

        #40;
        pix_x = 10'd100; // inside M
        pix_y = 10'd208;

        #40;
        pix_x = 10'd10; // screen
        pix_y = 10'd10;
    end

    initial begin
        #200 $finish;
    end

endmodule