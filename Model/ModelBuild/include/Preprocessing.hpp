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
    void removeStopWords();
    void ConvertTxtgzToTxt(std::string directory);
    void ConvertTxtgzToJson();
    void ConvertJsonToTxt();
    void dividePositiveandNegative(int Positive);
    void over_rideList(std::vector<std::string> list);
    void over_rideFileType(FileType newFT);
    void saveEqualdivided();
    std::vector<std::string> &getList();

private:
    FileType FT;
    std::vector<std::string> DatasetList;
};

#endif