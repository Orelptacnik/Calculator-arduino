/*
Calculator project - calculator, equations
-----------------------------
Arduino MEGA2560, LCD 1602, membrane switch module
-----------------------------
Current task: repairing problem
Next task: mini game
Problems: after second comeback to menu countdown doesn't display
Version: 0.2.0
-----------------------------
Created: 11. 3. 2024
Autor: GitHub = Orelptacnik
-----------------------------
Days wasted here: 6
*/

#include "Keypad.h"
#include "LiquidCrystal.h"
//libraries

const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
//lcd display pins

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
//lcd display setup

const byte ROWS = 4;
const byte COLS = 4;
//dimensions of keypad

char hexaKeys[ROWS][COLS] = {
  { '1', '2', '3', '+' },
  { '4', '5', '6', '-' },
  { '7', '8', '9', '/' },
  { '*', '0', '#', '=' }
};
//adding values to keys

byte rowPins[ROWS] = { 5, 4, 3, 2 };
byte colPins[COLS] = { A1, A2, A3, A4 };
//keypad pins

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
//creating a keypad

double number;
double num1;
double num2;
double result;
char operation;
char customKey;
int a = 0;
int currentMillis = 0;
int exitM = 0;
int switchDetect;
double equalTimes = 0;
double stX;
double stY;
double stResult;
double ndX;
double ndY;
double ndResult;
double det;
double x;
double y;

//declaring variables

void setup() {

  switchDetect = 0;

  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Calculator 0.1.1");
  lcd.setCursor(0, 1);
  lcd.print("----------------");
  delay(3000);
  //Calculator 0.1.1

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Press: 1 = Calc.");
  lcd.setCursor(0, 1);
  lcd.print("2 = equations");
  //menu

  lcd.setCursor(14, 1); //set cursor for countdown
  
  while ((millis() - currentMillis) / 1000 < 66) { //run for 60 seconds

    customKey = customKeypad.getKey();

    if (customKey) { //after key was pressed
      menuDetect();
      break;
      Serial.println("toto funguje");
    }

    if ((60 - ((millis() - currentMillis) / 1000 - 3)) < 10) { //countown when number is lower than 10
      lcd.setCursor(14, 1);
      lcd.print('0');
      lcd.print(60 - ((millis() - currentMillis) / 1000 - 3));
    }

    else { //countdown when number is 10 and higher
      lcd.setCursor(14, 1);
      lcd.print(60 - ((millis() - currentMillis) / 1000 - 3));
      Serial.println(millis());
      delay(1000);
    }

    if ((60 - ((millis() - currentMillis) / 1000 - 3)) < 1) { //after countdown ends
      lcd.clear();
      soSlow();
      break;
    }
  }
  //countdown and wait in the menu
}
//run when arduino was started or after exiting from calculator or equations

void loop() { //run for the whole time after setup() was executed and ended

  customKey = customKeypad.getKey();

  if (customKey) { //after key was pressed

    if (switchDetect == 0) { //when keys are pressed in menu

      menuDetect();
    }

    else if (switchDetect == 1) { //when keys are pressed in calculator

      calculatorDetect();
    }

    else if (switchDetect == 2) { //when keys are pressed in equations

      equationsDetect();
    }

    else if (switchDetect == 3) { //when keys are pressed in equations result

      eqResultDetect();
    }
  }
}

