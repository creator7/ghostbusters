#ifndef ADD
#define ADD

#include"ghost.h"
#include<unistd.h>
#include<time.h>


int generate_code(ghost g);
int chk_type(char str[20]);
int chk_address(char* str);
int chk_phone(char str[15]);
int chk_name(char* str);
int chk_province(char *str);
int chk_date(int,int,int,int);
int chk_time(int,int,int,int,int);
int chk_investigation(int,int,int,int,int,ghost);
void Add(int,ghost);
void write_mod(ghost g);
void write_file(ghost g);

void Add(int chk_mod,ghost g)
{	
	int mod;
	system("clear");
	char input[40];
	char opt;
	d:
	printf("Enter Event Date (Values can't be modified)\n");
	
	if(chk_mod==0)
	{
		mod=0;
		printf("\tYear(yyyy):  ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%d",&g.year);
		g.gcode=generate_code(g);
	}
	else
	{
		mod=1;
	}
		printf("\tMonth(mm):  ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%d",&g.month);
		printf("\tDay(dd) :  ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%d",&g.date);
		printf("\n\tEnter Time");
		printf("\n\tEnter Hours: ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%d",&g.hours);
		printf("\n\tEnter Minutes: ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%d",&g.minutes);
		if(!chk_date(g.date,g.month,g.year,mod))
		{
			printf("\nPlease Enter a valid Date.\n");
			goto d;
		}
		if(!chk_time(g.hours,g.minutes,g.date,g.month,g.year))
		{
			printf("\nWrong Time!!.\n");
			sleep(1);
			system("clear");
			goto d;
		}
	printf("\n\nEvents Should be of following type\n\n");
	printf("V (Vampire)\n");
	printf("W (Werewolf)\n");
	printf("G (Ghost)\n");
	printf("D (Demon)\n");
	printf("Z (Zombie)\n");
	printf("P (phi krasue)\n");
	printf("O (Other)\n");
	printf("More than one should sepparated by comma like V,M,Z\n");
	w:
	printf("Enter Event Type:  ");
	fgets(input,sizeof(input),stdin);
	sscanf(input,"%s",g.EventType);
	if(!chk_type(g.EventType))
	{
		printf("Not Valid!!\n");
		goto w;
	}
	i:	
		system("clear");
		printf("Code: %d:%d",g.year,g.gcode);
		printf("\t\tDate :%d-%d-%d",g.year,g.month,g.date);
		printf("\t\tTime :%d:%d\n",g.hours,g.minutes);
		printf("Enter Investigation Date\n");
		printf("\tYear(yyyy):  ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%d",&g.inv_year);
		printf("\tMonth(mm):  ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%d",&g.inv_month);
		printf("\tDay(dd) :  ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%d",&g.inv_date);
		printf("\n\tEnter Time");
		printf("\n\tEnter Hours: ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%d",&g.i_hour);
		printf("\n\tEnter Minutes: ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%d",&g.i_min);
		if(!chk_investigation(g.inv_date,g.inv_month,g.inv_year,g.i_hour,g.i_min,g))
		{
			printf("\nPlease Enter A Valid Investigation Date\n");
			sleep(1);
			goto i;
		}
	x:
	printf("Enter Name of person Reporting Event:    ");
	fgets(input,sizeof(input),stdin);

    if (input[strlen(input)-1] == '\n')
        input[strlen(input)-1] = '\0';
    strcpy(g.name,input);
	if(!chk_name(g.name))
	{
		printf("Not Valid!!\n");
		goto x;
	}
	y:
	printf("Enter Phone No of person Reporting Event\nFormat(0aa-nnnnnn) <-- :     ");
	fgets(input,sizeof(input),stdin);
	sscanf(input,"%s",g.phone_no);
	if(!chk_phone(g.phone_no))
	{
		printf("Not Valid!!\n");
		goto y;
	}
	z:
	printf("Enter Address of Event:   ");
	fgets(input,sizeof(input),stdin);

    if (input[strlen(input)-1] == '\n')
        input[strlen(input)-1] = '\0';
    strcpy(g.address,input);
	if(!(chk_address(g.address)))
	{
		printf("Not Valid!!\n");
		goto z;
	}
	p:
	printf("Enter Province (Thailand) <-- :    ");
	fgets(input,sizeof(input),stdin);
    strcpy(g.province,input);
	if(!chk_province(g.province))
	{
		printf("not valid province of thailand\n");
		goto p;
	}
		
	
	
	printf("Enter Result Status: (SUCCESS,FAILURE OR UNKNOWN):  ");
	fgets(input,sizeof(input),stdin);
	strcpy(g.result,input);
	if(mod==0)
	{
		write_file(g);
	}
	else
	{
		write_mod(g);
	}
	/*FILE *file;
	file = fopen("database.dat","a+b");
	if(file == NULL)
	{
		printf("nError in Opening File");
		exit(0);
	} 
	else
	{
		fwrite(&g,sizeof(g),1,file);
	}
	fclose(file);*/
	printf("DO You Want to enter Another Entry(Y/N)?");
	fgets(input,sizeof(input),stdin);
	sscanf(input,"%c",&opt);
	if((opt=='Y') || (opt=='y'))
	{
		printf("okay\n");
		Add(0,g);
		
	}
	else if((opt=='n') || (opt=='N'))
	{
		//main menu

	}

}
//////////////////////end function add///////////////////

