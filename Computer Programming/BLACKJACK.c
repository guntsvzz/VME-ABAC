#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>					//Used for random
#include <process.h>				//Used for system("cls") command

int k;
int l;
char c1;
char c2;
int n;
int win;
int lose;
int D;
int P;
char i, j;
char p1, p2, p3, p4, d1, d2, d3, d4;
char m = 't';			//CHECK HIT OR STAND
int random_card;
int dealer_total = 0;	//SCORE TOTAL
int player_total = 0;	//SCORE TOTAL

//PART MAIN
void logo();
void gameplay();
void rule();
void exitgame();

//PART GAME
int randcard();
int clubcard();
int diamondcard();
int heartcard();
int spadecard();
int printcard();	
void player();		//Player Game
void dealer();		//Stand
void stant();		//Result Game
void ask();			//Play again

int main()
{
	int dealer_total = player_total = D = P = 0;
	printf("\t#################################################\n");
	printf("\t##                  BLACKJACK                  ##\n");
	printf("\t##     VINCENT MARY SCHOOL OF ENGINEERING      ##\n");
	printf("\t##      Created by TODSAVAD & WACHIRAWIT       ##\n");
	printf("\t#################################################\n");
	printf("						@2018 VIDVA\n");
	logo();
	return 0;
}

void logo()
{
	int i;
	int dealer_total = player_total = D = P = 0;
	printf("\t#################################################\n");
	printf("\n");
	printf("                       -> 1. Start  game <-        \n");
	printf("                       -> 2. How to play <-        \n");
	printf("                       -> 3. Exit   game <-        \n");
	printf("\n");
	printf("\t#################################################\n");
	printf("\n");
	printf("\tSelect your choice : ");
	scanf("%d", &i);
	printf("\n");
	printf("\t#################################################\n");
	while(1) // If invalid choice entered
	{
		if (i !=1 && i !=2 && i !=3)
		{
			printf("\n\tIncorrect Choice. Please Only Select 1, 2 or 3 : ");
			scanf("%d", &i);
			printf("\n");
			printf("\t#################################################\n");
		}
		switch (i)
		{
			case 1:
				system("cls");
				gameplay();
				break;
			case 2:
				system("cls");
				rule();
				break;
			case 3:
				system("cls");
				exitgame();
				break;
		}
	}	
}

void rule()
{
	char ext;
	printf("\n");
	printf("\t#############################################################\n");
	printf("\t#############################################################\n");
	printf("														       \n");
	printf("\t\t\t\tHOW TO PLAY								              \n");
	printf("\t- An Ace can count as either 1 or 11, as explained below.   \n");
	printf("\t- The cards from 2 through 9 are valued at their face value.\n");
	printf("\t- The 10, Jack, Queen, and King are all valued at 10.       \n");
	printf("\t   _______               \t_______                          \n");
	printf("\t   |%c    |               \t|%c    |                        \n", 'C', 'D');
	printf("\t   |  ?  |   : Club card \t|  ?  |   : Diamond card         \n");
	printf("\t   |    %c|               \t|    %c|                        \n", 'C', 'D');
	printf("\t   |_____|               \t|_____|                          \n");
	printf("\t   _______               \t_______                          \n");
	printf("\t   |%c    |               \t|%c    |                        \n", 'H', 'S');
	printf("\t   |  ?  |   : Heart card\t|  ?  |   : Spade card           \n");
	printf("\t   |    %c|               \t|    %c|                        \n", 'H', 'S');
	printf("\t   |_____|               \t|_____|                          \n");
	printf("\t                                                            \n");
	printf("\t  - In game, you must sum your card to less or              \n");
	printf("\t     equal than 21.                                         \n");
	printf("\t                                                            \n");
	printf("\t############################################################\n");
	printf("\n");
	printf("\tWould you like to go the previous screen ? <Y/N> :");
	scanf(" %c", &ext);
	while(2)
	{
		if (ext != 'Y' && ext != 'y' && ext != 'N' && ext != 'n')// If invalid choice entered	
		{	
			printf("\n");
			printf("\t############################################################\n");
			printf("\n");
			printf("\tIncorrect Choice. Please Enter Y for Yes or N for No :");
			scanf(" %c", &ext);
		}
		if ((ext == 'Y') || (ext == 'y')) // If yes, continue. Prints menu.//
		{
			system("cls");
			main();
		}
		if ((ext == 'N') || (ext == 'n')) // If No, exit game
		{
			system("cls");
			exitgame();
		}
	}
}

