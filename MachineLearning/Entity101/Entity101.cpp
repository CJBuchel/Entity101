#include "mlpack/core.hpp"
#include "mlpack/methods/random_forest/random_forest.hpp"
#include "mlpack/methods/decision_tree/random_dimension_select.hpp"
#include "mlpack/core/cv/k_fold_cv.hpp"
#include "mlpack/core/cv/metrics/accuracy.hpp"
#include "mlpack/core/cv/metrics/precision.hpp"
#include "mlpack/core/cv/metrics/recall.hpp"
#include "mlpack/core/cv/metrics/F1.hpp"

using namespace arma;
using namespace mlpack;
using namespace mlpack::tree;
using namespace mlpack::cv;

mat dataset;
bool loaded = mlpack::data::Load("data/german.csv", dataset);
if (!loaded)
return -1;

Row<size_t> labels;
labels = conv_to<Row<size_t>>::from(dataset.row(dataset.n_rows - 1));
dataset.shed_row(dataset.n_rows - 1);

const size_t numClasses = 2;
const size_t minimumLeafSize = 5;
const size_t numTrees = 10;
RandomForest<GiniGain, RandomDimensionSelect> rf;
rf = RandomForest<GiniGain, RandomDimensionSelect>(dataset, labels,
	numClasses, numTrees, minimumLeafSize);

Row<size_t> predictions;
rf.Classify(dataset, predictions);
const size_t correct = arma::accu(predictions == labels);
cout << "\nTraining Accuracy: " << (double(correct) / double(labels.n_elem));

const size_t k = 10;
KFoldCV<RandomForest<GiniGain, RandomDimensionSelect>, Accuracy> cv(k,
	dataset, labels, numClasses);
double cvAcc = cv.Evaluate(numTrees, minimumLeafSize);
cout << "\nKFoldCV Accuracy: " << cvAcc;

double cvPrecision = Precision<Binary>::Evaluate(rf, dataset, labels);
cout << "\nPrecision: " << cvPrecision;
double cvRecall = Recall<Binary>::Evaluate(rf, dataset, labels);
cout << "\nRecall: " << cvRecall;
double cvF1 = F1<Binary>::Evaluate(rf, dataset, labels);
cout << "\nF1: " << cvF1;

mlpack::data::Save("mymodel.xml", "model", rf, false);

mlpack::data::Load("mymodel.xml", "model", rf);

mat sample("2 12 2 13 1 2 2 1 3 24 3 1 1 1 1 1 0 1 0 1 0 0 0");
mat probabilities;
rf.Classify(sample, predictions, probabilities);
u64 result = predictions.at(0);
cout << "\nClassification result: " << result << " , Probabilities: " <<
probabilities.at(0) << "/" << probabilities.at(1);