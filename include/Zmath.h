#define ZMATH_H
#pragma once
#include <string>
#include <sstream>
namespace zm{
//double to std::string
std::string Tostr(double d){
    std::stringstream ss;
    ss << d;
    std::string str1 = ss.str();
    return str1;
}
//绝对值函数
double abs(double m){
    if (m>=0)return m;
    else return -m;
}

//平方根
double sqrt(double x) {
    if (x < 0) return -1;  // 处理负数
    if (x == 0) return 0;
    
    double guess = x;
    for (int i = 0; i < 20; i++) {  // 迭代20次，精度足够
        guess = (guess + x / guess) / 2;
    }
    return guess;
}

//勾股数
double hypot(double a,double b){
    return zm::sqrt(a*a + b*b);
}
}