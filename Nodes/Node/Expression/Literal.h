//
// Created by zxk on 5/18/23.
//

#ifndef OLVP_LITERAL_H
#define OLVP_LITERAL_H
#include "Expression.h"

class Literal:public Expression
{
    string LiteralId;
public:
    Literal(string location,string literalId): Expression(location,"Literal"){
        this->LiteralId = literalId;
    }


    vector<Node*> getChildren(){
        return {};
    }
    string getLiteralId()
    {
        return this->LiteralId;
    }
    virtual void* accept(AstNodeVisitor *visitor,void* context) {return NULL;}


};

#endif //OLVP_LITERAL_H
