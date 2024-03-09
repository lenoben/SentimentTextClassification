#include "ModelBuild.hpp"

std::tuple<std::vector<std::string>, std::vector<int>> getVectorDataset()
{
    // magic variable here
    Preprocessor rawtext = Preprocessor(FileType::TXT, {"equalhightext_combined.txt"});
    rawtext.viewList();

    int total = (int)(countLines(rawtext.getList()[0]));
    int half = total / 2;
    std::cout << "[INFO] " << std::setw(4) << " Full raw is " << total << std::endl;
    std::cout << "[INFO] " << std::setw(4) << " High and low is " << half << std::endl;

    std::vector<int> raw_score;
    for (int i = 0; i < total; i++)
    {
        if (i < half)
        {
            raw_score.push_back(1); // top is high
        }
        else
        {
            raw_score.push_back(0); // bottom is low
        }
    }
    if (raw_score.size() != total)
    {
        std::cerr << "Not same size with raw vector and string file" << std::endl;
    }
    auto rawcorpus = file_to_vector(rawtext.getList()[0], total);
    return std::make_tuple(rawcorpus, raw_score);
}
