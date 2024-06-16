/**
 * @file mein_knn.hpp
 * @author John Obi (johnobi2003@gmail.com)
 * @brief The implementation of K-nearest neighbour
 * @version 0.1.0
 * @date 2024-04-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef MEIN_KNN_HPP
#define MEIN_KNN_HPP

#include "ModelBuild.hpp"

enum DistanceEQN
{
    EUCLIDEAN,
    COSINE,
    MANHATTAN,
    COSINE_DISSIMILARITY
};

template <typename MatrixType>
class Mein_KNN
{
private:
    MatrixType matrix;               // dataset
    arma::Row<size_t> matrix_label; // dataset label
    int k;
    DistanceEQN Deqn = DistanceEQN::EUCLIDEAN;

    int class_occurrences(std::vector<std::pair<double, size_t>> &distance_out, int k);

    int Rclass_occurrences(arma::Col<double> &distances, int k);

    arma::Col<double> Euclidean_distance(MatrixType &matrix, MatrixType &newmatrix);

    arma::Col<double> Cosine_distance(MatrixType &matrix, arma::Row<double> &newmatrix);

    arma::Col<double> CosineDis_distance(MatrixType &matrix, MatrixType &newmatrix);

    arma::Col<double> Cosine_distance(MatrixType &matrix, MatrixType &newmatrix);

    arma::Col<double> Manhattan_distance(MatrixType &matrix, MatrixType &newmatrix);

public:

    Mein_KNN();

    Mein_KNN(MatrixType &matt, arma::Row<size_t> &matrow);

    int Classify(MatrixType &predmat, int k = 1, DistanceEQN deqn = DistanceEQN::EUCLIDEAN);

    double Evaluate(MatrixType &matt, arma::Row<size_t> &matrow);

    void ClassReport(MatrixType &matt, arma::Row<size_t> &matrow);
};

#endif