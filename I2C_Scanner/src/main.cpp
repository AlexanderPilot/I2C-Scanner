#include <Arduino.h>
#include <Wire.h>

#define SDA1 21
#define SCL1 22

#define SDA2 17
#define SCL2 16

TwoWire I2C_one = TwoWire(0);
TwoWire I2C_two = TwoWire(1);

void scan1()
{
    uint8_t cnt=0;
    uint8_t ec;
    uint8_t i;
    Serial.println("Scanning I2C Addresses Channel 1");

    for(i=0;i<128;i++)
    {
        I2C_one.beginTransmission(i);
        ec=I2C_one.endTransmission(true);
        if(ec==0)
        {
            if(i<16)
            {
                Serial.print('0');
            }
            Serial.print(i,HEX);
            cnt++;
        }
        else
        {
            Serial.print("..");
        }
        Serial.print(' ');
        if ((i&0x0f)==0x0f)
        {
            Serial.println();
        }
    }
    Serial.print("Scan Completed, ");
    Serial.print(cnt);
    Serial.println(" I2C Devices found.");
}

void scan2()
{
    uint8_t cnt=0;
    uint8_t ec;
    uint8_t i;

    Serial.println("Scanning I2C Addresses Channel 1");

    for(i=0;i<128;i++)
    {
        I2C_two.beginTransmission(i);
        ec=I2C_two.endTransmission(true);
        if(ec==0)
        {
            if(i<16)
            {
                Serial.print('0');
            }
            Serial.print(i,HEX);
            cnt++;
        }
        else
        {
            Serial.print("..");
        }
        Serial.print(' ');
        if ((i&0x0f)==0x0f)
        {
            Serial.println();
        }
    }
    Serial.print("Scan Completed, ");
    Serial.print(cnt);
    Serial.println(" I2C Devices found.");
}


void setup()
{
    Serial.begin(115200);
    I2C_one.begin(SDA1,SCL1,400000); // SDA pin 21, SCL pin 22 TTGO TQ
    I2C_two.begin(SDA2,SCL2,400000); // SDA2 pin 17, SCL2 pin 16 
}

void loop()
{
    scan1();
    Serial.println();
    delay(100);
    scan2();
    Serial.println();
    delay(5000);
}