/*
 * Filename: uncompress.cpp
 * Author: Alex Meza
 * Userid: cs100vbj
 * Description: encodes text file into another file
 * Date: August 9, 2016
 */

#include "HCTree.hpp"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	std::string name = "";

	//Check for Arguments
	if(argc != 3){
		cout << "Invalid number of arguments.\n" 
		     << "Usage: ./main <input filename>.\n";
		return -1;
	}

	//Open files
	ofstream os;
    ifstream is;
    os.open(argv[2], ios::out);//second file to write to
	is.open(argv[1], ios::binary);//first file to read from

	//Check if input file was opened
	if(!os.is_open()||!is.is_open()) 
	{
		cout<< "Invalid input file. No file was opened. Please try again.\n";
		return -1;
	}



    int i=0;
    std::vector<int> freq(256,0);//intialize vector with 256 postitions


    string line;//for reading characters
    int total = 0;
    int num;
    char ai[4];
    while(i<256){//for every line that holds a freq in is get it
        for(int j = 3;j>0;j--){
            ai[j]=is.get();
        }
        ai[0]=0;
        memcpy(&num,ai,sizeof(int)); 
        total +=freq[i]= num;//convert line to int to int        
        i++;
    }
    HCTree hct= HCTree();
    hct.build(freq); //build hctree
    

    int nextByte;
    int read = 0;
    BitInputStream in(is);

    while(read<total){//for each character in file
        read++; 

        os.put(hct.decode(in));//encode each character into os 
    }

    is.close();
    os.close();
    //close files
    return 0;


}
