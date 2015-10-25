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
    Point* pointsArray;             // array of points
    double SCORE_DIFF_THRESHOLD;    // score differential threshold that determines the stopping point of the clustering process
    Clustering::Cluster* cList;

public:

   KMeans(double scoreDiff, int kay, unsigned d) : SCORE_DIFF_THRESHOLD(scoreDiff), dimensions(d), k(kay), cList(nullptr){}; // and also threshold value too later on

   void setK(int);

   double computeClusteringScore();

   void createClusters(std::ifstream &);

   void clusterizeData();


};


#endif //UCD_CSI2312_PA2_KMEANS_H
