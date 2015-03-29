#ifndef SEARCH
#define SEARCH

#include"ghost.h"
#include"delete.c"
#include"modify.c"
#include"Add.c"

void delete_menu();

/////////////////////start body search year////////////////////
void search_year(int y)
{
	int count=0;
	int flag=0;
	ghost g;
	FILE *file=fopen("database.dat","rb");
	if(file == NULL)
	{
		printf("empty");
	}
	else 
	{
		FILE* file1;
		file1=fopen("temporary.dat","wb");
		fseek(file1,0,SEEK_SET);
		system("clear");
		while((fread(&g,sizeof(g),1,file)) == 1)
		{
			if(y==g.year)
			{
				show_Allrecord(g,count);
				fwrite(&g,sizeof(g),1,file1);
				count++;
				flag++;
			}
			
			
		}
	fclose(file1);
		if(flag==0)
		{
			printf("Record Not Found\n");
		}
		else
		{
			fclose(file);
			delete_menu();
		}
	
	}
}
///////////////////////////////search year end//////////
////////////////////////////start search_code/////////////////
void search_code(int c)
{
	int count=0;
	int flag=0;
	ghost g;
	FILE *file=fopen("database.dat","rb");
	if(file == NULL)
	{
		printf("empty");
	}
	else 
	{
		FILE* file1;
		file1=fopen("temporary.dat","wb");

		fseek(file1,0,SEEK_SET);
		system("clear");
		while((fread(&g,sizeof(g),1,file)) == 1)
		{
			if(c==g.gcode)
			{
				show_Allrecord(g,count);
				fwrite(&g,sizeof(g),1,file1);
				count++;
				flag++;
				break;
				
			}	
		}
		fclose(file1);
		if(flag==0)
		{
			printf("Record Not Found\n");
		}
		else
		{
			fclose(file);
			delete_menu();
		}
	
	}
}
///////////////end search_code//////////////////////////////
///////////////start search_event///////////////////////////
void search_event(char *str)
{
	int i,j,flag;
	int flag1=0;
	int count=0;
	ghost g;
	FILE *file=fopen("database.dat","rb");
	if(file == NULL)
	{
		printf("empty");
	}
	else 
	{
		FILE* file1;
		file1=fopen("temporary.dat","wb");
		//fseek(file1,0,SEEK_SET);
		system("clear");

		while((fread(&g,sizeof(g),1,file)) == 1)
		{
			flag=0;
			for(i=0;i<strlen(g.EventType);i++)
			{
				if(g.EventType[i]==46)
				{
					i++;
				}
				for(j=0;j<strlen(str);j++)
				{
					if(str[j]==46)
					{
						j++;
					}
					
					if(str[j]==g.EventType[i])
					{
						show_Allrecord(g,count);
						fwrite(&g,sizeof(g),1,file1);
						flag++;
						flag1++;
						count++;
					}
			
				}
				if(flag==1)
				{
					break;
				}
			}
		}
		fclose(file1);
		if(flag1==0)
		{
			printf("Record Not Found\n");
		}
		else
		{
			fclose(file);
			delete_menu();
		}
	}
}

void delete_menu()
{
	int opt;
	int rec_no;
	char input[10];
	printf("\n\n\t1- Delete\n");
	printf("\t2- Modify\n");
	printf("\t3- Back to menu\n");
	printf("\n\t\tChoose An Option:     ");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:
		{
					printf("\n\tEnter Record No:  ");
					scanf("%d",&rec_no);
					fgets(input,sizeof(input),stdin);
					delete(rec_no);
					break;
				}
				case 2:
				{
					printf("\n\tEnter Record No:  ");
					scanf("%d",&rec_no);
					fgets(input,sizeof(input),stdin);
					modify(rec_no);
					break;
				}
				case 3:
				{
					fgets(input,sizeof(input),stdin);
					optionsDisplay();
					break;
				}
				default:
				{
					printf("Wrong Entry!!!");
				}
			}
}
#endif
////////////////end search_event///////////////////////////
