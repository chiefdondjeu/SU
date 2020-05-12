#include <iostream>
#include <fstream>
using namespace std;

int MeanValue(int arrM[], int elemsM);
void sortArray(int arrBS[], int elemsBS);
int searchNumb(int arrBs[], int elemsBs, int key);
int main()
{
    int numEl, numLook, mean, index;
    int i=0;
    ifstream infile;
    infile.open("data.txt");
    infile >> numEl;
    infile >> numLook;
    int integerArr[numEl];
    while(!infile.eof())
    {
        infile >> integerArr[i];
        i++;
    }
    int original[numEl];
    for(int i=0; i<numEl; i++)
    {
        original[i]=integerArr[i];
    }

    mean = MeanValue(integerArr, numEl);
    sortArray(integerArr, numEl);
    index = searchNumb(integerArr, numEl, numLook);

    ofstream outfile;
    outfile.open("result.txt");

    outfile << "\nThe size of the array is " << numEl;
    outfile << "\nThe original array order: ";
    for(int i=0; i<numEl; i++)
    {
        outfile << original[i] << " ";
    }
    outfile << "\nThe sorted array: ";
    for(int i=0; i<numEl; i++)
    {
        outfile << integerArr[i] << " ";
    }

    outfile << "\n\nThe number you looked up is: " << numLook << endl;

    if(index == -1)
    {
        outfile << "The number you looked up is not in the array." << endl;
    }
    else
    {
        outfile << "The number is located in index: " << index << endl;
    }
    outfile << "\nThe mean of the data set is: " << mean << endl;

    return 0;
}

int MeanValue(int arrM[], int elemsM)
{
    int total, m;
    total = 0;
    for(int i=0; i<elemsM; i++)
    {
        total+=arrM[i];
    }
    m = total/elemsM;

    return m;
}

void sortArray(int arrBS[], int elemsBS)
{
    bool swap;
    int temp;
    int bottom = elemsBS-1;
    do
    {
        swap = false;
        for(int c = 0; c < bottom; c++)
        {
            if(arrBS[c] > arrBS[c+1])
            {
                temp = arrBS[c];
                arrBS[c] = arrBS[c+1];
                arrBS[c+1] = temp;
                swap = true;
            }
        }
        bottom--;
    } while(swap != false);

}

int searchNumb(int arrBs[], int elemsBs, int key)
{
    int low = 0;
    int high = elemsBs;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(key == arrBs[mid])
        {
            return mid;
        }
        else if(key > arrBs[mid])
        {
            low = mid+1;
        }
        else high = mid-1;
    }

    return -1;
}



