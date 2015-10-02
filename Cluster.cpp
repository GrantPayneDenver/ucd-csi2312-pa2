
#include "Cluster.h"
#include "Point.h"
#include <iostream>

int DIM = 3;

namespace Clustering {

// Cluster.cpp
// Note: not all methods shown

// copy ctor
    Cluster::Cluster(const Cluster &rhs) {
        std::cout << "copy constructor entered" << std::endl;

        this->size = rhs.size;

        // need a conditional block to handle an empty cluster

        // take care of first case, linking head to first node
        //create new node
        //assign new head to it
        //now go through

        LNodePtr firstNode = new LNode();
        this->points = firstNode;      // link the new c's head to first node
        LNodePtr prevNode = firstNode; // set prevNode to first for a linking mechanism
        LNodePtr iterate = rhs.points; // points to first node of copied c
        firstNode->p = iterate->p;     // copies point information
        iterate = iterate->next;       // set iterate to next node of copied c to 'prime' the for loop

        for (; iterate != NULL; iterate = iterate->next) {
            // for each node of copied c
            // create a new node
            // set prev node point to new node
            // copy c's node's p pointer
            std::cout << "copy test" << std::endl;
            LNodePtr newNode = new LNode();            // create new node
            prevNode->next = newNode;                  // link the new node to new list
            prevNode = newNode;                        // set prevNode to new node
            newNode->p = iterate->p;                   // copy data from old point to new point
        }
    }

// dtor
/*
~Cluster() {
    if (points != nullptr) {
        for (int i = 0; i < size; i ++)
            delete points[i];
        delete [] points;
    }
    points = nullptr;
}



*/
    void Cluster::add(const PointPtr &pnt)
    {
        LNodePtr newNode = new LNode;
        newNode->p = pnt;

        if (this->points == NULL)
        {
            std::cout << "points was null, in c.add" << std::endl;

            newNode->next = NULL;
            this->points = newNode;
            this->size++;
        }
        else
        {
            LNodePtr curr = this->points;                // curr points to first node
            LNodePtr prev = curr;                        // prev points to curr
            bool placed = true;
            int count = 1;

            while( curr != NULL && placed)
            {
            std::cout << "entered list, comparing new node to current nodes" << std::endl;
//            for (int i = 0; i < newNode->p->getDim(); i++)
//            {
//                if (newNode->p->getCoor(i) > curr->p->getCoor(i) && count == 1) // > operator DIDNT WORKKKKKKKKKKK
                if(newNode->p > curr->p && count == 1)
                {
                    newNode->next = curr;      // this line works
                    //prev = newNode;
                    this->points = newNode;
                    this->size++;
                    placed = false;
                    break;
                }
//                else if (newNode->p->getCoor(i) > curr->p->getCoor(i)) {
                  else if (newNode->p > curr->p) {
                    newNode->next = curr;
                    prev->next = newNode;
                    this->size++;
                    placed = false;
                    break;
                } //else if
                //else if () // we reach end of list and find no placement
//            } // for
            prev = curr;
            curr = curr->next;
            count++;
            } // while

        } // else

    }//+++++ end add


// +++++++++++++++++++++++ OVERLOADEDS ++++++++++++++++++++++++++++++++++ \\

// parameters: const Cluster reference obj, ostream obj, (i think)
// precondition: Cluster obj isn;t empty
// postcondition: Print out of all of cluster's Linked List, to display each point and it's coordinates

    std::ostream &operator<<(std::ostream &out, const Cluster &c) {
        // start at front of list, points
        // create a LNodePtr to iterate through list

        if (c.points != NULL)
        {
            LNodePtr iterate;
            for (iterate = c.points->next; iterate != NULL; iterate = iterate->next)
            {
                for (int i = 0; i < iterate->p->getDim(); i++)
                    out << iterate->p->getCoor(i) << std::endl;
            }
        }

        return out;
    } // end overloaded <<

//*/

// +++++++++++++++++++++++ END OVERLOADEDS +++++++++++++++++++++++++++++++++ \\

} // clustering