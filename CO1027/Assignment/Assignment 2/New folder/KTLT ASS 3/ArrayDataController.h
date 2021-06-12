//
//  ArrayDataController.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef ArrayDataController_h
#define ArrayDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

//Functions used to manage Array
void print(Array& array){
    if (!array.size) {
        std::cout << "Array is empty" << endl;
        return;
    }
    std::cout <<"[";
    for(int i=0;i<array.size;i++){
        std::cout << array.arr[i].ID << " ";
    }
    std::cout <<"]" << endl;
}

void initArray (Array& array, int cap){
    //Init a new array with capacity equals to cap
    //TODO
    array.arr = new Soldier[cap];
	array.capacity = cap;
    array.size = 0;	
}

bool insertAt(Array& array, Soldier element, int pos){
    //Insert element into a pos in the array
    //Return true if insert successfully, false otherwise
    //TODO
    if (pos == array.size && array.size < array.capacity)
    {
        array.arr[pos] = element;
        array.size++;
        return true;
    }
    else if (pos >= 0 && pos < array.size && array.size < array.capacity)
    {
        for (int i = array.size-1; i >= 0; i--)
        {  
            if (pos == i)
            {
                array.arr[i+1] = array.arr[i];
                array.arr[i] = element;
                array.size++;
                return 1;
            }
            else array.arr[i+1] = array.arr[i];
        }
    }
    return false;
}

bool removeAt (Array& array, int idx){
    //Remove element at index idx in the array
    //Return true if remove successfully, false otherwise
    //TODO
    if(idx < 0 || idx >= array.size || array.size == 0)
    	return false;
	else
	{
		for(int i = idx; i < array.size-1; i++)
    	{
    		array.arr[i] = array.arr[i+1];
		}
		array.size--;
		return true;
	}
}

bool removeFirstItemWithHP (Array& array, int HP){
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO
    bool found = false;
    for (int i = 0; i < array.size; i++)
    {
        if (HP==array.arr[i].HP)
        {
            found = removeAt(array, i);
            break;
        }
    }
    return found;
    
}

void ensureCapacity(Array& array, int newCap){
    //Extend the capacity of the array
    //TODO
    array.capacity = newCap;
}

int indexOf(Array& array, Soldier soldier){
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    int y = -1;
    for (int i = 0; i < array.size; i++)
    {
        if (array.arr[i].HP == soldier.HP && array.arr[i].ID == soldier.ID  &&  array.arr[i].isSpecial == soldier.isSpecial)
        {
            y = i;
            break;
        }
    }
    return y;
}

int size(Array& array){
    //Return size of the array
    //TODO
    return array.size;
}

bool empty(Array& array){
    //Check whether the array is empty
    //TODO
    if(array.size == 0) 
    	return true;
    else return false;
}

string getIDAt(Array& array, int pos){
    //Get ID of the Soldier at pos
    //TODO
	if(pos >= 0 && pos < array.size)
        return array.arr[pos].ID;
    else return "-1";
}

int getHPAt(Array& array, int pos){
    //Get HP of the Soldier at pos
    //TODO
    if(pos >= 0 && pos < array.size)
        return array.arr[pos].HP;
    else return -1;
}

bool setHPAt(Array& array, int HP, int pos){
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    if(pos >= 0 && pos < array.size)
    {
    	array.arr[pos].HP = HP;
    	return true;
	}
    else return false;
}

void clear(Array& array){
    //Delete all of the elements in array
    //TODO
	array.arr = NULL;
	array.size = 0;
	array.capacity = 0;
	delete[] array.arr;
}

bool contains (Array& array, Soldier soldier){
    //Check if array contains soldier
    //TODO
    for (int i = 0; i < array.size; i++)
    {
        if (soldier.HP == array.arr[i].HP && soldier.ID == array.arr[i].ID && soldier.isSpecial == array.arr[i].isSpecial)
        {
            return true;
        }
    }
    return false;
    
}

//You can write your own functions here

//End your own functions

#endif /* ArrayDataController_h */
