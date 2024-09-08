//
// Created by zxk on 5/18/23.
//

#ifndef OLVP_NODE_H
#define OLVP_NODE_H

#include "../../common.h"

using namespace std;

class AstNodeVisitor;


class Node
{
    string location;
    string NodeId;
public:
    Node(string location,string NodeId)
    {
        this->location = location;
        this->NodeId = NodeId;
    }

    string getLocation(){
        return this->location;
    }

    string getNodeId()
    {
        return this->NodeId;
    }

    virtual void* accept(AstNodeVisitor *visitor,void* context) {return NULL;}


    virtual vector<Node*> getChildren() = 0;

    virtual void addChilds(vector<Node*> nodes){}


};


#endif //OLVP_NODE_H
