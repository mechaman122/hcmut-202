#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct SoldierNode{
    SoldierNode(): data(-1), next(NULL) {}
    SoldierNode(int data, SoldierNode* next): data(data), next(next) {}
    
    int data;
    SoldierNode* next;
};
SoldierNode *createLinkedList(int n)
{
  // TO DO
  SoldierNode *head = new SoldierNode();
  cin >> head->data;
  head->next = NULL;
  SoldierNode *haha = head;
  for(int i = 1; i < n; i++)
  {
    SoldierNode *temp = new SoldierNode();
    cin >> temp->data;
    temp->next = NULL;
    haha->next = temp;
    haha = haha->next;
  }
  haha->next = NULL;
  return head;
}

int main(){
	int n, m;
	cin >> n >> m;
	SoldierNode *head1 = createLinkedList(n);
	SoldierNode *head2 = createLinkedList(m);
	
	SoldierNode *temp1 = head1;
	for(int i = 0; i < n; i++)
	{
		cout << temp1->data << "->";
		temp1
		 = temp1->next;
	}
	cout << "NULL" << endl;
	
	SoldierNode *temp2 = head2;
	for(int i = 0; i < m; i++)
	{
		cout << temp2->data << "->";
		temp2 = temp2->next;
	}
	cout << "NULL" << endl;
	cout << endl;
	
	SoldierNode *chain = head1;  
	while(chain->next != NULL)
	{
    	chain = chain->next;
  	}
  	chain->next = head2;
  	
  	SoldierNode *temp11 = head1;
	for(int i = 0; i < n+m; i++)
	{
		cout << temp11->data << "->";
		temp11 = temp11->next;
	}
	cout << "NULL" << endl;
	
	int* arr = new int[n+m];
	for(int i = 0; i < n+m; i++)
	{
		arr[i] = 99;
	}
	
	cout << "Array is: ";
	for(int i = 0; i < n+m; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << endl;
	
	for(int i = 0 ; i < n+m; i++)
	{
		SoldierNode *temp13 = head1;
		while(temp13 != NULL)
		{
			if(arr[i] > temp13->data)
				arr[i] = temp13->data;
			temp13 = temp13->next;
		}
		SoldierNode *del = head1;
		while(del != NULL)
		{
			if(del->data == arr[i])
			{
				del->data = 99;
				break;
			}
			else del = del->next;
		}
		
		SoldierNode *del2 = head1;
		for(int i = 0; i < n+m; i++)
		{
			cout << del2->data << "->";
			del2 = del2->next;
		}
		cout << "NULL" << endl;
		
		cout << "Array is: ";
		for(int i = 0; i < n+m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		cout << endl;
	}
	
	SoldierNode *temp14 = head1;
	for(int i = 0; i < n+m; i++)
	{
		cout << temp14->data << "->";
		temp14 = temp14->next;
	}
	cout << "NULL" << endl;
}
