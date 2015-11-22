
#ifndef UCD_CSI2312_PA2_EXCEPTIONS_H
#define UCD_CSI2312_PA2_EXCEPTIONS_H
#include "Point.h"

namespace Clustering {

////////////////////////////////////
// POINT EXCEPTION CLASSES . . . . .
////////////////////////////////////
    class DimensionalityMismatchEx {
    private:

        int dimsRecieved;
        int dimsExpected;
        std::string name;

    public:

        DimensionalityMismatchEx(int &w, int &c) : dimsRecieved(w), dimsExpected(c), name("DimensionalityMismatchEx")
        { };

        int getDimsRecieved()const {return dimsRecieved;};
        int getDimsExpected()const {return dimsExpected;};
        std::string getName(){return name;};
        friend std::ostream &operator<<(std::ostream &out, const DimensionalityMismatchEx &e) // do this inline
        {
            out << "Expected dimensions: " << e.getDimsExpected() << "Recieved dimensions: " << e.getDimsRecieved() <<
            ". Point not created." << std::endl;
            return out;
        }        //friend std::ostream &operator<<(std::ostream &, const Cluster &);



    };

    class OutOfBoundsEx {

    };

////////////////////////////////////
// CLUSTER EXCEPTION CLASSES * * * *
////////////////////////////////////

    // how does one program the OutOfBounds cluster exceptoin? seems to cause a redefinition error, unless they use the same one..

    class RemoveFromEmptyEx {

        // when the remove() or comptCentroid() methods are called, when the cluster is empty. Throw an exception. these will occur in Kmeans
    private:
        int indexAttempted;

    public:

       friend std::ostream &operator<<(std::ostream&, const RemoveFromEmptyEx &);

    };

} // Clustering

#endif //UCD_CSI2312_PA2_EXCEPTIONS_H