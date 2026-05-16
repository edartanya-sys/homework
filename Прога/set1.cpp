#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <cmath>

std::set<int> getDigits(int num) {
    std::set<int> digits;
    num = abs(num);
    if (num == 0) {
        digits.insert(0);
        return digits;
    }
    while (num > 0) {
        digits.insert(num % 10);
        num /= 10;
    }
    return digits;
}

int main() {
    std::ifstream fin("input");
    std::ofstream fout("output");

    std::vector<int> numbers;
    int num;
    while (fin >> num) {
        numbers.push_back(num);
    }

    for (int i = 0; i + 2 < numbers.size(); ++i) {
        std::set<int> d1 = getDigits(numbers[i]);
        std::set<int> d2 = getDigits(numbers[i + 1]);
        std::set<int> d3 = getDigits(numbers[i + 2]);

        std::set<int> result;

        for (int digit = 0; digit <= 9; ++digit) {
            bool in1 = d1.count(digit);
            bool in2 = d2.count(digit);
            bool in3 = d3.count(digit);

            if ((in1 && in2 && in3) || (!in1 && !in2 && !in3)) {
                result.insert(digit);
            }
        }

        fout << numbers[i] << " " << numbers[i+1] << " " << numbers[i+2] << ": ";
        for (int d : result) {
            fout << d << " ";
        }
        fout << "\n";
    }

    fin.close();
    fout.close();
}