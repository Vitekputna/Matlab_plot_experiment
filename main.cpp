#include "matplot.h"
#include <iostream>
#include <string>
#include <cmath>
#include <string>

using namespace std;

int main()
{	
	m_pEngine = engOpen("null");

	const int arraysize = 1000;
	const double deg2rad = .0174;

	double sinArray[arraysize];
	double degrees[arraysize];

	for (int i = 0; i < arraysize; i++)
	{
		degrees[i] = i;
		sinArray[i] = sqrt(i)*sin(5 * i * deg2rad)/sqrt(arraysize);
	}
	
	figure(m_pEngine);
	//plot(degrees, sinArray, arraysize, m_pEngine);
	animation2D(degrees,sinArray,arraysize,m_pEngine,true);
	system("pause");
	exit(m_pEngine);
}
