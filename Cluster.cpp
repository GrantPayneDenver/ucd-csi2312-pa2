
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

Cluster::~Cluster() {
    // delete PointPtrs and nodes

    LNodePtr del = points;
    LNodePtr nextDel;

    while(del != nullptr)
    {
        nextDel = del->next;  // nextDel pointer saves next node
        delete del->p;        // delete the point pointer
        delete del;           // delete the node
        del = nextDel;        // set del to next node
    }   // shouldn't affect the actual Point object

    points = nullptr;
}


    void Cluster::add(const PointPtr &pnt)  // to do: check for duplicate point additions, can't have duplicate points.
    {                                       // this is not to say when the point has the same coordinates
                                            // but when is the same point literally, and memory location is one spot
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
            bool looking = true;
            int count = 1;

            while(curr != NULL && looking)
            {
            std::cout << "entered list, comparing new node to current nodes" << std::endl;

               if(*newNode->p > *curr->p && count == 1)
                {
                    newNode->next = curr;      // this line works
                    //prev = newNode;
                    this->points = newNode;
                    this->size++;
                    looking = false;
                    break;
                }

                 else if (*newNode->p > *curr->p) {                                                                  // not first
                    newNode->next = curr;
                    prev->next = newNode;
                    this->size++;
                    looking = false;
                    break;
                } //else if
                else if (curr->next == nullptr) // we reach end of list and find no placement                         // reached end of list
                {
                    std::cout << "reached end of list" << std::endl;
                    newNode->next = nullptr;
                    curr->next = newNode;
                    this->size++;
                    looking = false;
                    break;
                }// last else if

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

            int i = 1;

            for (iterate = c.points; iterate != NULL; iterate = iterate->next)
            {
                out << "Point " << i << std::endl << *iterate->p << std::endl;
                i++;
            }
        }

        return out;
    } // end overloaded <<

//*/

// +++++++++++++++++++++++ END OVERLOADEDS +++++++++++++++++++++++++++++++++ \\

} // clustering