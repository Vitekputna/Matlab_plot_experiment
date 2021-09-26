#pragma once

#include <engine.h>
#include <iostream>

#pragma comment (lib, "libmat.lib")
#pragma comment (lib, "libmx.lib")
#pragma comment (lib, "libmex.lib")
#pragma comment (lib, "libeng.lib")

Engine* m_pEngine;

void plot(double* x, double* y, int x_size, Engine* matlab)
{
	int y_size = x_size;

	mxArray* Y = mxCreateDoubleMatrix(x_size, 1, mxREAL);
	memcpy((void*)mxGetPr(Y), (void*)y, x_size * sizeof(double));
	engPutVariable(matlab, "Y", Y);

	mxArray* X = mxCreateDoubleMatrix(y_size, 1, mxREAL);
	memcpy((void*)mxGetPr(X), (void*)x, y_size * sizeof(double));
	engPutVariable(matlab, "X", X);

	engEvalString(matlab, "plot(X,Y,'-')");
}

void figure(Engine* matlab)
{
	engEvalString(matlab, "figure()");
}

void animation2D(double* x_file, double* y_file, int arraysize, Engine* matlab, bool hold)
{
	mxArray* SIN = mxCreateDoubleMatrix(arraysize, 1, mxREAL);
	memcpy((void*)mxGetPr(SIN), (void*)y_file, sizeof(double) * arraysize);
	engPutVariable(m_pEngine, "sinus", SIN);

	mxArray* DEG = mxCreateDoubleMatrix(arraysize, 1, mxREAL);
	memcpy((void*)mxGetPr(DEG), (void*)x_file, sizeof(double) * arraysize);
	engPutVariable(m_pEngine, "degrees", DEG);

	if (hold)
	{
		//engEvalString(m_pEngine, "figure('units','normalized','outerposition',[0 0 1 1])");
		engEvalString(m_pEngine, "for i = 1:length(degrees),plot(degrees(i),sinus(i),'r.'),ylim([-1 1]),xlim([0 1000]),pause(0.005),hold on,end");
	}
	else
	{
		//engEvalString(m_pEngine, "figure('units','normalized','outerposition',[0 0 1 1])");
		engEvalString(m_pEngine, "for i = 1:length(degrees),plot(degrees(i),sinus(i),'r.'),ylim([-1 1]),xlim([0 1000]),pause(0.005),end");
	}
}

void exit(Engine* matlab)
{
	engEvalString(matlab, "exit");
}
