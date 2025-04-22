#include <vector.hpp>


Myvector::Myvector(std::ptrdiff_t size) : size_(size) {
    data_ = std::make_unique<int[]>(size_);
}


Myvector::Myvector(const Myvector& other) : size_(other.size_) {
    data_ = std::make_unique<int[]>(size_);
    for (int i = 0;i < size_;i++) {
        data_[i] = other.data_[i];
    }
}


Myvector& Myvector::operator=(const Myvector& other) {
    if (&other != this) {
        size_ = other.size_;
        data_ = std::make_unique<int[]>(size_);
        for (int i = 0;i < size_;i++) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

Myvector& Myvector::operator= (Myvector&& other) {
    if (&other != this) {
        data_ = std::move(other.data_);
        size_ = other.size_;
        other.size_ = 0;
    }
    return *this;
}

Myvector::Myvector(Myvector&& other) :data_(std::move(other.data_)), size_(other.size_) {
    other.size_ = 0;
}

int& Myvector::operator[](std::ptrdiff_t index) {
    if (index >= size_ || index < 0) {
        throw std::invalid_argument("что-то не так с индексом");

    }
    return *(data_.get() + index);
}

int Myvector::operator[](const std::ptrdiff_t index) const {
    if (index >= size_ || index < 0) {
        throw std::invalid_argument("что-то не так с индексом");

    }
    return data_[index];
}