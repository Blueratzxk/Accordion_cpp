//
// Created by zxk on 5/30/23.
//

#ifndef OLVP_TABLESCANNODE_HPP
#define OLVP_TABLESCANNODE_HPP


#include "../../Utils/UUID.hpp"
#include "../../Descriptor/TableScanDescriptor.hpp"
class TableScanNode:public PlanNode
{

    TableScanDescriptor tableScanDescriptor;
public:

    TableScanNode(string id,TableScanDescriptor tableScanDescriptor) :PlanNode("TableScanNode",id)
    {
        this->tableScanDescriptor = tableScanDescriptor;
    }
    void addSource(PlanNode *node){}
    void addSources(PlanNode *node){}

    void* accept(NodeVisitor* visitor,void* context)  {
        return visitor->VisitTableScanNode(this,context);
    }




    string generateId()
    {
        return "tableScan_"+UUID::create_uuid();
    }

    PlanNode* replaceChildren(vector<PlanNode*> newChildren){
        if(this->getId().compare("-1") == 0)
            return new TableScanNode(generateId(),tableScanDescriptor);
        else
            return new TableScanNode(this->getId(),tableScanDescriptor);
    }

    string getId()
    {
        return PlanNode::getId();
    }

    TableScanDescriptor getDescriptor()
    {
        return this->tableScanDescriptor;
    }



};
#endif //OLVP_TABLESCANNODE_HPP
