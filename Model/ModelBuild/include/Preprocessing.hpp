#ifndef MODEL_BUILD_PREPROCESSING_HPP
#define MODEL_BUILD_PREPROCESSING_HPP

#include "SATC.hpp"

class Preprocessor
{
public:
    Preprocessor();
    Preprocessor(FileType FT);
    Preprocessor(FileType FT, std::vector<std::string> &List);
    void printType();
    void addList(std::vector<std::string> List);
    void viewList();
    void Combine();
    void Combine(FileType FT);
    void Combine(std::vector<std::string> List);

private:
    Json Dataset = {};
    FileType FT;
    std::vector<std::string> DatasetList;
};

#endif