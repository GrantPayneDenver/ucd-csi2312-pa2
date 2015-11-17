//
// Created by Folio on 10/17/2015.
//
/*
#include <cassert>
#include <limits>
#include <cmath>

#include "KMeans.h"
using namespace Clustering;

static int line = 0;

// notes outer cluster number
void kmeansLogOuter(std::fstream &file, int outer)
{
    line++;
    file << line << ":OUTER CYCLE*****Working on outer Cluster " << outer << std::endl;
}

void kmeansLogInner(std::fstream &file, int inner)
{
    file << ++line << ":";
    file << "Working on inner Cluster " << inner << std::endl;
}

//***note count, as well as iterate-> in log
void kmeansLogOuterP(std::fstream &file, int count, Point& p)
{
    file << ++line << ":";
    file <<"Working on outer Cluster's Point " << p << "at count " << count << std::endl;
}

void kmeansLogMovePerform(std::fstream &file, Point &p, int outer, int inner)
{
    file << ++line << ":";
    file <<"Moving point " << p << " from outer cluster " << outer << " to inner cluster " << inner << std::endl;

}

void kmeansReport(std::fstream &file, Clustering::Cluster* list, int k)
{
    file << "CLUSTER REPORT" << std::endl;

    for (int i = 0; i < k; i++)
    {

        file << list[i];
    }
}

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
    double denominator = 0;   // quotient of (sum of intre clust dist) over (# of inter cluster edges)

    for(int i = 0; i < k; i ++)  // for all k clusters...
    {
        numerator += cList[i].intraClusterDistance() / cList[i].getClusterEdges();

        for (int t = 0; t < k; t++)
        {
            if(i != t)
            {
                // the i'th cluster by the t'th cluster
                denominator += (interClusterDistance(cList[i], cList[t]))
                               / (interClusterEdges(cList[i], cList[t]));
            }
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

    std::cout << points_space;


    cList = new Cluster[k];                                // need a Cluster constructor that default builds Clusters...
    cList[0] = points_space;

    for (int i = 1; i < k; i++) {
        Clustering::Cluster C(dimensions);               // should this C be dynamic???
        cList[i] = C;
        //cList[i] = Cluster(dimensions);
    }

    //cList[k - 1] = points_space;

    std::cout << points_space;

                                                           // can't create an array of Points bc no default constructor. I BET
                                                           // undefined reference to `Point::Point()' when trying to make point[]
    pointsArray = new Point[k];
    //std::vector<Point> pointsArray(k);

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


void KMeans::clusterizeData()
{

    assert(cList != nullptr);
// have points array
// have cList with centroids
    //need a max number,
    // old score = max number
    //scoreDiff = SCOREDIFFTHRESHOLD + 1

    //open kLog

/*



    std::fstream Klog;
    Klog.open("C:\\Users\\Folio\\Desktop\\School\\intPA2\\ucd-csi2312-pa2\\klog.csv");
    Klog.clear();

    double scoreDiff = SCORE_DIFF_THRESHOLD + 1;
    double highPoint = std::numeric_limits<double>::max();        // find out full path so I don't need to #include <limits>
    scoreDiff = highPoint;
    double prevScore=0;
    double newScore=0;

    while (scoreDiff > SCORE_DIFF_THRESHOLD) // score diff should get smaller..
    {
        for(int outerCluster = 0; outerCluster < k; outerCluster++)
        {
            // ***note outer cluster in log
            //kmeansLogOuter(Klog, outerCluster);

            //LNodePtr iterate = cList[outerCluster].getPoints();              // set iterate to head of outerCluster
            //int index = 0;
            int count = 0;

            while(count < cList[outerCluster].getSize())
            {
                //note count, as well as iterate->p in log

                kmeansLogOuterP(Klog, count, *cList[outerCluster].operator[](count)->p);

                // compare each each point of outerCluster to each centroid of inner clusters.
                for (int innerCluster = 0; innerCluster < k; innerCluster++)
                {
                    //***note innerCluster in log
                    //kmeansLogInner(Klog, innerCluster);
                    //Klog << cList[innerCluster];

                    // if point from iterate is farther from outerCLuster centroid than innerCluster centroid
                    // move point to innerCluster

                        Point innerCent(*cList[innerCluster].getCentroid());      // innerCent Point, from innerCluster Centroid
                        Point outerCent(*cList[outerCluster].getCentroid());      // outerCent Point, from outerCluster Centroid
                        Point iteratePoint(*cList[outerCluster].operator[](count)->p);                          // iterate Point,   from *iterate->p Point

                        if (iteratePoint.distanceTo(innerCent) < iteratePoint.distanceTo(outerCent)) {

                            //move iteratePoint from outerCluster to innerCluster
                            //void Cluster::Move::perform(const PointPtr &pt, Cluster *to, Cluster *from)
                            //***void kmeansLogMovePerform(std::fstream &file, Point &p, int outer, int inner)

                            PointPtr ptr = &iteratePoint;

                            std::cout <<"moving point: " << *cList[outerCluster].operator[](count)->p <<std::endl;

                            kmeansLogMovePerform(Klog, *ptr, outerCluster, innerCluster);
                            Cluster::Move m;

                            m.perform(ptr, &cList[innerCluster], &cList[outerCluster]);

                            //cList[outerCluster].remove(ptr);

                            break;
                        }


                }//(int innerCluster = 0; innerCluster < k; innerCluster++)

                //iterate->p = iterate->next->p;
                //iterate = iterate->next;
                count++;



            }//while(iterate && count < cList[outerCluster].getSize()

        }// for(int outerCluster = 0; outerCluster < k; outerCluster++)

        for(int clust = 0; clust < k; clust++)
        {
            if(!cList[clust].getCentValid())
            {
                cList[clust].calcCent();
            }
        }

        newScore = this->computeClusteringScore();
        scoreDiff = std::abs(prevScore - newScore);// prevScore started at uber high number
        prevScore = newScore;

    } // while scoreDiff > threshold

    kmeansReport(Klog, cList, k);

    Klog.close();



} // end clusterizeData

void KMeans::printClusters()
{
    for (int i = 0; i < k; i++)
    {
        std::cout << ++line << cList[i];
    }
}


*/










