#include<iostream>
using namespace std;
int main() {
//instead of printing 0 and 1, create an array where 
//0 = False, 1 = True
string TorF[] = { "False", "True" };
int a = 50, b = 6, c = 6;
//Print out the string values of each relational operation
printf("%d < %d is %s.\n", a, b, TorF[a < b].c_str());
printf("%d > %d is %s.\n", a, b, TorF[a > b].c_str());
printf("%d != %d is %s.\n", a, b, TorF[a != b].c_str());
printf("%d >= %d is %s.\n", b, c, TorF[b >= c].c_str());
printf("%d <= %d is %s.\n", b, c, TorF[b <= c].c_str());
return 0;
}