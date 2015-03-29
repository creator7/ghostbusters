#ifndef DISPLAY_ALL
#define DISPLAY_ALL

#include"ghost.h"


//gotoxy function
int chk=0;
void gotoxy(int x,int y)
{
printf("%c[%d;%df",0x1B,y,x);
}
int Display(ghost g,int count,int count1);
void show_Allrecord(ghost g,int count)
{

			printf("\t\tRecord # %d",count+1);
			printf("\n\n");
			printf("Code:  %d:%d",g.year,g.gcode);
			printf("\t\t\tDate %d-%d-%d",g.year,g.month,g.date);
			printf("\t\tTime: %d:%d",g.hours,g.minutes);
			printf("\n\t\t\tInvestigation Date  %d-%d-%d",g.inv_year,g.inv_month,g.inv_date);
			printf("\t\tTime: %d:%d",g.i_hour,g.i_min);
			printf("\n\n\t\tEvent:  %s\n",g.EventType);
			printf("\t\tName : %s\n",g.name);
			printf("\t\tPhone-no: %s\n",g.phone_no);
			printf("\t\tAddress : %s\n",g.address);
			printf("\t\tProvince : %s\n\n",g.province);
			printf("\t\tResult : %s",g.result);

			
};
int display_All()
{
	ghost g;
	FILE *file;
	int count=0;
	int count1=0;
	int i;
	
	////////////////reading//////////////////////
	//read from file..
		file=fopen("database.dat","rb+");
		if(!file)
		{
	
			return 1;
			
		}
		
		if(fread(&g,sizeof(g),1,file)==0)
		{
			printf("\t\tDatabase is empty..");
		}
		else
		{
			fseek(file,0,SEEK_SET);
				printf("________________________________________________________________________________\n\n");
				printf("# |  Code   |  Date   |EvntTyp|   NAME  |   phone # |  Address     | Province |\n\n");
				printf("________________________________________________________________________________\n\n");
		while(fread(&g,sizeof(g),1,file)==1)
		{
			i=Display(g,count,count1);
			if(i==0)
			{
				count++;
				count1++;
			}
			else
			{
				count+=2;
				count1++;
			}
			
		}
	
	}// end else
		fclose(file);
		return 0;
		
}
int Display(ghost g,int count,int count1)
{
	//int n[20];
	int i=0;
	int x=1;
	int flag=0;
	int y=7+count;
			gotoxy(x,y);
			printf("%d",count1+1);
			gotoxy(x+2,y);
			printf("|%d:%d  ",g.year,g.gcode);
			gotoxy(x+12,y);
			printf("|%d/%d/%d",g.date,g.month,g.year);
			gotoxy(x+23,y);
			printf("|%s",g.EventType);
			gotoxy(x+30,y);
			if(strlen(g.name)>10)
			{
				printf("|");
				while(i<9)
				{
					printf("%c",g.name[i]);
					i++;
				}
				y++;
				gotoxy(x+30,y);
				printf("|");
				while(g.name[i]!='\0')
				{
					printf("%c",g.name[i]);
					i++;
				}
				gotoxy(x+40,y);
				printf("|");
				y--;
				flag++;
			}
			else
			{
				gotoxy(x+30,y);
				printf("|%s",g.name);
			}
			gotoxy(x+40,y);
			printf("|%s",g.phone_no);
			gotoxy(x+52,y);
			if(strlen(g.address)>12)
			{
				int f=0;
				printf("|");
				while(f<11)
				{
					printf("%c",g.address[f]);
					f++;
				}
				y++;
				gotoxy(x+52,y);
				printf("|");
				while(g.address[f]!='\0')
				{
					printf("%c",g.address[f]);
					f++;
				}
				gotoxy(x+67,y);
				printf("|");
				y--;
				flag++;
			}
			else
			{
				gotoxy(x+52,y);
				printf("|%s",g.address);
			}
			gotoxy(x+67,y);
			printf("|%s",g.province);
			x=1;
			y++;
			count++;
			if(flag==0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
#endif
