#ifndef BITOUTPUTSTREAM_HPP
#define BITOUTPUTSTREAM_HPP
#include <iostream>

class BitOutputStream{

private:
    
    char buf;
    int nbits;  //how many bits have been written to buf
    std::ostream & out; //ref to output stream to use\

public:

    /**
     * Initialize a BitOutput Stream that will use
     * the given outstream for ouput
     */

    BitOutputStream(std::ostream& os) : out(os), buf(0), nbits(0) {
        //clear buffer and bit counter
    }


    //send the buffer to the output, and clear it

    void flush(){
        out.put(buf);
        out.flush();
        buf = nbits = 0;
    }
    

    /**
     * write the least significant bit of the arg to
     * the bit buffer, and increment the bit buffer index
     * flush the buffer first if it is full
     */

    void writeBit(int i);    
};
#endif
