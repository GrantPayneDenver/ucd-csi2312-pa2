
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

#include "Point.h"
#include "Cluster.h"
#include "Exceptions.h"

using namespace std;

namespace Clustering {

   unsigned int Cluster::GenerateID(bool inc)
    {
        static unsigned int num = 1;
        if(!inc)
        {
            --num;
            return num;
        }
        return num++;
    }


    Cluster &Cluster::operator=(const Cluster &rhs)
    {

        // clear out this->points, size = 0
        points.clear();

        this->dimensionality = rhs.dimensionality;

        auto it = rhs.points.begin();

        while(it != rhs.points.end())
        {
            this->add(*it);
            it++;
        }

        return *this;
    }// end = operator

// copy ctor
    Cluster::Cluster(const Cluster &c)
    {
        this->dimensionality = c.dimensionality;
        ID = GenerateID(true);
        this->size = c.size;

        this->points.assign(c.points.begin(),c.points.end());

    } //cpy ctr

// dtor
Cluster::~Cluster() {
        if (this != nullptr) {
        if (centroid != nullptr && centValid == true)
            delete centroid;
    }
} // end ~Cluster


    void Cluster::add(const Point &pnt)
    {

        // if points is empty

        if(points.empty())
        {
            this->points.push_front(pnt);
            size++;
            //
            auto it = points.begin();
            it->setID(pnt.getID());
            //
            return;
        }

        if(size == 1)
        {
            auto it = points.begin();

            if(pnt < *it) {
                points.insert_after(it, pnt);
                //
                it++;
                it->setID(pnt.getID());
                //
            }
            else{
                points.push_front(pnt);
                //
                auto it = points.begin();
                it->setID(pnt.getID());
                //
            }
            size++;
            return;
        }

        //if size > 1
        if(size > 1)
        {
            auto it = points.begin();    // start it at front
            it++;                        // move it to 2nd element
            auto it2nd = points.begin(); // start it2nd at first element
            int count = 0;
            bool notPlaced = true;

            while (it != points.end()) {
                // if, immediately, pnt is greater than first element.
                if (pnt > *it2nd && count == 0) {
                    points.push_front(pnt);
                    //
                    auto it_again = points.begin();
                    it_again->setID(pnt.getID());
                    //
                    notPlaced = false;
                    break;
                }

                if (pnt > *it) {
                    points.insert_after(it2nd, pnt);
                    //
                    it2nd++;
                    it2nd->setID(pnt.getID());
                    //
                    notPlaced = false;
                    break;
                }
                it2nd = it;
                it++;
                count++;
            }

            if(it == points.end() && notPlaced)
            {
                points.insert_after(it2nd, pnt);
                //
                it2nd++;
                it2nd->setID(pnt.getID());
                //
            }
            size++;
        }

 //              if(*newNode->p > *curr->p && count == 1)                        // TODO  new node p > curr p try block... = += -= < >
 //               else if (*newNode->p > *curr->p) {                           // TODO  new node p > curr p try block... = += -= < >                             // not first


    }                                          //+++++ end add

    // Remove()
    const Point& Cluster::remove(const Point &pd)
    {


        if(points.empty())
        {
            return NULL;
        }

        if(size == 1)
        {
            auto it = points.begin();
            if(pd == *it)
            {
                points.clear();
                size--;
                return pd;
            }
        }

        auto it = points.begin();
        auto it2n = it;
        it++;

        while(it!= points.end())
        {
            if(*it2n == pd)
            {
                points.pop_front();
                size--;
                return pd;
            }

            if(pd == *it)
            {
                points.erase_after(it2n);
                size--;
                return pd;
            }

            it2n = it;
            it++;

        }

    }                                        // end remove


