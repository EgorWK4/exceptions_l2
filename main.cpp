#include <iostream>
#include "clothes.h"
#include "shop.h"
#include "customer.h"
#include "interface.h"

int main()
{

    Clothes obj(XS,"t-shirt","brown",10.5);
    Clothes obj1(M,"t-shirt","green",23.5);
    Clothes obj2(XL,"trousers","yellow",27.6);
    Clothes obj3(XXL,"Red blazer","red",1100);
    Clothes obj4(S,"Hat","green",50);
    Shop shop;
    shop.set_name("Massimo Dutti");
    shop.set_location("Petra Mstislavtsa");
    shop.add_clothes(obj,1);
    shop.add_clothes(obj1,2);
    shop.add_clothes(obj3,3);
    shop.add_clothes(obj4,4);
    Customer customer(BankAccount("Oleg","Yushkevich",100));

    menu(shop,customer);

}
//
