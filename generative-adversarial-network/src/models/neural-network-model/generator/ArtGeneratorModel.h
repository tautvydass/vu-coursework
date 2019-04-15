#pragma once

#include "../NeuralNetworkModel.h"

class ArtGeneratorModel : public NeuralNetworkModel
{
public:
	ArtGeneratorModel(const size_t& inputLength) : NeuralNetworkModel(inputLength) { }
	~ArtGeneratorModel() { }

	void init() override
	{
		addHiddenLayer(m_inputLength);
	}
};