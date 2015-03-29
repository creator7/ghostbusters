
#include"Add.c"

void Add_modify(ghost g);
void write_mod(ghost g);

void modify(int count)
{
	ghost g;
	ghost g1;
	char c;
	int i=0;
	FILE* file;
	file=fopen("temporary.dat","rb");
	while(fread(&g,sizeof(g),1,file)==1 && count>i);
	{
		i++;
	}
			
	fclose(file);
	file=fopen("database.dat","rb");
	while(fread(&g1,sizeof(g1),1,file)==1)
	{
		if(g.gcode==g1.gcode)
		{
			fclose(file);
			Add(1,g);
		}
	}
	printf("\n\t\tRecord Modified Succesfully\n");
	printf("Press Enter To Continue..");
	scanf("%c",&c);
	if(c)
	{
		optionsDisplay();
	}
}
