#include <iostream>
#include <cstring>
#include <cmath>

class Point {
private:
    double x = 0;
    double y = 0;

    void swap(Point &);
public:
    Point();
    Point(double, double);
    Point(const Point &);
    Point &operator=(const Point &);
    double getX();
    double getY();
    Point getPoint();
};



class Polyline{
protected:
    size_t sz = 0;
    Point *verices = nullptr;
private:
    void swap(Polyline &);
public:
    Polyline(const std::initializer_list<Point> &);
    Polyline(const Polyline&);
    Polyline& operator=(const Polyline &);
    double size(int, int);
    ~Polyline();
};

class ClosedPolygonal: public Polyline {
protected:
    void swap(ClosedPolygonal&);
public:
    ClosedPolygonal(const std::initializer_list<Point>&);
    ClosedPolygonal(const ClosedPolygonal&);
    ClosedPolygonal& operator=(const ClosedPolygonal&);
    double size();
    ~ClosedPolygonal();
};


class Polygon: public ClosedPolygonal {
private:
    void swap(Polygon& Polygon);
public:
    Polygon(const std::initializer_list<Point>&);
    Polygon(const Polygon&);
    Polygon& operator=(const Polygon& );

    virtual double square();
    ~Polygon();

};

class Triangle: public Polygon {
private:
    void swap(Triangle&);
public:
    Triangle(const std::initializer_list<Point>&);
    Triangle(const Triangle&);

    Triangle& operator=(const Triangle&);
    bool isRight();
    ~Triangle();
};

class Trapeze: public Polygon {
private:
    void swap(Trapeze&);
    double  vectorProduct( Point&, Point& );
    bool isTrapeze();
public:
    Trapeze(const std::initializer_list<Point>& );
    Trapeze(const Trapeze& );
    Trapeze& operator=(const Trapeze&);
    ~Trapeze();
};

class RegularPolygon: public Polygon {
private:
    void swap(RegularPolygon&);
public:
    RegularPolygon(const std::initializer_list<Point>&);
    RegularPolygon(const RegularPolygon& );
    RegularPolygon& operator=(const RegularPolygon&);
    double size();
    ~RegularPolygon();
};