void exitgame()//TO EXIT GAME
{
	char m = 'r';
	printf("                           # THANK YOU #           \n");
	printf("\n");
	printf("\t#################################################\n");
	printf("\n");
	printf("                           See you again           \n");
	printf("\n");
	printf("\t#################################################\n");
	printf("\n");
	exit(0);
}

int randcard()
{
	srand((unsigned)time(NULL));
	random_card = rand() % 4 + 1;

	if (random_card == 1)
	{
		clubcard();
		l = k;
	}

	if (random_card == 2)
	{
		diamondcard();
		l = k;
	}

	if (random_card == 3)
	{
		heartcard();
		l = k;
	}

	if (random_card == 4)
	{
		spadecard();
		l = k;
	}
	return l;
}

int clubcard()
{
	srand((unsigned)time(NULL));
	k = rand() % 13 + 1;

	return k;
}

int diamondcard()
{
	srand((unsigned)time(NULL));
	k = rand() % 13 + 1;

	k = k + 20;

	return k;
}

int heartcard()
{
	srand((unsigned)time(NULL));
	k = rand() % 13 + 1;

	k = k + 40;

	return k;
}

int spadecard()
{
	srand((unsigned)time(NULL));
	k = rand() % 13 + 1;

	k = k + 60;

	return k;
}

