#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <random>

class Node {
    public:
    std::vector<double> weights;
    Node(int numWeights);
    void printWeights();
};