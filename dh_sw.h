#ifndef DH_SW_H
#define DH_SW_H

#include "systemc.h"

typedef sc_uint<32> NN_DIGIT;

SC_MODULE(dh_sw) {
    // Ports
    sc_in<bool> clk;
    sc_in<bool> enable;
    sc_out<bool> done;
    sc_in<NN_DIGIT> operand1;
    sc_in<NN_DIGIT> operand2;
    sc_out<NN_DIGIT> result1;

    SC_CTOR(dh_sw) {
        SC_THREAD(process);
        sensitive << clk.pos();
    }

    void process();
};

#endif // DH_SW_H
