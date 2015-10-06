#include "Point.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
//using namespace Clustering;

const int DIMS = 3;

// Constructor
// takes in dim, creates dynamic array size of dim, coor then points to it
Point::Point(int num) {

    dim = num;
    coor = new double[dim];

    for (int i = 0; i < dim; i++)
    {
        double input;
        //std::cout << "Enter coordinate for dimension " << i << std::endl;
        //std::cin >> input;
        input = rand() % 10;
        coor[i] = input;
    }
}

// custom points constructor
Point::Point(int num, double a, double b, double c)
{
    dim = num;
    coor = new double[dim];
    coor[0] = a;
    coor[1] = b;
    coor[2] = c;
}

// flesh out point's dimensions,
//
Point::Point(double points[], int len)
{
    dim = len;
    coor = new double[dim];        // will this case a mem leak?

    for (int i = 0; i < len; i++)
    {
        this->coor[i] = points[i];
    }
}

// assignment operator overloaded
// this pointer used for left hand side, calling obj. rhs is right hand side, copied from, object
// p1 = p2.
Point& Point::operator=(const Point &rhs)
{

    if (dim != rhs.dim)
    {
        delete [] coor;
        coor = new double [rhs.dim];

    }

    for (int i = 0; i < dim; i++)
    {
        coor[i] = rhs.coor[i];
    }
    return *this;
} // end overloaded assignment operator


// Destructor
Point::~Point() {

    delete[] coor;
}

// copy constructor
Point::Point(const Point &copied)

{
    dim = copied.dim;
    coor = new double[dim];
    for (int i = 0; i < dim; i++)
    {
        coor[i] = copied.coor[i];
    }
}

// Accessing

int Point::getDim()
{
   return dim;
} // end getDim



double Point::distanceTo(const Point& pointIn){
    double distance;          // the end distance to be returned
    double sum = 0;
    double delta =0;

    //if(this == pointIn) must overload == operator
    for(int i = 0; i < dim; i ++)
    {
        delta = this->coor[i] - pointIn.coor[i];
        sum += pow(delta, 2);
    }

    distance = sqrt(sum);

    return distance;
} // end distanceTo



// Overloaded operators
//*********************************
bool operator==(const Point &a, const Point &b)
{
    bool equal = true;                 // equal is true until proven otherwise

    for (int i = 0; i < a.dim; i++)
    {
        if (a.coor[i] != b.coor[i])
        {
            equal = false;             // found a coor pair that isn't the same
            break;                     // false
        }
    }
    return equal;
}

bool operator!=(const Point &a, const Point &b)
{
    bool different = false;         // different is false until proven otherwise


        for (int i = 0; i < a.dim; i++) {
            if (a.coor[i] != b.coor[i]) {      // if any coor pair is found different
                different = true;
                break;
            }
        }

    return different;
}

bool operator<(const Point &a, const Point &b) // if p1 < p2 means if a(,,,) < b(,,,)
{
    bool less = true;                         // a point is less than until proven otherwise

    for (int i = 0; i < a.dim; i ++)
    {
        if (a.coor[i] > b.coor[i])            // if any a point > any b point
        {
            less = false;                     // less is false, break
            break;
        }
    }

    return less;
}

bool operator>(const Point &a, const Point &b)          // greater than operator
{
//    std::cout << " > operator accessed " << std::endl;

    bool greater = true;
                                                        // a is larger until proven otherwise
    for (int i = 0; i < 3; i++)
    {

        if (b.coor[i] > a.coor[i]) {                   // if any b coor is larger then any a coor we have a false situation
            greater = false;
            break;
        }
    }

//    std::cout << greater << "status reached" << std::endl;

    return greater;
}

std::ostream &operator<<(std::ostream &out, const Point &p)
{
    for (int i = 0; i < p.dim; i++)
    {
        out << "Dimension " << i << ": "  << p.coor[i] << std::endl; // if i don't end line with <<std::end; nothing prints
    }   // out is a ostream built up during this loop, it's returned after the loop concludes as one whole package

    return out;

} // end <<

//+= operator
Point operator+=(Point &lhs, const Point &rhs)
{
    lhs = rhs + lhs;
    //return rhs;

}//end +=

// + operator
const Point operator+(const Point &a, const Point &b)
{
    // create a point from arguemnt point information

    int dims = a.dim;                   // get point dimenstions
    double *darray = new double[dims];  // create array to hold them
                                        // this will 'seed' new point
    // get information
    double sum = 0;
    for (int i = 0; i < dims; i ++)
    {
        sum = a.coor[i] + b.coor[i];
        darray[i] = sum;
    }


    Point p(darray, dims);                    // use a Point constructor that takes in a
                                              // double array.
    return p;

}

//-= operator                                            // this function ends up calling the dtr
Point operator-=(Point &lhs, const Point &rhs)           // again after it reaches its end, but += doesn't..
{                                                        // no idea why. Causes a segfault.
    lhs = lhs - rhs;  // a-b
}

// operator -
const Point operator-(const Point &a, const Point &b)
{
    // create a point from arguemnt point information

    int dims = a.dim;                   // get point dimenstions
    double *darray = new double[dims];               // create array to hold them
    // this will 'seed' new point

    // get information
    double dif = 0;
    for (int i = 0; i < dims; i ++)
    {
        dif = a.coor[i] - b.coor[i];   // pairwise dimension subtraction
        darray[i] = dif;
    }

    Point p(darray, dims);

    return p;
}
// end - operator




//********************************************************
//End overloaded operators
