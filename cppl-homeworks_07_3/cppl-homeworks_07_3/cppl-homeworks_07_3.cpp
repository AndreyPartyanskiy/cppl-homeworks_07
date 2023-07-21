// cppl-homeworks_07_3.cpp 
#include <iostream>

template <class T>
class my_vector
{
public:
    struct Error_range
    {
        int index;
    };

    T* my_vector_ = nullptr;
    int logic_ptr;
    int actual_ptr;
    
    my_vector()
    {
        my_vector_ = new T[10]{};
        logic_ptr = 0;
        actual_ptr = 10;
    };

    void push_back(T in_data)
    {
        if ((logic_ptr + 1) < actual_ptr)
        {
            my_vector_[logic_ptr] = in_data;
            ++logic_ptr;
        }
        else
        {
            int* temp = new T[actual_ptr * 2]{};
            for (int y = 0; y < actual_ptr; y++)
            {
                temp[y] = my_vector_[y];
            }
            delete[] my_vector_;
            my_vector_ = new int [actual_ptr * 2] {};
            for (int y = 0; y < actual_ptr; y++)
            {
                my_vector_[y] = temp[y];
            }
            delete[]temp;
            actual_ptr = actual_ptr * 2;
            my_vector_[logic_ptr] = in_data;
            logic_ptr++;
        }
    }
    int size()
    {
        return logic_ptr;
    }
    int capacity()
    {
        return actual_ptr;
    }
    void print()
    {
        for (int i = 0; i < logic_ptr; i++) std::cout << my_vector_[i] << " ";
        std::cout << std::endl;
    }
    
    T at(int index)
    {
        try 
        {
            if (index > logic_ptr) throw Error_range();
        }
        catch (const Error_range)
        {
            std::cerr << "Range is not correct" << "\n";
            return 0;
        }
            return  my_vector_[index];
    }
    
    ~my_vector()
    {
        delete[] my_vector_;
    }
};


int main()
{
    auto test = my_vector <int>();
    test.push_back(5);
    test.push_back(5);
    test.push_back(5);
    test.push_back(5);
    test.push_back(5);
    test.push_back(5);
    test.push_back(5);
    test.push_back(5);
    test.push_back(5);
    test.push_back(5);
    test.print();

    std::cout << test.size() << std::endl;
    std::cout << test.capacity() << std::endl;
    std::cout << test.at(13) << std::endl;   
    return 0;
}