int printcard()
{
	int p = 0;

	randcard();
	p = k;

	if (p == 1 || p == 21 || p == 41 || p == 61)
	{
		if (p == 1)
		{
			c1 = 'C';
			c2 = 'A';

			if (player_total <= 10 || dealer_total <= 10)
			{
				n = 11;
			}
			else
			{
				n = 1;
			}
		}
		if (p == 21)
		{
			c1 = 'D';
			c2 = 'A';

			if (player_total <= 10 || dealer_total <= 10)
			{
				n = 11;
			}
			else
			{
				n = 1;
			}
		}
		if (p == 41)
		{
			c1 = 'H';
			c2 = 'A';

			if (player_total <= 10 || dealer_total <= 10)
			{
				n = 11;
			}
			else
			{
				n = 1;
			}
		}
		if (p == 61)
		{
			c1 = 'S';
			c2 = 'A';

			if (player_total <= 10 || dealer_total <= 10)
			{
				n = 11;
			}
			else
			{
				n = 1;
			}
		}
	}

	if ((p > 1 && p < 10) || (p>21 && p < 30) || (p>41 && p < 50) || (p>61 && p < 70))
	{
		if (p > 1 && p < 10)
		{
			c1 = 'C';
		}
		if (p > 21 && p < 30)
		{
			c1 = 'D';
		}
		if (p > 41 && p < 50)
		{
			c1 = 'H';
		}
		if (p > 61 && p < 70)
		{
			c1 = 'S';
		}
		n = p % 10;
		switch (n)
		{
		case 2:
			c2 = '2';
			break;
		case 3:
			c2 = '3';
			break;
		case 4:
			c2 = '4';
			break;
		case 5:
			c2 = '5';
			break;
		case 6:
			c2 = '6';
			break;
		case 7:
			c2 = '7';
			break;
		case 8:
			c2 = '8';
			break;
		case 9:
			c2 = '9';
			break;
		}
	}

	if (p >= 10 || p >= 30 || p >= 50 || p >= 70)
	{
		if (p == 10 || p == 30 || p == 50 || p == 70)
		{
			if (p == 10)
			{
				c1 = 'C';
				c2 = 'X';
			}
			if (p == 30)
			{
				c1 = 'D';
				c2 = 'X';
			}
			if (p == 50)
			{
				c1 = 'H';
				c2 = 'X';
			}
			if (p == 70)
			{
				c1 = 'S';
				c2 = 'X';
			}
			n = 10;
		}
		if (p == 11 || p == 31 || p == 51 || p == 71)
		{
			if (p == 11)
			{
				c1 = 'C';
				c2 = 'J';
			}
			if (p == 31)
			{
				c1 = 'D';
				c2 = 'J';
			}
			if (p == 51)
			{
				c1 = 'H';
				c2 = 'J';
			}
			if (p == 71)
			{
				c1 = 'S';
				c2 = 'J';
			}
			n = 10;
		}
		if (p == 12 || p == 32 || p == 52 || p == 72)
		{
			if (p == 12)
			{
				c1 = 'C';
				c2 = 'Q';
			}
			if (p == 32)
			{
				c1 = 'D';
				c2 = 'Q';
			}
			if (p == 52)
			{
				c1 = 'H';
				c2 = 'Q';
			}
			if (p == 72)
			{
				c1 = 'S';
				c2 = 'Q';
			}
			n = 10;
		}
		if (p == 13 || p == 33 || p == 53 || p == 73)
		{
			if (p == 13)
			{
				c1 = 'C';
				c2 = 'K';
			}
			if (p == 33)
			{
				c1 = 'D';
				c2 = 'K';
			}
			if (p == 53)
			{
				c1 = 'H';
				c2 = 'K';
			}
			if (p == 73)
			{
				c1 = 'S';
				c2 = 'K';
			}
			n = 10;
		}
	}

	return n;
}
//PART OF PRINTF
void player()
{
	FILE *fpt;
	fpt = fopen("Output.txt", "a");
	printf("     | \n     o-Player-o---------------------------------------------\n");
	while ((c1 == d3) || (c2 == d4))
	{
		printcard();
	}
	player_total = P + n;
	P = player_total;
	p1 = c1;
	p2 = c2;
	while ((c1 == p1) || (c2 == p2))
	{
		printcard();
	}
	player_total = P + n;
	P = player_total;
	p3 = c1;
	p4 = c2;

	printf("     | _______\t_______\n");
	printf("     | |%c    |\t|%c    |\n", p1, p3);
	printf("     | |  %c  |\t|  %c  |\n", p2, p4);
	printf("     | |    %c|\t|    %c|\n", p1, p3);
	printf("     | |_____|\t|_____|\n");

	if (P == 21)
	{
		printf("     |\n     | Player score is %d\n", P);
		printf("     | You win!!!\n");
		fprintf(fpt,"     | You win!!!\n");
		dealer_total = player_total = D = P = 0;
		ask();
	}

	if (P > 21)
	{
		printf("     |\n     | Player score is %d\n", P);
		printf("     | You lose!!!\n");
		fprintf(fpt,"     | You lose!!!\n");
		dealer_total = player_total = D = P = 0;
		ask();
	}

	if (P <= 21)
	{
		printf("     | Would you like to Hit or Stand? <H/S> : ");
		fprintf(fpt,"     | Would you like to Hit or Stand? <H/S> : ");
		scanf(" %c", &m);
		fprintf(fpt," %c\n", m);
		while (3)
		{
			if (m != 'H' && m != 'h' && m != 'S' && m != 's')// If invalid choice entered	
			{
				printf("\n");
				printf("\tIncorrect Choice. Please Enter H for Hit or S for Stand :");
				fprintf(fpt,"\tIncorrect Choice. Please Enter H for Hit or S for Stand :");
				scanf(" %c", &m);
				fprintf(fpt," %c\n", m);
			}
			dealer();
			while (m == 'h' || m == 'H')
			{
				while ((c1 == p3) || (c2 == p4))
				{
					printcard();
				}
				player_total = P + n;
				P = player_total;
				p3 = c1;
				p4 = c2;
				printf("     | _______\n");
				printf("     | |%c    |\n", p3);
				printf("     | |  %c  |\tPlayer score is %d\n", p4, P);
				printf("     | |    %c|\n", p3);
				printf("     | |_____|\n");
				m = 't';
				if (P <= 21)
				{
					printf("     | Would you like to Hit or Stand? <H/S> : ");
					fprintf(fpt,"     | Would you like to Hit or Stand? <H/S> : ");
					scanf(" %c", &m);
					fprintf(fpt," %c\n", m);
				}
				if (P > 21)
				{
					printf("     | You lose!!!\n");
					fprintf(fpt,"     | You lose!!!\n");
					dealer_total = player_total = D = P = 0;
					ask();
				}
			}
		}
	}
}

