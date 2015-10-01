
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
    void Cluster::add(const PointPtr &pnt) // prob need a dynamic array of nodes, no?
    {

        std::cout << "c.add entered" << std::endl;

        /*  nodes arranged by lexicographic order of their points
         *  largest to smallest actually WHAT ORDER IS SPECIFIED??
         *
         *
         * two situations
         * list is empty, simply let attach head to it
         * newNode points to NULL
         *
         * find first place where new node > current node
         * attach it there
         */

        LNodePtr newNode = new LNode;
        newNode->p = pnt;


        //this->size++;


        // if list is empty, just put
        // newNode after points(head)
        if (this->points == NULL)
        {
            std::cout << "points was null, in c.add" << std::endl;

            newNode->next = NULL;
            this->points = newNode;
            this->size++;
        }
        else
        {
            std::cout << "starting to look through nodes in c.add" << std::endl;

            // create a LNode pointer to run through existing nodes
            // create another one to trail it, and save previous spot
            LNodePtr curr = this->points;                // curr points to first node
            LNodePtr prev = curr;                        // prev points to curr


            // for loop to compare point's dims
            // gotta have a handle for if
            // we reach end of list and haven't found a spot
            // means newNode belongs at end of list

            std::cout<<"yo"<< std::endl;

            for(; curr != nullptr; curr = curr->next)       // this for loop seems to never be entered
                                                            // must be because curr is null ptr
                                                            // or because I have a fringe case error
                                                            // the process doesn't work when i only have one
                                                            // node on list
            {
                std::cout << "entered list, comparing new node to current nodes" << std::endl;
                    if (newNode->p > curr->p)
                    {
                        std::cout << "found a smaller node " << std::endl;

                        // new node is greater, add it to the list
                        // after node previously checked
                        newNode->next = curr;
                        prev->next = newNode;
                        this->size++;
                        break;
                    }
                    else if(curr->next == nullptr) // got to end of list and didn't find a node smaller than newNode
                    {

                        std::cout << "reached end of list, in c.add" << std::endl;
                        curr->next = newNode;      // last node points to newNode
                        newNode->next = nullptr;   // newNode next points to nullptr
                        this->size++;
                    }
                    else{
                        std::cout << "didn't find a spot, continuing to look, in c.add" << std::endl;

                        prev = curr;
                    }
            }
        }


    }//+++++ end add


// +++++++++++++++++++++++ OVERLOADEDS




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

// +++++++++++++++++++++++ END OVERLOADEDS

} // clustering