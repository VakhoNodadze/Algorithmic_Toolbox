#include <iostream>
#include <vector>

using namespace std;

double get_real_value(int value, int weight){
    return (double) value / weight;
}
double get_neccessary_num(int weight, int capacity){
    return (double) weight / capacity;
}
double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    double max_value = 0;
    int max_value_item_index = 0;
    while(weights.size() != 0 && capacity > 0){
        max_value = 0;
        for(int i = 0; i < weights.size(); i++){
            if(max_value < get_real_value(values[i], weights[i])){
                max_value = get_real_value(values[i], weights[i]);
                max_value_item_index = i;
            }
        }
        if(capacity >= weights[max_value_item_index]){
            capacity -= weights[max_value_item_index];
            value += values[max_value_item_index];
        }else{
            value += (double) (values[max_value_item_index] / get_neccessary_num(weights[max_value_item_index], capacity));
            capacity = 0;
        }
        weights.erase(weights.begin() + max_value_item_index);
        values.erase(values.begin() + max_value_item_index);
    }

    return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}