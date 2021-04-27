#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main(){

 int count =0;
    string A, B;
    cin>> B >> A;
    
	for(int i = 0; i < A.size(); i++){
		string temp = A.substr(i, B.size());
		if(B == temp) count++;
	}
    return count;
}
