#include "BitInputStream.hpp"


/** 
 * reads bit from file and returns an int 
 * @param: none
 * @return: int representation of the bit read in
 */

int BitInputStream::readBit(){
    
    if(nbits== 8){//if no bits to read
        fill();
     }

     int val = (buf>>(7-nbits))& 1;
     nbits++;

     return val;

}

