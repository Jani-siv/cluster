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
    std::vector<std::vector<double>> answers;
    std::ifstream currentfile;
    std::ofstream savefile;
    int error;

    /* data */
public:
    filehandle(/* args */);
    ~filehandle();
    int openFile(std::string filename);
    int createFile(std::string filename);
    int saveFileAppend(std::string filename);
    void setAnswers(std::string filename);
    void loadWeightsFromFile();
    void saveWeightsToFile(std::vector<long double> input, int layer,int node,double bias,std::string filename);
    std::vector<double>getAnswers(int place);
    int getAnswersSize();

};

#endif