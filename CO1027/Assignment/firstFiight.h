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
    
    if ((E1 < 100) || (E1 > 500)) {
    	return -999;
	}	else if ((E1 >= 100) && (E1 <= 199)) {   //truong hop 1
        	switch (ID) {
            	case 2: //tong chi huy
            	{
            		M = M;
            		HP = HP;
            		break;
				}
            	case 1:
            	{
                	M = M;
                	HP += 75; 
                	break;
            	}
            	case 0: //ko co chi huy
            	{
                	int h, J;
                	h = (E1 - 100) % 64;
                	J = HP % 100;
                	if (J > h) {
                    	if ((M % 2 == 0) && (M >= 200)) {
                        	 
                        		M -= 200;
                        		HP += 25;
							
                    	} else if ((M % 2 == 1) && (M >= 300)) {
                        	if (HP >= 500){
                        		M -= 300;
                        		HP += 50;
							} else {
								HP = HP;
								M = M;
							}
							
                    	}
                	}
                	break;
            	}
        	}
        	if (HP < 0) {
				HP = 0;
			} else if (HP > 1000) HP = 1000;
			else HP = HP;
        	return (HP + M);
    	} else if ((E1 >= 200) && (E1 <= 299)) {    //truong hop 2
        	int x, y, z;
        	x = (E1 % 4) + 1;
        	y = 190 + (x - 1) * 5;
        	z = 5 + (x - 1) * 2;
        
        	switch (ID) {
            	case 1:	//vua
            	case 2:	//tong chi huy
            	{
                	if (M >= y) {
						M -= y;
                		HP += z;
            		}
                	break;
				}
				case 0: //ko co chi huy
            	{
                	if (((x % 2) == (M % 2)) && (M >= y)){
                    	M -= y;
                    	HP += z;
                	} else {
                		M = M;
                		HP = HP;
					}
            		break;
				}
        	}
        	if (HP < 0) {
				HP = 0;
			} else if (HP > 1000) HP = 1000;
			else HP = HP;
			return (HP + M);  
    	} else if ((E1 >= 300) && (E1 <= 399)) {    //truong hop 3
        	int a, b;
        	b = (E1 % 10);
        
			if ((b == 1) || (b == 2) || (b == 3) || (b == 5) || (b == 7)) {
            	a = 2 * b;
        	} else {a = 1;}
        	if (HP >= 600) { //muon mua thuong thi a phai la so chan
				switch (ID) {
					case 1: //vua khi mua thuong thi hp tang 200
					{
						if ((a != 1) && (M >= 500)) {
							M -= 500;
							HP += 200;
						} else if ((a == 1) && (M >= 300)) {
							M -= 300;
							HP = ceil((double)HP * (1.01 - 0.0001));
						}
					}
					case 2: // tong chi huy
					case 0: // ko co chi huy
					{
						if ((a != 1) && (M >= 500)) {
							M -= 500;
							HP = ceil((double)HP * (1 + (a * 0.01) - 0.00001));
						} else if ((a == 1) && (M >= 300)) {
							M -= 300;
							HP = ceil((double)HP * (1.01 - 0.00001));
						}	
					}
				}
			}
			if (HP < 0) {
				HP = 0;
			} else if (HP > 1000) HP = 1000;
			else HP = HP;
			return (HP + M);
    	} else if ((E1 >= 400) && (E1 <= 499)){		//truong hop 4
			if (E1 % 5 == 0) {
				HP = ceil((double)HP * (0.9 - 0.00001));
			}
			if (HP < 0) {
				HP = 0;
			} else if (HP > 1000) HP = 1000;
			else HP = HP;
			return (HP + M);
		} else {		//truong hop 5
			HP = ceil((double)HP * (0.75 - 0.00001));
			M = ceil((double)M * (0.75 - 0.00001));
			if (HP < 0) {
				HP = 0;
			} else if (HP > 1000) HP = 1000;
			else HP = HP;
			return (HP + M);
		}
		
	}

int fight(int& HP1, int& HP2, const int& ID1, const int& ID2) { //code to calculate HP post-fight
	
	switch (ID1) {
		case 1: 
		{
			if (ID2 == 2) {
				HP1 = HP1;
				HP2 = HP2;
			} else if (ID2 == 0) {
				HP1 = HP1;
				HP2 = 0;
			}
		break;
		}
		case 0:
		{
			if (ID2 == 2) {
				HP1 = 0;
				HP2 = HP2;
			} else if (ID2 == 0) {
				int u;
				u = ceil(2 * double(HP1) * double(HP2)/(double(HP1) + double(HP2)));
				int temp = HP1;
				HP1 = HP1 - abs(HP2 - u);
				HP2 = HP2 - abs(temp - u);
			}
		break;
		}
	}

	if (HP1 < 0) {
		HP1 = 0;
	} else if (HP1 > 1000) HP1 = 1000;
	else HP1 = HP1;
	if (HP2 < 0) {
		HP2 = 0;
	} else if (HP2 > 1000) HP2 = 1000;
	else HP2 = HP2;
	return 0;	
}

int firstBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E2){
    //Complete this function to gain point on task 2
    if ((E2 >= 100) && (E2 <= 199)) {	//truong hop 1
    	HP1 = ceil((double)HP1 * (1.1 - 0.00001));
		HP2 = ceil((double)HP2 * (1.3 - 0.00001));
			
	} else if ((E2 >= 200) && (E2 <= 299)) { //truong hop 2
		HP1 = ceil((double)HP1 * (1.7 - 0.00001));
		HP2 = ceil((double)HP2 * (1.2 - 0.00001));
			
	} else if ((E2 >= 300) && (E2 <= 399)) { //truong hop 3
		if (E2 < 350) HP1 = HP1 + 30;
		else HP1 = HP1 + (E2 % 100);
	
	} else if ((E2 >= 400) && (E2 <= 499)) { //truong hop 4
		HP1 = ceil(double(HP1) * (0.65 - 0.00001));
		HP2 = ceil((double)HP2 * (0.8 - 0.00001));
	}
	
    if ((E2 >= 100) && (E2 <= 499)) fight(HP1, HP2, ID1, ID2);
    else {
    	HP1 = HP1;
    	HP2 = HP2;
	}
    if (HP1 < 0) {
		HP1 = 0;
	} else if (HP1 > 1000) HP1 = 1000;
	else HP1 = HP1;
	if (HP2 < 0) {
		HP2 = 0;
	} else if (HP2 > 1000) HP2 = 1000;
	else HP2 = HP2;
    
	if ((E2 >= 100)&&(E2 <= 499)){
		 HP1 = ceil((double)HP1 * (0.8 - 0.00001));//truong hop 5 luon xay ra
		if (((ID1 == 1) && (ID2 == 2)) || (HP1 == HP2)) return 0;
    	else if (HP1 < HP2) return -1;
    	else return 1;
    	
	} else return -999;
		
}

int secondBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E3){
    //Complete this function to gain point on task 3
    if ((E3 >= 100) && (E3 <= 299)) {
    	HP1 = ceil((double)HP1 * (1.4 - 0.00001));
    	HP2 = ceil((double)HP2 * (1.6 - 0.00001));
    	if(ID1 == 1) HP1 = HP1 * 2;
    	
    	if (ID2 == 2) HP2 = HP2;
    	else HP2 = ceil((double)HP2 * (0.95 - 0.00001));
    	
	}
	if (HP1 < 0) {
		HP1 = 0;
		} else if (HP1 > 1000) HP1 = 1000;
		else HP1 = HP1;
		if (HP2 < 0) {
			HP2 = 0;
		} else if (HP2 > 1000) HP2 = 1000;
		else HP2 = HP2;
    
	if ((E3 >= 100) && (E3 <= 199)) {	//truong hop 1
		int temp = HP1;
		fight(HP1, HP2, ID1, ID2);
		if (((ID1 == 1) && (ID2 == 2)) || (HP1 == HP2)) return 0;
    	else if (HP1 < HP2) {
    		HP1 = temp;
			return -1;	
		}
    	else return 1;
	} else if ((E3 >= 200) && (E3 <= 299)) { //truong hop 2 khong xet do khong co tran danh nao xay ra
		if (HP1 < 0) {
		HP1 = 0;
		} else if (HP1 > 1000) HP1 = 1000;
		else HP1 = HP1;
		if (HP2 < 0) {
			HP2 = 0;
		} else if (HP2 > 1000) HP2 = 1000;
		else HP2 = HP2;
		return 0;
	}
	else return -999;
	
	
}

int finalBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E4){
    //Complete this function to gain point on task 4
    if ((E4 >= 100) && (E4 <= 199)) { //truong hop 1
    	if (ID2 == 0) HP2 = ceil((double)HP2 * (0.1 - 0.00001));
    	else HP2 = ceil((double)HP2 * (0.3 - 0.00001));
    	return 0;
	} else if ((E4 >= 200) && (E4 <= 299)) { //truong hop 2
		HP2 = 0;
		HP1 = HP1;
		return 1;
	} else return -999;
    
}
////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* firstFight_h */
