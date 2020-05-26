//
// Created by egor on 21.05.20.
//

#ifndef EXCEPTIONS_L2_FILE_WRITING_H
#define EXCEPTIONS_L2_FILE_WRITING_H
#include <fstream>
#include <vector>
#include <regex>
#include "utility_fun.h"

bool to_file(const Shop& obj,const string& file_path,int& sort)
{
// we can't sort default std::map, so lets convert it to std::vector<std::pair<int,CLothes>> v;
    std::ofstream out (file_path);
    if(out.fail())
    {
        std::cout << "Problems with opening file" << std::endl;
        return false;
    }
    auto mapp = obj.get_map_cloths();
    auto v = Map2Vector(mapp);
    // замыкание sort в [];
    std::sort(v.begin(), v.end(),
              [sort](const std::pair<int,Clothes>& x, const std::pair<int,Clothes>& y)
              {
                  if(sort == 0)
                  {return x.second.get_price() < y.second.get_price();}
                  else
                  {return x.second.get_price() > y.second.get_price();}
              });
    for(const auto& elem : v)
    {
        out << elem.first << ":" << "\n";
        out << elem.second << "\n";
    }
    out.close();
    std::cout << "File writing was successful" << std::endl;
    return true;
}
bool wallet_to_file( Customer &obj,const std::string& file_path)
{

    std::ofstream  out (file_path);
    if(out.fail())
    {
        std::cout << "Problems with opening file" << std::endl;
        return false;
    }
    auto wallet = obj.get_clothes();
    for(const auto& elem : wallet)
    {
      out << elem << '\n';
    }
    out.close();
    return true;
}



std::vector<string> read_file_to_string(const std::string& path)
{
    // currently not used/ Wanted to change values directly in txt file without any interaction with data structures/
    std::vector<string> test1;
    //std::map<string,string> test2;
    //std::vector<std::pair<std::string,std::string>> test;
    std::string a = load(path);
    std::regex rgx(R"(([a-zA-Z \-0-9\.]+)\:([a-zA-Z \-0-9\.]+))");
    auto words_begin = std::sregex_iterator(a.begin(), a.end(), rgx);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end;  ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
        //std::cout << match_str << '\n';
        for (std::size_t i = 0; i < match.size(); ++i) {
            //std::cout << i << ": '" << match[i].str() << "'\n";
            if (i == 2) {
                test1.push_back(match[2].str());
            }
        }
    }
    return test1;
}
void read_file(const std::string& file_path)
{
    string name;
    std::ifstream dataFile(file_path);
    while (!dataFile.fail() && !dataFile.eof() )
    {
        dataFile >> name ;
        std::cout << name << std::endl;
    }
    dataFile.close();
}

#endif //EXCEPTIONS_L2_FILE_WRITING_H
