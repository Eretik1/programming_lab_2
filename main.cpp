#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

bool compare(const std::string& left, const std::string& right) { 
    int l1 = stoi(left.substr(0, left.find(".")));
    int l2 = stoi(left.substr(left.find(".") + 1, left.find(".", left.find(".") + 1)));
    int l3 = stoi(left.substr(left.find(".", left.find(".") + 1) + 1, left.find(".", left.find(".", left.find(".") + 1) + 1)));
    int l4 = stoi(left.substr(left.find(".", left.find(".", left.find(".") + 1) + 1) + 1, left.find(".", left.find(".", left.find(".", left.find(".") + 1) + 1))));
    int r1 = stoi(right.substr(0, right.find(".")));
    int r2 = stoi(right.substr(right.find(".") + 1, right.find(".", right.find(".") + 1)));
    int r3 = stoi(right.substr(right.find(".", right.find(".") + 1) + 1, right.find(".", right.find(".", right.find(".") + 1) + 1)));
    int r4 = stoi(right.substr(right.find(".", right.find(".", right.find(".") + 1) + 1) + 1, right.find(".", right.find(".", right.find(".", right.find(".") + 1) + 1))));
    if(l1 > r1){
        return 1;
    }
    else if((l1 == r1)){
        if(l2 > r2){
            return 1;
        }
        else if(l2 == r2){
            if(l3 > r3){
                return 1;
            }
            else if((l3 == r3) && (l4 > r4)){
                return 1;
            }
        }
    }
    return 0;
}

std::vector<std::string> readfile(){
    std::string line;
    std::vector<std::string> ip;
    std::ifstream file("ip_filter.tsv"); 
    while (std::getline(file, line)) {
        ip.push_back(line.substr(0, line.find("	")));
    }
    std::sort(begin(ip), end(ip), compare);
    /*/
    for(int i = 0; i < ip.size(); i++) {
        std::cout << ip[i] << std::endl;
    }
    //*/
    file.close();
    return ip;
}


int main(int, char**){
     
    auto print1 {[](std::string p){if(p.substr(0, p.find(".")) == "1")std::cout << p << std::endl;}};
    auto print2 {[](std::string p){if((p.substr(0, p.find(".")) == "46") && (p.substr(p.find(".") + 1, 2) == "70"))std::cout << p << std::endl;}};
    auto print3 {[](std::string p){if(p.substr(0, p.find(".")) == "46" 
        || stoi(p.substr(p.find(".") + 1, p.find(".", p.find(".") + 1))) == 46
        || stoi(p.substr(p.find(".", p.find(".") + 1) + 1, p.find(".", p.find(".", p.find(".") + 1) + 1))) == 46
        || stoi(p.substr(p.find(".", p.find(".", p.find(".") + 1) + 1) + 1, p.find(".", p.find(".", p.find(".", p.find(".") + 1) + 1)))) == 46
        )std::cout << p << std::endl;}};
    std::vector<std::string> ip = readfile();
    for(int i = 0; i < int(ip.size()); i++){
        print1(ip[i]);
    }
    for(int i = 0; i < int(ip.size()); i++){
        print2(ip[i]);
    }
    for(int i = 0; i < int(ip.size()); i++){
        print3(ip[i]);
    }
    return 0;
    
}
