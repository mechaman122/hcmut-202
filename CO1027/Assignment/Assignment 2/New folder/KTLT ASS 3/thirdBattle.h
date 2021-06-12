//
//  thirdBattle.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//
// Students can remove the final initial return of the functions

#ifndef thirdBattle_h
#define thirdBattle_h

#include "SLLDataController.h"
#include "ArrayDataController.h"
#include <vector>
#include <string>

//////////////////////////////////////////////////////
/// TASK 1
//////////////////////////////////////////////////////

bool push(Array& array, Soldier soldier){
    //Return true if push successfully, false otherwise
    //TODO
	if (array.size == 0) 
    {
        array.arr = new Soldier[1];
        array.arr[0] = soldier;
        array.size++;
        return true;
    }
    else if (array.size > 0) 
    {
        int y = array.size;
        Soldier* temp = new Soldier[y+1];
        for (int i = 0; i < y; i++) 
            temp[i] = array.arr[i];
        delete[] array.arr;
        array.arr = new Soldier[y+1];
        for (int i = 0; i < y; i++)
            array.arr[i] = temp[i];
        array.arr[y] = soldier;
        array.size++;
        delete[] temp;
        return true;
    }
    else  return false;
}

bool pop(Array& array){
    //Return true if pop successfully, false otherwise
    //TODO
    if (array.size == 1)
    {
        delete[] array.arr;
        array.size--;
        return true;
    }
    else if (array.size > 1)
    {
        array.size--;
        Soldier* temp = new Soldier[array.size];
        for (int i = 0; i < array.size; i++)
            temp[i] = array.arr[i];
        delete[] array.arr;
        array.arr = new Soldier[array.size];
        for ( int i = 0; i < array.size; i++)
            array.arr[i] = temp[i];
        delete[] temp;
        return true;
    }
    else return false;
    
}

Soldier top(Array& array){
    //TODO
    if(array.size == 0) return Soldier();
    else return array.arr[array.size-1];//return this if cannot get top
}

//////////////////////////////////////////////////////
/// TASK 2
//////////////////////////////////////////////////////

bool enqueue(SLinkedList& list, Soldier soldier){
    //Return true if enqueue successfully, false otherwise
    //TODO
    bool en = insertAt(list, soldier, 0);
    insertAt(list, soldier, 0);
    return en;
}

bool dequeue(SLinkedList& list){
    //Return true if dequeue successfully, false otherwise
    //TODO
    bool de = removeAt(list, list.size-1);
    removeAt(list, list.size-1);
    return de;
}

Soldier front(SLinkedList& list){
    //TODO
	if(list.size == 0) return Soldier();
    else
	{
		SoldierNode *temp = list.head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		return temp->data;
	}
}

//////////////////////////////////////////////////////
/// TASK 3
//////////////////////////////////////////////////////

void reverse(SLinkedList& list){
    //TODO

    SoldierNode *current = list.head; 
    SoldierNode *prev = NULL, *next = NULL; 
  
    while (current != NULL)
    {
    	next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    list.head = prev;
}

//////////////////////////////////////////////////////
/// TASK 4
//////////////////////////////////////////////////////

SLinkedList merge(SLinkedList& list1, SLinkedList& list2){
    //TODO
	SoldierNode *chain = list1.head;  
	while(chain->next != NULL)
	{
    	chain = chain->next;
  	}
  	chain->next = list2.head;
  	
	int count = list1.size+list2.size;
	
  	Soldier *head = new Soldier[count];
  	SoldierNode *hp = list1.head;
  	int Hp = 0;
  	while(hp != NULL)
  	{
  		if(Hp <= hp->data.HP) Hp = hp->data.HP;
  		hp = hp->next;
	}
  	for(int i = 0; i < count ; i++)
	  head[i] = Soldier(Hp, true, "ZZ");

	for(int i = 0; i < count; i++)
	{
		SoldierNode *temp = list1.head;
		while(temp != NULL)
		{
			if(head[i].HP > temp->data.HP)
				head[i] = temp->data;
			else if(head[i].HP == temp->data.HP)
			{
				if(head[i].isSpecial == false && temp->data.isSpecial == true)
					head[i] = head[i];
				else if(head[i].isSpecial == true && temp->data.isSpecial == false)
					head[i] = temp->data;
				else if(head[i].isSpecial == temp->data.isSpecial)
				{
					int x = head[i].ID.compare(temp->data.ID);
					if(x > 0) head[i] = temp->data;
					else head[i] = head[i];
				}
			}
			temp = temp->next;
		}
		SoldierNode *del = list1.head;
		while(del != NULL)
		{
			if(del->data.HP == head[i].HP && del->data.ID == head[i].ID && del->data.isSpecial == head[i].isSpecial)
			{
				del->data = Soldier(1e6, true, "ZZ");
				break;
			}
			else del = del->next;
		}
	}
	
	SoldierNode *temp1 = list1.head;
	for(int i = 0; i < count; i++)
	{	
		temp1->data = head[i];
		temp1= temp1->next;
	}
	list1.size = count;
	delete[] head;
  	return list1;
	
}

//You can write your own functions here

//End your own functions

#endif /* thirdBattle_h */
