//
// Created by zxk on 5/30/23.
//

#ifndef OLVP_LOOKUPJOINNODE_HPP
#define OLVP_LOOKUPJOINNODE_HPP


#include "../../Descriptor/LookupJoinDescriptor.hpp"

class LookupJoinNode :public PlanNode
{

    LookupJoinDescriptor desc;
    PlanNode *probe;
    PlanNode *build;
public:


    LookupJoinNode(string id,LookupJoinDescriptor desc):PlanNode("LookupJoinNode",id)
    {
        this->desc = desc;
    }


    void* accept(NodeVisitor* visitor,void* context)  {
        return visitor->VisitLookupJoinNode(this,context);
    }
    void addProbe(PlanNode *node)
    {
        this->probe = node;
    }
    void addBuild(PlanNode *node)
    {
        this->build = node;
    }
    LookupJoinDescriptor getLookupJoinDescriptor()
    {
        return this->desc;
    }
    PlanNode* getProbe(){
        return this->probe;
    }
    PlanNode* getBuild(){
        return this->build;
    }
    void addSources(vector<PlanNode*> nodes)
    {
        if(nodes.size() != 2){cout << "hash join node need 2 source!" << endl;exit(0);}
        this->probe = nodes[0];
        this->build = nodes[1];
    }
    void addSources(PlanNode *node){}
    vector<PlanNode*> getSources(){
        vector<PlanNode*> sources{this->probe,this->build};
        return sources;
    }
    string getId()
    {
        return PlanNode::getId();
    }

    PlanNode* replaceChildren(vector<PlanNode*> newChildren){
        LookupJoinNode *hashJoin = new LookupJoinNode(this->getId(),this->desc);
        hashJoin-> addProbe(newChildren[0]);
        hashJoin->addBuild(newChildren[1]);
        return hashJoin;
    }
};







#endif //OLVP_LOOKUPJOINNODE_HPP
