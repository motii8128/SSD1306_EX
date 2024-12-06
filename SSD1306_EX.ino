#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);

void setup()
{
  Serial.begin(115200);
  Serial.println("OLED initialized");
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32
  display.display();
  delay(1000);
  // Clear the buffer.
  display.clearDisplay();
  display.display();
  // Text display settings
  display.setTextSize(2);
  display.setTextColor(WHITE);
}

void loop()
{
  Output("Hello");
  delay(10);
}

void Output(char *text)
{
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print(text);
  display.display();
}
