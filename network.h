#pragma once
#include "layer.h"
#include <iterator>
#include <algorithm>

class Network {
    public:
    
    std::vector<Layer> layers;
    std::vector<double> feedForwardOutput;
    double learningRate = 0.1;

    Network(const std::vector<int>& n);
    void printNetWork();
    double feedForward(double in1, double in2);
    double backPropagate();
    double logisticFunction(double netInput);
};