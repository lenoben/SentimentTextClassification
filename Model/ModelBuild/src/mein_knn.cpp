#include "mein_knn.hpp"

// Explicit template instantiation for arma::mat and arma::sp_mat
template class Mein_KNN<arma::mat>;
template class Mein_KNN<arma::sp_mat>;

template <typename MatrixType>
arma::Col<double> Mein_KNN<MatrixType>::Euclidean_distance(MatrixType &matrix, MatrixType &newmatrix)
{
    arma::Col<double> distances(matrix.n_cols);
        
        for (arma::uword j = 0; j < matrix.n_cols; j++) {
            double squaredSum = 0.0;

            for (arma::uword i = 0; i < matrix.n_rows; i++) {
                double powered = std::pow((newmatrix(i, 0) - matrix(i, j)), 2);
                squaredSum += powered;
            }

            distances(j) = std::sqrt(squaredSum);
        }

        return distances;
}


template <typename MatrixType>
int Mein_KNN<MatrixType>::class_occurrences(std::vector<std::pair<double, size_t>> &distance_out, int k)
{
    std::unordered_map<int, int> class_count;
    for (size_t i = 0; i < k; ++i)
    {
        class_count[distance_out[i].second]++;
    }

    // find the majority class
    int max_count = 0;
    int max_class = -1;
    for (const auto &pair : class_count)
    {
        if (pair.second > max_count)
        {
            max_count = pair.second;
            max_class = pair.first;
        }
    }

    return max_class;
}


template <typename MatrixType>
Mein_KNN<MatrixType>::Mein_KNN(): k(1), Deqn(DistanceEQN::MANHATTAN) {};

template <typename MatrixType>
Mein_KNN<MatrixType>::Mein_KNN(MatrixType &matt, arma::Row<size_t> &matrow) : matrix(matt), matrix_label(matrow), k(1){};


template <typename MatrixType>
int Mein_KNN<MatrixType>::Classify(MatrixType &predmat, int k, DistanceEQN deqn)
{
    arma::Col<double> sumdistance = Euclidean_distance(matrix, predmat);

    std::vector<std::pair<double, size_t>> dist_label;
    for (size_t j = 0; j < matrix_label.n_cols; j++)
    {
        for (size_t i = 0; i < matrix_label.n_rows; i++)
        {
            dist_label.push_back({sumdistance(j, i),
                                  matrix_label(i, j)});
        }
    }

    // sort
    std::sort(
        dist_label.begin(), dist_label.end(),
        [](const std::pair<double, size_t> &a, const std::pair<double, size_t> &b)
        {
            return a.first < b.first;
        });

    // count occurrances
    if (dist_label.size() < k)
        std::cerr << "K is greater than dataset size" << std::endl;

    return class_occurrences(dist_label, k);
}


template <typename MatrixType>
double Mein_KNN<MatrixType>::Evaluate(MatrixType &matt, arma::Row<size_t> &matrow)
{
    arma::Row<size_t> res(matt.n_cols);
    for (arma::uword i = 0; i < matt.n_cols; i++)
    {
        MatrixType col = matt.col(i);
        res(i) = Classify(col,k,Deqn);
    }
    return ComputeAccuracy(res, matrow);
}

template <typename MatrixType>
void Mein_KNN<MatrixType>::ClassReport(MatrixType &matt, arma::Row<size_t> &matrow)
{
    arma::Row<size_t> res(matt.n_cols);
    for (arma::uword i = 0; i < matt.n_cols; i++)
    {
        MatrixType col = matt.col(i);
        res(i) = Classify(col,k,Deqn);;
    }
    double result = ComputeAccuracy(res, matrow);
    std::cout << "[INFO] " << std::setw(4) << "Accurracy - " << result << std::endl;
    ClassificationReport(res, matrow);
}