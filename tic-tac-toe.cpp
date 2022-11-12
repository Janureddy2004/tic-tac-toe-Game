#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<unistd.h>
#include<conio.h>
#define max 1000
char ch[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
char p1,p2;
void show_ch(){
	printf(" \t\t\t%c  | %c | %c ",ch[0],ch[1],ch[2]);
	printf("\n\t\t\t---|---|---\n");
	printf(" \t\t\t%c  | %c | %c ",ch[3],ch[4],ch[5]);
	printf("\n\t\t\t---|---|---\n");
	printf(" \t\t\t%c  | %c | %c ",ch[6],ch[7],ch[8]);
	puts("\n");
}
void reset_board(){
	for(int i=0;i<9;i++){
		ch[i]=' ';
	}
}
int checking_bank_ac(long long int n){
	int c=0,s=0,r;
	while(n){
		r=n%10;
		s+=r;
		n=n/10;
		c++;
	}
	return c;
}
long int random(){
	srand(time(NULL));
	return rand();
}
void get_x_player_choice(char c[max]){
	while(1){
		printf("\t\t-> %s Enter Your Position (1 - 9): \n",c);
		int choice;
		scanf("%d",&choice);
		choice--;
		if(choice<0||choice>8){
			puts("\t\t-> Please Select Your Choice From (1 - 9): ");
		}
		else if(ch[choice]!=' '){
			puts("\t\t-> Please Select An Empty Position.");
		}
		else{
			ch[choice]='X';
			break;
		}
	}
}
void get_o_player_choice(char c[max]){
	while(true){
		printf("\t\t-> %s Enter Your Position (1 - 9): \n",c);
		int choice;
		scanf("%d",&choice);
		choice--;
		if(choice<0||choice>8){
			puts("\t\t-> Please Select Your Choice From (1 - 9):");
		}
		else if(ch[choice]!=' '){
			puts("\t\t-> Please Select An Empty Position.\n");
		}
		else{
			ch[choice]='O';
			break;
		}
	}
}
void get_computer_choice(){
	srand(time(0));
	int choice;
	do{
		choice = rand()%10;
	}while(ch[choice]!=' ');
	ch[choice]='O';
}
void get_computer_choice2(){
	srand(time(0));
	int choice;
	do{
		choice = rand()%10;
	}while(ch[choice]!=' ');
	ch[choice]='X';
}

int count_board(char symb){
	int t=0;
	for(int i=0;i<9;i++){
		if(ch[i]==symb)
		t++;
	}
	return t;
}
char check_winner(){
//checking winner in horizontal/row
	if(ch[0]==ch[1] && ch[1]==ch[2] && ch[0] !=' ')
		return ch[0];
	if(ch[3]==ch[4] && ch[4]==ch[5] && ch[3] !=' ')
		return ch[3];
	if(ch[6]==ch[7] && ch[7]==ch[8] && ch[6] !=' ')
		return ch[6];
//checking winner in vertical/column
	if(ch[0]==ch[3] && ch[3]==ch[6] && ch[0] !=' ')
		return ch[0];
	if(ch[1]==ch[4] && ch[4]==ch[7] && ch[1] !=' ')
		return ch[1];
	if(ch[2]==ch[5] && ch[5]==ch[8] && ch[2] !=' ')
		return ch[2];
//checking winner inn Diagonal/cross
	if(ch[0]==ch[4] && ch[4]==ch[8] && ch[0] !=' ')
		return ch[0];
	if(ch[2]==ch[4] && ch[4]==ch[6] && ch[2] !=' ')
		return ch[2];
	if(count_board('X')+count_board('O')<9)
		return 'C';//continue
	else
		return 'D';//Draw
}
char check_winner_not(char a,char b){
//checking winner in horizontal/row
	if(ch[0]==ch[1] && ch[1]==ch[2] && ch[0] !=' ')
		return ch[0];
	if(ch[3]==ch[4] && ch[4]==ch[5] && ch[3] !=' ')
		return ch[3];
	if(ch[6]==ch[7] && ch[7]==ch[8] && ch[6] !=' ')
		return ch[6];
//checking winner in vertical/column
	if(ch[0]==ch[3] && ch[3]==ch[6] && ch[0] !=' ')
		return ch[0];
	if(ch[1]==ch[4] && ch[4]==ch[7] && ch[1] !=' ')
		return ch[1];
	if(ch[2]==ch[5] && ch[5]==ch[8] && ch[2] !=' ')
		return ch[2];
//checking winner inn Diagonal/cross
	if(ch[0]==ch[4] && ch[4]==ch[8] && ch[0] !=' ')
		return ch[0];
	if(ch[2]==ch[4] && ch[4]==ch[6] && ch[2] !=' ')
		return ch[2];
	if(count_board(a)+count_board(b)<9)
		return 'C';//continue
	else
		return 'D';//Draw
}
int toss(){
	int a;
	srand(time(NULL));
	a = (rand()%2)+1;
	return a;
}
void computer_vs_player(){
	char c[max];
	int o,m;
	puts("\t\t->Enter the player Name : ");
	fflush(stdin);
	gets(c);
	puts("\t\tLet's Toss The Coin (Head-1,Tail -2)\n\t\t->Enter your choice : ");
	scanf("%d",&o);
	int a=toss();
	if(o==a){
		printf("\t\t\t----> %s Won The Toss <----\n\n",c);
		puts("\t\t->Select A Symbol To Play The Game (X-1,O-2)\n\t\t->Enter Your choice :  ");
		scanf("%d",&m);
		if(m==1){
			while(true){
				show_ch();//shows the board
				if(count_board('X') == count_board('O')){
					printf("\t\t\t %s's Turn\n",c);
					get_x_player_choice(c);
				}
				else{
					puts("\t\t\t Computer's Turn\n");
					get_computer_choice();
				}
				char w = check_winner();
				if(w=='X'){
					show_ch();
					printf("\n\t\t\t----------------> '%s' Won The Game <----------------\n\n",c);
					break;
				}
				else if(w=='O'){
					show_ch();
					puts("\n\t\t\t----------------> 'Computer' Won the Game <----------------\n\n");
					break;
				}
				else if(w=='D'){ 
					show_ch();
					puts("\n\t\t\t----------------> Game is Draw <----------------\n");
					break;
				}
			}	
		}
		else{
			while(true){
				show_ch();//shows the board
				if(count_board('X') == count_board('O')){
					printf("\t\t\t %s's Turn\n",c);
					get_o_player_choice(c);
				}
				else{
					puts("\t\t\t Computer's Turn\n");
					get_computer_choice2();
				}
				char w = check_winner();
				if(w=='O'){
					show_ch();
					printf("\n\t\t\t----------------> '%s' Won The Game <----------------\n\n",c);
					break;
				}
				else if(w=='X'){
					show_ch();
					puts("\n\t\t\t----------------> 'Computer' Won the Game <----------------\n\n");
					break;
				}
				else if(w=='D'){ 
					show_ch();
					puts("\n\t\t\t----------------> Game is Draw <----------------\n");
					break;
				}
			}	
		}
	}
		
	else{
		puts("\t\t\t----> Computer Won The Toss <----\n\n");
		while(true){
			show_ch();//shows the board
			if(count_board('O')==count_board('X')){
				puts("\t\t\t Computer's Turn\n");
				get_computer_choice();
			}
			else{
				printf("\t\t\t %s's Turn\n",c);
				get_x_player_choice(c);
			}
			char w = check_winner();
			if(w=='X'){
				 
				show_ch();
				printf("\n\t\t\t----------------> '%s' Won The Game <----------------\n\n",c);
				break;
			}
			else if(w=='O'){
				 
				show_ch();
				puts("\n\t\t\t----------------> 'Computer' Won the Game <----------------\n\n");
				break;
			}
			else if(w=='D'){
				 
				show_ch();
				puts("\n\t\t\t----------------> Game is Draw <----------------\n");
				break;
			}
		}	
	}
}
void player_vs_player(){
	char h[max],j[max];
	int i,a;
	puts("\t\t-> Enter Your Name : ");
	fflush(stdin);
	gets(h);
	puts("\t\t-> Enter Your Patner Name : ");
	fflush(stdin);
	gets(j);
	puts("\t\t-> Lets Toss The Coin");
	printf("\t-> %s Choose  Head-1 or Tail -2 ",h);
	scanf("%d",&a);
	if(a==toss()){
		printf("\n\t\t -------> %s Won The Toss <-------\n\n",h);
		printf("\t\t-> %s Choose Your Symbol(X-1,O-2) : \n",h);
		scanf("%d",&i);
		if(i==1){
			while(1){
				show_ch();
				if(count_board('X')==count_board('O')){
					get_x_player_choice(h);
				}
				else{
					get_o_player_choice(j);
				}
				char w=check_winner();
				if(w=='X'){
					show_ch();
					printf("\t\t\t----------------> '%s' Won The Game <----------------\n",h);
					break;
				}
				else if(w=='O'){
					show_ch();
					printf("\t\t\t----------------> '%s' Won the Game <-----------------\n",j);
					break;
				}
				else if(w=='D'){
					show_ch();
					puts("\t\t\t----------------> Game is Draw <----------------\n");
					break;
				}
			}
		}
		else{
			while(1){
				show_ch();
				if(count_board('O')==count_board('X')){
					printf("\n\t\t\t %s'turn\n",h);
					get_o_player_choice(h);
				}
				else{
					printf("\n\t\t\t %s'turn\n",j);
					get_x_player_choice(j);
				}
				char w=check_winner();
				if(w=='O'){
					show_ch();
					printf("\t\t\t----------------> '%s' Won The Game <----------------\n",h);
					break;
				}
				else if(w=='X'){
					show_ch();
					printf("\t\t\t----------------> '%s' Won the Game <----------------\n",j);
					break;
				}
				else if(w=='D'){
					show_ch();
					puts("\t\t\t----------------> Game is Draw <----------------\n");
					break;
				}
			}
		}
	}
	else{
		printf("\n\t\t -----> %s Won The Toss <-----\n\n",j);
		printf("\t\t-> %s Choose Your Symbol(X-1,O-2) : \n",j);
		scanf("%d",&i);
		if(i==1){
			while(1){
				show_ch();
				if(count_board('X')==count_board('O')){
					get_x_player_choice(j);
				}
				else{
					get_o_player_choice(h);
				}
				char w=check_winner();
				if(w=='X'){
					show_ch();
					printf("\t\t\t----------------> '%s' Won The Game <----------------\n",j);
					break;
				}
				else if(w=='O'){
					show_ch();
					printf("\t\t\t----------------> '%s' Won the Game <----------------\n",h);
					break;
				}
				else if(w=='D'){
					show_ch();
					puts("\t\t\t----------------> Game is Draw <----------------\n");
					break;
				}
			}
		}
		else{
			while(1){
				show_ch();
				if(count_board('X')==count_board('O')){
					get_o_player_choice(j);
				}
				else{
					get_x_player_choice(h);
				}
				char w=check_winner();
				if(w=='O'){
					show_ch();
					printf("\t\t\t----------------> '%s' Won The Game <----------------\n",j);
					break;
				}
				else if(w=='X'){
					show_ch();
					printf("\t\t\t----------------> '%s' Won the Game <----------------\n",h);
					break;
				}
				else if(w=='D'){
					show_ch();
					puts("\t\t\t----------------> Game is Draw <----------------\n");
					break;
				}
			}
		}
	}
}
void get_u_player_choice(char c[max],char p){
	while(true){
		printf("\t\t-> %s Enter Your Position (1 - 9): \n",c);
		int choice;
		scanf("%d",&choice);
		choice--;
		if(choice<0||choice>8){
			puts("\t\t-> Please Select Your Choice From (1 - 9):");
		}
		else if(ch[choice]!=' '){
			puts("\t\t-> Please Select An Empty Position.\n");
		}
		else{
			ch[choice]=p;
			break;
		}
	}
}
void get_c_player_choice(char c[max],char p){
	while(true){
		printf("\t\t-> %s Enter Your Position (1 - 9): \n",c);
		int choice;
		scanf("%d",&choice);
		choice--;
		if(choice<0||choice>8){
			puts("\t\t-> Please Select Your Choice From (1 - 9):");
		}
		else if(ch[choice]!=' '){
			puts("\t\t-> Please Select An Empty Position.\n");
		}
		else{
			ch[choice]=p;
			break;
		}
	}
}
void other_than_x_o(char h[max],char j[max]){
	int a;
	puts("\t\t-> To Play With Different Characters You need To Pay 50Rs\nTo pay press 1 nor press 0");
	scanf("%d",&a);
	if(a){
		long long int c;
		puts("\t\t-> Enter Your bank ac no : ");
		scanf("%lld",&c);
		int k = checking_bank_ac(c);
		if(k==11){
			long int g= random();
			printf("\t-> Your Bank Balance : %ld\n\t----->* Transaction Succesfull *<-----\n\t-> Current Balance : %ld\n",g,g-50);
			char p1,p2;
			int i,a;
			printf("\t\t-> Enter %s's symbol : ",h);
			fflush(stdin);
			scanf(" %c",&p1);
			printf("\t\t-> Enter %s's symbol : ",j);
			fflush(stdin);
			scanf(" %c",&p2);
			printf("\t\t->  %s Choose Head-1 or Tail -2",h);
			scanf("%d",&a);
			if(a==toss()){
				printf("\n\t\t %s Won The Toss\n\n",h);
				while(1){
					show_ch();
					if(count_board(p1)==count_board(p2)){
						get_u_player_choice(h,p1);
					}
					else{
						get_c_player_choice(j,p2);
					}
					char w=check_winner_not(p1,p2);
					if(w==p1){
						show_ch();
						printf("\t\t\t----------------> '%s' Won The Game <----------------\n",h);
						break;
					}
					else if(w==p2){
						show_ch();
						printf("\t\t\t----------------> '%s' Won the Game <----------------\n",j);
						break;
					}
					else if(w=='D'){
						show_ch();
						puts("\t\t\t----------------> Game is Draw <----------------\n");
						break;
					}
				}
			}
			else{
				printf("\n\t\t %s\n\n",j);
				puts("\t\t---- Won the Toss ----");
				while(1){
					show_ch();
					if(count_board(p1)==count_board(p2)){
						get_u_player_choice(j,p2);
					}
					else{
						get_c_player_choice(h,p1);
					}
					char w=check_winner_not(p1,p2);
					if(w==p2){
						show_ch();
						printf("\t\t\t----------------> '%s' Won The Game <----------------\n",j);
						break;
					}
					else if(w==p1){
						show_ch();
						printf("\t\t\t----------------> '%s' Won the Game <----------------\n",h);
						break;
					}
					else if(w=='D'){
						show_ch();
						puts("\t\t\t----------------> Game is Draw <----------------\n");
						break;
					}
				}
			}
		}
		else{
			puts("--------------INVALID ACCOUNT NO-------------\n\t\tMaximum Invalid Transaction - Try Again Tommorrow\n");
			puts("\t\t-> Do you want to play with 'X' & 'O'(1-Yes,0-No)\n\t\t-> Enter Your Choice : ");
			int y;
			scanf("%d",&y);
			if(y==1){
				reset_board();
				player_vs_player();
			}
		}
	}
	else{
		puts("\t\t-> Do you want to play with 'X' & 'O'(1-Yes,0-No)\n\t\t-> Enter Your Choice : ");
		int s;
		scanf("%d",&s);
		if(s==1){
			reset_board();
			player_vs_player();
		}
	}
}
int main(){
	int k=1;
	puts("\t\t\t\t-----> WELCOME TO TIC TAC TOE GAME <-----\n\n");
	while(k){
		
		int a,u;
		printf("\t^-------------------------^\n");
		puts("\t| ->Menu:\t\t  |\n\t|   I. Single Player Mode |\n\t|\t\t\t  |\n\t|   II.Dual Player Mode   |\n\t^-------------------------^\n\n-----| Choose A Option To Play The Game |-----\n");
		puts("\t-> To Choose I Mode - Enter 1\n\t-> To Choose II Mode - Enter 2\n\t-> Enter Your Choice : \n");
		scanf( "%d",&a);
		if(a==1){
			puts("\t\t-> You Have Selected :\n\t\t------------------ | Single Player Mode | ------------------\n\n");
			puts("____|Select Your Play Option |____\n");
			puts("\t^---------------------------------------^");
			puts("\t| -> 1.Play With 'X'&'O'\t\t|\n\t|\t\t\t\t\t|");
			puts("\t^---------------------------------------^");
			puts("\n\t->Enter Your Option (1,Exit-2) :");
			scanf("%d",&u);
			if(u==1){
				puts("\t\t-> You Have Selected :\n\t\t------------------ | Single Player - X,O | ------------------\n\n");
				computer_vs_player();
			}
		}
		else{
			puts("\t\t-> You Have Selected :\n\t\t------------------ | Dual Player Mode| ------------------\n\n");
			puts("____| Select Your Play Option |____\n");
			puts("\t^---------------------------------------^");
			puts("\t| -> 1.Play With 'X'&'O'\t\t|\n\t| -> 2.Play With Different Characters   |");
			puts("\t^---------------------------------------^");
			puts("\n\t->Enter Your Option (1,2) :");
			scanf("%d",&u);
			if(u==1){
				puts("\t\t-> You Have Selected :\n\t\t------------------ | Play With 'X' & 'O' | ------------------\n\n");
				player_vs_player();
			}
			else{
				puts("\t\t-> You Have Selected :\n\t\t------------------ | Play With Different Characters | ------------------\n\n");
				char a[max],b[max];
				puts("\t\t->Enter your Name :");
				fflush(stdin);
				gets(a);
				puts("\t\t-> Enter your patner Name");
				fflush(stdin);
				gets(b);
				reset_board();
				other_than_x_o(a,b);
			}
		}
		puts("\t\t-> Do you Want To Play Again (Yes - 1, No - 0)\n\t\t-> Enter Your Choice :");
		scanf("%d",&k);
		reset_board();
		puts("\n\n");
		system("cls");
	}
	puts("\n------------->| Thank You |<-------------\n");
}


