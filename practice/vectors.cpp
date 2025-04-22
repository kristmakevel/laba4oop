#include <chrono>
#include <iostream>
#include <vector.hpp>

int main() {
    const std::ptrdiff_t size = 1000000;
    MyVector original(size);
    for (int i = 0; i < size; i++) {
        original[i] = static_cast<int>(i);
    }
    MyVector copy_target(size);
    MyVector move_target(size);
    // тест копирования
    const auto copy_start = std::chrono::high_resolution_clock::now();
    copy_target = original;
    const auto copy_end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> copy_time = copy_end - copy_start;
    std::cout << "time of making a copy: " << copy_time.count() << " seconds\n";
    // тест перемещения
    const auto move_start = std::chrono::high_resolution_clock::now();
    move_target = std::move(original);
    const auto move_end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> move_time = move_end - move_start;
    std::cout << "time of moving: " << move_time.count() << " seconds\n";
    return 0;
}