void gameplay()
{
	printf("\n     o-Dealer-o---------------------------------------------\n");
	printcard();
	dealer_total = D + n;
	D = dealer_total;
	d1 = c1;
	d2 = c2;
	while ((c1 == d1) || (c2 == d2))
	{
		printcard();
	}
	dealer_total = D + n;
	D = dealer_total;
	d3 = c1;
	d4 = c2;
	printf("     | _______\t_______\n");
	printf("     | |?    |\t|%c    |\n", d3);
	printf("     | |  ?  |\t|  %c  |\n", d4);
	printf("     | |    ?|\t|    %c|\n", d3);
	printf("     | |_____|\t|_____|\n");

	m = 't';
	player();
	dealer();
}

void dealer()
{
	FILE*fpt;
	fpt = fopen("Output.txt", "a");
	if (m == 's' || m == 'S')
	{
		if (D == 21)
		{
			printf("     |\n     | Dealer score is %d\n", D);
			printf("     | Dealer win!!!\n");
			fprintf(fpt,"     | Dealer win!!!\n");
			dealer_total = player_total = D = P = 0;
			ask();
		}

		if (D > 21)
		{
			printf("     |\n     | Dealer score is %d\n", D);
			printf("     | Dealer lose!!!\n");
			fprintf(fpt,"     | Dealer lose!!!\n");
			dealer_total = player_total = D = P = 0;
			ask();
		}

		while (D > 18 || D <= 21)
		{
			printcard();
			dealer_total = D + n;
			D = dealer_total;
			printf("     o------------------------------------------------------\n     | _______\n");
			printf("     | |%c    |\n", c1);
			printf("     | |  %c  |\tDealer score is %d\n", c2, D);
			printf("     | |    %c|\n", c1);
			printf("     | |_____|\n");
			stant();

		}
	}
}

void stant()
{
	FILE*fpt;
	fpt = fopen("Output.txt", "a");
	if (dealer_total < player_total)
	{
		printf("     | Player win!!!\n");
		fprintf(fpt,"     | Player win!!!\n");
		printf("     o------------------------------------------------------\n     | _______\n");
	}
	if (dealer_total == player_total)
	{
		printf("     | Draw game!!!\n");
		fprintf(fpt, "     | Draw game!!!\n");
		printf("     o------------------------------------------------------\n     | _______\n");
	}
	if (dealer_total > player_total)
	{
		if (dealer_total <= 21)
		{
			printf("     | Dealer win!!!\n");
			fprintf(fpt,"     | Dealer win!!!\n");
			printf("     o------------------------------------------------------\n     | _______\n");
		}
		else
		{
			printf("     | Player win!!!\n");
			fprintf(fpt,"     | Player win!!!\n");
			printf("     o------------------------------------------------------\n     | _______\n");
		}
	}
	ask();
}

void ask()
{
	FILE*fpt;
	fpt = fopen("Output.txt", "a");
	printf("\n");
	printf("\t############################################################\n");
	printf("\n");
	printf("\tDo you want to play again? <Yes/No> : ");
	fprintf(fpt,"\tDo you want to play again? <Yes/No> : ");
	scanf(" %c", &i);
	fprintf(fpt," %c\n", i);
	while(3)
	{
		if (i != 'Y' && i != 'y' && i != 'N' && i != 'n')// If invalid choice entered	
		{
			printf("\n");
			printf("\t############################################################\n");
			printf("\n");
			printf("\tIncorrect Choice. Please Enter Y for Yes or N for No :");
			fprintf(fpt,"\tIncorrect Choice. Please Enter Y for Yes or N for No :");
			scanf(" %c", &i);
			fprintf(fpt," %c\n", i);
		}
		if (i == 'y' || i == 'Y')
		{
			dealer_total = player_total = D = P = 0;
			system("cls");
			gameplay();
		}

		if (i == 'N' || i == 'n')
		{
			system("cls");
			exitgame();
			exit(0);
		}
	}
}
