// This #include statement was automatically added by the Particle IDE.
#include "Adafruit_TCS34725/Adafruit_TCS34725.h"



// This #include statement was automatically added by the Particle IDE.
#include "Adafruit_SSD1306/Adafruit_SSD1306.h"
#include <math.h>

//For the flora Color Sensor
boolean commonAnode = false;
char szInfo[128];
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

// use hardware SPI for the OLED Display
#define OLED_DC     D3
#define OLED_CS     D4
#define OLED_RESET  D5
Adafruit_SSD1306 display(OLED_DC, OLED_RESET, OLED_CS);

int x;

#define PIN A0 //input from analog proximity sensor.
int data = 0;

void setup() 
{
    
    pinMode (PIN, INPUT);
/*------------------------------------------------------------------------------------------------------------------- |   
                                                        Input
---------------------------------------------------------------------------------------------------------------------*/
//For the Input color sensor
    Serial.begin(9600);
    Serial.println("Color View Test!");
    
    if (tcs.begin()) {
        Serial.println("Found sensor");
    } else {
        Serial.println("No TCS34725 found ... check your connections");
        while (1); // halt!
    }

/*------------------------------------------------------------------------------------------------------------------- |   
                                                        Output
---------------------------------------------------------------------------------------------------------------------*/
//For the Output OLED Display
   display.begin(SSD1306_SWITCHCAPVCC);
   display.setTextSize(1.5);       // text size
   display.setTextColor(WHITE); // text color
   display.setTextWrap(false); // turn off text wrapping so we can do scrolling
   
   Particle.subscribe("rgbValue", myHandler, MY_DEVICES);
   
}

int i = 0;

void myHandler(const char *event, const char *data)
{
  i++;
  Serial.print(i);
  display.clearDisplay();
    display.setCursor(x/2, 7);
    display.print("\n\n");
    display.print("rgb(");
    display.print(data);
    display.print(")");
    display.display();
    delay(1000);
  Serial.print(", data: ");
  if (data)
    Serial.println(data);
  else
    Serial.println("NULL");
}

void loop() 
{
/*------------------------------------------------------------------------------------------------------------------- |   
                                                        Input
---------------------------------------------------------------------------------------------------------------------*/

//For the Input Flora Color Sensor
    uint16_t clear, red, green, blue;
    uint16_t value = analogRead(PIN);

    if(value > 2400){
        tcs.setInterrupt(false);      // turn on LED
        
        delay(20);  // takes 50ms to read 
          
        tcs.getRawData(&red, &green, &blue, &clear);
        tcs.setInterrupt(true);  // turn off LED
        
        // Figure out some basic hex code for visualization
        uint32_t sum = clear;
        float r, g, b;
        
        r = red; r /= sum;
        g = green; g /= sum;
        b = blue; b /= sum;
        r *= 256; g *= 256; b *= 256;
        
        sprintf(szInfo, "%d, %d, %d", (int)r, (int)g, (int)b);
        
       // Spark.publish("colorinfo", szInfo);
        
       // Serial.println(szInfo);
        
        delay(2000);
        
        String rgbValue = szInfo;
        bool success = Particle.publish("rgbValue", rgbValue, PRIVATE);
        if(!success)
            Serial.println("Failed to publish rgbValue");
    }
        
/*------------------------------------------------------------------------------------------------------------------- |   
                                                        Output
---------------------------------------------------------------------------------------------------------------------*/    
//For the Output OLED Display
    
    
}