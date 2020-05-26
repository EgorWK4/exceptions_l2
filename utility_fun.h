//
// Created by egor on 25.05.20.
//

#ifndef EXCEPTIONS_L2_UTILITY_FUN_H
#define EXCEPTIONS_L2_UTILITY_FUN_H
#include <fstream>
std::string load(const std::string& path)
{
    std::ifstream file(path);
    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}
void show_vector(const std::vector<std::pair<std::string,std::string>>& v )
{
    //utility function currently not used;
    for(const auto& elem : v)
    {
        std::cout << elem.first << "  "<<elem.second << std::endl;
    }
}
template <typename Key, typename Value>
std::ostream& operator << (std::ostream& out, const std::map<Key,Value>& vi)
{

    for(const auto& i : vi)
    {
        out << "id :" << i.first <<std::setw(5) <<std::cout.fill('_')<<  i.second <<  '\n';
    }
    return out;
}
template <typename key, typename value>
std::vector<std::pair<key,value>> Map2Vector(const std::map<key,value>& mapp)
{
    return std::vector<std::pair<key,value>>(mapp.begin(),mapp.end());
}
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

struct Price_Predicate
{
    bool operator()(Clothes& lhs, Clothes& rhs) const
    {
        return lhs.get_price() < rhs.get_price();
    }
};

template <typename Key, typename Value>
void print_map(const std::map<Key,Value>& obj)
{
    for(const auto& elem : obj)
    {
        std::cout << " Key " << elem.first << '\n';
        std::cout << " Value " << elem.second << '\n';
    }
}


#endif //EXCEPTIONS_L2_UTILITY_FUN_H
