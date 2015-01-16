/*************************************************************
Filename: history.c
Written by: Precious Pacaldo
Date:
Description: 
Revision:
*************************************************************/


#include "ATM.H"

char accNumber[5], mon[4];
h *last;
int y;

void displayHistory(h *from,h *to,int *yPos){
	
	double totalDebit = 0.00; 
	int posY = *yPos ,flag = 0;
	
	gotoxy(5,posY++);
	printf("==================================================================");
	gotoxy(5,posY); printf("DATE");
	gotoxy(20,posY); printf("TIME");
	gotoxy(35,posY); printf("DEBIT");
	gotoxy(55,posY++); printf("CREDIT");
				
				if(from != NULL){
					while(from != NULL && from <= to){
						gotoxy(5,posY);
						printf("%i/%i/%i",from -> mm,from -> dd, from -> yy);
						gotoxy(20,posY);
						printf("%i:%i:%i",from -> hr,from -> mn, from -> sec);
						gotoxy(35,posY);
						printf("%.2lf",from -> debit);
						gotoxy(55,posY++);
						printf("%.2lf",from -> credit);
						totalDebit += from -> debit;
						from = from -> next;	
						flag = 1;
					}
				}
				else{
				posY +=3;
				
				gotoxy(25,posY); printf("NO TRANSACTION MADE!");
				posY +=3;
				}
	gotoxy(5,posY++);
	printf("==================================================================");
		
			gotoxy(20,posY);
			printf("TOTAL:");
		if(flag == 1){
				gotoxy(35,posY);
				printf("%.2lf",totalDebit);
				gotoxy(55,posY++);
				printf("%.2lf",to -> credit);
		}

	*yPos = posY;
	
	printf("DISPLAY HISTORY : )");
}


void month(int month){

		switch(month){
		case 1: strcpy(mon,"Jan");break;
		case 2: strcpy(mon,"Feb");break;
		case 3: strcpy(mon,"Mar");break;
		case 4: strcpy(mon,"Apr");break;
		case 5: strcpy(mon,"May");break;
		case 6: strcpy(mon,"Jun");break;
		case 7: strcpy(mon,"Jul");break;
		case 8: strcpy(mon,"Aug");break;
		case 9: strcpy(mon,"Sep");break;		
		case 10: strcpy(mon,"Oct");break;
		case 11: strcpy(mon,"Nov");break;
		case 12: strcpy(mon,"Dec");break;
		}
		mon[3] = '\0';
}

void currentMonth(int mm, h *list, int *yP){
	h *from;
	int yPos = 2,locator = 0;
	
	
	while(list->next != NULL){
		if(list -> mm == mm){
				if(locator == 0){
					from = list;
				}
				locator++;
		}
		list = list -> next;
	}
	if(list -> next == NULL && locator == 0 && list -> mm == mm){
		from = list;
	}
	
	last = list;
	clrscr();
	gotoxy(5,1);
	printf("CURRENT MONTH: %s %i to %i",mon,from -> dd, last -> dd);
	displayHistory(from, last,&yPos);
	*yP = yPos;
}


void inclusiveDates(h *list,int *yPos,int fdd,int fmm,int fyy,int todd,int tomm,int toyy){
	int y = 4,locator = 0;
	h * from, *to;
	if(list != NULL){
				while(list -> next != NULL){
						if(list -> dd == fdd && list -> mm == fmm && list -> yy == fyy && locator == 0){
							from = list;
							locator++;
						}
						if(list -> dd == todd && list -> mm == tomm && list -> yy == toyy){
							to = list;
						}
						list = list -> next;
				}
							if(list -> next == NULL && locator == 0 && list -> dd == fdd && list -> mm == fmm && list -> yy == fyy){
									from = list;
							}
							else if(list -> next == NULL && locator != 0 && list -> dd == fdd && list -> mm == fmm && list -> yy == fyy){
									to = list;
							}
	}
	else{
		from = list;
		to = list;
	}
	displayHistory(from, to,&y);
	*yPos = y;
}


void history(REC user,h * list,int *yPos){
	int option,fdd = 0,fmm = 0,fyy = 0, todd = 0,tomm = 0,toyy = 0, y = 0, yPos2 = 2;
	char *mon;
	struct date dt;
	struct time tm;
	clrscr();
	
	list = list;
	strcpy(accNumber,user.accNumber);
	getdate(&dt);
	gettime(&tm);
		gotoxy(5,3);
		printf("================================ HISTORY =================================");
		gotoxy(5,4);
		printf("Date:%d/%d/%d",dt.da_day, dt.da_mon, dt.da_year);
		gotoxy(5,5);
		printf("Time:%d:%d:%d",tm.ti_hour, tm.ti_min, tm.ti_sec);
		gotoxy(5,6);
		printf("Name:<%s>,<%s>", user.lname, user.fname);
		gotoxy(5,7);
		printf("Account Number: <%s>",user.accNumber);
		gotoxy(5,8);
		printf("Current Balance:Php. %.2lf", user.money);
		
		gotoxy(5,8);
		printf("================================ OPTION ================================== ");
		gotoxy(5,9);
		printf("[1] CURRENT MONTH");
		gotoxy(5,10);
		printf("[2] INCLUSIVE DATES");
		y = 11;
				gotoxy(5,y++);
				printf("choice?:");		
				scanf("%d",&option);
				while(option < 1 && option > 2){
				gotoxy(5,y++);
				printf("enter choice again:");		
				scanf("%d",&option);
				gotoxy(5,y);
				printf("Invalid Input!!! Press a key to continue...");
				getch();
				}
		
		if(option == 1){
			month(dt.da_mon);
			currentMonth(dt.da_mon,list,&y);
			*yPos = y;
		}
		else{
			clrscr();
			if(list != NULL){
					gotoxy(5,yPos2);
					printf("From[dd/mm/yyyy]:  /  /");
					gotoxy(22,yPos2);
					scanf("%d",&fdd);
					gotoxy(25,yPos2);
					scanf("%d",&fmm);
					gotoxy(28,yPos2);
					scanf("%d",&fyy);
					gotoxy(5,++yPos2);
					printf("To[dd/mm/yyyy]:  /  /");
					gotoxy(20,yPos2);
					scanf("%d",&fdd);
					gotoxy(23,yPos2);
					scanf("%d",&fmm);
					gotoxy(26,yPos2++);
					scanf("%d",&fyy);
					inclusiveDates(list,&yPos2,fdd,fmm,fyy, todd,tomm,toyy);
			}
			else{
					inclusiveDates(list,&yPos2,0,0,0, 0,0,0);
			}
			*yPos = yPos2;
		}	
}



