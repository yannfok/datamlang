//
// Created by yanni on 24/06/2021.
//

#ifndef DTMLLANG_ALIASES_H
#define DTMLLANG_ALIASES_H

#include "../include/Alias.h"
#include <map>
#include <cstdarg>

#define getAliases(...) getAliasesDef(__VA_ARGS__, NULL)

class Aliases {
public:
    const static std::map<std::string, Alias *> __Aliases;
};

std::vector<Alias *> getAliasesDef(const char *args, ...);

std::vector<Alias*> getAllAliases();

bool AliasExist(const std::string& value);

#endif //DTMLLANG_ALIASES_H
