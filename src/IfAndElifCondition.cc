//
// Created by yanni on 12/07/2021.
//

#include "../include/IfAndElifCondition.h"
#include "../include/Parser.h"
#include "../include/StringUtils.h"

IfAndElifCondition::IfAndElifCondition(std::string identifier, std::map<std::string, std::string> JSTranslation,std::vector<Alias*> aliases) : KeyWord(std::move(identifier),std::move(JSTranslation),std::move(aliases)) {
    this->m_finalDelimiter = '{';
}

std::string IfAndElifCondition::parse(std::string content) {
    auto ret = KeyWord::parse(content);
    auto isElif = content.substr(0,4) == "elif";
    ret.insert( isElif ? 4 : 2," (");
    ret.insert(ret.length()," )");
    if(isElif)
        ret.insert(2,"se ");
    return ret;
}
