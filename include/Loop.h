//
// Created by yanni on 03/06/2021.
//

#ifndef DTMLLANG_LOOP_H
#define DTMLLANG_LOOP_H


#include "KeyWord.h"

class Loop : public KeyWord {
public:
    Loop(std::string  identifier,std::map<std::string,std::string> __JSTranslation);

protected:
    std::string parse(std::string content) override ;
};


#endif //DTMLLANG_LOOP_H
