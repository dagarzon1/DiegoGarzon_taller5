#include<iostream>
#include<math.h>
#include<string.h>

using namespace std;

int main(int argc, char ** argv)
{
	double L=5E-2;
	double l=2E-2;
	double d=1E-2;
	double h=5.0/512.0 * 0.01;
	int n=L/h;
	double V_in=100.0;
	int N=2 * n ;
	double ** dvdx=new double*[n];
	double ** dvdy=new double*[n];
	double ** v=new double*[n];
	double ** v_fut= new double*[n];
	for(int i=0;i<n;i++)
	{
		v[i]=new double[n];
		v_fut[i]=new double[n];
		dvdx[i]=new double[n];
		dvdy[i]=new double[n];
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
	double r;
	for(int k=0;k<N;k++)
	{
		for(int j=1;j<n-1;j++)
		{
			for(int i=1;i<n-1;i++)
			{
				r=0.25*( v[j][i+1] + v_fut[j][i-1] + v[j+1][i] + v_fut[j-1][i] ) - v[j][i];
				v_fut[j][i]= v[j][i] + 1.2*r;
			}
		}
		
	}
	for(int j=1;j<n-1;j++)
	{
		for(int i=1;i<n-1;i++)
		{
			dvdx[j][i]=v_fut[j][i]-( 0.5*( v_fut[j][i+1] + v_fut[j][i-1] ) );
			dvdy[j][i]=v_fut[j][i]-( 0.5*( v_fut[j+1][i] + v_fut[j-1][i] ) );
		}
	}
		

	if(strcmp(argv[0],"vo")==0)
	{
		for(int j=0;j<n;j++)
		{
			for(int i=0;i<n;i++)
			{
				cout<<v_fut[j][i]<<" ";
			}
			cout<<endl;
		}
	}
	if(strcmp(argv[0],"vx")==0)
	{
		for(int j=0;j<n;j++)
		{
			for(int i=0;i<n;i++)
			{
				cout<<dvdx[j][i]<<" ";
			}
			cout<<endl;
		}
	}
	else
	{	
		for(int j=0;j<n;j++)
		{
			for(int i=0;i<n;i++)
			{
				cout<<dvdy[j][i]<<" ";
				
			}
			cout<<endl;
		}
	}
	return 0;
}
