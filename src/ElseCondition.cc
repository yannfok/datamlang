//
// Created by yanni on 15/07/2021.
//

#include "../include/ElseCondition.h"

std::string ElseCondition::parse(std::string content) {
    return KeyWord::parse(content);
}

ElseCondition::ElseCondition(std::string identifier, std::map<std::string, std::string> JSTranslation) : KeyWord(std::move(identifier),std::move(JSTranslation))
{
    this->m_finalDelimiter = '{';
}