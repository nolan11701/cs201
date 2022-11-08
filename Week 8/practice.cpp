#include <iostream> 
using namespace std;

struct score {
    int math;
    int language;
};
bool compare(score a, score b)
{
    if (a.math != b.math)
        return a.math>b.math;;
    return (a.language > b.language);
}
int main(){
    score a[3];
    a[0].math = 50;
    a[1].math = 100;
    a[2].math = 20;
    sort(a, a+3, compare);
    
    for(int i = 0; i < 3; i++)
        cout << a[i].math << " " << a[i].language << endl;
}