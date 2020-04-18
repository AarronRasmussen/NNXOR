#include "layer.h"

Layer::Layer(int length, int numWeights) {
        std::random_device rd;
    std::mt19937 n(rd());

    std::uniform_real_distribution<double> dist(0,1);
    bias = dist(n);

    for(int i = 0; i < length; i++) {
        nodes.push_back(Node(numWeights));
    }
}