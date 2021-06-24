//
// Created by yanni on 03/06/2021.
//

#include "../include/Loop.h"
#include "../include/Parser.h"
#include "../include/StringUtils.h"

Loop::Loop(std::string identifier, std::map<std::string, std::string> JSTranslation) : KeyWord(std::move(identifier),std::move(JSTranslation)) {
    this->m_finalDelimiter = '{';
}

std::string Loop::parse(std::string content) {
    auto split = StringUtils::explode(content,' ');
    return "for(const " + split.at(1) + " of " + DATA_VARIABLE_NAME + ')';
}
