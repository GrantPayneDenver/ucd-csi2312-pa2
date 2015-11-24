
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




template<typename T>
Point<T>::Point(int num) {
     _id = GenerateID(true);
     dims = num;
     coor = std::vector<T>(num);
     for (int i = 0; i < dims; i++)
        {
            double input;
            input = rand() % 20;
            coor[i] = input;
        }
    }

//}

// assignment operator overloaded
// this pointer used for left hand side, calling obj. rhs is right hand side, copied from, object
// p1 = p2.

/*
template<typename T>
Point<T>& Point<T>::operator=(const Point<T> &rhs)
{
    dim = rhs.dim;

    for (int i = 0; i < dim; i++)
    {
        coor[i] = rhs.coor[i];
    }
    return *this;
} // end overloaded assignment operator
*/
template<typename T>
unsigned int Point<T>::GenerateID(bool inc)
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

template<typename T>
Point<T>::~Point() {
}

// copy constructor
template<typename T>
Point<T>::Point(const Point<T> &copied)

{
    _id = copied._id;
    dims = copied.dims;
    coor = std::vector<T>(dims);
    for (int i = 0; i < dims; i++)
    {
        coor[i] = copied.coor[i];
    }
}

// Accessing
template<typename T>
int Point<T>::getDims()
{
   return dims;
} // end getDim

template<typename T>
void Point<T>::setValue(int index, T value)
{
    coor[index] = value;
}

template<typename T>
T Point<T>::getValue(int index) const
{
    return coor[index];
}

//functions

template<typename T>
double Point<T>::distanceTo(const Point<T>& pointIn)const{
    double distance;          // the end distance to be returned
    double sum = 0;
    double delta =0;

    //if(this == pointIn) must overload == operator
    for(int i = 0; i < dims; i ++)
    {
        delta = this->coor[i] - pointIn.coor[i];
        sum += pow(delta, 2);
    }

    distance = sqrt(sum);

    return distance;
} // end distanceTo

//MEMBERS
template<typename T>
Point<T>& Point<T>::operator*=(double num)
{
    for (int i = 0; i < dims; i ++)
    {
        coor[i] *= num;
    }
    return *this;
}

template<typename T>
Point<T>& Point<T>::operator/=(double num)
{
    for (int i = 0; i < dims; i ++)
    {
        coor[i] /= num;
    }
    return *this;
}

template<typename T>
const Point<T> Point<T>::operator*(double num) const
{
    Point<T> p(dims);
    GenerateID(false);

    for (int i = 0; i < dims; i++)
    {
        p.coor[i] = coor[i] * num;
    }

    return p;
    // p2 = p3 * 5;
}

template<typename T>
const Point<T> Point<T>::operator/(double num) const
{
Point<T> p(dims);
GenerateID(false);


for (int i = 0; i < dims; i++)
{
p.coor[i] = coor[i] / num;
}

return p;
}

// Overloaded operators
//*********************************
/*
template<typename T>
bool operator==(const Point<T> &a, const Point<T> &b)
{

    if(a._id != b._id)
        return false;

    bool equal = true;                 // equal is true until proven otherwise

    for (int i = 0; i < a.dim; i++)
    {
        if (a.coor[i] != b.coor[i])
        {
            equal = false;             // found a coor pair that isn't the same
            return equal;                     // false
        }
    }
    return equal;
}
*/
/*
template<typename T>
bool operator!=(const Point<T> &a, const Point<T> &b)
{
    if(a._id != b._id)
        return true;

    bool different = false;                    // different is false until proven otherwise

        for (int i = 0; i < a.dim; i++) {
            if (a.coor[i] != b.coor[i]) {      // if any coor pair is found different
                different = true;
                return different;
            }
        }

    return different;
}
*/
/*
template <typename T>
bool operator<(const Point<T> &a, const Point<T> &b) // if p1 < p2 means if a(,,,) < b(,,,)
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
*/
/*
template<typename T>
bool operator<=(const Point<T> &a, const Point<T> &b)
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
 */
/*
template<typename T>
bool operator>(const Point<T> &a, const Point<T> &b)          // greater than operator. if p1 > p2 means if a(,,,) < b(,,,), a = p1, b = p2
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
*/
/*
template<typename T>
bool operator>=(const Point<T> &a, const Point<T> &b) // if p1 >= p2, a >= b
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
*/
/*
template<typename T>
std::ostream &operator<<(std::ostream &out, const Point<T> &p)
{
    cout<< std::fixed <<std::setw(2) << std::setprecision(1);

    out << p._id << ": ";

    for (int i = 0; i < p.dim; i++)
    {
        out << p.coor[i] << ", ";
    }

    return out;

} // end <<
*/


//+= operator
/*
template<typename T>
Point<T> operator+=(Point<T> &lhs, const Point<T> &rhs)
{
    // overload += first, have
    Point<T> temp(lhs + rhs);
    lhs = temp;

    return lhs;

}//end +=
 */


/*
// + operator
template<typename S>
const Point<S> operator+(const Point<S> &a, const Point<S> &b)
{
    // create a point from argument point information
    // get point dimensions
    Point<S> p(a.dim);

    // get information
    double sum = 0;
    for (int i = 0; i < a.dim; i ++)
    {
        sum = a.coor[i] + b.coor[i];
        p.coor[i] = sum;
    }

    return p;                                           // returns p, exits function, goes to = op
}// end + operator

 */

//-= operator

/*
template<typename T>
Point<T> operator-=(Point<T> &lhs, const Point<T> &rhs)
{

    Point<T> temp(lhs - rhs);
    GenerateID(false);
    lhs = temp;

    return lhs;
}
 */

// operator -
/*
template<typename T>
const Point<T> operator-(const Point<T> &a, const Point<T> &b) // just make sure its like + op
{
    // create a point from arguemnt point information
    Point<T> p(a.dim);

    double dif = 0;
    for (int i = 0; i < a.dim; i ++)
    {
        dif = a.coor[i] - b.coor[i];   // pairwise dimension subtraction
        p.coor[i] = dif;
    }

    return p;
}
// end - operator
*/

template<typename T>
std::istream& operator>>(std::istream& lineStream, Point<T> &p)
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
