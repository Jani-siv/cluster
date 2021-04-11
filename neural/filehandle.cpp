#include "filehandle.h"

filehandle::filehandle(/* args */)
{
}

filehandle::~filehandle()
{
    this->currentfile.close();
}

int filehandle::openFile(std::string filename)
{
this->currentfile.open(this->directory+filename,std::ios::in);
if (!this->currentfile)
{
    std::cout<<"error cannot open file"<<this->directory+filename<<std::endl;
    return -1;
}
else {
    std::cout<<"file opened for reading"<<std::endl;
    return 0;
}
return -2;
//open file
}
int filehandle::createFile(std::string filename)
{
    this->savefile.open(this->directory+filename,std::ios::out);
if (!this->savefile)
{
    std::cout<<"error cannot open file"<<this->directory+filename<<std::endl;
    return -1;
}
else {
    std::cout<<"file created"<<std::endl;
    return 0;
}
return -2;
//open file
}

int filehandle::saveFileAppend(std::string filename)
{
        this->savefile.open(this->directory+filename,std::ios::app);
if (!this->savefile)
{
    std::cout<<"error cannot open file"<<this->directory+filename<<std::endl;
    return -1;
}
else {
    std::cout<<"file opened for append mode"<<std::endl;
    return 0;
}
return -2;
}

void filehandle::loadWeightsFromFile()
{
    //load saved
}
void filehandle::setAnswers(std::string filename)
{
    //test file
    this->error = this->openFile(filename);
    if (this->error == 0)
    {
        std::string output;
        while (getline (this->currentfile, output))
        {
            std::vector<double> oneTraining;
            std::stringstream templine (output);
                while(getline (templine,output,','))
                {
                    double tempVariable = std::atof(output.c_str());        
                    oneTraining.push_back(tempVariable);
                }
        this->answers.push_back(oneTraining);
        }
    }
    this->currentfile.close();
}
int filehandle::getAnswersSize()
{
    return this->answers.size();
}

std::vector<double> filehandle::getAnswers(int place)
{
    return this->answers[place];
}

void filehandle::saveWeightsToFile(std::vector<long double> input, int layer,int node,double bias, std::string filename)
{
    //layer numebr, node numebr, bias of node, weights
    //test if file already is written
    this->error = 0;
    this->error = this->openFile(filename);
    this->currentfile.close();
    if (this->error == -1)
    {
        this->error = this->createFile(filename);
        this->savefile.close();
    }
    if (this->error == 0)
    {
    this->error = this->saveFileAppend(filename);
    if (this->error == 0)
    {
        std::stringstream ss;
        ss << layer;
        ss << ",";
        ss << node;
        ss << ",";
        ss << bias;
        for (int i = 0; i < input.size(); i++)
        {
        ss << ",";
        ss << input[i];
        std::string temp = ss.str();
        this->savefile << temp;
        }
        std::string endline = "\n";
        this->savefile << endline;
    }
    this->savefile.close();
    }
}


