//
// Created by yanni on 02/06/2021.
//

#include "../include/Function.h"

#include <utility>
#include "../include/Parser.h"

std::string Function::parse(std::string content) {
    return KeyWord::parse(content) + "(" + DATA_VARIABLE_NAME + ")" ;
}

Function::Function(std::string identifier, std::map<std::string, std::string> JSTranslation) : KeyWord(std::move(identifier),std::move(JSTranslation))
{
    this->m_finalDelimiter = '{';
}
