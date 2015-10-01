#include <iostream>
#include "Point.h"
#include "Cluster.h"

using namespace std;
using namespace Clustering;

int DIMS = 3;

int main()
{


    Point p1(DIMS);
    Point p2 = p1; // same as p2(p1)
    Cluster c1;
    PointPtr ptr = &p1;
    c1.add(ptr);
    Point p3(DIMS);
    PointPtr ptr2 = &p3;
    c1.add(ptr2);

    Point p4(DIMS);
    PointPtr ptr3 = &p4;
    c1.add(ptr3);

    Cluster c2(c1);  // if there are 3 points to copy, should hear loop signal twice

   // cout << p1 << endl;
   // cout << p2 << endl;
   // cout << p3;

    cout << c1;
    //cout << p2;

    // make
    //cout << c2;

    return 0;
}