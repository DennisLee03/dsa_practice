#include<iostream>

int rsum(int n);

int main(void) {
    int n = 0;
    std::cin >> n;
    std::cout << rsum(n) << std::endl;
    return 0;
}

int rsum(int n) {

    if(n > 1) {
        std::cout << "stack " << n - 1 << std::endl;
        return (rsum(n - 1) + n - 1);
    }

    std::cout << "stack 0" << std::endl; 
    return 0;
}