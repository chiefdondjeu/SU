#include <IOstream>
using namespace std;

const int width = 3;
const int length = 8;

int main(){
     int area = width*length;
     int perimeter = (2*width)+(2*length);
     cout <<"The area of the rectangle is " << area << endl;
     cout <<"The perimeter of the rectangle is " << perimeter << endl;

    return 0;
}
