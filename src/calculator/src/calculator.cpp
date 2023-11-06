#include "../header/tourism.h"
#include <stdexcept>

using namespace Coruh::Tourism;

double Tourism::add(double a, double b) {
    return a + b;
}

double Tourism::subtract(double a, double b) {
    return a - b;
}

double Tourism::multiply(double a, double b) {
    return a * b;
}

double Tourism::divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    return a / b;
}