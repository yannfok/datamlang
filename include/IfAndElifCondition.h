//
// Created by yanni on 12/07/2021.
//

#ifndef HELLO_IFANDELIFCONDITION_H
#define HELLO_IFANDELIFCONDITION_H

#include "KeyWord.h"

class IfAndElifCondition : public KeyWord {
public:
    IfAndElifCondition(std::string  identifier,std::map<std::string,std::string> __JSTranslation,std::vector<Alias*> aliases);
protected:
    std::string parse(std::string content) override ;
};


#endif //HELLO_IFANDELIFCONDITION_H
