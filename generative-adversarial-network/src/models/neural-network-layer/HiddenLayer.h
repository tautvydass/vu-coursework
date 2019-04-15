#pragma once
#include <armadillo>

class HiddenLayer
{
public:
	arma::mat weights;
	arma::vec biases;
	arma::vec activations;
	const size_t size;
	const size_t childNodeCount;

private:
	static inline void normalizeRandomValue(double& input)
	{
		input = (input - 0.5) * 2;
	}

public:
	HiddenLayer(const size_t& size, const size_t& childNodeCount) : size(size), childNodeCount(childNodeCount)
	{
		weights = arma::randu<arma::mat>(size, childNodeCount);
		biases = arma::randu<arma::vec>(size);

		weights.for_each(normalizeRandomValue);
		biases.for_each(normalizeRandomValue);
	}

	~HiddenLayer()
	{
		
	}
};

