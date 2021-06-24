//
// Created by yanni on 28/05/2021.
//

#ifndef DTMLLANG_STRINGUTILS_H
#define DTMLLANG_STRINGUTILS_H


#include <string>
#include <vector>

class StringUtils {

public:
    static void ltrim(std::string &s);
    static void rtrim(std::string &s);
    static void trim(std::string &s);
    static void replaceFirstOccurrence(std::string& source, const std::string& from, const std::string& to);
    static void replaceAll(std::string& source, const std::string& from, const std::string& to);
    static std::vector<std::string> explode(std::string const & s, char delimiter);
};


#endif //DTMLLANG_STRINGUTILS_H
