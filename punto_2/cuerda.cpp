#include<iostream>
#include<math.h>

using namespace std;

int main()
{
  double c=pow( 1.0/4.0 , 0.5 );
  int Nx=500;
  double dx=0.2;
  double dt=dx/c;
  double L=100;
  int Nt=200/dt;
  double * u_initial = new double[Nx];
  double * u= new double[Nx];
  double x=0.0;
  for(int i=0;i<Nx;i++)
  {
    x=i*dx;
    if(x<=(0.8*L))
	{
		u_initial[i]=1.25*x/L;
	}
    else
	{
		u_initial[i]=5.0-( 5.0 * x )/L;
		//cout<<x<<endl;
	}
  }
  double ** u_save = new double*[Nt];
  for(int i=0;i<Nt;i++)
  {
    u_save[i]=new double[Nx];
  }
  double * u_first=new double[Nx];
  for(int i=1;i<Nx-1;i++)
  {
    u_first[i]=u_initial[i]+( (c*c*dt*dt)/( 2.0*dx*dx ) * ( u_initial[i+1] + u_initial[i-1] - ( 2.0 * u_initial[i] ) ) );
  }
  for(int i=0;i<Nx;i++)
  {
    u_save[0][i]=u_initial[i];
    u_save[1][i]=u_first[i];
  }
  for(int j=2;j<Nt;j++)
  {
    for(int i=1;i<Nx-1;i++)
    {
      u[i]=(2.0*u_first[i])-u_initial[i]+ ( ( (c*c*dt*dt)/(dx*dx) ) * ( u_first[i+1] + u_first[i-1] - (2.0 * u_first[i]) ) );
    }
    for(int i=1;i<Nx-1;i++)
    {
      u_initial[i]=u_first[i];
      u_first[i]=u[i];
      u_save[j][i]=u[i];
    }
  }
  //x=0.0;
  for(int i=0;i<Nx;i++)
  {
    //x+=dx;
    //cout<<x<<" ";
    for(int j=0;j<Nt;j++)
    {
      //x+=dx;
      cout<<u_save[j][i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
