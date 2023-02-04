#include <iostream>

int nod(int a, int b) {
    int n = 1;
    while (n > 0) {
        n = a % b;
        a = b;
        b = n; 
    }
    return a;
}

int main() {
    int a = 0, b = 1;
    std::cin >> a >> b;
    std::cout << (a*b/nod(a, b)) << std::endl;
    return 0;
}