void write_mod(ghost g)
{
	FILE* file;
	ghost g1;
	int flag=0;
	file=fopen("database.dat","r+b");
	int pos=-1*sizeof(g);
	while(fread(&g1,sizeof(g1),1,file)==1 && flag==0)
	{
		printf("code:  %d\n",g1.gcode);
		if(g.gcode==g1.gcode)
		{
			fseek(file,pos,SEEK_CUR);
			fwrite(&g,sizeof(g),1,file);
			flag++;
		}
	}
	fclose(file);
	printf("\n\n\tRecord Successfully modified\n"); 
	optionsDisplay();
}
void write_file(ghost g)
{
	FILE *file;
	file = fopen("database.dat","a+b");
	if(file == NULL)
	{
		printf("nError in Opening File");
		exit(0);
	} 
	else
	{
		fwrite(&g,sizeof(g),1,file);
	}
	fclose(file);
}
int chk_province(char str[25])
{
	FILE *file;

	char p_name1[25];
	char p_name[25];
	int flag=0;
		strcpy(p_name,str);
		file=fopen("province.txt","rb");
		fseek(file,0,SEEK_SET);
		while(fread(p_name1,sizeof(p_name1),1,file)==1 && flag==0)
		{
			if(strcmp(p_name,p_name1)==0)
			{
				fclose(file);
				flag++;
				return 1;
			}
			
		}
		if(flag==0)
		{
			fclose(file);
			return 0;
		}
		
		
	return 0;
}
int chk_type(char str[20])
{
	int i=0,flag=0;
	while(str[i]!='\0')
	{
		if((str[i]=='v' || str[i]=='V' || str[i]=='w' || str[i]=='W' || str[i]=='G' || str[i]=='g' ||
			str[i]=='g' || str[i]=='G' || str[i]=='d' || str[i]=='D' || str[i]=='p' || str[i]=='P' ||
			str[i]=='Z' || str[i]=='z' || str[i]=='o' || str[i]=='O') && (str[i+1]==44 || str[i+1]=='\0'))
		{
			i++;
			if(str[i]=='\0')
				break;
		}
		else if(str[i]==44 && str[i+1]!='\0')
		{
			i++;
		}
		else
		{
			flag++;
			return 0;
		}
	}
	if(flag==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int chk_address(char* str)
{
	if(str[0]>47 && str[0]>58)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int chk_phone(char str[15])
{	
	if(((str[3]==45) || (str[2]==45) || (str[0]==0)) && ((strlen(str)>8) && (strlen(str)<13)) && (str[0]==48))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int chk_name(char* str)
{
	int i=0,flag=0;
	while(flag==0 && (i<(strlen(str)-1)))
	{
		if((str[i]>64 && str[i]<91) || (str[i]>96 && str[i]<123)
		 || (str[i]==46) || (str[i]==32) || (str[i]==39))
		{
			i++;
		}
		else
		{
			flag++;
		}
	}
	if(flag==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int chk_date(int d,int m,int y,int chk_mod)
{
	if(chk_mod==0)
	{
		if(d>0 && d<32 && m>0 && m<13 && y>1900 && y<2050)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if(d>0 && d<32 && m>0 && m<13)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
		
}
int chk_time(int h,int m,int d,int month,int year)
{
	time_t now;
	time (&now);
	struct tm *tm_struct = localtime(&now);
	int nhour=tm_struct->tm_hour+1;
	int nmin=tm_struct->tm_min;
	int nday=tm_struct->tm_mday;
	int nmonth=tm_struct->tm_mon+1;
	int nyear=tm_struct->tm_year+1900;
	if(year==nyear)
	{
		if(month==nmonth)
		{
			if(d==nday)
			{
				if(nhour==h)
				{
					if(nmin<m)
					{
						return 0;
					}
					else
					{
						return 1;
					}
				}
				else if(nhour>h)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else if(nday>d)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if(nmonth>month)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(nyear>year)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}							
	
int chk_investigation(int idate,int imonth,int iyear,int ihour,int imint,ghost g)
{
	
	if(iyear==g.year)
	{
		if(imonth==g.month)
		{
			if(ihour==g.hours)
			{
				if(imint>g.minutes)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
			else if(ihour>g.hours)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if(imonth>g.month)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(iyear>g.year)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int generate_code(ghost g)
{
		int n;
	int i=0;
	char in[20];
	srand(time(0));
	for(i=0;i<5;i++)
	{
		n=rand()%9999+1;
	}
	sprintf(g.code, "%d", n);
	sprintf(in, "%d", g.year);
	strcat(in,":");
	strcat(in,g.code);
	strcpy(g.code,in);
	return n;
}
	

#endif
