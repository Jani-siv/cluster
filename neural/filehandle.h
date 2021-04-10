#ifndef FILEHANDLE_H
#define FILEHANDLE_H
#include "strings.h"
#include <iostream>
#include <vector>
#include <fstream>

class filehandle
{
private:
    std::string directory ="saved/";
    std::string filename = "";
    int error;

    /* data */
public:
    filehandle(/* args */);
    ~filehandle();
    int openFile(std::string filename);
    void saveCurrentToFile(std::vector<std::vector<double>> *layer);
    std::vector<double> setAnswers(std::string filename);
    void loadWeightsFromFile();

};

#endif