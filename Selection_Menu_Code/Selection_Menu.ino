#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
  



//Define the pins you are connecting the LCD too. 
//PCD8544(SCLK, DIN/MOSI, D/C, SCE/CS, RST); 

Adafruit_PCD8544 nokia = Adafruit_PCD8544(3,4,5,7,6); 
int counter = 1;

void printHello(int x)
{
  nokia.clearDisplay();
  for (int i = 0; i < 6; i++)
  {
    if (i == x)
    {
      nokia.setTextColor(0, 1);      
    }
    nokia.println("Hello! Wolrd");
    nokia.setTextColor(1, 0);
  }
  nokia.display();
}
void setup(void)
{
  
  pinMode(2, INPUT);
  Serial.begin(9600);
  nokia.begin(); //Initialize lcd
  // set display to normal mode
  nokia.setContrast(50);
  nokia.display();
  //nokia.command(PCD8544_DISPLAYCONTROL | PCD8544_DISPLAYNORMAL);
  nokia.clearDisplay(); //clears the display.
  
  printHello(0);
  
  nokia.display();
 
}

void loop(void)
{
  int ButtonState = digitalRead(2);
  delay(200);
  Serial.println(counter, DEC);
  if(ButtonState)
  {
    Serial.println(counter, DEC);
    
    printHello(counter);
    counter++;
  }
  if (counter >= 6)
  {
    counter = 0;
  }
} 
