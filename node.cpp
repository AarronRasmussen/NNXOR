#include "node.h"

Node::Node(int numWeights) {
    std::random_device rd;
    std::mt19937 n(rd());

    std::uniform_real_distribution<double> dist(0,1);

    for(int i = 0; i < numWeights; i++) {
        weights.push_back(dist(n));
    }
}

void Node::printWeights() {
    std::copy(weights.begin(), weights.end(), std::ostream_iterator<double>(std::cout, ""));
    std::cout << std::endl;
}