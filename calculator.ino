/*
Calculator project - calculator, equations
-----------------------------
Arduino MEGA2560, LCD 1602, membrane switch module
-----------------------------
Current task: Repairing problem
Next task: Creating equations function
Problems: after exiting from calculator loop() -> that means calculator doesnt stop and making trouble in menu
Version: 0.1.1
-----------------------------
Created: 11. 3. 2024
Autor: GitHub = Orelptacnik
-----------------------------
Days wasted here: 5
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

double number;
double num1;
double num2;
double result;
char operation;
char customKey = customKeypad.getKey();
int x = 0;
int currentMillis = 0;
int exitM = 0;
//declaring variables

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
//creating a keypad

void setup() {
  exitLoop = 0;
  //allowed loop function

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

    if (customKey != NO_KEY) { //after key was pressed
      menuDetect();
      break;
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

  if (customKey) { //after key was pressed

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

        if (x % 2 == 0) { //if calculation is on first line

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
}

void menuDetect() { //if key was pressed while in menu

  if (customKey == '1') { //when 1 was pressed

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
  }

  else if (customKey == '2') { //when 2 was pressed

    lcd.clear();
    lcd.setCursor(0, 0);
    //clearing lcd

    equations();
  }

  else { //when anything else was pressed

    setup();
  }
}

void equations() { //function for equations

  lcd.print("Oh no, not");
  lcd.setCursor(0, 1);
  lcd.print("finished yet!");
  //Oh no, not finished yet!
}

void soSlow() { //when countdown runs out

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("60 seconds isn't");
  lcd.setCursor(0, 1);
  lcd.print("enough?! Restart");
  //60 seconds isn't enough?! Restart
}
