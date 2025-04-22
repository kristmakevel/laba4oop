#include <memory>
#include <iostream>
#include <stdexcept>

#ifndef MYARRAY
#define MYARRAY

template <class T, int size>
class MyArray {
public:
    ~MyArray() = default;

    MyArray() : size_(size) {
        data_ = std::make_unique<T[]>(size_);
    }

    MyArray(const MyArray& arr) : size_(arr.size_) {
        data_ = std::make_unique<T[]>(size_);
        for (int i = 0; i < size_; i++) {
            data_[i] = arr.data_[i];
        }
    }

    MyArray& operator=(const MyArray& arr) {
        if (&arr != this) {
            auto new_data = std::make_unique<T[]>(arr.size_);
            for (int i = 0; i < arr.size_; i++) {
                new_data[i] = arr.data_[i];
            }
            data_ = std::move(new_data);
            size_ = arr.size_;
        }
        return *this;
    }


    T& operator[](std::ptrdiff_t index) {
        if (index >= size_) {
            throw std::out_of_range("index out of range");
        }
        return data_[index];
    }

    T operator[](std::ptrdiff_t index) const {
        if (index >= size_) {
            throw std::out_of_range("index out of range");
        }
        return data_[index];
    }

    int Size() const {
        return size_;
    }

    void fill(const T& val) {
        for (int i = 0; i < size_; i++) {
            data_[i] = val;
        }
    }

    T& Front() const {
        return data_[0];
    }

    T& Back() const {
        return data_[size_ - 1];
    }

private:
    std::unique_ptr<T[]> data_;
    const std::ptrdiff_t size_;
};

#endif