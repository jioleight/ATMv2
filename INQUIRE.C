/**********************************************************
Filename: INQUIRE.c
Written By: Driane Saberon
Date: 
Description: This programs displays the balance of the user and returns to the main menu if the use presses any key.
Revision:
***********************************************************/

#include "ATM.H"

REC inquire(REC user,int *yPos){
	struct date dt;
	struct time tm;
	clrscr();
	getdate(&dt);
	gettime(&tm);
	
	gotoxy(20,3);
	printf("==================INQUIRE===================");
	gotoxy(25,4);
	printf("Date:%d/%d/%d",dt.da_day, dt.da_mon, dt.da_year);
	gotoxy(25,5);
	printf("Time:%d:%d:%d",tm.ti_hour, tm.ti_min, tm.ti_sec);
	gotoxy(25,6);
	printf("Name:<%s>,<%s>", user.lname, user.fname);
	gotoxy(25,7);
	printf("Current Balance:Php. %.2lf", user.money);
	
	*yPos = 8;
	return user;
}