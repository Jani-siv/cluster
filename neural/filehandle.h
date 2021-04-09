#ifndef FILEHANDLE_H
#define FILEHANDLE_H
#include "strings.h"
#include <iostream>
#include <vector>

class filehandle
{
private:
    std::string directory ="saved/";
    std::string filename = "";

    /* data */
public:
    filehandle(/* args */);
    ~filehandle();
    void openFile();
    void saveCurrentToFile(std::vector<std::vector<double>> *layer);
    void setAnswers();
    void loadWeightsFromFile();

};

#endif