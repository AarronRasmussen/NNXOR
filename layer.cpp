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

void Layer::printLayer() {
    std::cout << "Number of nodes in layer: " << nodes.size() << std::endl;
    std::cout << "Bias is: " << bias << std::endl;
    std::cout << std::endl;

    std::for_each(nodes.begin(), nodes.end(), [](auto& o){
        o.printWeights();
    });
}