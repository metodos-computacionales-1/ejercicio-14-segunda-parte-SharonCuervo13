#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
//Siguiendo los códigos de la presentación y loes enviados en el correo

double f0(double t, double y0, double y1); 
double f1(double t, double y0, double y1); 
void euler();

const double K=10.0;
const double M = 2;
const double DeltaT = 0.01;



double f0(double t, double y0, double y1)
{
  return y1;
}

double f1(double t, double y0, double y1)
{
  return (-K*y1)/M;
}
void euler()
{
    int cantidad= 50/DeltaT;
    float y1[cantidad], y0[cantidad], t[cantidad];
    y1[0]=1.0;
    y0[0]=1.0;
    
    for (int i = 1; i<cantidad; i++)
    {
        y1[i] = y1[i-1]*DeltaT*f0(y1[i-1],y0[i-1],y1[i-1]);
        y0[i] = y0[i-1]*DeltaT*f1(y1[i-1],y0[i-1],y1[i-1]);
    }
    for (int i = 1; i<cantidad; i++)
    {
        cout << y1[i] << "" << y0[i] << endl;
    }
}
    



int main(void)
{
    euler();
    return 0;
}


