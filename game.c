#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void playGuesser();
void title();
void playHangman();

void main() {
	title();
}

void title() {
	system("cls");
	int selectionInt = 0;

	printf("Wordie!\n1. Play Word Guesser\n2. Play Hangman\nSelection: ");
	scanf("%d", &selectionInt);

	switch (selectionInt) {
		case 1:
			playGuesser();
			break;
		case 2: 
			playHangman();
			break;
		default: 
			title();
			break;
	}
}

void playGuesser() {
	char wordDict[46][6] ={"brain", "prone", "swans", "drone", "enter","euler",
	"light", "water", "souls", "yearn", "crate", "crane", "fight", "cream",
	"plane", "sight", "prank", "train", "write", "green", "clean", "dream",
	"coals", "frame", "under", "where", "chair", "flare", "right", "hinge",
	"round", "house", "mouse", "shout", "learn", "weigh", "plate", "plain", 
	"force", "crown", "frown", "pound", "owner", "alone", "drain", "earth"};
	//dictionary of words

	char* chosenWord;
	char enteredWord[6], wordLib[6] = "-----";
	int i = 0;
	//declares variables for randomly chosen word, entered word, and for correct chars
	
	srand(time(0));
	chosenWord = wordDict[rand() % 46];

	while (strcmp(enteredWord, chosenWord) != 0 && i < 5) {
		system("cls");
		printf("Round %d/5\n%s\nEnter 5 letter Word: ", i + 1, wordLib);
		scanf("%s", &enteredWord);
		//input prompt

		for (int s = 0; s < 5; s++) {
			if (90 >= enteredWord[s]) {
				enteredWord[s] += 32;
			}
		}
		//converts uppercase entries to lowercase

		if (strlen(enteredWord) != 5) {
			printf("Invalid Input\n");
			system("pause");
		}//checks if input is a valid length
		else{
			for (int j = 0; j < 5; j++) {
				if (enteredWord[j] == chosenWord[j]) {
					wordLib[j] = chosenWord[j];
				}
			}
		}//else it enters correct characters into wordlib
		i++;//increases round num
	}

	if (strcmp(enteredWord, chosenWord) == 0){
		printf("You win\n");
	}
	else {
		printf("You lose, the word was %s\n", chosenWord);
	}
	system("pause");
	title();
}//checks win condition and prints proper output

void playHangman() {
	char wordDict[6][11] = {"gym", "yearn", "euler", "orange", "player", "western"};
	char* chosenWord;
	char enteredLetter, wordLib[11] = "";
	int chancesLeft = 5, isCorrect = 0;
	//declares variables for randomly chosen word, entered word, and for correct chars

	srand(time(0));
	chosenWord = wordDict[rand() % 6];

	for (int i = 0; i < strlen(chosenWord); i++) {
		wordLib[i] = '-';
	}

	while (strcmp(wordLib, chosenWord) != 0 && chancesLeft > 0) {
		system("cls");
		isCorrect = 0;

		printf("Chances Left: %i\n%s\nEnter letter: ", chancesLeft, wordLib);
		scanf("%s", &enteredLetter);
		if (90 >= enteredLetter) {
			enteredLetter += 32;
		}

		for (int j = 0; j < strlen(chosenWord); j++) {
			if (enteredLetter == chosenWord[j]) {
				isCorrect = 1;
				wordLib[j] = enteredLetter;
			}
		}
		if (isCorrect != 1) {
			chancesLeft--;
		}
	}
	if (strcmp(wordLib, chosenWord) == 0) {
		printf("You Win\n");
	}
	else {
		printf("You lose\n");
	}
	system("pause");
	title();
}
