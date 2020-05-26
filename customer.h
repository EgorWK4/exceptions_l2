//
// Created by egor on 6.05.20.
//

#ifndef EXCEPTIONS_L2_CUSTOMER_H
#define EXCEPTIONS_L2_CUSTOMER_H

#include <utility>
#include "shop.h"
#include <iostream>
#include "exceptions_handling.h"

template<typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& vi)
{
    if(vi.empty()) std::cout << "Your basket is empty" << std::endl;
    for (typename std::vector<T>::const_iterator i = vi.begin(); i != vi.end(); ++i)
    {
        std::cout <<std::cout.fill('*')<< *i <<  ' ';
    }
}
struct BankAccount
{
    //static int id;
    double balance{};
    string first_name;
    string second_name;
public:

    BankAccount();
    explicit BankAccount(string first_name = "", string second_name = "", double balance = 0);
    void set_balance(double balance);
    void set_first_name(string first_name);
    void set_second_name(string second_name);

    [[nodiscard]] double get_balance() const;
    [[nodiscard]] string get_first_name() const;
    [[nodiscard]] string get_second_name() const;
    //void show() const;

};

class Customer
{
    BankAccount account;
    std::vector<Clothes> vec_of_clothes;
    //Customer() = default;
public:
    std::vector<Clothes> get_clothes();
    static double withdraw(BankAccount account, double withdrawal);
    explicit Customer(BankAccount account);
    double make_dep(double sum);
    void make_deposit(double amount);
    double withdraw_account(double amount);
    std::vector<Clothes> buy_clothes(Shop& obj, int clothes_id);
    void show_balance() const;
    //void show();
    static void find_clothes(Shop& obj,unsigned price)
    {
        for(const auto& elem : obj.get_map_cloths())
        {
            if(elem.second.get_price() < price)
            {
                std::cout << "Id of clothes with price lower then " <<price <<  elem.first << std::endl;
            }
        }
    }

};

#endif //EXCEPTIONS_L2_CUSTOMER_H
