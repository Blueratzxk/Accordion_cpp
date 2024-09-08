//
// Created by zxk on 5/30/23.
//

#ifndef OLVP_PLANNODE_HPP
#define OLVP_PLANNODE_HPP


#include "../../common.h"

using namespace std;

class NodeVisitor;
class PlanNode {
private:
    string type;
    string id = "-1";
    string label;
public:


    PlanNode(string type, string id) {
        this->type = type;
        this->id = id;
        this->label = "";
    }


    string getId() {
        return id;
    }

    string getType() {
        return type;
    }
    string getLabel()
    {
        return this->label;
    }
    void setLabel(string label)
    {
        this->label = label;
    }

    virtual PlanNode *replaceChildren(vector<PlanNode *> newChildren) { return NULL; };

    virtual vector<PlanNode *> getSources() {
        vector<PlanNode *> null;
        return null;
    };

    virtual void addSources(vector<PlanNode *> nodes) {};

    virtual void addSource(PlanNode *) {};

    virtual PlanNode *getSource() { return NULL; };

    virtual void *accept(NodeVisitor *visitor, void *context) { return NULL; };


};





#endif //OLVP_PLANNODE_HPP
