//
// Created by Folio on 9/19/2015.
//

#ifndef UCD_CSCI2312_PA1_CLUSTER_H
#define UCD_CSCI2312_PA1_CLUSTER_H
#include "Point.h"

namespace Clustering {

    typedef Point *PointPtr;
    typedef struct LNode *LNodePtr;

//    struct LNode;
//    typedef LNode *LNodePtr;

    struct LNode {
        PointPtr p;
        LNodePtr next;
    };

    class Cluster {

    private:
        PointPtr centroid;
        int size;
        LNodePtr points;            // head, head is the start of a linked list of LNodes, not a Node its self
                                    // it is a LNodePtr, a pointer to nodes.

    private:
        class Centroid
        {
        private:
            int num = 3;               // gotta remove later
            Point centroid;            //
                                       // will need to calc mean of points on its own or get it from something else...

        public:
            void calcCent( );                   // send in one Point
            Point& getCent(LNodePtr &);        // return cent information
            void setCent(Point &);
        };



    public:
        Cluster() : size(0), points(nullptr), centroid(nullptr) {};
       ///*
        // The big three: cpy ctor, overloaded operator=, dtor
        Cluster(const Cluster &);


//         Cluster &operator=(const Cluster &);
        ~Cluster();

        // Set functions: They allow calling c1.add(c2.remove(p));
        // take point out of c2 and give to c1
        void add(const PointPtr &pnt);

        const PointPtr &remove(const PointPtr &);                                  //// done
        // Overloaded operators

        // IO
        friend std::ostream &operator<<(std::ostream &, const Cluster &);
        friend std::istream &operator>>(std::istream &, Cluster &);               /// worry about last

        // Set-preserving operators (do not duplicate points in the space)
        // - Friends
        friend bool operator==(const Cluster &lhs, const Cluster &rhs);          // done

        // - Members
        //friend Point &operator+=(Point &, const Point &); // union
        Cluster &operator-=(const Cluster &rhs); // (asymmetric) difference     // next
        Cluster &operator+=(const Cluster &rhs); // union
        Cluster &operator+=(const Point &rhs); // add point */                      // done
        Cluster &operator-=(const Point &rhs); // remove point                      // done

        // Set-destructive operators (duplicate points in the space)
        // - Friends
        friend const Cluster operator+(const Cluster &lhs, const Cluster &rhs);
        friend const Cluster operator-(const Cluster &lhs, const Cluster &rhs);

        friend const Cluster operator+(const Cluster &lhs, const PointPtr &rhs);
        friend const Cluster operator-(const Cluster &lhs, const PointPtr &rhs);

        /*
         * need a void pickPoints func
         *
         * also think about private moves class
         */


        //CENTROID

        void calcCent();

    };

}


#endif // UCD_CSCI2312_PA1_CLUSTER_H
