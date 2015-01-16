/*************************************************************
Filename: atm.c
Written by: Precious Pacaldo
Date: 
Description: A program that prompts the user to enter his/her
			 account number and access code to inquire, deposit,
			 withdraw, and view history in his account.
Revision:
*************************************************************/

#include "ATM.H"

h * list = NULL,*temp1;
REC record[2], *ptrREC;

int adminLocator = 0;
int initAdmin(){
	ptrREC = record;
	
	strcpy(ptrREC -> accNumber,"09303470");
	strcpy(ptrREC -> accessCode,"1234");
	strcpy(ptrREC -> fname,"    Oji   ");
	strcpy(ptrREC -> lname,"   Bucad   ");
	ptrREC++;	
	
	strcpy(ptrREC -> accNumber,"12345678");
	strcpy(ptrREC -> accessCode,"1234");
	strcpy(ptrREC -> fname,"   James  ");
	strcpy(ptrREC -> lname,"   Dean   ");
	ptrREC++;
}

int askInput(){
	int num;
	scanf("%d",&num);
	return num;
}

int checkUser(char accessCode[],char accNumber[]){

	REC *temp = record;
	int i = 0;


	while(temp != NULL && i < 4){	
		if(strcmp(accessCode, temp->accessCode) == 0 && strcmp(accNumber,temp->accNumber) == 0){
		adminLocator = i;
		return 0;
		}
		else{
		if(strcmp(accNumber, temp->accNumber) == 0)
		return 1;
		}
		temp++;
		i++;
	}
	return 2;
}

void menu(){
	clrscr();
	gotoxy(20,5);
	printf("==============MAIN MENU================");
	gotoxy(20,6);
	printf("[1]Inquire");
	gotoxy(20,7);
	printf("[2]Withdraw");
	gotoxy(20,8);
	printf("[3]Deposit");
	gotoxy(20,9);
	printf("[4]Fast Cash");
	gotoxy(20,10);
	printf("[5]History");
	gotoxy(20,11);
	printf("[6]Exit");
	
	gotoxy(20,14);
	printf("Choice?:");
	
	gotoxy(20,15);
	printf("=======================================");

}

void login(){
	
	char accNumber[9], accessCode[5];
	int i= 0,re,xPos;
	char input;
	clrscr();
	
	
	gotoxy(20,4);
	printf("============USC BANKING SERVICE===========");
	gotoxy(20,5);
	printf("Input Account Number:");
	gotoxy(20,6);
	printf("Input Access Code:");
	gotoxy(20,7);
	printf("==========================================");
	gotoxy(41,5);
	scanf("%s",&accNumber);	
	xPos = 38;
	accNumber[8] = '\0';
			while(i < 4){
			gotoxy(xPos,6);
			input = getch();
			
					if(input == 4 && i >= 1){
						accessCode[i] = '';
						i--;
						gotoxy(--xPos,6);
						printf(" ");
					}
					else{
						gotoxy(xPos++,6);
						printf("*");	
						accessCode[i] = input;
						i++;
					}
		}
	accessCode[4] = '\0';
	
	re = checkUser(accessCode, accNumber);
	if(re == 1){
	gotoxy(20,9);
	printf("Sorry Access Code: %s is not correct.", accessCode);
	getch();
	login();
	}
	else if(re == 2){
	gotoxy(20,8);
	printf("Sorry Account Number#<%s>",accNumber);
	gotoxy(20,9);
	printf("and Access Code: %s is not correct.", accessCode);
	getch();
	login();
	}
}

void scan(){
	list = scanffile(record[adminLocator]);
	temp1 = list;
	if(temp1 != NULL){		
	temp1 = list;
		while(temp1->next != NULL){
			temp1 = temp1 -> next;
		}
		record[adminLocator].money = temp1->credit;
	}
}
void main(){
	int choice;
	int yPos = 0;
	initAdmin();
	login();
	scan();
	menu();
	gotoxy(28,14);
	choice = askInput();
	
	
	while(choice != 6){
		switch(choice){
		case 1:
			record[adminLocator] = inquire(record[adminLocator],&yPos);
			break;
		case 2:	record[adminLocator] = withdraw(record[adminLocator],&yPos);
			break;
		case 3:
			record[adminLocator] = deposit(record[adminLocator],&yPos);
			break;
		case 4:record[adminLocator]=fastcash(record[adminLocator],&yPos);break;
		case 5:history(record[adminLocator],list,&yPos);break;
		}
		gotoxy(25,yPos+2);
		printf("[Press any key to continue]");
		getch();
		free(list);
		list = NULL;
		scan();
		menu();
		gotoxy(28,14);
		choice = askInput();
	}
}