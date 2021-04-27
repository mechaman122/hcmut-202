#include<iostream>
#include<string>
#include<math.h>
#include<limits>
using namespace std;

int main(){
	int NID; //Khoi tao mang ID
	cout << "Nhap so luong phan tu cua ID: ";
	cin >> NID;
	string ID[NID];
	cout << "Nhap cac phan tu: " << endl;
	for(int i = 0; i < NID; i++) cin >> ID[i];
	
	bool vuaexist = false;
	bool thdexist = false;
	
	for(int i = 0; i < NID; i++){
		string lmao = ID[i];
		if(lmao[0] == 'V' && lmao[1] == 'U' && lmao[2] == 'A'){
			vuaexist = true;
			break;
		} 
	}
	if(vuaexist == true) cout << "VUA exists." << endl;
	else cout << "VUA doesn't exist." << endl; 
	
	for(int i = 0; i < NID; i++){
		string haha = ID[i];
		int count = 0;
		for(int j = 0; j < haha.length() - 2; j++){
			if(haha[j] == 'T' && haha[j+1] == 'H' && haha[j+2] == 'D'){
				count = j;
				cout << count << " " << haha.length() << endl;
			}
			if(count > 0 && count < haha.length() - 3){
				thdexist = true;
				break;
			}
		}
	}
	if(thdexist == true) cout << "THD exists." << endl;
	else cout << "THD doesn't exist." << endl; 
	
	int n1; //khoi tao mang input
	cout << "Nhap so luong phan tu cua input: ";
	cin >> n1;
	string input1[n1];
	cout << "Nhap cac phan tu: " << endl;
	cin.ignore();
	
	for(int i = 0; i < n1; i++){
		getline(cin, input1[i]);
	}
	cout << endl;
 
 	for(int i = 0; i < n1; i++){ //xet phan tu, xet tung ki tu
 		string a = input1[i];
 		for(int j = 0; j < a.length() - 1; j++){
 			if(a[j] != ' ' ){
 				 switch (a[j]){
 				 	case '0':{
						break;
					  }
					case '1':{
						if(a[j+1] == '0') a[j+1] = '2';
						else a[j+1] = '3';
						break;
					}
				  }
				 a.erase (j,1); 
				 continue;
			 }
		 }
		 input1[i] = a;
	 }
	 
	 for(int i = 0; i < n1; i++) cout << input1[i] << endl;
	cout << endl;
	
	for(int i = 0; i < n1; i++){
		string hehe = input1[i];
		int count = 1;
		
		for(int j = 0; j < hehe.length() - 1; j++){
			int dec;
			if(hehe[j] == hehe[j+1]) count ++;
			else{
				if(count > 7) count -= 7;
				switch(hehe[j]){
				case '0':{
					dec = 69 - count + 1;
					break;
				}
				case '1':{
					dec = 76 - count + 1;
					break;
				}
				case '2':{
					if(count == 1) dec = 35;
					else dec = 84 - count + 1;
					break;
				}
				case '3':{
					if(count == 1) dec = 64;
					else if(count == 2) dec = 65;
					else if(count == 3) dec = 83;
					else if(count == 4) dec = 90;
					else dec = 66 - count + 1;
					break;
				}
				hehe[j] = char(dec);
				}
				
			}
		}
		cout << hehe << endl; //delete me
	}

	
	
	return 0;
}