    Point& Cluster::operator[](int index)
    {
        auto it = points.begin();
        if(!points.empty())
        {
            for (int i = 0; i < index; i ++)
            {
                it++;
            }

        }

        return *it;
    }

//++++++++++++++++++++++++ MEMBERS +++++++++++++++++++++++++++++++++++++\\\
//
/*
    Cluster& Cluster::operator+=(const Cluster &rhs)
    {
        Cluster c = *this;             // calls cpy ctr
        Cluster::GenerateID(false);    // roll back ID generation
        *this = c + rhs;
        c.centroid = nullptr;          // for some reason c has a centroid pointing to something, so set to nullptr
        return *this;
    }// end += for cluster



    Cluster& Cluster::operator-=(const Cluster &rhs)
    {
        Cluster c = *this;              // calls cpy ctr
        Cluster::GenerateID(false);
        *this = c - rhs;
        c.centroid = nullptr;
        return *this;
    }// end -= for clusters
*/
    Cluster& Cluster::operator+=(const Point &rhs)
    {
        this->add(rhs);
        return *this;
    } // end += for points


    Cluster& Cluster::operator-=(const Point &rhs)
    {
        this->remove(rhs);
        return *this;
    }//end -= for points


    double Cluster::intraClusterDistance()
    {
        double sum = 0;
        auto firstNode = points.begin();
        auto thruNode = points.begin();

        while(firstNode != points.end())
        {
            while(thruNode != points.end())
            {
                sum+= (*firstNode).distanceTo(*thruNode);

                thruNode++;
            }
            firstNode++;
        }

        return sum / 2;
    }


