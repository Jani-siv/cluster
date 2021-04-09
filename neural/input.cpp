#include "input.h"

input::input(/* args */)
{
}

input::~input()
{
}

void input::setData(long double data)
{
    this->inputData.push_back(data);
}

size_t input::getSize()
{
    return this->inputData.size();
}

long double input::getData(int cell)
{
    return this->inputData[cell];
}