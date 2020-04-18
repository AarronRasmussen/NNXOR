#include "network.h"

Network::Network(const std::vector<int>& n) {
    auto iter = n.begin() + 1;

    std::for_each(n.begin(), n.end(), [&](int num){
        layers.push_back(Layer(num, *iter));
        iter++;
    });
}