/********************************************************************************************
Filename: deposit.c
Written by: Ryan Punay
Date: 
Description:	A subprogram that displays time, date, account number, current balance
				and asks user for the amount to be deposited then it is added to the 
				current  balance afterwhich it stores its updated current balance to the
				database.
Revision:
*********************************************************************************************/

#include "ATM.H"

REC deposit(REC user,int *yPos){
	struct date dt;
	struct time tm;
	double tempMoney;
	clrscr();
	getdate(&dt);
	gettime(&tm);
	gotoxy(20,3);
		printf("==================DEPOSIT===================");
	gotoxy(25,4);
	printf("Date:%d/%d/%d",dt.da_day, dt.da_mon, dt.da_year);
	gotoxy(25,5);
	printf("Time:%d:%d:%d",tm.ti_hour, tm.ti_min, tm.ti_sec);
	gotoxy(25,6);
	printf("Name:<%s>,<%s>", user.lname, user.fname);
	gotoxy(25,7);
	printf("Current Balance:Php. %.2lf", user.money);
	gotoxy(25,8);
	printf("Deposit Amount:Php.");
	scanf("%lf",&tempMoney);
	
	*yPos = 9;
	if(user.money == NULL){
	user.money = tempMoney;
	}
	else{
	user.money += tempMoney;
	}
	save(user,0,dt,tm);
	return user;	
}
