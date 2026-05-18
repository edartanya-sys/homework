#include <iostream>
#include <stack>
#include <string>

int main() {
    std::stack<std::string> inputStack;
    std::string word;

#include <sstream>

    std::string line;
    std::getline(std::cin, line);  // читаем одну строку целиком
    std::istringstream iss(line);
    while (iss >> word) {
        inputStack.(word);
    }


    std::string lastWord = inputStack.top();
    int count = 1;


    std::stack<std::string> tempStack;
    tempStack.push(inputStack.top());
    inputStack.pop();

      while (!inputStack.empty()) {
        std::string current = inputStack.top();
        inputStack.pop();

        if (current == lastWord) {
            count++;
        } else {
            tempStack.push(current);
        }
    }

    std::cout << count << "\n";

    std::stack<std::string> resultStack;
    while (!tempStack.empty()) {
        resultStack.push(tempStack.top());
        tempStack.pop();
    }

 resultStack.push(lastWord);
    std::cout << "Результат: ";
    while (!resultStack.empty()) {
        std::cout << resultStack.top() << " ";
        resultStack.pop();
    }
    std::cout << "\n";

}