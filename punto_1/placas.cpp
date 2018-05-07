#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	double L=5E-2;
	double l=2E-2;
	double d=1E-2;
	double h=5.0/512.0 * 0.01;
	int n=L/h;
	double V_in=100.0;
	int N=2 * n * n;
	double ** v=new double*[n];
	double ** v_fut= new double*[n];
	for(int i=0;i<n;i++)
	{
		v[i]=new double[n];
		v_fut[i]=new double[n];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			v[i][j]=0;
			if((i>=154) && (j==154) && (i<=359))
			{
				v[i][j]=-V_in/2.0;
			}
			if((i>=154) && (j==359) && (i<=359))
			{
				v[i][j]=V_in/2.0;
			}
			if((i>154) && (i<359) && (j>154) && (j<359))
			{
				v[i][j]=V_in;
			}
		}
	}
	

	return 0;
}
