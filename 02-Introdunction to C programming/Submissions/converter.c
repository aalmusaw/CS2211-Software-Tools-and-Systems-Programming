/* 'Converter' is a program that converts inputs with a
 * certain unit to an output with a related unit.
 * 
 * Author: Ali Al-Musawi
 * CS 2211a - Assignment 2
 * Fall 2019
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

void KilometerMileConverter();
void MeterFeetConverter();
void CentimeterInchConverter();
void CelsiusFahrenheitConverter();

int main() {
  printf("Welcome to Converter!\n\n");
  
  while(true) {
  int mainInput;

  printf("Select one of the following options:\n\n");
  printf("For conversion between Kilometer and Mile, press 1\n");
  printf("For conversion between Meter and Feet, press 2\n");
  printf("For conversion between Centimeter and Inch, press 3\n");
  printf("For conversion between Celsius and Fahrenheit, press 4\n");
  printf("To quit, press 5\n\n");
  scanf("%d", &mainInput);
  switch(mainInput) {
  case 1: KilometerMileConverter();
    break;
  case 2: MeterFeetConverter();
    break;
  case 3: CentimeterInchConverter();
    break;
  case 4: CelsiusFahrenheitConverter();
    break;
  case 5:
    printf("Exiting Program ... \n");
    exit(0);
  default:
    continue; // for any other integer input, simply re-loop.
  }
  }
  return 0;
}


/*
 * Function: KilometerMileConverter
 * -----------------------------------------------------
 * Converts inputs between kilometers and miles
 * Uses the approximate formula 1 mile = 1.609 km
 * There are two modes: K and M.
 * K: Converts from kilometers to miles.
 * M: Converts from miles to kilometers.  
 *
 */

void KilometerMileConverter() {
  const float ratio = 1.609; // (kilometer/mile)
  char control;
  float input;
  do {
    printf("To convert from Kilometer to Mile, press K\n");
    printf("To convert from Mile to Kilometer, press M\n");
    scanf(" %c", &control);
    bool valid = ( toupper(control) == 'K' || toupper(control) == 'M' );
    if (!valid)
      printf("Your input is invalid! You may enter either 'K' or 'M'\n");
    else break;
  }
  while (true);
 
  if (toupper(control) == 'K') {
    printf("Enter your value in Kilometers: \n");
    scanf("%f", &input);
    printf("Your value converted to Miles is: %.3f \n", (input/ratio));
   }
  else {
    printf("Enter your value in Miles: \n");
    scanf("%f", &input);
    printf("Your value converted to Kilometers is: %.3f \n", (input*ratio));
   }
}

/*
 * Function: MeterFeetConverter
 * -----------------------------------------------------
 * Converts inputs between meters and feet.
 * Uses the approximate formula 1 meter = 3.281 feet
 * There are two modes: F and M.
 * F: Converts from feet to meters.
 * M: Converts from meters to feet.
 *
 */

void MeterFeetConverter() {
  const float ratio = 3.281; // (feet/meter)
  char control;
  float input;
  do {
    printf("To convert from Meter to Feet, press M\n");
    printf("To convert from Feet to Meter, press F\n");
    scanf(" %c", &control);
    bool valid = (toupper(control) == 'F' || toupper(control) == 'M');
    if (!valid)
      printf("Your input is invalid! You may enter either 'M' or 'F'\n");
    else break;
  }
  while (true);
  if (toupper(control) == 'M') {
      printf("Enter your value in Meters: \n");
      scanf("%f", &input);
      printf("Your value converted to Feet is: %.3f \n", (input*ratio)); }                                                                                                               else {
      printf("Enter your value in Feet: \n");
      scanf("%f", &input);
      printf("Your value converted to Meters is: %.3f \n", (input/ratio)); }
}

/*
 * Function: CentimeterInchConverter
 * -----------------------------------------------------
 * Converts inputs between centimeters and inches.
 * Uses the approximate formula 1 inch = 2.54 centimeter
 * There are two modes: C and I.
 * C: Converts from centimeters to inches.
 * I: Converts from inches to centimeters.
 *
 */

void CentimeterInchConverter() {
  const float ratio = 2.540; // (centimeter/inch)
  char control;
  float input;
  do {
    printf("To convert from Centimeteres to Inches, press C\n");
    printf("To convert from Inches to Centimeteres, press I\n");
    scanf(" %c", &control);
    bool valid = (toupper(control) == 'C' || toupper(control) == 'I');
    if (!valid)                                                                                                                                                                          printf("Your input is invalid! You may enter either 'C' or 'I'\n");
    else break;
  }
  while (true);
  if (toupper(control) == 'C') {
      printf("Enter your value in Centimeters: \n");
      scanf("%f", &input);
      printf("Your value converted to Inches is: %.3f \n", (input/ratio)); }
    else {
      printf("Enter your value in Inches: \n");
      scanf("%f", &input);
      printf("Your value converted to Centimeters is: %.3f \n", (input*ratio)); }
}

/*
 * Function: CelsiusFahrenheitConverter
 * -----------------------------------------------------
 * Converts inputs between celsius and fahrenheit.
 * Uses the formula C = (F - 32)*(5/9), or equivalently:
 * F = C*(9/5) + 32
 * There are two modes: C and F.
 * C: Converts from celsius to fahrenheit.
 * F: Converts from fahrenheit to celsius.
 *
 */

void CelsiusFahrenheitConverter() {
  char control;
  float input;
  do {
    printf("To convert from Celsius to Fahrenheit, press C\n");
    printf("To convert from Fahrenheit to Celsius, press F\n");
    scanf(" %c", &control);
    bool valid = (toupper(control) == 'C' || toupper(control) == 'F');
    if (!valid)
      printf("Your input is invalid! You may enter either 'C' or 'F'\n");
    else break;
  }
  while (true);
  if (toupper(control) == 'C') {
      printf("Enter your value in Celsius: \n");
      scanf("%f", &input);
      printf("Your value converted to Fahrenheit is: %.3f \n", (input*(9.0/5.0)) + 32.0); } // Review documentation for formula
  else {
      printf("Enter your value in Fahrenheit: \n");
      scanf("%f", &input);
      printf("Your value converted to Celsius is: %.3f \n", (input - 32.0)*(5.0/9.0) ); } // Review documentaion for formula
}
