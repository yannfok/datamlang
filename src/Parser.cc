//
// Created by yanni on 23/05/2021.
//

#include "../include/Parser.h"
#include "Error.cc"
#include "../include/StringUtils.h"
#include "../include/Function.h"
#include "../include/Loop.h"
#include "../constants/Aliases.h"
#include <vector>


/**
 * Declare here all the keywords that need to be implemented by the language
 */


std::map<std::string, KeyWord *> Parser::KEYWORDS = {
        {"__DECLARE",                 new KeyWord(R"(^dec +[a-zA-Z-_]+ *= *[a-zA-Z0-9-.\->]+$)", {
                {"dec", "let"}
        },getAllAliases())},
        {"__RETURN",                  new KeyWord(R"(^give [a-zA-Z-_.\->]+$|^give [0-9]+$)", {
                {"give", "return"}
        },getAllAliases())},
        {"__MAIN_FUNC",               new Function("^f.[a-zA-Z-_]+$", {
                {"f", "function"},
                {".", " "},
        })},
        {"__INCREMENTATION_OPERATOR", new KeyWord(R"(^[a-zA-Z-_]+ \+\= [0-9-.]+$|^[a-zA-Z-_]+ \+\= [a-zA-Z-_.\->]+$)", {

        },getAllAliases())},
        {"__DECREMENTATION_OPERATOR", new KeyWord(R"(^[a-zA-Z-_]+ \-\= [0-9-.]+$|^[a-zA-Z-_]+ \-\= [a-zA-Z-_.\->]+$)", {

        },getAllAliases())},
        {"__LOOP",                    new Loop("^data->loop[ ]+[a-zA-Z-_]+$", {

        })},
        {"__CONSTANT",                    new KeyWord(R"(^cst +[a-zA-Z-_]+ *= *[a-zA-Z0-9-.\->]+$)", {
                {"cst","const"}
        },getAllAliases())}
};

std::string Parser::JAVASCRIPT_CODE;

Parser::Parser(std::string &srcCode) : currentPosition(0), m_srcCode(std::move(srcCode)) {
    checkBracesSyntax(this->m_srcCode);
    checkKeyWordSecurityBreak(this->m_srcCode);
    this->m_srcCode.erase(std::remove(this->m_srcCode.begin(), this->m_srcCode.end(), '\n'), this->m_srcCode.end());
}

void Parser::checkBracesSyntax(const std::string &srcCode) {
    if (std::count(srcCode.begin(), srcCode.end(), '{') != std::count(srcCode.begin(), srcCode.end(), '}'))
        throw ClosureCloseException();
}

void Parser::parse() {
    auto nextElementIndex = this->m_srcCode.find_first_of("{;", this->currentPosition);
    while (nextElementIndex != std::string::npos) {
        auto element = this->m_srcCode.substr(this->currentPosition, nextElementIndex - this->currentPosition);
        if (element.find('}') != std::string::npos) {
            element.erase(std::remove(element.begin(), element.end(), '}'), element.end());
            Parser::JAVASCRIPT_CODE += '}';
        }
        StringUtils::trim(element);
        this->currentPosition = nextElementIndex + 1;
        auto index = 0;
        for (const auto &elem : Parser::KEYWORDS) {
            if (elem.second->checkValidity(element)) {
                Parser::JAVASCRIPT_CODE += elem.second->retrieveJSCodeLine(element);
                break;
            }
            index++;
        }
        if (index == Parser::KEYWORDS.size()) throw SyntaxError(element);

        nextElementIndex = this->m_srcCode.find_first_of("{;", this->currentPosition);
    }
    Parser::JAVASCRIPT_CODE += '}';
}

void Parser::checkKeyWordSecurityBreak(const std::string &srcCode) {
    for (const auto &elem : JS_PRIVATE_IDENTIFIER) {
        std::vector<std::string> explodedSourceCode = StringUtils::explode(srcCode, ' ');
        for (const auto &eachWord : explodedSourceCode)
            if (eachWord == elem) {
                throw JSPrivateIdentifierError(elem);
            }
    }
}

Parser::~Parser() {

}
