`timescale 1ns / 1ns

module Top_tb();

    reg         sys_clk;
    reg         sys_rst_n;
    wire        hsync;
    wire        vsync;
    wire [15:0] rgb;

    Top dut (
        .sys_clk   (sys_clk),
        .sys_rst_n (sys_rst_n),
        .hsync     (hsync),
        .vsync     (vsync),
        .rgb       (rgb)
    );

     integer err_rst, err_clk, err_hs, err_vs;
    integer err_px, err_blank, err_mask, err_row, err_frm;
    integer total;

    initial begin
        err_rst = 0; err_clk = 0; err_hs = 0; err_vs = 0;
        err_px  = 0; err_blank = 0; err_mask = 0; err_row = 0; err_frm = 0;
    end

    initial begin
        sys_clk = 0;
        forever #10 sys_clk = ~sys_clk;
    end

    initial begin
        sys_rst_n = 0;
        #120 sys_rst_n = 1;
    end

        initial begin
        $dumpfile("Top_tb.vcd");
        $dumpvars(0, Top_tb);
        #70_000       $dumpoff;
        #7_704_000    $dumpon;
        #32_000       $dumpoff;
        #8_989_000    $dumpon;
        #20_000       $dumpoff;
        #16_775_000   $dumpon;
        #20_000       $dumpoff;
    end

       initial begin
        #100;
        if (rgb === 16'hFFE0)
            $display("[CHK] t=%0t ns  reset: rgb = %h (blanking colour, PASS)", $time, rgb);
        else begin
            err_rst = err_rst + 1;
            $display("[ERR] t=%0t ns  reset: rgb = %h (expect FFE0)", $time, rgb);
        end

        if (hsync === 1'b0 && vsync === 1'b0)
            $display("[CHK] t=%0t ns  reset: hsync = vsync = 0 (PASS)", $time);
        else begin
            err_rst = err_rst + 1;
            $display("[ERR] t=%0t ns  reset: hsync = %b, vsync = %b (expect 0,0)",
                     $time, hsync, vsync);
        end
    end

       time    t_vclk;
    integer n_vclk;

    initial begin
        t_vclk = 0;
        n_vclk = 0;
    end

    always @(posedge dut.vga_clk) begin
        if (n_vclk < 4) begin
            if (t_vclk != 0) begin
                if (($time - t_vclk) == 40)
                    $display("[CHK] t=%0t ns  vga_clk period = %0t ns (PASS)", $time, $time - t_vclk);
                else begin
                    err_clk = err_clk + 1;
                    $display("[ERR] t=%0t ns  vga_clk period = %0t ns (expect 40)",
                             $time, $time - t_vclk);
                end
            end
            t_vclk = $time;
            n_vclk = n_vclk + 1;
        end
    end

       time    t_hfall, t_vfall;
    integer n_hfall, n_vfall;

    initial begin
        t_hfall = 0; n_hfall = 0;
        t_vfall = 0; n_vfall = 0;
    end

    always @(negedge hsync) begin
        if (n_hfall < 6) begin
            if (t_hfall != 0) begin
                if (($time - t_hfall) == 32000)
                    $display("[CHK] t=%0t ns  hsync period = %0t ns (PASS)", $time, $time - t_hfall);
                else begin
                    err_hs = err_hs + 1;
                    $display("[ERR] t=%0t ns  hsync period = %0t ns (expect 32000)",
                             $time, $time - t_hfall);
                end
            end
            t_hfall = $time;
            n_hfall = n_hfall + 1;
        end
    end

    always @(posedge hsync) begin
        if (n_hfall >= 2 && n_hfall <= 5) begin
            if (($time - t_hfall) == 3840)
                $display("[CHK] t=%0t ns  hsync low width = %0t ns (PASS)", $time, $time - t_hfall);
            else begin
                err_hs = err_hs + 1;
                $display("[ERR] t=%0t ns  hsync low width = %0t ns (expect 3840)",
                         $time, $time - t_hfall);
            end
        end
    end

    always @(negedge vsync) begin
        if (n_vfall < 4) begin
            if (t_vfall != 0) begin
                if (($time - t_vfall) == 16_800_000)
                    $display("[CHK] t=%0t ns  vsync period = %0t ns (PASS)", $time, $time - t_vfall);
                else begin
                    err_vs = err_vs + 1;
                    $display("[ERR] t=%0t ns  vsync period = %0t ns (expect 16800000)",
                             $time, $time - t_vfall);
                end
            end
            t_vfall = $time;
            n_vfall = n_vfall + 1;
        end
    end

    always @(posedge vsync) begin
        if (n_vfall >= 2 && n_vfall <= 3) begin
            if (($time - t_vfall) == 64_000)
                $display("[CHK] t=%0t ns  vsync low width = %0t ns (PASS)", $time, $time - t_vfall);
            else begin
                err_vs = err_vs + 1;
                $display("[ERR] t=%0t ns  vsync low width = %0t ns (expect 64000)",
                         $time, $time - t_vfall);
            end
        end
    end

       parameter NPIX = 8;

    reg [9:0]  pb_x    [0:NPIX-1];
    reg [9:0]  pb_y    [0:NPIX-1];
    reg [15:0] pb_col  [0:NPIX-1];
    reg        pb_done [0:NPIX-1];

    integer ip, k, n_hit;

    initial begin
        pb_x[0] = 10'd100; pb_y[0] = 10'd208; pb_col[0] = 16'h001F; // M, row 0 col 0
        pb_x[1] = 10'd205; pb_y[1] = 10'd208; pb_col[1] = 16'h001F; // U, row 0 col 1
        pb_x[2] = 10'd308; pb_y[2] = 10'd208; pb_col[2] = 16'h001F; // S, row 0 col 2
        pb_x[3] = 10'd404; pb_y[3] = 10'd208; pb_col[3] = 16'h001F; // T, row 0 col 1
        pb_x[4] = 10'd 60; pb_y[4] = 10'd240; pb_col[4] = 16'hFFE0; // left of M
        pb_x[5] = 10'd370; pb_y[5] = 10'd240; pb_col[5] = 16'hFFE0; // between S and T
        pb_x[6] = 10'd500; pb_y[6] = 10'd240; pb_col[6] = 16'hFFE0; // right of T
        pb_x[7] = 10'd100; pb_y[7] = 10'd260; pb_col[7] = 16'hFFE0; // inside M box, empty row
        for (ip = 0; ip < NPIX; ip = ip + 1)
            pb_done[ip] = 1'b0;
    end

    always @(posedge dut.vga_clk) begin
        if (sys_rst_n === 1'b1 && dut.u_VGA_ctrl.rgb_valid === 1'b1) begin
            for (k = 0; k < NPIX; k = k + 1) begin
                if (pb_done[k] === 1'b0 &&
                    dut.u_VGA_ctrl.pix_x === (pb_x[k] + 10'd1) &&
                    dut.u_VGA_ctrl.pix_y === pb_y[k]) begin
                    pb_done[k] = 1'b1;
                    if (rgb === pb_col[k])
                        $display("[CHK] t=%0t ns  pixel (%0d,%0d) rgb = %h (PASS)",
                                 $time, pb_x[k], pb_y[k], rgb);
                    else begin
                        err_px = err_px + 1;
                        $display("[ERR] t=%0t ns  pixel (%0d,%0d) rgb = %h (expect %h)",
                                 $time, pb_x[k], pb_y[k], rgb, pb_col[k]);
                    end
                end
            end
        end
    end

       always @(posedge dut.vga_clk) begin
        if (sys_rst_n === 1'b1 && dut.u_VGA_ctrl.rgb_valid === 1'b0 && rgb !== 16'hFFE0) begin
            err_blank = err_blank + 1;
            if (err_blank <= 5)
                $display("[ERR] t=%0t ns  blanking: rgb = %h (expect FFE0)", $time, rgb);
        end
    end

        always @(posedge dut.vga_clk) begin
        if (sys_rst_n === 1'b1 && dut.u_VGA_ctrl.pix_data_req === 1'b0 &&
            (dut.u_VGA_ctrl.pix_x !== 10'h3ff || dut.u_VGA_ctrl.pix_y !== 10'h3ff)) begin
            err_mask = err_mask + 1;
            if (err_mask <= 5)
                $display("[ERR] t=%0t ns  masked coordinates: pix_x = %h, pix_y = %h (expect 3ff,3ff)",
                         $time, dut.u_VGA_ctrl.pix_x, dut.u_VGA_ctrl.pix_y);
        end
    end

      reg [9:0] y_d;

    always @(posedge dut.vga_clk or negedge sys_rst_n) begin
        if (!sys_rst_n) y_d <= 10'd0;
        else            y_d <= dut.u_VGA_ctrl.pix_y;
    end

    always @(posedge dut.vga_clk) begin
        if (sys_rst_n === 1'b1 && dut.u_VGA_ctrl.rgb_valid === 1'b1 &&
            (y_d < 10'd208 || y_d > 10'd271) && rgb !== 16'hFFE0) begin
            err_row = err_row + 1;
            if (err_row <= 5)
                $display("[ERR] t=%0t ns  row %0d has no bitmap, rgb = %h (expect FFE0)",
                         $time, y_d, rgb);
        end
    end

        integer blue_cnt, frames_done;

    initial begin
        blue_cnt    = 0;
        frames_done = 0;
    end

    always @(posedge dut.vga_clk) begin
        if (sys_rst_n === 1'b1 && dut.u_VGA_ctrl.rgb_valid === 1'b1 && rgb === 16'h001F)
            blue_cnt = blue_cnt + 1;
    end

    always @(negedge vsync) begin
        if (frames_done > 0) begin
            if (blue_cnt == 4784)
                $display("[CHK] frame %0d: blue pixel count = %0d (PASS)", frames_done, blue_cnt);
            else begin
                err_frm = err_frm + 1;
                $display("[ERR] frame %0d: blue pixel count = %0d (expect 4784)",
                         frames_done, blue_cnt);
            end
        end
        frames_done = frames_done + 1;
        blue_cnt    = 0;
    end

       initial begin
        #33_650_000;

        n_hit = 0;
        for (ip = 0; ip < NPIX; ip = ip + 1)
            if (pb_done[ip] === 1'b1) n_hit = n_hit + 1;
        if (n_hit != NPIX) begin
            err_px = err_px + (NPIX - n_hit);
            $display("[ERR] only %0d of %0d pixel probes were reached", n_hit, NPIX);
        end

        total = err_rst + err_clk + err_hs + err_vs + err_px +
                err_blank + err_mask + err_row + err_frm;

        $display("--------------------------------------------------------------");
        $display(" TOP TB SUMMARY, simulated %0t ns (two frames)", $time);
        $display("   reset behaviour         errors = %0d", err_rst);
        $display("   clock division          errors = %0d", err_clk);
        $display("   hsync / vsync timing    errors = %0d", err_hs + err_vs);
        $display("   pixel probes (%0d)        errors = %0d", NPIX, err_px);
        $display("   blanking invariant      errors = %0d", err_blank);
        $display("   coordinate masking      errors = %0d", err_mask);
        $display("   empty-row invariant     errors = %0d", err_row);
        $display("   frame blue count        errors = %0d", err_frm);
        $display("--------------------------------------------------------------");
        if (total == 0) $display(" RESULT: ALL CHECKS PASSED");
        else            $display(" RESULT: %0d ERROR(S)", total);
        $display("--------------------------------------------------------------");

        $finish;
    end

