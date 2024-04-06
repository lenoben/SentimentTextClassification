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

#define LETTER(ch) (isupper(ch) || islower(ch)) s

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

#endif