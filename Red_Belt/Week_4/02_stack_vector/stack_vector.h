#pragma once

#include <array>
#include <stdexcept>
using namespace std;

template <typename T, size_t N>
class StackVector {
public:
    explicit StackVector(size_t a_size = 0) {
        if(a_size > capacity_) {
            throw invalid_argument("out or range");
        } else {
            size_ = a_size;
        }
    }
    
    T& operator[](size_t index) {
        return a[index];
    }
    
    const T& operator[](size_t index) const {
        return a[index];
    }
    
    typename array<T, N>::iterator begin()             { return &a[0];       }
    typename array<T, N>::iterator end()               { return &a[size_];   }
    typename array<T, N>::const_iterator begin() const { return &a[0];       }
    typename array<T, N>::const_iterator end()   const { return &a[size_];   }
    
    size_t Size() const {
        return size_;
    }
    size_t Capacity() const {
        return capacity_;
    }
    
    void PushBack(const T& value) {
        if(size_ == capacity_) {
            throw overflow_error("overflow");
        } else {
            a[size_] = value;
            size_++;
        }
    }
    
    T PopBack() {
        if(size_ == 0) {
            throw underflow_error("underflow");
        } else {
            size_--;
            return a[size_];
        }
    }
    
private:
    size_t size_;
    size_t capacity_ = N;
    array<T, N> a;
};



