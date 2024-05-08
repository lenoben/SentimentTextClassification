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

namespace mb
{
    /*
    Models Examples
        ---------------
        Layers: Input layer (29 neurons) -> Fully connected layer (64 neurons) -> ReLU activation -> Fully connected layer (32 neurons) -> ReLU activation -> Output layer (1 neuron)
        Activation Functions: ReLU for hidden layers, sigmoid for the output layer
        Loss Function: Binary cross-entropy, mlpack::BCELoss
        Initialization Rule: Random initialization
        ---------------
        Layers: Input layer (29 neurons) -> Fully connected layer (128 neurons) -> ReLU activation -> Dropout (with dropout rate 0.5) -> Fully connected layer (64 neurons) -> ReLU activation -> Dropout (with dropout rate 0.5) -> Fully connected layer (32 neurons) -> ReLU activation -> Dropout (with dropout rate 0.5) -> Output layer (1 neuron)
        Activation Functions: ReLU for hidden layers, sigmoid for the output layer
        Loss Function: Binary cross-entropy
        Initialization Rule: He initialization
        ---------------
        Layers: Input layer (29 neurons) -> Fully connected layer (64 neurons) -> Leaky ReLU activation -> Batch normalization -> Fully connected layer (32 neurons) -> Leaky ReLU activation -> Batch normalization -> Output layer (1 neuron)
        Activation Functions: Leaky ReLU for hidden layers, sigmoid for the output layer
        Loss Function: Hinge loss
        Initialization Rule: Xavier initialization
        ---------------
    */

    mlpack::FFN<mlpack::CrossEntropyError, mlpack::RandomInitialization> &binary_random(int numberOfCols)
    {
        mlpack::FFN<mlpack::CrossEntropyError, mlpack::RandomInitialization> *model = new mlpack::FFN<mlpack::CrossEntropyError, mlpack::RandomInitialization>();
        model->Add<mlpack::Linear>(numberOfCols);
        model->Add<mlpack::ReLU>();
        model->Add<mlpack::Linear>(64);
        model->Add<mlpack::ReLU>();
        model->Add<mlpack::Linear>(32);
        model->Add<mlpack::ReLU>();
        model->Add<mlpack::Linear>(1);
        model->Add<mlpack::Sigmoid>();

        return *model;
    }

    mlpack::FFN<mlpack::CrossEntropyError, mlpack::HeInitialization> &binary_he(int numberofrows)
    {
        mlpack::FFN<mlpack::CrossEntropyError, mlpack::HeInitialization> *model = new mlpack::FFN<mlpack::CrossEntropyError, mlpack::HeInitialization>();
        model->Add<mlpack::Linear>(numberofrows);
        model->Add<mlpack::Dropout>(0.5);
        model->Add<mlpack::LeakyReLU>();
        model->Add<mlpack::Linear>(32);
        model->Add<mlpack::LeakyReLU>();
        model->Add<mlpack::Linear>(64);
        model->Add<mlpack::Dropout>(0.5);
        model->Add<mlpack::LeakyReLU>();
        model->Add<mlpack::Linear>(128);
        model->Add<mlpack::LeakyReLU>();
        model->Add<mlpack::LogSoftMax>();
        model->Add<mlpack::Linear>(64);
        model->Add<mlpack::LeakyReLU>();
        model->Add<mlpack::Dropout>(0.5);
        model->Add<mlpack::Linear>(32);
        model->Add<mlpack::LeakyReLU>();
        model->Add<mlpack::Linear>(1);
        model->Add<mlpack::Sigmoid>();

        return *model;
    }

    mlpack::FFN<mlpack::MeanSquaredError, mlpack::HeInitialization> &mean_he(int noOfrows)
    {
        mlpack::FFN<mlpack::MeanSquaredError, mlpack::HeInitialization> *model = new mlpack::FFN<mlpack::MeanSquaredError, mlpack::HeInitialization>();
        model->Add<mlpack::Linear>(noOfrows);
        model->Add<mlpack::Dropout>(0.5);
        model->Add<mlpack::LeakyReLU>();
        model->Add<mlpack::Linear>(32);
        model->Add<mlpack::LeakyReLU>();
        model->Add<mlpack::Linear>(64);
        model->Add<mlpack::Dropout>(0.5);
        model->Add<mlpack::LeakyReLU>();
        model->Add<mlpack::Linear>(128);
        model->Add<mlpack::LeakyReLU>();
        model->Add<mlpack::Linear>(64);
        model->Add<mlpack::LeakyReLU>();
        model->Add<mlpack::Dropout>(0.5);
        model->Add<mlpack::Linear>(32);
        model->Add<mlpack::LeakyReLU>();
        model->Add<mlpack::Linear>(1);
        model->Add<mlpack::Sigmoid>();

        return *model;
    }
}
