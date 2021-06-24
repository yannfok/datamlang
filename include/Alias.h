//
// Created by yanni on 24/06/2021.
//

#ifndef DTMLLANG_ALIAS_H
#define DTMLLANG_ALIAS_H

#define ALIAS_HEADER "data->"

#include <string>

class Alias {
private:
    std::string m_identifier;
    std::string m_replacer;
public:
    Alias(const std::string& identifier,std::string replacer);
    void replace(std::string &content);
    std::string getIdentifier() const{return this->m_identifier;};
};


#endif //DTMLLANG_ALIAS_H
