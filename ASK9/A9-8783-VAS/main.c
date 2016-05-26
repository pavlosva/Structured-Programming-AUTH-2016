/*
============================================================================
Name        : A8-8783.c
Author      : Paul Vasileiou
Version     : 1.0.0.0
Subject	    : Structured Programming (2nd Semester)
============================================================================
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Account.h"

#define abs(x) ((x>0)?(x):(-x))
#define FLOAT_ERR 1e-9
#define FILENAME "BANK_RECORDS.txt"
int id_count = 0;
typedef struct account_t account;

void environment();
void CreateNewAccount();
void ShowAllAccounts();
void ShowZeroAccounts();
void ClearDatabase();
int prompt();

int main(){
	ClearDatabase();
	environment();
	int option = prompt();
	while (option >= 1 && option < 4){
		switch (option) {
		case 1:
			CreateNewAccount();
			break;
		case 2:
			ShowAllAccounts();
			break;
		case 3:
			ShowZeroAccounts();
			break;
		case 4:
			break;
		}
		option = prompt();
	}
	return 0;
}

void environment(){
	printf("\tWelcome to International Bank! \n\n");
	printf("Available options: \n1)Add a new Record \n2)Show all Records \n3)Show all \"zero-balance\" accounts \n4)Exit \n");
}

int prompt(){
	int option;
	printf("\nSelect an Option:");
	scanf("%d", &option);
	if (!(option >= 1 && option <= 4)){
		do
		{
			printf("Wrong Option! Try Again!");
			scanf("%d", &option);
		} while (!(option >= 1 && option <= 4));
	}
	return option;
}

void CreateNewAccount(){
	system("cls");
	FILE *file;
	file = fopen(FILENAME, "a");
	if (file == NULL)
	{
		printf("Error opening the file!\n");
		exit(1);
	}

	printf("Create New Accounts: \n");

	account new;
	new.id = ++id_count;
	printf("Enter the Name of the Owner: ");
	scanf("%s", new.name);
	printf("\n");
	printf("Enter the Balance(USE WITH CAUTION): ");
	scanf("%f", &new.balance);

	fprintf(file, "%d\t%s\t%.2f\n", new.id, new.name, new.balance);
	fclose(file);
}

void ShowAllAccounts(){
	system("cls");
	FILE *file;
	file = fopen(FILENAME, "r");
	if (file == NULL)
	{
		printf("Error opening the file!\n");
		exit(1);
	}

	printf("Accounts: \n");

	char SingleLine[155];
	fgets(SingleLine, 155, file);
	while (!feof(file)){
		puts(SingleLine);
		fgets(SingleLine, 155, file);
	}
	fclose(file);

}

void ShowZeroAccounts(){
	system("cls");
	FILE* file;
	file = fopen(FILENAME, "r");
	if (file == NULL)
	{
		printf("Error opening the file!\n");
		exit(1);
	}


	printf("Accounts with Zero Balance: \n");
	char* token[3];
	char SingleLine[155];
	fgets(SingleLine, 155, file);
	while (!feof(file)){
		char *ptr = strtok(SingleLine, " \t");
		int i = 0;
		while (ptr != NULL){
			token[i] = ptr;
			ptr = strtok(NULL, "\t");
			i++;
		}
		float Balance = atof(token[2]);
		if (abs(Balance) < FLOAT_ERR){
			printf("%s: %s\n", token[0], token[1]);
		}
		fgets(SingleLine, 155, file);
	}

	fclose(file);
}

void ClearDatabase(){
	FILE* file = fopen(FILENAME, "w");
	fclose(file);
}
