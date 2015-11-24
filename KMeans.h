//
// Created by Folio on 10/17/2015.
//


#include "Cluster.h"
#include "Point.h"
#include <vector>

#ifndef UCD_CSI2312_PA2_KMEANS_H
#define UCD_CSI2312_PA2_KMEANS_H

template <typename T, int dimensionality>

class KMeans
{

private:

    int k;                                // clusters in program
    unsigned dimensions;                  // dimensionality of the points of the clusters
    Point<T>* pointsArray;                   // array of points

    double SCORE_DIFF_THRESHOLD = .0005;          // score differential threshold that determines the stopping point of the clustering process

    Clustering::Cluster<T, dimensionality>* cList;

public:

   KMeans( int kay, unsigned d) : dimensions(d), k(kay), cList(nullptr) { };

   void setK(int);
   double computeClusteringScore();
   void createClusters(std::ifstream &);
   void clusterizeData();
   void printClusters();


};


#endif //UCD_CSI2312_PA2_KMEANS_H

//*/