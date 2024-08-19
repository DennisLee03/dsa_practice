#include<iostream>
using namespace std;

int fibo1(int n);
int fibo2(int n);

int main() {
    int n;
    cin >> n;
    cout << "by recursive: " << fibo1(n) << endl;
    cout << "by iterative: " << fibo2(n) << endl;
    return 0;
}

int fibo1(int n) {
    if(n <= 1) {
        return n;
    } else {
        return fibo1(n - 1) + fibo1(n - 2);
    }
}


int fibo2(int n) {
    if(n <= 1) {
        return n;
    } else {
        // a, b, c
        int a = 0;
        int b = 1;
        int c;

        for(int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }

        return c;
    }
}