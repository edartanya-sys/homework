#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>

class Ing {
public:
    std::string name;
    double measure;
    double price;

    Ing(const std::string &n, double m, double p) {
        name = n;
        measure = m;
        price = p;
    }
    Ing() = default;
};

class Recipe {
private:
    std::vector<Ing> ingredient;
    std::string metod;
    double time;

public:
    static int count;

    Recipe(std::vector<Ing> &ing, const std::string &m, double t) {
        ingredient = ing;
        metod = m;
        time = t;
        count++;
    }

    Recipe() {
        metod = "";
        time = 0;
        count++;
    }

    std::vector<Ing> GetIngredient() const {
        return ingredient;
    }

    std::string GetMetod() const {
        return metod;
    }

    double GetTime() const {
        return time;
    }

    void SetIngredient(std::vector<Ing> &ing) {
        ingredient = ing;
    }

    void SetMetod(const std::string &m) {
        metod = m;
    }

    void SetTime(double t) {
        time = t;
    }

    double Price() const {
        double res = 0;
        for(int i = 0; i < ingredient.size(); i++) {
            res += ingredient[i].price;
        }
        return res;
    }

    bool operator>(const Recipe &a) const {
        if (this->time != a.time) {
            return this->time > a.time;
        }
        return this->Price() > a.Price();
    }

    bool operator<(const Recipe &a) const {
        if (this->time != a.time) {
            return this->time < a.time;
        }
        return this->Price() < a.Price();
    }

    bool operator==(const Recipe &a) const {
        return (this->time == a.time) && (this->Price() == a.Price());
    }
};

int Recipe::count = 0;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);


    std::ifstream inFile("input");
    if (!inFile.is_open()) {
        std::cout << "Ошибка!\n";
        return 1;
    }



    int count1;
    inFile >> count1;

    std::vector<Ing> ing1;
    for(int i = 0; i < count1; i++) {
        std::string name;
        double measure, price;

        inFile >> name >> measure >> price;
        ing1.push_back(Ing(name, measure, price));
    }

    std::string metod1;
    double time1;
    inFile.ignore();
    std::getline(inFile, metod1);
    inFile >> time1;

    Recipe recipe1(ing1, metod1, time1);



    int count2;
    inFile >> count2;

    std::vector<Ing> ing2;
    for(int i = 0; i < count2; i++) {
        std::string name;
        double measure, price;

        inFile >> name >> measure >> price;
        ing2.push_back(Ing(name, measure, price));
    }

    std::string metod2;
    double time2;
    inFile.ignore();
    std::getline(inFile, metod2);
    inFile >> time2;

    Recipe recipe2(ing2, metod2, time2);



    int count3;
    inFile >> count3;

    std::vector<Ing> ing3;
    for(int i = 0; i < count3; i++) {
        std::string name;
        double measure, price;

        inFile >> name >> measure >> price;
        ing3.push_back(Ing(name, measure, price));
    }

    std::string metod3;
    double time3;
    inFile.ignore();
    std::getline(inFile, metod3);
    inFile >> time3;

    Recipe recipe3(ing3, metod3, time3);

    inFile.close();
    std::cout << "\n";

    std::cout << "Информация о рецепте\n\n";

    std::cout << "Recipe 1:\n";
    std::cout << "  Ингредиенты:\n";
    auto ingredients1 = recipe1.GetIngredient();
    for(int i = 0; i < ingredients1.size(); i++) {
        std::cout << "    " << ingredients1[i].name << "\t"
                  << ingredients1[i].measure << "\t"
                  << ingredients1[i].price << "\n";
    }
    std::cout << "  Метод: " << recipe1.GetMetod() << "\n";
    std::cout << "  Время: " << recipe1.GetTime() << " мин\n";
    std::cout << "  Общая цена: " << recipe1.Price() << "\n";




    std::cout << "Сравнение рецептов\n";

    if (recipe1 > recipe2) {
        std::cout << "Recipe 1 занимает больше времени чем Recipe 2\n";
    } else if (recipe1 < recipe2) {
        std::cout << "Recipe 1  меньше Recipe 2\n";
    }

    if (recipe2 == recipe3) {
        std::cout << "Recipe 2 и Recipe 3 равны (время и цена совпадают)\n";
    } else {
        std::cout << "Recipe 2 и Recipe 3 НЕ равны\n";
    }

    if (recipe1 > recipe3) {
        std::cout << "Recipe 1 занимает больше времени чем Recipe 3\n";
    } else {
        std::cout << "Recipe 1 занимает меньше или равно Recipe 3\n";
    }

    std::cout << "\n";

    std::cout << "Всего рецептов: " << Recipe::count << "\n";


}