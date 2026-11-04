// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDevelopmentBoard.h for the primary calling header

#include "VDevelopmentBoard.h"
#include "VDevelopmentBoard__Syms.h"

//==========

void VDevelopmentBoard::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VDevelopmentBoard::eval\n"); );
    VDevelopmentBoard__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("DevelopmentBoard.v", 3, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VDevelopmentBoard::_eval_initial_loop(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("DevelopmentBoard.v", 3, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VDevelopmentBoard::_sequent__TOP__1(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_sequent__TOP__1\n"); );
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__vga_clk 
        = ((IData)(vlTOPp->B2) & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__vga_clk)));
}

VL_INLINE_OPT void VDevelopmentBoard::_sequent__TOP__3(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_sequent__TOP__3\n"); );
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    SData/*9:0*/ __Vdly__DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_h;
    SData/*9:0*/ __Vdly__DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_v;
    // Body
    __Vdly__DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_h 
        = vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_h;
    __Vdly__DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_v 
        = vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_v;
    if (vlTOPp->B2) {
        vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_data 
            = (((((0x64U <= (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x)) 
                  & (0xa4U > (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x))) 
                 & (0xd0U <= (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y))) 
                & (0x110U > (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y)))
                ? ((0x20U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                             - (IData)(0xd0U))) ? (
                                                   (0x10U 
                                                    & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                                       - (IData)(0xd0U)))
                                                    ? 0xffe0U
                                                    : 
                                                   ((8U 
                                                     & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                                        - (IData)(0xd0U)))
                                                     ? 
                                                    ((4U 
                                                      & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                                         - (IData)(0xd0U)))
                                                      ? 
                                                     ((1U 
                                                       & (0xe738U 
                                                          >> 
                                                          (0xfU 
                                                           & ((IData)(0xfU) 
                                                              - 
                                                              (0xffU 
                                                               & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                                   - (IData)(0x64U)) 
                                                                  >> 2U))))))
                                                       ? 0x1fU
                                                       : 0xffe0U)
                                                      : 
                                                     ((1U 
                                                       & (0xe738U 
                                                          >> 
                                                          (0xfU 
                                                           & ((IData)(0xfU) 
                                                              - 
                                                              (0xffU 
                                                               & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                                   - (IData)(0x64U)) 
                                                                  >> 2U))))))
                                                       ? 0x1fU
                                                       : 0xffe0U))
                                                     : 
                                                    ((4U 
                                                      & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                                         - (IData)(0xd0U)))
                                                      ? 
                                                     ((1U 
                                                       & (0xefb8U 
                                                          >> 
                                                          (0xfU 
                                                           & ((IData)(0xfU) 
                                                              - 
                                                              (0xffU 
                                                               & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                                   - (IData)(0x64U)) 
                                                                  >> 2U))))))
                                                       ? 0x1fU
                                                       : 0xffe0U)
                                                      : 
                                                     ((1U 
                                                       & (0xefb8U 
                                                          >> 
                                                          (0xfU 
                                                           & ((IData)(0xfU) 
                                                              - 
                                                              (0xffU 
                                                               & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                                   - (IData)(0x64U)) 
                                                                  >> 2U))))))
                                                       ? 0x1fU
                                                       : 0xffe0U))))
                    : ((0x10U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                 - (IData)(0xd0U)))
                        ? ((8U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                  - (IData)(0xd0U)))
                            ? ((4U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                      - (IData)(0xd0U)))
                                ? ((1U & (0xefb8U >> 
                                          (0xfU & ((IData)(0xfU) 
                                                   - 
                                                   (0xffU 
                                                    & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                        - (IData)(0x64U)) 
                                                       >> 2U))))))
                                    ? 0x1fU : 0xffe0U)
                                : ((1U & (0xfdf8U >> 
                                          (0xfU & ((IData)(0xfU) 
                                                   - 
                                                   (0xffU 
                                                    & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                        - (IData)(0x64U)) 
                                                       >> 2U))))))
                                    ? 0x1fU : 0xffe0U))
                            : ((4U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                      - (IData)(0xd0U)))
                                ? ((1U & (0xfdf8U >> 
                                          (0xfU & ((IData)(0xfU) 
                                                   - 
                                                   (0xffU 
                                                    & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                        - (IData)(0x64U)) 
                                                       >> 2U))))))
                                    ? 0x1fU : 0xffe0U)
                                : ((1U & (0xfcf8U >> 
                                          (0xfU & ((IData)(0xfU) 
                                                   - 
                                                   (0xffU 
                                                    & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                        - (IData)(0x64U)) 
                                                       >> 2U))))))
                                    ? 0x1fU : 0xffe0U)))
                        : ((8U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                  - (IData)(0xd0U)))
                            ? ((4U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                      - (IData)(0xd0U)))
                                ? ((1U & (0xf8f8U >> 
                                          (0xfU & ((IData)(0xfU) 
                                                   - 
                                                   (0xffU 
                                                    & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                        - (IData)(0x64U)) 
                                                       >> 2U))))))
                                    ? 0x1fU : 0xffe0U)
                                : ((1U & (0xf8f8U >> 
                                          (0xfU & ((IData)(0xfU) 
                                                   - 
                                                   (0xffU 
                                                    & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                        - (IData)(0x64U)) 
                                                       >> 2U))))))
                                    ? 0x1fU : 0xffe0U))
                            : ((4U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                      - (IData)(0xd0U)))
                                ? ((1U & (0xf878U >> 
                                          (0xfU & ((IData)(0xfU) 
                                                   - 
                                                   (0xffU 
                                                    & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                        - (IData)(0x64U)) 
                                                       >> 2U))))))
                                    ? 0x1fU : 0xffe0U)
                                : ((1U & (0xf038U >> 
                                          (0xfU & ((IData)(0xfU) 
                                                   - 
                                                   (0xffU 
                                                    & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                        - (IData)(0x64U)) 
                                                       >> 2U))))))
                                    ? 0x1fU : 0xffe0U)))))
                : (((((0xc8U <= (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x)) 
                      & (0x108U > (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x))) 
                     & (0xd0U <= (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y))) 
                    & (0x110U > (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y)))
                    ? ((0x20U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                 - (IData)(0xd0U)))
                        ? ((0x10U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                     - (IData)(0xd0U)))
                            ? 0xffe0U : ((8U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                                - (IData)(0xd0U)))
                                          ? ((4U & 
                                              ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                               - (IData)(0xd0U)))
                                              ? ((1U 
                                                  & (0x1f80U 
                                                     >> 
                                                     (0xfU 
                                                      & ((IData)(0xfU) 
                                                         - 
                                                         (0xffU 
                                                          & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                              - (IData)(0xc8U)) 
                                                             >> 2U))))))
                                                  ? 0x1fU
                                                  : 0xffe0U)
                                              : ((1U 
                                                  & (0x79c0U 
                                                     >> 
                                                     (0xfU 
                                                      & ((IData)(0xfU) 
                                                         - 
                                                         (0xffU 
                                                          & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                              - (IData)(0xc8U)) 
                                                             >> 2U))))))
                                                  ? 0x1fU
                                                  : 0xffe0U))
                                          : ((4U & 
                                              ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                               - (IData)(0xd0U)))
                                              ? ((1U 
                                                  & (0x70e0U 
                                                     >> 
                                                     (0xfU 
                                                      & ((IData)(0xfU) 
                                                         - 
                                                         (0xffU 
                                                          & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                              - (IData)(0xc8U)) 
                                                             >> 2U))))))
                                                  ? 0x1fU
                                                  : 0xffe0U)
                                              : ((1U 
                                                  & (0x70e0U 
                                                     >> 
                                                     (0xfU 
                                                      & ((IData)(0xfU) 
                                                         - 
                                                         (0xffU 
                                                          & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                              - (IData)(0xc8U)) 
                                                             >> 2U))))))
                                                  ? 0x1fU
                                                  : 0xffe0U))))
                        : ((0x10U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                     - (IData)(0xd0U)))
                            ? ((8U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                      - (IData)(0xd0U)))
                                ? ((4U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                          - (IData)(0xd0U)))
                                    ? ((1U & (0x70e0U 
                                              >> (0xfU 
                                                  & ((IData)(0xfU) 
                                                     - 
                                                     (0xffU 
                                                      & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                          - (IData)(0xc8U)) 
                                                         >> 2U))))))
                                        ? 0x1fU : 0xffe0U)
                                    : ((1U & (0x70e0U 
                                              >> (0xfU 
                                                  & ((IData)(0xfU) 
                                                     - 
                                                     (0xffU 
                                                      & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                          - (IData)(0xc8U)) 
                                                         >> 2U))))))
                                        ? 0x1fU : 0xffe0U))
                                : ((4U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                          - (IData)(0xd0U)))
                                    ? ((1U & (0x70e0U 
                                              >> (0xfU 
                                                  & ((IData)(0xfU) 
                                                     - 
                                                     (0xffU 
                                                      & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                          - (IData)(0xc8U)) 
                                                         >> 2U))))))
                                        ? 0x1fU : 0xffe0U)
                                    : ((1U & (0x70e0U 
                                              >> (0xfU 
                                                  & ((IData)(0xfU) 
                                                     - 
                                                     (0xffU 
                                                      & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                          - (IData)(0xc8U)) 
                                                         >> 2U))))))
                                        ? 0x1fU : 0xffe0U)))
                            : ((8U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                      - (IData)(0xd0U)))
                                ? ((4U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                          - (IData)(0xd0U)))
                                    ? ((1U & (0x70e0U 
                                              >> (0xfU 
                                                  & ((IData)(0xfU) 
                                                     - 
                                                     (0xffU 
                                                      & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                          - (IData)(0xc8U)) 
                                                         >> 2U))))))
                                        ? 0x1fU : 0xffe0U)
                                    : ((1U & (0x70e0U 
                                              >> (0xfU 
                                                  & ((IData)(0xfU) 
                                                     - 
                                                     (0xffU 
                                                      & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                          - (IData)(0xc8U)) 
                                                         >> 2U))))))
                                        ? 0x1fU : 0xffe0U))
                                : ((4U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                          - (IData)(0xd0U)))
                                    ? ((1U & (0x70e0U 
                                              >> (0xfU 
                                                  & ((IData)(0xfU) 
                                                     - 
                                                     (0xffU 
                                                      & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                          - (IData)(0xc8U)) 
                                                         >> 2U))))))
                                        ? 0x1fU : 0xffe0U)
                                    : ((1U & (0x70e0U 
                                              >> (0xfU 
                                                  & ((IData)(0xfU) 
                                                     - 
                                                     (0xffU 
                                                      & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                          - (IData)(0xc8U)) 
                                                         >> 2U))))))
                                        ? 0x1fU : 0xffe0U)))))
                    : (((((0x12cU <= (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x)) 
                          & (0x16cU > (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x))) 
                         & (0xd0U <= (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y))) 
                        & (0x110U > (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y)))
                        ? ((0x20U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                     - (IData)(0xd0U)))
                            ? ((0x10U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                         - (IData)(0xd0U)))
                                ? 0xffe0U : ((8U & 
                                              ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                               - (IData)(0xd0U)))
                                              ? ((4U 
                                                  & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                                     - (IData)(0xd0U)))
                                                  ? 
                                                 ((1U 
                                                   & (0x3f80U 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(0xfU) 
                                                          - 
                                                          (0xffU 
                                                           & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                               - (IData)(0x12cU)) 
                                                              >> 2U))))))
                                                   ? 0x1fU
                                                   : 0xffe0U)
                                                  : 
                                                 ((1U 
                                                   & (0x71c0U 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(0xfU) 
                                                          - 
                                                          (0xffU 
                                                           & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                               - (IData)(0x12cU)) 
                                                              >> 2U))))))
                                                   ? 0x1fU
                                                   : 0xffe0U))
                                              : ((4U 
                                                  & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                                     - (IData)(0xd0U)))
                                                  ? 
                                                 ((1U 
                                                   & (0xe0c0U 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(0xfU) 
                                                          - 
                                                          (0xffU 
                                                           & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                               - (IData)(0x12cU)) 
                                                              >> 2U))))))
                                                   ? 0x1fU
                                                   : 0xffe0U)
                                                  : 
                                                 ((1U 
                                                   & (0xe0U 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(0xfU) 
                                                          - 
                                                          (0xffU 
                                                           & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                               - (IData)(0x12cU)) 
                                                              >> 2U))))))
                                                   ? 0x1fU
                                                   : 0xffe0U))))
                            : ((0x10U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                         - (IData)(0xd0U)))
                                ? ((8U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                          - (IData)(0xd0U)))
                                    ? ((4U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                              - (IData)(0xd0U)))
                                        ? ((1U & (0x1c0U 
                                                  >> 
                                                  (0xfU 
                                                   & ((IData)(0xfU) 
                                                      - 
                                                      (0xffU 
                                                       & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                           - (IData)(0x12cU)) 
                                                          >> 2U))))))
                                            ? 0x1fU
                                            : 0xffe0U)
                                        : ((1U & (0xfc0U 
                                                  >> 
                                                  (0xfU 
                                                   & ((IData)(0xfU) 
                                                      - 
                                                      (0xffU 
                                                       & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                           - (IData)(0x12cU)) 
                                                          >> 2U))))))
                                            ? 0x1fU
                                            : 0xffe0U))
                                    : ((4U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                              - (IData)(0xd0U)))
                                        ? ((1U & (0x3f00U 
                                                  >> 
                                                  (0xfU 
                                                   & ((IData)(0xfU) 
                                                      - 
                                                      (0xffU 
                                                       & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                           - (IData)(0x12cU)) 
                                                          >> 2U))))))
                                            ? 0x1fU
                                            : 0xffe0U)
                                        : ((1U & (0x7800U 
                                                  >> 
                                                  (0xfU 
                                                   & ((IData)(0xfU) 
                                                      - 
                                                      (0xffU 
                                                       & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                           - (IData)(0x12cU)) 
                                                          >> 2U))))))
                                            ? 0x1fU
                                            : 0xffe0U)))
                                : ((8U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                          - (IData)(0xd0U)))
                                    ? ((4U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                              - (IData)(0xd0U)))
                                        ? ((1U & (0xe000U 
                                                  >> 
                                                  (0xfU 
                                                   & ((IData)(0xfU) 
                                                      - 
                                                      (0xffU 
                                                       & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                           - (IData)(0x12cU)) 
                                                          >> 2U))))))
                                            ? 0x1fU
                                            : 0xffe0U)
                                        : ((1U & (0x61c0U 
                                                  >> 
                                                  (0xfU 
                                                   & ((IData)(0xfU) 
                                                      - 
                                                      (0xffU 
                                                       & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                           - (IData)(0x12cU)) 
                                                          >> 2U))))))
                                            ? 0x1fU
                                            : 0xffe0U))
                                    : ((4U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                              - (IData)(0xd0U)))
                                        ? ((1U & (0x71c0U 
                                                  >> 
                                                  (0xfU 
                                                   & ((IData)(0xfU) 
                                                      - 
                                                      (0xffU 
                                                       & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                           - (IData)(0x12cU)) 
                                                          >> 2U))))))
                                            ? 0x1fU
                                            : 0xffe0U)
                                        : ((1U & (0x3f80U 
                                                  >> 
                                                  (0xfU 
                                                   & ((IData)(0xfU) 
                                                      - 
                                                      (0xffU 
                                                       & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                           - (IData)(0x12cU)) 
                                                          >> 2U))))))
                                            ? 0x1fU
                                            : 0xffe0U)))))
                        : (((((0x190U <= (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x)) 
                              & (0x1d0U > (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x))) 
                             & (0xd0U <= (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y))) 
                            & (0x110U > (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y)))
                            ? ((0x20U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                         - (IData)(0xd0U)))
                                ? ((0x10U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                             - (IData)(0xd0U)))
                                    ? 0xffe0U : ((8U 
                                                  & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                                     - (IData)(0xd0U)))
                                                  ? 
                                                 ((4U 
                                                   & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                                      - (IData)(0xd0U)))
                                                   ? 
                                                  ((1U 
                                                    & (0x1c00U 
                                                       >> 
                                                       (0xfU 
                                                        & ((IData)(0xfU) 
                                                           - 
                                                           (0xffU 
                                                            & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                                - (IData)(0x190U)) 
                                                               >> 2U))))))
                                                    ? 0x1fU
                                                    : 0xffe0U)
                                                   : 
                                                  ((1U 
                                                    & (0x1c00U 
                                                       >> 
                                                       (0xfU 
                                                        & ((IData)(0xfU) 
                                                           - 
                                                           (0xffU 
                                                            & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                                - (IData)(0x190U)) 
                                                               >> 2U))))))
                                                    ? 0x1fU
                                                    : 0xffe0U))
                                                  : 
                                                 ((4U 
                                                   & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                                      - (IData)(0xd0U)))
                                                   ? 
                                                  ((1U 
                                                    & (0x1c00U 
                                                       >> 
                                                       (0xfU 
                                                        & ((IData)(0xfU) 
                                                           - 
                                                           (0xffU 
                                                            & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                                - (IData)(0x190U)) 
                                                               >> 2U))))))
                                                    ? 0x1fU
                                                    : 0xffe0U)
                                                   : 
                                                  ((1U 
                                                    & (0x1c00U 
                                                       >> 
                                                       (0xfU 
                                                        & ((IData)(0xfU) 
                                                           - 
                                                           (0xffU 
                                                            & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                                - (IData)(0x190U)) 
                                                               >> 2U))))))
                                                    ? 0x1fU
                                                    : 0xffe0U))))
                                : ((0x10U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                             - (IData)(0xd0U)))
                                    ? ((8U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                              - (IData)(0xd0U)))
                                        ? ((4U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                                  - (IData)(0xd0U)))
                                            ? ((1U 
                                                & (0x1c00U 
                                                   >> 
                                                   (0xfU 
                                                    & ((IData)(0xfU) 
                                                       - 
                                                       (0xffU 
                                                        & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                            - (IData)(0x190U)) 
                                                           >> 2U))))))
                                                ? 0x1fU
                                                : 0xffe0U)
                                            : ((1U 
                                                & (0x1c00U 
                                                   >> 
                                                   (0xfU 
                                                    & ((IData)(0xfU) 
                                                       - 
                                                       (0xffU 
                                                        & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                            - (IData)(0x190U)) 
                                                           >> 2U))))))
                                                ? 0x1fU
                                                : 0xffe0U))
                                        : ((4U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                                  - (IData)(0xd0U)))
                                            ? ((1U 
                                                & (0x1c00U 
                                                   >> 
                                                   (0xfU 
                                                    & ((IData)(0xfU) 
                                                       - 
                                                       (0xffU 
                                                        & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                            - (IData)(0x190U)) 
                                                           >> 2U))))))
                                                ? 0x1fU
                                                : 0xffe0U)
                                            : ((1U 
                                                & (0x1c00U 
                                                   >> 
                                                   (0xfU 
                                                    & ((IData)(0xfU) 
                                                       - 
                                                       (0xffU 
                                                        & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                            - (IData)(0x190U)) 
                                                           >> 2U))))))
                                                ? 0x1fU
                                                : 0xffe0U)))
                                    : ((8U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                              - (IData)(0xd0U)))
                                        ? ((4U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                                  - (IData)(0xd0U)))
                                            ? ((1U 
                                                & (0x1c00U 
                                                   >> 
                                                   (0xfU 
                                                    & ((IData)(0xfU) 
                                                       - 
                                                       (0xffU 
                                                        & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                            - (IData)(0x190U)) 
                                                           >> 2U))))))
                                                ? 0x1fU
                                                : 0xffe0U)
                                            : ((1U 
                                                & (0x1c00U 
                                                   >> 
                                                   (0xfU 
                                                    & ((IData)(0xfU) 
                                                       - 
                                                       (0xffU 
                                                        & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                            - (IData)(0x190U)) 
                                                           >> 2U))))))
                                                ? 0x1fU
                                                : 0xffe0U))
                                        : ((4U & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y) 
                                                  - (IData)(0xd0U)))
                                            ? ((1U 
                                                & (0x1c00U 
                                                   >> 
                                                   (0xfU 
                                                    & ((IData)(0xfU) 
                                                       - 
                                                       (0xffU 
                                                        & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                            - (IData)(0x190U)) 
                                                           >> 2U))))))
                                                ? 0x1fU
                                                : 0xffe0U)
                                            : ((1U 
                                                & (0xffc0U 
                                                   >> 
                                                   (0xfU 
                                                    & ((IData)(0xfU) 
                                                       - 
                                                       (0xffU 
                                                        & (((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x) 
                                                            - (IData)(0x190U)) 
                                                           >> 2U))))))
                                                ? 0x1fU
                                                : 0xffe0U)))))
                            : 0xffe0U))));
        __Vdly__DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_h 
            = ((0x31fU == (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_h))
                ? 0U : (0x3ffU & ((IData)(1U) + (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_h))));
    } else {
        vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_data = 0xffe0U;
        __Vdly__DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_h = 0U;
    }
    if (vlTOPp->B2) {
        if (((0x20cU == (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_v)) 
             & (0x31fU == (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_h)))) {
            __Vdly__DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_v = 0U;
        } else {
            if ((0x31fU == (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_h))) {
                __Vdly__DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_v 
                    = (0x3ffU & ((IData)(1U) + (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_v)));
            }
        }
    } else {
        __Vdly__DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_v = 0U;
    }
    vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_h 
        = __Vdly__DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_h;
    vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_v 
        = __Vdly__DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_v;
    vlTOPp->h_sync = (0x60U <= (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_h));
    vlTOPp->v_sync = (2U <= (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_v));
    vlTOPp->rgb = (((((0x90U <= (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_h)) 
                      & (0x310U > (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_h))) 
                     & (0x23U <= (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_v))) 
                    & (0x203U > (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_v)))
                    ? (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_data)
                    : 0xffe0U);
    vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__pix_data_req 
        = ((((0x8fU <= (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_h)) 
             & (0x30fU > (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_h))) 
            & (0x23U <= (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_v))) 
           & (0x203U > (IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_v)));
    if (vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__pix_data_req) {
        vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x 
            = (0x3ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_h) 
                         - (IData)(0x8fU)));
        vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y 
            = (0x3ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__u_VGA_ctrl__DOT__cnt_v) 
                         - (IData)(0x23U)));
    } else {
        vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_x = 0x3ffU;
        vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__pix_y = 0x3ffU;
    }
}

