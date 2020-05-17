//
// Created by egor on 17.05.20.
//

#include "customer.h"
#include <iostream>
BankAccount::BankAccount()
{
    //++id;
    std::cout << "Bank account constructor"<<std::endl;
}
BankAccount::BankAccount(string first_name, string second_name, double balance):
first_name(std::move(first_name)), second_name(std::move(second_name)),balance(balance)
{
    if(balance <= 0)
    {
        throw(ZeroBalance("Cant create account without first deposit or negative amount"));
    }
}
void BankAccount::set_balance(double balance)
{
    this->balance = balance;
}
void BankAccount::set_first_name(string first_name)
{

        this->first_name = first_name;
}
void BankAccount::set_second_name(string second_name)
{
    this->second_name = second_name;
}
double BankAccount::get_balance() const
{
    return balance;
}
string BankAccount::get_first_name() const
{
    return first_name;
}
string BankAccount::get_second_name() const
{
    return second_name;
}
/*void BankAccount::show() const
{
    std::cout <<'[';
    std::cout << "First name :" << first_name << std::endl;
    std::cout << "Second name:" << second_name << std::endl;
    std::cout << "Account Balance:"<< balance << ']'<< std::endl;
}
*/
// Customer methods
Customer::Customer(BankAccount account)
try: account(std::move(account)){std::cout << "Customer constructor" << std::endl;}
catch(ZeroBalance& exception)
{
    std::cerr << "An zero balance exception occurred (" << exception.what() << ")\n";

}

void Customer::make_deposit(double amount)
{
    try
    {
        amount = make_dep(amount);
        account.balance +=amount;
        //account.balance += make_dep(amount);
    }
    catch(NegativeDeposit& exception)
    {
        std::cerr << " Cant make deposit with zero or negative amount (" << exception.what() << ")\n";
    }
}
double Customer::make_dep(double sum)
{
    if(sum <= 0)
    {
        throw (NegativeDeposit("NegativeDeposit exception"));
    }
    return sum;
}
double Customer::withdraw_account(double amount)
{
    using std::cout;
    using std::endl;
    try
    {
        //account.balance -= amount;
        account.balance = withdraw(account, amount);


        cout << "You withdrew " << amount << " dollars." << endl;
        cout << "Your account has $: "  << account.balance;
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
double Customer::withdraw(BankAccount account, double withdrawal) noexcept(false)
{
    if (withdrawal > 1000)
        throw ExceedsMax();
    if (account.balance - withdrawal < 0)
        throw ExceedsBalance("Not enough money in the account.");
        // Return new balance
        return account.balance -= withdrawal;

}
std::vector<Clothes> Customer::get_clothes()
{
    return vec_of_clothes;
}
void Customer::show_balance() const
{
    std::cout << "Your current bank balance is :" << std::setprecision(10) << account.get_balance() << std::endl;
}

std::vector<Clothes> Customer::buy_clothes(Shop &obj, int clothes_id)
{
    //obj.print_map();
    auto mapp = obj.get_map_cloths();

    auto clothes = mapp.at(clothes_id);// there is a exception in std::map already(std::out_of_range)
    withdraw_account(clothes.get_price());
    vec_of_clothes.push_back(clothes);
    obj.delete_f_storage(clothes_id);
    return vec_of_clothes;
}