#include "atm.h"

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
