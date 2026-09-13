#include <cmath>

#include "calculator.h"

using namespace std;

void Calculator::Add(Number num) {
    res_ += num;
}

void Calculator::Sub(Number num) {
    res_ -= num;
}

void Calculator::Div(Number num) {
    res_ /= num;
}

void Calculator::Mul(Number num) {
    res_ *= num;
}

void Calculator::Pow(Number num) {
    res_ = pow(res_, num);
}

void Calculator::Save() {
    mem_ = res_;
}

void Calculator::Load() {
    res_ = mem_.value();
}
