#include "network.h"

Network::Network(const std::vector<int>& n) {
    for(int i = 1; i < n.size(); i++) {
        layers.push_back(Layer(n.at(i), n.at(i - 1)));
    }
}

void Network::printNetWork() {
    std::cout << "Printing Network information: " << std::endl;

    std::for_each(layers.begin(), layers.end(), [](auto &o){
        o.printLayer();
    });
}

double Network::feedForward(double in1, double in2){
    //layer one outputs
    double l1n1netInput = in1 * this->layers[0].nodes[0].weights[0] + in2 * this->layers[0].nodes[0].weights[1] + this->layers[0].bias;
    double l1n2netInput = in1 * this->layers[0].nodes[1].weights[0] + in2 * this->layers[0].nodes[1].weights[1] + this->layers[0].bias;
    double l1n1out = this->logisticFunction(l1n1netInput);
    double l1n2out = this->logisticFunction(l1n2netInput);
   
    double l2n1netInput = l1n1out * this->layers[1].nodes[0].weights[0] + l1n2out * this->layers[1].nodes[0].weights[1] + this->layers[1].bias;
    double l2n1out = logisticFunction(l2n1netInput);

    return l2n1out;
}

double Network::logisticFunction(double netInput){
    return (1 / (1 + exp(-1 * netInput)));
}