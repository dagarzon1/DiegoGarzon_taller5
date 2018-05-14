#include<iostream>
#include<math.h>

using namespace std;

double dq1(double t, double q1,double q2,double p1,double p2);
double dq2(double t, double q1,double q2,double p1,double p2);
double dp1(double t, double q1,double q2,double p1,double p2);
double dp2(double t, double q1,double q2,double p1,double p2);
double runge_kutta(double h, int N, double p1_in, double p2_in, double q1_in, double q2_in);
void imprimir(double * q1, double * q2, double * p1, double *p2, int N);

int main()
{
	double h=0.006;
	int N=3000/h;
	double a=pow(2.0,0.5)/2.0;
	runge_kutta(h,N,0.0,0.0,a,-a);
	return 0;
																					
}
double dq1(double t, double q1,double q2,double p1,double p2)
{
	return p1;
}
double dq2(double t, double q1,double q2,double p1,double p2)
{
	return p2;
}
double dp1(double t, double q1,double q2,double p1,double p2)
{
	double eps=0.001*0.001;
	double q=q1*q1;
	double res= (-1.0)*( 2.0*q1 ) / ( pow( eps + q * 4.0 , 1.5 ) ) ;
	return res;
}
double dp2(double t, double q1,double q2,double p1,double p2)
{
	double eps=0.001;
	double res=( ( q1-q2 ) / ( pow( ( ( ( q1-q2 ) * ( q1-q2 ) ) + ( eps*eps/4.0 ) ) , 3.0/2.0 ) ) ) - ( ( q1+q2 ) / ( pow( ( ( ( q1+q2 ) * ( q1+q2 ) ) + ( eps*eps/4.0 ) ) , 3.0/2.0 ) ) );
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
	double t;

	for(int i=1;i<N;i++)
	{
		t=h*i;
		q1k1=dq1(t,q1[i-1],q2[i-1],p1[i-1],p2[i-1]);
		q2k1=dq2(t,q1[i-1],q2[i-1],p1[i-1],p2[i-1]);
		p1k1=dp1(t,q1[i-1],q2[i-1],p1[i-1],p2[i-1]);
		p2k1=dp2(t,q1[i-1],q2[i-1],p1[i-1],p2[i-1]);
		
		q1k2=dq1(t + h/2,q1[i-1] + q1k1 * h/2, q2[i-1] + q2k1 * h/2, p1[i-1] + p1k1 * h/2, p2[i-1] + p2k1 * h/2 );
		q2k2=dq2(t + h/2,q1[i-1] + q1k1 * h/2, q2[i-1] + q2k1 * h/2, p1[i-1] + p1k1 * h/2, p2[i-1] + p2k1 * h/2 );
		p1k2=dp1(t + h/2,q1[i-1] + q1k1 * h/2, q2[i-1] + q2k1 * h/2, p1[i-1] + p1k1 * h/2, p2[i-1] + p2k1 * h/2 );
		p2k2=dp2(t + h/2,q1[i-1] + q1k1 * h/2, q2[i-1] + q2k1 * h/2, p1[i-1] + p1k1 * h/2, p2[i-1] + p2k1 * h/2 );

		q1k3=dq1(t + h/2,q1[i-1] + q1k2 * h/2, q2[i-1] + q2k2 * h/2, p1[i-1] + p1k2 * h/2, p2[i-1] + p2k2 * h/2 );
		q2k3=dq2(t + h/2,q1[i-1] + q1k2 * h/2, q2[i-1] + q2k2 * h/2, p1[i-1] + p1k2 * h/2, p2[i-1] + p2k2 * h/2 );
		p1k3=dp1(t + h/2,q1[i-1] + q1k2 * h/2, q2[i-1] + q2k2 * h/2, p1[i-1] + p1k2 * h/2, p2[i-1] + p2k2 * h/2 );
		p2k3=dp2(t + h/2,q1[i-1] + q1k2 * h/2, q2[i-1] + q2k2 * h/2, p1[i-1] + p1k2 * h/2, p2[i-1] + p2k2 * h/2 );

		q1k4=dq1(t + h,q1[i-1] + q1k3 * h,q2[i-1] + q2k3 * h, p1[i-1] + p1k3 * h, p2[i-1] + p2k3 * h);
		q2k4=dq2(t + h,q1[i-1] + q1k3 * h,q2[i-1] + q2k3 * h, p1[i-1] + p1k3 * h, p2[i-1] + p2k3 * h);
		p1k4=dp1(t + h,q1[i-1] + q1k3 * h,q2[i-1] + q2k3 * h, p1[i-1] + p1k3 * h, p2[i-1] + p2k3 * h);
		p2k4=dp2(t + h,q1[i-1] + q1k3 * h,q2[i-1] + q2k3 * h, p1[i-1] + p1k3 * h, p2[i-1] + p2k3 * h);
		
		q1[i]=q1[i-1] + h * (q1k1 + 2*q1k2 + 2*q1k3 + q1k4)/6.0;
		q2[i]=q2[i-1] + h * (q2k1 + 2*q2k2 + 2*q2k3 + q2k4)/6.0;
		p1[i]=p1[i-1] + h * (p1k1 + 2*p1k2 + 2*p1k3 + p1k4)/6.0;
		p2[i]=p2[i-1] + h * (p2k1 + 2*p2k2 + 2*p2k3 + p2k4)/6.0;
	}
	imprimir(q1,q2,p1,p2,N);
}
void imprimir(double * q1, double * q2, double * p1, double *p2, int N)
{
	double t;
	for(int i=1;i<N;i++)
	{	
		if( ( q1[i-1]<0.1 ) && ( q1[i]>0.0 ) )
		{
			cout<<q2[i]<<" "<<p2[i]<<endl;
		}
	}
}
