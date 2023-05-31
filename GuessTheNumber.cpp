#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>

const int max = 5;

struct player{
	char username[101];
};

void playGame();

void art(){
	printf("\t\t _____                       _____ _            _   _                 _               \n");
	printf("\t\t|  __ \\                     |_   _| |          | \\ | |               | |              \n");
	printf("\t\t| |  \\/_   _  ___  ___ ___    | | | |__   ___  |  \\| |_   _ _ __ ___ | |__   ___ _ __ \n");
	printf("\t\t| | __| | | |/ _ \\/ __/ __|   | | | '_ \\ / _ \\ | . ` | | | | '_ ` _ \\| '_ \\ / _ \\ '__|\n");
	printf("\t\t| |_\\ \\ |_| |  __/\\__ \\__ \\   | | | | | |  __/ | |\\  | |_| | | | | | | |_) |  __/ |   \n");
	printf("\t\t \\____/\\__,_|\\___||___/___/   \\_/ |_| |_|\\___| \\_| \\_/\\__,_|_| |_| |_|_.__/ \\___|_|   \n");
}

int randomizerEasy(){
	int num;
	num = rand() % 100;
	if(num == 0){
		num + 1;
	}
	return num;
}

int randomizerNormal(){
	int num;
	num = rand() % 900 + 100;
	return num;
}

int randomizerHard(){
	int num;
	num = rand() % 9000 + 1000;
	return num;
}

int botRandomizerEasy() {
    int num;
    num = rand() % 100;
    if(num == 0){
		num + 1;
	}
    return num;
}

int botRandomizerNormal(){
	int num;
	num = rand() % 900 + 100;
	return num;
}

int botRandomizerHard(){
	int num;
	num = rand() % 9000 + 1000;
	return num;
}

void setYellow(){
	printf("\033[0;33m");
}

void setBlack(){
	printf("\033[0m"); 	
}

int botGuessingEasy(int botGuess) {
    int newGuess = botRandomizerEasy();

    while (newGuess == botGuess) {
        newGuess = botRandomizerEasy();
    }

    printf("[*] The bot's guess: %d\n", newGuess);
    
    return newGuess;
}

int botGuessingNormal(int botGuess) {
    int newGuess = botRandomizerNormal();

    while (newGuess == botGuess) {
        newGuess = botRandomizerNormal();
    }

    printf("[*] The bot's guess: %d\n", newGuess);
    
    return newGuess;
}

int botGuessingHard(int botGuess) {
    int newGuess = botRandomizerHard();

    while (newGuess == botGuess) {
        newGuess = botRandomizerHard();
    }

    printf("[*] The bot's guess: %d\n", newGuess);
    
    return newGuess;
}

//EasyMode Done
void easyMode(){
    system("cls");
    int choose;
    int guess;
    int random = randomizerEasy();
    int botGuess = botRandomizerEasy();
    int hintsGiven = 0;
    int originalRandom = random; 
    
    while (1){
        system("cls");
        printf("\nThe Number : ");
        int tempRandom = originalRandom;
        

        for (int i = 1; i >= 0; i--) {
            if (hintsGiven > i) {
                int digit = (tempRandom / (int)pow(10, i)) % 10;
                printf("%d", digit);
            } else {
                printf("*");
            }
        }
        
        printf("\n");
        printf("--------------------------\n\n");
        printf("1. Try to Guess\n");
        printf("2. Hint\n");
        printf("What do you want to do? ");
        scanf("%d", &choose);

        switch (choose){
            case 1:
                printf("Enter your guessing number: ");
                scanf("%d", &guess);
                
                if(guess == originalRandom){ 
                    printf("[*] Boom! You guessed the right number. You win!\n");
                    system("pause");
                    system("cls");
                    playGame();
                    return;
                }else{
                    printf("[*] The number is not right. Try Again\n");
                }
                
                botGuess = botGuessingEasy(botGuess);
                
                if(botGuess == originalRandom){  
                    printf("[*] Boom! The bot guessed the right number. You lose!\n");
                    system("pause");
                    system("cls");
                    playGame();
                    return;
                }else{
                    printf("[*] The bot's guess is not right.\n");
                }
                
                system("pause");
                break;
            case 2:
                if(hintsGiven < 1){
                    hintsGiven++;
                    printf("[*] You use hint. Bot can do 2 turn\n");
                    for(int i = 0; i<2; i++){
                        botGuess = botGuessingEasy(botGuess);    
                        if(botGuess == originalRandom){  
                            printf("[*] Boom! The bot guessed the right number. You lose!\n");
                            system("cls");
                            system("pause");
                            playGame();
                            return;
                        }else{
                            printf("[*] The bot's guess is not right.\n");
                        }
                    }
                    system("pause");
                    break;
                }else{
                    printf("[*] No more hints available.\n");
                    system("pause");
                    break;
                }
        }
    }
}

