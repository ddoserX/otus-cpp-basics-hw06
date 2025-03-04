#pragma once

#include "../source/list.hpp"
#include <gtest/gtest.h>

/*
- создание контейнера
- вставка элементов в конец
- вставка элементов в начало
- вставка элементов в середину
- удаление элементов из конца
- удаление элементов из начала
- удаление элементов из середины
- получение элементов из контейнера
- получение размера контейнера (фактическое количество элементов)
*/

TEST(List, CreateContainer)
{
    Container::List<int> list;
    constexpr size_t expectedSize = 0;

    const size_t currectSize = list.size();

    ASSERT_EQ(expectedSize, currectSize);
}

TEST(List, PushBack)
{
    Container::List<int> list;
    constexpr size_t expectedValue = 10;
    constexpr size_t expectedSize = 1;

    list.push_back(expectedValue);

    const size_t currectSize = list.size();

    ASSERT_EQ(expectedSize, currectSize);

    const int currectValue = list[0];

    ASSERT_EQ(expectedValue, currectValue);
}

TEST(List, InsertToFirts)
{
    Container::List<int> expectedList{{10, 0, 1, 2, 3, 4, 5}};
    Container::List<int> currectList{{0, 1, 2, 3, 4, 5}};

    constexpr size_t expectedValue = 10;
    currectList.insert(0, expectedValue);

    ASSERT_EQ(expectedList.size(), currectList.size());

    for (size_t i = 0; i < expectedList.size(); i++)
    {
        ASSERT_EQ(expectedList[i], currectList[i]);
    }
}

TEST(List, InsertToMiddle)
{
    Container::List<int> expectedList{{0, 1, 2, 10, 3, 4, 5}};
    Container::List<int> currectList{{0, 1, 2, 3, 4, 5}};

    constexpr size_t expectedValue = 10;
    currectList.insert(currectList.size() / 2, expectedValue);

    ASSERT_EQ(expectedList.size(), currectList.size());

    for (size_t i = 0; i < expectedList.size(); i++)
    {
        ASSERT_EQ(expectedList[i], currectList[i]);
    }
}

TEST(List, EraseFromLast)
{
    Container::List<int> expectedList{{0, 1, 2, 3, 4}};
    Container::List<int> currectList{{0, 1, 2, 3, 4, 5}};

    currectList.erase(currectList.size() - 1);

    ASSERT_EQ(expectedList.size(), currectList.size());

    for (size_t i = 0; i < expectedList.size(); i++)
    {
        ASSERT_EQ(expectedList[i], currectList[i]);
    }
}

TEST(List, EraseFromFirst)
{
    Container::List<int> expectedList{{1, 2, 3, 4, 5}};
    Container::List<int> currectList{{0, 1, 2, 3, 4, 5}};

    currectList.erase(0);

    ASSERT_EQ(expectedList.size(), currectList.size());

    for (size_t i = 0; i < expectedList.size(); i++)
    {
        ASSERT_EQ(expectedList[i], currectList[i]);
    }
}

TEST(List, EraseFromMiddle)
{
    Container::List<int> expectedList{{0, 1, 2, 4, 5}};
    Container::List<int> currectList{{0, 1, 2, 3, 4, 5}};

    currectList.erase(currectList.size() / 2);

    ASSERT_EQ(expectedList.size(), currectList.size());

    for (size_t i = 0; i < expectedList.size(); i++)
    {
        ASSERT_EQ(expectedList[i], currectList[i]);
    }
}

TEST(List, GetFromIndex)
{
    Container::List<int> currectList{{0, 1, 2, 3, 4, 5}};

    ASSERT_EQ(0, currectList[0]);
    ASSERT_EQ(2, currectList[2]);
    ASSERT_EQ(4, currectList[4]);
}

TEST(List, GetSize)
{
    Container::List<int> currectList{{0, 1, 2, 3, 4, 5}};
    constexpr size_t expectedSize = 6;

    ASSERT_EQ(expectedSize, currectList.size());
}

TEST(List, CopyCtor)
{
    Container::List<int> expectedList{{0, 1, 2, 3, 4, 5}};
    expectedList.push_back(6);

    Container::List<int> currectList{expectedList};

    ASSERT_EQ(expectedList.size(), currectList.size());

    for (size_t i = 0; i < expectedList.size(); i++)
    {
        ASSERT_EQ(expectedList[i], currectList[i]);
    }
}

TEST(List, IsEmpty)
{
    Container::List<int> list{{0}};

    list.erase(0);

    ASSERT_TRUE(list.empty());
}

TEST(List, CopyOperator)
{
    Container::List<int> expectedList{{0, 1, 2, 3, 4, 5}};
    Container::List<int> currectList;

    currectList = expectedList;

    ASSERT_EQ(expectedList.size(), currectList.size());

    for (size_t i = 0; i < expectedList.size(); i++)
    {
        ASSERT_EQ(expectedList[i], currectList[i]);
    }
}

TEST(List, MoveOperator)
{
    Container::List<int> list{{0, 1, 2, 3, 4, 5}};
    const size_t expectedSize = list.size();

    Container::List<int> currectList{std::move(list)};

    ASSERT_EQ(0, list.size());
    ASSERT_TRUE(list.empty());
    ASSERT_FALSE(currectList.empty());
    ASSERT_EQ(expectedSize, currectList.size());
}

TEST(List, Clear)
{
    Container::List<int> list{{0, 1, 2, 3, 4, 5}};

    list.clean();

    ASSERT_TRUE(list.empty());
}