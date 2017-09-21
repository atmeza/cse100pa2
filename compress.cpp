/*
 * Filename: compress.cpp
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
    os.open(argv[2], ios::binary);//second file to write to
	is.open(argv[1], ios::binary);//first file to read from

	//Check if input file was opened
	if(!os.is_open()||!is.is_open()) 
	{
		cout<< "Invalid input file. No file was opened. Please try again.\n";
		return -1;
	}



    int i;
    std::vector<int> freq(256,0);//intialize vector with 256 postitions


    int nextByte;
    
    while((nextByte = is.get())!=EOF){
      
        freq[nextByte]++;//increment count of each character found in freq        

    }
    HCTree hct= HCTree();
    hct.build(freq); //build hctree
    
    is.clear();//clear eof flag
    is.seekg(0,ios::beg);//point back to beginning of file


    char temp[3];
    //write out frequencies first
    for(i = 0;i<256;i++){

        memcpy(&temp, (&freq[i])+1, sizeof(temp));
        os<< temp ;
    }
    BitOutputStream out(os);
    int count = 0;

    while((nextByte=is.get())!=EOF){//for each character in file
         
       
        hct.encode(nextByte,out);//encode each character into os 
        count++;
    }
    is.close();
    out.flush();
    os.close();
    //close files
    return 0;


}





