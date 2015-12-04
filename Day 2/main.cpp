#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

void main(void)
{
	unsigned int l, w, h;
	unsigned int totallength, templength;
	unsigned int totalribbon, tempribbon;
	ifstream inputfile("input.txt");
	string line;

	l = 0;
	w = 0;
	h = 0;

	totallength = 0;
	templength = 0;
	totalribbon = 0;
	tempribbon = 0;


	if (inputfile.is_open())
	{
		while (getline(inputfile, line))
		{
			sscanf_s(line.c_str(), "%dx%dx%d", &l, &w, &h);

			templength = 2 * l*w + 2 * w*h + 2 * h*l;
			templength += (unsigned int) fmin(fmin(l*w, w*h), h*l);

			tempribbon = (unsigned int) fmin(fmin(2*l+2*w, 2*w+2*h), 2*h+2*l);
			tempribbon += l*w*h;

			totallength += templength;
			totalribbon += tempribbon;
		}
		inputfile.close();

	}
	else
	{
		cout << "Unable to open file";
	}

	cout << "Total paper:\t" << totallength << "\n";
	cout << "Total ribbon:\t" << totalribbon << "\n";

	return;
}