
#include "pch.h"
#include "ctsadll.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ctsadll.h"
#include "../src/errors.c"




namespace ctsaBinding
{
	extern void mapsarimaxobject(sarimax_object sobj, sarimaxset* s);
	extern void maparimaobject(arima_object ao, arimaset* as);
	extern void maparimaset(arimaset* ao, arima_object aop);
	extern void mapautoarimaobject(auto_arima_object ao, autoarimaset* aas);
	extern void mapautoarimaset(autoarimaset* aaso, auto_arima_object aao);
	extern void mapchararray(char* left, char* right, int n);

	void arimafree(arimaset* object) {
		free(object);
	}

	void sarimaxfree(sarimaxset* object) {
		free(object);
	}

	void sarimaxwrapperfree(sarimaxwrapperset* object) {
		sarimaxfree(object->sarimax);
		free(object);
	}

	void myarimafree(myarimaset* object) {
		sarimaxfree(object->sarimax);
		free(object);
	}

	void aa_retfree(aaretset* object) {
		if (object->otype == 1) {
			free(object->myarima);
		}
		else {
			free(object->Arima);
		}
		free(object);
	}

	void autoarimafree(autoarimaset* object) {
		free(object);
	}

	void sarimafree(sarimaset* object) {
		free(object);
	}

	void arfree(arset* object) {
		free(object);
	}


	//Errors
	void daany_pe(double* predicted, double* actual, int N, double* err)
	{
		pe(predicted, actual, N, err);
	}
	double daany_me(double* predicted, double* actual, int N)
	{
		return me(predicted, actual, N);
	}
	double daany_mse(double* predicted, double* actual, int N)
	{
		return mse(predicted, actual, N);
	}
	double daany_rmse(double* predicted, double* actual, int N)
	{
		return rmse(predicted, actual, N);
	}
	double daany_mae(double* predicted, double* actual, int N)
	{
		return mae(predicted, actual, N);
	}
	double daany_mape(double* predicted, double* actual, int N)
	{
		return mape(predicted, actual, N);
	}
	double daany_mpe(double* predicted, double* actual, int N)
	{
		return mpe(predicted, actual, N);
	}
	double daany_mase(double* predicted, double* actual, int N, double* tseries, int length)
	{
		return mase(predicted, actual, N, tseries, length);
	}

	//ARIMA related methods
	arimaset* daany_arima_init(int p, int d, int q, int N)
	{
		arima_object ao = arima_init(p,d,q,N);
		arimaset* as = (arimaset*)malloc(sizeof(struct arimaset));
		maparimaobject(ao, as);
		
		//free obj
		arima_free(ao);
		return as;

	}
	void daany_arima_setMethod(arimaset* asp, int value)
	{
		/*arima_object obj = maparimaset(asp);
		arima_setMethod(obj, value);*/
		if (value == 0) {
			asp->method = 0;
		}
		else if (value == 1) {
			asp->method = 1;
		}
		else if (value == 2) {
			asp->method = 2;
		}
		else {
			printf("\n Acceptable Numerical Values 0 - MLE, 1 - CSS, 2 - Box-Jenkins \n");
		}

	}
	void daany_arima_setOptMethod(arimaset* asp, int value)
	{
		/*arima_object obj = maparimaset(asp);
		arima_setOptMethod(obj, value);*/
		/*
	* Method 0 - Nelder-Mead
	* Method 1 - Newton Line Search
	* Method 2 - Newton Trust Region - Hook Step
	* Method 3 - Newton Trust Region - Double Dog-Leg
	* Method 4 - Conjugate Gradient
	* Method 5 - BFGS
	* Method 6 - Limited Memory BFGS
	* Method 7 - BFGS More-Thuente Line Search
	*/
		if (value == 0) {
			asp->optmethod = 0;
		}
		else if (value == 1) {
			asp->optmethod = 1;
		}
		else if (value == 2) {
			asp->optmethod = 2;
		}
		else if (value == 3) {
			asp->optmethod = 3;
		}
		else if (value == 4) {
			asp->optmethod = 4;
		}
		else if (value == 5) {
			asp->optmethod = 5;
		}
		else if (value == 6) {
			asp->optmethod = 6;
		}
		else if (value == 7) {
			asp->optmethod = 7;
		}
		else {
			printf("\n Acceptable Numerical Values 0,1,2,3,4,5,6,7 \n");
			printf("\n Method 0 - Nelder-Mead \n");
			printf("\n Method 1 - Newton Line Search \n");
			printf("\n Method 2 - Newton Trust Region - Hook Step \n");
			printf("\n Method 3 - Newton Trust Region - Double Dog-Leg \n");
			printf("\n Method 4 - Conjugate Gradient \n");
			printf("\n Method 5 - BFGS \n");
			printf("\n Method 6 - Limited Memory BFGS \n");
			printf("\n Method 7 - BFGS More-Thuente Line Search \n");
		}
	}
	void daany_arima_exec(arimaset* asp, double* inp)
	{
		arima_object aop = (arima_object)malloc(sizeof(struct arima_set));
		maparimaset(asp, aop);
		arima_exec(aop, inp);
		maparimaobject(aop,asp);
	}
	void daany_arima_summary(arimaset* asp)
	{
		arima_object aop = (arima_object)malloc(sizeof(struct arima_set));
		maparimaset(asp,aop);
		arima_summary(aop);
	}
	void daany_arima_predict(arimaset* asp, double* inp, int L, double* xpred, double* amse)
	{
		arima_object aop = (arima_object)malloc(sizeof(struct arima_set));
		maparimaset(asp, aop);
		arima_predict(aop, inp, L, xpred, amse);
	}

