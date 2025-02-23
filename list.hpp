#include "containers.hpp"

namespace Container
{
    template <typename T>
    struct Node
    {
        Node *previous;
        Node *next;
        T data;
    };

    template <typename T>
    class List : public IContainer<T>
    {
    public:
        List();

        void push_back(const T &value) override;
        void insert(const size_t &pos, const T &value) override;
        void erase(const size_t &pos) override;
        size_t size() const override;

        T &operator[](const size_t &pos) const override;

    private:
        size_t m_size;
        Node<T> m_node;
        Node<T> *m_previous;
        Node<T> *m_next;
    };

    template <typename T>
    inline List<T>::List() : m_size{0}, m_node{}, m_next{nullptr}, m_previous{nullptr}
    {
    }

    template <typename T>
    inline void List<T>::push_back(const T &value)
    {
    }
} // namespace Container
