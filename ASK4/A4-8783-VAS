/*Programmer VASILEIOU PAVLOS 8783
______ALL RIGHTS RESERVED _________*/

//Libraries
#include <stdio.h>

//Type Change
typedef unsigned int BIT; 

//Global Variables
BIT a, b;

//Function Declaration
BIT sum(BIT, BIT), carry(BIT, BIT), decimal(BIT, BIT);
void input(), result();

//Main
int main(){
	input();
	result();
	return 0;
}

//Function Definition
BIT sum(BIT x, BIT y){
	return x^y;
}

BIT carry(BIT x, BIT y){
	return x*y;
}
BIT decimal(BIT x, BIT y){
	return (x + y * 2);
}

void input(){
	printf("Please give me the first bit: ");
	scanf("%d", &a);
	while (a != 0 && a != 1){
		printf("Not a binary digit! Please enter again: ");
		scanf("%d", &a);
	}
	printf("Please give me the second bit: ");
	scanf("%d", &b);
	while (b != 0 && b != 1){
		printf("Not a binary digit! Please enter again: ");
		scanf("%d", &b);
	}
}

void result(){
	printf("The Sum is %d and the carry is %d. \n", sum(a, b), carry(a, b));
	printf("So the result is %d%d in Binary and %d in Decimal.\n", carry(a, b), sum(a, b), decimal(sum(a, b), carry(a, b)));
}