	//AUTOARIMA related methods
	autoarimaset* daany_auto_arima_init(int* pdqmax, int* PDQmax, int s, int r, int N)
	{
		auto_arima_object aao = auto_arima_init(pdqmax, PDQmax, s, r, N);
		//
		autoarimaset* aas = (autoarimaset*)malloc(sizeof(struct autoarimaset));
		mapautoarimaset(aas, aao);

		auto_arima_free(aao);
		return aas;
	}
	void daany_auto_arima_setApproximation(autoarimaset* obj, int approximation)
	{
		if (approximation == 0 || approximation == 1) {
			obj->approximation = approximation;
		}
		else {
			printf("Approximation parameter accepts only two values - 0 or 1 \n");
		}
	}
	void daany_auto_arima_setStepwise(autoarimaset* obj, int stepwise)
	{
		if (stepwise == 0 || stepwise == 1) {
			obj->stepwise = stepwise;
		}
		else {
			printf("Stepwise parameter accepts only two values - 0 or 1 \n");
		}
	}
	void daany_auto_arima_exec(autoarimaset* obj, double* inp, double* xreg)
	{
		auto_arima_object aao = (auto_arima_object)malloc(sizeof(struct auto_arima_set));
		mapautoarimaobject(aao, obj);
		auto_arima_exec(aao, inp, xreg);
		mapautoarimaset(obj, aao);
	}
	void daany_auto_arima_summary(autoarimaset* obj)
	{
		auto_arima_object aao = (auto_arima_object)malloc(sizeof(struct auto_arima_set));
		auto_arima_summary(aao);
	}
	void daany_auto_arima_predict(autoarimaset* obj, double* inp, double* xreg, int L, double* newxreg,
		double* xpred, double* amse)
	{
		auto_arima_object aaop = (auto_arima_object)malloc(sizeof(struct auto_arima_set));
		mapautoarimaobject(aaop, obj);
		auto_arima_predict(aaop, inp, xreg, L, newxreg, xpred, amse);
	}



	int daany_auto_arima(int p, int d, int q, double* ts, int tsLength, double* regressors)
	{
		int i, L;

		//int p, d, q;
		double* phi, * theta;
		double* xpred, * amse;
		arima_object obj;

		//allocated memory
		L = 0;

		phi = (double*)malloc(sizeof(double) * p);
		theta = (double*)malloc(sizeof(double) * q);

		xpred = (double*)malloc(sizeof(double) * L);
		amse = (double*)malloc(sizeof(double) * L);

		obj = arima_init(p, d, q, tsLength);
		arima_setMethod(obj, 0); // Method 0 ("MLE") is default so this step is unnecessary. The method also accepts values 1 ("CSS") and 2 ("Box-Jenkins")
		//arima_setCSSML(obj,0); // 0 - Only MLE , 1 - CSS + MLE (Default)
		arima_setOptMethod(obj, 5);// Method 5 ("BFGS") is default. The method also accepts values 0,1,2,3,4,5,6,7. Check the documentation for details.
		arima_exec(obj, ts);
		arima_summary(obj);

		// Predict the next 5 values using the obtained ARIMA model
		arima_predict(obj, ts, L, xpred, amse);
		printf("\n");
		printf("Predicted Values : ");
		for (i = 0; i < L; ++i) {
			printf("%g ", xpred[i]);
		}
		printf("\n");
		printf("Standard Errors  : ");
		for (i = 0; i < L; ++i) {
			printf("%g ", sqrt(amse[i]));
		}
		printf("\n");
		arima_free(obj);
		free(phi);
		free(theta);
		free(xpred);
		free(amse);
		return obj->ncoeff;
	}

