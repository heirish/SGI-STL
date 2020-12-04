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
    std::unordered_map<const char *, int> days{
        {"january", 31},
        {"Feb", 28},
        {"mar", 31},
        {"apr", 30},
        {"may", 31},
        {"june", 30},
        {"july", 31},
        {"aug", 31},
        {"sep", 30},
        {"oct", 31},
        {"nov", 30},
        {"dec", 31}};
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