#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int get_change(int m) {
    vector<int> arr(m+1, m);
    vector<int> coins{1,3,4};
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i < arr.size(); i++){
        for(int j = 0; j < coins.size(); j++){
            if(coins[j] <= i){
                arr[i] = min(arr[i], 1 + arr[i - coins[j]]);
            }
            else{
                break;
            }
        }
    }
    return arr[m] > m ? -1 : arr[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}