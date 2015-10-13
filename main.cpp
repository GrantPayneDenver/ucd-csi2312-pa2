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
     *
     * must finish point >> operator
     * and finish cluster class
     *
     *
     * retest point = operator.

     *test cluster + operator
     * do - and + operator work with clusters that are only one node?

     need to handle empty rhs clusters in = and cpy ctr for cluster



    */

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



   Cluster c1;

    c1+=p1;
    c1+=p2;
    c1+=p3;

    Cluster c2;
    c2+= p1;
    c2 +=p2;
    c2 +=p3;
    c2+=p4;

    c1-=c2;
    c1.calcCent();

    PointPtr ptr = &p4;

    c1 = c2 - ptr;

    cout << c1 << endl;


    return 0;
}