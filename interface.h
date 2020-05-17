//
// Created by egor on 14.05.20.
//

#ifndef EXCEPTIONS_L2_INTERFACE_H
#define EXCEPTIONS_L2_INTERFACE_H
#include <optional>
#include <algorithm>

#include <locale>
#define MAX 100000
#define MIN -10000
sizes mapp(const string& size)
{
    std::map<string, sizes> map_of_sizes{
            {"XSS", XSS},
            {"XS",  XS},
            {"S",   S},
            {"M",   M},
            {"L",   L},
            {"XL",  XL},
            {"XXL", XXL}};
    return map_of_sizes.at(size);
}
string& filter_string(string& str)
{

    str.erase(remove_if(str.begin(), str.end(), [](const char &s) { return isalpha(s) == 0; }), str.end());
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

        int id = 4;
        int a ;
        string name,color,size;
        int price;
        std::cout << "Enter your choice" << std::endl;
        a = intInput(1,7);
        switch(a)
        {
            case 1:
                std::cout << obj.get_map_cloths();
                break;
            case 2:
                std::cout << "Enter index of clothes to buy " << std::endl;
                int pos;
                pos = intInput(1,MAX);
                obj1.buy_clothes(obj,pos);
                break;
            case 3:
                obj1.show_balance();
                break;
            case 4:
                std::cout << obj1.get_clothes();
                break;
            case 5:
                int amount;
                amount = intInput(1,1001);
                obj1.withdraw_account(amount);
                break;
            case 6:
                int amount_;
                amount_ = intInput(-1000,MAX); // -1000 to test exception
                obj1.make_deposit(amount_);
                break;
            case 7 :
                id+=1;
                //Clothes clothes;
                std::cout << "Enter clothes_name/color/size/price" << std::endl;
                std::cin >>name;
                std::cin >>color;
                std::cin >> size;
                price = intInput(1,3000);
                //clothes.set_price(price);
                //clothes.set_name(filter_string(name));
                //clothes.set_color(filter_string(color));
                //clothes.set_size(mapp(size));
                //obj.add_clothes(Clothes(),id); TODO change add_clothes signature
                break;
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
