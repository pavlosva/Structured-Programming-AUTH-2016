#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Account.h"

#define FILENAME "BANK_RECORDS.txt"
int id_count = 0;
typedef struct account_t account;

void environment();
void CreateNewAccount();
void ShowAllAccounts();
void ShowZeroAccounts();
int prompt();

int main(){
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

	fprintf(file, "%d %s %.2f \n", new.id, new.name, new.balance);
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

	char SingleLine[105];
	while (!feof(file)){
		fgets(SingleLine, 105, file);
		puts(SingleLine);
	}
	
	fclose(file);

}

void ShowZeroAccounts(){
	system("cls");
	FILE *file;
	file = fopen(FILENAME, "r");
	if (file == NULL)
	{
		printf("Error opening the file!\n");
		exit(1);
	}

	fclose(file);
}
