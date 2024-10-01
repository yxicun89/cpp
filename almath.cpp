#include <iostream>
#include <cmath>
using namespace std;

long long factorial(int n){
    if (n <= 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    int n;
    cin >> n;
    long long result = 0;
    result = factorial(n);
    cout << result << endl;
    return 0;
}