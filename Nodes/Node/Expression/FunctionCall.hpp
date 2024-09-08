//
// Created by zxk on 5/18/23.
//

#ifndef OLVP_FUNCTIONCALL_HPP
#define OLVP_FUNCTIONCALL_HPP

#include "Expression.h"

class FunctionCall:public Expression
{
    string Name;
    string outputType;
    vector<Node*> arguments;

public:
    FunctionCall(string location,string Name,string outputType): Expression(location,"FunctionCall"){
        this->Name = Name;
        this->outputType = outputType;
    }


    string getFuncName()
    {
        return this->Name;
    }
    string getOutputType()
    {
        return this->outputType;
    }


    vector<Node*> getChildren(){

        vector<Node*> nodes;

       return this->arguments;
    }
    void addChilds(vector<Node*> childs) override
    {
        for(int i = 0 ; i < childs.size() ; i++)
            this->arguments.push_back(childs[i]);
    }

    void* accept(AstNodeVisitor *visitor,void* context) {return visitor->VisitFunctionCall(this,context);}


};
#endif //OLVP_FUNCTIONCALL_HPP
