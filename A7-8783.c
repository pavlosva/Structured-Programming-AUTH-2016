//Libraries
#include <stdio.h>
#include <conio.h>

#define _CRT_SECURE_NO_WARNINGS

//Global Variables
char letter[26] = { 0 };
int flag_max = 0, flag_min = 0;

//Function Declaration
void graphCreator();
int max(), min();
void routine();
void to_lower(char*);
void top_bottom(int,int);

//Main
int main(){
	routine();
	system("cls");
	graphCreator();
	top_bottom(max(),min());
	return 0;
}

//Function Definition
void graphCreator(){
	printf("\n");
	printf("________________________RESULTS_________________________\n");
	int i;
	for (i = 0; i < 26; ++i){
		if (letter[i] != 0){
			printf("\t%c:", i + 97);
			int j = 1;
			do{
				++j;
				printf("*");
			} while (j <= letter[i]);
			printf("\n");
		}
	}

}

void to_lower(char* a){
	*a += 32;
}

int max(){
	int max_value = letter[0];
	int i;
	for (i = 0; i < 26; ++i){
		if (letter[i] > max_value){
			max_value = letter[i];
			flag_max = i;
		}
	}
	return max_value;
}

int min(){
	int min_value = letter[0];
	int i;
	for (i = 0; i < 26; ++i){
		if ((letter[i] < min_value)&&letter[i]!=0){
			min_value = letter[i];
			flag_min = i;
		}
	}
	return min_value;
}

void top_bottom(int a,int b){
	printf("\n \tMost frequent: %c; %d time(s)\n\n",flag_max+97,a);
	printf("\tLeast frequent: %c; %d time(s)\n\n",flag_min+97,b);
	printf("_________________________________________________________\n");
}

void routine(){
	char choice;
	printf("Enter a character(!to break): ");
	scanf("%c", &choice);
	while (choice != 33) {
	    if ((choice >= 65 && choice <= 90)||(choice >= 97 && choice <= 122)){
		if (choice >= 65 && choice <= 90){
			to_lower(&choice);
		}
		letter[choice - 97]++;
    }
		scanf("%c", &choice);
	}
}
