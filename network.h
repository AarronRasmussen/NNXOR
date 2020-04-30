#pragma once
#include "layer.h"
#include <iterator>
#include <algorithm>

class Network {
    public:
    
    std::vector<Layer> layers;

    std::vector<double> feedForwardOutput;
    std::vector<double> deltaOutput;

    double learningRate = 0.5;

    Network(const std::vector<int>& n);
    void printNetWork();
    double feedForward(double in1, double in2);
    void backPropagate(double target);
    void updateWeights();
    double logisticFunction(double netInput);
};