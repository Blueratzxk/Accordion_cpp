//
// Created by zxk on 5/19/23.
//

#ifndef OLVP_EXPROUPUT_HPP
#define OLVP_EXPROUPUT_HPP

#include <string>

class ExprOutput
{
    std::string outputName;
    std::string outputType;
public:
    ExprOutput(){}
    ExprOutput(std::string name,std::string type)
    {
        this->outputName = name;
        this->outputType = type;
    }

    std::string getName()
    {
        return this->outputName;
    }

    std::string getType()
    {
        return this->outputType;
    }
};


#endif //OLVP_EXPROUPUT_HPP
