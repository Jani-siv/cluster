#ifndef FILEHANDLE_H
#define FILEHANDLE_H
#include "strings.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <sstream>

class filehandle
{
private:
    std::string directory ="saved/";
    std::string filename = "";
    std::vector<std::vector<double>> answers;
    std::ifstream currentfile;
    int error;

    /* data */
public:
    filehandle(/* args */);
    ~filehandle();
    int openFile(std::string filename);
    void saveCurrentToFile(std::vector<std::vector<double>> *layer);
    void setAnswers(std::string filename);
    void loadWeightsFromFile();
    std::vector<double>getAnswers(int place);
    int getAnswersSize();

};

#endif