    void Cluster::pickPoints(int &k, Point* &pointArray)
    {
        // length of cluster linked list / k assigned to an int
        // the int is size of the interval between linked list elements we
        // give the point array


        // if k <= size
        int interval = size / k;

        if (interval == 0)
            interval = 1;

        auto traverse = points.begin();
        int counter = 0;
        pointArray[counter] = *traverse;


            for (int i = 0; i < k - 1; i++)                  // divide linked list by intervals, // maybe just - 1 iterval.
            {
                for (int y = 0; y < interval; y++) {
                    if (traverse != points.end())
                        traverse = traverse++;           // move thru linked list interval times
                }
                counter++;
                if (traverse != points.end())
                    pointArray[counter] = *traverse;
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

        if (!c.points.empty())
        {
           // out << "Cluster ID: " << c.ID << std::endl;

            auto it = c.points.begin();

            while(it != c.points.end())
            {
                out << *it << " : " << c.ID <<  std::endl;
                it++;
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
    /*
    //+ operator
    const Cluster operator+(const Cluster &lhs, const Cluster &rhs)
    {
        bool add;
        Cluster c(rhs);                                               // new cluster
        Cluster::GenerateID(false);                                   // roll back ID gen


        if(lhs.size == 0 && rhs.size == 0)
        {
            return c;
        }
        if(lhs.size == 0)
            return rhs;
        if(rhs.size == 0)
            return lhs;

        // set c to rhs
        // add whats not in rhs, but in lhs, to rhs

        auto it = lhs.points.begin();


        while (it != lhs.points.end())
        {
            add = true;
            auto it2 = rhs.points.begin();

            while(it2 != rhs.points.end())
            {
                std::cout << *it << " c "  << std::endl;
                cout << *it2 << " rhs " << endl;

                if(*it == *it2)
                {
                    add = false;
                }

                it2++;
            }

            if(add) {
                c.add(*it);
                cout << "adding" <<endl;
            }
            it++;
        }

        return c;

    }// end overloaded + operator


                      // !!! //


    //overloaded - operator
    const Cluster operator-(const Cluster &lhs, const Cluster &rhs) // lhs - rhs
    {
        // take two const clust refs
        // return the the points in lhs that are distinct from rhs

        // check for clusters being empty, just return an empty cluster

        Cluster c (lhs.dimensionality);                                // new cluster, do I really even need to bother with making a new CLUSTER!!!
                                                                        // just return lhs after lhs - rhs.
        Cluster::GenerateID(false);

        if(lhs.size == 0 && rhs.size == 0)
        {
            return lhs;
        }
        if(lhs.size == 0)                        // if one C is empty while the other is not, return the non empty one.
            return rhs;
        if(rhs.size == 0)
            return lhs;

        c = lhs;                                  // assign cluster c to lhs cluster, SOMEHOW CENTROIDS ARE SAME...weird..
        auto itOuter = lhs.points.begin();
        //auto itInner = rhs.points.begin();


        //outer loop, run through rhs' points
        // inner loop, run through c's points

        while(itOuter != lhs.points.end())                // while running thru rhs
        {
                                                          //bool out, false, meaning assume that we'll not be trimming a node from c upon inspecting rhs
            bool out = false;
            auto itInner = rhs.points.begin();

            while(itInner != rhs.points.end())             // step through c
            {

                if(*itInner == *itOuter)           // found a node in rhs that matches a node in c
                {
                    out = true;
                    break;
                }

                itInner++;
            } // inner while
                                                   // if break, get out of searching thru c
            if(out)                                // found a node to remove from c
            {
                c.remove(*itInner);                       // error caused here.. does remove actually work?
            }

            itOuter++;                      // on to next node in rhs

        } // outer while


    return c;                // return c, constructor called, dtr called,

}// end overloaded -         // dtr called again.

// +++++++++++++++++++++++ END OVERLOADEDS +++++++++++++++++++++++++++++++++ \\

*/

// CENTRIOD

void Cluster::calcCent()
{
    if(size == 0)
        centroid = nullptr;

    if (!points.empty()) // if linked list not empty.
    {

       if (size == 1)                                               // centroid has a dynamic point
       {
           centroid = new Point(dimensionality);
           auto it = points.begin();
           *centroid = *it;                                  // centroid PointPtr = LNodePtr's LNode's PointPtr

       }
       else
       {
           // p1/3 + p2/3 + p3/3, 3 = size of linked list, or size member of cluster
//                                                                                             TODO try bloc, cent point += curr->point
           centroid = new Point(dimensionality);

           auto itr = points.begin();


           while (itr != points.end())
           {
               *centroid += *itr / size;         // hp = p1 /3

               itr++;                    // iterate to next node
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

        if(lhs.points.empty() && rhs.points.empty())
            return true;

        // if clusters are differnt size then not same
        if (lhs.size != rhs.size)
        {
            same = false;
            return same;
        }
        // if clusters are more than size one, go through linked list and compare
        // using overloaded == operator of Points.

        auto leftPtr = lhs.points.begin();
        auto rightPtr= rhs.points.begin();

        while(leftPtr != lhs.points.end())
        {

            if(*leftPtr != *rightPtr)
            {
                same = false;
                return same;
            }

            leftPtr++;
            rightPtr++;

        }// while

        return same;

    }// end == operator

    double interClusterDistance(const Cluster &lhs,const Cluster &rhs)
    {
        double sum = 0;
        auto firstNode = lhs.points.begin();
        auto thruNode = rhs.points.begin();

        while(firstNode != lhs.points.end())
        {
            while(thruNode != rhs.points.end())
            {

                sum += (*firstNode).distanceTo(*thruNode);

                thruNode++;
            }
            firstNode++;
        }

        return sum;
    }

// end set preserving


    // friend +
    const Cluster operator+(const Cluster &lhs, const Point &rhs)    // c2 = c1 + p1
    {
        Cluster c(lhs);
        Cluster::GenerateID(false);
        c.add(rhs);
        return c;
    }// end friend +

    // friend -
    const Cluster operator-(const Cluster &lhs, const Point &rhs)    // c2 = c1 - p1
    {
        Cluster c(lhs);
        Cluster::GenerateID(false);
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

                try
                {  //////////////////// Ensure point data meets expectations before it's added to c, roll back point ID if not.
                    lineStream >> p;

                    c += p;
                }  ////////////////////
                catch(DimensionalityMismatchEx e)
                {
                    std::cout << e.getName() << ":";
                    std::cout << e;
                    Point::GenerateID(false);           // decrements static id
                }

            }
        }

    }// end >>

// end FRIENDS


//=========================== MOVE CLASS ===================================\\

    void Cluster::Move::perform(const Point &pt, Cluster *to, Cluster *from)
    {
        to->add(from->remove(pt));
        //Invalidates the centroids of both cluster from and to.
    }// end perform




} // clustering
