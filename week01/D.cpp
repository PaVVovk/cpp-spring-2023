#include <iostream>

int main() {
    int a = 0, b = 0, n = 1;
    std::cin >> a >> b;
    while (n > 0) {
        n = a % b;
        a = b;
        b = n; 
    }
    std::cout << a << std::endl;
    return 0;
}

