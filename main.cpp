#include <iostream>
#include "Point.h"
#include "Cluster.h"
#include "KMeans.h"
#include <cstdlib>



using namespace std;

using namespace Clustering;
/*
 * update the point <, <=, >=
 *
 * retest all cluster funcs, now that I've changed the constructor and initialization
 *
 * change all cluster funcs to handle points, not point ptr
 *
 * MAKE SURE THAT ALL MUTATOR FUNCS THAT CHANGE A CLUSTER INVALIDATE THE CENTROID

   - and + functions create a new cluster, which increments the cluster ID generator...

   assignment and copy ctr need to handle centroids. Can't simply have
   pointPtrs point to same point. That'll be a quick path to segfault.

 */

int main()

{


   // Cluster* cPtr;
   // cPtr = new Cluster(5);

    //Point pointArray[10];
    //int foo[3];
    //Cluster cList[10];


    std::fstream seed;

    seed.open("C:\\Users\\Folio\\Desktop\\School\\intPA2\\ucd-csi2312-pa2\\numbers.csv");

    seed.clear();

    for(int i = 0; i < 10; i++)
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

//    std::ifstream csv;

//    csv.open("C:\\Users\\Folio\\Desktop\\School\\intPA2\\ucd-csi2312-pa2\\numbers.csv", std::ifstream::in);

    KMeans kOne(3, 5);

//    one.setK(5);
//    one.createClusters(csv, 5);

///*
    Cluster universe(5);

    std::ifstream csv;

    csv.open("C:\\Users\\Folio\\Desktop\\School\\intPA2\\ucd-csi2312-pa2\\numbers.csv", std::ifstream::in);

    csv >> universe; // call overloaded cluster extraction operator

    csv.close();

    cout << universe;

    //double icd = universe.intraClusterDistance();
//*/

// !!!!!!!!!!!!
//    PointPtr pointArray[universe.getSize()]; // could fill this thing with universe's size


    /*
    Point p1(DIMS, 1, 2, 3);
    Point p2(DIMS, 4, 5, 6);
    Point p3(DIMS, 1, 1, 1);
    Point p4(DIMS, 7, 8, 9);
    Point p5(DIMS, 0, 0, 0);
    Point z (DIMS, 3, 3, 3);
    Point z2(DIMS, 3, 3, 3);
/*

    z += p1;

    z-=p2;                // error again!!!

    z *= 5;
    cout << z << endl;
    z /= 3;
    cout << z << endl;
    p1 = z*5;
    cout << p1 << endl;
    p1 = z / 5;
    cout << p1 << endl;
    if (z > p3){cout << "true" << endl;}
    if (z >= p2) {cout << "trye " << endl;}
    if (z >= p3) {cout << "trye " << endl;}
    z+=p1;                 // error
    cout << z<< endl;
    p5 = z + 3;
    cout << z << endl;
    if (z == z2) {cout << "true" << endl;}
    if (z != p4) {cout << "true " << endl;}
    if (z < p4)  {cout << "true" << endl;}
    if (z <= p4) {cout << "true" << endl;}
    cout << z << endl;
    p2 = z - 1;           // this may not work, need ot override -= function for doubles too.
    cout << z << endl;

*/


    // p4, p2, p1, p3, p5

    //Point p5(DIMS, 9, 10, 8);
    //Point p6(DIMS, 9, 9, 10);


///*
    int DIMS = 5;

    Point p1(DIMS);
    Point p2(DIMS);
    Point p3(DIMS);
    Point p4(DIMS);
    Point p5(DIMS);
    Point z (DIMS);
    Point z2(DIMS);


   Cluster c1(5);

    c1+=p1;
    c1+=p2;
    c1+=p3;

    Cluster c2(5);
    c2+= p1;
    c2 +=p2;
    c2 +=p3;
    c2+=p4;

    c1-=c2;
    c1.calcCent();

    PointPtr ptr = &p4;

    //c1 = c2 - ptr;

    cout << c1 << endl;

    Cluster::Move m;

    Cluster *pc1 = &c1;
    Cluster *pc2 = &c2;

    m.perform(ptr, pc1, pc2);

    universe += c1;
    universe += c2;
    universe += c1;
//*/
    cout << universe;

    cout <<"end";
    return 0;
}