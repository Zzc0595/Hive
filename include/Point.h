#define POINT_H
#pragma once
#include "Zmath.h"
namespace zm{  
        class Point{
        protected:
        double x;double y;

        public:
        //构造函数
        Point(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}        
        //读写坐标
        double getx() const {return x;}
        double gety() const {return y;}
        void setx(double sx){x = sx;}
        void sety(double sy){y = sy;}
        //显示坐标
        std::string display(){
            std::string s1 = "(" + Tostr(x) + "," + Tostr(y) + ")";
            return s1;
        }
        // 运算符重载
        bool operator==(const Point& other) const {
        return (eq(x,other.x)) && (eq(y,other.y));
    }  
        bool operator!=(const Point& other) const {
        return !(*this == other);
    }    
        Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }   
        Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }   
        Point& operator=(const Point& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }

        //move a point(rt,lf,up,dn,or any radian)
        double rt=0,lf=PI,up=0.5*PI,dn=1.5*PI;
        void move(double angle,double d){
            x += d*cos(angle);
            y += d*sin(angle);
        }

};
    
    //两点距离
    double Dist(Point &a ,Point &b){
        if (a==b){return 0.0;}
        else{
            double dx= abs(a.getx()-b.getx());
            double dy= abs(a.gety()-b.gety());
            return hypot(dx,dy);}//用到zmath定义的hypot勾股数
    }

}