	myarimaset* daany_search_arima(double* x, int N, int d, int D, int p_max, int q_max, int P_max, int Q_max, int Order_max, int stationary, int s, const char* ic,
		int approximation, double* xreg, int r, double offset, int allowdrift, int allowmean, int verbose, int method)
	{
		//
		myarima_object retVal = search_arima(x, N, d, D, p_max, q_max, P_max, Q_max, Order_max, stationary, s, ic,
									approximation, xreg, r, offset, allowdrift, allowmean, verbose, method);


		sarimaxset* sms = (sarimaxset*)malloc(sizeof(struct sarimaxset));
		myarimaset* as = (myarimaset*)malloc(sizeof(struct myarimaset));
		as->aic = retVal->aic;
		as->aicc = retVal->aicc;
		as->bic = retVal->bic;
		as->ic = retVal->ic;
		as->idrift = retVal->idrift;
		
		mapsarimaxobject(retVal->sarimax, sms);
		
		as->sarimax = sms;
		as->sigma2 = retVal->sigma2;

		//free obje
		myarima_free(retVal);

		return as;
	}

	
	void mapautoarimaobject(auto_arima_object ao, autoarimaset* aas)
	{
		ao->aic = aas->aic;
		ao->aicc = aas->aicc;
		ao->alpha_seas = aas->alpha_seas;
		ao->alpha_test = aas->alpha_test;
		ao->approximation = aas->approximation;
		ao->bic = aas->bic;
		ao->D = aas->D;
		ao->d = aas->d;
		ao->Dmax = aas->Dmax;
		ao->dmax = aas->dmax;
		ao->exog = aas->exog;
		ao->ic = aas->ic;
		ao->idrift = aas->idrift;
		ao->imean = aas->imean;
		mapchararray(ao->information_criteria, aas->information_criteria, 10);	
		ao->lambda = aas->lambda;
		ao->loglik = aas->loglik;
		ao->lvcov = aas->lvcov;
		ao->M = aas->M;
		ao->mean = aas->mean;
		ao->method = aas->method;
		ao->N = aas->N;
		ao->ncoeff = aas->ncoeff;
		ao->num_models = aas->num_models;
		ao->Nused = aas->Nused;
		ao->optmethod = aas->optmethod;
		ao->Order_max = aas->Order_max;
		ao->P = aas->P;
		ao->p = aas->p;
		ao->params[0] = aas->params[0];
		ao->PHI = aas->PHI;
		ao->phi = aas->phi;
		ao->Pmax = aas->Pmax;
		ao->pmax = aas->pmax;
		ao->P_start = aas->P_start;
		ao->p_start = aas->p_start;
		ao->Q = aas->Q;
		ao->q = aas->q;
		ao->Qmax = aas->Qmax;
		ao->qmax = aas->qmax;
		ao->Q_start = aas->Q_start;
		ao->q_start = aas->q_start;
		ao->r = aas->r;
		ao->res = aas->res;
		ao->retval = aas->retval;
		ao->s = aas->s;
		mapchararray(ao->seas,aas->seas, 10);
		ao->seasonal = aas->seasonal;
		ao->sigma2 = aas->sigma2;
		ao->start = aas->start;
		ao->stationary = aas->stationary;
		ao->stepwise = aas->stepwise;
		mapchararray(ao->test, aas->test, 10);
		ao->THETA = aas->THETA;
		ao->theta = aas->theta;
		mapchararray(ao->type, aas->type, 10);
		ao->var = aas->var;
		ao->vcov = aas->vcov;
		ao->verbose = aas->verbose;
	}
	void mapautoarimaset(autoarimaset* aaso, auto_arima_object aao)
	{
		aaso->aic = aao->aic;
		aaso->aicc = aao->aicc;
		aaso->alpha_seas = aao->alpha_seas;
		aaso->alpha_test = aao->alpha_test;
		aaso->approximation = aao->approximation;
		aaso->bic = aao->bic;
		aaso->D = aao->D;
		aaso->d = aao->d;
		aaso->Dmax = aao->Dmax;
		aaso->dmax = aao->dmax;
		aaso->exog = aao->exog;
		aaso->ic = aao->ic;
		aaso->idrift = aao->idrift;
		aaso->imean = aao->imean;
		mapchararray(aaso->information_criteria, aao->information_criteria, 10);
		aaso->lambda = aao->lambda;
		aaso->loglik = aao->loglik;
		aaso->lvcov = aao->lvcov;
		aaso->M = aao->M;
		aaso->mean = aao->mean;
		aaso->method = aao->method;
		aaso->N = aao->N;
		aaso->ncoeff = aao->ncoeff;
		aaso->num_models = aao->num_models;
		aaso->Nused = aao->Nused;
		aaso->optmethod = aao->optmethod;
		aaso->Order_max = aao->Order_max;
		aaso->P = aao->P;
		aaso->p = aao->p;
		aaso->params[0] = aao->params[0];
		aaso->PHI = aao->PHI;
		aaso->phi = aao->phi;
		aaso->Pmax = aao->Pmax;
		aaso->pmax = aao->pmax;
		aaso->P_start = aao->P_start;
		aaso->p_start = aao->p_start;
		aaso->Q = aao->Q;
		aaso->q = aao->q;
		aaso->Qmax = aao->Qmax;
		aaso->qmax = aao->qmax;
		aaso->Q_start = aao->Q_start;
		aaso->q_start = aao->q_start;
		aaso->r = aao->r;
		aaso->res = aao->res;
		aaso->retval = aao->retval;
		aaso->s = aao->s;
		mapchararray(aaso->seas, aao->seas, 10);
		aaso->seasonal = aao->seasonal;
		aaso->sigma2 = aao->sigma2;
		aaso->start = aao->start;
		aaso->stationary = aao->stationary;
		aaso->stepwise = aao->stepwise;
		mapchararray(aaso->test, aao->test, 10);
		aaso->THETA = aao->THETA;
		aaso->theta = aao->theta;
		mapchararray(aaso->type, aao->type, 10);
		aaso->var = aao->var;
		aaso->vcov = aao->vcov;
		aaso->verbose = aao->verbose;

	}

