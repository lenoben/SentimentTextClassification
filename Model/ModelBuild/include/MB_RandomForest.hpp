#ifndef MODEL_BUILD_MB_RANDOM_FOREST_HPP
#define MODEL_BUILD_MB_RANDOM_FOREST_HPP

#include "ModelBuild.hpp"

// RANDOM FOREST
#include <mlpack/methods/random_forest/random_forest.hpp>

namespace mb
{
    double randomForestSetup(EncoderType ET, scaler_methods SM = scaler_methods::NONE, int numClasses = 2, int numTrees = 0);
};

#endif