#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#ifndef __point_h
#define __point_h


//namespace Clustering {

    class Point {

    private:
        int dim;                               // dim will be used to initialize the dynamic array
        //double *coor;
        unsigned int _id;
        std::vector<double> coor;
        static unsigned int IDgenerator;

    public:



        // Constructors

        Point(): dim(0), coor(0){_id = IDgenerator;};   // default        // ID generated
        Point(int num): dim(0), _id(IDgenerator++)
        {
            dim = num;
            coor = std::vector<double>(num);
        };                         // one argument constructor              // ID generated



        static unsigned int GenerateID(bool inc)
        {
            static unsigned int num = 0;
            std::cout<<"Point ID gen: " << num << std::endl;
            if(!inc)
            {
                --num;
                return num;
            }
            return num++;
        }

        // Big 3, overloaded=, dstr, copy
        Point &operator=(const Point &);         // overloaded assignment operator
        ~Point();                                // destructor
        Point(const Point &);                    // copy constructor


        // distanceTo
        double distanceTo(const Point &);
        void setDim(unsigned dimFromKmeans){dim = dimFromKmeans;};
        void setCoor(int num){coor = std::vector<double>(dim);};
        int getDims();
        void setValue(int, double);
        double getValue(int) const;
        int getID(){return _id;};

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
