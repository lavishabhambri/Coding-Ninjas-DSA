/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.
Input format :
A numeric string S
Output Format :
All possible codes in different lines
Constraints :
1 <= Length of String S <= 10
Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
*/

#include <string.h>
using namespace std;

int asciiToInt(char a){
    return a-'0';
}

char intToAscii(int k){
    return 'a'+k-1;
}

void helper(string input, string output){
    if(input.size()==0){
        cout<<output<<endl;
        return;
    }
    
    
    char x=intToAscii(asciiToInt(input[0]));
    helper(input.substr(1), output+x);
    int z= ((asciiToInt(input[0]))*10) + asciiToInt(input[1]);
    char y= intToAscii(z);
    if(z>=10 && z<=26){
        if(input.size()==0){
            output+=y;
        }
        else{
            helper(input.substr(2), output+y);
        }
    	
	}
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    helper(input, "");
}

