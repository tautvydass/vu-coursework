#include <iostream>
#include <armadillo>

#include "utils/ImageUtils.h"
#include "utils/Benchmark.h"
#include "models/neural-network-model/discriminator/ArtDiscriminatorModel.h"
#include "models/neural-network-model/generator/ArtGeneratorModel.h"

#define LOG(x) std::cout << x << std::endl;

#define IMAGE_SIZE 64
#define INPUT_LENGTH IMAGE_SIZE * IMAGE_SIZE * 3
#define GENERATOR_HIDDEN_LAYER_NODE_COUNT 128
#define DISCRIMINATOR_HIDDEN_LAYER_NODE_COUNT 64

using namespace arma;

void testDiscriminator()
{
	ArtDiscriminatorModel* model = new ArtDiscriminatorModel(INPUT_LENGTH);
	model->addHiddenLayer(DISCRIMINATOR_HIDDEN_LAYER_NODE_COUNT);
	model->addHiddenLayer(DISCRIMINATOR_HIDDEN_LAYER_NODE_COUNT);
	model->init();

	ArtDiscriminatorModelResult* result = model->discriminateArt(randu<vec>(INPUT_LENGTH));

	delete result;
	delete model;
}

void testGenerator()
{
	ArtGeneratorModel* model = new ArtGeneratorModel(INPUT_LENGTH);
	model->addHiddenLayer(GENERATOR_HIDDEN_LAYER_NODE_COUNT);
	model->addHiddenLayer(GENERATOR_HIDDEN_LAYER_NODE_COUNT);
	model->init();

	vec result = model->calculate(randu<vec>(INPUT_LENGTH));

	delete model;
}

int main()
{
	Benchmark::run(testDiscriminator, 5, "Discriminator Test");
	Benchmark::run(testGenerator, 5, "Generator Test");

	system("PAUSE");

	return 0;
}
