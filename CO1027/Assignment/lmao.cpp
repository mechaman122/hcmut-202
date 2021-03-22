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
		int effect = 5 + (x -1) * 5; //tac dung cua mu giap
		
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
		for (int i = 1; i <= 9; i ++) { //tim tinh nguyen to cua unit
			if (unit % i == 0) count += 1;
		}
		
		int a = 0;
		if (count == 2) a = 2 * unit; //tim gia tri cua a
		else a = 1;
		
		if (HP >= 600) { //chi mua khi mau >= 600
			if ((count == 2) && (M >= 500)) { //mua thuong
				if (ID == 1) { //co vua thi cong 200 mau
					HP += 200;
					M -= 500;
				} else { //cac truong hop con lai tinh theo table
					M -= 500;
					HP = ceil((double)HP * (1 + 2 * a * 0.01 - 0.0001));
				}
			} else if ((count != 2) && (M >= 300)) { //mua dao
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
	int u = ceil(((2 * (double)HP1 * (double)HP2) / (HP1 + HP2)) - 0.0001); //tinh trung binh dieu hoa
	int temp = HP1; //cho 1 bien giu gia tri cua HP1
	
	switch (ID1) {
		case 0: {
			if (ID2 == 0) { //ca 2 ben khong co nguoi chi huy
				HP1 = HP1 - abs(HP2 - u); //tinh toan sat thuong
				HP2 = HP2 - abs(temp - u); 
			} else HP1 = 0; //khong co vua, co tong chi huy
			break;	
		}
		case 1: {
			if (ID2 == 0) { //co vua, khong co tong chi huy
				HP2 = 0;
			} //ca 2 ben co nguoi chi huy khong xet
			break;
		}
	}
	if (HP1 > 1000) HP1 = 1000; //reset HP neu can thiet
	else if (HP1 < 0) HP1 = 0;
	else HP1 = HP1;
	if (HP2 > 1000) HP2 = 1000;
	else if (HP2 < 0) HP2 = 0;
	else HP2 = HP2;
}

int result(int& HP1, int& HP2, const int& ID1, const int& ID2) { //ham tra ket qua sau chien dau
	switch(ID1) {
		case 0: {
			if(ID2 == 0) {
				if (HP1 < HP2) return -1;
				else if(HP1 == HP2) return 0;
				else return 1;
			} else return -1;
			break;
		}
		case 1: {
			if (ID2 == 0) return 1;
			else return 0;
			break;
		}
	}
}

int firstBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E2){
    //Complete this function to gain point on task 2
    return -1;
}

int secondBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E3){
    //Complete this function to gain point on task 3
    return -1;
}

int finalBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E4){
    //Complete this function to gain point on task 4
    return -1;
}
////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* firstFight_h */
