#pragma once
#include "network.h"
#include <assert.h>

void testFeedForward(){
    //setup network
    //network specs
    std::vector<int> n{2,2,1};
    //test inputs
    Network net(n);

    net.layers[0].bias = 0.1;
    net.layers[0].nodes[0].weights[0] = 0.3;
    net.layers[0].nodes[0].weights[1] = 0.7;
    net.layers[0].nodes[1].weights[0] = 0.4;
    net.layers[0].nodes[1].weights[1] = 0.2;
    
    net.layers[1].bias = 0.3;
    net.layers[1].nodes[0].weights[0] = 0.5;
    net.layers[1].nodes[0].weights[1] = 0.1;

    double outPut = net.feedForward(1.0, 1.0);
    std::cout << "Feed forward returned: " << outPut << std::endl;

    assert(outPut < 1.0);
    assert(outPut > 0.0);
    
}

void testBackProp(){
    //setup network
    //network specs
    std::vector<int> n{2,2,1};
    //test inputs
    Network net(n);

    net.layers[0].bias = 0.1;
    net.layers[0].nodes[0].weights[0] = 0.3;
    net.layers[0].nodes[0].weights[1] = 0.7;
    net.layers[0].nodes[1].weights[0] = 0.4;
    net.layers[0].nodes[1].weights[1] = 0.2;
    
    net.layers[1].bias = 0.3;
    net.layers[1].nodes[0].weights[0] = 0.5;
    net.layers[1].nodes[0].weights[1] = 0.1;
    double outPut = net.feedForward(1.0, 1.0);
    std::cout << "Feed forward returned: " << outPut << std::endl;
}