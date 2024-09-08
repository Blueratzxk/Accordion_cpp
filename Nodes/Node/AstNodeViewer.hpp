//
// Created by zxk on 5/18/23.
//

#ifndef OLVP_ASTNODEVIEWER_HPP
#define OLVP_ASTNODEVIEWER_HPP

#include "AstNodeVisit.hpp"
#include "AstNodeVisitor.hpp"
class AstNodeViewer:public AstNodeVisitor
{


public:


    void* VisitFunctionCall(FunctionCall* node,void* context) {
        vector<Node*> arguments = node->getChildren();
        for(int i = 0 ; i < arguments.size() ; i++)
        {
            Visit(arguments[i],NULL);
        }


        cout << node->getFuncName() << endl;

        return NULL;

    }

    void* VisitDoubleLiteral(DoubleLiteral* node,void* context) {


        cout << node->getValue() << endl;

        return NULL;

   }
    void* VisitInt32Literal(Int32Literal* node,void* context) {
        cout << node->getValue() << endl;
        return NULL;
   }
    void* VisitInt64Literal(Int64Literal* node,void* context) {
        cout << node->getValue() << endl;
        return NULL;
   }

    void* VisitDate32Literal(Date32Literal* node,void* context) {
        cout << node->getValue() << endl;
        return NULL;
    }

    void* VisitDayTimeIntervalLiteral(DayTimeIntervalLiteral* node,void* context) {
        cout << node->getValue() << endl;
        return NULL;
    }

    void* VisitStringLiteral(StringLiteral* node,void* context){
        cout << node->getValue() << endl;
        return NULL;
   }
    void* VisitIdentifier(Identifier* node,void* context){
        cout << node->getValue() << endl;
        return NULL;
    }

    void* VisitColumn(Column* node,void* context){
        cout << node->getValue()<<"|"<< node->getColumnType() << endl;
        return NULL;
    }


   void test()
   {

       StringLiteral *name = new StringLiteral("1","Name");
       StringLiteral *nameCom = new StringLiteral("1","zxk");
       FunctionCall *funcName = new FunctionCall("1","like","boolean");
       funcName->addChilds({name,nameCom});

       Int64Literal *age = new Int64Literal("2","12");
       Int64Literal *ageCom = new Int64Literal("3","32");
       FunctionCall *funcAge = new FunctionCall("4","less_than","boolean");
       funcAge->addChilds({age,ageCom});


       FunctionCall *andCom = new FunctionCall{"7","and","boolean"};
       andCom->addChilds({funcName,funcAge});

       this->Visit(andCom,NULL);



   }



};


#endif //OLVP_ASTNODEVIEWER_HPP
