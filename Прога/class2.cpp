#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class Date {
public:
    int d, m, y;

    Date(const std::string& s = "00.00.00") {
        char dot;
        std::istringstream(s) >> d >> dot >> m >> dot >> y;
    }

    bool operator<(const Date& other) const {
        if (y != other.y) return y < other.y;
        if (m != other.m) return m < other.m;
        return d < other.d;
    }
};

class Goods{
protected:
    std::string name;
    double price;
    Date date;
    Date term;

public:
    virtual void Print() = 0;
    virtual void Term(const Date &term2) = 0;
};

class Product : public Goods{
public:
    Product(){
        term = Date();
        name = "";
        price = 0;
        date = Date();
    }
    Product(const std::string &n, double p, const std::string &d, const std::string &t ){
        name = n;
        price = p;
        date = Date(d);
        term = Date(t);
    }
    void Print(){
        std::cout << "Product:"
                  <<  name
                  << " Price: " <<  price
                  << " | Date: " << date.d << "." << date.m << "." << date.y
                  << " | Term: " << term.d << "." << term.m << "." << term.y << std::endl;
    }

    void Term(const Date &term2){
        if(term < term2 && !(term.d == 0 && term.m == 0 && term.y == 0)) {
            std::cout << "prosrochen:" << name << "\n";
        }
    }
    Date GetTerm(){
        return term;
    }
    std::string GetName(){
        return name;
    }
};

class Party : public Goods{
private:
    int count;
public:
    Party(){
        name = "";
        price = 0;
        count = 0;
        date = Date();
        term = Date();
    }
    Party(const std::string &n, double p, int c, const std::string &d, const std::string &t){
        name = n;
        price = p;
        count = c;
        date = Date(d);
        term = Date(t);
    }
    void Term(const Date &term2){
        if(term < term2 && !(term.d == 0 && term.m == 0 && term.y == 0)) {
            std::cout << "prosrochen:" << name << "\n";
        }
    }

    void Print(){std::cout  << "Party:"
                            <<  name
                            << " Price: " <<  price
                            << " Count: " << count
                            << " | Date: " << date.d << "." << date.m << "." << date.y
                            << " | Term: " << term.d << "." << term.m << "." << term.y << std::endl;
    }
};

class Kit : public Goods{
private:
    std::vector <Product> list;
public:
    Kit(){
        name = "";
        price = 0;
    }
    Kit(const std::string &n, double p,  std::vector <Product> &l){
        name = n;
        price = p;
        list = l;
    }

    void Print(){
        std::cout << "Kit:"
                  << name
                  << " Total Price: " << price << std::endl;

        for (size_t i = 0; i < list.size(); i++) {
            std::cout << "   + ";
            list[i].Print();
        }
    }
    void Term(const Date &dats){
        for(int i = 0; i < list.size(); i++) {
            Date t = list[i].GetTerm();
            if(t < dats && !(t.d == 0 && t.m == 0 && t.y == 0)){
                std::cout << "prosrochen:" << list[i].GetName()<< "\n";
            }
        }
    }
};

int main(){
    std::ifstream in("a");
    if (!in.is_open()) {
        std::cerr << "File not found!" << std::endl;
        return 1;
    }
    int n;
    in >> n;

    std::vector <Goods*> baz(n);
    int cl;
    std::string name, name1, dat, term_str;
    double price, prise; int count, nn;
    std::vector <Product> l;

    for(int i = 0;i < n; i++){
        in >> cl;
        if(cl == 1) {
            in >> name >> price >> dat >> term_str;
            baz[i] = new Product(name, price, dat, term_str);
        }
        if(cl == 2) {
            in >> name >> price >> count >> dat >> term_str;
            baz[i] = new Party(name, price, count, dat, term_str);
        }
        if(cl == 3) {
            in >> name1 >> prise >> nn;
            for(int j = 0; j < nn; j++){
                in >> name >> price >> dat >> term_str;
                Product a(name, price, dat, term_str);
                l.push_back(a);
            }
            baz[i] = new Kit(name1, prise, l);
            l.clear();
        }
    }
    in.close();

    for(int i = 0; i < n; i++){
        baz[i]->Print();
    }

    std::string dats_str;
    std::cin >> dats_str;
    Date dats(dats_str);

    for(int i = 0; i < n; i++) {
        baz[i]->Term(dats);
    }

}