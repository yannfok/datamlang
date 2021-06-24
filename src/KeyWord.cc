//
// Created by yanni on 28/05/2021.
//

#include "../include/KeyWord.h"
#include <regex>
#include <utility>
#include "../include/StringUtils.h"


bool KeyWord::checkValidity(const std::string& line) const {
    return std::regex_match(line,std::regex(this->m_identifier));
}

KeyWord::KeyWord(std::string identifier,std::map<std::string,std::string> JSTranslation) : m_identifier(std::move(identifier)),m_JSTranslation(std::move(JSTranslation)) {

}

std::string KeyWord::parse(std::string content) {
    std::string& parse = content;
    for(const auto &elem : this->m_JSTranslation)
    {
        StringUtils::replaceFirstOccurrence(parse,elem.first,elem.second);
    }
    for(const auto &elem : this->m_aliases)
    {
        elem->replace(parse);
    }
    return parse;
}

std::string KeyWord::retrieveJSCodeLine(std::string content) {
    return this->parse(std::move(content)) + this->m_finalDelimiter;
}

KeyWord::KeyWord(std::string identifier, std::map<std::string, std::string> JSTranslation,
                  std::vector<Alias*> aliases) : m_identifier(std::move(identifier)), m_JSTranslation(std::move(JSTranslation)), m_aliases(std::move(aliases)) {

}
