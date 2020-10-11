#include <iostream>

using namespace std;

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long gcd_fast(int a, int b) {
    if(b == 0 ){
        return a;
    }
    return gcd_fast(b, a % b);
}

long long lcm_fast(long long a, long long b){
    long long multiple = a * b;
    long long devider = gcd_fast(a,b);
    long long answer = multiple / devider;
    return answer;
}

void test_solution() {
    // for (int n = 0; n < 5; ++n){
        // long long a = rand() % 100000;
        // long long b = rand() % 100000;
        if(lcm_fast(714552,  374513) == lcm_naive(714552, 374513)){
            cout << "OKAY" << endl;
        }else{
            cout << "ERROR for numbers: " << "714552" << " and " << "374513" << 
            " ANSWER: " << lcm_fast(714552,  374513) << " " << lcm_naive(714552, 374513) <<  endl;
        }
    // }
        
}
int main() {
  int a, b;
  std::cin >> a >> b;
//   test_solution();
//   std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}