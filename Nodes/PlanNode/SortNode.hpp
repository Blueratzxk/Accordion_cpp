//
// Created by zxk on 5/30/23.
//

#ifndef OLVP_SORTNODE_HPP
#define OLVP_SORTNODE_HPP


#include "../../Descriptor/SortDescriptor.hpp"

class SortNode : public PlanNode
{
    SortDescriptor desc;
    PlanNode *source;
public:

    SortNode (string id,SortDescriptor desc) :PlanNode("SortNode",id)
    {
        this->desc = desc;
    }

    SortDescriptor getSortDesc()
    {
        return this->desc;
    }


    void* accept(NodeVisitor* visitor,void* context)  {
        return visitor->VisitSortNode(this,context);
    }
    void addSource(PlanNode *node)
    {
        this->source = node;
    }
    void addSources(PlanNode *node){}
    PlanNode* getSource(){
        return this->source;
    }
    vector<PlanNode*> getSources(){
        vector<PlanNode*> sources{this->source};
        return sources;
    }
    string getId()
    {
        return PlanNode::getId();
    }


    PlanNode* replaceChildren(vector<PlanNode*> newChildren){
        SortNode *sort = new SortNode(this->getId(),this->getSortDesc());
        sort->addSource(newChildren[0]);
        return sort;
    }
};


#endif //OLVP_SORTNODE_HPP
