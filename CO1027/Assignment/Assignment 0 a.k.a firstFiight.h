/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2021
    * Author: Nguyen Thanh Nhan
    * Date: 08.02.2021
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef firstFight_h
#define firstFight_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
int getReady(int& HP, const int& ID, int& M, const int& E1){
    //Complete this function to gain point on task 1
    
	if ((E1 >= 100) && (E1 <= 199)) { //TRUONG HOP 1
    	int h = (E1 - 100) % 64; //tinh toan cho truong hop khong co chi huy
    	int J = HP % 100;
    	
    	switch (ID) {
    		case 0: { //khong co nguoi chi huy
    			if (J > h) {
    				if ((HP >= 500) && (M % 2 == 1) && (M >= 300)) {
    					M -= 300;
    					HP += 50;
					} else if ((M % 2 == 0) && (M >= 200)) {
						M -= 200;
						HP += 25;
					} else {
						M = M;
						HP = HP;
					}
				}
				break;
			}	
			case 1: { //co vua
				M = M;
				HP += 75;
				break;
			}
			case 2: { //co tong chi huy thi khong mua 
				break;
			}
		}
		
		if (HP > 1000) HP = 1000; //reset HP neu can thiet
		else if (HP < 0) HP = 0;
		else HP = HP;
		return (HP + M); //tra ket qua sau khi tinh toan
	}
	else if ((E1 >= 200) && (E1 <= 299)) { //TRUONG HOP 2
		int x = (E1 % 4) + 1; //tim ten cua mu giap can mua
		
		int price = 190 + (x -1) * 5; //gia tien cua mu giap
		int effect = 5 + (x -1) * 2; //tac dung cua mu giap
		
		switch (ID) {
			case 0: { //khong co nguoi chi huy
				if ((M % 2) == (x % 2) && (M >= price)) { //chi mua khi cung le hoac chan va du tien
					M = M - price;
					HP = HP + effect;
				}
				break;
			}
			case 1: { //co vua thi mua thoai mai
				if (M >= price) { //phai co du tien
					M = M - price;
					HP = HP + effect;
				}
				break;
			}
			case 2: { //co tong chi huy cung tuong tu
				if (M >= price) { //phai co du tien
					M = M - price;
					HP = HP + effect;
				}
				break;
			}
		}
	
	if (HP > 1000) HP = 1000; //reset HP neu can thiet
		else if (HP < 0) HP = 0;
		else HP = HP;
		return (HP + M); //tra ket qua sau khi tinh toan	
	}
	else if ((E1 >= 300) && (E1 <= 399)) { //TRUONG HOP 3
		int unit = (E1 % 10); //tim chu so hang don vi cua E3
		
		int count = 0;
    	for(int i = 2; i <= sqrt(unit); i++){
        	if(unit % i == 0){
            	count++;
        	}
    }
		
		int a = 0;
		if (count == 0) a = 2 * unit; //tim gia tri cua a
		else a = 1;
		
		if (HP >= 600) { //chi mua khi mau >= 600
			if ((count == 0) && (M >= 500)) { //mua thuong
				if (ID == 1) { //co vua thi cong 200 mau
					HP += 200;
					M -= 500;
				} else if ((M >= 500)) { //cac truong hop con lai tinh theo table
					M -= 500;
					HP = ceil((double)HP * (1 + 2 * a * 0.01 - 0.0001));
				}
			} else if (((unit < 2) || (count > 0)) && (M >= 300)) { //mua dao
				M -= 300;
				HP = ceil((double)HP * (1 + a * 0.01 - 0.0001));
			} else {
				HP = HP;
				M = M;
			}
		}
		
		if (HP > 1000) HP = 1000; //reset HP neu can thiet
		else if (HP < 0) HP = 0;
		else HP = HP;
		return (HP + M); //tra ket qua sau khi tinh toan
	}
	else if ((E1 >= 400) && (E1 <= 499)) { //TRUONG HOP 4
		if (E1 % 5 == 0) { //tru 10% hp khi E1 chia het cho 5
			HP = ceil((double)HP * (0.9 - 0.0001));
		}
		
		return (HP + M); //tra ket qua sau khi tinh toan
	}
	else if (E1 == 500) { //TRUONG HOP 5
		HP = ceil((double)HP * (0.75 - 0.0001)); //luon tru 1 phan 4 HP va M
		M = ceil((double)M * (0.75 - 0.0001));
		
		return (HP + M); //tra ket qua sau khi tinh toan
	}
	else return -999; //cac truong hop khong hop le thi tra -999
}

