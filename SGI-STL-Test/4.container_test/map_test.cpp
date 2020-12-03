#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<std::string, int> simap;
    simap["awef"] = 1;
    simap["zewoifsdf"] = 2;
    simap["besd"] = 3;
    simap["kwefs"] = 4;
    //会区分大小写
    simap[std::string("Aawe")] = 5;
    simap[std::string("aawe")] = 6;

    std::map<std::string, int>::iterator it = simap.begin();
    for (; it != simap.end(); it++)
    {
        std::cout << it->first << "," << it->second << std::endl;
    }

    std::pair<std::string, int> value(std::string("david"), 5);
    const auto[iter, succeed] = simap.insert(value);
    std::cout << "insert succeed?" << succeed << std::endl;

    //insert twice will failed because of unique key in map
    const auto[iter1, succeed1] = simap.insert(value);
    std::cout << "insert twice succeed ? " << succeed1 << std::endl;

    std::map<std::string, int>::iterator ite = simap.find("david");
    if (ite != simap.end())
    {
        std::cout << "found " << ite->first << ",value:" << ite->second << std::endl;
    }
    ite->second = 9;
    std::cout << "after change, " << ite->first << "'s value is :" << ite->second << std::endl;
}