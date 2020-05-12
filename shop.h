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
    //std::vector<Clothes> vec_of_clothes;
    std::map<int,Clothes> map_of_clothes;
    string name;
    string location;
public:
    Shop()
    {
    //vec_of_clothes = std::vector<Clothes> ();
    map_of_clothes = std::map<int,Clothes> ();
    }
    Shop(std::map<int,Clothes>clothes_map,string name, string location)  :
    map_of_clothes(std::move(clothes_map)), name(std::move(name)),location(std::move(location))
    {}
    //std::vector<Clothes>vec, vec_of_clothes(vec),
    [[nodiscard]] string get_name() const
    {
        return name;
    }
    [[nodiscard]] string get_location() const
    {
        return location;
    }
    [[nodiscard]] std::map<int,Clothes> get_map_cloths() const
    {
        //return vec_of_clothes;
        return map_of_clothes;
    }

    void set_name(std::string name)
    {
        this->name = name;
    }
    void set_location(std::string location)
    {
        this->location = location;
    }
    void add_clothes(Clothes& obj,const int key)
    {
        map_of_clothes.insert(std::make_pair(key,obj));
    }
    void print_map()
    {
        for(auto elem : map_of_clothes)
        {
            std::cout << elem.first << ":";
            elem.second.show();
        }
    }
    std::map<int,Clothes> delete_f_storage(int key)
    {
        if(map_of_clothes.empty())
        {
            throw string("size error, map is empty");
        }
        map_of_clothes.erase(key);
        return map_of_clothes;
    }
    std::map<int,Clothes> delete_in_range(int left, int right)
    {
        /*
         Iterator to an element with key equivalent to key. If no such element is found, past-the-end (see end()) iterator is returned.
        */
        auto iterator1 = map_of_clothes.find(left);
        auto iterator2 = map_of_clothes.find(right);
        map_of_clothes.erase(iterator1, iterator2);
        return map_of_clothes;
    }
};
#endif //EXCEPTIONS_L2_SHOP_H
