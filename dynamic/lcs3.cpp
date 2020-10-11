#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxx(int a, int b);

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  int aSize = a.size();
  int bSize = b.size();
  int cSize = c.size();
  int temp[aSize + 1][bSize + 1][cSize + 1];
  int max = 0;
  for(int i = 0; i <= a.size(); i++) {
      for(int j = 0; j <= b.size(); j++) {
          for(int k = 0; k <= c.size(); k++) {
            if(i == 0 || j == 0 || k == 0){
                temp[i][j][k] = 0;
            }else if(a[i - 1] == b[j - 1] && a[i - 1 ] == c[k - 1] && b[j - 1] == c[k - 1]){
                temp[i][j][k] = temp[i - 1][j - 1][k - 1] + 1;
            }
            else{
                    temp[i][j][k] = maxx(maxx(temp[i - 1][j][k], temp[i][j - 1][k]), temp[i][j][k - 1]);
            }
          }
      }
  }
  return temp[aSize][bSize][cSize];
}

int maxx(int a, int b) { 
    return (a > b) ? a : b; 
} 

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}