//
// Created by yanni on 24/06/2021.
//

#include <vector>
#include "../constants/Aliases.h"

const std::map<std::string, Alias *> Aliases::__Aliases = {
        {"__SUM",  new Alias("sum", "data.reduce((a, b) => a + b, 0)")},
        {"__SIZE", new Alias("size", "data.length")},
};

std::vector<Alias *> getAliasesDef(const char *args, ...) {
    va_list arguments;

    std::vector<Alias*> aliases;

    for (va_start(arguments, args); args != NULL; args = va_arg(arguments, const char *)) {
        aliases.push_back(Aliases::__Aliases.at(args));
    }

    va_end(arguments);
    return aliases;
}

std::vector<Alias*> getAllAliases()
{
    std::vector<Alias*> aliases;
    aliases.reserve(Aliases::__Aliases.size());
    for(const auto &elem : Aliases::__Aliases)
        aliases.push_back(elem.second);
    return aliases;
}

bool AliasExist(const std::string& value)
{
    for(const auto &elem : Aliases::__Aliases)
        if(elem.second->getIdentifier() == value)
            return true;
    return false;
}