#include <iostream>

int main() {
    int n = 0, f = 1;
    std::cin >> n;
    while (n > 1) {
        f *= n;
        n--;
    }
    std::cout << f << std::endl;
    return 0;
}

