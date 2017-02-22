#include <iostream>
#include <cmath>

using namespace std;



float entropy(int yes1, int no1)
{
    int total = yes1+no1;
    float yes = (float)yes1/total;
    float no = (float)no1/total;


    float ent = (yes * (log2(yes)) + no * (log2(no)));

    cout << ent;

}

float E()
{

}



int main()
{
    //get
    entropy(760, 2040);
}

