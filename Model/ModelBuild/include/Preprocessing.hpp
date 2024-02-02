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

private:
    Json Dataset = {};
    FileType FT;
    std::vector<std::string> DatasetList;
};

#endif