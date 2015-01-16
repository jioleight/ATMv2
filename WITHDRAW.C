/********************************************************************
Filename: withdraw.c
Written by: Anniely Alquizar
Date: 
Description: a subprogram that enable the user to input an amount 
			and check if the inputted amount is
				sufficient and subtract it to the remaining balance.


**********************************************************************/

#include "ATM.H"

REC withdraw(REC user,int *yPos){
	int y;
	double debitMoney;
	struct date dt;
	struct time tm;
	clrscr();
	getdate(&dt);
	gettime(&tm);
	gotoxy(20,3);
	printf("==================WITHDRAW===================");
	gotoxy(25,4);
	printf("Date:%d/%d/%d",dt.da_day, dt.da_mon, dt.da_year);
	gotoxy(25,5);
	printf("Time:%d:%d:%d",tm.ti_hour, tm.ti_min, tm.ti_sec);
	gotoxy(25,6);
	printf("Name:<%s>,<%s>", user.lname, user.fname);
	gotoxy(25,7);
	printf("Current Balance:Php. %.2lf", user.money);
	gotoxy(25,8);
	printf("Withdraw Amount: Php.");
	scanf("%lf",&debitMoney);
	
	y = 9;
	
	while(debitMoney > user.money){
		gotoxy(25,y++);
		printf("Insufficient Balance!");
		gotoxy(25,y);
		printf("Enter Withdraw Amount Again: Php.");
		scanf("%lf",&debitMoney);
	}
	
	user.money -= debitMoney;
	*yPos = y+2;
	save(user,debitMoney,dt,tm);
	return user;	
}