#include <iostream>
#include <vector>
using namespace std;


int fibonacci(int n, int idx, int fib) {
    if(idx == n) return fib;
    else fibonnaci(n, idx+1, fib)
}

int main() {
    int n, m;
    while(cin >> n >> m) {
        int fib = fibonacci(n,0, 0);
    }
}