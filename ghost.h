#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>

#ifndef GHOST
#define GHOST
typedef struct
{
	int gcode;
	int inv_date; 
	int inv_year;
	int inv_month;
	int i_hour;
	int i_min;
	int date; 
	int year;
	int month;
	int minutes;
	int hours;
	char code[15];
	char EventType[20];
	char name[30];
	char phone_no[15];
	char address[50];
	char province[40];
	char result[15];
	
}ghost;


void optionsDisplay();
void search_options();
#endif
