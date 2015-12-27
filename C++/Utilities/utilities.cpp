/* Utilities.c 
   Measurement Converter (Austin <-> Ireland)
	 Happy Traveling!
   Written by : Ronald MacMaster  
   Created : 9/13/15 
   Last Modified : 9/14/15    */

#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"

/*Private Menu Functions*/
void MenuPrint(void);
void MenuSelect(int conversion);
void MenuError(int error);

int main(void)
 {
	 int option; 
	 
	 while(1)
	  {
		 /*Print Conversion Menu*/
		 MenuPrint();
		 
		 /*Menu Selection Prompt*/
		 printf("Enter a number from the menu (1-11) to select a specific \n");
		 printf("conversion to perform or to quit: ");
		 scanf("%d", &option );
		 MenuSelect(option);
	  }
		 
 }

/************************Menu Functions*********************/
/* MenuPrint           */
/* Prints the Conversion Menu */
void MenuPrint(void)
 {
	printf("1. Convert a given Austin time to Irish time\n");
	printf("2. Convert a given Irish time to Austin time\n");
	printf("3. Convert a given USD value to EUR\n");
	printf("4. Convert a given EUR value to USD value\n");
	printf("5. Convert a given Fahrenheit temperature to Celsius\n");
	printf("6. Convert a given Celsius temperature to Fahrenheit\n");
	printf("7. Convert a given weight in kg to pounds, ounces\n");
	printf("8. Convert a given weight in pounds, ounces to kg\n");
	printf("9. Convert a given distance in km to miles\n");
	printf("10.Convert a given distance in miles to km\n");
	printf("11.Stop doing conversions and quit the program\n");
 }
 
