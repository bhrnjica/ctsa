#pragma once

#include "pch.h"
/*
	ctsabinding  0.1, https://github.com/bhrnjica/ctsa
	A Univariate Time Series Analysis and ARIMA Modeling Package Bindings


*/

namespace ctsaBinding
{
	//
	extern "C" CTSABINDINGS_API int autoarima(int p, int d, int q, double* ts, double* regressors);

}

