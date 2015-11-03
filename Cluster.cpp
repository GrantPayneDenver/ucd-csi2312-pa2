
#include "Cluster.h"
#include "Point.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>


using namespace std;

namespace Clustering {

// Cluster.cpp


    Cluster &Cluster::operator=(const Cluster &rhs)
    {

        // FIRST, clear out calling cluster if need be.
        // assign size of calling obj to parameter obj
        // handle parameter obj being 0 or 1 in size first

        if(points != nullptr)                       // do work if cluster isn't empty
        {
            if (size == 1)
            {
                delete points;
            }
            else
            {
                LNodePtr next = points->next;      // get node after points node

                for(int i = 0; i < size -1; i++)   // delete nodes up until you have one left
                {
                    delete points;
                    points = next;
                    next = next->next;
                }
                delete points;                      // delete last node
            }
        }

        this->size = rhs.size;                // copy size of rhs into calling obj

        if(this->size == 0)                   // if it turns out that calling obj was empty return this.
        {
            return *this;
        }
        if(this->size == 1)
        {
            LNodePtr onlyNode = new LNode();  // take care of first and only node;
            onlyNode->p = rhs.points->p;      // copy the one point
            this->points = onlyNode;          // link head to onlyNode
            return *this;
        }

        LNodePtr copy = rhs.points;

        LNodePtr firstNode = new LNode();  // take care of first node;
        firstNode->p = copy->p;
        this->points = firstNode;
        LNodePtr prev = firstNode;
        copy = copy->next;

        while(copy)//should work even if size is zero
        {
            LNodePtr newNode = new LNode();
            newNode->p = copy->p;
            prev->next = newNode;
            prev = newNode;
            copy = copy->next;
        }

      return *this;
    }// end = operator

// copy ctor
    Cluster::Cluster(const Cluster &rhs)
    {
        std::cout << "copy constructor entered" << std::endl;

        this->dimensionality = rhs.dimensionality;

        ID = GenerateID();

        this->size = rhs.size;

        if(this->size > 1) {

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
        }// if size > 1

        if(this->size == 1)
        {
            LNodePtr onlyNode = new LNode();
            onlyNode->p = rhs.points->p;
            this->points = onlyNode;
        }

        //if size is 0, then nothing will happen

    } //cpy ctr

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


    if(points != nullptr)                       // do work if cluster isn't empty
    {
        if (size == 1)
        {
             delete points;
        }
        else
        {
            LNodePtr next = points->next;      // get node after points node

            for(int i = 0; i < size -1; i++)   // delete nodes up until you have one left
            {
                delete points;
                points = next;
                next = next->next;
            }
            delete points;                      // delete last node


        }
    }

        if(centroid != nullptr)
            delete centroid;

} // end ~Cluster


    void Cluster::add(const PointPtr &pnt)
    {
        //if (pnt == nullptr)
        //    return;
        // assert(pnt);
        LNodePtr newNode = new LNode();
        newNode->p = pnt;

        if (this->points == nullptr)
        {
            std::cout << "points was null in c.add" << std::endl;

            newNode->next = nullptr;
            this->points = newNode;
            this->size++;
            centValid = false;
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
                    centValid = false;
                    looking = false;
                    break;
                }

                 else if (*newNode->p > *curr->p) {                                                                  // not first
                    newNode->next = curr;
                    prev->next = newNode;
                    this->size++;
                    centValid = false;
                    looking = false;
                    break;
                } //else if
                else if (curr->next == nullptr) // we reach end of list and find no placement                         // reached end of list
                {
                    std::cout << "reached end of list" << std::endl;
                    newNode->next = nullptr;
                    curr->next = newNode;
                    this->size++;
                    centValid = false;
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

        if(*points->p == *remove->p) // if first node is the one to be removed
        {
            curr = points->next;   // save the second node
            delete points;         // delete first node
            points = curr;         // set head to second node.
            --size;
            centValid = false;
            return pd;
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
                centValid = false;
                if(size == 0)
                points = nullptr;
                return pd;
            }
        }

    }// end remove


    LNodePtr Cluster::operator[](int index)
    {
        if(index < this->size)
        {
            //send in 4, return the 5th
            // 0,1,2,3,4
            LNodePtr ptr = this->points;//starts at 0
            int count = 0;
            for (; count < index; count++)
            {
                ptr = ptr->next;
            }
           return ptr;
        }
    }

