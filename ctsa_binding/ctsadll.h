#pragma once

#include "pch.h"
/*
	ctsabinding  0.1, https://github.com/bhrnjica/ctsa
	A Univariate Time Series Analysis and ARIMA Modeling Package Bindings


*/

namespace ctsaBinding
{
	extern "C" CTSABINDINGS_API struct arimaset {
		int N;// length of time series
		int Nused;//length of time series after differencing, Nused = N - d
		int method;
		int optmethod;
		int p;// size of phi
		int d;// Number of times the series is to be differenced
		int q;//size of theta
		int M; // M = 0 if mean is 0.0 else M = 1
		int ncoeff;// Total Number of Coefficients to be estimated
		int cssml;// Uses CSS before MLE if 1 else uses MLE only if cssml is 0
		double* phi;
		double* theta;
		double* vcov;// Variance-Covariance Matrix Of length lvcov
		int lvcov; //length of VCOV
		double* res;
		double mean;
		double var;
		double loglik;
		double aic;
		int retval;
		double params[0];
	};
	extern "C" CTSABINDINGS_API struct sarimaset {
		int N;// length of time series
		int Nused;//length of time series after differencing, Nused = N - d - s*D
		int method;
		int optmethod;
		int p;// size of phi
		int d;// Number of times the series is to be differenced
		int q;//size of theta
		int s;// Seasonality/Period
		int P;//Size of seasonal phi
		int D;// The number of times the seasonal series is to be differenced
		int Q;//size of Seasonal Theta
		int M; // M = 0 if mean is 0.0 else M = 1
		int ncoeff;// Total Number of Coefficients to be estimated
		int cssml;// Uses CSS before MLE if 1 else uses MLE only if cssml is 0
		double* phi;
		double* theta;
		double* PHI;
		double* THETA;
		double* vcov;// Variance-Covariance Matrix Of length lvcov
		int lvcov; //length of VCOV
		double* res;
		double mean;
		double var;
		double loglik;
		double aic;
		int retval;
		double params[0];
	};
	extern "C" CTSABINDINGS_API struct arset {
		int N;// length of time series
		int method;
		int optmethod;// Valid only for MLE estimation
		int p;// size of phi
		int order; // order = p
		int ordermax; // Set Maximum order to be fit
		double* phi;
		double* res;
		double mean;
		double var;
		double aic;
		int retval;
		double params[0];
	};
	extern "C" CTSABINDINGS_API struct sarimaxset {
		int N;// length of time series
		int Nused;//length of time series after differencing, Nused = N - d
		int method;
		int optmethod;
		int p;// size of phi
		int d;// Number of times the series is to be differenced
		int q;//size of theta
		int s;// Seasonality/Period
		int P;//Size of seasonal phi
		int D;// The number of times the seasonal series is to be differenced
		int Q;//size of Seasonal Theta
		int r;// Number of exogenous variables
		int M; // M = 0 if mean is 0.0 else M = 1
		int ncoeff;// Total Number of Coefficients to be estimated
		double* phi;
		double* theta;
		double* PHI;
		double* THETA;
		double* exog;
		double* vcov;// Variance-Covariance Matrix Of length lvcov
		int lvcov; //length of VCOV
		double* res;
		double mean;
		double var;
		double loglik;
		double aic;
		int retval;
		int start;
		int imean;
		double params[0];
	};
	extern "C" CTSABINDINGS_API struct autoarimaset {
		int N;// length of time series
		int Nused;//length of time series after differencing, Nused = N - d
		int method;
		int optmethod;
		int pmax;// Maximum size of phi
		int dmax;// Maximum Number of times the series is to be differenced
		int qmax;// Maximum size of theta
		int Pmax;//Maximum Size of seasonal phi
		int Dmax;// Maximum number of times the seasonal series is to be differenced
		int Qmax;//Maximum size of Seasonal Theta
		int p;// size of phi
		int d;// Number of times the series is to be differenced
		int q;//size of theta
		int s;// Seasonality/Period
		int P;//Size of seasonal phi
		int D;// The number of times the seasonal series is to be differenced
		int Q;//size of Seasonal Theta
		int r;// Number of exogenous variables
		int M; // M = 0 if mean is 0.0 else M = 1
		int ncoeff;// Total Number of Coefficients to be estimated
		double* phi;
		double* theta;
		double* PHI;
		double* THETA;
		double* exog;
		double* vcov;// Variance-Covariance Matrix Of length lvcov
		int lvcov; //length of VCOV
		double* res;
		double mean;
		double var;
		double loglik;
		double ic;
		int retval;
		int start;
		int imean;
		int idrift;
		int stationary;
		int seasonal;
		int Order_max;
		int p_start;
		int q_start;
		int P_start;
		int Q_start;
		char information_criteria[10];
		int stepwise;
		int num_models;
		int approximation;
		int verbose;
		char test[10];
		char type[10];
		char seas[10];
		double alpha_test;
		double alpha_seas;
		double lambda;
		double sigma2;
		double aic;
		double bic;
		double aicc;
		double params[0];
	};
	extern "C" CTSABINDINGS_API struct sarimaxwrapperset {
		sarimaxset* sarimax;
		int idrift;
		double aic;
		double bic;
		double aicc;
		double lambda;
		double sigma2;
	};
	extern "C" CTSABINDINGS_API struct myarimaset {
		sarimaxset* sarimax;
		int idrift;
		double ic;
		double aic;
		double bic;
		double aicc;
		double sigma2;
	};
	extern "C" CTSABINDINGS_API struct aaretset {
		sarimaxwrapperset* Arima;
		myarimaset* myarima;
		int otype;
	};


