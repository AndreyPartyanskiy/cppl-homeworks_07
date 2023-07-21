// cppl-homeworks_07_2.cpp 

#include <iostream>
#include <set>
int main()
{
    int a = 0;
    int b = 0;
    std::cout << "[IN]: \n";
    std::cin >> a;
    std::set <int> my_set;
    for (int i = 0; i < a; i++) 
    {
        std::cin >> b;
        my_set.insert(b);
    }
    std::cout << "[OUT]: \n";
    for (auto it = my_set.rbegin();it!=my_set.rend();++it)
    std::cout << *it << std::endl;
    return 0;
}
