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
 * update the point <, <=, >=
 *
 * retest all cluster funcs, now that I've changed the constructor and initialization
 *
 *
 * MAKE SURE THAT ALL MUTATOR FUNCS THAT CHANGE A CLUSTER INVALIDATE THE CENTROID

   - and + functions create a new cluster, which increments the cluster ID generator...

   assignment and copy ctr need to handle centroids. Can't simply have
   pointPtrs point to same point. That'll be a quick path to segfault.


    make sure move:Invalidates the centroids of both cluster from and to.
   //////// probably better done with just lines in add and remove that invalidate the centroid.

   Reimplement __values as a std::vector<double>. Use vector methods and iterators to
   manipulate the point values. You should be able to do that without changing the interface.
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

    KMeans kOne(2, 5);  // 2 clusters, dimensionality of 5, as of now file has 10 points


    kOne.createClusters(csv);

    kOne.clusterizeData();

    kOne.printClusters();

    csv.close();


    return 0;
}