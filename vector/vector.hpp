#ifndef MYVECTOR
#define MYVECTOR

#include <memory>
#include <cstddef>
#include <stdexcept>

class MyVector {
public:
    MyVector();
    explicit MyVector(std::ptrdiff_t size);
    ~MyVector() = default;

    MyVector(const MyVector&); // копирование
    MyVector(MyVector&&) noexcept; // перемещение

    MyVector& operator=(const MyVector&); // копирование
    MyVector& operator=(MyVector&&) noexcept; // перемещение

    int& operator[](std::ptrdiff_t index); // доступ для модификации
    const int& operator[](std::ptrdiff_t index) const; // доступ для чтения <---- ИСПРАВЛЕНО

    std::ptrdiff_t size() const {
        return size_;
    }

private:
    std::unique_ptr<int[]> data_;
    std::ptrdiff_t size_ = 0;
};

#endif

