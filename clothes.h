//
// Created by egor on 5.05.20.
//
//

#ifndef EXCEPTIONS_L2_CLOTHES_H
#define EXCEPTIONS_L2_CLOTHES_H
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
#include <map>
#include <iostream>

enum sizes {XSS,XS,S,M,L,XL,XXL};
using std::string;

class Clothes{
    string name;
    sizes size_;
    string color;
    float price;

public:
     /*static string sizes_map(sizes s) {
        std::vector<string> map_of_sizes{"XSS", "XS", "S", "M", "L", "XL", "XXL"};
        return map_of_sizes[(int) s];
    }
      */
    [[nodiscard]] string sizes_map() const{
        std::map<sizes,string> map_of_sizes{
                {XSS,"XSS"},{XS,"XS" },
                {S,"S" },{M,"M" },{L,"L" },
                {XL,"XL" },{XXL,"XXL" }};
        return map_of_sizes.at(size_);
    }
    Clothes();
    explicit Clothes(sizes size, string name = "", string color = "", float price = 0);

    void set_name(const string name);
    void set_color(const string color);
    void set_size(sizes size);
    void set_price(const float price);
    [[nodiscard]] std::string get_name() const;
    [[nodiscard]] std::string get_color() const;
    [[nodiscard]] sizes get_size() const;
    [[nodiscard]] float get_price() const;
    //void show();
    friend std::ostream &operator<<( std::ostream &output, const Clothes &D )
    {
        output << "[";
        output <<"Clothes name : "<< D.name << std::setw(5)<<"";
        output << "Color : "<<D.color << std::setw(5)<<"";
        output << "Price : " << D.price << std::setw(5)<<"";
        output << "Size : " << D.sizes_map() << std::setw(5) << "]" << std::endl;
        return output;
    }


};

#endif //EXCEPTIONS_L2_CLOTHES_H