//NormalMode Done
void normalMode() {
    system("cls");
    int choose;
    int guess;
    int random = randomizerNormal();
    int botGuess = botRandomizerNormal();
    int hintsGiven = 0;
    int originalRandom = random;

    while (1) {
        system("cls");
        printf("\nThe Number : ");
        int tempRandom = originalRandom;

        for (int i = 2; i >= 0; i--) {
            if (hintsGiven > i) {
                int digit = (tempRandom / (int)pow(10, i)) % 10;
                printf("%d", digit);
            } else {
                printf("*");
            }
        }

        printf("\n");
        printf("--------------------------\n\n");
        printf("1. Try to Guess\n");
        printf("2. Hint\n");
        printf("What do you want to do? ");
        scanf("%d", &choose);

        switch (choose) {
            case 1:
                printf("Enter your guessing number: ");
                scanf("%d", &guess);

                if (guess == originalRandom) {
                    printf("[*] Boom! You guessed the right number. You win!\n");
                    system("pause");
                    system("cls");
                    playGame();
                    return;
                } else {
                    printf("[*] The number is not right. Try Again\n");
                }

                botGuess = botGuessingNormal(botGuess);

                if (botGuess == originalRandom) {
                    printf("[*] Boom! The bot guessed the right number. You lose!\n");
                    system("pause");
                    system("cls");
                    playGame();
                    return;
                } else {
                    printf("[*] The bot's guess is not right.\n");
                }

                system("pause");
                break;
            case 2:
                if (hintsGiven < 2) {
                    hintsGiven++;
                    printf("[*] You used a hint. The bot can make 3 turns.\n");
                    for (int i = 0; i < 3; i++) {
                        botGuess = botGuessingNormal(botGuess);

                        if (botGuess == originalRandom) {
                            printf("[*] Boom! The bot guessed the right number. You lose!\n");
                            system("pause");
							system("cls");
							playGame();
                            return;
                        } else {
                            printf("[*] The bot's guess is not right.\n");
                        }
                    }
                    system("pause");
                    break;
                } else {
                    printf("[*] No more hints available.\n");
                    system("pause");
                    break;
                }
        }
    }
}

//HardMode Done
void hardMode(){
	system("cls");
    int choose;
    int guess;
    int random = randomizerHard();
    int botGuess = botRandomizerHard();
    int hintsGiven = 0;
    int originalRandom = random; 
    
    while (1){
    	system("cls");
        printf("\nThe Number : ");
        int tempRandom = originalRandom;  
        
        for (int i = 3; i >= 0; i--) {
            if (hintsGiven > i) {
                int digit = (tempRandom / (int)pow(10, i)) % 10;
                printf("%d", digit);
            } else {
                printf("*");
            }
        }
        
        printf("\n");
        printf("--------------------------\n\n");
        printf("1. Try to Guess\n");
        printf("2. Hint\n");
        printf("What do you want to do? ");
        scanf("%d", &choose);

        switch (choose){
            case 1:
                printf("Enter your guessing number: ");
                scanf("%d", &guess);

                if(guess == originalRandom){  
                    printf("[*] Boom! You guessed the right number. You win!\n");
                    system("pause");
                    system("cls");
                    playGame();
                    return;
                }else{
                    printf("[*] The number is not right. Try Again\n");
                }
                
                botGuess = botGuessingHard(botGuess);
                
                if(botGuess == originalRandom){  
                    printf("[*] Boom! The bot guessed the right number. You lose!\n");
                    system("cls");
                    playGame();
                    return;
                }else{
                    printf("[*] The bot's guess is not right.\n");
                }
                
                system("pause");
                break;
            case 2:
                if(hintsGiven < 2){
                    hintsGiven++;
					printf("[*] You use hint. Bot can do 4 turn\n");
                    for(int i = 0; i<4; i++){
                    	botGuess = botGuessingHard(botGuess);	
								
						if(botGuess == originalRandom){  
                    		printf("[*] Boom! The bot guessed the right number. You lose!\n");
                    		system("cls");
                    		system("pause");
                    		playGame();
                    		return;
                		}else{
                    		printf("[*] The bot's guess is not right.\n");
                		}
					}
                    system("pause");
                    break;
                }else{
                    printf("[*] No more hints available.\n");
                    system("pause");
                    break;
                }
        }
    }	
}