void VDevelopmentBoard::_eval(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_eval\n"); );
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((~ (IData)(vlTOPp->B2)) & (IData)(vlTOPp->__Vclklast__TOP__B2)) 
         | ((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    if ((((~ (IData)(vlTOPp->B2)) & (IData)(vlTOPp->__Vclklast__TOP__B2)) 
         | ((IData)(vlTOPp->__VinpClk__TOP__DevelopmentBoard__DOT__Top_inst__DOT__vga_clk) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__DevelopmentBoard__DOT__Top_inst__DOT__vga_clk))))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__B2 = vlTOPp->B2;
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__DevelopmentBoard__DOT__Top_inst__DOT__vga_clk 
        = vlTOPp->__VinpClk__TOP__DevelopmentBoard__DOT__Top_inst__DOT__vga_clk;
    vlTOPp->__VinpClk__TOP__DevelopmentBoard__DOT__Top_inst__DOT__vga_clk 
        = vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__vga_clk;
}

VL_INLINE_OPT QData VDevelopmentBoard::_change_request(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_change_request\n"); );
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VDevelopmentBoard::_change_request_1(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_change_request_1\n"); );
    VDevelopmentBoard* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__vga_clk ^ vlTOPp->__Vchglast__TOP__DevelopmentBoard__DOT__Top_inst__DOT__vga_clk));
    VL_DEBUG_IF( if(__req && ((vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__vga_clk ^ vlTOPp->__Vchglast__TOP__DevelopmentBoard__DOT__Top_inst__DOT__vga_clk))) VL_DBG_MSGF("        CHANGE: /media/sf_ShareFolder/Project/Lab3/RTL/Top.v:11: DevelopmentBoard.Top_inst.vga_clk\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__DevelopmentBoard__DOT__Top_inst__DOT__vga_clk 
        = vlTOPp->DevelopmentBoard__DOT__Top_inst__DOT__vga_clk;
    return __req;
}

#ifdef VL_DEBUG
void VDevelopmentBoard::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((B2 & 0xfeU))) {
        Verilated::overWidthError("B2");}
    if (VL_UNLIKELY((B3 & 0xfeU))) {
        Verilated::overWidthError("B3");}
    if (VL_UNLIKELY((B4 & 0xfeU))) {
        Verilated::overWidthError("B4");}
    if (VL_UNLIKELY((B5 & 0xfeU))) {
        Verilated::overWidthError("B5");}
}
#endif  // VL_DEBUG
