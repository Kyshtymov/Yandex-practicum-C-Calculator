#include "calculator.h"

#include <cassert>
#include <cmath>
#include <string>



void Calculator::Set(Number n){
    x_ = n;
}

Number Calculator::GetNumber() const{
    return x_;
}

void Calculator::Add(Number n){
    x_ += n;
}

void Calculator::Sub(Number n){
    x_ -= n;
}

void Calculator::Div(Number n){
    x_ /= n;
}

void Calculator::Mul(Number n){
    x_ *= n;
}

void Calculator::Pow(Number n){
    x_ = pow(x_, n);
}

void Calculator::Save(Number n){
    save_ = n;
    has_mem_ = true;
}

Number Calculator::Load() const{
    return save_;
}

void Calculator::Clear(){
    save_ = 0;
    has_mem_ = false;
}

bool Calculator::HasMem() const{
    return has_mem_;
}

std::string Calculator::GetNumberRepr() const{
    return std::to_string(x_);
}
