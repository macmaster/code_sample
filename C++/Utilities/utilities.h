/*
 * AuTimeToIr : Converts a given time in Austin to the equivalent time in Ireland
 * hour: hour in Austin
 * minute : minute in Austin
 * IrHour : pointer to where hour in Ireland will be stored
 * IrMinute : pointer to where minute in Ireland will be stored
 * IrDay : pointer to where day (previous, same, next) will be stored
 *
 * The time in Austin will be given by hour and minute. After execution, the ints pointed to
 * by IrHour and IrMinute should hold the equivalent time in Ireland
 * IrDay should point to an int that will have the value:
 * -1 if the time in Ireland corresponds to the previous day
 *  0 if the time in Ireland corresponds to the same day
 *  1 if the time in Ireland corresponds to the next day
 */
void AuTimeToIr(int hour, int minute, int* IrHour, int* IrMinute, int* IrDay);

/*
 * IrTimeToAu : Converts a given time in Ireland to the equivalent time in Austin
 * hour: hour in Ireland
 * minute : minute in Ireland
 * AuHour : pointer to where hour in Austin will be stored
 * AuMinute : pointer to where minute in Austin will be stored
 * AuDay : pointer to where day (previous, same, next) will be stored
 *
 * The time in Ireland will be given by hour and minute. After execution, the ints pointed to
 * by AuHour and AuMinute should hold the equivalent time in Austin
 * AuDay should point to an int that will have the value:
 * -1 if the time in Austin corresponds to the previous day
 *  0 if the time in Austin corresponds to the same day
 *  1 if the time in Austin corresponds to the next day
 */
void IrTimeToAu(int hour, int minute, int* AuHour, int* AuMinute, int* AuDay);

/*
 * USDToEUR : Converts a given dollar and cent amount to euros
 * dollars : how many dollars
 * cents : how many cents
 *
 * returns : equivalent value in Euros
 */
double USDToEUR(int dollars, int cents);

/*
 * EURToUSD : Converts a given euro amount into dollars and cents
 * euros : how many euros
 * dollars : pointer to where dollar amount will be stored
 * cents : pointer to where cent amount will be stored
 *
 * After execution, the ints pointed to by dollars and cents will hold the equivalent
 * monetary amount in USD
 */
void EURToUSD(double euros, int* dollars, int* cents);

/* fahrenheitToCelsius : Converts a temperature in Fahrenheit to Celsius
 * fahrenheit : the temperature in Fahrenheit
 *
 * returns : the equivalent temperature in Celsius
 */
double fahrenheitToCelsius(int fahrenheit);

/* celsiusToFahrenheit : Converts a temperature in Celsius to Fahrenheit
 * celsius : the temperature in Celsius
 *
 * returns : the equivalent temperature in Fahrenheit
 */
int celsiusToFahrenheit(double celsius);

/* kgToLbOz : Converts a weight in kilograms to pounds and ounces
 * kg : the weight in kilograms
 * lb : pointer to where pound amount will be stored
 * oz : pointer to where ounce amount will be stored
 *
 * after execution, the ints pointed to by lb and oz should hold the
 * equivalent weight in pounds and ounces
 */
void kgToLbOz(double kg, int* lb, int* oz);

/* lbOzToKg : Converts a weight in pounds and ounces to kilograms
 * lb : pounds
 * oz : ounces
 *
 * returns : equivalent weight in kilograms
 */
double lbOzToKg(int lb, int oz);

/* kmToMi : Converts a distance in kilometers to miles
 * km : distance in kilometers
 *
 * returns : equivalent distance in miles
 */
double kmToMi(double km);

/* miToKm : Converts a distance in miles to kilometers
 * mi : distance in miles
 *
 * returns : equivalent distance in kilometers
 */
double miToKm(double mi);