#include <string>
#include <set>
#include <list>
#include <vector>
#include <iostream>
#include <sstream>


template <typename T>
void Myswap(T& first, T& sec) {
    T third = std::move(first);
    first = std::move(sec);
    sec = std::move(third;
}


template <typename T>
std::string cotnainer_to_string(T& box) {
    std::ostringstream ostring;
    starting = 1;
    for (auto thing : box) {
        if (starting != 1) {
            ostring << ', ';
        }
        starting = 0;
        ostring << thing;
    }
    return ostring.str();
}



int main() {
    std::cout << "let's start with swapping \n";
    int a = 0;
    int b = 1000;
    std::cout << "before a=" << a << " b=" << b << "\n";
    Myswap(a, b);
    std::cout << "after a=" << a << " b=" << b << "\n";

    float c = 23.2345432;
    float d = 23454.111111111;
    std::cout << "before c=" << c << " d=" << d << "\n";
    Myswap(c, d);
    std::cout << "after c=" << c << " d=" << d << "\n";

    std::string e = "first";
    std::string f = "second";
    std::cout << "before e=" << e << " f=" << f << "\n";
    Myswap(e, f);
    std::cout << "after e=" << e << " f=" << f << "\n";


    std::cout << "turning a container to string\n";
    std::vector<int> smth1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::cout << "the first vector " << container_to_string(smth1) << "\n";

    std::vector <double> smth2 = { 1.23453, 2.234, 3.2345, 4.23456 };
    std::cout << "the second vector " << container_to_string(smth2) << "\n";

    std::vector <std::string> smth3 = { "take", "this", "cup", "away", "from", "me", "for", "i", "don't", "want", "to", "taste", "its", "poison" };
    std::cout << "the third vector " << container_to_string(smth3) << "\n";
}