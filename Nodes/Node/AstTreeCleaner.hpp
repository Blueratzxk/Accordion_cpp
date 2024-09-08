//
// Created by zxk on 5/29/23.
//

#ifndef OLVP_ASTTREECLEANER_HPP
#define OLVP_ASTTREECLEANER_HPP

#include "AstNodeVisit.hpp"
#include "AstNodeVisitor.hpp"
class AstTreeCleaner:public AstNodeVisitor
{


public:


    void* VisitFunctionCall(FunctionCall* node,void* context) {
        vector<Node*> arguments = node->getChildren();
        for(int i = 0 ; i < arguments.size() ; i++)
        {
            Visit(arguments[i],NULL);
        }
        delete node;
        return NULL;

    }

    void* VisitDoubleLiteral(DoubleLiteral* node,void* context) {

        delete node;
        return NULL;

    }
    void* VisitInt32Literal(Int32Literal* node,void* context) {

        delete node;
        return NULL;
    }
    void* VisitInt64Literal(Int64Literal* node,void* context) {

        delete node;
        return NULL;
    }
    void* VisitStringLiteral(StringLiteral* node,void* context){

        delete node;
        return NULL;
    }
    void* VisitDate32Literal(Date32Literal* node,void* context){

        delete node;
        return NULL;
    }
    void* VisitIdentifier(Identifier* node,void* context){

        delete node;
        return NULL;
    }
    void *VisitDayTimeIntervalLiteral(DayTimeIntervalLiteral* node,void* context)
    {
        delete node;
        return NULL;
    }

    void* VisitColumn(Column* node,void* context){

        delete node;
        return NULL;
    }

    void* VisitIfExpression(IfExpression *node,void* context)
    {
        vector<Node*> arguments = node->getChildren();
        for(int i = 0 ; i < arguments.size() ; i++)
        {
            Visit(arguments[i],NULL);
        }
        delete node;
        return NULL;
    }

    void* VisitInExpression(InExpression *node,void* context)
    {
        vector<Node*> arguments = node->getChildren();
        for(int i = 0 ; i < arguments.size() ; i++)
        {
            Visit(arguments[i],NULL);
        }
        delete node;
        return NULL;
    }


};

#endif //OLVP_ASTTREECLEANER_HPP
