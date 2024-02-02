#ifndef SATC_HPP
#define SATC_HPP

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

#include <filesystem>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <typeinfo>

#include <stdexcept>
#include <array>
#include <cstdlib>

#include <zlib.h>

#include "json.hpp"

using Json = nlohmann::json;
enum FileType
{
    TXTGZ,
    JSON,
    TXT
};

#endif