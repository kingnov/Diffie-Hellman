#ifndef DH_HW_MULT_H
#define DH_HW_MULT_H

#include "systemc.h"

typedef sc_uint<32> NN_DIGIT;

SC_MODULE(dh_hw_mult) {
    // Ports
    sc_in<bool> clk;
    sc_in<bool> enable;
    sc_out<bool> done;
    sc_in<NN_DIGIT> operand1;
    sc_in<NN_DIGIT> operand2;
    sc_out<NN_DIGIT> result1;

    // Internal states
    enum states { WAIT, EXECUTE, OUTPUT, FINISH } state;

    SC_CTOR(dh_hw_mult) : state(WAIT) {
        SC_THREAD(process_mult);
        sensitive << clk.pos();
    }

    void process_mult();
};

#endif // DH_HW_MULT_H
