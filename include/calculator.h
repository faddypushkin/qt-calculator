#pragma once

#include <string>
#include <optional>

using Number = double;

class Calculator {
public:
    void Add(Number n);
    void Sub(Number n);
    void Div(Number n);
    void Mul(Number n);
    void Pow(Number n);
    void Save();
    void Load();

    void Set(Number n) {
        res_ = n;
    }

    bool HasMem() const {
        return mem_.has_value();
    }

    Number GetNumber() const {
        return res_;
    }

    std::string GetNumberRepr() const {
        return std::to_string(res_);
    }

private:
    Number res_ = 0;
    std::optional<Number> mem_;
};
