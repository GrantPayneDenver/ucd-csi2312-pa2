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





 */

int main()

{




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

    Point p1(3);
    Point p2(3);
    Point p3(3);
    Point p4(3);
    Point p5(3);


    Cluster a(3);
    Cluster b(3);

    a.add(p1);
    a.add(p2);
    a.add(p3);
    a.add(p4);


    b.add(p5);
    b.add(p4);

    Cluster c(b);

    if (c == b) cout << " c == b true " << endl;

    Point p6(3);
    Point p7(3);

    b.add(p3);

    b.add(p7);

    cout << "cluster a" << a;
    cout << "cluster b" << b;

    c = b;

    Cluster z(3);

    z.add(p4);

//    a = z - b;

    cout << "cluster a" << endl;
    cout << endl << a;

//    a-=b;

    cout << "cluster a before -= p5" << endl;
    cout << a;

    a-=p5;

    cout << "cluster a after -= p5 " << endl;
    cout << a;

    a+=p5;

    cout << "cluster a" << endl;
    cout << a;

    a-=p5;

    cout << "cluster a" << endl;
    cout << a;


    p4 += p1;

    double v = a.intraClusterDistance();
    double vv = interClusterDistance(a, b);



    return 0;
}