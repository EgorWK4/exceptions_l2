//
// Created by egor on 5.05.20.
//
//

#ifndef EXCEPTIONS_L2_CLOTHES_H
#define EXCEPTIONS_L2_CLOTHES_H
#include <string>
#include <utility>
#include <vector>

enum sizes {XSS,XS,S,M,L,XL,XXL};
using std::string;

class Clothes {
    string name;
    sizes size_;
    string color;
    float price{};



public:
    static string sizes_map(sizes s) {
        std::vector<string> map_of_sizes{"XSS", "XS", "S", "M", "L", "XL", "XXL"};
        return map_of_sizes[(int) s];
    }
    Clothes() = default;

    explicit Clothes(sizes size, string name = "", string color = "", float price = 0) :
            name(std::move(name)), size_(size), color(std::move(color)), price(price) {}

    void set_name(const string name) {
        this->name = name;
    }

    void set_color(const string color) {
        this->color = color;
    }

    void set_size(sizes size) {
        this->size_ = size;
    }

    void set_price(const float price) {
        this->price = price;
    }

    [[nodiscard]] std::string get_name() const
    {
        return name;
    }
    [[nodiscard]] std::string get_color() const
    {
        return color;
    }
    [[nodiscard]] sizes get_size() const
    {
        return size_;
    }
    [[nodiscard]] float get_price() const
    {
        return price;
    }

     void show()
    {
        std::cout<< "[";
        std::cout << "Clothes name :"  << name << std::endl;
        std::cout << "Color :" << color << std::endl;
        std::cout << "Price : " << price << std::endl;
        std::cout << "Size :" << sizes_map(size_) << "]" << std::endl;
    }
        friend std::ostream &operator<<( std::ostream &output, const Clothes &D ) {
        output << "Name : " << D.name << " Color : " <<D.color;
        return output;
    }

};

#endif //EXCEPTIONS_L2_CLOTHES_H
