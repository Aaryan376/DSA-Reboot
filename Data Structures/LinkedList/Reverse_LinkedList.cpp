#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node* next;
};

Node* insert(Node* head,int value){

   Node* temp = new Node();
   temp->data = value;

   if(head==NULL){
       head=temp;
       temp->next=NULL;
   }
   else{
       Node* ptr = head;

       while(ptr->next!=NULL){
           ptr=ptr->next;
       }
       ptr->next = temp;
       temp->next=NULL;
   }
   return head;
}

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* current = head;
    Node* currentNext;

    while(current!=NULL){
        currentNext=current->next; // used so that we are able to move to next node in ll after links are reversed
        current->next=prev; // reversing the link
        prev=current;   // reassigning the prev pointer to Node
        current = currentNext; // Moving to the nezt node
        
    }
    head = prev;
    return head;
}


void display(Node* head){

     while(head!=NULL){
         cout<<head->data<<" ";
         head=head->next;
     }
     cout<<endl;
}
int main(){

        Node* head = NULL; 
        int n;
        cout<<"Enter the number of nodes you want in the linked list: ";
        cin>>n;
        while(n>0){
            int x;
            cin>>x;

            head = insert(head,x);
            n--;
        }
        display(head);
        
        head = reverse(head);

        display(head);

}