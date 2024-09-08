//
// Created by zxk on 5/18/23.
//

#ifndef OLVP_STRINGLITERAL_HPP
#define OLVP_STRINGLITERAL_HPP
#include "../Literal.h"
class StringLiteral:public Literal
{
    string Value;
public:
    StringLiteral(string location,string value): Literal(location,"StringLiteral")
    {
        this->Value = value;
    }

    string getValue()
    {
        return this->Value;
    }

    void* accept(AstNodeVisitor *visitor,void* context) {return visitor->VisitStringLiteral(this,context);}


};

#endif //OLVP_STRINGLITERAL_HPP
