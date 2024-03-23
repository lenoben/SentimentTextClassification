#include "MF_LinearRegression.hpp"

namespace mf
{

    arma::Row<size_t> rowvecToRow(const arma::rowvec &row)
    {
        arma::Row<size_t> result(row.n_elem);
        for (arma::uword i = 0; i < row.n_elem; ++i)
        {
            result(i) = static_cast<size_t>(std::round(row(i)));
        }
        return result;
    }

    double linearRegressionSetup(EncoderType ET, scaler_methods SM, bool intercept)
    {
        arma::Row<size_t> trainLabel, testLabel;
        arma::mat trainMat, testMat;
        std::tie(trainMat, testMat, trainLabel, testLabel) = getMatrixDataset(ET);
        arma::rowvec pred, trainLabelvec = arma::conv_to<arma::rowvec>::from(trainLabel), testLabelvec = arma::conv_to<arma::rowvec>::from(testLabel);

        trainMat.brief_print("Train Matrix 🧩");
        trainLabel.brief_print("Test Label 🧩");
    }
};
