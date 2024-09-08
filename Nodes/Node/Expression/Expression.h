//
// Created by zxk on 5/18/23.
//

#ifndef OLVP_EXPRESSION_H
#define OLVP_EXPRESSION_H
#include "../Node.h"

class Expression:public Node
{
    string ExpressionId;
public:
    Expression(string location,string ExpressionId): Node(location,"Expression"){
        this->ExpressionId = ExpressionId;
    }
    string getExpressionId()
    {
        return this->ExpressionId;
    }
    virtual void* accept(AstNodeVisitor *visitor,void* context) {return NULL;}

    virtual  void addChilds(vector<Expression*> childs){}

};


#endif //OLVP_EXPRESSION_H
