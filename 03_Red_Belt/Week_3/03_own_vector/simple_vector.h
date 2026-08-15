#pragma once

#include <cstddef>

template <typename T>
class SimpleVector {
public:
    SimpleVector();
    explicit SimpleVector(size_t size);
    ~SimpleVector();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    T* begin();
    T* end();

    const T* begin() const;
    const T* end() const;

    size_t Size() const;
    size_t Capacity() const;
    void PushBack(const T& value);

private:
    T* data;
    size_t capacity_;
    size_t size_;
};

template <typename T>
SimpleVector<T>::SimpleVector()
    : data(nullptr)
    , capacity_(0)
    , size_(0)
{
}

template <typename T>
SimpleVector<T>::SimpleVector(size_t size)
    : data(new T[size])
    , capacity_(size)
    , size_(size)
{
}

template <typename T>
SimpleVector<T>::~SimpleVector() {
    delete[] data;
}

template <typename T>
T& SimpleVector<T>::operator[](size_t index) {
    return data[index];
}

template <typename T>
const T& SimpleVector<T>::operator[](size_t index) const {
    return data[index];
}

template <typename T>
T* SimpleVector<T>::begin() {
    return data;
}

template <typename T>
T* SimpleVector<T>::end() {
    return data + size_;
}

template <typename T>
const T* SimpleVector<T>::begin() const {
    return data;
}

template <typename T>
const T* SimpleVector<T>::end() const {
    return data + size_;
}

template <typename T>
size_t SimpleVector<T>::Size() const {
    return size_;
}

template <typename T>
size_t SimpleVector<T>::Capacity() const {
    return capacity_;
}

template <typename T>
void SimpleVector<T>::PushBack(const T& value) {
    if(size_ == capacity_) {
        if(size_ == 0) {
            capacity_ = 1;
            
        }
        T* old_data = data;
        data = new T[capacity_ * 2];
        for(int i = 0; i < size_; i++) {
            data[i] = old_data[i];
        }
        delete[] old_data;
        capacity_ *= 2;
        
    }
    data[size_] = value;
    size_++;
}
