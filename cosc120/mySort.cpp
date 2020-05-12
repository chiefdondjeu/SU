#include <iostream>
#include <iomanip>
using namespace std;

void sorts(float *sgrade, int ns);

int main()
{
   // {5, 100, 90, 95, 100, 90}
    int numScore;
    float score;
    float total=0;
    cout << "Please input the number of scores" << endl;
    cin >> numScore;
    float *grades=new float[numScore];
    for(int i=0; i<numScore; i++)
    {
        cout << "Please enter a score" << endl;
        cin >> score;
        grades[i]=score;
        total+=score;
    }
    cout << "The average of the score is " << total/numScore << endl;
    sorts(grades, numScore);
    delete []grades;
    grades=NULL;

    return 0;
}
void sorts(float *sgrade, int ns)
{
    cout << setprecision(2) << fixed << showpoint;
    cout << "\nHere are the scores in ascending order\n";
    bool swap;
    float temp;
    int bottom = ns-1;
    do
    {
        swap = false;
        for(int i=0; i<bottom; i++)
        {
            if(sgrade[i] > sgrade[i+1])
            {
                temp = sgrade[i];
                sgrade[i] = sgrade[i+1];
                sgrade[i+1] = temp;
                swap= true;
            }
        }
        bottom--;
    } while(swap != false);
    for(int j=0; j<ns;j++)
    {
        cout << sgrade[j] << endl;
    }


}
