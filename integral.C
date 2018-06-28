double f(double z)
{
	//Declare Function in Terms of z

	double output;
	output = sin(exp(z));
	return output;
}

double macro7(double xLBound, double xUBound)
{
	//Create New Graph

	TGraph *gr1 = new TGraph();

	//Seed Random Number Generator
	
	srand((unsigned)time(NULL));

	//Declare Variables (Integral Calculation)
	
	double underCurve = 0.;
	double totalPts = 0.;
	double posIntegral;

	//Declare Variables (Bounds)

	double fMax = 0.;

	//Find Function Maximum

	fMax = fMax(xLBound, xUBound);

	cout << "The function max is " << fMax << endl;

	//Generate and Test Random Points Within Bounds
	
	for (int i=0;i<1000000;i++)
	{
		double x;
		double y;
		
		x = ((rand()%1000001))/1000000.*(xUBound-xLBound)+xLBound;
		y = ((rand()%1000001))/1000000.*fMax;

		if (y<=f(x))
		{
			if (y>=0)
			{
				gr1->SetPoint(underCurve,x,y);
				underCurve++;
			}
		}

		totalPts++;
	}

	//Calculate Integral and Graph Points Under Curve

	posIntegral = (underCurve/totalPts)*(xUBound-xLBound)*fMax;
	gr1->Draw("P");
	return posIntegral;
}

double macro6(double xLBound, double xUBound)
{
	//Create New Graph

	TGraph *gr2 = new TGraph();

	//Seed Random Number Generator

	srand((unsigned)time(NULL));

	//Declare Variables (Integral Calculation)

	double underCurve = 0;
	double totalPts = 0;
	double negIntegral;

	//Declare Variables (Bounds)

	double fMin = 0;

	//Find Function Minimum

	fMin = fMin(xLBound, xUBound);

	cout << "The function min is " << fMin << endl;

	//Generate and Test Random Points Within Bounds

	for (int i=0;i<1000000;i++)
	{
		double x;
		double y;

		x=((rand()%1000001))/1000000.*(xUBound-xLBound)+xLBound;
		y=((rand()%1000001))/1000000.*fMin;

		if (y>=f(x))
		{
			if (y<=0)
			{
				gr2->SetPoint(underCurve,x,y);
				underCurve++;
			}
		}

		totalPts++;
	}

	//Calculate Integral and Graph Points Above Curve

	negIntegral = (underCurve/totalPts)*(xUBound-xLBound)*fMin;
	gr2->Draw("P");
	return negIntegral;
}

double fMax(double xLBound, double xUBound)
{
	double fMax = 0.;

	//Generate Random x Values and Test Corresponding f(x) Values
	//To Determine Function Maximum

	for (int j=0;j<1000000;j++)
	{
		double a;

		a = ((rand()%1000001))/1000000.*(xUBound-xLBound)+xLBound;
		if (f(a)>fMax)
		{
			fMax=f(a);
		}
	}

	return fMax;
}

double fMin(double xLBound, double xUBound)
{
	double fMin = 0.;

	//Generate Random x Values and Test Corresponding f(x) Values
	//To Determine Function Minimum

	for (int j=0;j<1000000;j++)
	{
		double a;

		a = ((rand()%1000001))/1000000.*(xUBound-xLBound)+xLBound;
		if (f(a)<fMin)
		{
			fMin = f(a);
		}
	}

	return fMin;
}

void macro5()
{
	//Declare Variables
	
	double posInt;
	double negInt;
	double totalInt;
	double xUB, xLB;

	//User Declares Upper and Lower X Bounds

	cout << "Please enter the lower x bound:" << endl;
	cin >> xLB;
	cout << "Please enter the upper x bound:" << endl;
	cin >> xUB;

	//Create Canvas which Includes Whole Graph

	auto c1 = new TCanvas();
	c1->DrawFrame(xLB,fMin(xLB,xUB),xUB,fMax(xLB,xUB));
	
	//Calculate Positive and Negative Integrals Separately
	//And Graph Positive and Negative Components on Same Canvas

	posInt = macro7(xLB, xUB);
	negInt = macro6(xLB, xUB);

	//Calculate Total Integral

	totalInt = posInt + negInt;

	//Return Result to User

	cout << "The integral of the function is " << totalInt << endl;
}
