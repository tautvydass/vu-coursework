#pragma once

#include "../ArtDiscriminatorModel.h"
#include "CreativeArtDiscriminatorModelResult.h"

class CreativeArtDiscriminatorModel : public ArtDiscriminatorModel
{
public:
	CreativeArtDiscriminatorModel(const size_t& inputLength) : ArtDiscriminatorModel(inputLength) { }

	~CreativeArtDiscriminatorModel() { }

	CreativeArtDiscriminatorModelResult* discriminateArtStyle(const arma::vec& input)
	{
		return new CreativeArtDiscriminatorModelResult(calculate(input));
	}

	void train(const arma::vec& input, const arma::vec& expectedResult)
	{

	}
};
