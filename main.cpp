#include <iostream>
#include "Point.h"
#include "Cluster.h"

using namespace std;
using namespace Clustering;

int DIMS = 3; // default dimensions for program is 3

int main()
{
    /*10/5
     * don't kno how to implement clustor dtr
     * get weird runtime errors when I do += and -= for point class, -= cauese segfault
     *
     *
     */
    cout << "what number of dimensions woukd you like your points to have?" << endl;
    cin >> DIMS;

    Point p1(DIMS, 1, 2, 3);
    Point p2(DIMS, 4, 5, 6);
    Point p3(DIMS, 1, 1, 1);
    Point p4(DIMS, 7, 8, 9);
    Point p5(DIMS, 0, 0, 0);

    // p4, p2, p1, p3, p5

    //Point p5(DIMS, 9, 10, 8);
    //Point p6(DIMS, 9, 9, 10);

       cout << p1 << endl;
    cout << p2 << endl;

//    p1-=p3
//    p1+=p3;
    Point p6 = p3 + p2;

    p5 = p3 + p4;

    Cluster c1;

    PointPtr ptr = &p1;
    c1.add(ptr);

    ptr = &p2;
    c1.add(ptr);

    ptr = &p3;
    c1.add(ptr);

    ptr = &p4;
    c1.add(ptr);

    ptr = &p5;
    c1.add(ptr);


    int i = 0;
    if (i == 0)
    {
        Cluster c2(c1);

    }


    cout << c1;

   // cout << p1 << endl;
   // cout << p2 << endl;
   // cout << p3;

   // cout << c1;
    //cout << p2;

    // make
    //cout << c2;

    return 0;
}