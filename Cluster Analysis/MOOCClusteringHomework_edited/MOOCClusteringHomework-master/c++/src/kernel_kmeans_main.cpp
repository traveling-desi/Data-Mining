#include "clustering/k_means.h"
#include "clustering/kernel_k_means.h"
#include "evaluation/supervised_evaluation.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;

vector< vector<double> > loadPoints(string filename)
{
    FILE* in = fopen(filename.c_str(), "r");
    int n, d;
    fscanf(in, "%d%d", &n, &d);
    vector< vector<double> > data(n, vector<double>(d, 0));
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < d; ++ j) {
            fscanf(in, "%lf", &data[i][j]);
        }
    }
    fclose(in);
    return data; 
}

vector<int> loadClusters(string filename)
{
    FILE* in = fopen(filename.c_str(), "r");
    int n;
    fscanf(in, "%d", &n);
    vector<int> clusters(n, 0);
    for (int i = 0; i < n; ++ i) {
        fscanf(in, "%d", &clusters[i]);
    }
    fclose(in);
    return clusters;
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        cout << "[usage] <data-file> <ground-truth-file>" << endl;
        exit(-1);
    }
    string dataFilename = argv[1];
    string groundtruthFilename = argv[2];

    // load data
    vector< vector<double> > data = loadPoints(dataFilename);
    vector<int> groundtruth = loadClusters(groundtruthFilename);
    
    const double SIGMA = 4;
    vector< vector<double> > kernel_data = KernelKMeans::kernel(data, SIGMA);
    vector< vector<double> > centers;
    centers.push_back(kernel_data[0]);
    centers.push_back(kernel_data[1]);
    
    vector<int> result = KMeans::kmeans(kernel_data, centers);
    
    cout << "Purity = " << SupervisedEvaluation::purity(groundtruth, result) << endl;
    cout << "NMI = " << SupervisedEvaluation::NMI(groundtruth, result) << endl;
    
    return 0;
}


