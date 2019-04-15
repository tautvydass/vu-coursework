#pragma once

#include "ArtDiscriminatorModelResult.h"
#include "../NeuralNetworkModel.h"
#include "../../image/TrainingImage.h"

class ArtDiscriminatorModel : public NeuralNetworkModel
{
public:
	ArtDiscriminatorModel(const size_t& inputLength) : NeuralNetworkModel(inputLength) { }

	~ArtDiscriminatorModel() { }

	ArtDiscriminatorModelResult* discriminateArt(const arma::vec& input)
	{
		return new ArtDiscriminatorModelResult(calculate(input));
	}

	void train(const TrainingImage& imageInput)
	{
		ArtDiscriminatorModelResult* result = discriminateArt(*imageInput.data);
		if (result->getArtDiscrimination() == imageInput.artDiscrimination)
		{
			// reward
		}
		else
		{
			// loss
		}
	}

	void init() override
	{
		// Add final result layer, where values indicate: [0] - art, [1] - not art
		addHiddenLayer(2);
	}
};
