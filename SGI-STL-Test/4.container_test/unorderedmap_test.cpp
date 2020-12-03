#include <unordered_map>
#include <iostream>
#include <cstring>

struct eqstr
{
    bool operator()(const char *s1, const char *s2)
    {
        return strcmp(s1, s2) == 0;
    }
};

int main()
{
    std::unordered_map<const char *, int> days;
    days["january"] = 31;
    days["Feb"] = 28;
    days["mar"] = 31;
    days["apr"] = 30;
    days["may"] = 31;
    days["june"] = 30;
    days["july"] = 31;
    days["aug"] = 31;
    days["sep"] = 30;
    days["oct"] = 31;
    days["nov"] = 30;
    days["dec"] = 31;
    for (int i = 0; i < days.bucket_count(); i++)
    {
        std::cout << "bucket " << i << ",size:" << days.bucket_size(i) << std::endl;
    }

    std::cout << "january days:" << days["january"] << std::endl;
    std::cout << "january days:" << days["Feb"] << std::endl;

    for (const auto &item : days)
    {
        std::cout << item.first << " days:" << item.second << std::endl;
    }
}