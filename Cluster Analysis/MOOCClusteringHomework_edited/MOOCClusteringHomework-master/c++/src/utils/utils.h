#ifndef __UTILS_H__
#define __UTILS_H__

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

namespace Utils
{
    double sqr(double x)
    {
        return x * x;
    }

    double squaredDistance(const vector<double> &a, const vector<double> &b)
    {
        double sum = 0;
        for (int i = 0; i < a.size(); ++ i) {
            sum += sqr(a[i] - b[i]);
        }
        return sum;
    }
};

#endif
