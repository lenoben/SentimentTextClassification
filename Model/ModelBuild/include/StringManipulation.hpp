/**
 * @file StringManipulation.hpp
 * @author lenoben (lenoben002@gmail.com)
 * @brief A header file to house string manipulations that will be used
 * @version 0.1.0
 * @date 2024-01-28
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef STRING_MANIPULATION_HPP
#define STRING_MANIPULATION_HPP

#include <string>
#include <algorithm>

#include "SATC.hpp"

/**
 * @brief Extract the actual filename from the fullpath
 * @example ../data/parser.py -->> parser
 * @example ../data/parser.txt.gz -->> parser
 * @param path path to the file
 * @return the actual filename
 */
std::string extractFilename(const std::string &path);

/**
 * @brief Calls the extractFilename method
 * makes the path variable a constant string
 * @param path
 */
void removeNonFilename(std::string &path);

void to_lower_str(std::string &cleaned);

void to_lower_vec(std::vector<std::string> &string_vector);

std::string cleanString(std::string dirty);

bool removeStop(std::vector<std::string> &DatasetList);

void combineJsonLineByLine(std::vector<std::string> &DatasetList);

void saveVectors(std::vector<std::string> &vector, std::string filename);

void sm_convertJsonToTxt(std::string JsonFile, std::vector<std::string> &DatasetList);

void combineTXT(std::vector<std::string> &DatasetList);

void categorizeByScore(std::vector<std::string> &DatasetList, int positive);

int countLines(const std::string &fileName);

void equalizeLines(const std::string &inputFileName, std::ofstream &output, int n);

void equalizer(std::vector<std::string> &DatasetList);

std::vector<std::string> file_to_vector(const std::string &filename, int length);
#endif