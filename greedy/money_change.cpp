#include <iostream>

int get_change(int m) {
    int arr[3] = {10, 5, 1};
    int n = 0;
    while(m >= arr[0]){
        n++;
        m -= arr[0];
    }
    while(m >= arr[1]){
        n++;
        m -= arr[1];
    }
    while(m >= arr[2]){
        n++;
        m -= arr[2];
    }
    return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}