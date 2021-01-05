/*
You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.
 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First and the only line of each test case or query contains the the elements of the singly linked list separated by a single space.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
 Output format :
For each test case, the only line of output that print 'true' if the list is Palindrome or 'false' otherwise.
 Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the singly linked list.
Sample Input 1 :
1
9 2 3 3 2 9 -1
Sample Output 1 :
true
Sample Input 2 :
2
0 2 3 2 5 -1
-1
Sample Output 2 :
false
true
Explanation for the Sample Input 2 :
For the first query, it is pretty intuitive that the the given list is not a palindrome, hence the output is 'false'.

For the second query, the list is empty. An empty list is always a palindrome , hence the output is 'true'.
*/

/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
int length(Node *head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}

Node* reverseLinkedList(Node *head){
    if(head==NULL ||head->next==NULL){
        return head;
    }
    
    Node *prev=NULL;
    Node *curr=head;
    while(curr!=NULL){
        Node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head=prev;
    return head;
}

bool isPalindrome(Node *head)
{
    //Write your code here
	int len=length(head);
    int count=0;
    
    if(len==1||len==0){
        return true;
    }
    Node *head2=NULL;
    Node *temp1=head;
    Node *temp2=NULL;
    while(count<(len/2)-1){
        temp1=temp1->next;
        count++;
    }
    
    if(len%2==0){
        head2=temp1->next;
    }else{
        head2=temp1;
    }
    
    
    head2=reverseLinkedList(head2);
    temp1=head;
    temp2=head2;
    
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data != temp2->data){
            return false;
        }
        else{
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    return true;
     
}
