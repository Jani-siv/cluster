#ifndef INPUT_H
#define INPUT_H
#include <vector>
class input
{
private:
    /* data */
    std::vector<double> inputData;
public:
    input(/* args */);
    ~input();
    void setData(double data);
    size_t getSize();
    double getData(int cell);
};


#endif