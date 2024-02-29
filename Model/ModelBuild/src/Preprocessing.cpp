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

void Preprocessor::Combine(FileType FileType_to_combine_to)
{
    if (FileType_to_combine_to == FileType::TXT)
    {
        if (FT == FileType::JSON)
        {
            // TODO
        }
    }
}

void Preprocessor::Combine(std::vector<std::string> list)
{
    if (DatasetList.empty())
    {
        if (!list.empty())
        {
            DatasetList = list;
        }
        else
        {
            std::cerr << "[WARN]" << std::setw(4) << ""
                      << "Both Lists are empty" << std::endl;
            return;
        }
    }
    else
    {
        // Add two vectors together
        DatasetList.insert(DatasetList.end(), list.begin(), list.end());
    }

    Combine();
    return;
}

void Preprocessor::removeStopWords()
{
    auto it = std::find(DatasetList.begin(), DatasetList.end(), "text.txt");
    if (it != DatasetList.end())
    {
        if (!removeStop(DatasetList))
        {
            std::cerr << "[WARN] " << std::setw(4) << " Could not remove stopWords\nCheck if text.txt exists, stopwords.txt exists and if the DatasetList is text.txt only " << std::endl;
        }
    }
    else
    {
        std::cout << "[WARN] " << std::setw(4) << " Can only perform this if text.txt exists" << std::endl;
        return;
    }
}

void Preprocessor::ConvertTxtgzToTxt(std::string directory)
{
    if (FT != FileType::TXTGZ)
    {
        std::cerr << "[WARN]" << std::setw(4) << "Cannot convert to TXT" << std::endl;
        return;
    }

    for (auto filename : DatasetList)
    {
        std::string outputData = {};
        if (gzTotzt::decompressGzip(filename + ".txt.gz", outputData))
        {
            removeNonFilename(filename);
            if (gzTotzt::saveToFile(directory + filename + ".txt", outputData))
            {
                std::cout << "[INFO]" << std::setw(4) << ""
                          << "Decompressed data saved to " << filename + ".txt" << std::endl;
                // change filetype
                FT = FileType::TXT;
            }
            else
            {
                std::cerr << "[WARN]" << std::setw(4) << "Error saving data" << std::endl;
            }
        }
    }
}

void Preprocessor::ConvertTxtgzToJson()
{
    if (FT != FileType::TXTGZ)
    {
        std::cerr << "[WARN]" << std::setw(4) << ""
                  << " Cannot use this to convert to json" << std::endl;
        return;
    }
    gzTojson::initializeScript(initializeScript);
    for (const auto &dataset : DatasetList)
    {
        gzTojson::convert(dataset, extractFilename(dataset));
    }
    for (auto &dataset : DatasetList)
    {
        dataset = extractFilename(dataset) + ".json";
    }
    FT = FileType::JSON;
}