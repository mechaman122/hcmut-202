#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main(){

 int count =0;
    string A, B;
    cin>> A >> B; //delete me please
    int lenA = A.length();
    int lenB = B.length();
	cout << lenA << " " << lenB;
	
	int temp[lenB];
	
	int lenTemp = 0;
	temp[0] = 0;
	int z = 1;
	while(z < lenB){
		if(B[z] == B[lenTemp]){
			lenTemp += 1;
			temp[z] = lenTemp;
			z += 1;
		} else{
			if(lenTemp != 0){
				lenTemp = temp[lenTemp-1];
			} else{
				temp[z] = 0;
				z += 1;
			}
		}
	}
	
	int i = 0, j = 0; //tri so cho A va B
	while(i < lenA){
		if(A[i] == B[j]){
			i += 1;
			j += 1;
		}
		
		if(j == lenB){
			count += 1;
			j = temp[j - 1];
		}
		
		else if(i < lenA && A[i] != B[j]){
			if(j != 0) j = temp[j - 1];
			else i += 1;
		}
	}
	for(int i = 0; i < lenB; i++){
		cout << temp[i] << " "; //delete me please
	}
	
	return count;
}
