#include "containers.hpp"

namespace Container
{
    template <typename T>
    class List : public IContainer<T>
    {
    public:
        void push_back(const T &value) override;
        void insert(const size_t &pos, const T &value) override;
        void erase(const size_t &pos) override;
        size_t size() const override;

        T &operator[](const size_t &pos) const override;

    private:
        size_t m_size;
        T *m_array;
    };
} // namespace Container