//++++++++++++++++++++++++ MEMBERS +++++++++++++++++++++++++++++++++++++\\\

    Cluster& Cluster::operator+=(const Cluster &rhs)
    {
        Cluster c = *this;             // calls cpy ctr
        *this = c + rhs;
        c.centroid = nullptr;          // for some reason c has a centroid pointing to something, so set to nullptr
        return *this;
    }// end += for clusters

    Cluster& Cluster::operator-=(const Cluster &rhs)
    {
        Cluster c = *this;              // calls cpy ctr
        *this = c - rhs;
        c.centroid = nullptr;
        return *this;
    }// end -= for clusters

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

    double Cluster::intraClusterDistance()
    {
        double sum = 0;
        LNodePtr firstNode = points;
        LNodePtr thruNode = points;

        while(firstNode)
        {
            while(thruNode)
            {
                sum+= (*firstNode->p).distanceTo(*thruNode->p);

                thruNode = thruNode->next;
            }
            firstNode = firstNode->next;
        }

        return sum / 2;
    }


    void Cluster::pickPoints(int &k, PointPtr &pointArray)
    {
        // length of cluster linked list / k assigned to an int
        // the int is size of the interval between linked list elements we
        // give the point array


        // if k <= size
        int interval = size / k;

        if (interval == 0)
            interval = 1;

        LNodePtr traverse = points;
        int counter = 0;
        pointArray[counter] = *points->p;

        while (counter < size +1)
        {

            for (int i = 0; i < k - 1; i++)                  // divide linked list by intervals, // maybe just - 1 iterval.
            {
                for (int y = 0; y < interval; y++) {
                    if (traverse != nullptr)
                        traverse = traverse->next;           // move thru linked list interval times
                }
                counter++;
                if (traverse != nullptr)
                    pointArray[counter] = *traverse->p;
            }

        }


    }// pick points end

    double Cluster::getClusterEdges()
    {
        double edges;
        edges = ((size -1 ) * size)/2;
        return edges;
    }

    //get edges end


// parameters: const Cluster reference obj, ostream obj, (i think)
// precondition: Cluster obj isn;t empty
// postcondition: Print out of all of cluster's Linked List, to display each point and it's coordinates

    std::ostream &operator<<(std::ostream &out, const Cluster &c) {
        // start at front of list, points
        // create a LNodePtr to iterate through list

        if (c.points != NULL)
        {
           // out << "Cluster ID: " << c.ID << std::endl;

            LNodePtr iterate;


            for (iterate = c.points; iterate != NULL; iterate = iterate->next)
            {
                out << *iterate->p << " : " << c.ID <<  std::endl;
            }

            if(c.centroid)
            out << "Centroid" << std::endl << *c.centroid << std::endl;
            else{
                out << "Centroid not yet calculated" << std::endl;
            }
        }

        else{
            out << "Cluster is empty. " << std::endl;
        }
        return out;
    } // end overloaded <<


