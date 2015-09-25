
#include "Cluster.h"
using namespace Clustering;

// Cluster.cpp
// Note: not all methods shown

// copy ctor
Cluster::Cluster(const Cluster &rhs)
{
    //       : size(rhs.size), capacity(rhs.capacity) {
    //   points = new PointPtr[capacity];
    //   for (int i = 0; i < capacity; i++)
    //       points[i] = nullptr;
    //   for (int i = 0; i < size; i++)
    //       points[i] = new Point(rhs.points[i]);

    this->size = rhs.size;
    LNodePtr thatClustersNodeHead = rhs.points;
    LNodePtr newNode = new LNode;
    points = newNode;
    LNodePtr thatClustersNode = thatClustersNodeHead->next;
    newNode = thatClustersNode;

    for (int i = 0; i < size; i++)
    {


    }




}


/*
// assignment oper
Cluster &operator=(const Cluster &rhs) {
    if (this == &rhs) {
        return *this;
    } else {
        if (points != nullptr) {
            for (int i = 0; i < size; i++)
                delete points[i];
            delete [] points;
        }

        this->size = rhs.size;
        this->capacity = rhs.capacity;

        this->points = new PointPtr[capacity];
        for (int i = 0; i < capacity; i++)
            this->points[i] = nullptr;
        for (int i = 0; i < size; i++)
            this->points[i] = new Point(rhs.points[i]);
    }

    return *this;
}

// dtor
~Cluster() {
    if (points != nullptr) {
        for (int i = 0; i < size; i ++)
            delete points[i];
        delete [] points;
    }
    points = nullptr;
}

*/
void Cluster::add(const PointPtr &pnt) // prob need a dynamic array of nodes, no?
{

    LNodePtr newNode = new LNode;

    if (points = nullptr)
    {
        this->size = 1;
        newNode->p = pnt;
        newNode->next = nullptr;
        points = newNode;
    }
    else
    {

    }

    /*
    if(points == nullptr)
        // points, or head, is empty
    {
        size = 1;
        points = new LNode[size];
        points[size].p = pnt;
        points[size].next = nullptr;
    }
    else // head isn't empty
    {
        points[size].p = pnt;
        points[size].next = nullptr;
        points[size-1] = points[size];
    } ++size; // if theres one this will go past the array's bounds, need to allocate more space
    */

    //node.p = pnt;
    //node.next = nullptr;

} // end add





//void Cluster::add(PointPtr const &ptr) {
// if

//}


/*
 *
 */
