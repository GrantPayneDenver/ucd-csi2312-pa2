#include <iostream>
#include "Point.h"
#include "Cluster.h"
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

using namespace Clustering;

int DIMS = 3; // default dimensions for program is 3

int main()
{
    /*10/5
     * don't kno how to implement clustor dtr
     * get weird runtime errors when I do += and -= for point class, -= cause segABRT
     *
     * 10/8 seem to have dtr and +- and +=
     *
     * must finish point >> operator
     * and finish cluster class
     *
     *
     * retest point = operator.
     *
    */

    Point p1(DIMS, 1, 2, 3);
    Point p2(DIMS, 4, 5, 6);
    Point p3(DIMS, 1, 1, 1);
    Point p4(DIMS, 7, 8, 9);
    Point p5(DIMS, 0, 0, 0);
    Point z (DIMS, 3, 3, 3);
    Point z2(DIMS, 3, 3, 3);

    /*

    Point p;// call default
    p = p1;

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

    Cluster c1;

    PointPtr ptr2 = &p1;

    c1.add(ptr2);
    ptr2 = &p3;
    c1.add(ptr2);
    ptr2 = &p4;
    c1.add(ptr2);

    ptr2 = &p2;


    c1 += p2;    // has p2 only after this
    c1 -= p2;
    c1.remove(ptr2);

    c1.calcCent();

    cout << c1;




/*
   PointPtr pt = &z;

    int i = 0;
    if (i == 0)
    {
        Cluster c2;
        c2.add(pt); /// this may have called destructor


        cout << "!!!" << endl;
    } // cluster goes out  of scope

*/
//3    cout << c1;

   // cout << p1 << endl;
   // cout << p2 << endl;
   // cout << p3;

   // cout << c1;
    //cout << p2;

    // make
    //cout << c2;

    return 0;
}