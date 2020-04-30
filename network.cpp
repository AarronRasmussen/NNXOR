#include "network.h"
#include <cmath>

Network::Network(const std::vector<int>& n) {
    for(int i = 1; i < n.size(); i++) {
        layers.push_back(Layer(n.at(i), n.at(i - 1)));
    }
    this->feedForwardOutput = std::vector(5, 0.0);
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

    this->feedForwardOutput[0] = in1;
    this->feedForwardOutput[1] = in2;
    this->feedForwardOutput[2] = l1n1out; //.7503
    this->feedForwardOutput[3] = l1n2out; //.6682
    this->feedForwardOutput[4] = l2n1out; //.6774
    return l2n1out;
}

void Network::backPropagate(double target) {    
    std::cout << "Total Error: " << (0.5 * pow(target - feedForwardOutput.at(4), 2)) << std::endl;
    
    deltaOutput.push_back(-(target - feedForwardOutput.at(4)) * (feedForwardOutput.at(4) * (1 - feedForwardOutput.at(4))) * (feedForwardOutput.at(2)));
    deltaOutput.push_back(-(target - feedForwardOutput.at(4)) * (feedForwardOutput.at(4) * (1 - feedForwardOutput.at(4))) * (feedForwardOutput.at(3)));

    deltaOutput.push_back(-(target - feedForwardOutput.at(4)) * (feedForwardOutput.at(4) * (1 - feedForwardOutput.at(4))) * layers.at(1).nodes.at(0).weights.at(0) * (feedForwardOutput.at(2) * (1.0 - feedForwardOutput.at(2))) * feedForwardOutput.at(0));
    deltaOutput.push_back(-(target - feedForwardOutput.at(4)) * (feedForwardOutput.at(4) * (1 - feedForwardOutput.at(4))) * layers.at(1).nodes.at(0).weights.at(0) * (feedForwardOutput.at(2) * (1.0 - feedForwardOutput.at(2))) * feedForwardOutput.at(1));

    deltaOutput.push_back(-(target - feedForwardOutput.at(4)) * (feedForwardOutput.at(4) * (1 - feedForwardOutput.at(4))) * layers.at(1).nodes.at(0).weights.at(1) * (feedForwardOutput.at(3) * (1.0 - feedForwardOutput.at(3))) * feedForwardOutput.at(0));
    deltaOutput.push_back(-(target - feedForwardOutput.at(4)) * (feedForwardOutput.at(4) * (1 - feedForwardOutput.at(4))) * layers.at(1).nodes.at(0).weights.at(1) * (feedForwardOutput.at(3) * (1.0 - feedForwardOutput.at(3))) * feedForwardOutput.at(1));

    // std::cout << -(target - feedForwardOutput.at(4)) * (feedForwardOutput.at(4) * (1 - feedForwardOutput.at(4))) * (feedForwardOutput.at(2)) << std::endl;
    // std::cout << -(target - feedForwardOutput.at(4)) * (feedForwardOutput.at(4) * (1 - feedForwardOutput.at(4))) * (feedForwardOutput.at(3)) << std::endl;

    // std::cout << -(target - feedForwardOutput.at(4)) * (feedForwardOutput.at(4) * (1 - feedForwardOutput.at(4))) * layers.at(1).nodes.at(0).weights.at(0) * (feedForwardOutput.at(2) * (1.0 - feedForwardOutput.at(2))) * feedForwardOutput.at(0) << std::endl;
    // std::cout << -(target - feedForwardOutput.at(4)) * (feedForwardOutput.at(4) * (1 - feedForwardOutput.at(4))) * layers.at(1).nodes.at(0).weights.at(0) * (feedForwardOutput.at(2) * (1.0 - feedForwardOutput.at(2))) * feedForwardOutput.at(1) << std::endl;

    // std::cout << -(target - feedForwardOutput.at(4)) * (feedForwardOutput.at(4) * (1 - feedForwardOutput.at(4))) * layers.at(1).nodes.at(0).weights.at(1) * (feedForwardOutput.at(3) * (1.0 - feedForwardOutput.at(3))) * feedForwardOutput.at(0) << std::endl;
    // std::cout << -(target - feedForwardOutput.at(4)) * (feedForwardOutput.at(4) * (1 - feedForwardOutput.at(4))) * layers.at(1).nodes.at(0).weights.at(1) * (feedForwardOutput.at(3) * (1.0 - feedForwardOutput.at(3))) * feedForwardOutput.at(1) << std::endl;

}

double Network::logisticFunction(double netInput){
    return (1 / (1 + exp(-1 * netInput)));
}

void Network::updateWeights() {
    layers.at(1).nodes.at(0).weights.at(0) = (layers.at(1).nodes.at(0).weights.at(0) -  (learningRate * deltaOutput.at(0)));
    layers.at(1).nodes.at(0).weights.at(1) = (layers.at(1).nodes.at(0).weights.at(1) -  (learningRate * deltaOutput.at(1)));

    layers.at(0).nodes.at(0).weights.at(0) = (layers.at(0).nodes.at(0).weights.at(0) - (learningRate * deltaOutput.at(2)));
    layers.at(0).nodes.at(0).weights.at(1) = (layers.at(0).nodes.at(0).weights.at(1) - (learningRate * deltaOutput.at(3)));

    layers.at(0).nodes.at(1).weights.at(0) = (layers.at(0).nodes.at(1).weights.at(0) - (learningRate * deltaOutput.at(4)));
    layers.at(0).nodes.at(1).weights.at(1) = (layers.at(0).nodes.at(1).weights.at(1) - (learningRate * deltaOutput.at(5)));

}