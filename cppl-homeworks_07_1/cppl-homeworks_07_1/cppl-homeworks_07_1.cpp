// cppl-homeworks_07_1.cpp 

#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
 
class PAIR
{
public:
    char s;
    int a;
};

int main()
{ 
    std::map<char, int> map; 
    std::string in_str= "Hello world!!";
    std::cout << "[IN]: " << in_str << std::endl;

    for (char abc : in_str) map[abc]++;

    std::vector <PAIR> vec;
    PAIR temp;
    for (auto const& pair : map) 
    {
        temp.s = pair.first;
        temp.a = pair.second;
        vec.push_back(temp);
    }
    std::sort(vec.begin(), vec.end(), [](PAIR a,PAIR b)
        {
            return a.a > b.a;
        });
    
    std::cout << "[OUT]: " << std::endl;
    for (int i = 0; i < vec.size(); i++)
    {     
        std::cout << vec[i].s << ": " << vec[i].a << std::endl;
    }
    return 0;
}