//
// Created by yanni on 24/06/2021.
//

#include "../include/Alias.h"
#include "../include/StringUtils.h"
#include "../constants/Aliases.h"
#include "iostream"
#include "Error.cc"

Alias::Alias(const std::string &identifier, std::string replacer) : m_replacer(std::move(replacer)) {
    this->m_identifier = ALIAS_HEADER + identifier;
}

void Alias::replace(std::string &content) {
    std::string &beforeReplace = content;
    auto beginAlias = content.find(ALIAS_HEADER);
    if (beginAlias != std::string::npos) {
        auto hasSpaceIndex = content.find_first_not_of("abcdefghijklmnopqrstuvwxyz",beginAlias+6);
        auto identifier = content.substr(beginAlias,hasSpaceIndex != std::string::npos ? hasSpaceIndex - beginAlias : content.length());
        StringUtils::trim(identifier);
        if(!AliasExist(identifier))
            throw AliasUnknownError(content.substr(content.find(ALIAS_HEADER), content.length()));
        StringUtils::replaceFirstOccurrence(content, m_identifier, m_replacer);
    }
}