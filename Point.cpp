
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "Point.h"
#include "Exceptions.h"

using namespace std;

const int DIMS = 3;

// Constructor
// takes in dim, creates dynamic array size of dim, coor then points to it


unsigned int Point::IDgenerator = 0;
/*
Point::Point(int num) {

    //_id = GenerateID(true);
    _id(++IDgenerator);
    dim = num;
    coor = std::vector<double>(num);
/*
    for (int i = 0; i < dim; i++)
    {
        double input;
        //std::cout << "Enter coordinate for dimension " << i << std::endl;
        //std::cin >> input;
        input = rand() % 20;
        coor[i] = input;
    }
*/
//}

// assignment operator overloaded
// this pointer used for left hand side, calling obj. rhs is right hand side, copied from, object
// p1 = p2.
Point& Point::operator=(const Point &rhs)
{
    //delete []coor;  // delete current array      in case dims isn't equal??? shouldn't happen tho.

    //coor = new double[rhs.dim];

    dim = rhs.dim;

    for (int i = 0; i < dim; i++)
    {
        coor[i] = rhs.coor[i];
    }
    return *this;
} // end overloaded assignment operator

unsigned int Point::GenerateID(bool inc)
{
    static unsigned int num = 1;
    std::cout << "Point ID gen: " << num << std::endl;
    if (!inc)
    {
        --num;
        return num;
    }
    return num++;
}


// Destructor
Point::~Point() {
}

// copy constructor
Point::Point(const Point &copied)

{
    dim = copied.dim;
    coor = std::vector<double>(dim);
    for (int i = 0; i < dim; i++)
    {
        coor[i] = copied.coor[i];
    }
}

// Accessing

int Point::getDims()
{
   return dim;
} // end getDim

void Point::setValue(int index, double value)
{
    coor[index] = value;
}

double Point::getValue(int index) const
{
    return coor[index];
}

//functions

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

//MEMBERS
Point& Point::operator*=(double num)
{
    for (int i = 0; i < dim; i ++)
    {
        coor[i] *= num;
    }
    return *this;
}

Point& Point::operator/=(double num)
{
    for (int i = 0; i < dim; i ++)
    {
        coor[i] /= num;
    }
    return *this;
}

const Point Point::operator*(double num) const
{
    Point p(dim);

    for (int i = 0; i < dim; i++)
    {
        p.coor[i] = coor[i] * num;
    }

    return p;
    // p2 = p3 * 5;
}

const Point Point::operator/(double num) const
{
    Point p(dim);

    for (int i = 0; i < dim; i++)
    {
        p.coor[i] = coor[i] / num;
    }

    return p;
}

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
    bool different = false;                    // different is false until proven otherwise


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
            return less;
        }
        if(a.coor[i] < b.coor[i])
        {
            less = true;
            return less;
        }
    }

    return less;
}

bool operator<=(const Point &a, const Point &b)
{
    bool lessOrEqual = true;                         // a point is <= than until proven otherwise

    for (int i = 0; i < a.dim; i ++)
    {
        if (a.coor[i] > b.coor[i])                  // if any a point > any b point
        {
            lessOrEqual = false;                     // less is false, break
            break;
        }
        if (b.coor[i] < a.coor[i])
        {
            lessOrEqual = false;                     // less is false, break
            break;
        }
    }
    return lessOrEqual;
}

bool operator>(const Point &a, const Point &b)          // greater than operator. if p1 > p2 means if a(,,,) < b(,,,), a = p1, b = p2
{

    bool greater = true;
                                                        // a is larger until proven otherwise
    for (int i = 0; i < a.dim; i++)
    {

        if (b.coor[i] > a.coor[i])                      // if any b coor is larger then any a coor we have a false situation
        {
            greater = false;
            return greater;
        }
        if(a.coor[i] > b.coor[i])                       //  if any a coor is larger than any b coor we have a true situation
        {
            greater = true;
            return greater;
        }
    }

    return greater;
}

bool operator>=(const Point &a, const Point &b) // if p1 >= p2, a >= b
{
    bool greaterOrEqual = true;
    // a is greater or equal until proven otherwise
    for (int i = 0; i < a.dim; i++)
    {
        if (b.coor[i] > a.coor[i]) {                   // if any b coor is larger then any a coor we have a false situation
            greaterOrEqual = false;
            return greaterOrEqual;
        }
        if (a.coor[i] >= b.coor[i])
        {
            greaterOrEqual = true;
            return greaterOrEqual;
        }

    }

    return greaterOrEqual;
}

std::ostream &operator<<(std::ostream &out, const Point &p)
{
    cout<< std::fixed <<std::setw(2) << std::setprecision(1);

    out << p._id << ": ";

    for (int i = 0; i < p.dim; i++)
    {
        out << p.coor[i] << ", ";
    }

    return out;

} // end <<

//+= operator
Point operator+=(Point &lhs, const Point &rhs)
{
    // overload += first, have
    Point temp(lhs + rhs);
    lhs = temp;

    // or could rewrite machinery used in +
    //return rhs;
    return lhs;

}//end +=
//calls dtr after =

// + operator
const Point operator+(const Point &a, const Point &b)
{
    // create a point from argument point information
    // get point dimensions
    Point p(a.dim);

    // get information
    double sum = 0;
    for (int i = 0; i < a.dim; i ++)
    {
        sum = a.coor[i] + b.coor[i];
        p.coor[i] = sum;
    }

    return p;                                           // returns p, exits function, goes to = op
}// end + operator

//-= operator
Point operator-=(Point &lhs, const Point &rhs)
{
    Point temp(lhs - rhs);
    lhs = temp;

    return lhs;
}

// operator -
const Point operator-(const Point &a, const Point &b) // just make sure its like + op
{
    // create a point from arguemnt point information
    Point p(a.dim);

    double dif = 0;
    for (int i = 0; i < a.dim; i ++)
    {
        dif = a.coor[i] - b.coor[i];   // pairwise dimension subtraction
        p.coor[i] = dif;
    }

    return p;
}
// end - operator


std::istream& operator>>(std::istream& lineStream, Point &p)
{
    int i = 0;
    double d;
    string value;
    double numFromLine;
    int pointDims = p.getDims();
    int lineSegments = 0;  // keeps track of distinct numbers in linesStream; Ex: "___,___,___,___"

    //point>>

        while (getline(lineStream, value, ',')) {
            lineSegments++;                              // for every iteration while segments of lineStream last, increment.

                if(lineSegments > pointDims)
                {
                    throw Clustering::DimensionalityMismatchEx(lineSegments, pointDims);        // create and throw an exception obj
                }

            string text = value;

            std::stringstream thing(text);

            if (!(thing >> numFromLine)) // if this doesn't work, num = 0;
                numFromLine = 0;

            d = numFromLine;

            std::cout << "Value: " << d << std::endl;

            p.setValue(i++, d);
        }

        if (lineSegments < pointDims)
            throw Clustering::DimensionalityMismatchEx(lineSegments, pointDims);



    //All Point exceptions should be "external" relative to the class code but "internal" relative to the Clustering codebase.

} // end >> operator

//********************************************************
//End overloaded operators
