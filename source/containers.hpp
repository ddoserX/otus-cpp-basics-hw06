#pragma once

#include <initializer_list>

namespace Container
{
    using size_t = unsigned long long;

    template <typename T>
    class IContainer
    {
    public:
        virtual void push_back(const T &value) = 0;
        virtual void insert(const size_t &pos, const T &value) = 0;
        virtual void erase(const size_t &pos) = 0;
        virtual size_t size() const = 0;
        virtual bool empty() const = 0;
        virtual const char *name() const = 0;

        virtual T &operator[](const size_t &pos) const = 0;
    };
} // namespace Container
