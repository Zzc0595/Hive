#define LINE_H
#pragma once
#include <Point.h>


namespace zm{
class Line : public Point{
    protected:
        double A,B,C; //Ax+By+C=0
    public:
        //基本读写操作
        Line(double a = 1.0 , double b = 1.0 , double c = 0.0) : A(a), B(b) ,C(c) {}
        double getA()const {return A;}
        double getB()const {return B;}
        double getC()const {return C;}
        void setA(double val) {A=val;}
        void setB(double val) {B=val;}
        void setC(double val) {C=val;}

        //Generate a line by two points
        void TwoPoint(Point a, Point b){
            setA(a.gety()-b.gety());
            setB(b.getx()-a.getx());
            setC(a.getx()*b.gety() - b.getx()*a.gety());}
        
        //斜率
        double k() const {if (B==0) return INFINITY; else return -A/B;}

        //Pass a point?
        bool Pass (Point p) const{
            if (eq(A*p.getx() + B*p.gety() +C,0)) return true;
            else return false;
        }

        //The distance from a point to the line
        double Dist(Point p){
            return abs(p.getx()*A +p.gety()*B +C)
            /hypot(A,B);
        }

        
};
//parallel
bool paral(Line a,Line b){if (eq(a.k(),b.k() ))return true;else return false;}

}