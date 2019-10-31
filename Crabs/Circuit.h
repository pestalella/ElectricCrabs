#pragma once

#include <string>
#include <vector>

#include "Component.h"

class Circuit
{
public:
    Circuit();
    ~Circuit();
    static Circuit generateRandomCircuit(int nodes, int numComponents);
    std::string toSPICEString();

private:
    static Component generateRandomComponent(int numNodes);

private:
    int numNodes;
    //std::vector<int> nodes;
    std::vector<Component> components;
};