void calculatorDetect() {

  if (customKey != '=') { //every other key than =
  
    if (customKey == '0') { //when 0 was pressed
    
      if (number == 0) {
        number = 0;
      }
      else {
        number = (number * 10) + 0;
      }
      //if other number already exist it's neccesary to multiple it by 10 and then add it to the number
      lcd.print(customKey);
    }

    if (customKey == '1') { //when 1 was pressed

      if (number == 0) {
        number = 1;
      }
      else {
        number = (number * 10) + 1;
      }
      //if other number already exist it's neccesary to multiple it by 10 and then add it to the number
      lcd.print(customKey);
    }

    if (customKey == '2') { //when 2 was pressed

      if (number == 0) {
        number = 2;
      }
      else {
        number = (number * 10) + 2;
      }
      //if other number already exist it's neccesary to multiple it by 10 and then add it to the number
      lcd.print(customKey);
    }

    if (customKey == '3') { //when 3 was pressed

      if (number == 0) {
        number = 3;
      }
      else {
        number = (number * 10) + 3;
      }
      //if other number already exist it's neccesary to multiple it by 10 and then add it to the number
      lcd.print(customKey);
    }

    if (customKey == '4') { //when 4 was pressed

      if (number == 0) {
        number = 4;
      }
      else {
        number = (number * 10) + 4;
      }
      //if other number already exist it's neccesary to multiple it by 10 and then add it to the number
      lcd.print(customKey);
    }

    if (customKey == '5') { //when 5 was pressed

      if (number == 0) {
        number = 5;
      }
      else {
        number = (number * 10) + 5;
      }
      //if other number already exist it's neccesary to multiple it by 10 and then add it to the number
      lcd.print(customKey);
    }

    if (customKey == '6') { //when 6 was pressed

      if (number == 0) {
        number = 6;
      }
      else {
        number = (number * 10) + 6;
      }
      //if other number already exist it's neccesary to multiple it by 10 and then add it to the number
      lcd.print(customKey);
    }

    if (customKey == '7') { //when 7 was pressed

      if (number == 0) {
        number = 7;
      }
      else {
        number = (number * 10) + 7;
      }
      //if other number already exist it's neccesary to multiple it by 10 and then add it to the number
      lcd.print(customKey);
    }

    if (customKey == '8') { //when 8 was pressed

      if (number == 0) {
        number = 8;
      }
      else {
        number = (number * 10) + 8;
      }
      //if other number already exist it's neccesary to multiple it by 10 and then add it to the number
      lcd.print(customKey);
    }

    if (customKey == '9') { //when 9 was pressed

      if (number == 0) {
        number = 9;
      }
      else {
        number = (number * 10) + 9;
      }
      //if other number already exist it's neccesary to multiple it by 10 and then add it to the number
      lcd.print(customKey);
    }

    if (customKey == '+') { //after + was pressed (A)

      operation = '+'; //deciding what to do with the numbers
      num1 = number;
      number = 0;
      //storing value of the first number
      lcd.print(customKey);
    }

    if (customKey == '-') { //after - was pressed (B)

      operation = '-'; //deciding what to do with the numbers
      num1 = number;
      number = 0;
      //storing value of the first number
      lcd.print(customKey);
    }

    if (customKey == '/') { //after / was pressed (C)

      operation = '/'; //deciding what to do with the numbers
      num1 = number;
      number = 0;
      //storing value of the first number
      lcd.print(customKey);
    }

    if (customKey == '*') { //after * was pressed (*)

      operation = '*'; //deciding what to do with the numbers
      num1 = number;
      number = 0;
      //storing value of the first number

      exitM++; //increasing number of times when * is pressed -> 3 = exit from calculator
      lcd.print(customKey);
    }

    if (customKey == '#') { //# was pressed

      number = 0;
      lcd.clear();
      x = 0;
      //clear everything
    }
  }

  else { //after '=' was pressed
  
    if (exitM == 3) { //check if * was pressed 3 times

      x = 0;
      number = 0;
      num1 = 0;
      num2 = 0;
      exitM = 0;
      lcd.clear();
      lcd.setCursor(0, 0);
      currentMillis = millis();
      setup();
      //clear everything and go to menu
    }

    else { //if * wasn't pressed 3 times

      if (operation == '+') { //operation is addition

        num2 = number;
        result = num1 + num2;
        //storing value of the second number and calculating
      }

      else if (operation == '-') { //operation is subtraction

        num2 = number;
        result = num1 - num2;
        //storing value of the second number and calculating
      }
      
      else if (operation == '/') { //operation is division

        num2 = number;
        result = num1 / num2;
        //storing value of the second number and calculating
      }

      else if (operation == '*') { //operation is multiplication

        num2 = number;
        result = num1 * num2;
        //storing value of the second number and calculating
      }

      if (a % 2 == 0) { //if calculation is on first line

        lcd.setCursor(0, 1);
        lcd.print("                ");
        lcd.setCursor(0, 1);
        lcd.print(result);
        x++;
      }

      else { //if calculation is on second line

        lcd.setCursor(0,0);
        lcd.print("                ");
        lcd.setCursor(0, 0);
        lcd.print(result);
        x++;
      }

      num1 = 0;
      num2 = 0;
      number = result;
      exitM = 0;
      //deleting values and result = first number
    }
  }
}

