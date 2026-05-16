#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    std::transform(v.begin(), v.end(), v.begin(), [](int n) {
        return (n < 0) ? n * 2 : n;
    });
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
}