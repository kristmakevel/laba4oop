#include <iostream>
#include <memory>
#include <vector>


#ifndef MYVECTOR
#define MYVECTOR

class Myvector {
public:
	Myvector();
	~Myvector() = default;
	Myvector::Myvector(std::ptrdiff_t size);
	Myvector& operator=(const Myvector&); //копирование
	Myvector& operator= (Myvector&&); //перемещение
	Myvector(const Myvector&); //копирование
	Myvector(Myvector&&); //перемещение
	int& operator[](std::ptrdiff_t index); //обращение по индексу чтобы изменить
	int operator[](const std::ptrdiff_t index) const; //обращение по индексу чтение
	int size() const {
		return size_;
	}
private:
	std::unique_ptr<int[]> data_;
	std::ptrdiff_t size_ = 0;
};

#endif