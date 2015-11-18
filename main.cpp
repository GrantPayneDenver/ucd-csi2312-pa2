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


 Reteset all these for Point class:

        friend std::istream &operator>>(std::istream &, Point &);


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


    Cluster a(3);
    Cluster b(3);

    a.add(p1);
    a.add(p2);
    a.add(p3);
    a.add(p4);

    b = a;




    return 0;
}