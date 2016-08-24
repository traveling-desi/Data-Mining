#ifndef __KMEANS_H__
#define __KMEANS_H__

#include "../utils/utils.h"

namespace KMeans
{
    #include <iostream>
    using std::cout;
    using std::endl;
    using Utils::squaredDistance;
    
    double computeSSE(const vector< vector<double> > &data, const vector< vector<double> > &centers, const vector<int> & clusterID) {
        double sse = 0;
        int n = data.size();
        for (int i = 0; i < n; ++ i) {
            int c = clusterID[i];
            sse += squaredDistance(data[i], centers[c]);
        }
        return sse;
    }

    vector<int> updateClusterID(const vector< vector<double> > &data, const vector< vector<double> > &centers) {
        vector<int> clusterID(data.size(), 0);
        // TODO assign the closet center to each data point
        // you can use the function squaredDistance defined in utils.h
        return clusterID;
    }

    vector< vector<double> > updateCenters(const vector< vector<double> > &data, const vector<int> &clusterID, int K) {
        vector< vector<double> > centers(K, vector<double>(data[0].size(), 0));
        
        // TODO recompute the centers based on current clustering assignment
        // If a cluster doesn't have any data points, in this homework, leave it to ALL 0s.
        
        return centers;
    }

    /** run kmeans a single time, with specific initialization and number of iterations
     *  vector<vector<double>> data are the points need to be clustered
     *  vector<vector<double>> centers are the initializations
     *  int maxIter is the max number of itertions for kmeans, default is 100
     *  double tol is the tolerance for stop criterion, default is 1e-6
     *  return clusterID
    **/
    vector<int> kmeans(const vector< vector<double> > &data, vector< vector<double> > centers, int maxIter = 100, double tol = 1e-6) {
        int n = data.size(); // the number of data points
        if (n == 0) {
            return vector<int>();
        }
        int k = centers.size();
        vector<int> clusterID(n, 0);
        if (k >= n) {
            for (int i = 0; i < n; ++ i) {
                clusterID[i] = i;
            }
            return clusterID;
        }
        int d = data[0].size(); // the dimension of a point
        
        double lastDistance = 1e100; // set to infinity
        for (int iter = 0; iter < maxIter; ++ iter) {
            clusterID = updateClusterID(data, centers);
            centers = updateCenters(data, clusterID, k);
            double distance = computeSSE(data, centers, clusterID);
            
            if ((lastDistance - distance) < tol || (lastDistance - distance) / lastDistance < tol) { // stop criterion
                cout << "# iterations = " << iter << endl;
                cout << "SSE = " << distance << endl;
                return clusterID;
            }
            lastDistance = distance;
        }
        cout << "# iterations = " << maxIter << endl;
        cout << "SSE = " << lastDistance << endl;
        return clusterID;
    }
};

#endif

