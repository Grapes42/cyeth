#include <iostream>

void order_first(int &a, int &b) {
    if (a > b) {
        int a_old = a;
        int b_old = b;

        a = b_old;
        b = a_old;
    }
}

int main() {
    int a = 1;
    int b = 2;

    order_first(a, b);

    std::cout << "a: " << a << std::endl
              << "b: " << b << std::endl;

    a = 2;
    b = 1;

    order_first(a, b);

    std::cout << "a: " << a << std::endl
              << "b: " << b << std::endl;
}