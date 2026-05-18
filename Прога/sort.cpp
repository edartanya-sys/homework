#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

struct student{
    std::string f;
    std::string n;
    std::string o;
    int y;
    std::vector<int> v;
};
int partition(std::vector<student>& arr, int low, int high) {

    int pivot = std::accumulate(arr[high].v.begin(), arr[high].v.end(), 0)
                / arr[high].v.size();
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        if (std::accumulate(arr[j].v.begin(), arr[j].v.end(), 0)
            / arr[high].v.size() <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}


void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::ifstream in("in");
    std::ofstream out("out");
    int buf;
    in >> buf;
    out << buf;
    student s;
    std::vector<student> data;
    while(in >> s.f >> s.n >> s.o >> s.y >> s.v[0]
    >> s.v[1] >> s.v[2] >> s.v[3] >> s.v[4]){
        data.push_back(s);
    }
    int n = data.size();
    quickSort(data, 0, n - 1);
    for (int i : data) {
         << i << " ";
    }

}
