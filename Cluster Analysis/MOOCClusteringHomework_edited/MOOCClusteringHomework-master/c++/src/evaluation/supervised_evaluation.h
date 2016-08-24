#ifndef __SUPERVISED_EVALUTION_H__
#define __SUPERVISED_EVALUTION_H__

#include "../utils/utils.h"

namespace SupervisedEvaluation
{
    using std::vector;
    
    double purity(const vector<int> &groundtruthAssignment, const vector<int> &algorithmAssignment) {
        // compute the purity
        return 0.0;
    }
    
    double NMI(const vector<int> &groundtruthAssignment, const vector<int> &algorithmAssignment) {
        // compute the NMI
        return 0.0;
    }
};

#endif
