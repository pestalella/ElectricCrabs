#include "pch.h"

#include "Component.h"
#include "utils.h"

Component::Component()
{
}


Component Component::createCapacitor(int node1, int node2, double value)
{
    Component capacitor;

    capacitor.impl = std::make_shared<Capacitor>(node1, node2, value);
    return capacitor;
}

Component Component::createResistor(int node1, int node2, double value)
{
    Component resistor;

    resistor.impl = std::make_shared<Resistor>(node1, node2, value);
    return resistor;
}

Component::~Component()
{
}

std::string Component::toSPICEString()
{
    return impl->toSPICEString();
}


Capacitor::Capacitor(int terminalA, int terminalB, double value) :
    terminalA(terminalA), terminalB(terminalB),
    value(value)
{

}

std::string Capacitor::toSPICEString()
{
    return std::string("C? ") +
        std::to_string(terminalA) + " " +
        std::to_string(terminalB) + " " +
        // value scaled to output prefix
        std::to_string(static_cast<int>(Utils::scaledToPrefix(value))) +
        Utils::valueToPrefix(value) +
        "F";  // Farads
}

Resistor::Resistor(int terminalA, int terminalB, double value) :
    terminalA(terminalA), terminalB(terminalB),
    value(value)
{
}

std::string Resistor::toSPICEString()
{
    return std::string("R? ") +
        std::to_string(terminalA) + " " +
        std::to_string(terminalB) + " " +
        // value scaled to output prefix
        std::to_string(static_cast<int>(Utils::scaledToPrefix(value))) +
        Utils::valueToPrefix(value);
}
