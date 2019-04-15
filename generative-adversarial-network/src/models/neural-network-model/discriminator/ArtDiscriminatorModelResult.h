#pragma once

#include "../NeuralNetworkModelResult.h"

enum ArtDiscrimination
{
	Art,
	NotArt,
	Count
};


class ArtDiscriminatorModelResult : public NeuralNetworkModelResult
{
public:
	ArtDiscriminatorModelResult(const arma::vec& result) : NeuralNetworkModelResult(result) { }

	ArtDiscrimination getArtDiscrimination()
	{
		return (ArtDiscrimination)(baseResult(arma::span(0, ArtDiscrimination::Count - 1)).index_max());
	}

	virtual ~ArtDiscriminatorModelResult() { }
};