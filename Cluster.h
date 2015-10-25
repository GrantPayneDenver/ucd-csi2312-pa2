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
        unsigned dimensionality;    // dimensionality of the points that cluster holds
        unsigned int ID;            // static int that increments when each new C made
        PointPtr centroid;          // Pointer to a dynamic point, centroid.
        int size;                   // length of linked list
        LNodePtr points;            // head, head is the start of a linked list of LNodes, not a Node its self
                                    // it is a LNodePtr, a pointer to nodes.

    public:
        class Move
        {
        public:
            void perform(const PointPtr &, Cluster *, Cluster *);
        };

    public:
        Cluster():dimensionality(0), size(0), points(nullptr), centroid(nullptr){ID = GenerateID();};          // default
        Cluster(unsigned d) : dimensionality(d), size(0), points(nullptr), centroid(nullptr){ID = GenerateID();};
        // The big three: cpy ctor, overloaded operator=, dtor
        Cluster(const Cluster &);                                                  // done
        Cluster &operator=(const Cluster &);                                       // implement
        ~Cluster();

        int getSize(){return size;}
        void setDimensionality(unsigned d) {dimensionality = d;};

        static unsigned int GenerateID()
        {
            static unsigned int num = 0;
            return num++;
        }

        // Set functions: They allow calling c1.add(c2.remove(p));
        // take point out of c2 and give to c1
        void add(const PointPtr &pnt);                                             // done
        const PointPtr &remove(const PointPtr &);                                  // done
        // Overloaded operators

        // IO
        friend std::ostream &operator<<(std::ostream &, const Cluster &);
        friend std::istream &operator>>(std::ifstream &, Cluster &);             // done

        // Set-preserving operators (do not duplicate points in the space)
        // - Friends
        friend bool operator==(const Cluster &lhs, const Cluster &rhs);          // done
        friend double interClusterDistance(const Cluster &lhs, const Cluster &rhs);

        // - Members

        Cluster &operator-=(const Cluster &rhs); // (asymmetric) difference     // done
        Cluster &operator+=(const Cluster &rhs); // union                       // done
        Cluster &operator+=(const Point &rhs);   // add point */                // done
        Cluster &operator-=(const Point &rhs);   // remove point                // done
        double intraClusterDistance();           // inner distance of a single cluster
        void pickPoints(int &, PointPtr& );      // selects points from point_space cluster
        double getClusterEdges();                // cluster edges of one cluster, the calling obj


        // Set-destructive operators (duplicate points in the space)
        // - Friends
        friend const Cluster operator+(const Cluster &lhs, const Cluster &rhs);     //done
        friend const Cluster operator-(const Cluster &lhs, const Cluster &rhs);     // will have same issue I'm sure..
        friend const Cluster operator+(const Cluster &lhs, const PointPtr &rhs);    // c2 = c1 + p1 // done
        friend const Cluster operator-(const Cluster &lhs, const PointPtr &rhs);    // c2 = c1 - p1 // done
        friend double interClusterEdges(const Cluster &, const Cluster &);


        /*
         * need a void pickPoints func
         *
         * also think about private moves class
         */

        //CENTROID

        void calcCent();
        void setCent(Point &);

    };
}// clustering

#endif // UCD_CSCI2312_PA1_CLUSTER_H
