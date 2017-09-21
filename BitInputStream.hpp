#ifndef BITINPUTSTREAM_HPP
#define BITINPUTSTREAM_HPP
#include <iostream>

class BitInputStream{

private:
    char buf;//one byte buffer of bits
    int nbits; //how many bits have been written
    std::istream& in;
    
public:
    
    /** Intialize a BitInputStream that will use
     * the given istream for input
     */
    BitInputStream(std::istream & is) : in(is), buf(0), nbits(8) {

        //buf = 0;
        //nbits = 8;

    }
    /**
     * gets next byte into buffer
     */

    void fill(){
        buf = in.get();
        nbits = 0;
    }

    /** Reade next bit from buffer fill the buffer from
     * input stream first if needed. return 1 if bit read is1
     * return 0 if bit read is 0
     */

    int readBit();
};

#endif
