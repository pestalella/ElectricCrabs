#include "pch.h"
#include "Circuit.h"
#include "utils.h"

Circuit::Circuit()
{

}


Circuit::~Circuit()
{
}

Circuit Circuit::generateRandomCircuit(int nodes, int numComponents)
{
    Circuit cir;
    cir.numNodes = nodes;
    for (int i = 0; i < numComponents; ++i) {
        cir.components.push_back(generateRandomComponent(nodes));
    }
    return cir;
}

std::string Circuit::toSPICEString()
{
    std::string result;
    for (auto comp : components) {
        result += comp.toSPICEString() + "\n";
    }
    return result;
}

Component Circuit::generateRandomComponent(int numNodes)
{
    auto node1 = rand() % numNodes;
    auto node2 = rand() % numNodes;

    switch (rand()%2) {
    case 0:
        return Component::createCapacitor(node1, node2, Utils::randomCapacitorValue());
    case 1:
        return Component::createResistor(node1, node2, Utils::randomResistorValue());
    }
    return Component();
}
