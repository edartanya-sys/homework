#include <iostream>
#include <vector>
#include <fstream>

void Sort(std::vector<std::vector<int>>& matrix, int col, int rows, bool a) {
    for (int i = 1; i < rows; i++) {
        int j = i;
        while (j > 0) {
            bool c = false;
            if (a) {
                if (matrix[j][col] < matrix[j - 1][col]) c = true;
            } else {
                if (matrix[j][col] > matrix[j - 1][col]) c = true;
            }


            if (c) {
                int temp = matrix[j][col];
                matrix[j][col] = matrix[j - 1][col];
                matrix[j - 1][col] = temp;
                j--;
            } else {
                break;
            }
        }
    }
}

int main() {
    std::ifstream in("input");
    std::ofstream out("output");

    int n, m;
    in >> n >> m;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            in >> matrix[i][j];
        }
    }

    for (int j = 0; j < m; j++) {
        if (j % 2 == 0) {
            Sort(matrix, j, n, true);
        } else {
            Sort(matrix, j, n, false);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            out << matrix[i][j] << " ";
        }
        out << "\n";
    }

    in.close();
    out.close();
}