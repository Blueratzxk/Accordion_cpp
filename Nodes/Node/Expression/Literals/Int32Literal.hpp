//
// Created by zxk on 5/18/23.
//

#ifndef OLVP_INT32LITERAL_HPP
#define OLVP_INT32LITERAL_HPP


#include "../Literal.h"
class Int32Literal:public Literal
{
    int32_t Value;
public:
    Int32Literal(string location,string value): Literal(location,"Int32Literal")
    {
        this->Value = stoi(value);
    }

    int32_t getValue()
    {
        return this->Value;
    }


    void* accept(AstNodeVisitor *visitor,void* context) {return visitor->VisitInt32Literal(this,context);}


};

#endif //OLVP_INT32LITERAL_HPP
