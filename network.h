#include "layer.h"
#include <iterator>
#include <algorithm>

class Network {
    public:
    std::vector<Layer> layers;
    Network(const std::vector<int>& n);
};