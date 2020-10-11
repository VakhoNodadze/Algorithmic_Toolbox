#include <algorithm>
#include <iostream>
#include <vector>
#include <map>  
#include <string>

using namespace std;

int get_majority_element(vector<long long> &a) {
  map<long long, long long> m; 
  long long size = a.size();
    for(long long i = 0; i < size; i++) {
        m[a[i]]++; 
    }
    for(pair<int, int>  i : m) { 
        if(i.second > size / 2) { 
            return 1;
            break; 
        } 
    } 
    return 0;
}

int main() {
  long long n;  
  cin >> n;
  vector<long long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  cout << get_majority_element(a) << '\n';
}