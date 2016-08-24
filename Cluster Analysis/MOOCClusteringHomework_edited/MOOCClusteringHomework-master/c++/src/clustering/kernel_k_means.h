#ifndef __KERNEL_KMEANS_H__
#define __KERNEL_KMEANS_H__

#include "../utils/utils.h"

namespace KernelKMeans
{
    using Utils::squaredDistance;

    vector< vector<double> > kernel(const vector< vector<double> > &data, double sigma) {
        // TODO transform the data points to kernel space
        // here we are going to implement RBF kernel, K(x_i, x_j) = e^{\frac{-|x_i - x_j|^2}{2 \sigma^2}}
        return data;
    }
};

#endif

