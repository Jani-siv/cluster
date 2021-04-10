#ifndef INPUT_H
#define INPUT_H
#include <vector>
class input
{
private:
    /* data */
    std::vector<long double> inputData;
public:
    input(/* args */);
    ~input();
    void setData(long double data);
    size_t getSize();
    long double getData(int cell);
};


#endif