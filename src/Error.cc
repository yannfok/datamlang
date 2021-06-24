//
// Created by yanni on 28/05/2021.
//

#include <exception>
#include <string>

struct ClosureSyntaxError : public std::exception
{

    const char * what() const noexcept override {
        return "Error on Closure Definition";
    }

};

struct ClosureCloseException : public std::exception
{
    const char * what() const noexcept override{
        return "Too many or not enough braces";
    }
};

struct SyntaxError : public std::exception{

    std::string m_errorLine;

    explicit SyntaxError(std::string line){
        this->m_errorLine = "Error on line : " + std::move(line);
    }

    const char * what() const noexcept override{
        return this->m_errorLine.c_str();
    }
};

struct JSPrivateIdentifierError : public std::exception{

    std::string m_errorLine;

    explicit JSPrivateIdentifierError(std::string keyword){
        this->m_errorLine = "Unable to use JS identifier : " + std::move(keyword);
    }

    const char * what() const noexcept override{
        return this->m_errorLine.c_str();
    }
};

struct AliasUnknownError : public std::exception{

    std::string m_errorLine;

    explicit AliasUnknownError(std::string line){
        this->m_errorLine = "Unknown Alias : " + std::move(line);
    }

    const char * what() const noexcept override{
        return this->m_errorLine.c_str();
    }
};
