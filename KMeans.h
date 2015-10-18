//
// Created by Folio on 10/17/2015.
//

#include "Cluster.h"
#include "Point.h"

#ifndef UCD_CSI2312_PA2_KMEANS_H
#define UCD_CSI2312_PA2_KMEANS_H


class KMeans
{

    // after universe is made
    // pick a k
    // pick k points from U as centroids for each k and U its self.
    // Initially U has all points but after it computers its intracluster distance it will be able to identify
    // many points that it will no longer wish to have
    // then it will be able to distribute those points to the other clusters
    // then each cluster, including U, can recompute its centroid
        // but then why assign random centroids to each k cluster from the beginning??


};


#endif //UCD_CSI2312_PA2_KMEANS_H
