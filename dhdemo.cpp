#include "systemc.h"
#include "dh_sw.h"
#include "dh_hw_mult.h"

typedef sc_uint<32> NN_DIGIT;

int sc_main(int argc, char* argv[]) {
    sc_core::sc_report_handler::set_actions("/IEEE_Std_1666/deprecated", sc_core::SC_DO_NOTHING);

    sc_signal<bool> clk;
    sc_signal<bool> enable;
    sc_signal<bool> done;
    sc_signal<NN_DIGIT> operand1;
    sc_signal<NN_DIGIT> operand2;
    sc_signal<NN_DIGIT> hw_result;
    sc_signal<NN_DIGIT> sw_result;

    dh_hw_mult hw_mult("HW_MULT");
    hw_mult.clk(clk);
    hw_mult.enable(enable);
    hw_mult.done(done);
    hw_mult.operand1(operand1);
    hw_mult.operand2(operand2);
    hw_mult.result1(hw_result);

    dh_sw sw("SW");
    sw.clk(clk);
    sw.enable(enable);
    sw.done(done);
    sw.operand1(operand1);
    sw.operand2(operand2);
    sw.result1(sw_result);

    // Initialize signals and start the simulation
    sc_start(0, SC_NS);

    // Your testbench code here, e.g., providing inputs and toggling the clock

    return 0;
}
