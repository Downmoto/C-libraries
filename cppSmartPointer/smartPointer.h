#ifndef SHACO_SMARTPOINTER_H_
#define SHACO_SMARTPOINTER_H_

namespace shaco
{
    class SharedCounter
    {
        unsigned int m_cnt;

    public:
        SharedCounter() { m_cnt = 0; }

        unsigned int count() const { return m_cnt; }

        void operator++() { m_cnt++; }
        void operator++(int) { m_cnt++; }
        void operator--() { m_cnt--; } 
        void operator--(int) { m_cnt--; } 
    };

    template<typename T>
    class SmartPointer
    {
    protected:
        T* m_ptr;

    public:
        virtual ~SmartPointer();

        T* get() const { return m_ptr; }
        T& operator*() { return *m_ptr; }
        T* operator->() { return m_ptr; }
    };

    template<typename T>
    class UniquePointer : private SmartPointer<T>
    {
    public:
        explicit UniquePointer(T* ptr) { m_ptr = ptr; };
        ~UniquePointer() override { delete m_ptr; };
    };

    template<typename T>
    class SharedPointer : private SmartPointer<T>
    {
        SharedCounter* m_count;

    public:
        explicit SharedPointer(T* ptr)
        {
            m_ptr = ptr;
            m_count = new SharedCounter();

            (*m_count)++;
        }

        SharedPointer(SharedPointer<T>& ptr)
        {
            m_ptr = ptr;
            m_count = ptr.m_count;

            (*m_count)++;
        }

        ~SharedPointer() override
        {
            (*m_count)--;
            if (m_count->count() == 0)
            {
                delete m_ptr;
                delete m_count;
            }
        }
    };

} // namespace shaco

#endif