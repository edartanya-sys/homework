#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <cctype>

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    std::string line;
    int lineNum = 1;

    while (std::getline(fin, line)) {
        std::set<char> upper, lower;

        for (char c: line) {
            if (std::isalpha(c)) {
                if (std::isupper(c)) {
                    upper.insert(c);
                } else {
                    lower.insert(c);
                }
            }
        }

        std::set<char> result;
        for (char c: upper) {
            char low = std::tolower(c);
            if (lower.count(low) == 0) {
                result.insert(c);
            }
        }

        fout << "Line " << lineNum << ": ";
        for (char c: result) {
            fout << c << " ";
        }
        fout << "\n";

        lineNum++;
    }

    fin.close();
    fout.close();
}