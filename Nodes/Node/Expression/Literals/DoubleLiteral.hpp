//
// Created by zxk on 5/18/23.
//

#ifndef OLVP_DOUBLELITERAL_HPP
#define OLVP_DOUBLELITERAL_HPP

#include "../Literal.h"
class DoubleLiteral:public Literal
{
    double_t Value;
public:
    DoubleLiteral(string location,string value): Literal(location,"DoubleLiteral")
    {
        this->Value = stod(value);
    }

    double_t getValue()
    {
        return this->Value;
    }

    void* accept(AstNodeVisitor *visitor,void* context){return visitor->VisitDoubleLiteral(this,context);}


};


#endif //OLVP_DOUBLELITERAL_HPP
