#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using std::endl;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int start = 0;
    int counter = 0;
    while(start + tank < dist){
        for(int i = stops.size() - 1; stops[i] >= start; i--){
            if(stops[i] == start){
                return -1;
            }
            if(stops[i] <= start + tank){
                start = stops[i];
                counter++;
                break;
            }
        }
    }
    return counter;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}