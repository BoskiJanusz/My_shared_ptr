#pragma once

namespace my
{
    template <class T>
    class shared_ptr
    {
    private:
        T* ptr_ = nullptr;
        size_t* counter_ = nullptr;
    public:
        shared_ptr(){}
        shared_ptr(T* ptr) : ptr_(ptr), counter_(new size_t{1}){}
        shared_ptr(const shared_ptr &){}
        shared_ptr(shared_ptr &&){}
        shared_ptr& operator=(const shared_ptr &){}
        shared_ptr& operator=(shared_ptr &&){}
        operator bool() const;
        T* operator->() const
        {
            return ptr_;
        }
        T& operator*() const
        {
            return *(ptr_);
        }
        T* get() const
        {
            return ptr_;
        }
        void reset();
        long use_count() const;
        ~shared_ptr(){}
    };
}
