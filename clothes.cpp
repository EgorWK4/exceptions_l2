//
// Created by egor on 17.05.20.
//

#include "clothes.h"
Clothes::Clothes()
{
    name = string();
    size_ = sizes();
    color = string();
    price = float();
}
Clothes::Clothes(sizes size, string name, string color, float price)  :
name(std::move(name)), size_(size), color(std::move(color)), price(price) {std::cout << "Clothes constructor" << std::endl;}
void Clothes::set_name(const string name)
{
    this->name = name;
}
void Clothes::set_price(const float price)
{
    this->price = price;
}
void Clothes::set_size(sizes size)
{
    this->size_ = size;
}
void Clothes::set_color(const string color)
{
    this->color = color;
}
float Clothes::get_price() const
{
    return price;
}
std::string Clothes::get_color() const
{
    return color;
}
std::string Clothes::get_name() const
{
    return name;
}
sizes Clothes::get_size() const
{
    return size_;
}
/*void Clothes::show()
{
    std::cout<< "[";
    std::cout <<"|Clothes name :"  << name;
    std::cout << "|Color :" << color;
    std::cout << "|Price :" << price;
    std::cout << "|Size :" << sizes_map(size_) << "]" << std::endl;
}
*/