	//Utils for free memory
	extern "C" CTSABINDINGS_API void arimafree(arimaset* object);
	extern "C" CTSABINDINGS_API void sarimaxfree(sarimaxset* object);
	extern "C" CTSABINDINGS_API void sarimaxwrapperfree(sarimaxwrapperset* object);
	extern "C" CTSABINDINGS_API void myarimafree(myarimaset* object);
	extern "C" CTSABINDINGS_API void aa_retfree(aaretset* object);
	extern "C" CTSABINDINGS_API void autoarimafree(autoarimaset* object);
	extern "C" CTSABINDINGS_API void sarimafree(sarimaset* object);
	extern "C" CTSABINDINGS_API void arfree(arset* object);

	//erors
	extern "C" CTSABINDINGS_API   void daany_pe(double* predicted, double* actual, int N, double* err);
	extern "C" CTSABINDINGS_API double daany_me(double* predicted, double* actual, int N);
	extern "C" CTSABINDINGS_API double daany_mse(double* predicted, double* actual, int N);
	extern "C" CTSABINDINGS_API double daany_rmse(double* predicted, double* actual, int N);
	extern "C" CTSABINDINGS_API double daany_mae(double* predicted, double* actual, int N);
	extern "C" CTSABINDINGS_API double daany_mape(double* predicted, double* actual, int N);
	extern "C" CTSABINDINGS_API double daany_mpe(double* predicted, double* actual, int N);
	extern "C" CTSABINDINGS_API double daany_mase(double* predicted, double* actual, int N, double* tseries, int length);

	//
	extern "C" CTSABINDINGS_API int daany_auto_arima(int p, int d, int q, double* ts, int tsLength, double* regressors);
	extern "C" CTSABINDINGS_API myarimaset* daany_search_arima(double* x, int N, int d, int D, int p_max, int q_max, int P_max, int Q_max, int Order_max, int stationary, int s, const char* ic,
		int approximation, double* xreg, int r, double offset, int allowdrift, int allowmean, int verbose, int method);

	//ARIMA related methods
	extern "C" CTSABINDINGS_API arimaset* daany_arima_init(int p, int d, int q, int N);
	extern "C" CTSABINDINGS_API void daany_arima_setMethod(arimaset* asp, int value);
	extern "C" CTSABINDINGS_API void daany_arima_setOptMethod(arimaset* asp, int value);
	extern "C" CTSABINDINGS_API void daany_arima_exec(arimaset* asp, double* inp);
	extern "C" CTSABINDINGS_API void daany_arima_summary(arimaset* asp);
	extern "C" CTSABINDINGS_API void daany_arima_predict(arimaset* asp, double* inp, int L, double* xpred, double* amse);

	//AUTOARIMA related methods
	extern "C" CTSABINDINGS_API autoarimaset* daany_auto_arima_init(int* pdqmax, int* PDQmax, int s, int r, int N);
	extern "C" CTSABINDINGS_API void daany_auto_arima_setApproximation(autoarimaset* obj, int approximation);
	extern "C" CTSABINDINGS_API void daany_auto_arima_setStepwise(autoarimaset* obj, int stepwise);
	extern "C" CTSABINDINGS_API void daany_auto_arima_exec(autoarimaset* obj, double* inp, double* xreg);
	extern "C" CTSABINDINGS_API void daany_auto_arima_summary(autoarimaset* obj);
	extern "C" CTSABINDINGS_API void daany_auto_arima_predict(autoarimaset* obj, double* inp, double* xreg, int L, double* newxreg, double* xpred, double* amse);
	//SARIMA related methods


}

