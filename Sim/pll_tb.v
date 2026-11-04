`timescale 1ns / 1ns
module pll_tb;

reg sys_clk;
reg sys_rst_n;
wire vga_clk;

pll u_pll(
    .sys_clk(sys_clk),
    .sys_rst_n(sys_rst_n),
    .vga_clk(vga_clk)
);

initial begin
    sys_clk = 1'b0;
    forever #10 sys_clk = ~sys_clk;
end

initial begin
    sys_rst_n = 1'b0;
    #40 sys_rst_n = 1'b1;
    #200; 
    $finish;
end

initial begin
    $dumpfile("pll_tb.vcd");
    $dumpvars(0,pll_tb);
end

endmodule