//
// Created by zxk on 5/30/23.
//

#ifndef OLVP_FILTERNODE_HPP
#define OLVP_FILTERNODE_HPP

#include "../../Descriptor/FilterDescriptor.hpp"

class NodeVisitor;
class FilterNode:public PlanNode
{
    FilterDescriptor fdesc;
    PlanNode *source;
public:

    FilterNode(string id,FilterDescriptor fdesc):PlanNode("FilterNode",id)
    {
        this->fdesc = fdesc;
    }

    void* accept(NodeVisitor* visitor,void*context)  {
        return visitor->VisitFilterNode(this,context);
    }

    FilterDescriptor getFilterDesc()
    {
        return this->fdesc;
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

    string getId ()
    {
        return PlanNode::getId();
    }

    PlanNode* replaceChildren(vector<PlanNode*> newChildren){
        FilterNode *filter = new FilterNode(this->getId(),this->getFilterDesc());
        filter->addSource(newChildren[0]);
        return filter;
    }



};




#endif //OLVP_FILTERNODE_HPP
