//
//  SLLDataControler.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef SLLDataController_h
#define SLLDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

//Functions used to manage Singly Linked List
void print(SLinkedList& list){
    if (!list.size) {
        std::cout << "List is empty" << endl;
        return;
    }
    SoldierNode* head = list.head;
    while (head){
        std::cout << head->data.ID << "->";
        head = head->next;
    }
    std::cout << "NULL"<<endl;
}



bool insertAt (SLinkedList& list, Soldier element, int pos){
    //Insert element into a pos in the SLL
    //Return true if insert successfully, false otherwise
    //TODO
   	SoldierNode* p = new SoldierNode();
	p->data = element;
	p->next = NULL;	
	
    if(pos < 0 || pos > list.size) return false;
	else if(pos == 0)
    {
		p->next = list.head;
		list.head = p;
		list.size++;
    	return true;
	}
	else if(pos == list.size)
	{
		SoldierNode* temp = list.head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = p;
		list.size++;
		return true;
	}
    else if(pos > 0 && pos < list.size)
	{
	
		int i = 0;
		SoldierNode* temp = list.head;
		while(temp->next != NULL && i != pos-1)
    	{
    		i++;
    		temp = temp->next;
		}
		p->next = temp->next;
		temp->next = p;
		list.size++;
		return true;

	}
	else return false;
}

bool removeAt (SLinkedList& list, int idx){
    //Remove element at index idx in the SLL
    //Return true if remove successfully, false otherwise
    //TODO
    if(list.size == 0) return false;
    else if(idx < 0 || idx >= list.size) return false;
    else
    {
    	SoldierNode* node1 = list.head;
		if(idx == 0)
    	{
    		list.head = list.head->next;
    		delete node1;
    		list.size--;
    		return true;
		}
		else if (idx == list.size-1)
        {
            while (node1->next->next != NULL)
            {
                node1 = node1->next;
            }
            delete node1->next;
            node1->next = NULL;
            list.size--;
            return 1;
        }
		else
		{
			int i = 0;
			while(node1->next != NULL &&  i != idx-1)
			{
				i++;
				node1 = node1->next;
			}
			SoldierNode* node2 = node1->next;
			node1->next = node2->next;
			delete node2;
			list.size--;
			return true;
		}
		
	}
}

bool removeFirstItemWithHP (SLinkedList& list, int HP){
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO
	SoldierNode* node1 = list.head;
    int i = 0;
   	for(int i = 0; i < list.size; i++)
    {
  		if(node1->data.HP == HP)
  		{
  			return removeAt(list, i);	
		}
		else
		{
			node1 = node1->next;
		}
	}
	return false;
}

int indexOf(SLinkedList& list, Soldier soldier){
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    if(list.head != NULL)
    {
    	SoldierNode* temp = list.head;
    	int i = 0;
    	while(temp != NULL)
    	{
    		if(temp->data.HP == soldier.HP && temp->data.ID == soldier.ID && temp->data.isSpecial == soldier.isSpecial)
    		{
    			return i;
    			break;
			}
    		else
    		{
    			i++;
    			temp = temp->next;
			}
		}
	}
    return -1;
    
}

int size(SLinkedList& list){
    //Return size of the list
    //TODO
    return list.size;
}

bool empty(SLinkedList& list){
    //Check whether the list is empty
    //TODO
    if (list.head == NULL)
    	return true;
    else return false;
}

void clear(SLinkedList& list){
    //Delete all of the elements in list
    //TODO
    for(int i = 0; i < list.size; i++)
    {
    	SoldierNode* temp = list.head;
    	list.head = temp->next;
    	delete(temp);
	}
	list.size = 0;
}

string getIDAt(SLinkedList& list, int pos){
    //Get ID of the Soldier at pos
    //TODO
 	if (pos < 0 || pos >= list.size || list.size == 0)
 		return "-1";
 	else
 	{
 		SoldierNode* temp = list.head;
        for (int i = 0; i < pos; i++)
            temp = temp->next;
        return temp->data.ID;	
	}
}

int getHPAt(SLinkedList& list, int pos){
    //Get HP of the Soldier at pos
    //TODO
 	if (pos < 0 || pos >= list.size || list.size == 0)
 		return -1;
 	else
 	{
 		SoldierNode* temp = list.head;
        for (int i = 0; i < pos; i++)
            temp = temp->next;
        return temp->data.HP;	
	}
}

bool setHPAt(SLinkedList& list, int HP, int pos){
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
 	if (pos < 0 || pos >= list.size || list.size == 0)
 		return false;
 	else
 	{
 		SoldierNode* temp = list.head;
        for (int i = 0; i < pos; i++)
            temp = temp->next;
        temp->data.HP = HP;
		return true;	
	}
}

bool contains (SLinkedList& list, Soldier soldier){
    //Check if array contains soldier
    //TODO
    SoldierNode* temp = list.head;
    while (temp != NULL)
    {
        if (temp->data.ID == soldier.ID && temp->data.HP == soldier.HP && temp->data.isSpecial == soldier.isSpecial)
        {
        	return -1;
        	break;
		}
        else temp = temp->next;
    }
    return 0;
}

//You can write your own functions here


//End your own functions

#endif /* SLLDataControler_h */
