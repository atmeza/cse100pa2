
/*
 *
 * Filename: HCTree.cpp
 * Author: Alex Meza
 * Userid: cs100vbj
 * Description: HCTree implementation
 * Date : August 8, 2016
 */

#include "HCTree.hpp"
#include <vector>
#include <queue>
#include <string>

//constructor

HCTree::~HCTree(){
    
        clear(root); 
    }
/**
 * builds huffman tree 
 * @param: freqs - vector of ints
 * @return: void
 */

void HCTree::build(const vector<int>& freqs){

    //pq holds forest of nodes
    std::priority_queue<HCNode*, std::vector<HCNode*>, HCNodePtrComp> pq;

    int byte = 0;
    HCNode* temp;
    for(auto i : freqs){//for each frequency for byte i
        
        if(i>0){//if freq is more than 0 
           temp = new HCNode(i,byte, 0,0,0); 

            leaves.at(byte)= temp;//these nodes will be leaves
            pq.push(temp);// create node in tree
            
        }
        
        byte++;
    }

    while(pq.size()>1){//while more than one forest in priority queue
    
        HCNode* n1 = pq.top();//get smallest elements
        pq.pop();
        HCNode* n2 = pq.top();
        pq.pop();
        int total = n1->count +n2->count;//add frequencies of forest
        if(n1 <n2){
            temp = new HCNode(total,n1->symbol,n1,n2,0);
            
            pq.push(temp);
        }
        else{
            temp = new HCNode(total, n2->symbol,n1,n2,0);
            

            pq.push(temp);//push back on stack

        }

        n1->p = temp;
        n2->p = temp;

    }

   
    root = pq.top();//root is last node in pq



}



/**
 * encodes given byte and writes to file
 * @param: symbol- byte to encode, out - stream to write to
 * @return: void
 */

void HCTree::encode(byte symbol, BitOutputStream & out)const {

     std::deque<int> ec;
     
        
            
            HCNode* temp = leaves[(int)symbol];
            while(temp!=NULL&&temp->p){
               
                if(temp->p->c0==temp){//if coming from left s.t.
                    ec.push_front(0);
                }
                else
                {
                    ec.push_front(1);
                }
                temp = temp->p;

            }

     int i=0;
     for(;i<ec.size(); ){//for each pos until 0
       


        out.writeBit(ec.front());//write out character array in reverse
        ec.pop_front();
     }


    



}
void HCTree::encode(byte symbol, ofstream & out) const{

     std::deque<int> ec;
     
     for(auto hcn: leaves){
        
        if (hcn->symbol == symbol){
            
            HCNode* temp = hcn;
            while(temp->p){
               
                if(temp->p->c0==temp){//if coming from left s.t.
                    ec.push_front( '0');
                }
                else
                {
                    ec.push_front('1');
                }
                temp = temp->p;

            }
            break;
        }

     }
     int i=0;
     for(;i<ec.size(); ){//for each pos until 0
       


        out.put(ec.front());//write out character array in reverse
        ec.pop_front();
     }

}

int HCTree::decode(BitInputStream& in) const{

    int ret;
    HCNode* temp = root;// start at root 
    while(true){

        if(temp->c0==NULL&&temp->c1==NULL){
            return temp->symbol;
     }
     int symb = in.readBit();
        if(symb==0){//if directs to left subtree

            temp= temp->c0;//go to left subtree
        }
        else{
            temp = temp->c1;//go to right subtree

        }
    }
    return 0;
}


int HCTree::decode(ifstream& in) const{

    int ret;
    HCNode* temp = root;// start at root 
    HCNode* current = temp;
    while(true){
    
        char symb = (unsigned char)in.get();
        if(symb=='0'){//if directs to left subtree
            temp= temp->c0;//go to left subtree
        }
        else{
            temp = temp->c1;//go to right subtree

        }
        if(temp==0){
            ret = (int)current->symbol;//return symbol as an int      
            in.unget();
            break;

        }
        current = temp;
    }
    return ret;
}

/**
 * recursive method to help delete tree\
 * @param: node - node to delete
 * @return: void
 */

void HCTree::clear(HCNode* node){

    if(node){

        clear(node->c0);
        clear(node->c1);
        delete node;//clear node
        if(node->c0){

            node->c0=NULL;

        }
        if(node->c1!=NULL){node->c1= NULL;}//if theres a right node remove
        node = NULL;
    }

}










