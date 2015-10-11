
#include "Cluster.h"
#include "Point.h"
#include <iostream>

int DIM = 3;

namespace Clustering {

// Cluster.cpp

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

    /*
     * use two pointers, but one is head, so only need to create one pointer
     * this pointer will continually be a step ahead of head
     * head is the pointer through which deletions happen
     *  delete head->p   // deletes the pointPtr
     *  delete head      // deletes the node
     *  then you set head to next pointer, and move pointer up the chain
     *  need to account for a situation where cluster is empty or only has one node
     *  use the size member to help.
     */

    LNodePtr next = points->next;
    if(points != nullptr)                       // do work if cluster isn't empty
    {
        if (size == 1)
        {
             delete points;
        }
        else
        {
            for(int i = 0; i < size -1; i++)   // delete nodes up until you have one left
            {
                delete points;
                points = next;
                next = next->next;
            }
            delete points;                      // delete last node
        }
    }

} // end ~Cluster


    void Cluster::add(const PointPtr &pnt)  // to do: check for duplicate point additions, can't have duplicate points.
    {                                       // this is not to say when the point has the same coordinates
                                            // but when is the same point literally, and memory location is one spot
        LNodePtr newNode = new LNode();     // Why is LNodePtr newNode = new LNode() different than LNodePtr newNode = new LNode
        newNode->p = pnt;

        if (this->points == nullptr)
        {
            std::cout << "points was null in c.add" << std::endl;

            newNode->next = nullptr;
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

    // Remove()
    const PointPtr& Cluster::remove(const PointPtr &pd)
    {
        //during debugging, if you click pd, it say in red "attempt to take address
        // of value not located in memory"
        // pd is const PointPtr passed by reference.
        // it seems that it MUST be passed by reference. (at least in this program. Due to the dynamic data in Points?)
        // It makes intuitive sense
        // what is a pointer if not a reference? What good would passing a pointer
        // by value do? You make a copy of it, but it STILL must point to something
        // thus it is still referencing.


        if(!points)
            return pd;             // just return the point to be deleted, the list was empty....

        LNodePtr remove  = new LNode();  // so, if you want to really instantiate a LNodePtr, you
                                         // you must do all that, rather than just LNodePtr remove;
                                         // remove->p = pd causes an error. I don't understand why.
        remove->p = pd;            // pointer node with point info to be deleted

        LNodePtr curr;             // traverse nodes
        LNodePtr prev;

        if(points->p == pd) // if first node is the one to be removed
        {
            curr = points->next;   // save the second node
            delete points;         // delete first node
            points = curr;         // set head to second node.
        }

        else
        {
            curr = points;         // set curr to start traversing thru list

            // iterate thru list until a value is found that matches the value pd

            while(curr != nullptr && *curr->p != *pd )
            {
                prev = curr;            // save curr with prev
                curr = curr->next;      // have curr go on to next node

                // loop will terminate once end of list reached or we find the value being saught
            }// end while

            if(curr) // if curr found the desired node, and didn't reach the end of the list
            {
                prev->next = curr->next;// save linkage between previous node and node after curr
                delete curr;
                --size;
            }
        }




    }// end remove

//++++++++++++++++++++++++ MEMBERS +++++++++++++++++++++++++++++++++++++\\\

    Cluster& Cluster::operator+=(const Point &rhs)
    {
        this->add(new Point(rhs));

        return *this;
    } // end += for points


    Cluster& Cluster::operator-=(const Point &rhs)
    {
        this->remove(new Point(rhs));

        return *this;
    }//end -= for points

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

            out << "Centroid" << std::endl << *c.centroid << std::endl;
        }
        return out;
    } // end overloaded <<

