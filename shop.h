//
// Created by egor on 5.05.20.
//

#ifndef EXCEPTIONS_L2_SHOP_H
#define EXCEPTIONS_L2_SHOP_H
#include "clothes.h"
#include <map>
#include <stdexcept>      // std::out_of_range
#include <utility>
template <typename Key, typename Value>
std::ostream& operator << (std::ostream& out, const std::map<Key,Value>& vi)
{

    for(const auto& i : vi)
    {
        out << "id :" << i.first <<std::setw(5) <<std::cout.fill('_')<<  i.second <<  '\n';
    }
    return out;
}
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
    //void print_map();

    std::map<int,Clothes> delete_f_storage(int key);
    std::map<int,Clothes> delete_in_range(int left, int right);


};
#endif //EXCEPTIONS_L2_SHOP_H
