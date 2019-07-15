//A c-program to print a calendar of an entered month and year
#include<stdio.h>
 
#define TRUE    1
#define FALSE   0
 
int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]= 
{ 
	" ",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};
//A string with month names
 
int inputmonth(void)
{
	int month;
    	while(TRUE)
    	{ 
            //using an infinite loop and continue
    	   //and break statements, to enter correct value
	
    	   printf("Please enter a month (between 1,12) : ");
    	   scanf("%d", &month);
		   if(month<1||month>12)
		   {   
				//checking wether m onth is valid
				printf("invalid month\n");
				printf("enter in between 1 and 12\n");
				continue;
		   } 
		break;
	}
	return month;
}
 
int inputyear(void)
{
	int year;
    	while(TRUE)
	{
		printf("\nPlease enter a year (between 1583,4091) : ");
		scanf("%d", &year);
		if(year< 0)
   	    	{
    			printf("\nInvalid year value...");
    			continue;
		}
		if(year< 100)
    		year += 1900;
		if(year < 1582 || year > 4902)
		{  
      			//limits for grgorian calendar
    			printf("\nInvalid year value...");
    			continue;
		}

		break;
	}
	return year;
}
 
int determinedaycode(int month,int year)
{   
    //determining first day using zeller's congrunce
    int Day = 1, ZMonth, ZYear, daycode,k,j;
    if(month < 3)
        ZMonth = month+10;
    else
        ZMonth = month-2;
    if(ZMonth > 10)
        ZYear = year-1;
    else
        ZYear = year;
    daycode =  ((int)((13*ZMonth-1)/5)+Day+ZYear%100+
            (int)((ZYear%100)/4)-2*(int)(ZYear/100)+
            (int)(ZYear/400)+77)%7;
	return daycode;
}
 
//to determine wether leap year or not
int determineleapyear(int year)
{   
    //each year has 365.2425 days(not 365.25)
	if(year% 4 == FALSE && year%100 != FALSE || year%400 == FALSE)
	{
		days_in_month[2] = 29;
		return TRUE;
	}
	else
	{
		days_in_month[2] = 28;
		return FALSE;
	}
}
 
//to print the calendar
void calendar(int month ,int year, int daycode)
{
	int day;
        printf("\n\n\n");
		printf("\t\t\t%s", months[month]);
		printf("\n\n    ------------------------------------------");
		printf("\n\tSun  Mon  Tue  Wed  Thu  Fri  Sat\n" );
        printf("    ------------------------------------------\n\t");
		// Correct the position for the first date
		for ( day = 1; day <=  daycode ; day++ )
		{
			printf("     ");
		}
 		printf(" ");
		// Print all the dates for one month
		for ( day = 1; day <= days_in_month[month]; day++ )
		{
			printf("%2d", day );
 
			// Is day before Sat? Else start next line Sun.
			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n\t " );
		}
		printf("\n    -----------------------------------------\n");	
 
}
 
int main()
{
	
    int month, year, daycode, leapyear;
    int k=1;
    while(k==1)
    {

	    month =inputmonth();
	    year = inputyear();
	    daycode = determinedaycode(month, year);
	    determineleapyear(year);
	    calendar(month, year, daycode);
	    printf("\n\n\n u want to enter aother month?");
	    printf("\npress '1' to enter another month\n");
	    printf("press '0' to exit\n");
	    scanf("%d",&k);
    }
    return 0;
}
