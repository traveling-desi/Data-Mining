# Programming Assignment - C++ version

####Dependencies:####

* g++
* linux (recommended) or windows (you may not be able to apply the make commands, but you can use your own IDE, such as Visual Studio and Code Blocks.)

####Goals####

* Implement the following clustering algorithms: K-means and Kernel K-means.
* Implement the following supervised clustering evaluation metrics: purity and NMI.

####Step 1. K-means####

* Complete the following two key functions of K-means in src/clustering/k_means.h
```
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
```

* Write the purity and NMI metrics in src/evaluation/supervised_evaluation.h
```
    double purity(const vector<int> &groundtruthAssignment, const vector<int> &algorithmAssignment) {
        // compute the purity
        return 0.0;
    }
    
    double NMI(const vector<int> &groundtruthAssignment, const vector<int> &algorithmAssignment) {
        // compute the NMI
        return 0.0;
    }
```

* Compile via Makefile, and then run the executable file.
```
make
./kmeans_tester ../data/self_test.data ../data/self_test.ground
```

* If your implementation is correct, you should have information printed on your screen that is very similar to the information given below.
```
# iterations = 11
SSE = 24189.1
Purity = 0.666667
NMI = 0.0848238
```

####Step 2. Kernel K-means####

* Once you have done K-means, you only need to implement a wrapper to transform the data points into the kernel space for kernel K-means. In this homework, we are going to implement the RBF kernel. Please complete the following coordinates transformation function.
```
    vector< vector<double> > kernel(const vector< vector<double> > &data, double sigma) {
        // TODO transform the data points to kernel space
        // here we are going to implement RBF kernel, K(x_i, x_j) = e^{\frac{-|x_i - x_j|^2}{2 \sigma^2}}
        return data;
    }
```

* Compile via Makefile, and then run the executable file.
```
make
./kernel_kmeans_tester ../data/self_test.data ../data/self_test.ground
```

* If your implementation is correct, you should have information printed on your screen that is very similar to the information given below.
```
# iterations = 3
SSE = 2991.54
Purity = 0.996667
NMI = 0.968781
```

