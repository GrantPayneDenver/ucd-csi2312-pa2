//
// Created by Folio on 10/17/2015.
//

#include "KMeans.h"
using namespace Clustering;
/*
Create a cluster point_space (the rest OPTIONAL) with __release_points set to true
Open data file and read in points into point_space
Pick k points to serve as initial centroids
Create k-1 empty clusters (the rest OPTIONAL) with __release_points set to false

 for (int i = 0; i < k - 1; i++)
    Cluster C;
    C.release_points = false;
    clusterArray[i] = C;
 }

 //if size five (0th ~ 4th indexes) as in made 4 clusters + 5th cluster point_space, the 4th index is k-1
 clusterArray[k-1] = points_space

Set the centroids of the the k clusters to the k points that were picked

 // prob have a Cluster Array set to size k, that point_space should be added to
 //

Create double score, double scoreDiff
Set scoreDiff = SCORE_DIFF_THRESHOLD + 1
---------------------------------------
loop until scoreDiff < SCORE_DIFF_THRESHOLD
    loop through all clusters
        loop through all points
            find the min distance(point, centroid)
            if centroid not of current cluster
                perform move(point, current, other)
    loop through all clusters
        if centroid invalid
            compute and set valid to true
    compute new clustering score
    compute absolute difference and set scoreDiff
---------------------------------------
write out the clustering results to a file
(OPTIONAL) move all points back to point_space by setting all other centroids to infinity
delete all clusters
 */
void KMeans::setK(int num)
{
    k = num;
}

///*
void KMeans::createClusters(std::ifstream & file) {

    Clustering::Cluster points_space(dimensions);

    file >> points_space;

    cList = new Cluster[k];                              // need a Cluster constructor that default builds Clusters...

    //Cluster* list[k];

    //cList[k];

//    PointPtr poinz[19];

//    for (int h = 0; h < k; h++) {
//        cList[h].setDimensionality(dimensions);          // make sure all the clusters have the right dimensionality
//    }

    for (int i = 0; i < k - 1; i++) {
        //Clustering::Cluster C(dimensions);               // should this C be dynamic???
        cList[i] = Cluster(dimensions);
    }

    cList[k - 1] = points_space;

    std::cout << points_space;

    Point* pointsArray;                                    // can't create an array of Points bc no default constructor. I BET
                                                           // undefined reference to `Point::Point()' when trying to make point[]
    pointsArray = new Point[k];

    for (int j = 0; j < k; j++)
    {
        pointsArray[j].setDim(dimensions);
        pointsArray[j].setCoor(dimensions);
    }

    points_space.pickPoints(k, pointsArray);

    std::cout << "points array made" << std::endl;
/*
    Cluster::Move m;

    Cluster c(5);

    Point p(dimensions);

    c+=p;

    PointPtr ptr = &p;

    Cluster *c1 = &points_space;
    Cluster *c2 = &c;

    m.perform(ptr, c1, c2);

    m.perfrom(point*&, to, from)
*/


}// end createClusters