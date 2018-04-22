#include<iostream>
#include<math.h>

using namespace std;

double dq1(double p1);
double dq2(double p2);
double dp1(double q1);
double dp2(double q1, double q2);
double runge_kutta(double h, int N, double p1_in, double p2_in, double q1_in, double q2_in);
void imprimir(double * q1, double * q2, double * p1, double *p2, int N);

int main()
{
	double h=0.006;
	int N=3000/h;
	double a=1.0/(2.0 * pow(2.0 , 0.5 ));
	runge_kutta(h,N,0.0,0.0,a,0.0);
	return 0;
																					
}
double dq1(double p1)
{
	return p1;
}
double dq2(double p2)
{
	return p2;
}
double dp1(double q1)
{
	double eps=0.001;
	double res= ( 2.0*q1 ) / ( pow( ( ( 4.0*q1*q1 ) + ( eps*eps ) ) , 3.0/2.0 ) ) ;
	return res;
}
double dp2(double q1, double q2)
{
	double eps=0.001;
	double res=( ( q1-q2 ) / ( pow( ( ( ( q1-q2 ) * ( q1-q2 ) ) + ( eps*eps/4.0 ) ) , 3.0/2.0 ) ) )- ( ( q1+q2 ) / ( pow( ( ( ( q1+q2 ) * ( q1+q2 ) ) + ( eps*eps/4.0 ) ) , 3.0/2.0 ) ) );
	return res;
}
double runge_kutta(double h, int N, double p1_in, double p2_in, double q1_in, double q2_in)
{
	double * p1 = new double[N];
	double * p2 = new double[N];
	double * q1 = new double[N];
	double * q2 = new double[N];
	
	p1[0]=p1_in;
	p2[0]=p2_in;
	q1[0]=q1_in;
	q2[0]=q2_in;

	double q1k1,q1k2,q1k3,q1k4;
	double q2k1,q2k2,q2k3,q2k4;
	double p1k1,p1k2,p1k3,p1k4;
	double p2k1,p2k2,p2k3,p2k4;

	for(int i=1;i<N;i++)
	{
		q1k1=dq1(p1[i-1]);
		q2k1=dq2(p2[i-1]);
		p1k1=dp1(q1[i-1]);
		p2k1=dp2(q1[i-1],q2[i-1]);

		q1k2=dq1(p1[i-1]+( h/2.0 * q1k1 ));
		q2k2=dq2(p2[i-1]+( h/2.0 * q2k1 ));
		p1k2=dp1(q1[i-1]+( h/2.0 * p1k1 ));
		p2k2=dp2(q1[i-1]+( h/2.0 * p2k1 ),q2[i-1]+( h/2.0 * p2k1 ));

		q1k3=dq1(p1[i-1]+( h/2.0 * q1k2 ));
		q2k3=dq2(p2[i-1]+( h/2.0 * q2k2 ));
		p1k3=dp1(q1[i-1]+( h/2.0 * p1k2 ));
		p2k3=dp2(q1[i-1]+( h/2.0 * p2k2 ),q2[i-1]+( h/2.0 * p2k2 ));
		
		q1k2=dq1(p1[i-1]+( h * q1k3 ));
		q2k2=dq2(p2[i-1]+( h * q2k3 ));
		p1k2=dp1(q1[i-1]+( h * p1k3 ));
		p2k2=dp2(q1[i-1]+( h * p2k3 ),q2[i-1]+( h * p2k3 ));

		q1[i]=q1[i-1] + ( h/6.0 * ( q1k1 + q1k4 + ( 2.0 * ( q1k2 + q1k3 ) ) ) );
		q2[i]=q2[i-1] + ( h/6.0 * ( q2k1 + q2k4 + ( 2.0 * ( q2k2 + q2k3 ) ) ) );
		p1[i]=p1[i-1] + ( h/6.0 * ( p1k1 + p1k4 + ( 2.0 * ( p1k2 + p1k3 ) ) ) );
		p2[i]=p2[i-1] + ( h/6.0 * ( p2k1 + p2k4 + ( 2.0 * ( p2k2 + p2k3 ) ) ) );
	}
	imprimir(q1,q2,p1,p2,N);
}
void imprimir(double * q1, double * q2, double * p1, double *p2, int N)
{
	for(int i=1;i<N;i=i+5000)
	{	
		cout<<q2[i]<<" "<<i*0.006<<endl;/*
		if( ( q1[i-1]>0.0 ) && ( q1[i]<0.0 ) )
		{
			cout<<q2[i]<<" "<<p2[i]<<endl;
		}*/
	}
}
