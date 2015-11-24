/*
 *     template <typename S>
    friend std::ostream &operator<<(std::ostream &os, const Point<S> &p);

};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Point<T> &p) {
    os << p.getX() << ", " << p.getY();

    return os;
}

 */


#ifndef UCD_CSCI2312_PA1_CLUSTER_H
#define UCD_CSCI2312_PA1_CLUSTER_H

#include <forward_list>

#include "Point.h"

namespace Clustering {

    template <typename T, int dimensionality>

    class Cluster {

    private:
        //unsigned dimensionality;    // dimensionality of the points that cluster holds
        unsigned int ID;            // static int that increments when each new C made
        Point<T> centroid;          // Pointer to a dynamic point, centroid.
        int size;                   // length of linked list
        bool centValid;
        std::forward_list<Point<T>> points;


    public:

        class Move
        {
        public:
            void perform(const Point<T> &, Cluster<T, dimensionality> &, Cluster<T, dimensionality> &);
        };

    public:

        Cluster();

        // The big three: cpy ctor, overloaded operator=, dtor
        Cluster(const Cluster &);                                                  // done
        Cluster &operator=(const Cluster &);                                       // done


        ~Cluster();

        //getters, setters
        Point<T> getCentroid(){return centroid;};
        //template <typename S>
        //std::forward_list<Point<>>::iterator getPoints(){return points.begin();};
        int getSize(){return size;}
        bool getCentValid(){return centValid;};


        static unsigned int GenerateID(bool inc);

        // Set functions: They allow calling c1.add(c2.remove(p));
        // take point out of c2 and give to c1
        void add(const Point<T> &pnt);                                             // done
        const Point<T>& remove(const Point<T> &);                                  // done
        Point<T>& operator[](int);                                                 // done
        // Overloaded operators

        // IO


        template <typename s, int dimensional>
        friend std::ostream &operator<<(std::ostream &out, const Cluster<s, dimensional> &c);


        template <typename s, int dimensional>
        friend std::istream &operator>>(std::ifstream &, Cluster<s, dimensional> &);

        // Set-preserving operators (do not duplicate points in the space)
        // - Friends
        friend bool operator==(const Cluster &lhs, const Cluster &rhs);

        template <typename s, int dimensional>
        friend double interClusterDistance(const Cluster<s, dimensional> &lhs, const Cluster<s, dimensional> &rhs);


        // - Members
        double intraClusterDistance();           // inner distance of a single cluster
        void pickPoints(int &, Point<T>*&);         // selects points from point_space cluster
        double getClusterEdges();                // cluster edges of one cluster, the calling obj

        Cluster &operator-=(const Cluster &rhs); // (asymmetric) difference
        Cluster &operator+=(const Cluster &rhs); // union
        Cluster &operator+=(const Point<T> &rhs);   // add point
        Cluster &operator-=(const Point<T> &rhs);   // remove point


        // Set-destructive operators (duplicate points in the space)
        // - Friends
        friend const Cluster operator+(const Cluster &lhs, const Cluster &rhs);     //done
        friend const Cluster operator-(const Cluster &lhs, const Cluster &rhs);
        friend const Cluster operator+(const Cluster &lhs, const Point<T> &rhs);    // c2 = c1 + p1 // done
        friend const Cluster operator-(const Cluster &lhs, const Point<T> &rhs);    // c2 = c1 - p1 // done

        template <typename s, int dimensional>
        friend double interClusterEdges(const Cluster<s, dimensional> &, const Cluster<s, dimensional> &);

        //CENTROID

        //template <typename s, int dimensional>
        void calcCent();

        void setCent(Point<T> &);

    }; // Cluster
/*
    template <typename T, int dimensionality>
    std::ostream &operator<<(std::ostream &out, const Cluster<T, dimensionality> &c) {
        // start at front of list, points
        // create a LNodePtr to iterate through list

        if (!c.points.empty())
        {
            // out << "Cluster ID: " << c.ID << std::endl;

            auto it = c.points.begin();

            while(it != c.points.end())
            {
                out << *it << " : " << c.ID <<  std::endl;
                it++;
            }

            if(getCentValid())
                out << "Centroid" << std::endl << c.centroid << std::endl;
            else{
                out << "Centroid not yet calculated" << std::endl;
            }
        }

        else{
            out << "Cluster is empty. " << std::endl;
        }
        return out;
    } // end overloaded <<
*/


}     // clustering

#include "Cluster.cpp"

#endif // UCD_CSCI2312_PA1_CLUSTER_H

//*/