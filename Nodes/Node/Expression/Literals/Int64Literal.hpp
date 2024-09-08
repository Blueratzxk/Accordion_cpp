//
// Created by zxk on 5/18/23.
//

#ifndef OLVP_INT64LITERAL_HPP
#define OLVP_INT64LITERAL_HPP

#include "../Literal.h"
class Int64Literal:public Literal
{
    int64_t Value;
public:
    Int64Literal(string location,string value): Literal(location,"Int64Literal")
    {
        this->Value = stol(value);
    }

    int64_t getValue()
    {
        return this->Value;
    }


    void* accept(AstNodeVisitor *visitor,void* context) {return visitor->VisitInt64Literal(this,context);}

};

#endif //OLVP_INT64LITERAL_HPP
