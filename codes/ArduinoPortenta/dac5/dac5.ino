#include "Wire.h"
#include <Adafruit_MCP4725.h>
#include <Arduino_PortentaBreakout.h>

#define TCAADDR 0x70

Adafruit_MCP4725 p[5];

void tcaselect(uint8_t i) {
  if (i > 7) return;
 
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}


void setup()
{
    while (!Serial);
    delay(1000);

    //Załączenie magistrali na rozszerzeniu płytki
    Breakout.I2C_0.begin();

    Wire.begin();
    
    Serial.begin(115200);
    Serial.println("\nTCAScanner ready!");

    //Sprawdzenie czy DAC zostały poprawnie podłączone
    for (uint8_t t=0; t<8; t++) {
      tcaselect(t);
      Serial.print("TCA Port #"); Serial.println(t);

      for (uint8_t addr = 0; addr<=127; addr++) {
        if (addr == TCAADDR) continue;

        Wire.beginTransmission(addr);
        if (!Wire.endTransmission()) {
          Serial.print("Found I2C 0x");  Serial.println(addr,HEX);
        }
      }
    }
    Serial.println("\ndone");

    //Zaadresowanie poszczególnych DAC
    for (uint8_t i=0; i<5; i++) {
    tcaselect(i);
    p[i].begin(0x62);
    }
}

void loop() 
{
  // //Na zmianę co 2 sekundy sygnał maksymalny i zerowy
  // for (int i=0; i<5; i++) {
  //   tcaselect(i);
  //   p[i].setVoltage(4095, false);
  // }
  // delay(2000);
  // for (int i=0; i<5; i++) {
  //   tcaselect(i);
  //   p[i].setVoltage(0, false);
  // }
  // delay(2000);

  // Sygnał trójkątny ale tylko na wybranym paśmie widocznym na diodach
  int counter;
  for (counter = 3000; counter < 3500; counter++)
  {
    for (int i=0; i<5; i++) {
      tcaselect(i);
      p[i].setVoltage(counter, false);
    }
  }
  for (counter = 3500; counter > 3000; counter--)
  {
    for (int i=0; i<5; i++) {
      tcaselect(i);
      p[i].setVoltage(counter, false);
    }
  }
}