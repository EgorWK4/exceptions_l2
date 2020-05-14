//
// Created by egor on 14.05.20.
//

#ifndef EXCEPTIONS_L2_INTERFACE_H
#define EXCEPTIONS_L2_INTERFACE_H
sizes sizes_map(const string& size) {
    std::map<string,sizes> map_of_sizes{
            {"XSS" ,XSS},{"XS" ,XS},
            {"S" ,S},{"M" ,M},{"L" ,L},
            {"XL" ,XL},{"XXL" ,XXL}};
    return map_of_sizes.at(size); // to fill  object Clothes fields from keyboard; throws out_of_range if not found;
    //currently not used
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
        int a ;
        std::cout << "Enter your choice" << std::endl;
        std::cin >> a;
        switch(a)
        {
            case 1:
                obj.print_map();
                break;
            case 2:
                std::cout << "Enter index of clothes to buy " << std::endl;
                int pos;
                std::cin >> pos;
                obj1.buy_clothes(obj,pos);
                break;
            case 3:
                obj1.show_balance();
                break;
            case 4:
                obj1.print_consumer_clothes();
                break;
            default :
                std::cout << "Wrong operation key" << std::endl;
                break;
        }
        std::cout << "Would you like to continue ? 0 - to exit" << std::endl;
        std::cin >> i;
        //std::cout << "\033[2J\033[1;1H" << std::endl; // to clear console output with special escaping sequence of characters/dont working dunno why
        if (i == 0)
            flag = false;
    }
}
// currently not used
#endif //EXCEPTIONS_L2_INTERFACE_H
