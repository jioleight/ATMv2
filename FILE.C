#include "ATM.H"

h *list1 = NULL, *temp;


int insert(h * newNode){
	if(list1 == NULL){
		list1 = newNode;
	}
	else{
	temp = list1;
	
		while(temp -> next != NULL){
			temp = temp -> next;
		}
		temp -> next = newNode;
	}
}

h* scanffile(REC user)
{
	FILE *fp;
	int dd, yy,mm, hr,mn,sec;
	double credit,debit;
	h *newnode,*reList;
	char *filename = strcat(user.accNumber,".TXT");
	
	if((fp = fopen(filename, "r")) != NULL){
		while((fscanf(fp,"%lf %lf %d %d %d %d %d %d\n",&credit,&debit,&dd,&mm,&yy,&hr,&mn,&sec)) != EOF){
				
				
				newnode = (struct node1*)malloc(sizeof(struct node1));
				
				if(newnode != NULL){
					newnode -> credit = credit;
					newnode -> debit = debit;
					newnode -> dd = dd;
					newnode -> yy = yy;
					newnode -> mm = mm;
					newnode -> hr = hr;
					newnode -> mn = mn;
					newnode -> sec = sec;
					newnode -> next = NULL;
					insert(newnode);	
				}
				else{
				printf("\nUnable to allocate!");
				}
			
		}
	}	
	fclose(fp);
	reList = list1;
	list1 = NULL;
return reList;
}

void save(REC user,double debit, struct date dt, struct time tm){
	FILE *newFile,*oldFile;
	char *filename = strcat(user.accNumber,".TXT");
	
	if((oldFile = fopen(filename,"a")) != NULL){
	fprintf(oldFile,"%.2lf %.2lf %d %d %d %d %d %d\n",user.money, debit,dt.da_day,dt.da_mon, dt.da_year,tm.ti_hour, tm.ti_min, tm.ti_sec);
	}
	else{
	newFile = fopen(filename,"w");
	fprintf(newFile,"%.2lf %.2lf %d %d %d %d %d %d\n",user.money, debit,dt.da_day,dt.da_mon, dt.da_year,tm.ti_hour, tm.ti_min, tm.ti_sec);
	}
	fclose(newFile);
	fclose(oldFile);
}
