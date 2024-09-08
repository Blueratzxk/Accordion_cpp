//
// Created by zxk on 5/18/23.
//

#ifndef OLVP_ASTNODEVISITOR_HPP
#define OLVP_ASTNODEVISITOR_HPP


#include "Node.h"
#include "Expression/Expression.h"
#include "Expression/Literal.h"

class FunctionCall;
class DoubleLiteral;
class Int32Literal;
class Int64Literal;
class StringLiteral;
class Date32Literal;
class DayTimeIntervalLiteral;
class Identifier;
class Column;
class IfExpression;
class InExpression;

class AstNodeVisitor {

public:


    virtual void* VisitNode(Node* node,void* context) {return NULL;};
    virtual void* VisitExpression(Expression* node,void* context) { return VisitNode(node,context);} ;
    virtual void* VisitFunctionCall(FunctionCall* node,void* context)  = 0 ;
    virtual void* VisitIfExpression(IfExpression *node,void* context) = 0;
    virtual void* VisitInExpression(InExpression *node,void* context) = 0;
    virtual void* VisitLiteral(Literal* node,void* context) { return VisitExpression(node,context);};
    virtual void* VisitDoubleLiteral(DoubleLiteral* node,void* context)  = 0 ;
    virtual void* VisitInt32Literal(Int32Literal* node,void* context) = 0 ;
    virtual void* VisitInt64Literal(Int64Literal* node,void* context)  = 0 ;
    virtual void* VisitDate32Literal(Date32Literal* node,void* context)  = 0 ;
    virtual void* VisitDayTimeIntervalLiteral(DayTimeIntervalLiteral* node,void* context)  = 0 ;

    virtual void* VisitStringLiteral(StringLiteral* node,void* context)  = 0 ;

    virtual void* VisitIdentifier(Identifier* node,void* context)  = 0 ;
    virtual void* VisitColumn(Column* node,void* context)  = 0 ;


    void* Visit(Node* node,void* context) {
        return node->accept(this,context);
    }
};



#endif //OLVP_ASTNODEVISITOR_HPP
