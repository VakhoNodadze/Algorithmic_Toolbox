#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxx(int a, int b);

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  int temp[a.size() + 1][b.size() + 1];
  int max = 0;
  for(int i = 0; i <= a.size(); i++) {
      for(int j = 0; j <= b.size(); j++) {
          if(i == 0 || j == 0){
              temp[i][j] = 0;
          }else if(a[i - 1] == b[j - 1]){
              temp[i][j] = temp[i - 1][j - 1] + 1;
          }
          else{
                temp[i][j] = maxx(temp[i - 1][j], temp[i][j - 1]);
          }
          if(temp[i][j] > max){
              max = temp[i][j];
          }
      }
  }
  return max;
}

int maxx(int a, int b) { 
    return (a > b) ? a : b; 
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}