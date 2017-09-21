#include "HCNode.hpp"



//compare HCNodes where smaller has higher priority
//if equal uses value of symbols
bool HCNode::operator<( HCNode const & other) {



    if(count != other.count)return count>other.count;

    return HCNode::symbol<other.symbol;
};








