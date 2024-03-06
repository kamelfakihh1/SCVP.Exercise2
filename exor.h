#ifndef EXOR_H
#define EXOR_H

#include <systemc.h>

#include "nand.h"

// TODO: Insert your code here
SC_MODULE(exor)
{

    public:

    sc_in<bool> A, B;
    sc_out<bool> Z;

    nand a, b, c, d;
    sc_signal<bool> h1, h2, h3;

    SC_CTOR(exor) :
        A("A"), B("B"), Z("Z"),
        h1("h1"), h3("h3"), h2("h2"), 
        a("nand a"), b("nand b"), c("nand c"), d("nand d")  
    {        
        a.A.bind(A);
        a.B.bind(B);
        a.Z.bind(h1);

        b.A.bind(A);
        b.B.bind(h1);
        b.Z.bind(h2);

        c.A.bind(B);
        c.B.bind(h1);
        c.Z.bind(h3);

        d.A.bind(h2);
        d.B.bind(h3);
        d.Z.bind(Z);
    }    
};

#endif // EXOR_H
