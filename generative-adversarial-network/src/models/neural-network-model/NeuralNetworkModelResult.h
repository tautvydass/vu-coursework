#pragma once

#include <armadillo>

class NeuralNetworkModelResult
{
public:
	const arma::vec baseResult;

	NeuralNetworkModelResult(const arma::vec& result) : baseResult(result) { }

	virtual ~NeuralNetworkModelResult() { }
};
