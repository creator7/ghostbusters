#ifndef MAIN_MENU
#define MAIN_MENU


#include"search.c"
#include"dump.c"
#include"Add.c"

#include<unistd.h>
#define DOTS_10 ".........."
#define SPAC_10 "          "


void main_menu()
{
    char input[32];
    int enterProgram;

    while(1)
        {
		system("clear");	
        printf("\n\n                    ||=============OPTIONS============||");
        printf("\n                    || Enter 1 to Enter Ghost Busters ||");
        printf("\n                    || Enter 2 to Exit                ||");
        printf("\n                    ||================================||");
        printf("\n\n What do you want to do?:");
        fgets(input,sizeof(input),stdin);
        sscanf(input,"%d",&enterProgram);
        while(enterProgram < 1 || enterProgram > 2 )
            {
            printf("\n(Invalid option) Please enter again?:");
            fgets(input,sizeof(input),stdin);
            sscanf(input,"%d",&enterProgram);
            }

        if(enterProgram != 1)
            {
				printf("\n=========================Thank You, See you soon================================\n");
				exit(1);
            }
        else
            {
				optionsDisplay();
			}
		}
	}

void optionsDisplay()
{
	ghost g;
	int i;
	char c;
    char input[32];
    int choice;
		 system("clear");
    printf("\n\n                    ||=============OPTIONS===========||");
    printf("\n                    || Enter 1 to Display all records  ||");
    printf("\n                    || Enter 2 to Add new record       ||");
    printf("\n                    || Enter 3 to Dump database        ||");
    printf("\n                    || Enter 4 to Search for records   ||");
    printf("\n                    || Enter 5 Back To Main Menu       ||");
    printf("\n                    ||================================ ||");
    
            printf("\n\n What do you want to do?:");
            fgets(input,sizeof(input),stdin);
            sscanf(input,"%d",&choice);
            while(choice < 1 || choice > 5 )
                {
                printf("\n(Invalid option) Please enter again?:");
                fgets(input,sizeof(input),stdin);
                sscanf(input,"%d",&choice);
                }
            if(choice == 5)
                {
					main_menu();
                }
            switch(choice)
                {
                case 1:
                {
					int i;
					system("clear");
					i=display_All();
					if(i==1)
					{
						printf("No Record Found Please Enter Record First..\n\n");
					}
					printf("\n\nPress Enter To Continue.. ");
					scanf("%c",&c);
					if(c)
					{
						optionsDisplay();
					}
				}
                    
                case 2:
					Add(0,g);
					printf("Press Enter To Continue.. ");
                    scanf("%c",&c);
                    if(c)
                    optionsDisplay();
                    
                case 3:
                    dump();
                    //sleep(5);
					printf("Dumping Databse");
                     for (i = 0; i < 10000; i++)
                     {
						
						printf("\rDumping Database %d", i/100+1);
						
					 }
					 
					printf("\n");
					printf("\n\t\t\tDone..\n");	
                    printf("Pres Enter To Continue.. ");
                    scanf("%c",&c);
                    if(c)
                    {
						optionsDisplay();
					}
                
                case 4:
                {
					
	FILE* file;
	file=fopen("database.dat","rb");
	char c;
                
				if(file==NULL)
				{
					system("clear");
					printf("Database is empty!!\nEnter Record First\n");
					printf("Press Enter To Continue..");
					scanf("%c",&c);
					if(c)
					{
						optionsDisplay();
					}
				}
				else
				{
					search_options();
				}
			}
    }
}
void   search_options()
    {
		system("clear");
	char c;
    char input[32];
    int search_choice;
    //variables for searching..
    char evnt[20];
    int year;
    int code;
			printf("\n\n                    ||=============OPTIONS============||");
        printf("\n                    || Enter 1 to Search By Year         ||");
        printf("\n                    || Enter 2 to Search By Code         ||");
        printf("\n                    || Enter 3 to Search By Event        ||");
		printf("\n                    || Enter 4 Back To Previous Menu     ||");	
        printf("\n                    ||================================||");
        printf("\n\n What do you want to do?:");
				fgets(input,sizeof(input),stdin);
				sscanf(input,"%d",&search_choice);
				while(search_choice < 1 || search_choice > 4 )
                {
					printf("\n(Invalid option) Please enter again?:");
					fgets(input,sizeof(input),stdin);
					sscanf(input,"%d",&search_choice);
                }
                if(search_choice == 4)
                {
					optionsDisplay();
				}
				switch(search_choice)
				{
					case 1:
							printf("\tYear(2000-2050):  ");
							fgets(input,sizeof(input),stdin);
							sscanf(input,"%d",&year);
							search_year(year);
							printf("Press Enter To Continue..");
							scanf("%c",&c);
							if(c)
							{
								search_options();
							}
					case 2:
							printf("Enter Code: ");
							fgets(input,sizeof(input),stdin);
							sscanf(input,"%d",&code);
							
							search_code(code);
							search_options();
					case 3:
					{
							x:
							printf("Enter Event: ");
							fgets(input,sizeof(input),stdin);
							sscanf(input,"%s",evnt);
							if(!chk_type(evnt))
							{
								printf("Not Valid!!\n");
								goto x;
							}
								search_event(evnt);
								printf("Press Enter To Continue..");
								scanf("%c",&c);
								if(c)
								{
									search_options();
								}
							
						}
				}
			}


#endif
