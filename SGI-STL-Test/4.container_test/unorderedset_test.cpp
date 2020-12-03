#include <unordered_set>
#include <iostream>
#include <cstring>

struct eqstr
{
    bool operator()(const char *s1, const char *s2) const
    {
        return strcmp(s1, s2) == 0;
    }
};

void look_up(const std::unordered_set<const char *, std::hash<const char *>, eqstr> &set, const char *word)
{
    auto it = set.find(word);
    std::cout << "found " << word << " ? " << (it != set.end()) << std::endl;
}

int main()
{
    std::unordered_set<const char *, std::hash<const char *>, eqstr> set;
    std::cout << "bucket count" << set.bucket_count() << std::endl;
    set.emplace("kiwi");
    set.emplace("plum");
    set.emplace("apple");
    set.emplace("mango");
    set.emplace("apricot");
    set.emplace("banana");
    for(int i=0; i<set.bucket_count(); i++) {
        std::cout << "bucket " << i << ",size:" << set.bucket_size(i) << std::endl;
    }

    look_up(set, "mango");
    look_up(set, "durian");
    for (const auto &item : set)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}