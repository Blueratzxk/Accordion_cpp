//
// Created by zxk on 5/30/23.
//

#ifndef OLVP_PROJECTNODE_HPP
#define OLVP_PROJECTNODE_HPP

#include "PlanNode.hpp"
#include "../../Descriptor/ProjectDescriptor.hpp"

class ProjectNode :public PlanNode
{
    PlanNode *source;
    ProjectAssignments assignments;

public:


    ProjectNode (string id,ProjectAssignments assignments):PlanNode("ProjectNode",id)
    {
        this->assignments = assignments;
    }

    ProjectAssignments getAssignments(){
        return this->assignments;
    }

    void* accept(NodeVisitor* visitor,void* context)  {
        return visitor->VisitProjectNode(this,context);
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
        ProjectNode *proj = new ProjectNode(this->getId(),this->assignments);
        proj->addSource(newChildren[0]);
        return proj;
    }



};




#endif //OLVP_PROJECTNODE_HPP
