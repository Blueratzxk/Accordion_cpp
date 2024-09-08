//
// Created by zxk on 5/30/23.
//

#ifndef OLVP_FINALAGGREGATIONNODE_HPP
#define OLVP_FINALAGGREGATIONNODE_HPP

#include "../../Descriptor/AggregationDescriptor.hpp"

class FinalAggregationNode : public PlanNode
{


    AggregationDesc desc;
    PlanNode *source;
public:


    FinalAggregationNode(string id,AggregationDesc desc):PlanNode("FinalAggregationNode",id) {
        this->desc = desc;
    }

    void* accept(NodeVisitor* visitor,void *context)  {
        return visitor->VisitFinalAggregationNode(this,context);
    }

    AggregationDesc getAggregationDesc()
    {
        return this->desc;
    }


    string getId()
    {
        return PlanNode::getId();
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
    PlanNode* replaceChildren(vector<PlanNode*> newChildren){
        FinalAggregationNode *fagg = new FinalAggregationNode(this->getId(),this->getAggregationDesc());
        fagg->addSource(newChildren[0]);
        return fagg;
    }

};

#endif //OLVP_FINALAGGREGATIONNODE_HPP
