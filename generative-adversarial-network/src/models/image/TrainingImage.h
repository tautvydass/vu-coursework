#pragma once

#include <armadillo>
#include "../neural-network-model/discriminator/ArtDiscriminatorModelResult.h"
#include "../neural-network-model/discriminator/creative/CreativeArtDiscriminatorModelResult.h"

class TrainingImage
{
public:
	const ArtDiscrimination artDiscrimination;
	const ArtStyleDiscrimination artStyleDiscrimination;
	const size_t size;
	const arma::vec* data;

public:
	TrainingImage(const ArtDiscrimination& artDiscrimination, const ArtStyleDiscrimination& artStyleDiscrimination, const size_t& size, const arma::vec* imageData)
		: artDiscrimination(artDiscrimination), artStyleDiscrimination(artStyleDiscrimination), size(size), data(imageData) { }

	~TrainingImage()
	{
		if (data != nullptr)
		{
			delete data;
		}
	}

	arma::vec getArtDiscriminationExpectedResult()
	{
		arma::vec result = arma::zeros<arma::vec>(ArtDiscrimination::Count);
		result.at(artDiscrimination) = 1;
		return result;
	}

	arma::vec getArtStyleDiscriminationExpectedResult()
	{
		arma::vec result = arma::zeros<arma::vec>(ArtDiscrimination::Count + ArtStyleDiscrimination::ArtStyleCount);
		result.at(artDiscrimination) = 1;
		if (artDiscrimination == ArtDiscrimination::Art)
		{
			result.at(ArtDiscrimination::Count + artStyleDiscrimination) = 1;
		}
		return result;
	}
};