/* MenuSelect           */
/* Reads User's Conversion Selection */
void MenuSelect(int conversion)
 {
	 /* Conversion Variables */
	 int AuHour, AuMinute, AuDay;       /* Time */
	 int IrHour, IrMinute, IrDay;
	 int dollars, cents; double euros;  /* Money */
	 int fahrenheit; double celsius;    /* Temperature */
	 int lb, oz; double kg;             /* Weight(Mass) */
	 double  km, mi;                    /* Distance */
	 
	 fflush(stdin); /* clear input buffer */
	 
	 /* Selection Tree */
	 /* 1) Conversion Input Prompt */
	 /* 2) Conversion Function Call */
	 /* 3) Conversion Output Prompt */
	 switch(conversion)
	  {
			case 1: /* Austin Time to Irish Time */
				printf("Enter an Austin time to be converted, expressed in hours and\n");
        printf("minutes: ");
				scanf("%d:%d", &AuHour, &AuMinute);
				fflush(stdin);
				/* Time Validation */
				if(((AuHour >= 0)&&(AuHour <= 23))&&((AuMinute >= 0)&&(AuMinute <= 59))){
						AuTimeToIr(AuHour, AuMinute, &IrHour, &IrMinute, &IrDay);
				 }
				else{
					MenuError(401);
					break;
				 }
				printf("The time in Ireland equivalent to %d:%.2d in Austin is %d:%.2d of\n", AuHour, AuMinute, IrHour, IrMinute);
				if(IrDay)
					printf("the next day.\n");
				else
					printf("the same day.\n");
				break;
			case 2: /* Irish Time to Austin Time */
				printf("Enter an Irish time to be converted, expressed in hours and\n");
        printf("minutes: ");
				scanf("%d:%d", &IrHour, &IrMinute);
				fflush(stdin);
				/* Time Validation */
				if(((IrHour >= 0)&&(IrHour <= 23))&&((IrMinute >= 0)&&(IrMinute <= 59))){
						IrTimeToAu(IrHour, IrMinute, &AuHour, &AuMinute, &AuDay);
				 }
				else{
					MenuError(402);
					break;
				 }
				printf("The time in Austin equivalent to %d:%.2d in Ireland is %d:%.2d of\n", IrHour, IrMinute, AuHour, AuMinute);
				if(AuDay)
					printf("the previous day.\n");
				else
					printf("the same day.\n");
				break;
			case 3: /* USD to EUR*/
				printf("Enter an amount in US Dollars to be converted, expressed in dollars and\n");
        printf("cents: ");
				scanf("%d . %d", &dollars, &cents);
				fflush(stdin);
				if((cents >=0) && (cents <= 99))
					euros = USDToEUR(dollars, cents);
				else
					MenuError(403);
				printf("%.2lf Euros is equivalent to $%d.%.2d in US Dollars.\n", euros, dollars, cents);
				break;
			case 4: /* EUR to USD*/
				printf("Enter an amount in Euros to be converted, expressed in Euros: ");
				scanf("%lf", &euros);
				fflush(stdin);
				EURToUSD(euros, &dollars, &cents);
				printf("$%d.%.2d in US Dollars is equivalent to %.2lf Euros.\n", dollars, cents, euros);
				break;
			case 5: /* Fahrenheit to Celsius */
				printf("Enter a temperature in Farenheit to be converted, expressed in degrees \n");
				printf("Farenheit: ");
				scanf("%d", &fahrenheit);
				fflush(stdin);
				if(fahrenheit > -460)
					celsius = fahrenheitToCelsius(fahrenheit);
				else
					MenuError(405);
				printf("%.1lf Celsius is equivalent to %d Fahrenheit.\n", celsius, fahrenheit);
				break;
			case 6: /* Celsius to Fahrenheit */
				printf("Enter a temperature in Celsius to be converted, expressed in degrees \n");
				printf("Celsius: ");
				scanf("%lf", &celsius);
				fflush(stdin);
				if(celsius > -273.15)
					fahrenheit = celsiusToFahrenheit(celsius);
				else
					MenuError(406);
				printf("%d Fahrenheit is equivalent to %.1lf Celsius.\n", fahrenheit, celsius);
				break;
			case 7: /* Kilograms to Pounds, Ounces */
				printf("Enter an amount in Kilograms to be converted, expressed in kilograms: ");
				scanf("%lf", &kg);
				fflush(stdin);
				kgToLbOz(kg, &lb, &oz);
				printf("%d lb %d oz is equivalent to %.1lf kg.\n", lb, oz, kg);
				break;
			case 8: /* Pounds, Ounces to Kilograms */
				printf("Enter an amount in Pounds and Ounces to be converted, expressed in\n");
				printf("pounds and ounces: ");
				scanf("%d lb %d oz", &lb, &oz);
				fflush(stdin);
				kg = lbOzToKg(lb, oz);
				printf("%.1lf kg is equivalent to %d lb %d oz.\n", kg, lb,oz);
				break;
			case 9: /* Kilometers to Miles */
				printf("Enter a distance in Kilometers to be converted, expressed in kilometers: ");
				scanf("%lf", &km);
				fflush(stdin);
				mi = kmToMi(km);
				printf("%lf mi is equivalent to %lf km.\n", mi, km);
				break;
			case 10: /* Miles to Kilometers */
				printf("Enter a distance in Miles to be converted, expressed in miles: ");
				scanf("%lf", &mi);
				fflush(stdin);
				km = miToKm(mi);
				printf("%lf km is equivalent to %lf mi.\n", km, mi);
				break;
			case 11: /* Quit Program */
				printf("Good Bye");
				exit(0);
				break;
			default:  /* Invalid Input */
				MenuError(400);
				break;
		}
  }

