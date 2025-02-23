#include "containers.hpp"

namespace Container
{
    template <typename T>
    class Array : public IContainer<T>
    {
    public:
        Array();
        ~Array();

        void push_back(const T &value) override;
        void insert(const size_t &pos, const T &value) override;
        void erase(const size_t &pos) override;
        size_t size() const override;

        T &operator[](const size_t &pos) const override;

    private:
        size_t m_size;
        T *m_array;
    };

    template <typename T>
    inline Array<T>::Array() : m_size{0}, m_array{nullptr}
    {
    }

    template <typename T>
    inline Array<T>::~Array()
    {
        if (m_array != nullptr)
        {
            delete[] m_array;
        }
    }

    template <typename T>
    inline void Array<T>::push_back(const T &value)
    {
        T *new_array = new T[m_size + 1];

        for (size_t i = 0; i < m_size; i++)
        {
            new_array[i] = m_array[i];
        }

        new_array[m_size] = value;

        delete[] m_array;

        m_array = new_array;
        ++m_size;
    }

    template <typename T>
    inline void Array<T>::insert(const size_t &pos, const T &value)
    {
        if (pos >= m_size)
        {
            push_back(value);
            return;
        }

        T *new_array = new T[m_size + 1];

        for (size_t i = 0; i < pos; i++)
        {
            new_array[i] = m_array[i];
        }

        new_array[pos] = value;

        for (size_t i = pos; i < m_size; i++)
        {
            new_array[i + 1] = m_array[i];
        }

        delete m_array;

        m_array = new_array;
        ++m_size;
    }

    template <typename T>
    inline void Array<T>::erase(const size_t &pos)
    {
        if (pos >= m_size)
        {
            return;
        }

        T *new_array = new T[m_size - 1];

        for (size_t i = 0; i < pos; i++)
        {
            new_array[i] = m_array[i];
        }

        for (size_t i = pos; i < m_size - 1; i++)
        {
            new_array[i] = m_array[i + 1];
        }

        delete[] m_array;

        m_array = new_array;
        --m_size;
    }

    template <typename T>
    inline size_t Array<T>::size() const
    {
        return m_size;
    }

    template <typename T>
    inline T &Array<T>::operator[](const size_t &pos) const
    {
        if (pos >= m_size)
        {
            return m_array[m_size - 1];
        }

        return m_array[pos];
    }
} // namespace Container
