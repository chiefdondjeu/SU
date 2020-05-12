// Exam2.cpp
// Your name: Florent Dondjeu Tschoufack

#include<iostream>
using namespace std;

/*
GradeCounters structure keeps track of counters for each grade category.
See the exam 2 hand out for the detail of grading scales.
*/
struct GradeCounters{
    int A;
    int B;
    int C;
    int D;
    int F;
};

/*
GradeCounters structure keeps track of the size of the class who took the exam,
a pointer to an array that stores each student's grade, and some basic statistics
of the exam, including exam average, maximum score, minimum score, and a grade counter
that counts the number of As, Bs, Cs, Ds, and Fs.
*/
struct Exam{
    int size;
    float* scores;
    float average;
    float max;
    float min;
    GradeCounters gc;
};


/* pre:  a pointer to an array and the size of the array
 * post: scores read from keyboard and stored in the array.
 */
void readScores(float* scores, int size);


/* pre:  a pointer to an array and the size of the array
 * post: scores (separated by space) are printed to the screen
 */
void printScores (float* scores, int size);


/* pre:  a pointer to an array and the size of the array
 * post: computes and return the average of the scores from the array
 */
float average(float* scores, int size);

/* pre:  a pointer to an array and the size of the array
 * post: computes and return the maximum of the scores from the array
 */
float maximum(float* scores, int size);


/* pre:  a pointer to an array and the size of the array
 * post: computes and return the minumum of the scores from the array
 */
float minimum(float* scores, int size);

/* pre:  a pointer to an array and the size of the array
 * post: computes the number of grade As, Bs, Cs, Ds, and Fs based on the scale:
        A>=90 B>=80, C>=70, D>=60, F<60. Store these counters in a GradeCounters
        structure and return it.
 */
GradeCounters gradeStats(float* scores, int size);


/* pre:  an exam of Exam structure, and a new score
 * post: returns an updated exam with the new score being added into its scores array
*/
Exam addScore(Exam exam, float newScore);


int main() {
   Exam exam2;
   cout << "Enter a sample size of the scores for exam2: " << endl;
   cin >> exam2.size;

   exam2.scores = new float[exam2.size];
   cout << "Enter " << exam2.size << " number of scores " << endl;
   readScores(exam2.scores, exam2.size);

   cout << "Scores entered: " << endl;
   printScores(exam2.scores, exam2.size);

   exam2.average = average(exam2.scores, exam2.size );
   exam2.max = maximum(exam2.scores, exam2.size );
   exam2.min = minimum(exam2.scores, exam2.size );

   exam2.gc = gradeStats(exam2.scores, exam2.size );

   cout << "\nPrinting Exam 2 Stats: " << endl;
   cout << "average: " << exam2.average << endl;
   cout << "max: " << exam2.max<< endl;
   cout << "min: " << exam2.min<< endl;
   cout << "number of A: " << exam2.gc.A << endl;
   cout << "number of B: " << exam2.gc.B << endl;
   cout << "number of C: " << exam2.gc.C << endl;
   cout << "number of D: " << exam2.gc.D << endl;
   cout << "number of F: " << exam2.gc.F << endl;

   cout << "Enter another score " << endl;
   float last;
   cin >> last;

   exam2 = addScore(exam2, last);

   cout << "Scores entered: " << endl;
   printScores(exam2.scores, exam2.size);

   exam2.average = average(exam2.scores, exam2.size );
   exam2.max = maximum(exam2.scores, exam2.size );
   exam2.min = minimum(exam2.scores, exam2.size );

   exam2.gc = gradeStats(exam2.scores, exam2.size );

   cout << "\nRe-Printing Exam 2 Stats: " << endl;
   cout << "average: " << exam2.average << endl;
   cout << "max: " << exam2.max<< endl;
   cout << "min: " << exam2.min<< endl;
   cout << "number of A: " << exam2.gc.A << endl;
   cout << "number of B: " << exam2.gc.B << endl;
   cout << "number of C: " << exam2.gc.C << endl;
   cout << "number of D: " << exam2.gc.D << endl;
   cout << "number of F: " << exam2.gc.F << endl;

   return 0;
 }

void readScores(float* scores, int size)
{
    float grade;
    for(int i=0; i<size; i++)
    {
        cin >> grade;
        scores[i]= grade;
    }

}

void printScores (float* scores, int size)
{
    for(int i=0; i<size; i++)
    {
        cout << scores[i] << " ";
    }
    cout << endl;

}

float average(float* scores, int size)
{
    float avg;
    float sum=0;
    for(int i=0; i<size; i++)
    {
        sum+=scores[i];
    }
    avg=sum/size;

    return avg;
}

float maximum(float* scores, int size)
{
    float hg=scores[0];
    for(int i=1; i<size; i++)
    {
        if(scores[i]>=hg)
        {
            hg=scores[i];
        }
    }

    return hg;
}

float minimum(float* scores, int size)
{
    float lg=scores[0];
    for(int i=1; i<size; i++)
    {
        if(scores[i]<=lg)
        {
            lg=scores[i];
        }
    }

    return lg;
}

GradeCounters gradeStats(float* scores, int size)
{
    GradeCounters counter;
    counter.A=0;
    counter.B=0;
    counter.C=0;
    counter.D=0;
    counter.F=0;
    for(int i=0; i<size; i++)
    {
        if(scores[i]>=90)
        {
            counter.A++;
        }
        if(scores[i]>=80 && scores[i]<90)
        {
            counter.B++;
        }
        if(scores[i]>=70 && scores[i]<80)
        {
            counter.C++;
        }
        if(scores[i]>=60 && scores[i]<70)
        {
            counter.D++;
        }
        if(scores[i]<60)
        {
            counter.F++;
        }
    }

    return counter;
}

Exam addScore(Exam exam, float newScore)
{
    ++exam.size;
    float* temp=new float[exam.size];
    for(int i=0; i<exam.size; i++)
    {
        temp[i]=exam.scores[i];
    }
    temp[exam.size]=newScore;
    delete []exam.scores;
    exam.scores=new float[exam.size];
    for(int i=0; i<exam.size; i++)
    {
        exam.scores[i]=temp[i];
    }
    //exam.scores[exam.size]= newScore;
    delete []temp;
    temp=NULL;

    return exam;
}
