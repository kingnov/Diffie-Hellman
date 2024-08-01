#include "dh_sw.h"

void dh_sw::process() {
    while (true) {
        wait(); // Wait for clock

        if (enable.read() == 1) {
            result1.write(operand1.read() * operand2.read());
            done.write(1);
        } else {
            done.write(0);
        }
    }
}
