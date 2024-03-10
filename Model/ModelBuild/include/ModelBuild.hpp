#ifndef MODEL_BUILD_HPP
#define MODEL_BUILD_HPP

/// Define these to print extra informational output and warnings.
#define MLPACK_PRINT_INFO
#define MLPACK_PRINT_WARN
#define MLPACK_ENABLE_ANN_SERIALIZATION

#include "ModelFlow.hpp"
#include "Preprocessing.hpp"
#include "StringManipulation.hpp"
#include <mlpack/core/data/load.hpp>
#include <mlpack/core/data/tokenizers/char_extract.hpp>
#include "mlpack/core/data/tokenizers/split_by_any_of.hpp"
#include <mlpack/core/data/string_encoding_policies/bag_of_words_encoding_policy.hpp>
#include <mlpack/core/data/string_encoding_policies/tf_idf_encoding_policy.hpp>
#include <mlpack/core/data/save.hpp>

#include <armadillo>

std::tuple<std::vector<std::string>, std::vector<int>> getVectorDataset();

std::tuple<std::vector<std::string>, std::vector<int>> getVectorDatasetFromFile(std::string filename);

arma::mat convertVectorStringToMatrix(std::vector<std::string> &vector_of_strings, EncoderType ET, TheTokenType TTT, bool saveEncoder = true, mlpack::data::TfIdfEncodingPolicy::TfTypes MDTT = mlpack::data::TfIdfEncodingPolicy::TfTypes::TERM_FREQUENCY, bool boolean = false);

#endif