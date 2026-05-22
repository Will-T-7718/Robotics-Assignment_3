#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Adafruit_NeoPixel.h>

#define LedS 10 //Led Strip Pin
#define NumLed 7

Adafruit_NeoPixel strip(NumLed, LedS, NEO_GRB + NEO_KHZ800);
LiquidCrystal_I2C lcd1(0x27, 16, 2);

const int pot = A2; //potentiometer
const int pBut = 8; //push button
int patchWorkFix = 9;
long randCards; 
int Ran; 
int inputPot; //
int toggle; //checks what state the button is in
int togStateOn;
int togStateOff;
unsigned long time = 0; 
unsigned long debounce = 200UL; 
bool patPlay = false;
bool ran1 = false; // genuinley the best solution i could think of
bool ran2 = false;
bool ran3 = false;
bool ran4 = false;
bool ran5 = false;
bool ran6 = false;

void setup() 
{
  Serial.begin(1500);
  strip.begin();
  strip.show(); 
  strip.setBrightness(50);
  pinMode (pot, INPUT); 
  pinMode (pBut, INPUT);
  pinMode(patchWorkFix, OUTPUT);
  lcd1.init();
  lcd1.backlight();
  lcd1.clear();
}

void loop() 
{
  toggle = digitalRead(pBut);
   if (toggle == HIGH && togStateOff == LOW && millis() - time > debounce)
  {
    if 
      (togStateOn == HIGH)
      togStateOn = LOW;
    else
      togStateOn = HIGH;
      time = millis();
      ran3 = false;
      ran4 = false;
      ran5 = false;
      ran6 = false;
  }

  digitalWrite(patchWorkFix, togStateOn);
  togStateOff = toggle;

  if (digitalRead(9) == HIGH)
  {
    buttonPress();
  }
}

void buttonPress()
{
  patternCol();
  cards();
  stripPotVal();
  potTest();
}

void potTest()
{
  inputPot = analogRead(pot);
  inputPot = map(inputPot, 0, 1023, 0, 255);
  lcd1.setCursor(0, 1);
  lcd1.print(inputPot);
  lcd1.print("   ");
}

void cards()
{
  if (inputPot > 10)
  {
    if (!ran1)
      {
        Ran = analogRead(A0);
        randomSeed(Ran);
        Ran = random(1,14);
        ran1 = true;
        lcd1.setCursor(0,0);
        lcd1.print(Ran);
        delay(2);
      }
  }
  else
  {
    lcd1.setCursor(0,0);
    lcd1.print("   ");
    ran1 = false;
  }

    if (inputPot > 42.5)
  {
    if (!ran2)
      {
        Ran = analogRead(A0);
        randomSeed(Ran);
        Ran = random(1,14);
        ran2 = true;
        lcd1.setCursor(3,0);
        lcd1.print(Ran);
        delay(2);
      }
  }
  else
  {   
    lcd1.setCursor(3,0);
    lcd1.print("   ");
    ran2 = false;
  }

  if (inputPot > 85)
  {
    if (!ran3)
      {
        Ran = analogRead(A0);
        randomSeed(Ran);
        Ran = random(1,14);
        ran3 = true;
        lcd1.setCursor(6,0);
        lcd1.print(Ran);
        delay(2);
      }
  }
  else
  {   
    lcd1.setCursor(6,0);
    lcd1.print("   ");
    ran3 = false;
  }

  if (inputPot > 127.5)
  {
    if (!ran4)
      {
        Ran = analogRead(A0);
        randomSeed(Ran);
        Ran = random(1,14);
        ran4 = true;
        lcd1.setCursor(9,0);
        lcd1.print(Ran);
        delay(2);
      }
  }
  else
  {   
    lcd1.setCursor(9,0);
    lcd1.print("   ");
    ran4 = false;
  }

  if (inputPot > 170)
  {
    if (!ran5)
      {
        Ran = analogRead(A0);
        randomSeed(Ran);
        Ran = random(1,14);
        ran5 = true;
        lcd1.setCursor(12,0);
        lcd1.print(Ran);
        delay(2);
      }
  }
  else
  {   
    lcd1.setCursor(12,0);
    lcd1.print("   ");
    ran6 = false;
  }

  if (inputPot > 212.5)
  {
    if (!ran6)
      {
        Ran = analogRead(A0);
        randomSeed(Ran);
        Ran = random(1,14);
        ran6 = true;
        lcd1.setCursor(15,0);
        lcd1.print(Ran);
        delay(2);
      }
  }
  else
  {   
    lcd1.setCursor(15,0);
    lcd1.print("   ");
    ran6 = false;
  }
}

void pattern(uint32_t color, int wait) 
{
  for(int i=0; i<LedS; i++) 
  { 
    strip.setPixelColor(i, color);        
    strip.show();                         
    delay(wait);                     
  }
}

void patternCol()
{
  if (!patPlay)
  {
    pattern(strip.Color(255, 0, 0), 40); //red
    pattern(strip.Color(127.5, 127.5, 0), 40); //yellow
    pattern(strip.Color(0, 255, 0), 40); //green
    pattern(strip.Color(0, 127.5, 127.5),40); //turquoise
    pattern(strip.Color(0, 0, 255),40); //blue
    pattern(strip.Color(127.5, 0, 127.5), 40); //magenta
    patPlay = true;
  }
}

void stripPotVal()
{
  if(inputPot > 10)
  {
    strip.setPixelColor(0, 255, 0, 0); 
    strip.show();
  }
  else
  {
    strip.setPixelColor(0, 0, 0, 0); 
    strip.show();
  }

  if(inputPot > 42.5)
  {
    strip.setPixelColor(1, 127.5, 127.5, 0); 
    strip.show();
  }
    else
  {
    strip.setPixelColor(1, 0, 0, 0); 
    strip.show();
  }

  if(inputPot > 85)
  {
    strip.setPixelColor(2, 0, 255, 0); 
    strip.show();
  }
  else
  {
    strip.setPixelColor(2, 0, 0, 0); 
    strip.show();
  }

  if(inputPot > 127.5)
  {
    strip.setPixelColor(3, 0, 127.5, 127.5); 
    strip.show();
  }
  else
  {
    strip.setPixelColor(3, 0, 0, 0); 
    strip.show();
  }

  if(inputPot > 170)
  {
    strip.setPixelColor(4, 0, 0, 255); 
    strip.show();
  }
  else
  {
    strip.setPixelColor(4, 0, 0, 0); 
    strip.show();
  }

  if(inputPot > 212.5)
  {
    strip.setPixelColor(5, 127.5, 0, 127.5); 
    strip.show();
  }
  else
  {
    strip.setPixelColor(5, 0, 0, 0); 
    strip.show();
  }
}