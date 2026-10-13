#pragma once

#include <string>

using Number = double;

class Calculator{
public:
    void Set(Number n);
    Number GetNumber() const;
    void Add(Number n);
    void Sub(Number n);
    void Div(Number n);
    void Mul(Number n);
    void Pow(Number n);
    void Save(Number n);
    void Clear();
    Number Load() const;
    bool HasMem() const;
    std::string GetNumberRepr() const;
private:
    Number x_ = 0;
    bool has_mem_ = false;
    Number save_ = 0;
};
