//
// Created by Folio on 10/17/2015.
//
#include <cassert>
#include "KMeans.h"
using namespace Clustering;
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

/*

Create a cluster point_space (the rest OPTIONAL) with __release_points set to true
Open data file and read in points into point_space
Pick k points to serve as initial centroids
Create k-1 empty clusters (the rest OPTIONAL) with __release_points set to false



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

//computes clustering score for use in score diff
//in: cList full of clusters
//out: Clustering Score
double KMeans::computeClusteringScore()
{
    assert(cList != nullptr);

    double numerator = 0;     // quotient of (sum of intra clust dist) over (# of intra cluster edges)
    double denominator = 0;  // quotient of (sum of intre clust dist) over (# of inter cluster edges)

    for(int i = 0; i < k; i ++)  // for all k clusters...
    {
        numerator += cList[i].intraClusterDistance() / cList[i].getClusterEdges();

        for (int t = 0; t < k; t++)
        {
            // the i'th cluster by the t'th cluster
            denominator += (interClusterDistance(cList[i], cList[t]))
                        / (interClusterEdges(cList[i], cList[t]));
        }
    }

    return numerator / denominator;
}

// creates clusters, fills cList member cluster array
// fills point array with points via pickPoints Cluster function.
// pointArray and cList are members, with dynamic memory
// so we can just close the function after they're filled
// and move on to other funcionalities of KMeans.

void KMeans::createClusters(std::ifstream & file) {

    Clustering::Cluster points_space(dimensions);

    file >> points_space;

    cList = new Cluster[k];                                // need a Cluster constructor that default builds Clusters...

    for (int i = 0; i < k - 1; i++) {
        Clustering::Cluster C(dimensions);               // should this C be dynamic???
        cList[i] = C;
        //cList[i] = Cluster(dimensions);
    }

    cList[k - 1] = points_space;

    std::cout << points_space;

                                                           // can't create an array of Points bc no default constructor. I BET
                                                           // undefined reference to `Point::Point()' when trying to make point[]
    pointsArray = new Point[k];

    for (int j = 0; j < k; j++)
    {
        pointsArray[j].setDim(dimensions);
        pointsArray[j].setCoor(dimensions);
    }

    points_space.pickPoints(k, pointsArray);



    int i = 0;

    // assign each Cluster's centroid (PointPtr) to a Point.

    while (i < points_space.getSize() && i < k)
    {
        cList[i].setCent(pointsArray[i]);
        i++;
    }

    std::cout << "points array made" << std::endl;

}// end createClusters

/*
 * clusterizeData
 * in: Cluster array cList, with centroids set
 * out: clusters filled out with adjacent points
 */
void KMeans::clusterizeData()
{
/*
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
*/
    assert(cList != nullptr && pointsArray != nullptr);






} // end clusterizeData


















