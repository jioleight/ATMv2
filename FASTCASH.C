

/************************************************************************

FILENAME		: FastCash.c
WRITTEN BY	: Miguel Cortes
DATE			: 
DESCRIPTION	: This program provides a fast cash withdrawal method
				  in an atm banking system.

************************************************************************/

#include "ATM.H"


REC fastcash(REC user,int *yPos){
	double debitMoney;
	struct date dt;
	struct time tm;
	int choice,  y;
	clrscr();
	getdate(&dt);
	gettime(&tm);
	gotoxy(20,3);
	printf("==================FAST CASH===================");
	gotoxy(25,4);
	printf("Date:%d/%d/%d",dt.da_day, dt.da_mon, dt.da_year);
	gotoxy(25,5);
	printf("Time:%d:%d:%d",tm.ti_hour, tm.ti_min, tm.ti_sec);
	gotoxy(25,6);
	printf("Name:<%s>,<%s>", user.lname, user.fname);
	gotoxy(25,7);
	printf("Current Balance:Php. %.2lf", user.money);
	
	gotoxy(25,8);
	printf("=========OPTION=========");
	
	gotoxy(25,9);
	printf("[1]500");
	gotoxy(25,10);
	printf("[2]1000");
	gotoxy(25,11);
	printf("[3]2000");
	gotoxy(25,12);
	printf("[4]5000");
	gotoxy(25,13);
	printf("[5]10000");
	gotoxy(25,14);
	printf("Choice?:");
	
	y = 15;
	scanf("%d",&choice);
	while(choice < 0 || choice > 5){
		gotoxy(25,y++);
		printf("Invalid Input!");
		gotoxy(25,y);
		printf("Input again?:");
		scanf("%d",&choice);
	}
	switch(choice){
		case 1: debitMoney = 500;break;
		case 2: debitMoney = 1000;break;
		case 3: debitMoney = 2000;break;
		case 4: debitMoney = 5000;break;
		case 5: debitMoney = 10000;break;
	}

	if(debitMoney < user.money){
		user.money -= debitMoney;
		gotoxy(25,y+1);
		printf("Success!");
	}
	else{
		gotoxy(25,y+1);
		printf("Insufficient Balance!");
		gotoxy(25,y+2);
		printf("Remaining Balance: %.2lf" ,user.money);
	}
	*yPos = y+3;
	save(user,debitMoney,dt,tm);
	return user;	
}