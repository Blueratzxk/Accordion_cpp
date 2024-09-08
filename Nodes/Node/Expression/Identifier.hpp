//
// Created by zxk on 5/18/23.
//

#ifndef OLVP_IDENTIFIER_HPP
#define OLVP_IDENTIFIER_HPP
#include "Expression.h"

class Identifier:public Expression
{
    string Value;


public:
    Identifier(string location,string value): Expression(location,"Identifier"){
        this->Value = value;
    }


    string getValue()
    {
        return this->Value;
    }



    void* accept(AstNodeVisitor *visitor,void* context) {return visitor->VisitIdentifier(this,context);}

    vector<Node*> getChildren() {return  {};}


};

#endif //OLVP_IDENTIFIER_HPP
