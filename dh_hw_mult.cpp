#include "dh_hw_mult.h"

void dh_hw_mult::process_mult() {
    while (true) {
        wait(); // Wait for clock

        switch (state) {
            case WAIT:
                if (enable.read() == 1) {
                    state = EXECUTE;
                }
                break;

            case EXECUTE:
                // Perform the multiplication
                result1.write(operand1.read() * operand2.read());
                state = OUTPUT;
                break;

            case OUTPUT:
                done.write(1); // Assert done signal
                state = FINISH;
                break;

            case FINISH:
                if (enable.read() == 0) {
                    done.write(0); // Deassert done signal
                    state = WAIT;
                }
                break;

            default:
                state = WAIT;
                break;
        }
    }
}
