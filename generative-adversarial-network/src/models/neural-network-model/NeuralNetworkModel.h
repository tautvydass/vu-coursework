#pragma once

#include <vector>
#include "../neural-network-layer/HiddenLayer.h"

class NeuralNetworkModel
{
protected:
	const size_t m_inputLength;
	std::vector<HiddenLayer*> m_hiddenLayers;

	size_t m_hiddenLayerCount = 0;

protected:
	static inline void sigmoid(double& input)
	{
		input = 1 / (1 + exp(-input));
	}

public:
	NeuralNetworkModel(const size_t& inputLength) : m_inputLength(inputLength) { }

	virtual ~NeuralNetworkModel()
	{
		for (HiddenLayer* layer : m_hiddenLayers)
		{
			delete layer;
		}
		m_hiddenLayers.clear();
	}

	void addHiddenLayer(const size_t& size)
	{
		m_hiddenLayers.push_back(new HiddenLayer(size, m_hiddenLayerCount == 0 ? m_inputLength : m_hiddenLayers[m_hiddenLayerCount - 1]->size));
		m_hiddenLayerCount++;
	}

	arma::vec calculate(const arma::vec& input)
	{
		for (size_t i = 0; i < m_hiddenLayerCount; i++)
		{
			m_hiddenLayers[i]->activations = m_hiddenLayers[i]->weights * (i == 0 ? input : m_hiddenLayers[i - 1]->activations) + m_hiddenLayers[i]->biases;
			m_hiddenLayers[i]->activations.for_each(sigmoid);
		}

		return m_hiddenLayers[m_hiddenLayerCount - 1]->activations;
	}

	virtual void init() = 0;
};
