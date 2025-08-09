#ifndef _FIGURES_H
#define _FIGURES_H

// class Point2D {
// 	double x, y;
// public:
// 	void Set(double x0, double y0);
// 	void Move(double dx, double dy);
// 	void Scale(double sx, double sy);
// };

// class Circle {
// 	Point2D Center;
// 	double Radius;
//     const double PI = 3.14;
// public:
// 	void Set(double x0, double y0, double r);
// 	void Move(double dx, double dy);
//     double Area();	
//     double Perimeter();
// };

class Point2D {
    double x, y;
public:
    void Set(double x0, double y0)
    {
        x=x0;
        y=y0;
    }
    void Move(double dx, double dy)
    {
        x=x+dx;
        y=y+dy;
    }
    void Scale(double sx, double sy)
    {
        x=x*sx;
        y=y*sy;
    }
};

class Circle{
    Point2D Center;
    double Radius;
    const double PI = 3.14;
public:
    void Set(double x0, double y0, double r)
    {
        Center.Set(x0,y0);
        if(r>0) this->Radius= r;
    }
    void Move(double dx,double dy)
    {
        Center.Move(dx,dy);
    }
    double Area()
    {
        return PI*Radius*Radius;
    }
    double Perimeter()
    {
        return 2*PI*Radius;
    }
};
#endif _FIGURES_H