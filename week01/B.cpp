#include <iostream>
#include <cmath>

int main() {
    int a = 0, b = 0, c = 0, d = 0;
    std::cin >> a >> b >> c;
    d = b*b - 4*a*c;
    if ((d < 0) || ((a*a + b*b) == 0)) {
        std::cout << "\n" << std::endl;
    } else if (a == 0) {
        std::cout << (-c/b) << std::endl;
    } else if (d == 0) {
        std::cout << (-b/(2*a)) << std::endl;
    } else {
        std::cout << ((-b-sqrt(d))/(2*a)) << ' '
                  << ((-b+sqrt(d))/(2*a)) << std::endl;
    }
    return 0;
}

