#include <iostream>

using namespace std;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m){
    int f[n+1];
    f[0] = 0;
    f[1] = 1;

    for (long long i = 2;i<=n;i++ ){
        f[i] = (f[i-1]+f[i-2])%m;
    }

    return f[n];
}

void test_solution() {
    for (int n = 0; n < 5; ++n){
        long long a = rand() % 10000000;
        long long b = rand() % 10000000;
        if(get_fibonacci_huge_fast(a,  b) == get_fibonacci_huge_naive(a, b)){
            cout << "OKAY" << endl;
        }else{
            cout << "ERROR for numbers: " << a << " and " << b << 
            " ANSWER: " << get_fibonacci_huge_fast(a,  b) << " " << get_fibonacci_huge_naive(a, b) <<  endl;
        }
    }
        
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    test_solution();
    // std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    // std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}