void chooseDiff(){
	int idx = 0;
	int selectedIdx = 0;
	
	while(1){
		printf("\033[0;0H");
		printf("\n\n");
		printf("Choose Difficult\n");
		
		if(selectedIdx == 0){
			setYellow();
			printf("Easy\n");
			setBlack();
			printf("Normal\n");
			printf("Hard\n");
		}else if(selectedIdx == 1){
			printf("Easy\n");
			setYellow();
			printf("Normal\n");
			setBlack();
			printf("Hard\n");
		}else if(selectedIdx == 2){
			printf("Easy\n");
			printf("Normal\n");
			setYellow();
			printf("Hard\n");
			setBlack();
		}
		
		idx = getch();
		
		if(idx == 'w' || idx == 'W'){
			selectedIdx = (selectedIdx - 1 + 3) % 3;
		}else if(idx == 's' || idx == 'S'){
			selectedIdx = (selectedIdx + 1) % 3; 
		}else if(idx == '\r'){
			switch(selectedIdx){
				case 0:
					printf("[*] You choose Easy mode [Number range is 00-99]...\n");
					system("pause");
					easyMode();
					return;
					break;
				case 1:
					printf("[*] You choose Normal mode [Number range is 000-999]...\n");
					system("pause");
					normalMode();
					return;
					break;
				case 2:
					printf("[*] You choose Easy mode [Number range is 0000-9999]...\n");
					system("pause");
					hardMode();
					return;
					break;
			}
		}
	}
}

void soloPlayer(){
	system("cls");
	player user;
	
	printf("Enter your username: ");
	scanf("%s", user.username);
	
	chooseDiff();
}

void multiPlayer(){
	system("cls");
	int playercount;
	int playername[max][20];
	int randomnumber;
	int currentPlayer = 0;
	int guess;
	int minRange = 1;
	int maxRange = 100;
	int points[playercount];
	int hintCost;
	int powerCost = 5;
	int choicess;
	int guesses;
	int choosing;
	
	do{
		printf("Enter the number of players (from 2 to %d) : ", max);
		scanf("%d", &playercount); getchar();
		if(playercount <= 1 || playercount > max){
			printf("Invalid numbers of player.\n");
		}
	}while(playercount <= 1 || playercount > max);
	
	for (int i = 0; i < playercount; i++) {
		
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", playername[i]);
    }
    
    printf("Game Starts !!\n");
	
	randomnumber = rand() % 100 + 1;
	srand(time(NULL));
	
	for (int i = 0; i < playercount; i++) {
        points[i] = 0;
    }
	
	while (1) {
        printf("\n%s's turn.\n", playername[currentPlayer]);
        printf("Points: %d\n", points[currentPlayer]);
        do{
        	printf("1. Guess\n");
        	printf("2. Power\n");
        	printf("Do you want to guess or use power? : ");
        	scanf("%d", &choosing);
        }while(choosing < 1 || choosing > 2);
        
        switch(choosing){
        	case 1:
        		printf("Enter your guess number within %d - %d : ", minRange, maxRange);
        		scanf("%d", &guess);
        
        		while(guess <= minRange || guess >= maxRange){
        		printf("Invalid Guess ! Guess number must be between %d - %d : ", minRange, maxRange);
        		scanf("%d", &guess);
				}

        		if (guess == randomnumber) {
            		printf("Boom! You guessed the boom number. You lose!\n\n");
            		system("pause");
            		system("cls");
            		playGame();
            		break;
        		} else if (guess < randomnumber) {
            		minRange = guess;
        		} else {
            		maxRange = guess;
        		}
        
        		if (minRange > maxRange) {
            		printf("Invalid range. No boom number exists in this range. Game over.\n");
            		break;

           			currentPlayer = (currentPlayer + 1) % playercount;

            		printf("Next person's turn.\n");
	
            		continue; 
        		}
        
				points[currentPlayer]++;
				
				currentPlayer = (currentPlayer + 1) % playercount;
        		break;
        	
        	case 2:
        		if(points[currentPlayer] == powerCost){
        			printf("Player %d chooses to use Power.\n", currentPlayer + 1);
        			printf("Skipping Player %d's turn.\n", currentPlayer + 1);
        			system("pause");
        			currentPlayer = (currentPlayer + 1) % playercount;
				}else{
					printf("Points not enough to use power (5 Points)\n");
				}
        		break;
		}
	}
}

void playGame(){
	system("cls");
	int idx = 0;
	int selectedIdx = 0;
	
	while(1){
		printf("\033[0;0H");
		art();
		printf("\n\n");
		
		if(selectedIdx == 0){
			setYellow();
			printf("\t\t\t\t\t\tSolo Player\n");
			setBlack();
			printf("\t\t\t\t\t\tMultiplayer\n");
			printf("\t\t\t\t\t\tBack to Menu\n");
		}else if(selectedIdx == 1){
			printf("\t\t\t\t\t\tSolo Player\n");
			setYellow();
			printf("\t\t\t\t\t\tMultiplayer\n");
			setBlack();
			printf("\t\t\t\t\t\tBack to Menu\n");
		}else if(selectedIdx == 2){
			printf("\t\t\t\t\t\tSolo Player\n");
			printf("\t\t\t\t\t\tMultiplayer\n");
			setYellow();
			printf("\t\t\t\t\t\tBack to Menu\n");
			setBlack();
		}
		
		idx = getch();
		
		if(idx == 'w' || idx == 'W'){
			selectedIdx = (selectedIdx - 1 + 3) % 3;
		}else if(idx == 's' || idx == 'S'){
			selectedIdx = (selectedIdx + 1) % 3; 
		}else if(idx == '\r'){
			switch(selectedIdx){
				case 0:
					soloPlayer();
					return;
					break;
				case 1:
					multiPlayer();
					return;
					break;
				case 2:
					system("cls");
					break;
			}
			
			if(selectedIdx == 2){
				break;
			}
		}
	}
}

