#include <Adafruit_MCP4728.h>
#include <Wire.h>

Adafruit_MCP4728 mcp;

const int delaySteps = 0; //delay between channels given as a number of values
int microSnail=0; //delay between values in microseconds
int buffer[delaySteps]; // Buffer for the second DAC
int snaill[]={201000,325000,41500,41500,5000000}; //delay between fluctations
int values1[]={415,472,547,660,749,884,1008,1160,1262,1358,1435,1461,1493,1518,1533,1549,1557,1558,1565,1555,1526,1466,1343,1217,1098,962,833,695,589,512,474,417,380};
int values2[]={412,486,624,764,944,1164,1409,1573,1719,1805,1879,1906,1927,1926,1952,1956,2004,2043,2064,2088,2056,1946,1800,1603,1394,1135,925,758,642,514,445,407,380};
int values3[]={415,469,554,620,782,881,1015,1152,1248,1332,1380,1426,1438,1452,1455,1462,1475,1488,1502,1507,1478,1424,1339,1230,1088,938,793,680,594,504,442,403,380};
int values4[]={420,467,516,578,641,758,903,997,1128,1241,1373,1408,1485,1474,1480,1491,1518,1551,1567,1574,1582,1518,1449,1370,1261,1177,1004,868,755,645,553,482,380};
int values5[]={437,478,540,618,714,837,965,1125,1243,1344,1414,1461,1496,1519,1533,1547,1551,1573,1587,1591,1585,1553,1488,1394,1270,1136,980,838,726,588,507,449,380};

void adjustSnaill(int* snaill, int size, int delaySteps) {
    int adjustment = delaySteps * 1200; // 1.2 milliseconds in microseconds

    for (int i = 0; i < size; i++) {
        snaill[i] -= adjustment;
    }
}

void processValues(int* values, int size, int delaySteps, int snailll) {
    for (int i = 0; i < size; i++) {
      mcp.setChannelValue(MCP4728_CHANNEL_A, values[i]);
      mcp.setChannelValue(MCP4728_CHANNEL_B, values[i]);
      mcp.setChannelValue(MCP4728_CHANNEL_C, values[i]);
      mcp.setChannelValue(MCP4728_CHANNEL_D, values[i]);
    }
    delayMicroseconds(snailll);
}

void setup() {
  Serial.begin(9600);

  if (!mcp.begin()) {
    Serial.println("Failed to find MCP4728 chip");
    while (1) {
      delay(10);
    }
  }

  mcp.setChannelValue(MCP4728_CHANNEL_A, 380);
  mcp.setChannelValue(MCP4728_CHANNEL_B, 380);

  adjustSnaill(snaill, sizeof(snaill)/sizeof(snaill[0]), delaySteps);
}

void loop() {
  processValues(values1, sizeof(values1)/sizeof(values1[0]), delaySteps, snaill[0]);
  processValues(values2, sizeof(values2)/sizeof(values2[0]), delaySteps, snaill[1]);
  processValues(values3, sizeof(values3)/sizeof(values3[0]), delaySteps, snaill[2]);
  processValues(values4, sizeof(values4)/sizeof(values4[0]), delaySteps, snaill[3]);
  processValues(values5, sizeof(values5)/sizeof(values5[0]), delaySteps, snaill[4]);
}