//SET DESTRUCTIVE OPERATORS
    //Duplicate points in the space

    //+ operator
    const Cluster operator+(const Cluster &lhs, const Cluster &rhs)
    {
        // take two const clust refs
        // return the the points in lhs that are distinct from rhs

        // check for clusters being empty, just return an empty cluster

        Cluster c(lhs.dimensionality);                                // new cluster

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
                //PointPtr p = new Point(*addInNode->p);       // now we have dynamic point, whereas all others are static..hmm

                Point p(*addInNode->p);

                //c.add(p);        // c.add with a pointPtr argument.

                c+=p;              // p should go out of scope, but might be okay...
            }

            addInNode = addInNode->next;    // on to next node in rhs
            nextNode = c.points;            // set nextNode back to start of c list.
        } // while

        return c;
    }// end overloaded + operator


                      // !!! //


    //overloaded - operator
    const Cluster operator-(const Cluster &lhs, const Cluster &rhs)
    {
        // take two const clust refs
        // return the the points in lhs that are distinct from rhs

        // check for clusters being empty, just return an empty cluster

        Cluster c(lhs.dimensionality);                                // new cluster

        if(lhs.size == 0 && rhs.size == 0)
        {
            return c;
        }

        c = lhs;                                  // assign cluster c to lhs cluster, SOMEHOW CENTROIDS ARE SAME...weird..
        LNodePtr nextNode = c.points;             // node to travel through lhs's nodes, that are in c
        LNodePtr addInNode = rhs.points;          // travels through rhs, assigns nodes into c if need be

        //outer loop, run through rhs' points
        // inner loop, run through c's points

        while(addInNode != nullptr)                // while running thru rhs
        {
                                                   //bool out, false, meaning assume that we'll not be trimming a node from c upon inspecting rhs
            bool out = false;

            while(nextNode != nullptr)             // step through c
            {

                if(*addInNode->p == *nextNode->p)  // found a node in rhs that matches a node in c
                {
                    out = true;
                    break;
                }

                nextNode = nextNode->next;
            } // inner while
                                                   // if break, get out of searching thru c
            if(out)                                // found a node to remove from c
            {
                Point p(*addInNode->p);

                c-=p;                       // error caused here.. does remove actually work?
            }

            addInNode = addInNode->next;    // on to next node in rhs
            nextNode = c.points;            // set nextNode back to start of c list.
        } // outer while

    return c;
}// end overloaded -

// +++++++++++++++++++++++ END OVERLOADEDS +++++++++++++++++++++++++++++++++ \\


// CENTRIOD

void Cluster::calcCent()
{
    if(size == 0)
        points = nullptr;

    if (points) // if linked list not empty.
    {

       if (size == 1)                                               // centroid has a dynamic point
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
           while (curr != nullptr)
           {
               *centroid += *curr->p / size;         // hp = p2 /3

               curr = curr->next;                    // iterate to next node
           }//while
       } //else
    }// if (points)

    centValid = true;

} // calcCent

    void Cluster::setCent(Point &p)
    {
        if(centroid)                 // clear centroid if need be
            delete centroid;

        centroid = &p;               // have centroid point to Point sent in by reference.
        centValid = true;
    }


//FRIENDS, set preserving

    // ======
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


    double interClusterDistance(const Cluster &lhs, const Cluster &rhs)
    {
        double sum = 0;
        LNodePtr firstNode = lhs.points;
        LNodePtr thruNode = rhs.points;

        while(firstNode)
        {
            while(thruNode)
            {
                sum+= (*firstNode->p).distanceTo(*thruNode->p);

                thruNode = thruNode->next;
            }
            firstNode = firstNode->next;
        }

        return sum;

    }

// end set preserving


    // friend +
    const Cluster operator+(const Cluster &lhs, const PointPtr &rhs)    // c2 = c1 + p1
    {
        Cluster c(lhs);
        c.add(rhs);
        return c;
    }// end friend +

    // friend -
    const Cluster operator-(const Cluster &lhs, const PointPtr &rhs)    // c2 = c1 - p1
    {
        Cluster c(lhs);
        c.remove(rhs);
        return c;
    }// end friend -

    double interClusterEdges(const Cluster &lhs, const Cluster &rhs)
    {
        double edges;
        edges = ((lhs.size - 1) * (lhs.size)) / 2;
        edges += ((rhs.size - 1) * (rhs.size)) / 2;
        return edges;
    }//end interClusterEdges


    //friend >>
    std::istream &operator>>(std::ifstream &csv, Cluster &c)
    {
        // dimensionality known to user, it's 5

        std::string line;

        if (csv.is_open())
        {
            while (getline(csv, line))
            {
                std::cout << "Line: " << line << std::endl;
                std::stringstream lineStream(line);
                Point p(c.dimensionality);

                // point created with dimensionality five, from here
                // can use point >> operator and read in dims, then can
                // come back here and add point to cluster

                lineStream >> p;

                c+=p;
            }
        }

    }// end >>

// end FRIENDS


//=========================== MOVE CLASS ===================================\\

    void Cluster::Move::perform(const PointPtr &pt, Cluster *to, Cluster *from)
    {
        to->add(from->remove(pt));
        //Invalidates the centroids of both cluster from and to.
    }// end perform

} // clustering
