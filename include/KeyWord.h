//
// Created by yanni on 28/05/2021.
//

#ifndef DTMLLANG_KEYWORD_H
#define DTMLLANG_KEYWORD_H

#include <string>
#include <utility>
#include <map>
#include <vector>
#include "Alias.h"

#define DEFAULT_FINAL_DELIMITER ';'

class KeyWord{
private:
    std::string m_identifier;
    std::map<std::string,std::string> m_JSTranslation;
    std::vector<Alias*> m_aliases;
protected:
    char m_finalDelimiter = DEFAULT_FINAL_DELIMITER;
    virtual std::string parse(std::string content);
public:
    KeyWord(std::string  identifier,std::map<std::string,std::string> __JSTranslation);
    KeyWord(std::string identifier,std::map<std::string,std::string> __JSTranslation,std::vector<Alias*> aliases);
    bool checkValidity(const std::string& line) const;
    std::string retrieveJSCodeLine(std::string content);
};


#endif //DTMLLANG_KEYWORD_H
