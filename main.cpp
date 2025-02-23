#include "array.hpp"
#include <iostream>

template <typename T>
void print(const Container::Array<T> &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "size: " << arr.size() << std::endl;
}

int main()
{
    Container::Array<int> arr;

    for (size_t i = 0; i < 10; i++)
    {
        arr.push_back(i);
    }

    print(arr);

    arr.erase(2);
    arr.erase(3);
    arr.erase(4);

    print(arr);

    arr.insert(0, 10);

    print(arr);

    arr.insert(arr.size() / 2, 20);

    print(arr);

    arr.push_back(30);

    print(arr);

    return 0;
}