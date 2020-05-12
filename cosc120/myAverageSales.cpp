#include <iostream>
#include <iomanip>
using namespace std;

float yearlysum(float *ySales, int yNs);
float average(float *aSales, int aNs);

int main()
{
    cout << setprecision(2) << fixed << showpoint;
     int ns;
     float msales, avg, tsales;
     cout << "Please input the number of monthly sales to be input" << endl;
     cin >> ns;
     float *salesarr= new float[ns];
     for(int i=0; i<ns; i++)
     {
         cout << "Please input the sales for month " << i+1 << endl;
         cin >> msales;
         salesarr[i]=msales;
     }
     tsales=yearlysum(salesarr, ns);
     avg=average(salesarr, ns);
     cout << "\nThe total sales for the year is $" << tsales << endl;
     cout << "The average monthly sale is $" << avg << endl;

     return 0;
}
float yearlysum(float *ySales, int yNs)
{
    float total=0;
    for(int i=0; i<yNs; i++)
    {
        total+=ySales[i];
    }
    return total;
}
float average(float *aSales, int aNs)
{
    float average=0;
    for(int i=0; i<aNs;i++)
    {
        average+=aSales[i];
    }
    return average/aNs;
}
