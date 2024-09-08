//
// Created by zxk on 6/17/23.
//

#ifndef OLVP_DATE32LITERAL_HPP
#define OLVP_DATE32LITERAL_HPP


#include "../Literal.h"

class Date32Literal:public Literal
{
    string Value;
public:
    Date32Literal(string location,string value): Literal(location,"Date32Literal")
    {
        this->Value = value;
    }

    string getValue()
    {
        return this->Value;
    }


    void* accept(AstNodeVisitor *visitor,void* context) {return visitor->VisitDate32Literal(this,context);}

};


#endif //OLVP_DATE32LITERAL_HPP
