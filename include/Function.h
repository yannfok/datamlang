//
// Created by yanni on 02/06/2021.
//

#ifndef DTMLLANG_FUNCTION_H
#define DTMLLANG_FUNCTION_H

#include "KeyWord.h"

class Function : public KeyWord {
public:
    Function(std::string  identifier,std::map<std::string,std::string> __JSTranslation);
protected:
    std::string parse(std::string content) override;
};


#endif //DTMLLANG_FUNCTION_H
