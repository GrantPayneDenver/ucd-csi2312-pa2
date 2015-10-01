#include "Point.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
//using namespace Clustering;

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
    bool equal = true;
    if (a.dim != b.dim)
    {
        equal = false;
    }
    for (int i = 0; i < a.dim; i++)
    {
        if (a.coor[i] != b.coor[i])
        {
            equal = false;
            break;
        }
    }
    return equal;
}

bool operator!=(const Point &a, const Point &b)
{
    bool different = false;
    if (a.dim != b.dim)
    {
        different = true;
    }
    for (int i = 0; i < a.dim; i++)
    {
        if (a.coor[i] != b.coor[i])
        {
            different = true;
            break;
        }
    }
    return different;
}

bool operator<(const Point &a, const Point &b) // if p1 < p2 means if a(,,,) < b(,,,)
{
    bool less = false;

    for (int i = 0; i < a.dim; i ++)
    {
        if (a.coor[i] < b.coor[i])
            less = true;
        break;
    }

    return less;
}

bool operator>(const Point &a, const Point &b)
{
    bool greater = false;
    for (int i = 0; i < a.dim; i ++)
    {
        if (a.coor[i] > b.coor[i])
            greater = true;
        break;
    }

    return greater;

}

std::ostream &operator<<(std::ostream &out, const Point &p)
{
    for (int i = 0; i < p.dim; i++)
    {
        out << "Dimension " << i << ": "  << p.coor[i] << std::endl; // if i don't end line with <<std::end; nothing prints
    }

} // end <<
//********************************************************
//End overloaded operators
