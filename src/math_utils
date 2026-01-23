#include "math_utils.h"
#include <cmath>
#include <iostream>
#include <random>


double sigmoid(double z)
{
    double e_power_neg_z = std::exp(-z);
    return 1.0/(1.0 + e_power_neg_z);
}

double clamp(double x, double lo, double hi)
{
    if (x < lo) return lo;
    if (x > hi) return hi;
    return x;
}

double deriv(double a)
{
    double deriv_of_neuron = a * (1.0 - a);
    return deriv_of_neuron;
}

double rand_uniform(double lo, double hi)
{
    std::mt19937 gen{std::random_device{}()};
    std::uniform_real_distribution<double> dist(lo, hi);
    return dist(gen);
}
