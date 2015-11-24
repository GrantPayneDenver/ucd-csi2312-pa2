#include <iostream>
#include <cstdlib>


#include "Point.h"
#include "Cluster.h"
#include "KMeans.h"

using namespace std;

using namespace Clustering;
/*
 * make sure compute clustering score works, debug it
 *
 * point ID generation doesn't work. Has something to do with the way they're being initialized in operator>> of Cluster, I think.
 *
   - and + functions create a new cluster, which increments the cluster ID generator...

Cluster

 cont working on fwd listing
 change centroid to Point instead of PointPtr???


    this returns NULL if points is empty. That would be a problem for the move.perfrom func, I'm sure.

    test:
    void pickPoints(int &, Point*&);                         // selects points from point_space cluster



    double intraClusterDistance();                                              // inner distance of a single cluster
    void pickPoints(int &, Point*&);                                            // selects points from point_space cluste
    double interClusterDistance(const Cluster &lhs, const Cluster &rhs)


Reimplement operator+(C, P) and operator-(C, P) to take a const Point & instead of PointPtr.
Reuse already implemented operators to get a very short and straightforward implementation

 Point

 Reteset all these for Point class:







    std::fstream seed;

    seed.open("C:\\Users\\Folio\\Desktop\\School\\intPA2\\ucd-csi2312-pa2\\numbers.csv");

    seed.clear();

    for(int i = 0; i < 6; i++)
    {
        double num = rand() % 100;
        seed << num;
        seed << ",";

        num = rand() % 100;
        seed << num;
        seed << ",";

        num = rand() % 100;
        seed << num;
        seed << ",";

        num = rand() % 100;
        seed << num;
        seed << ",";

        num = rand() % 100;
        seed << num;
        seed << std::endl;
    }

    seed.close();

    std::ifstream csv;

    csv.open("C:\\Users\\Folio\\Desktop\\School\\intPA2\\ucd-csi2312-pa2\\numbers.csv", std::ifstream::in);


    Point >> operator

    Point<T>& operator[](int);                                                 // done

        // Overloaded operators

 CLUSTER

        // IO
        friend std::ostream &operator<<(std::ostream &, const Cluster &);
        friend std::istream &operator>>(std::ifstream &, Cluster &);


        friend double interClusterDistance(const Cluster &lhs, const Cluster &rhs);


        double intraClusterDistance();           // inner distance of a single cluster
        void pickPoints(int &, Point<T>*&);         // selects points from point_space cluster
        double getClusterEdges();                // cluster edges of one cluster, the calling obj




        // do last

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

        //end do last

        friend double interClusterEdges(const Cluster &, const Cluster &);

        //CENTROID

        void calcCent();
        void setCent(Point<T> &);




 */
int main (){

    Cluster<double, 5> c;
    Point<double> p(5);
    Cluster<double, 5> d;
    Cluster<double, 5>::Move m;

    c.add(p);
    c.remove(p);
    c.add(p);
    cout << c[0] << endl;
    cout << p;

    //(const Point<T> &pt, Cluster *to, Cluster *from)
    m.perform(p, d, c);

    d.calcCent();

    cout << d;


    return 0;

}

