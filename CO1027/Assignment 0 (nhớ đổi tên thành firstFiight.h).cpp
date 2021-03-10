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
    
    
    if ((E1 >= 100) && (E1 <= 199)) {   //truong hop 1
        switch (ID) {
            case 2:
            case 1:
            {
                M -= 500;
                HP += 75; 
                break;
            }
            case 0:
            {
                int h, J;
                h = (E1 - 100) % 64;
                J = HP % 100
                if (J > h) {
                    if ((HP >= 500) && (M % 2 == 1) && (M >= 300)) {
                        M -= 300;
                        HP += 50;
                    } else if ((M % 2 == 0) && (M >= 200)) {
                        M -= 200;
                        HP += 25;
                    }
                }
                break;
            }
        }
    } else if ((E1 >= 200) && (E1 <= 299)) {    //truong hop 2
        int x;
        x = E1 % 4 + 1;
        switch (ID) {
            case 1:
            {
                M -= (190 + (x - 1) * 5);
                HP += (5 + (x - 1) * 2);
                break;
            }
            case 2:
            {
                M -= (190 + (x - 1) * 5);
                HP += (5 + (x - 1) * 2);
                break;
            case 0:
            {
                if ((x % 2) != (M1 % 2)) {
                    M -= (190 + (x - 1) * 5);
                    HP += (5 + (x - 1) * 2);
                    break; 
                }
            }
        }  
    } else if ((E1 >= 300) && (E1 <= 399)) {    //truong hop 3
        int a, b;
        b = E1 - 300;
        if ((b == 1) || (b == 2) || (b == 3) || (b == 5) || (b == 7)) {
            a = 2 * b;
        } else {a = 1;}
        if ((ID == 1) && (HP >= 600) && (a != 1)) {
            M -= 500;
            HP += 200;
        } else if (HP >= 600) {
            
        }
    }


    return -1;
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