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
    else if(l1 == r1){
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