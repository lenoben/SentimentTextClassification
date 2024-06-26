#ifndef MODEL_BUILD_MB_FNN_HPP
#define MODEL_BUILD_MB_FNN_HPP

#include "ModelBuild.hpp"
// FNN

#include <mlpack/core.hpp>
#include <mlpack/methods/ann/layer/layer.hpp>

#include <mlpack/methods/ann/ffn.hpp>
// init rules
#include <mlpack/methods/ann/init_rules/he_init.hpp>     //mlpack::HeInitialization
#include <mlpack/methods/ann/init_rules/random_init.hpp> //mlpack::RandomInitialization
// Loss functions
#include <mlpack/methods/ann/loss_functions/mean_squared_error.hpp>      //mlpack::MeanSquaredError
#include <mlpack/methods/ann/loss_functions/negative_log_likelihood.hpp> //mlpack::NegativeLogLikelihood
#include <mlpack/methods/ann/loss_functions/cross_entropy_error.hpp>     //mlpack::mlpack::CrossEntropyError --* from local mlpack::BCELoss
#include <mlpack/methods/ann/loss_functions/hinge_embedding_loss.hpp>    //  mlpack::HingeEmbeddingLoss ---*from local <hinge_loss.hpp> mlpack::HingeLoss

#endif