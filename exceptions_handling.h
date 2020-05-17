//
// Created by egor on 17.05.20.
//

#ifndef EXCEPTIONS_L2_EXCEPTIONS_HANDLING_H
#define EXCEPTIONS_L2_EXCEPTIONS_HANDLING_H
#include <exception>
#include <string>
class ExceedsMax
{
};
class ZeroBalance: public std::exception
{

    std::string m_error;

public:
    explicit ZeroBalance(std::string error)
            : m_error(std::move(error)){}

    [[nodiscard]] const char* what() const noexcept override { return m_error.c_str(); }
};

class ExceedsBalance
{
public:
    ExceedsBalance() { message = "Need more money.";};
    explicit ExceedsBalance(std::string s) { message=std::move(s); };

    std::string message;
};

class NegativeDeposit : std::exception
{
    std::string m_error;
public:
    explicit NegativeDeposit( std::string error)
    :  m_error(std::move(error)) {}
    [[nodiscard]] const char* what() const noexcept override {return m_error.c_str();}
};
#endif //EXCEPTIONS_L2_EXCEPTIONS_HANDLING_H
