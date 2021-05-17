//
// Created by Nhan Nguyen on 01/03/2021.
//
#ifndef MONGOL_H
#define MONGOL_H

// The library here is concretely set, students are not allowed to include any other libraries.

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1);
int decode(const string A, const string B);
string findRoute(const string ID[], const int NID, const string input3[]);
string decodeVfunction(const string A, const string B);
string findBetrayals(const string input5[], const int N5);
int attack(const string input6[]);
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix, const int N7);

////////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER HERE
////////////////////////////////////////////////////////////////////////////

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1)
{
    string *temp1 = new string[N1];
    string* temp2 = new string[N1];
    for (int i = 0; i < N1; i++)
    {
        string hcm = input1[i];
        string result;
        int len1 = hcm.length(), j = 0;
        while (j < len1){
            if (hcm[j] != ' '){
                int a = (int)hcm[j] + (int)hcm[j + 1];
                if (a == 98){
                    result += "3";
                }
                if (a == 97 && (int)hcm[j] == 49){
                    result += "2";
                }
                if (a == 97 && (int)hcm[j] == 48){
                    result += "1";
                }
                if (a == 96){
                    result += "0";
                }
                j += 2;
            }
            else{
                result += " ";
                j++;
            }
        }
        temp1[i] = result;
    }
    for (int i = 0; i < N1; i++){
        string hcm = temp1[i];
        int j = 0;
        while (j<hcm.length()){
            int count=1;
            while (hcm[j]==hcm[j+count]){
                count++;
            }
            int r = count / 7;
            count = count - 7 * r;
			switch ((int)hcm[j]){
                case 32:{
                    j++;
                    break;
                }
                case 48:{
                    switch (count){
                    case 1:{
        				temp2[i] +='E';
                        break; }
                    case 2:{
                		temp2[i] += 'F';
                        break; }
                    case 3:{
                    	temp2[i] += 'G';
                        break; }
                    case 4:{
                    	temp2[i] += 'H';
                        break; }
                    case 5:{
                    	temp2[i] += 'I';
                        break; }
                    case 6:{
                    	temp2[i] += 'J';
                        break; }
                    case 7:{
                    	temp2[i] += 'K';
                        break; }
                    }
                    j += count;
                    break;
                }
                case 49:{
                    switch (count){
                    case 1:{
            			temp2[i] += 'L';
                    	break; }
                    case 2:{
                    	temp2[i] += 'M';
                    	break; }
                    case 3:{
                    	temp2[i] += 'N';
                    	break; }
                    case 4:{
                    	temp2[i] += 'O';
                    	break; }
                    case 5:{
                    	temp2[i] += 'P';
                    	break; }
                    case 6:{
                    	temp2[i] += 'Q';
                    	break; }
                    case 7:{
                    	temp2[i] += 'R';
                    	break; }
                    }
                    j += count;
                    break;
                }
                case 50:{
                    switch (count){
                    case 1:{
                    	temp2[i] += '#';
                    	break; }
                    case 2:{
                    	temp2[i] += 'T';
                    	break; }
                    case 3:{
                    	temp2[i] += 'U';
                    	break; }
                    case 4:{
                    	temp2[i] += 'V';
                    	break; }
                    case 5:{
                    	temp2[i] += 'W';
                    	break; }
                    case 6:{
                    	temp2[i] += 'X';
                    	break; }
                    case 7:{
                    	temp2[i] += 'Y';
                    	break; }
                    }
                    j += count;
                    break;
                }
                case 51:{
                    switch (count){
                    case 1:{
                    	temp2[i] += '@';
                    	break; }
                    case 2:{
                    	temp2[i] += 'A';
                    	break; }
                    case 3:{
                    	temp2[i] += 'S';
                    	break; }
                    case 4:{
                    	temp2[i] += 'Z';
                    	break; }
                    case 5:{
                    	temp2[i] += 'B';
                    	break; }
                    case 6:{
                    	temp2[i] += 'C';
                    	break; }
                    case 7:{
                    	temp2[i] += 'D';
                    	break; }
                    }
                    j += count;
                    break;
                }
            }
        }
        for (unsigned int k = 0; k < temp2[i].length(); k++) {
            if (temp2[i][k] == '#' && temp2[i][temp2[i].length()-1] < 90){
                temp2[i] += (char)(temp2[i][temp2[i].length() - 1] + 1);
            }
            else if (temp2[i][k] == '#' && temp2[i][temp2[i].length() - 1] == 90){
                temp2[i] += 'A';
            }
        } 
        int k1 = 0;
        while (k1 < temp2[i].length()){
            int k2 = k1 +1;
            if (temp2[i][k1] == '@'){
                while (temp2[i][k2] != '@' && k2 < temp2[i].length()){
                    k2++;
                }
            }
            for (int j = 0; j < k2 - k1; j++){
                char a = temp2[i][k1 + j];
                temp2[i][k1 + j] = temp2[i][k2 - j];
                temp2[i][k2 - j] = a;
            }
            k1 += k2;
        }
    }
    for (int i = 0; i < N1; i++){
        for (unsigned int j = 0; j < temp2[i].length(); j++){
            if (temp2[i][j]=='@' || temp2[i][j] == '#'){
                temp2[i].erase(j, 1);
            }
        }
    }
    for (int i = 0; i < NID; i++){
        string check = { ID[i][0] ,ID[i][1] ,ID[i][2] };
        if (check == "VUA"){
            for (int j = 0; j < N1; j++){
                for (unsigned int k = 0; k < temp2[j].length(); k += 2){
                    char a = temp2[j][k];
                    temp2[j][k] = temp2[j][temp2[j].length() - 1 - k];
                    temp2[j][temp2[j].length() - 1 - k] = a;
                }
            }
            break;
        }
        for (unsigned int j = 1; j < ID[i].length()-1; j++){
            string check = { ID[i][j] ,ID[i][j+1] ,ID[i][j+2] };
            if (check == "THD"){
                for (int i1 = 0; i1 < N1; i1++){
                    for (unsigned int k = 0; k < temp2[i1].length(); k++){
                        if ((int)temp2[i1][k]%3==0){
                            temp2[i1].erase(k, 1);
                        }
                    }
                    for (unsigned int k = 0; k < temp2[i1].length()-1; k++){
                        char a = temp2[i1][k];
                        if ((int)temp2[i1][k+1]>=(int)a){
                            temp2[i1][k] = temp2[i1][k + 1];
                            temp2[i1][k + 1] = a;
                        }
                    }
                }
            }
            break;
        }
    }
    string end;
    for (int i = 0; i < N1; i++){
        end += temp2[i];
        if (i < N1-1){
            end += ' ';
        }
    }
    return end;
}


