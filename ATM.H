#ifndef	__ATM_H
#define __ATM_H
#include <CONIO.H>
#include <STDIO.H>
#include <STDLIB.H>
#include <DOS.H>

typedef struct node1 {
	
	double credit;
	double debit;
	int dd;
	int yy;
	int mm;
	int hr;
	int mn;
	int sec;
	struct node1 *next;

}h;

typedef struct node2 {

	char accNumber[9];
	char accessCode[5];
	char fname[11];
	char lname[11];
	double money;

}REC;

int insert(h * newNode);
h* scanffile(REC user);
void save(REC user,double debit, struct date dt, struct time tm);

REC inquire(REC user,int *yPos);
REC deposit(REC user,int *yPos);
REC withdraw(REC user,int *yPos);
REC fastcash(REC user,int *yPos);
void history(REC user,h * list,int *yPos);

void displayHistory(h *from,h *to,int *yPos);
void month(int month);
void currentMonth(int mm, h *list, int *yP);
void inclusiveDates(h *list,int *yPos,int fdd,int fmm,int fyy,int todd,int tomm,int toyy);

#endif