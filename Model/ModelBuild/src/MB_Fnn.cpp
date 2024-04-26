#include "MB_Fnn.hpp"

arma::Row<size_t> getLabels(const arma::mat &yPreds)
{
    arma::Row<size_t> yLabels(yPreds.n_cols);
    for (arma::uword i = 0; i < yPreds.n_cols; ++i)
    {
        yLabels(i) = yPreds.col(i).index_max();
    }
    return yLabels;
}

arma::Row<size_t> _convertToRow(const arma::mat &matrix, double threshold)
{
    arma::Row<size_t> result(matrix.n_cols);

    for (size_t i = 0; i < matrix.n_cols; ++i)
    {
        result(i) = (matrix(0, i) >= threshold) ? 1 : 0;
    }

    return result;
}