#pragma once

#include <armadillo>
#include "../ArtDiscriminatorModelResult.h"

enum ArtStyleDiscrimination
{
	Abstract_Expressionism,
	Action_painting,
	Analytical_Cubism,
	Art_Nouveau,
	Baroque,
	Color_Field_Painting,
	Contemporary_Realism,
	Cubism,
	Early_Renaissance,
	Expressionism,
	Fauvism,
	High_Renaissance,
	Impressionism,
	Mannerism_Late_Renaissance,
	Minimalism,
	Naive_Art_Primitivism,
	New_Realism,
	Northern_Renaissance,
	Pointillism,
	Pop_Art,
	Post_Impressionism,
	Realism,
	Rococo,
	Romanticism,
	Symbolism,
	Synthetic_Cubism,
	Ukiyo_e,
	ArtStyleCount
};

class CreativeArtDiscriminatorModelResult : ArtDiscriminatorModelResult
{
public:
	CreativeArtDiscriminatorModelResult(const arma::vec& result) : ArtDiscriminatorModelResult(result) { }
	~CreativeArtDiscriminatorModelResult() { }

	ArtStyleDiscrimination getArtStyleDiscrimination()
	{
		return (ArtStyleDiscrimination)(baseResult(arma::span(ArtDiscrimination::Count, ArtDiscrimination::Count + ArtStyleDiscrimination::ArtStyleCount)).index_max());
	}
};