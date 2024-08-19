#include<iostream>
using namespace std;

int fact1(int n);
int fact2(int n);

int main() {
    int n;
    cin >> n;
    cout << "by recursive: " << fact1(n) << endl;
    cout << "by iterative: " << fact2(n) << endl;
    return 0;
}

int fact1(int n) {
    if(n == 0){
        return 1;
    } else {
        return n * fact1(n - 1);
    }
}

int fact2(int n) {
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        ans *= i;
    }
    return ans;
}