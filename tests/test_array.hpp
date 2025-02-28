#pragma once

#include "../source/array.hpp"
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

TEST(Array, CreateContainer)
{
    Container::Array<int> array;
    constexpr size_t expectedSize = 0;

    const size_t currectSize = array.size();

    ASSERT_EQ(expectedSize, currectSize);
}

TEST(Array, PushBack)
{
    Container::Array<int> array;
    constexpr size_t expectedValue = 10;
    constexpr size_t expectedSize = 1;

    array.push_back(expectedValue);

    const size_t currectSize = array.size();

    ASSERT_EQ(expectedSize, currectSize);

    const int currectValue = array[0];

    ASSERT_EQ(expectedValue, currectValue);
}

TEST(Array, InsertToFirts)
{
    Container::Array<int> expectedArray{{10, 0, 1, 2, 3, 4, 5}};
    Container::Array<int> currectArray{{0, 1, 2, 3, 4, 5}};

    constexpr size_t expectedValue = 10;
    currectArray.insert(0, expectedValue);

    ASSERT_EQ(expectedArray.size(), currectArray.size());

    for (size_t i = 0; i < expectedArray.size(); i++)
    {
        ASSERT_EQ(expectedArray[i], currectArray[i]);
    }
}

TEST(Array, InsertToMiddle)
{
    Container::Array<int> expectedArray{{0, 1, 2, 10, 3, 4, 5}};
    Container::Array<int> currectArray{{0, 1, 2, 3, 4, 5}};

    constexpr size_t expectedValue = 10;
    currectArray.insert(currectArray.size() / 2, expectedValue);

    ASSERT_EQ(expectedArray.size(), currectArray.size());

    for (size_t i = 0; i < expectedArray.size(); i++)
    {
        ASSERT_EQ(expectedArray[i], currectArray[i]);
    }
}

TEST(Array, EraseFromLast)
{
    Container::Array<int> expectedArray{{0, 1, 2, 3, 4}};
    Container::Array<int> currectArray{{0, 1, 2, 3, 4, 5}};

    currectArray.erase(currectArray.size() - 1);

    ASSERT_EQ(expectedArray.size(), currectArray.size());

    for (size_t i = 0; i < expectedArray.size(); i++)
    {
        ASSERT_EQ(expectedArray[i], currectArray[i]);
    }
}

TEST(Array, EraseFromFirst)
{
    Container::Array<int> expectedArray{{1, 2, 3, 4, 5}};
    Container::Array<int> currectArray{{0, 1, 2, 3, 4, 5}};

    currectArray.erase(0);

    ASSERT_EQ(expectedArray.size(), currectArray.size());

    for (size_t i = 0; i < expectedArray.size(); i++)
    {
        ASSERT_EQ(expectedArray[i], currectArray[i]);
    }
}

TEST(Array, EraseFromMiddle)
{
    Container::Array<int> expectedArray{{0, 1, 2, 4, 5}};
    Container::Array<int> currectArray{{0, 1, 2, 3, 4, 5}};

    currectArray.erase(currectArray.size() / 2);

    ASSERT_EQ(expectedArray.size(), currectArray.size());

    for (size_t i = 0; i < expectedArray.size(); i++)
    {
        ASSERT_EQ(expectedArray[i], currectArray[i]);
    }
}

TEST(Array, GetFromIndex)
{
    Container::Array<int> currectArray{{0, 1, 2, 3, 4, 5}};

    ASSERT_EQ(0, currectArray[0]);
    ASSERT_EQ(2, currectArray[2]);
    ASSERT_EQ(4, currectArray[4]);
}

TEST(Array, GetSize)
{
    Container::Array<int> currectArray{{0, 1, 2, 3, 4, 5}};
    constexpr size_t expectedSize = 6;

    ASSERT_EQ(expectedSize, currectArray.size());
}

TEST(Array, CheckCorrectLenIncrease)
{
    Container::Array<int> currectArray{{0, 1, 2, 3, 4, 5}};
    const size_t expectedLen = currectArray.len() * 2;

    currectArray.push_back(6);

    ASSERT_EQ(expectedLen, currectArray.len());
}

TEST(Array, CopyCtor)
{
    Container::Array<int> expectedArray{{0, 1, 2, 3, 4, 5}};
    expectedArray.push_back(6);

    Container::Array<int> currectArray{expectedArray};

    ASSERT_EQ(expectedArray.size(), currectArray.size());
    ASSERT_EQ(expectedArray.len(), currectArray.len());

    for (size_t i = 0; i < expectedArray.size(); i++)
    {
        ASSERT_EQ(expectedArray[i], currectArray[i]);
    }
}

TEST(Array, MoveOperator)
{
    Container::Array<int> array{{0, 1, 2, 3, 4, 5}};
    const size_t expectedSize = array.size();

    Container::Array<int> currectArray{std::move(array)};

    ASSERT_EQ(0, array.size());
    ASSERT_TRUE(array.empty());
    ASSERT_FALSE(currectArray.empty());
    ASSERT_EQ(expectedSize, currectArray.size());
}