void menuDetect() { //if key was pressed while in menu

  if (customKey == '1') { //when 1 was pressed

    switchDetect = 1; //loop() wil use calculator-defined keys

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Use only 2 num.");
    lcd.setCursor(0, 1);
    lcd.print("per line!  UwU");
    delay(3000);
    //Use only two numbers

    lcd.clear();
    lcd.setCursor(0, 0);
    //clearing lcd

    loop();
    calculatorDetect();
  }

  else if (customKey == '2') { //when 2 was pressed

    switchDetect = 2;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("    x+    y=    ");
    lcd.setCursor(0, 1);
    lcd.print("    x+    y=    ");
    lcd.setCursor(0, 0);
    //set the interface of equations

    equationsDetect();
  }

  else { //when anything else was pressed

    switchDetect = 0;
    setup();
  }
}

void equationsDetect() { //if key was pressed while in equations

  if (customKey == '0') { //when 0 was pressed
    
    if (equalTimes == 0) { //first x
      
      if (stX == 0) {
        stX = 0;
      }
      else {
        stX = stX * 10 + 0;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 1) { //first y
      
      if (stY == 0) {
        stY = 0;
      }
      else {
        stY = stY * 10 + 0;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 2) { //first result
      
      if (stResult == 0) {
        stResult = 0;
      }
      else {
        stResult = stResult * 10 + 0;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 3) { //second x
      
      if (ndX == 0) {
        ndX = 0;
      }
      else {
        ndX = ndX * 10 + 0;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 4) { //second y
      
      if (ndY == 0) {
        ndY = 0;
      }
      else {
        ndY = ndY * 10 + 0;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 5) { //second result
      
      if (ndResult == 0) {
        ndResult = 0;
      }
      else {
        ndResult = ndResult * 10 + 0;
      }

      lcd.print(customKey);
    }
  }

  if (customKey == '1') { //when 1 was pressed
    
    if (equalTimes == 0) { //first x
      
      if (stX == 0) {
        stX = 1;
      }
      else {
        stX = stX * 10 + 1;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 1) { //first y
      
      if (stY == 0) {
        stY = 1;
      }
      else {
        stY = stY * 10 + 1;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 2) { //first result
      
      if (stResult == 0) {
        stResult = 1;
      }
      else {
        stResult = stResult * 10 + 1;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 3) { //second x
      
      if (ndX == 0) {
        ndX = 1;
      }
      else {
        ndX = ndX * 10 + 1;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 4) { //second y
      
      if (ndY == 0) {
        ndY = 1;
      }
      else {
        ndY = ndY * 10 + 1;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 5) { //second result
      
      if (ndResult == 0) {
        ndResult = 1;
      }
      else {
        ndResult = ndResult * 10 + 1;
      }

      lcd.print(customKey);
    }
  }

  if (customKey == '2') { //when 2 was pressed
    
    if (equalTimes == 0) { //first x
      
      if (stX == 0) {
        stX = 2;
      }
      else {
        stX = stX * 10 + 2;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 1) { //first y
      
      if (stY == 0) {
        stY = 2;
      }
      else {
        stY = stY * 10 + 2;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 2) { //first result
      
      if (stResult == 0) {
        stResult = 3;
      }
      else {
        stResult = stResult * 10 + 3;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 3) { //second x
      
      if (ndX == 0) {
        ndX = 3;
      }
      else {
        ndX = ndX * 10 + 3;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 4) { //second y
      
      if (ndY == 0) {
        ndY = 3;
      }
      else {
        ndY = ndY * 10 + 3;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 5) { //second result
      
      if (ndResult == 0) {
        ndResult = 3;
      }
      else {
        ndResult = ndResult * 10 + 3;
      }

      lcd.print(customKey);
    }
  }

  if (customKey == '3') { //when 3 was pressed
    
    if (equalTimes == 0) { //first x
      
      if (stX == 0) {
        stX = 3;
      }
      else {
        stX = stX * 10 + 3;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 1) { //first y
      
      if (stY == 0) {
        stY = 3;
      }
      else {
        stY = stY * 10 + 3;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 2) { //first result
      
      if (stResult == 0) {
        stResult = 3;
      }
      else {
        stResult = stResult * 10 + 3;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 3) { //second x
      
      if (ndX == 0) {
        ndX = 3;
      }
      else {
        ndX = ndX * 10 + 3;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 4) { //second y
      
      if (ndY == 0) {
        ndY = 3;
      }
      else {
        ndY = ndY * 10 + 3;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 5) { //second result
      
      if (ndResult == 0) {
        ndResult = 3;
      }
      else {
        ndResult = ndResult * 10 + 3;
      }

      lcd.print(customKey);
    }
  }

  if (customKey == '4') { //when 4 was pressed
    
    if (equalTimes == 0) { //first x
      
      if (stX == 0) {
        stX = 4;
      }
      else {
        stX = stX * 10 + 4;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 1) { //first y
      
      if (stY == 0) {
        stY = 4;
      }
      else {
        stY = stY * 10 + 4;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 2) { //first result
      
      if (stResult == 0) {
        stResult = 4;
      }
      else {
        stResult = stResult * 10 + 4;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 3) { //second x
      
      if (ndX == 0) {
        ndX = 4;
      }
      else {
        ndX = ndX * 10 + 4;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 4) { //second y
      
      if (ndY == 0) {
        ndY = 4;
      }
      else {
        ndY = ndY * 10 + 4;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 5) { //second result
      
      if (ndResult == 0) {
        ndResult = 4;
      }
      else {
        ndResult = ndResult * 10 + 4;
      }

      lcd.print(customKey);
    }
  }

  if (customKey == '5') { //when 5 was pressed
    
    if (equalTimes == 0) { //first x
      
      if (stX == 0) {
        stX = 5;
      }
      else {
        stX = stX * 10 + 5;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 1) { //first y
      
      if (stY == 0) {
        stY = 5;
      }
      else {
        stY = stY * 10 + 5;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 2) { //first result
      
      if (stResult == 0) {
        stResult = 5;
      }
      else {
        stResult = stResult * 10 + 5;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 3) { //second x
      
      if (ndX == 0) {
        ndX = 5;
      }
      else {
        ndX = ndX * 10 + 5;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 4) { //second y
      
      if (ndY == 0) {
        ndY = 5;
      }
      else {
        ndY = ndY * 10 + 5;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 5) { //second result
      
      if (ndResult == 0) {
        ndResult = 5;
      }
      else {
        ndResult = ndResult * 10 + 5;
      }

      lcd.print(customKey);
    }
  }

  if (customKey == '6') { //when 6 was pressed
    
    if (equalTimes == 0) { //first x
      
      if (stX == 0) {
        stX = 6;
      }
      else {
        stX = stX * 10 + 6;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 1) { //first y
      
      if (stY == 0) {
        stY = 6;
      }
      else {
        stY = stY * 10 + 6;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 2) { //first result
      
      if (stResult == 0) {
        stResult = 6;
      }
      else {
        stResult = stResult * 10 + 6;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 3) { //second x
      
      if (ndX == 0) {
        ndX = 6;
      }
      else {
        ndX = ndX * 10 + 6;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 4) { //second y
      
      if (ndY == 0) {
        ndY = 6;
      }
      else {
        ndY = ndY * 10 + 6;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 5) { //second result
      
      if (ndResult == 0) {
        ndResult = 6;
      }
      else {
        ndResult = ndResult * 10 + 6;
      }

      lcd.print(customKey);
    }
  }

  if (customKey == '7') { //when 7 was pressed
    
    if (equalTimes == 0) { //first x
      
      if (stX == 0) {
        stX = 7;
      }
      else {
        stX = stX * 10 + 7;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 1) { //first y
      
      if (stY == 0) {
        stY = 7;
      }
      else {
        stY = stY * 10 + 7;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 2) { //first result
      
      if (stResult == 0) {
        stResult = 7;
      }
      else {
        stResult = stResult * 10 + 7;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 3) { //second x
      
      if (ndX == 0) {
        ndX = 7;
      }
      else {
        ndX = ndX * 10 + 7;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 4) { //second y
      
      if (ndY == 0) {
        ndY = 7;
      }
      else {
        ndY = ndY * 10 + 7;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 5) { //second result
      
      if (ndResult == 0) {
        ndResult = 7;
      }
      else {
        ndResult = ndResult * 10 + 7;
      }

      lcd.print(customKey);
    }
  }

  if (customKey == '8') { //when 8 was pressed
    
    if (equalTimes == 0) { //first x
      
      if (stX == 0) {
        stX = 8;
      }
      else {
        stX = stX * 10 + 8;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 1) { //first y
      
      if (stY == 0) {
        stY = 8;
      }
      else {
        stY = stY * 10 + 8;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 2) { //first result
      
      if (stResult == 0) {
        stResult = 8;
      }
      else {
        stResult = stResult * 10 + 8;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 3) { //second x
      
      if (ndX == 0) {
        ndX = 8;
      }
      else {
        ndX = ndX * 10 + 8;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 4) { //second y
      
      if (ndY == 0) {
        ndY = 8;
      }
      else {
        ndY = ndY * 10 + 8;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 5) { //second result
      
      if (ndResult == 0) {
        ndResult = 8;
      }
      else {
        ndResult = ndResult * 10 + 8;
      }

      lcd.print(customKey);
    }
  }

  if (customKey == '9') { //when 9 was pressed
    
    if (equalTimes == 0) { //first x
      
      if (stX == 0) {
        stX = 9;
      }
      else {
        stX = stX * 10 + 9;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 1) { //first y
      
      if (stY == 0) {
        stY = 9;
      }
      else {
        stY = stY * 10 + 9;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 2) { //first result
      
      if (stResult == 0) {
        stResult = 9;
      }
      else {
        stResult = stResult * 10 + 9;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 3) { //second x
      
      if (ndX == 0) {
        ndX = 9;
      }
      else {
        ndX = ndX * 10 + 9;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 4) { //second y
      
      if (ndY == 0) {
        ndY = 9;
      }
      else {
        ndY = ndY * 10 + 9;
      }

      lcd.print(customKey);
    }

    if (equalTimes == 5) { //second result
      
      if (ndResult == 0) {
        ndResult = 9;
      }
      else {
        ndResult = ndResult * 10 + 9;
      }

      lcd.print(customKey);
    }
  }

  if (customKey == '+') { //when + (A) was pressed

    if (equalTimes == 0) { //when stX was filled

      lcd.setCursor(6, 0);
    }

    if (equalTimes == 1) { //when stY was filled

      lcd.setCursor(12, 0);
    }

    if (equalTimes == 2) { //when stResult was filled

      lcd.setCursor(0, 1);
    }

    if (equalTimes == 3) { //when ndX was filled

      lcd.setCursor(6, 1);
    }

    if (equalTimes == 4) { //when ndY was filled

      lcd.setCursor(12, 1);
    }

    if (equalTimes == 5) { //when ndResult was filled

      equationsCalculate();
    }

    equalTimes++;
  }

  if (customKey == '-') { //when - (B) was pressed

    if (equalTimes == 0) { //first x
      
      stX = -stX;
      lcd.setCursor(0, 0);
      lcd.print(stX);
    }

    if (equalTimes == 1) { //first y
      
      stY = -stY;
      lcd.setCursor(6, 0);
      lcd.print(stY);
    }

    if (equalTimes == 2) { //first X
      
      stResult = -stResult;
      lcd.setCursor(12, 0);
      lcd.print(stResult);
    }

    if (equalTimes == 3) { //second x
      
      ndX = -ndX;
      lcd.setCursor(0, 1);
      lcd.print(ndX);
    }

    if (equalTimes == 4) { //second y
      
      ndY = -ndY;
      lcd.setCursor(6, 1);
      lcd.print(ndY);
    }

    if (equalTimes == 5) { //second result
      
      ndResult = -ndResult;
      lcd.setCursor(12, 1);
      lcd.print(ndResult);
    }
  }

  if (customKey == '/') { //when / (C) is pressed

    if (equalTimes == 0) { // first x

      lcd.setCursor(0, 0);
      lcd.print("    ");
      lcd.setCursor(0, 0);
      stX = 0;
      //deleting current number
    }

    if (equalTimes == 1) { // first y

      lcd.setCursor(6, 0);
      lcd.print("    ");
      lcd.setCursor(6, 0);
      stY = 0;
      //deleting current number
    }

    if (equalTimes == 2) { // first result

      lcd.setCursor(12, 0);
      lcd.print("    ");
      lcd.setCursor(12, 0);
      stResult = 0;
      //deleting current number
    }

    if (equalTimes == 3) { // second x

      lcd.setCursor(0, 1);
      lcd.print("    ");
      lcd.setCursor(0, 1);
      ndX = 0;
      //deleting current number
    }

    if (equalTimes == 4) { // second y

      lcd.setCursor(6, 1);
      lcd.print("    ");
      lcd.setCursor(6, 1);
      ndY = 0;
      //deleting current number
    }

    if (equalTimes == 5) { // second result

      lcd.setCursor(12, 1);
      lcd.print("    ");
      lcd.setCursor(12, 1);
      ndResult = 0;
      //deleting current number
    }
  }

  if (customKey == '=') { //when = (D) was pressed

    equationsCalculate();
  }

  if (customKey == '#') { // when # was pressed

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("    x+    y=    ");
    lcd.setCursor(0, 1);
    lcd.print("    x+    y=    ");
    lcd.setCursor(0, 0);
    //set the interface of equations

    equalTimes = 0;
    stX = 0;
    stY = 0;
    stResult = 0;
    ndX = 0;
    ndY = 0;
    ndResult = 0;
    //clearing values
  }

  if (customKey == '*') { //when * was pressed

    if (equalTimes == 0) { // first x

      lcd.setCursor(0, 0);
      lcd.print("    ");
      lcd.setCursor(0, 0);
      stX = 0;
      //deleting current number
    }

    if (equalTimes == 1) { // first y

      lcd.setCursor(0, 0);
      lcd.print("    ");
      lcd.setCursor(0, 0);
      stX = 0;
      //deleting current number
      
      equalTimes--;
    }

    if (equalTimes == 2) { // first result

      lcd.setCursor(6, 0);
      lcd.print("    ");
      lcd.setCursor(6, 0);
      stY = 0;
      //deleting current number
      
      equalTimes--;
    }

    if (equalTimes == 3) { // second x

      lcd.setCursor(12, 0);
      lcd.print("    ");
      lcd.setCursor(12, 0);
      stResult = 0;
      //deleting current number
      
      equalTimes--;
    }

    if (equalTimes == 4) { // second y

      lcd.setCursor(0, 1);
      lcd.print("    ");
      lcd.setCursor(0, 1);
      ndX = 0;
      //deleting current number
      
      equalTimes--;
    }

    if (equalTimes == 5) { // second result

      lcd.setCursor(6, 1);
      lcd.print("    ");
      lcd.setCursor(6, 1);
      ndY = 0;
      //deleting current number

      equalTimes--;
    }
  }
}

void equationsCalculate() {

  det = stX * ndY - stY * ndX;
  //determinant

  if (det == 0) { //no solution

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No solution");
    lcd.setCursor(0, 1);
    lcd.print("1=new, 2=menu");
    //printing result

    equalTimes = 0;
    stX = 0;
    stY = 0;
    stResult = 0;
    ndX = 0;
    ndY = 0;
    ndResult = 0;
    x = 0;
    y = 0;
    //clearing values

    switchDetect = 3;
  }
  else {

    x = (stResult * ndY - stY * ndResult) / det; //calculation of x
    
    y = (stX * ndResult - stResult * ndX) /det; //calculation of y

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("x=");
    lcd.print(x);
    lcd.print(" y=");
    lcd.print(y);
    lcd.setCursor(0, 1);
    lcd.print("1=new, 2=menu");
    //printing result

    equalTimes = 0;
    stX = 0;
    stY = 0;
    stResult = 0;
    ndX = 0;
    ndY = 0;
    ndResult = 0;
    x = 0;
    y = 0;
    //clearing values

    switchDetect = 3;
  }
}

void eqResultDetect() {

  if (customKey == '1') { //when 1 was pressed

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("    x+    y=    ");
    lcd.setCursor(0, 1);
    lcd.print("    x+    y=    ");
    lcd.setCursor(0, 0);
    //set the interface of equations

    equalTimes = 0;
    stX = 0;
    stY = 0;
    stResult = 0;
    ndX = 0;
    ndY = 0;
    ndResult = 0;
    x = 0;
    y = 0;
    //clearing values

    equationsDetect();
  }

  else if (customKey == '2') { //when 2 was pressed

    lcd.clear();
    lcd.setCursor(0, 0);
    //clearing lcd

    equalTimes = 0;
    stX = 0;
    stY = 0;
    stResult = 0;
    ndX = 0;
    ndY = 0;
    ndResult = 0;
    x = 0;
    y = 0;
    //clearing values

    currentMillis = millis();
    setup();
  }

  else { //when anything else was pressed

    //do nothing
  }
}

void soSlow() { //when countdown runs out

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("60 seconds isn't");
  lcd.setCursor(0, 1);
  lcd.print("enough?! Restart");
  //60 seconds isn't enough?! Restart
}
