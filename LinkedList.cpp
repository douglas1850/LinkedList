#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* Link; //addr of Link Link
};

class list
{
    private:
    Node *head, *tail;
    public:
    list()
    {
        head = NULL;
        tail = NULL;
    }

    void createNode(int value)
    {
      Node *temp = new Node;
      temp->data = value; //adding data to new Node object
      temp->Link = NULL;
      if(head == NULL) //if initializing a new list
      {
        head = temp;
        tail = temp;
        temp = NULL;
      }
      else
      {	
        tail->Link = temp; //if head already exists, append new value in List
        tail = temp;
      }
    }

    //display the LL
    void display()
    {
         Node *temp = new Node;
         temp = head;
         while(temp != NULL)
        {
         cout<<temp->data<<"\t";
         temp = temp->Link; //traverse LL until end is reached
         }
    }

    void insert_start(int value)
    {
			Node *temp = new Node; //create temp Node struct
			temp->data = value; //assign it a value
			temp->Link = head; //assign it an addr to Link to (the current head)
			head = temp; //make temp the new head
    }
    //passed position to insert into and the value to insert
    void insert_position(int pos, int value)
    {
        //create prev, cur and temp Node structs
        Node *prev = new Node; 
        Node *cur = new Node;
        Node *temp = new Node;
        cur = head;
        for(int i = 1; i< pos; i++)
        {
            //traverse List, moving prev up to cur and cur to the next
            prev = cur;
            cur = cur->Link;
        }
        temp->data = value;
        prev->Link = temp; //set prev's next Link to temp
        temp->Link = cur; //set temp's next Link to the current one
    }
    void delete_first()
    {
        Node *temp = new Node;
        temp = head;
        head = head->Link;
        delete temp;
    }
    void delete_last()
    {
        Node *current = new Node;
        Node *previous = new Node;
        current = head;
        while(current->Link != NULL)
        {
            //traverse list looking for NULL
            previous = current;
            current = current->Link;	
        }
        tail = previous;
        previous->Link = NULL;
        delete current;
    }
    void delete_position(int pos)
    {
        Node *current = new Node;
        Node *previous = new Node;
        current = head;
        for(int i = 1; i < pos; i++)
        {
            previous = current;
            current = current->Link;
        }
        previous->Link = current->Link;
    }
};

int main()
{
	list obj;
	obj.createNode(10);
	obj.createNode(20);
	obj.createNode(30);
	obj.createNode(40);
    obj.createNode(50);
	cout<<"\n-----------------------------------------------------------\n";
	cout<<"---------------Displaying All Nodes------------------------";
	cout<<"\n-----------------------------------------------------------\n";
	obj.display();
	cout<<"\n-----------------------------------------------------------\n";
	cout<<"-----------------Inserting At End--------------------------";
	cout<<"\n-----------------------------------------------------------\n";
	obj.createNode(60);
	obj.display();
	cout<<"\n-----------------------------------------------------------\n";
	cout<<"----------------Inserting At Start-------------------------";
	cout<<"\n-----------------------------------------------------------\n";
	obj.insert_start(00);
	obj.display();
	cout<<"\n-----------------------------------------------------------\n";
	cout<<"-------------Inserting At Index 4--------------------------";
	cout<<"\n-----------------------------------------------------------\n";
	obj.insert_position(5,35);
	obj.display();
	cout<<"\n-----------------------------------------------------------\n";
	cout<<"----------------Deleting At Start--------------------------";
	cout<<"\n-----------------------------------------------------------\n";
	obj.delete_first();
	obj.display();
	cout<<"\n-----------------------------------------------------------\n";
	cout<<"-----------------Deleing At End----------------------------";
	cout<<"\n-----------------------------------------------------------\n";
	obj.delete_last();
	obj.display();
	cout<<"\n-----------------------------------------------------------\n";
	cout<<"--------------Deleting At Index 4--------------------------";
	cout<<"\n-----------------------------------------------------------\n";
	obj.delete_position(4);
	obj.display();
	cout<<"\n-----------------------------------------------------------\n";
	return 0;
}


