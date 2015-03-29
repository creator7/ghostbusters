#ifndef DELETE
#define DELETE

#include"display_All.c"


void delete(int count)
{
	ghost g;
	ghost g1;
	int i=0;
	char c;
	FILE* file;
	file=fopen("temporary.dat","rb");
	while(fread(&g,sizeof(g),1,file)==1 && count>i);
	{
		i++;
	}
			
	fclose(file);
	FILE* file1;
	file1=fopen("temporary1.dat","a+b");
	file=fopen("database.dat","rb");
	while(fread(&g1,sizeof(g1),1,file)==1)
	{
		if(g.gcode==g1.gcode)
		{
			//dont write
		}
		else
		{
			fwrite(&g1,sizeof(g1),1,file1);
		}
	}
	remove("database.dat");
	fclose(file);
	rename("temporary1.dat","database.dat");
	fclose(file1);
	system("clear");
	printf("\n\n\tRecord Deleted Successfully\n");
	printf("\nPress Enter To Continue..");
	scanf("%c",&c);
	if(c)
	{
		optionsDisplay();
	}	
}	
#endif
