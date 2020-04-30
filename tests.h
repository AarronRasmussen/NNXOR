#pragma once
#include "network.h"
#include <assert.h>
#include <algorithm>
#include <iterator>

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

    std::random_device rd;
    std::mt19937 nrd(rd());

    std::uniform_real_distribution<double> dist(0,3);

    std::vector<double> input{1.0,1.0,0.0,0,0};

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

for(int i = 0; i < 100; i++) {

    double in1 = input.at(dist(nrd));
    double in2 = input.at(dist(nrd));
    double target = int(in1) ^ int(in2);

    double output = net.feedForward(in1, in2);

    net.backPropagate(target);

    /*
        h0w0: .2931
        h0w1: .6931

        h1w0: .3984
        h1w2: .1984

        o0w0: .4445
        o0w1: .0506
    */
    //    std::copy(net.deltaOutput.begin(), net.deltaOutput.end(), std::ostream_iterator<double>(std::cout, " "));

   net.updateWeights();
}

    // std::cout << "The updated weights are: " << std::endl;
    // std::cout << "h0w0: " << net.layers[0].nodes[0].weights[0] << std::endl;
    // std::cout << "h0w1: " << net.layers[0].nodes[0].weights[1] << std::endl;

    // std::cout << "h1w0: " << net.layers[0].nodes[1].weights[0] << std::endl;
    // std::cout << "h1w1: " << net.layers[0].nodes[1].weights[1] << std::endl;

    // std::cout << "h0w0: " << net.layers[1].nodes[0].weights[0] << std::endl;
    // std::cout << "h0w1: " << net.layers[1].nodes[0].weights[1] << std::endl;
}