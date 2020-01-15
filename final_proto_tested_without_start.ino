#include <LiquidCrystal.h>
const int temp = 7; //sets temperature
const int inc = 5; //increase the value
const int dec = 4; //decrease the value
int buttonState = HIGH;
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;
long lastDebounceTime1 = 0;  // the last time the output pin was toggled
long debounceDelay1 = 50;
const int timer = 6; //sets the timer
const int start = 3; //starts the system
//const int etchant = 2; //controls the etchant
//const int water = 1; //controls water
LiquidCrystal lcd(13,12,11,10,9,8);
int t=0; // holds the temperature
int m=0; // holds the timing
void setup()
{
 lcd.begin(16, 2);
 Serial.begin(9600);
 pinMode(temp, INPUT_PULLUP);
 pinMode(inc, INPUT_PULLUP);
 pinMode(dec, INPUT_PULLUP);
 pinMode(timer, INPUT_PULLUP);
 pinMode(start, INPUT_PULLUP);
 /*pinMode(etchant, OUTPUT);
 pinMode(water, OUTPUT);*/
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("Agitator");
  lcd.setCursor(2,1);
  lcd.print("Configure..");
  delay(500);
  temperature();
  timing();
  /*while(digitalRead(start) == 1);
  {
    //etchant and water control
    //timer action
    }*/
}
void temperature()
{
  int state=1;
  buttonState = digitalRead(temp);
  if ( (millis() - lastDebounceTime) > debounceDelay) {
  if(buttonState==LOW)
  {
    state=0;
    lastDebounceTime = millis();
    while(state == 0)
    {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temperature");
    lcd.setCursor(2,1);
    lcd.print(t);
    delay(500);
    if ( (millis() - lastDebounceTime1) > debounceDelay1) {
    if(digitalRead(inc) == LOW)
    {
        lastDebounceTime1 = millis();
        t++;
    }
    if(digitalRead(dec) == LOW)
    {
        lastDebounceTime1 = millis();
        t--;
    }
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Temperature");
        lcd.setCursor(2,1);
        lcd.print(t);
        delay(500);
    if(digitalRead(temp)==LOW)
    {
      lastDebounceTime = millis();
      state=1;
      Serial.println(t);
    }
    }
  }
  }
  }
}
void timing()
{
  int state=1;
  buttonState = digitalRead(timer);
  if ( (millis() - lastDebounceTime) > debounceDelay) {
  if(buttonState==LOW)
  {
    state=0;
    lastDebounceTime = millis();
    while(state == 0)
    {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Timer");
    lcd.setCursor(2,1);
    lcd.print(m);
    delay(500);
    if ( (millis() - lastDebounceTime1) > debounceDelay1) {
    if(digitalRead(inc) == LOW)
    {
        lastDebounceTime1 = millis();
        m++;
    }
    if(digitalRead(dec) == LOW)
    {
        lastDebounceTime1 = millis();
        m--;
    }
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Timer");
        lcd.setCursor(2,1);
        lcd.print(m);
        delay(500);
    if(digitalRead(timer)==LOW)
    {
      lastDebounceTime = millis();
      state=1;
      Serial.println(m);
    }
    }
  }
  }
  }
}
