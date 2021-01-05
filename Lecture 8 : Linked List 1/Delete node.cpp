/*
You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'pos'.
Note :
Assume that the Indexing for the linked list always starts from 0.

If the position is greater than or equal to the length of the linked list, you should return the same linked list without any change.
Illustration :
The following images depict how the deletion has been performed.
Image-I :
Alt txt

Image-II :
Alt txt

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the linked list separated by a single space. 

The second line of each test case contains the integer value of 'pos'. It denotes the position in the linked list from where the node has to be deleted.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the resulting linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a separate line.
You don't need to print explicitly, it has been taken care of.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
pos >= 0
Time Limit: 1sec

Where 'N' is the size of the singly linked list.
Sample Input 1 :
1 
3 4 5 2 6 1 9 -1
3
Sample Output 1 :
3 4 5 6 1 9
Sample Input 2 :
2
3 4 5 2 6 1 9 -1
0
10 20 30 40 50 60 -1
7
Sample Output 2 :
4 5 2 6 1 9
10 20 30 40 50 60
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
    Node *temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}

Node *deleteNode(Node *head, int pos)
{
    //Write your code here
    Node *curr=head;
    Node *prev=NULL;
    int count=0; //keeps record of the present index
    
    if(pos==0){  //when we try to delete the 0th index
        head=head->next;
        delete curr;
    	return head;
    }
    
    if(pos>length(head)-1){  //when we try to delete the index out of range
        return head;
    }
    
	while(curr!=NULL && count<=(pos-1)){ //reaching the prev at index=pos-1
        prev=curr;
        curr=curr->next;
        count++;
    }  
    
    if(curr!=NULL){  //this means curr is a valid index as it is not equal to null.So it can be dleted
        prev->next=curr->next;
    	delete curr;
    }
    
    return head;
    
    
}
