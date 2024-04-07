#ifndef MODEL_BUILD_STEMMER_HPP
#define MODEL_BUILD_STEMMER_HPP

#include "ModelBuild.hpp"

#include "porter_stemmer.h"
#include <stdio.h>
#include <stdlib.h> /* for malloc, free, realloc */
#include <ctype.h>  /* for isupper, islower, tolower */

// Static members
static char *s;
static int i_max = 50; /* maximum offset in s */

#define LETTER(ch) (isupper(ch) || islower(ch))

/**
 * @brief a class for handling porter stemmer
 *
 */
class stemm
{
private:
    struct stemmer *z;
    const int INC = 50; /* size units in which s is increased */
    void processLines(std::vector<std::string> &lines, std::vector<std::string> &result);

public:
    stemm(/* args */);
    ~stemm();
    std::string stemWord(std::string &str);
    void stemfile(std::string inputFile, std::string outputFile);
};

void stemm::processLines(std::vector<std::string> &lines, std::vector<std::string> &result)
{
    stemm s;
    for (const auto &line : lines)
    {
        std::stringstream ss(line);
        std::string word;
        std::string stemmedLine;
        while (ss >> word)
        {
            stemmedLine += s.stemWord(word) + " ";
        }
        result.push_back(stemmedLine);
    }
}

stemm::stemm(/* args */)
{
    z = create_stemmer();
    s = (char *)malloc(i_max + 1);
}

stemm::~stemm()
{
    free(s);
    free_stemmer(z);
}

#endif