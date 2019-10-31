#pragma once

#include <string>
#include <memory>

class ComponentImpl {
public:
    virtual std::string toSPICEString() = 0;
};

class Capacitor : public ComponentImpl
{
public:
    Capacitor(int terminalA, int terminalB, double value);

    std::string toSPICEString();

private:
    int terminalA, terminalB;
    double value;
};

class Resistor : public ComponentImpl
{
public:
    Resistor(int terminalA, int terminalB, double value);

    std::string toSPICEString();

private:
    int terminalA, terminalB;
    double value;
};

class Component
{
public:
    Component();
    ~Component();

    std::string toSPICEString();

    static Component createCapacitor(int node1, int node2, double value);
    static Component createResistor(int node1, int node2, double value);

private:
    std::shared_ptr<ComponentImpl> impl;
};

