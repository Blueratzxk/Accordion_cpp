//
// Created by zxk on 5/30/23.
//

#ifndef OLVP_PARTIALAGGREGATIONNODE_HPP
#define OLVP_PARTIALAGGREGATIONNODE_HPP


class PartialAggregationNode :public PlanNode
{

    AggregationDesc desc;
    PlanNode *source;
public:


    PartialAggregationNode (string id,AggregationDesc desc):PlanNode("PartialAggregationNode",id)
    {
        this->desc = desc;
    }
    void* accept(NodeVisitor* visitor,void* context)  {
        return visitor->VisitPartialAggregationNode(this,context);
    }


    string getId()
    {
        return PlanNode::getId();
    }
    AggregationDesc getAggregationDesc()
    {
        return this->desc;
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
        vector<PlanNode*> list{this->source};
        return list;
    }
    PlanNode* replaceChildren(vector<PlanNode*> newChildren){
        PartialAggregationNode *pagg = new PartialAggregationNode(this->getId(),this->getAggregationDesc());
        pagg->addSource(newChildren[0]);
        return pagg;
    }
};

#endif //OLVP_PARTIALAGGREGATIONNODE_HPP
