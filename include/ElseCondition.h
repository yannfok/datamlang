//
// Created by yanni on 15/07/2021.
//

#ifndef HELLO_ELSECONDITION_H
#define HELLO_ELSECONDITION_H

#include "KeyWord.h"


class ElseCondition : public KeyWord {
public:
    ElseCondition(std::string  identifier,std::map<std::string,std::string> __JSTranslation);
protected:
    std::string parse(std::string content) override ;
};


#endif //HELLO_ELSECONDITION_H
