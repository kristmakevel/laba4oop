#include <iostream>
#include <array.hpp>
#include <string>

int main() {
    MyArray <int, 10> int_array;
    int_array.fill(1);
    std::cout << "array with int in it\n";
    for (int i = 0; i < int_array.Size();i++) {
        std::cout << int_array[i] << " ";
    }


    MyArray <std::string, 10> string_attay;
    string_array.fill(":(");
    std::cout << "\narray with string in it\n:";
    for (int i = 0;i < arr_str.Size();i++) {
        std::cout << string_attay[i] << " ";
    }

    MyArray <double, 20> double_array;
    std::cout << "\narray with double in it\n";
    for (int i = 0;i < double_array.Size();i++) {
        double_array[i] = (i + 1) * 24.2;
    }
    for (int i = 0;i < double_array.Size();i++) {
        std::cout << double_array[i] << " ";
    }
    std::cout << "\nfront: " << double_array.Front() << "\nback: " << double_array.Back() << "\n";
}