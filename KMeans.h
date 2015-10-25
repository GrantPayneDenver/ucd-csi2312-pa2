//
// Created by Folio on 10/17/2015.
//

#include "Cluster.h"
#include "Point.h"
#include <vector>

#ifndef UCD_CSI2312_PA2_KMEANS_H
#define UCD_CSI2312_PA2_KMEANS_H



class KMeans
{
private:

    int k;                          // clusters in program
    unsigned dimensions;            // dimensionality of the points of the clusters

    Clustering::Cluster* cList;

public:

   KMeans(int kay, unsigned d) : dimensions(d), k(kay), cList(nullptr){}; // and also threshold value too later on

   void setK(int);

   void createClusters(std::ifstream &);


};


#endif //UCD_CSI2312_PA2_KMEANS_H
