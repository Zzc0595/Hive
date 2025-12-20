#include </home/zc/Hive/include/Point.h>
#include <iostream>
int main (){
    zm::Point A(2.0,3.0);
    zm::Point B(3.0,4.0);
    std::cout << zm::Dist(A,B) << std::endl;
    return 0;
}