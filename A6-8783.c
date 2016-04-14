//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Constants
#define MIL 10000
//Pre_Processor
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

typedef short int dice;

//Fuction Definition
//Ðñáãìáôïðïéåß ôïõò ôõ÷áßïõò áñéèìïýò
dice dice_roll(){
	return (rand() % 6) + 1;
}

//"Ñß÷íåé" ôá æÜñéá, êáé ìåôñÜåé ôçí óõ÷íüôçôá åìöÜíéóçò
void routine(){
	dice t;
	int freq[6] = { 0 }; // Áñ÷éêïðïßçóç Ðßíáêá 6 èÝóåùí ìå ôçí ôéìÞ 0
	for (int i = 0; i < MIL; ++i){
		t = dice_roll();
		freq[t - 1]++;
		printf("%d ", t);
	}
	printf("\n");
	for (int j = 0; j < 6; ++j){
		printf("Case %d showed up %d times. Frequency: %lf. Percentage: %.2f%% \n", j + 1, freq[j], (double)freq[j] / MIL,
			((double)freq[j] / MIL)*100);
	}
}

//×ôßæåé áðëÜ ôï ðåñéâÜëëïí input/output
void enviroment(){
	printf("******************************\n");
	printf("\tHello Welcome\nDo you want to roll the Dice?\n");
	printf("*******************************\n");
	printf("Option (y or n):");
	char ans;
	do {
		scanf_s("%c", &ans);
	} while (!(ans == 'n' || ans == 'y'));
	if (ans == 'y'){
		system("cls");
		printf("\t \tGet ready for some MatriX effect!!!\n");
		system("pause");
		routine();
	}
	else{
		printf("Goodbye!!!! \n");
	}
}

//Main
int main(void){
	srand((unsigned int)time(NULL));
	/*Ç óõíÜñôçóç srand äÝ÷åôáé ðñáêôéêÜ åíáí unsigned int óáí üñéóìá åíþ ç time() åðéóôñÝöåé áñéèìü ôýðïõ time_t. 
	Ãé'áõôï êáé ç ìåôáôñïðÞ (Possible DATA LOSS) (âë. TYPECASTING)*/
	enviroment();
}
