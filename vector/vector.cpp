#include  <vector.hpp>
#include <stdexcept>


MyVector::MyVector(std::ptrdiff_t size) : size_(size) {
    data_ = std::make_unique<int[]>(size_);
}


MyVector::MyVector(const MyVector& other)
    : size_(other.size_),
    data_(std::make_unique<int[]>(size_))
{
    for (std::ptrdiff_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

MyVector& MyVector::operator=(const MyVector& other) {
    if (this != &other) {
        size_ = other.size_;
        data_ = std::make_unique<int[]>(size_);

        for (std::ptrdiff_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

MyVector& MyVector::operator=(MyVector&& other) noexcept {
    if (this != &other) {
        data_ = std::move(other.data_);
        size_ = other.size_;
        other.size_ = 0;
    }
    return *this;
}

MyVector::MyVector(MyVector&& other) noexcept
    : data_(std::move(other.data_)),
    size_(other.size_)
{
    other.size_ = 0;
}

int& MyVector::operator[](std::ptrdiff_t index) {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("index out of range");
    }
    return data_[index];
}

const int& MyVector::operator[](std::ptrdiff_t index) const {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("index out of range");
    }
    return data_[index];
}
