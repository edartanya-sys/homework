#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    s = std::accumulate(v.begin(), v.end(), 0);
    if (abs(s) >= 10 && abs(s) <= 99) cout << "Yes";
    else cout << "No";
}