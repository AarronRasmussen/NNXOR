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