int decode(const string A, const string B)
{
    int count =0;
    int lenA = A.length();
    int lenB = B.length();
	
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
	
	int i = 0, j = 0;
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
	return count;
}
string findRoute(const string input3)
{
	int len = input3.length();
    string N = "", B = "", S = "";
	for(int i = 0; i < len; i++){
		if(input3[i] != ' '){
			N += input3[i];
		} else break;
	}
	int lenN = N.length();
	
	for(int i = lenN+1; i < len; i++){
		if(input3[i] != ' '){
			B += input3[i];
		} else break;
	}
	int lenB = B.length();
	
	for(int i = lenN+lenB+2; i < len; i++){
		if(input3[i] != ' '){
			S += input3[i];
		}
	}
	
	int lenS = S.length();
	string S2 = "";
	int numB = stoi(B);
	if(numB > 0){
		while(numB >= lenS){
			numB -= lenS;
		}	
	} else {
		while(abs(numB) >= lenS){
			numB += lenS;
		}
	}
	
	if(numB > 0){
		for(int i = 0; i < lenS; i++){
			if(i+ numB + 1 > lenS){
				S2 += S[i];
			}
		}
		int temp = S2.length();
		for(int i = 0; i < lenS - temp; i++){
			S2 += S[i];
		}
	} else if(numB < 0){
		for(int i = 0; i < lenS; i++){
			if(i + numB >= 0){
				S2 += S[i];
			}
		}
		int temp = S2.length();
		for(int i = 0; i < lenS - temp; i++){
			S2 += S[i];
		}
	} else S2 = S;
	
	int numN = stoi(N);
	for(int i = 0; i < lenS; i++){
		int change = abs(numN - 2 * i);
		while(change >= 4){
			change -= 4;
		}
		switch(S2[i]){
			case 'U':{
				if(change == 0) S2[i] = 'U';
				else if(change == 1) S2[i] = 'D';
				else if(change == 2) S2[i] = 'L';
				else S2[i] = 'R'; 
				break;
			}
			case 'D':{
				if(change == 0) S2[i] = 'D';
				else if(change == 1) S2[i] = 'L';
				else if(change == 2) S2[i] = 'R';
				else S2[i] = 'U'; 
				break;
			}
			case 'L':{
				if(change == 0) S2[i] = 'L';
				else if(change == 1) S2[i] = 'R';
				else if(change == 2) S2[i] = 'U';
				else S2[i] = 'D'; 
				break;
			}
			case 'R':{
				if(change == 0) S2[i] = 'R';
				else if(change == 1) S2[i] = 'U';
				else if(change == 2) S2[i] = 'D';
				else S2[i] = 'L'; 
				break;
			}
		}
	}

	int x = 0, y = 0;
	for(int i = 0; i < lenS; i++){
		switch(S2[i]){
			case 'U':{
				y += 1;
				break;
			}
			case 'D':{
				y -= 1;
				break;
			}
			case 'L':{
				x -= 1;
				break;
			}
			case 'R':{
				x += 1;
				break;
			}
		}
	}
	string cor;
	cor = cor + "(" + to_string(x) + "," + to_string(y) + ")";
	return cor;
}
string decodeVfunction(const string A, const string B)
{
    int a1 = 0, b1 = 0, lenA = A.length(), lenB = B.length();
	for(int i = 0; i < lenA; i++){
		if(A[i] == 'V') a1++;
	}
	for(int i = 0; i < lenB; i++){
		if(B[i] == 'V') b1++;
	}
	int total = a1 * b1;
	string C = "";
	for(int i = 0; i < total; i++){
		C += "V(";
	}
	C += "0";
	for(int i = 0; i < total; i++){
		C += ")";
	}
	return C;
}
string findBetrayals(const string input5[], const int N5)
{
    // tao mang temp luu tru gia tri cua tung nguoi
	int temp[26];
	for(int l = 0; l < 26; l++) temp[l] = 0;
	// xet tung chuoi, xet tung phan tu
	for(int i = 0; i < N5; i++){
		string a = input5[i];
		int lena = a.length();
		for(int j = 0; j < lena; j++){
			for(int m = 65; m <= 90; m++){
				if(m == (int)a[j]) temp[m - 65] += (6 - j);
			}
		}
	}
	string result = "";
	for(int i = 0; i < 3; i++){
		int max = 0;
		for(int j = 0; j < 26; j++){
			if(max < temp[j]) max = temp[j];
		}
		for(int l = 0; l < 26; l++){
			if(temp[l] == max){
				result += (char)(l + 65);
				break;
			} 
		}
		for(int x = 0; x < 26; x++){
			if(temp[x] == max){
				temp[x] = 0;
				break;
			}
		}
	}
	result += "\0";
	return result;
	
}
int attack(const string input6[])
{
    int temp[10]; //mang luu tru so cac so 0 trong phan tu
	for(int i = 0; i < 10; i++) temp[i] = 0;
	for(int i = 0; i < 10; i++){ //xet hang, xet phan tu
		string a = input6[i];
		int lena = a.length();
		for(int j = 0; j < lena; j++){
			if(a[j] == '0') temp[i]++;
		}
	}
	
	for(int i = 0; i < 10; i++){ //xet hang, xet phan tu
		string a = input6[i];
		int lena = a.length();
		for(int j = 0; j < lena; j++){
			if(a[j] == '2') temp[i] = 0; //loai bo cac hang co chua so 2
		}
	}
	
	bool found = false;
	for(int i = 0; i < 10; i++){
		if(temp[i] != 0){
			found = true;
			break;
		}
	}
	
	if(found == false) return -1;
	else {
		int max = 0;
		int place = 0;
		for(int i = 0; i < 10; i++){
			if(max <= temp[i]){
				max = temp[i];
				place = i;
			}
		}
		return place;
	}
}
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k)
{
	return -1;
}

#endif /* MONGOL_H */