//Set Preserving Operators
    //friends
    bool operator==(const Cluster &lhs, const Cluster &rhs)
    {
        bool same = true;       // clusters same until proven otherwise

        // if clusters are empty then they're the same

        if (lhs.points == nullptr && rhs.points == nullptr)
            return same;

        // if clusters are differnt size then not same
        if (lhs.size != rhs.size)
        {
            same = false;
            return same;
        }
        // if clusters are more than size one, go through linked list and compare
        // using overloaded == operator of Points.

        LNodePtr leftPtr = lhs.points;
        LNodePtr rightPtr= rhs.points;

        while(leftPtr != nullptr)
        {
            if(*leftPtr->p != *rightPtr->p)
            {
                same = false;
                return same;
            }

            leftPtr = leftPtr->next;
            rightPtr = rightPtr->next;

        }// while

        return same;

    }// end == operator

//SET DESTRUCTIVE OPERATORS
    //Duplicate points in the space
    /*
     * Overload operator+ to represent the UNION of two Cluster-s.
     * Example: C1 + C2. Hint: The union of two sets contains all the distinct elements that are in one, the other, or both sets. For example,
     * (p1, p3, p4) + (p4, p5, p8) is (p1, p3, p4, p5, p8).
     */

    //+ operator
    const Cluster operator+(const Cluster &lhs, const Cluster &rhs)
    {
        // take two const clust refs
        // return the union of them, all distinct elements, in a clust

        // check for clusters being empty, just return an empty cluster

        Cluster c;                                // new cluster

        if(lhs.size == 0 && rhs.size == 0)
        {
            return c;
        }

        c = lhs;                                  // assign cluster c to lhs cluster, SOMEHOW CENTROIDS ARE SAME...weird..
        LNodePtr nextNode = c.points;             // node to travel through lhs's nodes, that are in c
        LNodePtr addInNode = rhs.points;          // travels through rhs, assigns nodes into c if need be

        //outer loop, run through rhs' points
        // inner loop, run through c's points

        while(addInNode != nullptr)
        {
            //bool add, true, meaning we assume that each node of rhs is distinct and should go into c
            //until discovered otherwise
            bool add = true;

            while(nextNode != nullptr)     // step through c
            {

                if(*addInNode->p == *nextNode->p)
                {
                    add = false;
                    break;
                }

                nextNode = nextNode->next;
            } //while
            // if add wasn't made false, add addInNode to c

            if(add)
            {
                c.add(addInNode->p);        // c.add with a pointPtr argument.
                c.size++;
            }

            addInNode = addInNode->next;    // on to next node in rhs
        } // while

        return c;
    }// end overloaded + operator

/*    const Cluster Clustering::operator+(const Cluster &lhs, const Cluster &rhs)
    {
        // get union, or proper set of both clusters
        // store one cluster in a new cluster, cluster stored is lhs
        Cluster c(lhs);

        LNodePtr next = rhs.points;
        while(next!= nullptr)
        {
            c.add(next->p);          // add each node of rhs to c. add function should determine whether it
                                     // should really be added or not.
                                     // if two nodes are literally same, ie same mem address, then don't add
            next = next->next;
        }

        // loop thru rhs and add its points using add function, which will
        // only add if the point being added is unique

        return c;
    }
*/

// +++++++++++++++++++++++ END OVERLOADEDS +++++++++++++++++++++++++++++++++ \\


// CENTRIOD

void Cluster::calcCent()
{
    if (points) // if linked list not empty.
    {

       if (size == 1)                                             // centroid has a dynamic point
       {
           centroid = new Point(points->p->getDims());
           *centroid = *points->p;                                  // centroid PointPtr = LNodePtr's LNode's PointPtr

       }
       else
       {
           // p1/3 + p2/3 + p3/3, 3 = size of linked list, or size member of cluster

           centroid = new Point(points->p->getDims());

           *centroid = *points->p / size;            // hp = p1 / 3, if there are 3 nodes
           LNodePtr curr = points->next;             // access p2
           while (curr != nullptr) {
               *centroid += *curr->p / size;         // hp = p2 /3

               curr = curr->next;                    // iterate to next node
           }//while
       } //else
    }// if (points)

} // calcCent


} // clustering

