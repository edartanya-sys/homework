#include <fstream>
#include <string>
#include <iostream>

int main(){

    std::ifstream in("in");
    std::ofstream out("out");

    std::string buf;
    char c;
    int count = 0; std::cin >> c;

    while(std::getline(in, buf)){
        if(buf.size() > 0 && buf[0] == c){
            count++;
        }
    }
    in.close();
    out << count;
    out.close();
}