#include "Preprocessing.hpp"
#include <iomanip>

Preprocessor::Preprocessor() : DatasetList({}){};

Preprocessor::Preprocessor(FileType FT) : FT(FT), DatasetList({}){};

Preprocessor::Preprocessor(FileType FT, std::vector<std::string> &List) : FT(FT), DatasetList(List){};

void Preprocessor::printType()
{
    switch (FT)
    {
    case TXT:
        std::cout << "[INFO]" << std::setw(4) << ""
                  << "TXT FileType" << std::endl;
        return;
    case TXTGZ:
        std::cout << "[INFO]" << std::setw(4) << ""
                  << "TXTGZ FileType" << std::endl;
        return;
    case JSON:
        std::cout << "[INFO]" << std::setw(4) << ""
                  << "JSON FileType" << std::endl;
        return;
    default:
        std::cerr << "[INFO]" << std::setw(4) << ""
                  << "NO FileType" << std::endl;
        return;
    }
}

void Preprocessor::addList(std::vector<std::string> List)
{
    if (List.empty())
    {
        std::cerr << "[WARN]" << std::setw(4) << "Empty List" << std::endl;
        return;
    }
    DatasetList = List;
    return;
}

void Preprocessor::viewList()
{
    if (DatasetList.empty())
    {
        std::cout << "[INFO]" << std::setw(4) << "List Empty" << std::endl;
        return;
    }
    size_t count = 0;
    for (const auto &List : DatasetList)
    {
        std::cout << "[INFO]" << std::setw(4) << "[" << count << "]" << std::setw(4) << "" << List << std::endl;
        count++;
    }
    return;
}

void Preprocessor::Combine()
{
    if (FT == FileType::TXTGZ)
    {
        std::cerr << "[WARN] " << std::setw(4) << ""
                  << "No implementation for TXTGZ to combine!\nConvert to Json/Txt before combining" << std::endl;
        return;
    }
    if (FT == FileType::JSON)
    {
        if (DatasetList.empty())
        {
            std::cerr << "[WARN]" << std::setw(4) << "No Lists of [<filename>].json available" << std::endl;
            return;
        }
        combineJsonLineByLine(DatasetList);
        return;
    }
    if (FT == FileType::TXT)
    {
        if (DatasetList.empty())
        {
            std::cerr << "[WARN]" << std::setw(4) << "No Lists of [<filename>].txt available" << std::endl;
            return;
        }
        if (DatasetList.size() == 2)
        {
            if (DatasetList[0] == "hightext.txt" || DatasetList[0] == "equalhightext.txt" || DatasetList[0] == "train_equalhightext.txt" || DatasetList[0] == "test_equalhightext.txt")
            {
                combineTXT(DatasetList);
                std::cout << "[INFO] " << std::setw(4) << "Combined - " << DatasetList[0] << std::endl;
            }
        }
        // TODO
        return;
    }
    std::cout << "[WARN]" << std::setw(4) << ""
              << "Invalid!" << std::endl;
    return;
}