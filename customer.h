//
// Created by egor on 6.05.20.
//

#ifndef EXCEPTIONS_L2_CUSTOMER_H
#define EXCEPTIONS_L2_CUSTOMER_H

#include <utility>
#include "shop.h"
#include <iostream>

 class ExceedsMax
{
};

class ExceedsBalance
{
public:
    ExceedsBalance() { message = "Need more money.";};
    explicit ExceedsBalance(string s) { message=std::move(s); };
    string message;
};
struct BankAccount
{
    static int id;
    double balance{};
    string first_name;
    string second_name;
public:
    BankAccount()  {++id;}
    explicit BankAccount(string first_name = "", string second_name = "", double balance = 0)
    : first_name(std::move(first_name)), second_name(std::move(second_name)), balance(balance){}

    void set_balance(double balance)
    {
        this->balance = balance;
    }
    void set_first_name(string first_name)
    {
        this->first_name = first_name;
    }
    void set_second_name(string second_name)
    {
        this->second_name = second_name;
    }
    [[nodiscard]] double get_balance() const
    {
        return balance;
    }
    [[nodiscard]] string get_first_name() const
    {
        return first_name;
    }
    [[nodiscard]] string get_second_name() const
    {
        return second_name;
    }

    void show() const
    {
        std::cout <<'[';
        std::cout << "First name :" << first_name << std::endl;
        std::cout << "Second name:" << second_name << std::endl;
        std::cout << "Account Balance:"<< balance << ']'<< std::endl;
    }
};
class Customer
{
    BankAccount account;
    std::vector<Clothes> vec_of_clothes;
    //Customer() = default;
public:
    static double withdraw(BankAccount account, double withdrawal)
    noexcept(false)
    {
        if (withdrawal > 1000)
            throw ExceedsMax();
        if (account.balance - withdrawal < 0)
            throw ExceedsBalance("Not enough money in the account.");
        // Return new balance
        return account.balance -= withdrawal;
    }
    void show()
    {
        account.show();
    }
    explicit Customer(BankAccount account)
    : account(std::move(account)){}// std::vector<Clothes> vec_of_clothes,vec_of_clothes(std::move(vec_of_clothes))

    void make_deposit(double amount)
    {
        account.balance += amount;
    }
    double withdraw_account(double amount)
    {
        using std::cout;
        using std::endl;
    try
    {
        //account.balance -= amount;
        account.balance = withdraw(account, amount);


        cout << "You withdrew " << amount << " dollars." << endl;
        cout << "Your account has $: " << account.balance;
        std::cout << std::endl;
    }
    catch (const ExceedsBalance& e)
    {
        throw(e);
        cout << e.message << endl;
    }
    catch (const ExceedsMax& e)
    {
        cout << "You exceeded the maximum withdrawal amount." << endl;
        throw(e);
    }
    catch(...){cout << " Unhandled exception " << endl; throw(string("unhandled"));}
    return account.balance;
    }
    void print_consumer_clothes() const
    {
        for(const auto& elem : vec_of_clothes)
        {
            std::cout<<elem << " " << std::endl;
            std::cout << "Congrats!" << std::endl;
        }
    }

    std::vector<Clothes> buy_clothes(Shop& obj, int clothes_id)
    {
        //obj.print_map();
        auto mapp = obj.get_map_cloths();

        auto clothes = mapp.at(clothes_id);// there is a exception in std::map already(std::out_of_range)
        withdraw_account(clothes.get_price());
        vec_of_clothes.push_back(clothes);
        obj.delete_f_storage(clothes_id);
        return vec_of_clothes;
    }
    void show_balance() const
    {
        std::cout << "Your current bank balance is :" << account.get_balance() << std::endl;
    }

};

#endif //EXCEPTIONS_L2_CUSTOMER_H