/* MenuSelect           */
/* Menu Error Handler   */
void MenuError(int error){
	switch(error){
		/* menu error 4** */
		case 400:
			printf("Error (%d): Invalid Menu Selection!\n", error); 
			break;
		case 401:
			printf("Error (%d): Invalid Austin Time!\n", error);
			break;
		case 402: 
			printf("Error (%d): Invalid Irish Time!\n", error);
			break;
		case 403:
			printf("Error (%d): Invalid US Dollars Amount! \n", error);
			printf("(try entering amount without $ sign)\n");
			break;
		case 405:
			printf("Error (%d): Fahrenheit Temperature!\n", error);
			printf("Temperature must be greater than Absolute 0 K (-460F)\n");
			break;
		case 406:
			printf("Error (%d): Fahrenheit Temperature!\n", error);
			printf("Temperature must be greater than Absolute 0 K (-273.15C)\n");
			break;
	 }
				printf("Press enter to continue");
				getchar(); fflush(stdin);
}
	
	
/**************************** Conversion Algorithms ***********************************/
/* Austin Time to Irish Time */
void AuTimeToIr(int hour, int minute, int* IrHour, int* IrMinute, int* IrDay){
	*IrDay = 0; /* Current Day by Default */
	*IrHour = hour + 6; /* 6 hr time difference */
	*IrMinute = minute; 
	/* Next Day in Ireland? */
	if(*IrHour >= 24){
		*IrDay = 1; 
	  *IrHour %= 24;
	}	
}

/* Irish Time to Austin Time */
void IrTimeToAu(int hour, int minute, int* AuHour, int* AuMinute, int* AuDay){
	*AuDay = 0; /* Current Day by Default */
	*AuHour = hour - 6; /* 6 hr time difference */
	*AuMinute = minute; 
	/* Previous Day in Austin? */
	if(*AuHour < 0){
		*AuDay = -1; 
	  *AuHour += 24;
	}	
}

/* US Dollars to Euros */
double USDToEUR(int dollars, int cents){
	double euros;
	const double EURO_RATE = 0.74;
	euros = (EURO_RATE)*(100*dollars + cents) / 100; /* (100*dollars + cents) is implicity converted to double */
	return euros;
}

/* Euros to US Dollars */
void EURToUSD(double euros, int* dollars, int* cents){
	const double DOLLAR_RATE = 1.36;
	double total = DOLLAR_RATE*euros ;
	*dollars = (int)(total); /* fractional component is dropped */
	*cents = 100*((total) - (*dollars)) + 0.5; /* cents = 100*fraction. +0.5  implements "rounding to nearest whole number" */
}

/* Farenheit to Celsius */
double fahrenheitToCelsius(int fahrenheit){
	double celsius; /* C = (5/9)(F-32) */
	const double CELSIUS_RATE = (5.0 / 9.0);
	const double CELSIUS_CONSTANT = -32.0;
	celsius = (CELSIUS_RATE)*(fahrenheit + CELSIUS_CONSTANT);
	return celsius;
}

/* Celsius to Farenheit */
int celsiusToFahrenheit(double celsius){
	int fahrenheit; /* F = (9/5)C + 32 */
	const double FAHRENHEIT_RATE = (9.0 / 5.0);
	const double FAHRENHEIT_CONSTANT = +32.0;
	fahrenheit = ((FAHRENHEIT_RATE)*(celsius) + FAHRENHEIT_CONSTANT + 0.5); /* +0.5 implements "rounding to nearest whole number" */
	return fahrenheit;
}

/* Kilograms to Pounds and Ounces */
void kgToLbOz(double kg, int* lb, int* oz){
	const double POUND_RATE = (1.0 / 0.45359237); /* 1 lb = 453.59237g */
	double total = (POUND_RATE)*kg;
	*lb = total;  /* +0.5 implements "rounding to nearest whole number" */
	*oz = 16*((total) - (int)(total)) + 0.5; /* 16 oz in 1 lb */
}

/* Pounds and Ounces to Kilograms */
double lbOzToKg(int lb, int oz){
	const double KG_RATE = 0.45359237; /* 1 lb = 453.59237g */
	double kg;
	kg = (KG_RATE)*(lb + ((double)oz / 16)); /* kg = 0.45359237*(lb + oz/16) */
	return kg;
}

/* 1km = 0.6213712 mi */
/* Kilometers to Miles */
double kmToMi(double km){
	double mi;
	const double MI_RATE = (1.0 / 0.6213712);
	mi = km * MI_RATE;
	return mi;
}

/* Miles to Kilometers */
double miToKm(double mi){
	double km;
	const double KM_RATE = 0.6213712;
	km = mi * KM_RATE;
	return km;
}