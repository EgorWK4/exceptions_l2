//
// Created by egor on 14.05.20.
//

#ifndef EXCEPTIONS_L2_INTERFACE_H
#define EXCEPTIONS_L2_INTERFACE_H
#include <optional>
#include <algorithm>

#include <locale>
#include "utility_fun.h"
#define MAX 100000
#define MIN -10000
#include "file_writing.h"

string& filter_string(string& str)
{

    str.erase(remove_if(str.begin(), str.end(), [](const char &s) { return isalpha(s) == 0; }), str.end());
    if(str.empty())
    {
        str+= "default";
        return str;
    }
    return str;
}

int intInput(int left_limit, int right_limit)
{
    // TODO make std::optional in future
using std::cout;
using std::endl;
    int i;
    while(true)
    {
        //cout << "Enter integer number" <<endl;
        std::cin >> i;
        if (std::cin.good() && (i >= left_limit && i <= right_limit))
        {
            std::cin.ignore(10,'\n');
            break;
        }
            std::cin.clear();
            cout << "Wrong input \n";
            std::cin.ignore(10,'\n');

    }
    cout << "Your choice is : " << i << endl;
    return i;
}

[[maybe_unused]] void clear_concole()
{
    std::cout << "\033[2J\033[1;1H" << std::endl;
}
void menu(Shop& obj, Customer obj1)
{

    bool flag  = true;
    int i;
    while(flag)
    {
        std::cout << "1: show clothes in the store" << std::endl;
        std::cout << "2: buy clothes by index " << std::endl;
        std::cout << "3: show user balance " << std::endl;
        std::cout << "4: show purchased clothes " << std::endl;
        std::cout << "5: Withdraw money from account " << std::endl;
        std::cout << "6: Make deposit " << std::endl;
        std::cout << "7: Create Clothes and add it to store " << std::endl;
        std::cout << "8: Find clothes by price lower then argument " << std::endl;
        std::cout << "9: Sort clothes in the store by price both ascending available and add it to file" << std::endl;
        std::cout << "10: Print user's wallet" << std::endl;

        int id = 4;
        int a ;
        string name,color,size;
        int price;
        std::cout << "Enter your choice" << std::endl;
        a = intInput(1,10);
        switch(a)
        {
            case 1:
            {
                std::cout << obj.get_map_cloths();
                break;
            }

            case 2:
            {
                std::cout << "Enter index of clothes to buy " << std::endl;
                int pos;
                pos = intInput(1,MAX);
                obj1.buy_clothes(obj,pos);
                break;
            }
            case 3:
            {
                obj1.show_balance();
                break;
            }
            case 4:
            {
                std::cout << obj1.get_clothes();
                break;
            }
            case 5:
            {
                int amount;
                amount = intInput(1,1001);
                obj1.withdraw_account(amount);
                break;
            }
            case 6:
            {
                int amount_;
                amount_ = intInput(-1000,MAX); // -1000 to test exception
                obj1.make_deposit(amount_);
                break;
            }
            case 7 :
            {
                std::cout << "How many entities would you like to add" << std::endl;
                int vec_size = intInput(1,10);
                std::vector<Clothes> vec_of_clothes(vec_size);
                std::cout << "Enter clothes_name/color/size/price" << std::endl;
                for(std::size_t c = 0; c != vec_size; ++c)
                {
                    std::cin>> name >> color >> size;
                    filter_string(name);
                    filter_string(color);
                    filter_string(size);
                    price = intInput(1,2000);
                    Clothes clothes(mapp(size),name,color,price);
                    vec_of_clothes.push_back(clothes);
                }
                for(const auto& elem : vec_of_clothes)
                {
                    obj.add_clothes(const_cast<Clothes &>(elem), id++);
                }
                break;
            }
            case 8:
            {
                std::cout << "Enter price below" << std::endl;
                double price_to_find;
                std::cin >> price_to_find;
                auto mapp = obj.get_map_cloths();
                for(const auto& elem : mapp)
                {
                    if(elem.second.get_price() < price_to_find)
                    {
                        std::cout << "Id is: "<<elem.first << '\n';
                        std::cout << "Clothes: " << elem.second << '\n';
                    }
                }
                break;
            }
            case 9 :
            {
                std::cout << "descending or ascending / 0 or 1" << std::endl;
                int sort;
                sort = intInput(0,1);
                const std::string file_path = "shop.txt";
                if(to_file(obj,file_path, sort))
                {
                    std::cout << "This is shop database" << std::endl;
                    read_file(file_path);
                }
                else
                {
                    std::cout << "File writing went wrong" << std::endl;
                }
                break;
            }
            case 10:
            {
                const std::string file_path = "wallet.txt";
                if(wallet_to_file(obj1,file_path))
                {
                    std::cout << "File writing was succesfull" << std::endl;
                    std::cout << "This is user's wallet" << std::endl;
                    read_file(file_path);
                }
                else
                {
                    std::cout << "File writing went wrong" << std::endl;
                }
                break;
            }

        }
        std::cout << "Would you like to continue ? 0 - to exit/ 1-9 continue" << std::endl;
        i = intInput(0,9);
        //std::system("clear");
        if (i == 0)
            flag = false;
    }
}
// currently not used
#endif //EXCEPTIONS_L2_INTERFACE_H
