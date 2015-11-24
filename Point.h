#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

#ifndef __point_h
#define __point_h


//namespace Clustering {
template <typename T>

    class Point {

    private:
        int dims;                              // dim will be used to initialize the dynamic array
        unsigned int _id;
        std::vector<T> coor;

    public:



        // Constructors

        Point(): dims(0), coor(0){_id = GenerateID(true);};   // default        // ID generated
        Point(int num);                                      // one argument constructor              // ID generated

        static unsigned int GenerateID(bool inc);
        void rewindIdGen(){GenerateID(false);};

        // Big 3, overloaded=, dstr, copy
        Point<T> &operator=(const Point<T> &rhs)         // overloaded assignment operator
        {
            dims = rhs.dims;

            for (int i = 0; i < dims; i++)
            {
                coor[i] = rhs.coor[i];
            }
            return *this;
        } // end overloaded assignment operator

        ~Point();                                // destructor
        Point(const Point &);                    // copy constructor


        // distanceTo
        double distanceTo(const Point &)const;
        void setDim(unsigned dimFromKmeans){dims = dimFromKmeans;};
        void setCoor(int num){coor = std::vector<T>(dims);};
        int getDims();
        void setValue(int, T);
        T getValue(int) const;
        unsigned int getID() const {return _id;};
        void setID(unsigned int num) {_id = num;};

        T &operator[](int index) { return coor[index - 1]; }

        // Members
        Point& operator*=(double);
        Point& operator/=(double);
        const Point operator*(double) const; // prevent (p1*2) = p2;
        const Point operator/(double) const;

        // get coordinate
        double getCoor(int i) {return coor[i];}

        friend bool operator==(const Point &a, const Point &b)
        {

            if(a._id != b._id)
                return false;

            bool equal = true;                 // equal is true until proven otherwise

            for (int i = 0; i < a.dims; i++)
            {
                if (a.coor[i] != b.coor[i])
                {
                    equal = false;             // found a coor pair that isn't the same
                    return equal;                     // false
                }
            }
            return equal;
        }


        friend bool operator!=(const Point &a, const Point &b)
        {
            if(a._id != b._id)
                return true;

            bool different = false;                    // different is false until proven otherwise

            for (int i = 0; i < a.dims; i++) {
                if (a.coor[i] != b.coor[i]) {      // if any coor pair is found different
                    different = true;
                    return different;
                }
            }

            return different;
        }

        friend bool operator<(const Point &a, const Point &b)
        {
            bool less = true;                         // a point is less than until proven otherwise

            for (int i = 0; i < a.dims; i ++)
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
        template <typename s>
        friend bool operator<=(const Point<s> &a, const Point<s> &b);

        friend bool operator>(const Point &a, const Point &b)
        {
            bool greater = true;
            // a is larger until proven otherwise
            for (int i = 0; i < a.dims; i++)
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

        template <typename s>
        friend bool operator>=(const Point<s> &a, const Point<s> &b);

        //operator+(Point<double> const&, Point<double> const&)
        //friend const Point operator+(const Point &, const Point &);

        friend const Point<T> operator+(const Point<T> &a, const Point<T> &b)
        {
                // create a point from argument point information
                // get point dimensions
                GenerateID(false);
                Point<T> p(a.dims);


                // get information
                double sum = 0;
                for (int i = 0; i < a.dims; i ++)
                {
                    sum = a.coor[i] + b.coor[i];
                    p.coor[i] = sum;
                }

                return p;                                           // returns p, exits function, goes to = op
        }// end + operator


        friend Point<T> operator+=(Point<T> &lhs, const Point<T> &rhs)
        {
            // overload += first, have
            GenerateID(false);
            Point<T> temp(lhs + rhs);
            lhs = temp;

            return lhs;

        }//end +=


        friend const Point<T> operator-(const Point<T>&a, const Point<T> &b)
        {
            // create a point from arguemnt point information
            GenerateID(false);
            Point<T> p(a.dims);


            double dif = 0;
            for (int i = 0; i < a.dims; i ++)
            {
                dif = a.coor[i] - b.coor[i];   // pairwise dimension subtraction
                p.coor[i] = dif;
            }

            return p;
        }

        friend Point operator-=(Point &lhs, const Point &rhs)
        {
            Point<T> temp(lhs - rhs);
            GenerateID(false);
            lhs = temp;

            return lhs;
        }

        friend std::ostream &operator<<(std::ostream &out, const Point<T> &p)
        {
            std::cout << std::fixed << std::setw(2) << std::setprecision(1);

            out << p._id << ": ";

            for (int i = 0; i < p.dims; i++)
            {
                out << p.getValue(i) << ", ";
            }

            return out;

        } // end <<
        friend std::istream &operator>>(std::istream & lineStream, Point<T> &p);
        /*
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
*/
    }; // class Point

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Point.cpp"

/*
template<typename T>
std::ostream &operator<<(std::ostream &out, const Point<T> &p)
{
    std::cout << std::fixed << std::setw(2) << std::setprecision(1);

    out << p._id << ": ";

    for (int i = 0; i < p.dim; i++)
    {
        out << p.coor[i] << ", ";
    }

    return out;

} // end <<

 */
/*
template<typename T>
const Point<T> operator+(const Point<T> &a, const Point<T> &b)
{
    // create a point from argument point information
    // get point dimensions
    Point<T> p(a.dim);

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


template<typename T>
bool operator<=(const Point<T> &a, const Point<T> &b) {
    bool lessOrEqual = true;                         // a point is <= than until proven otherwise

    for (int i = 0; i < a.dims; i++) {
        if (a.coor[i] > b.coor[i])                  // if any a point > any b point
        {
            lessOrEqual = false;                     // less is false, break
            break;
        }
        if (b.coor[i] < a.coor[i]) {
            lessOrEqual = false;                     // less is false, break
            break;
        }
    }
    return lessOrEqual;
}

template<typename T>
bool operator>=(const Point<T> &a, const Point<T> &b) // if p1 >= p2, a >= b
{
    bool greaterOrEqual = true;
    // a is greater or equal until proven otherwise
    for (int i = 0; i < a.dims; i++)
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
/*
template<typename T>
const Point<T> operator-(const Point<T> &a, const Point<T> &b) // just make sure its like + op
{
    // create a point from arguemnt point information
    Point<T> p(a.dim);
    GenerateID(false);

    double dif = 0;
    for (int i = 0; i < a.dim; i ++)
    {
        dif = a.coor[i] - b.coor[i];   // pairwise dimension subtraction
        p.coor[i] = dif;
    }

    return p;
}
*/
#endif //  __point_h


