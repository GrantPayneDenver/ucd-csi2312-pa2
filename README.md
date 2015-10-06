# ucd-csi2312-pa2
Program is incomplete

Program works with two classes, a Point Class and a Cluster Class.

default amount of dimensions is 3
the program does prompt the user for a numebr, however. 

Point Class:
member data is dim, for dimensions number, and coor[], a dynamic array of doubles the size of dim



Point constructors:
no default, there is a constructor that takes in an int and 3 doubles so you can create your points custom, 
there is a constructor that takes in only an int that initializes the array size to that int and generates
random numbers for you.
There is also a constructor that takes in a double array and initializes a new point to the information in that array.

// copy constructor
Point::Point(const Point &copied)
copies information of on point to the other

Point functions:
double distanceTo(const Point &)
calculates the distance between two points, using euclidean math.

double getCoor(int i) {return coor[i];}

friend functions:

        friend bool operator==(const Point &a, const Point &b);

        friend bool operator!=(const Point &a, const Point &b);

        friend bool operator<(const Point &a, const Point &b);

        friend bool operator>(const Point &a, const Point &b);

        friend const Point operator+(const Point &, const Point &);
        friend Point operator+=(Point &, const Point &);

        friend const Point operator-(const Point&, const Point &);
        friend Point operator-=(Point &, const Point &);


        friend std::ostream &operator<<(std::ostream &, const Point &);
        
Cluster Class
The class contains a linked list, each node in the list points to a point, as well as another node or nullptr
if it's the last one.
The member data is points, the head of the list, and size, the size of list.



        default constructor
        Cluster() : size(0), points(nullptr) {};
   
        // The big three: cpy ctor, overloaded operator=, dtor
        Cluster(const Cluster &);
        constructor takes a cluster reference and initializes a new cluster with the referenced cluster
        
        Cluster &operator=(const Cluster &);
        constructor assigns information to calling cluster gathered from a referenced cluster
        
        ~Cluster();
        destructor, deletes all point pointers in the linked list, and also the nodes in the linked list. 
        

        // Set functions: They allow calling c1.add(c2.remove(p));
        // take point out of c2 and give to c1
        void add(const PointPtr &pnt);
        will add a new point to an existing cluster, in lexicographical order of the point dimensions
        

        // const PointPtr &remove(const PointPtr &);
        // Overloaded operators

        // IO
        friend std::ostream &operator<<(std::ostream &, const Cluster &);/*
        friend std::istream &operator>>(std::istream &, Cluster &);

        // Set-preserving operators (do not duplicate points in the space)
        // - Friends
        friend bool operator==(const Cluster &lhs, const Cluster &rhs);

        // - Members
        Cluster &operator+=(const Cluster &rhs); // union
        Cluster &operator-=(const Cluster &rhs); // (asymmetric) difference

        Cluster &operator+=(const Point &rhs); // add point
        Cluster &operator-=(const Point &rhs); // remove point

        // Set-destructive operators (duplicate points in the space)
        // - Friends
        friend const Cluster operator+(const Cluster &lhs, const Cluster &rhs);
        
        compares one cluster's nodes to another's. If any of the points are not the same, 
        ie same memory address, then the addition will be done and added to the new cluster.
        take all the points in one cluster and see the new cluster with them. Then compare the addend
        cluster to those points and add in what's not already there. 
        
        friend const Cluster operator-(const Cluster &lhs, const Cluster &rhs);

        friend const Cluster operator+(const Cluster &lhs, const PointPtr &rhs);
        friend const Cluster operator-(const Cluster &lhs, const PointPtr &rhs);
    
