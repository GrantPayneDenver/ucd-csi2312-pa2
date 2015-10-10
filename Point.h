// A multi-dimensional point class!
// Number of dimensions is user input
// Coordinates are floating point double
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#ifndef __point_h
#define __point_h


//namespace Clustering {

    class Point {

    private:
        int dim;                               // dim will be used to initialize the dynamic array
        double *coor;                          // coor (short for coordinates) will be used to point to the dynamic array
                                                // of dimensions

    public:
        // Constructors

        Point();                            // default
        Point(int);                         // one argument constructor
        Point(int, double, double, double); // 4 argument for custom coordinates
        Point(double [], int);              //

        // Big 3, overloaded=, dstr, copy
        Point &operator=(const Point &);         // overloaded assignment operator
        ~Point();                                // destructor
        Point(const Point &);                    // copy constructor


        // distanceTo
        double distanceTo(const Point &);

        int getDims();
        void setValue(int, double);
        double getValue(int) const;

        double &operator[](int index) { return coor[index - 1]; }

        // Members
        Point& operator*=(double);
        Point &operator/=(double);
        const Point operator*(double) const; // prevent (p1*2) = p2;
        const Point operator/(double) const;

        // get coordinate
        double getCoor(int i) {return coor[i];}

        friend bool operator==(const Point &a, const Point &b);

        friend bool operator!=(const Point &a, const Point &b);

        friend bool operator<(const Point &a, const Point &b);
        friend bool operator<=(const Point &a, const Point &b);

        friend bool operator>(const Point &a, const Point &b);
        friend bool operator>=(const Point &a, const Point &b);

        friend const Point operator+(const Point &, const Point &);
        friend Point operator+=(Point &, const Point &);

        friend const Point operator-(const Point&, const Point &);
        friend Point operator-=(Point &, const Point &);

        friend std::ostream &operator<<(std::ostream &, const Point &);
        friend std::istream &operator>>(std::istream &, Point &);

    };

#endif //  __point_h

//}//clustering