void howToPlay(){
	system("cls");
	printf("Single Player game and Multiplayer game is two different games with two different rules.\n\n");
	printf("Single Player Game Rules :\n\n");
	printf(" - There are 3 Mode in this Single Player game which is : Easy, Medium, and Hard.\n");
	printf(" - Every mode got the same rules. The only thing that differs from them is the range of the hidden number.\n");
	printf(" - Rules are simple. You and the bot have each turn to guess the hidden number.\n");
	printf(" - Who can guesses the hidden number first wins the game.\n");
	printf(" - You can use hint to get 1 digit of the hidden number. But you can only use once for the easy mode.\n");
	printf(" - And if you uses hint, the bot will guesses more than 1 time (according to what mode u are playing).\n\n");
	printf("Multiplayer Game Rules :\n\n");
	printf(" - If the Single Player Game need the person to guess the hidden number to win, Multiplayer game is the opposite way.\n");
	printf(" - In Multiplayer Game, the one who guesses the hidden number (BOOM Number) loses !\n");
	printf(" - Rules are also simple. First, everyone who want to play need to input their username. (max 5 players)\n");
	printf(" - Then everyone get each turn to guess a number.\n");
	printf(" - Everytime you guess the number, the range of the hidden number gets smaller.\n");
	printf(" - In Mutiplayer Game, everyone can use power too! and the power is to skip their turn to guess.\n");
	printf(" - But to use the power, you need 5 points. Everytime you guesses and it's not the boom number, you got 1 point.\n\n");
	printf(" - Here is a example :\n\n");
	printf(" - Range of the Boom Number is 1-100. Example : Boom number is 49.\n");
	printf(" - There is only 2 player, First person choose 10.\n");
	printf(" - So the range will get smaller to 10 - 100.\n");
	printf(" - The second player only can choose number between 10 - 100.\n");
	printf(" - More guesses and the range will get smaller.\n");
	printf(" - And at last the boom number will be chosen by a player and that player will lose.\n\n");
}

void scoreBoard(){
	
}

void menu(){
	int idx = 0;
	int selectedIdx = 0;
	
	while(1){
		printf("\033[0;0H");
		art();
		printf("\n\n");
		
		if(selectedIdx == 0){
			setYellow();
			printf("\t\t\t\t\t\tPlay Game\n");
			setBlack();
			printf("\t\t\t\t\t\tHow to Play\n");
			printf("\t\t\t\t\t\tScoreboards\n");
			printf("\t\t\t\t\t\tExit\n");
		}else if(selectedIdx == 1){
			printf("\t\t\t\t\t\tPlay Game\n");
			setYellow();
			printf("\t\t\t\t\t\tHow to Play\n");
			setBlack();
			printf("\t\t\t\t\t\tScoreboards\n");
			printf("\t\t\t\t\t\tExit\n");
		}else if(selectedIdx == 2){
			printf("\t\t\t\t\t\tPlay Game\n");
			printf("\t\t\t\t\t\tHow to Play\n");
			setYellow();
			printf("\t\t\t\t\t\tScoreboards\n");
			setBlack();
			printf("\t\t\t\t\t\tExit\n");
		}else if(selectedIdx == 3){
			printf("\t\t\t\t\t\tPlay Game\n");
			printf("\t\t\t\t\t\tHow to Play\n");
			printf("\t\t\t\t\t\tScoreboards\n");
			setYellow();
			printf("\t\t\t\t\t\tExit\n");
			setBlack();
		}
		
		idx = getch();
		
		if(idx == 'w' || idx == 'W'){
			selectedIdx = (selectedIdx - 1 + 4) % 4;
		}else if(idx == 's' || idx == 'S'){
			selectedIdx = (selectedIdx + 1) % 4;
		}else if(idx == '\r'){
			switch(selectedIdx){
				case 0:
					playGame();
					break;
				case 1:
					howToPlay();
					system("pause");
					system("cls");
					break;
				case 2:
					scoreBoard();
					break;
				case 3:
					break;
			}
			if(selectedIdx == 3){
				break;
			}
		}
	}
}

int main(){
	srand(time(NULL));
	menu();
	return 0;
}
