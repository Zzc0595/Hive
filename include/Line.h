#define LINE_H
#pragma once
#include <Point.h>


namespace zm{
class Line{
    private:
        double A,B,C; //Ax+By+C=0
    public:
        //基本读写操作
        Line(double a = 1.0 , double b = 1.0 , double c = 0.0) : A(a), B(b) ,C(c) {}
        double get_A()const {return A;}
        double get_B()const {return B;}
        double get_C()const {return C;}
        void set_A(double val) {A=val;}
        void set_B(double val) {B=val;}
        void set_C(double val) {C=val;}

        //Generate a line by two points
        void TwoPoint(Point a, Point b){
            set_A(a.get_y()-b.get_y());
            set_B(b.get_x()-a.get_x());
            set_C(a.get_x()*b.get_y() - b.get_x()*a.get_y());}
        
        //斜率
        double k(){return -A/B;}

        //Pass a point?
        bool Pass (Point p){
            if (A*p.get_x() + B*p.get_y() +C ==0) return true;
            else return false;
        }

        //The distance from a point to the line
        double Dist(point p)

        
};
//parallel
bool paral(Line a,Line b){if (a.k() == b.k() )return true;else return false;}

}