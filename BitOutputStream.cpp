#include "BitOutputStream.hpp"
/**
 * writes bit to buffer
 * @param i  - int to write to fill buffer in
 * @return - void
 */

void BitOutputStream::writeBit(int i){


    //if buffer is full
    
    if(nbits==8){

        flush();
    }
 buf = buf|(i<<(7-nbits));
 nbits++;
}
