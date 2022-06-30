#pragma once

#include <stack>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void print_vector(vector<T> s){
    for (auto &val: s){
        std::cout << val << " | " ;
    }
}
