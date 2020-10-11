#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// int optimal_sequence(int n) {
//   std::vector<int> sequence;
//   vector<int> dp_table(n + 1, n);
//   dp_table[0] = 0;
//   dp_table[1] = 1;
//   dp_table[2] = 1;
//   dp_table[3] = 1;
//   for(int i = 4; i < dp_table.size(); i++){
//     if(i % 3 == 0){
//       dp_table[i] = min(dp_table[i/3] + 1, dp_table[i]);
//     }
//     else if(i % 2 == 0){
//       dp_table[i] = min(dp_table[i/2] + 1, dp_table[i-1] + 1);
//     }else{
//       dp_table[i] = dp_table[i-1] + 1;
//     }
//   }
//   reverse(sequence.begin(), sequence.end());
//   // for(int i = 0; i < dp_table.size(); i++){
//   //   cout << dp_table[i] << endl;
//   // }
//   return dp_table[n];
// }
vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  vector<int> arr(n + 1, n);
    for (int i = 1; i < arr.size(); i++) {
        arr[i] = arr[i - 1] + 1;
        if (i % 2 == 0) arr[i] = min(1 + arr[i / 2], arr[i - 1] + 1);
        if (i % 3 == 0) arr[i] = min(1 + arr[i / 3], arr[i]);
    }

    for (int i = n; i > 1; ) {
        sequence.push_back(i);
        if (arr[i - 1] == arr[i] - 1)
            i = i - 1;
        else if (i % 2 == 0 && (arr[i / 2] == arr[i] - 1))
            i = i / 2;
        else if (i % 3 == 0 && (arr[i / 3] == arr[i] - 1))
            i = i / 3;
    }
    sequence.push_back(1);
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}