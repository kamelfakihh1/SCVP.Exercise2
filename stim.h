#ifndef STIMULUS_H
#define STIMULUS_H

#include <systemc.h>

SC_MODULE(stim)
{
public:
    sc_out<bool> A, B;
    sc_in<bool> clk;

    SC_CTOR(stim) : clk("clk")
    {
        SC_THREAD(StimGen);
        sensitive << clk.pos();
    }

private:
    void StimGen()
    {
        // wait(SC_ZERO_TIME);
        wait();
        A.write(false);
        B.write(false);
        // wait(10, SC_NS);
        wait();
        A.write(false);
        B.write(true);
        // wait(15, SC_NS);
        wait();
        A.write(true);
        B.write(false);
        // wait(10, SC_NS);
        wait();
        A.write(true);
        B.write(true);
        // wait(10, SC_NS);
        wait();
        A.write(false);
        B.write(false);
        // wait(10, SC_NS);
        wait();
        sc_stop();
    }
};

#endif
