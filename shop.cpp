//
// Created by egor on 17.05.20.
//
#include "shop.h"

Shop::Shop()
{
    map_of_clothes = std::map<int,Clothes> ();
    std::cout << "Shop constructor" << std::endl;
}
Shop::Shop(std::map<int, Clothes> clothes_map, string name, string location) :
map_of_clothes(std::move(clothes_map)), name(std::move(name)),location(std::move(location))
{

}
std::map<int, Clothes> Shop::get_map_cloths() const
{
    return map_of_clothes;
}
string Shop::get_location() const
{
    return location;
}
string Shop::get_name() const
{
    return name;
}
void Shop::set_name(std::string name)
{
    this->name = name;
}
void Shop::set_location(std::string location)
{
    this->location = location;
}
void Shop::add_clothes(Clothes &obj, const int key)
{
    map_of_clothes.insert(std::make_pair(key,obj));
}
/*void Shop::print_map()
{
    for(auto elem : map_of_clothes)
    {
        std::cout << elem.first << ":";
        elem.second.show();
    }
}
 */
std::map<int, Clothes> Shop::delete_f_storage(int key)
{
    if(map_of_clothes.empty())
    {
        throw string("size error, map is empty");
    }
    map_of_clothes.erase(key);
    return map_of_clothes;
}
std::map<int, Clothes> Shop::delete_in_range(int left, int right)
{
    /*
        Iterator to an element with key equivalent to key. If no such element is found, past-the-end (see end()) iterator is returned.
    */
    auto iterator1 = map_of_clothes.find(left);
    auto iterator2 = map_of_clothes.find(right);
    map_of_clothes.erase(iterator1, iterator2);
    return map_of_clothes;
}