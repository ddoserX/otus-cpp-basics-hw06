#pragma once

#include "containers.hpp"

namespace Container
{
    template <typename T>
    struct Node
    {
        Node *prev;
        Node *next;
        T data;
    };

    template <typename T>
    class List : public IContainer<T>
    {
    public:
        List();
        ~List() override;
        List(std::initializer_list<T> l);
        List(List<T> &rhs) noexcept;
        List(List<T> &&rhs) noexcept;

        void push_back(const T &value) override;
        void insert(const size_t &pos, const T &value) override;
        void erase(const size_t &pos) override;
        size_t size() const override;
        bool empty() const override;
        const char *name() const override;
        void clean();

        T &operator[](const size_t &pos) const override;
        List<T> &operator=(List<T> &rhs) noexcept;
        List<T> &operator=(List<T> &&rhs) noexcept;

    private:
        size_t m_size;
        Node<T> *m_first;
        Node<T> *m_last;

        Node<T> *get(const size_t &pos) const;
    };

    template <typename T>
    inline List<T>::List() : m_size{0}, m_first{nullptr}, m_last{nullptr}
    {
    }

    template <typename T>
    inline List<T>::~List()
    {
        clean();
    }

    template <typename T>
    inline List<T>::List(std::initializer_list<T> l) : m_size(0), m_first{nullptr}, m_last{nullptr}
    {
        auto ptr = l.begin();

        for (size_t i = 0; i < l.size(); i++)
        {
            push_back(ptr[i]);
        }
    }

    template <typename T>
    inline List<T>::List(List<T> &rhs) noexcept
        : m_size(0), m_first{nullptr}, m_last{nullptr}
    {
        for (size_t i = 0; i < rhs.size(); i++)
        {
            push_back(rhs[i]);
        }
    }

    template <typename T>
    inline List<T>::List(List<T> &&rhs) noexcept
    {
        m_first = rhs.m_first;
        m_last = rhs.m_last;
        m_size = rhs.m_size;

        rhs.m_first = nullptr;
        rhs.m_last = nullptr;
        rhs.m_size = 0;
    }

    template <typename T>
    inline void List<T>::push_back(const T &value)
    {
        Node<T> *new_node = new Node<T>{};
        new_node->data = value;

        if (m_last == nullptr)
        {
            m_last = new_node;
            m_first = new_node;
        }
        else
        {
            new_node->prev = m_last;
            new_node->prev->next = new_node;
            m_last = new_node;
        }

        m_size += 1;
    }

    template <typename T>
    inline void List<T>::insert(const size_t &pos, const T &value)
    {
        if (pos >= m_size)
        {
            push_back(value);
            return;
        }

        Node<T> *ptr = get(pos);

        if (ptr == nullptr)
        {
            return;
        }

        Node<T> *new_node = new Node<T>{};
        new_node->data = value;

        if (ptr->prev != nullptr)
        {
            new_node->prev = ptr->prev;
            ptr->prev->next = new_node;
        }
        else
        {
            m_first = new_node;
        }

        new_node->next = ptr;
        ptr->prev = new_node;

        m_size += 1;
    }

    template <typename T>
    inline void List<T>::erase(const size_t &pos)
    {
        if (pos >= m_size)
        {
            return;
        }

        Node<T> *ptr = get(pos);

        if (ptr == nullptr)
        {
            return;
        }

        if (ptr->prev != nullptr)
        {
            ptr->prev->next = ptr->next;
        }
        else
        {
            m_first = ptr->next;
        }

        if (ptr->next != nullptr)
        {
            ptr->next->prev = ptr->prev;
        }
        else
        {
            m_last = ptr->prev;
        }

        delete ptr;
        m_size -= 1;
    }

    template <typename T>
    inline size_t List<T>::size() const
    {
        return m_size;
    }

    template <typename T>
    inline bool List<T>::empty() const
    {
        if (m_size == 0 && m_first == nullptr && m_last == nullptr)
        {
            return true;
        }

        return false;
    }

    template <typename T>
    inline const char *List<T>::name() const
    {
        return "container::list<T>";
    }

    template <typename T>
    inline T &List<T>::operator[](const size_t &pos) const
    {
        Node<T> *ptr;

        if (pos >= m_size)
        {
            ptr = get(m_size - 1);
        }
        else
        {
            ptr = get(pos);
        }

        return ptr->data;
    }

    template <typename T>
    inline List<T> &List<T>::operator=(List<T> &rhs) noexcept
    {
        if (this == &rhs)
        {
            return *this;
        }

        if (rhs.m_size == 0)
        {
            return *this;
        }

        if (this->empty() == false)
        {
            this->clean();
        }

        for (size_t i = 0; i < rhs.m_size; i++)
        {
            this->push_back(rhs[i]);
        }

        return *this;
    }

    template <typename T>
    inline List<T> &List<T>::operator=(List<T> &&rhs) noexcept
    {
        if (&rhs != this)
        {
            clean();

            m_first = rhs.m_first;
            m_last = rhs.m_last;
            m_size = rhs.m_size;

            rhs.m_first = nullptr;
            rhs.m_last = nullptr;
            rhs.m_size = 0;
        }

        return *this;
    }

    template <typename T>
    inline Node<T> *List<T>::get(const size_t &pos) const
    {
        if (pos >= m_size)
        {
            return nullptr;
        }

        Node<T> *ptr = m_first;
        for (size_t i = 0; i < pos; ++i)
        {
            ptr = ptr->next;
        }

        return ptr;
    }
    template <typename T>
    inline void List<T>::clean()
    {
        Node<T> *ptr = m_first;

        while (ptr != nullptr)
        {
            Node<T> *next = ptr->next;
            delete ptr;
            ptr = next;
        }

        m_first = nullptr;
        m_last = nullptr;
        m_size = 0;
    }
} // namespace Container
