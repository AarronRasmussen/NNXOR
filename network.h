#include "layer.h"
#include <iterator>
#include <algorithm>

class Network {
    public:
    
    std::vector<Layer> layers;
    double feedForwardOutput;

    Network(const std::vector<int>& n);
    void printNetWork();
    void feedForward(double in1, double in2);
    double logisticFunction(double netInput);
};