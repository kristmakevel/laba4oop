#include <vector.hpp>

Myvector::Myvector(std::ptrdiff_t size)
    : size_(size),
    data_(std::make_unique<int[]>(size_))
{
}

Myvector::Myvector(const Myvector& other)
    : size_(other.size_),
    data_(std::make_unique<int[]>(size_))
{
    for (std::ptrdiff_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

Myvector& Myvector::operator=(const Myvector& other) {
    if (this != &other) {
        size_ = other.size_;
        data_ = std::make_unique<int[]>(size_);

        for (std::ptrdiff_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

Myvector& Myvector::operator=(Myvector&& other) {
    if (this != &other) {
        data_ = std::move(other.data_);
        size_ = other.size_;
        other.size_ = 0;
    }
    return *this;
}

Myvector::Myvector(Myvector&& other)
    : data_(std::move(other.data_)),
    size_(other.size_)
{
    other.size_ = 0;
}

int& Myvector::operator[](std::ptrdiff_t index) {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("something is wrong with an index");
    }
    return data_[index];
}

const int& Myvector::operator[](std::ptrdiff_t index) const {
    if (index < 0 || index >= size_) {
        throw std::out_of_range("something is wrong with an index");
    }
    return data_[index];
}