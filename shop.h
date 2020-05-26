//
// Created by egor on 5.05.20.
//

#ifndef EXCEPTIONS_L2_SHOP_H
#define EXCEPTIONS_L2_SHOP_H
#include "clothes.h"
#include <map>
#include <stdexcept>      // std::out_of_range
#include <utility>

class Shop
{
    std::map<int,Clothes> map_of_clothes;
    string name;
    string location;
public:
    Shop();

    Shop(std::map<int,Clothes>clothes_map,string name, string location);
    [[nodiscard]] string get_name() const;
    [[nodiscard]] string get_location() const;
    [[nodiscard]] std::map<int,Clothes> get_map_cloths() const;

    void set_name(std::string name);
    void set_location(std::string location);

    void add_clothes(Clothes &obj,int key);

    std::map<int,Clothes> delete_f_storage(int key);
    std::map<int,Clothes> delete_in_range(int left, int right);

};
#endif //EXCEPTIONS_L2_SHOP_H
