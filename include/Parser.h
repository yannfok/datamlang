//
// Created by yanni on 23/05/2021.
//

#ifndef DTMLLANG_TRANSPILER_H
#define DTMLLANG_TRANSPILER_H

#include <iostream>
#include "KeyWord.h"
#include <list>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#define DATA_VARIABLE_NAME "data"
#define JS_PRIVATE_IDENTIFIER {"this","window","const","let","var","for","new","in",}

class Parser {

private:
    static void checkBracesSyntax(const std::string& srcCode);
    static void checkKeyWordSecurityBreak(const std::string& srcCode);
    unsigned int currentPosition;
    std::string m_srcCode;
    static std::map<std::string,KeyWord*> KEYWORDS;
    static bool hasReturned;
public:
    static std::string JAVASCRIPT_CODE;

    explicit Parser(std::string &srcCode);
    ~Parser();
    void parse();
};

#endif //DTMLLANG_TRANSPILER_H
