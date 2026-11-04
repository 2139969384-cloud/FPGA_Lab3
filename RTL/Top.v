`timescale 1ns / 1ns

module Top (
    input sys_clk,
    input sys_rst_n,
    output hsync,
    output vsync,
    output wire [15:0] rgb
);

    wire vga_clk;
    wire [9:0] pix_x;
    wire [9:0] pix_y;
    wire [15:0] pix_data;

    pll u_pll (.sys_clk(sys_clk), .sys_rst_n (sys_rst_n), .vga_clk(vga_clk));

    VGA_ctrl u_VGA_ctrl (
        .vga_clk(vga_clk), .sys_rst_n (sys_rst_n),
        .pix_x(pix_x), .pix_y(pix_y), .pix_data (pix_data),
        .hsync(hsync), .vsync(vsync), .rgb(rgb)
    );

    VGA_pic u_VGA_pic (
        .vga_clk(vga_clk), .sys_rst_n(sys_rst_n),
        .pix_x(pix_x),.pix_y(pix_y),.pix_data(pix_data)
    );

endmodule