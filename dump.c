#include"ghost.h"

void dump()
{
	int count=0;
	ghost g;
	char c;
	FILE *dfile;		//preiously created binary file.
	FILE *dumptxt;		//create new txt file using dump file*.
	dfile=fopen("database.dat","rb+");
	if(dfile==NULL)
	{	
		system("clear");
		printf("file not found!!");
		printf("Press Enter To Continue..");
		scanf("%c",&c);
		if(c)
		{
			optionsDisplay();
		}
	}
	else
	{	
	
		dumptxt=fopen("dump.txt","w+");
		
		fseek(dumptxt,0,SEEK_SET);
		while(fread(&g,sizeof(g),1,dfile)==1)
		{
			count++;
			fprintf(dumptxt,"\t\tRecord # %d",count);
			fprintf(dumptxt,"\n\nCode:  %d:%d",g.year,g.gcode);
			fprintf(dumptxt,"\t\t\tDate %d-%d-%d",g.year,g.month,g.date);
			fprintf(dumptxt,"\t\tTime: %d:%d",g.hours,g.minutes);
			fprintf(dumptxt,"\n\t\t\tInvestigation Date  %d-%d-%d",g.inv_year,g.inv_month,g.inv_date);
			fprintf(dumptxt,"\t\tTime: %d:%d",g.i_hour,g.i_min);
			fprintf(dumptxt,"\n\n\t\tEvent:  %s\n",g.EventType);
			fprintf(dumptxt,"\t\tName : %s\n",g.name);
			fprintf(dumptxt,"\t\tPhone-no: %s\n",g.phone_no);
			fprintf(dumptxt,"\t\tAddress : %s\n",g.address);
			fprintf(dumptxt,"\t\tProvince : %s\n\n",g.province);
			fprintf(dumptxt,"\t\tResult : %s",g.result);
			
		}
		fclose(dumptxt);
	}
	fclose(dfile);
};
