#pragma once
#include "node.h"
#include <vector>
#include <random>

class Layer {
    public:
    double bias;
    std::vector<Node> nodes;
    Layer(int length, int numWeights);
    void printLayer();
};