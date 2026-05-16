#include <fstream>
#include <queue>

int main() {
    std::queue<int> a;
    std::queue<int> a2;
    std::ifstream in("in");
    std::ofstream out("out");
    int buf;

    while (in >> buf) {
        a.push(buf);
    }

    if (a.empty()) return 0;

    buf = a.front();
    a.pop();
    a2.push(buf);

    while (!a.empty()) {
        int current = a.front();
        a.pop();
        if (current != buf) {
            a2.push(current);
            buf = current;
        }
    }

    while (!a2.empty()) {
        out << a2.front() << " ";
        a2.pop();
    }


}