	void maparimaobject(arima_object ao, arimaset* as)
	{
		as->aic = ao->aic;
		as->cssml = ao->cssml;
		as->d = ao->d;
		as->loglik = ao->loglik;
		as->lvcov = ao->lvcov;
		as->M = ao->M;
		as->mean = ao->mean;
		as->method = ao->method;
		as->N = ao->N;
		as->ncoeff = ao->ncoeff;
		as->Nused = ao->Nused;
		as->optmethod = ao->optmethod;
		as->p = ao->p;
		as->params[0] = ao->params[0];
		as->phi = ao->phi;
		as->q = ao->q;
		as->res = ao->res;
		as->retval = ao->retval;
		as->theta = ao->theta;
		as->var = ao->var;
		as->vcov = ao->vcov;

	}
	void maparimaset(arimaset* ao, arima_object aop)
	{
		//arima_object aop = (arima_object)malloc(sizeof(struct arima_set));
		aop->aic = ao->aic;
		aop->cssml = ao->cssml;
		aop->d = ao->d;
		aop->loglik = ao->loglik;
		aop->lvcov = ao->lvcov;
		aop->M = ao->M;
		aop->mean = ao->mean;
		aop->method = ao->method;
		aop->N = ao->N;
		aop->ncoeff = ao->ncoeff;
		aop->Nused = ao->Nused;
		aop->optmethod = ao->optmethod;
		aop->p = ao->p;
		aop->params[0] = ao->params[0];
		aop->phi = ao->phi;
		aop->q = ao->q;
		aop->res = ao->res;
		aop->retval = ao->retval;
		aop->theta = ao->theta;
		aop->var = ao->var;
		aop->vcov = ao->vcov;
	}
	void mapsarimaxobject(sarimax_object sobj, sarimaxset* s)
	{
		//sarimaxset* s = (sarimaxset*)malloc(sizeof(struct sarimaxset));
		s->aic = sobj->aic;
		s->D = sobj->D;
		s->d = sobj->d;
		s->exog = sobj->exog;
		s->imean = sobj->imean;
		s->loglik = sobj->loglik;
		s->lvcov = sobj->lvcov;
		s->M = sobj->M;
		s->mean = sobj->mean;
		s->method = sobj->method;
		s->N = sobj->N;
		s->ncoeff = sobj->ncoeff;
		s->Nused = sobj->Nused;
		s->optmethod = sobj->optmethod;
		s->P = sobj->P;
		s->p = sobj->p;
		s->params[0] = sobj->params[0];
		s->PHI = sobj->PHI;
		s->phi = sobj->phi;
		s->Q = sobj->Q;
		s->q = sobj->q;
		s->r = sobj->r;
		s->res = sobj->res;
		s->retval = sobj->retval;
		s->s = sobj->s;
		s->start = sobj->start;
		s->THETA = sobj->THETA;
		s->theta = sobj->theta;
		s->var = sobj->var;
		s->vcov = sobj->vcov;
	}

	void mapchararray(char* left, char* right, int n)
	{
		for (int i = 0; i < n; i++)
			left[i] = right[i];
	}
}