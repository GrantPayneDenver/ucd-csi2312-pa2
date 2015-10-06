// A multi-dimensional point class!
// Number of dimensions is user input
// Coordinates are floating point double
#include <iostream>
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

        Point(int);                                         // one argument constructor
        Point(int, double, double, double); // 4 argument for custom coordinates
        Point(double [], int);

        // Big 3, overloaded=, dstr, copy
        Point &operator=(const Point &);         // overloaded assignment operator
        ~Point();                                // destructor
        Point(const Point &);                    // copy constructor


        // distanceTo
        double distanceTo(const Point &);

        // get Dimensions
        int getDim();

        // get coordinate
        double getCoor(int i) {return coor[i];}

        friend bool operator==(const Point &a, const Point &b);

        friend bool operator!=(const Point &a, const Point &b);

        friend bool operator<(const Point &a, const Point &b);

        friend bool operator>(const Point &a, const Point &b);

        friend const Point operator+(const Point &, const Point &);
        friend Point operator+=(Point &, const Point &);

        friend const Point operator-(const Point&, const Point &);
        friend Point operator-=(Point &, const Point &);


        friend std::ostream &operator<<(std::ostream &, const Point &);



    };

#endif //  __point_h

//}//clustering
