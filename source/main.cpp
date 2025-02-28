#include "array.hpp"
#include "list.hpp"
#include <iostream>

template <typename T>
void print(const Container::IContainer<T> &arr)
{
    std::cout << arr.name() << std::endl;
    std::cout << "size: " << arr.size() << std::endl;
    std::cout << "\t";

    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

template <typename T>
void print_containers(Container::IContainer<T> **containers, const size_t &size)
{
    for (size_t i = 0; i < size; i++)
    {
        print(*containers[i]);
    }
}

int main()
{
    constexpr size_t containers_count = 2;
    Container::IContainer<int> *containers[containers_count];

    containers[0] = new Container::Array<int>{};
    containers[1] = new Container::List<int>{};

    std::cout << "push_back" << std::endl;
    for (size_t i = 0; i < containers_count; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            containers[i]->push_back(j);
        }
    }

    print_containers(containers, containers_count);

    std::cout << "erase" << std::endl;
    for (size_t i = 0; i < containers_count; i++)
    {
        containers[i]->erase(2);
        containers[i]->erase(3);
        containers[i]->erase(4);
    }

    print_containers(containers, containers_count);

    std::cout << "insert" << std::endl;
    for (size_t i = 0; i < containers_count; i++)
    {
        containers[i]->insert(0, 10);
    }

    print_containers(containers, containers_count);

    std::cout << "insert" << std::endl;
    for (size_t i = 0; i < containers_count; i++)
    {
        containers[i]->insert(containers[i]->size() / 2, 20);
    }

    print_containers(containers, containers_count);

    std::cout << "push_back" << std::endl;
    for (size_t i = 0; i < containers_count; i++)
    {
        containers[i]->push_back(30);
    }

    print_containers(containers, containers_count);

    Container::Array<int> array1{};
    array1.push_back(5);
    Container::Array<int> array2{std::move(array1)};

    print(array1);
    print(array2);

    array1 = std::move(array2);

    print(array1);
    print(array2);

    Container::List<int> list1{};
    list1.push_back(7);
    Container::List<int> list2{std::move(list1)};

    print(list1);
    print(list2);

    list1 = std::move(list2);

    print(list1);
    print(list2);
    return 0;
}