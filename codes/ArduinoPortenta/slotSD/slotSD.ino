#include "SDMMCBlockDevice.h"
#include "FATFileSystem.h"

SDMMCBlockDevice block_device;
mbed::FATFileSystem fs("fs");

void setup() {
  delay(2000);
  Serial.begin(115200);
  Serial.println("Test");
  int err =  fs.mount(&block_device);
  if (err) {
    Serial.println("No filesystem found, formatting... ");
    fflush(stdout);
    err = fs.reformat(&block_device);
  }

  FILE *fp = fopen("/fs/test.txt", "a");
    Serial.println("1");
    fprintf(fp,"test \r\n");
    Serial.println("2");
    fclose(fp);
}

void loop() {
}