int fight(int& HP1, int& HP2, const int& ID1, const int& ID2) { //ham hinh thuc chien dau 2 ben
	int u = ceil(((2 * (double)HP1 * (double)HP2) / ((double)HP1 + (double)HP2)) - 0.0001); //tinh trung binh dieu hoa
	int temp1 = HP1; 
	int temp2 = HP2;
	int u1 = HP1 - abs(HP2 - u); //tinh toan sat thuong
	int u2 = HP2 - abs(temp1 - u);
	
	switch (ID1) {
		case 0: {
			if (ID2 == 0) {
				HP1 = u1;
				HP2 = u2;
			} else if (ID2 == 2) {
				if (HP1 == HP2) {
					HP1 = temp1;
					HP2 = temp2;
				} else HP1 = 0;
			}
			break;
		}
		case 1: {
			if (ID2 == 0) {
				if (HP1 == HP2) {
					HP1 = temp1;
					HP2 = temp2;
				} else HP2 = 0;
			} else if (ID2 == 2) {
				HP1 = temp1;
				HP2 = temp2;
			}
			break;
		}
		
	}
	

	
	if (HP1 > 1000) HP1 = 1000; //reset HP neu can thiet
	else if (HP1 < 0) HP1 = 0;
	else HP1 = HP1;
	if (HP2 > 1000) HP2 = 1000;
	else if (HP2 < 0) HP2 = 0;
	else HP2 = HP2;
	return 0;
}

int firstBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E2){
    //Complete this function to gain point on task 2
    
    if ((E2 >= 100) && (E2 <= 199)) { //TRUONG HOP 1
    	HP1 = ceil((double)HP1 * (1.1 - 0.0001)); //HP cua 2 phe deu tang
    	HP2 = ceil((double)HP2 * (1.3 - 0.0001));
    	
		if (HP1 > 1000) HP1 = 1000; //reset HP neu can thiet
		else if (HP1 < 0) HP1 = 0;
		else HP1 = HP1;
		if (HP2 > 1000) HP2 = 1000;
		else if (HP2 < 0) HP2 = 0;
		else HP2 = HP2;
	
		fight(HP1, HP2, ID1, ID2);  //chien dau
	}
	else if ((E2 >= 200) && (E2 <= 299)) { //TRUONG HOP 2
		HP1 = ceil((double)HP1 * (1.7 - 0.0001)); //HP cua 2 phe deu tang
    	HP2 = ceil((double)HP2 * (1.2 - 0.0001));
		
		if (HP1 > 1000) HP1 = 1000; //reset HP neu can thiet
		else if (HP1 < 0) HP1 = 0;
		else HP1 = HP1;
		if (HP2 > 1000) HP2 = 1000;
		else if (HP2 < 0) HP2 = 0;
		else HP2 = HP2;
		
		fight(HP1, HP2, ID1, ID2);  //chien dau
	}
	else if ((E2 >= 300) && (E2 <= 399)) { //TRUONG HOP 3
		if (E2 < 350) HP1 += 30; //tang HP cho quan ta
		else HP1 = HP1 + (E2 % 100);
		
		if (HP1 > 1000) HP1 = 1000; //reset HP neu can thiet
		else if (HP1 < 0) HP1 = 0;
		else HP1 = HP1;
		if (HP2 > 1000) HP2 = 1000;
		else if (HP2 < 0) HP2 = 0;
		else HP2 = HP2;
		
		fight(HP1, HP2, ID1, ID2);  //chien dau
	}
	else if ((E2 >= 400) && (E2 <= 499)) { //TRUONG HOP 4
		HP1 = ceil((double)HP1 * (1.3 - 0.0001)); //HP cua 2 phe deu giam
    	HP2 = ceil((double)HP2 * (0.8 - 0.0001));
    	HP1 = ceil((double)HP1 * (0.5 - 0.0001));
    	
    	if (HP1 > 1000) HP1 = 1000; //reset HP neu can thiet
		else if (HP1 < 0) HP1 = 0;
		else HP1 = HP1;
		if (HP2 > 1000) HP2 = 1000;
		else if (HP2 < 0) HP2 = 0;
		else HP2 = HP2;
    	
    	fight(HP1, HP2, ID1, ID2);  //chien dau	
	} 
	else return -999; //cac truong hop khong hop le thi tra -999
	
	if ((E2 >= 100) && (E2 <= 499)) { //chi giam hp quan ta khi 1 trong 4 TRUONG HOP tren xay ra
		int t = HP1;
		HP1 = ceil((double)HP1 * (0.8 - 0.0001)); 
		if (((ID1 == 1) && (ID2 == 2)) || (t == HP2)) return 0; //tra ket qua
    	else if (((ID1 == 0) && (ID2 == 2)) || (t < HP2)) return -1;
    	else return 1;
	}
	else return -999;
}

int secondBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E3){
    //Complete this function to gain point on task 3
    
    if ((E3 >= 100) && (E3 <= 299)) {
    	HP1 = ceil((double)HP1 * (1.4 - 0.0001)); //HP cua 2 phe deu tang neu hop le
    	HP2 = ceil((double)HP2 * (1.6 - 0.0001));
    	
		if (HP1 > 1000) HP1 = 1000; //reset HP neu can thiet
		else if (HP1 < 0) HP1 = 0;
		else HP1 = HP1;
		if (HP2 > 1000) HP2 = 1000;
		else if (HP2 < 0) HP2 = 0;
		else HP2 = HP2;
    	
		if (ID1 == 1) HP1 = 2 * HP1; //gap doi khi nghe thai su Tran Thu Do noi
	
		if (HP1 > 1000) HP1 = 1000; //reset HP neu can thiet
		else if (HP1 < 0) HP1 = 0;
		else HP1 = HP1;
		if (HP2 > 1000) HP2 = 1000;
		else if (HP2 < 0) HP2 = 0;
		else HP2 = HP2;
	}
	
	
	
	
	if ((E3 >= 100) && (E3 <= 199)) { //TRUONG HOP 1
		int temp = HP1;
		if (ID2 == 0) HP2 = ceil((double)HP2 * (0.95 - 0.0001)); //qua song nen quan Mong bi giam HP neu khong co nguoi chi huy
		
		fight(HP1, HP2, ID1, ID2);  //chien dau va tra ket qua
		if (((ID1 == 1) && (ID2 == 2)) || (HP1 == HP2)) return 0;
    	else if (HP1 < HP2) {
    		HP1 = temp;
    		return -1;
		}
    	else return 1;
 //giu nguyen HP cua quan ta neu thua
	}
	else if ((E3 >= 200) && (E3 <= 299)) { //TRUONG HOP 2
		if (ID2 == 0) HP2 = ceil((double)HP2 * (0.95 - 0.0001)); //qua song nen quan Mong bi giam HP neu khong co nguoi chi huy
		return 0; //khong co tran danh nao xay ra
		
		
	}
	else return -999; //cac truong hop khong hop le thi tra -999
}

int finalBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E4){
    //Complete this function to gain point on task 4
    
    if ((E4 >= 100) && (E4 <= 199)) { //TRUONG HOP 1
    	if (ID2 == 0) HP2 = ceil((double)HP2 * (0.1 - 0.0001)); //HP giam do doi khat benh tat
    	else HP2 = ceil((double)HP2 * (0.3 - 0.0001));
    	return 0; //khong co tran danh nao xay ra
	}
	else if ((E4 >= 200) && (E4 <= 299)) { //TRUONG HOP 2
		HP2 = 0; //quan dich bi danh tan tac
		HP1 = HP1;
		return 1;
	}
	else return -999; //cac truong hop khong hop le thi tra -999
}
////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* firstFight_h */
