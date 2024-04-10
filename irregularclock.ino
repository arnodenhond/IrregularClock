#include <MD_MAX72xx.h>
#include <Chronos.h>
//#include <TimeLib.h>
#include <RTClib.h>


#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES	4

#define CLK_PIN   13  // or SCK
#define DATA_PIN  11  // or MOSI
#define CS_PIN    10  // or SS

MD_MAX72XX mx = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
RTC_DS1307 rtc;


//when reaging the age of 53.68 years there will be a gap of 52 days. 
const PROGMEM uint8_t  chars[45][32] =
  {
    {//0
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//1
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//2:9
      0b00000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//3:9
      0b00000000,
      0b10000000,
      0b10001000,
      0b11001000,
      0b11111111,
      0b11001000,
      0b10001000,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//4:14
      0b00000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    }, 
     {//5:9
      0b00000000,
      0b10000000,
      0b10010010,
      0b11010010,
      0b11111111,
      0b11010010,
      0b10010010,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
     {//6:14
      0b00000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10001000,
      0b11001000,
      0b11111111,
      0b11001000,
      0b10001000,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
     {//7:9
      0b00000000,
      0b10000000,
      0b10001111,
      0b11001000,
      0b11111000,
      0b11001000,
      0b10001111,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//8:19
      0b00000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
     {//9:16
      0b00000000,
      0b10000000,
      0b10001000,
      0b11001000,
      0b11111111,
      0b11001000,
      0b10001000,
      0b10000000,
      0b10000000,
      0b10001000,
      0b11001000,
      0b11111111,
      0b11001000,
      0b10001000,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    }, 
    {//10:14
      0b00000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10010010,
      0b11010010,
      0b11111111,
      0b11010010,
      0b10010010,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//11:9
      0b00000000,
      0b10000000,
      0b10101010,
      0b10101010,
      0b11111111,
      0b10101010,
      0b10101010,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//12:19
      0b00000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10001000,
      0b11001000,
      0b11111111,
      0b11001000,
      0b10001000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
     {//13:9
      0b00000000,
      0b10000000,
      0b10111100,
      0b10100000,
      0b11100000,
      0b10100100,
      0b10111111,
      0b10000100,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
      {//14:14
      0b00000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10001111,
      0b11001000,
      0b11111000,
      0b11001000,
      0b10001111,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
     {//15:16
      0b00000000,
      0b10000000,
      0b10001000,
      0b11001000,
      0b11111111,
      0b11001000,
      0b10001000,
      0b10000000,
      0b10000000,
      0b10010010,
      0b11010010,
      0b11111111,
      0b11010010,
      0b10010010,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
     {//16:24
      0b00000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
     }, 
     {//17:9
      0b00000000,
      0b10000000,
      0b10010111,
      0b11010100,
      0b11111100,
      0b11010100,
      0b10010111,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//18:19
      0b00000000,
      0b10000000,
      0b10001000,
      0b11001000,
      0b11111111,
      0b11001000,
      0b10001000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10001000,
      0b11001000,
      0b11111111,
      0b11001000,
      0b10001000,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
      {//19:11
      0b00000000,
      0b10000000,
      0b10001111,
      0b10001000,
      0b11001000,
      0b11111111,
      0b11001000,
      0b10001000,
      0b10001111,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//20:18
      0b00000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10010010,
      0b11010010,
      0b11111111,
      0b11010010,
      0b10010010,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
     {//21:15
      0b00000000,
      0b10000000,
      0b10001000,
      0b11001000,
      0b11111111,
      0b11001000,
      0b10001000,
      0b10000000,
      0b10001111,
      0b11001000,
      0b11111000,
      0b11001000,
      0b10001111,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//22:14
      0b00000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b10101010,
      0b10101010,
      0b11111111,
      0b10101010,
      0b10101010,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//23:9
      0b00000000,
      0b10000100,
      0b10111111,
      0b10100100,
      0b11100000,
      0b10100100,
      0b10111111,
      0b10000100,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//24:24
      0b00000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10001000,
      0b11001000,
      0b11111111,
      0b11001000,
      0b10001000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//25:16
      0b00000000,
      0b10000000,
      0b10010010,
      0b11010010,
      0b11111111,
      0b11010010,
      0b10010010,
      0b10000000,
      0b10000000,
      0b10010010,
      0b11010010,
      0b11111111,
      0b11010010,
      0b10010010,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//26:15
      0b00000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b10111100,
      0b10100000,
      0b11100000,
      0b10100100,
      0b10111111,
      0b10000100,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//27:23
      0b00000000,
      0b10000000,
      0b10001000,
      0b11001000,
      0b11111111,
      0b11001000,
      0b10001000,
      0b10000000,
      0b10000000,
      0b10001000,
      0b11001000,
      0b11111111,
      0b11001000,
      0b10001000,
      0b10000000,
      0b10000000,
      0b10001000,
      0b11001000,
      0b11111111,
      0b11001000,
      0b10001000,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//28:19
      0b00000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10001111,
      0b11001000,
      0b11111000,
      0b11001000,
      0b10001111,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },           
    {//29:9
      0b00000000,
      0b10000000,
      0b10111100,
      0b10100000,
      0b11100000,
      0b10101010,
      0b10111111,
      0b10001010,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },     
    {//30:20
      0b00000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10001000,
      0b11001000,
      0b11111111,
      0b11001000,
      0b10001000,
      0b10000000,
      0b10010010,
      0b11010010,
      0b11111111,
      0b11010010,
      0b10010010,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },     
    {//31:9
      0b00000000,
      0b10000000,
      0b10101010,
      0b10101010,
      0b11111111,
      0b01010101,
      0b01010101,
      0b00000001,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//32:28
      0b00000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//33:14
      0b00000000,
      0b10001000,
      0b11001000,
      0b11111111,
      0b11001000,
      0b10001000,
      0b10000000,
      0b10101010,
      0b10101010,
      0b11111111,
      0b10101010,
      0b10101010,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
     {//34:14
      0b00000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10010111,
      0b11010100,
      0b11111100,
      0b11010100,
      0b10010111,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
 {//35:15
      0b00000000,
      0b10000000,
      0b10010010,
      0b11010010,
      0b11111111,
      0b11010010,
      0b10010010,
      0b10000000,
      0b10001111,
      0b11001000,
      0b11111000,
      0b11001000,
      0b10001111,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
     {//36:25
      0b00000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10001000,
      0b11001000,
      0b11111111,
      0b11001000,
      0b10001000,
      0b10000000,
      0b10001000,
      0b11001000,
      0b11111111,
      0b11001000,
      0b10001000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
     {//37:11
      0b00000000,
      0b10000000,
      0b10111100,
      0b10100000,
      0b10100100,
      0b11111111,
      0b10100100,
      0b10100000,
      0b10111100,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//38:16
      0b00000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10001111,
      0b10001000,
      0b11001000,
      0b11111111,
      0b11001000,
      0b10001000,
      0b10001111,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
      {//39:15
      0b00000000,
      0b10000000,
      0b10001000,
      0b11001000,
      0b11111111,
      0b11001000,
      0b10001000,
      0b10000000,
      0b10111100,
      0b10100000,
      0b11100000,
      0b10100100,
      0b10111111,
      0b10000100,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//40:24
      0b00000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10010010,
      0b11010010,
      0b11111111,
      0b11010010,
      0b10010010,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
     {//41:9
      0b00000000,
      0b10000000,
      0b10101110,
      0b10101000,
      0b11111000,
      0b10101010,
      0b10101111,
      0b10000010,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//42:20
      0b00000000,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10001000,
      0b11001000,
      0b11111111,
      0b11001000,
      0b10001000,
      0b10000000,
      0b10001111,
      0b11001000,
      0b11111000,
      0b11001000,
      0b10001111,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//43:10
      0b00000000,
      0b10000000,
      0b10111100,
      0b10100000,
      0b11100111,
      0b10100100,
      0b10111100,
      0b10000100,
      0b00000111,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
    {//44:19
      0b00000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b10000000,
      0b10101010,
      0b10101010,
      0b11111111,
      0b10101010,
      0b10101010,
      0b10000000,
      0b10000000,
      0b11000000,
      0b11111111,
      0b11000000,
      0b10000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
      0b00000000,
    },
  };

uint8_t widths[45] = {0,0,9,9,14,9,14,9,19,16,14,9,19,9,14,16,24,9,19,11,19,15,14,9,24,16,15,23,19,9,20,9,29,14,14,15,25,11,16,15,24,9,20,10,19};


int primes[43] = {3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,91,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191};

Chronos::DateTime DoB = Chronos::DateTime(1979,12,27,0,0) ;

//current day. used to see if we need to recalculate
int currentDayOfMonth = 0;

//in countdown mode, which direction are we going and at what position are we?
bool goingleft = true;
int slide = 0;

Chronos::DateTime getDateTime() {
  DateTime rtcnow = rtc.now();
  Chronos::DateTime chronosnow = Chronos::DateTime::now();
  chronosnow.setYear(rtcnow.year());
  chronosnow.setMonth(rtcnow.month());
  chronosnow.setDay(rtcnow.day());
  chronosnow.setHour(rtcnow.hour());
  chronosnow.setMinute(rtcnow.minute());
  return chronosnow;
}

bool isPrime(int test) {
  if (test%2==0)
    return false;
  int sqroot = sqrt(test);
  for (int i = 0; i < sizeof(primes); i++) {

    //optimization: dont need to check any further
    if (primes[i]>sqroot)
      return true;

    if (test%primes[i]==0)
      return false;

  }
  return true;
}

int nextPrime(int start) {
  int result = 0;
  while (!isPrime(start+result)) {
    result++;
  }
  return result;
}

void setup() {
  Serial.begin(9600);
  rtc.begin();
  //reset clock to compilation time
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  mx.begin();
  //todo: read led intensity from eeprom
  mx.control(MD_MAX72XX::INTENSITY, 0);

  uint8_t allon[32];
  for (int z=0; z < 32; z++) {
    allon[z]=255;
  }

  //show characters
  for (int i=2; i < sizeof(widths); i++) {
    mx.setBuffer(mx.getColumnCount()-1, 32, allon);
    
    uint8_t ar[32];
    for (int z=0; z < 32; z++) {
      ar[z]=pgm_read_byte(&chars[i][z]);
    }
    mx.setBuffer((mx.getColumnCount()/2)+(widths[i]/2), widths[i], ar);
    delay(100);
    // for debugging characters. replace this with set led intensity to eeprom. 
    // if (Serial.available()) {
    //   String n = Serial.readString();
    //   Serial.println("Echo: "+n);
    //   i = n.toInt();
    //   //mx.setBuffer(mx.getColumnCount()-1, 32, chars[0]);
    //   uint8_t ar[32];
    //   for (int z=0; z < 32; z++) {
    //     ar[z]=pgm_read_byte(&chars[i][z]);
    //   }
    //   mx.setBuffer((mx.getColumnCount()/2)-1+(widths[i]/2), widths[i], ar);
    //   delay(1000);
    // }
    mx.clear();
  }

  //show prime display. first randomize screen, then randomly turn leds on or off
  for (uint8_t x=0; x<8; x++) {
    for (uint8_t y=0; y<mx.getColumnCount(); y++) {
      mx.setPoint(x,y,random(2));
    }
  }
  for (int i = 0; i < 1000; i++) {
    mx.setPoint(random(8),random(mx.getColumnCount()),random(2));
    //delay(10);
  }
  mx.clear();
}

long i = 100;
int num = 0;

void loop() {

  if (Serial.available()) {
    String timestamp = Serial.readString();
    Serial.println("Echo: "+timestamp);
    char chars[timestamp.length()];
    timestamp.toCharArray(chars, timestamp.length());
    rtc.adjust(DateTime(chars));
    //force recalculation
    currentDayOfMonth=0;
  }

  DateTime nowdt = rtc.now();
  if (nowdt.day() != currentDayOfMonth) {
    Chronos::DateTime now = getDateTime();

    currentDayOfMonth=nowdt.day();

    // time to recalculate number of days remaining
    String timestamp = nowdt.timestamp(DateTime::TIMESTAMP_FULL);
    Serial.print("Now: ");
    Serial.println(timestamp);
    
    //uint32_t daysnow = rtc.now().unixtime()/86400;
    //uint32_t diff = daysnow-3647;
    Chronos::Span::Absolute diff = now - DoB;
    Serial.print("Days old: ");
    //Serial.println(diff, DEC);
    Serial.println(diff.days(), DEC);
    
    //num = nextPrime(diff);
    num = nextPrime(diff.days());

    Serial.print("Days to next prime: ");
    Serial.println(num, DEC);

    slide = (mx.getColumnCount()/2)+(widths[num]/2);
    i=100;
  } else {
    i++;
  }

  if (num==0) {
    if (i==100) {
      for (uint8_t x=0; x<8; x++) {
        for (uint8_t y=0; y<mx.getColumnCount(); y++) {
          mx.setPoint(x,y,random(2));
        }
      }
    }
    mx.setPoint(random(8),random(mx.getColumnCount()),random(2));
    return;
  }

  mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::OFF);
  mx.clear();

  for (uint8_t r = 0; r < 8; r++) {
    for (uint8_t c = 0; c < mx.getColumnCount(); c++) {
      if ((r + i) % primes[c] == 0) {
          mx.setPoint(r, c, true);
      }
    }
  }
  for (uint8_t r = 8; r > 0; r--) {
    for (uint8_t c = 0; c < mx.getColumnCount(); c++) {
      if (((i + 8) - r) % primes[c] == 0) {
        mx.setPoint(r - 1, mx.getColumnCount() - c - 1, true);
      }
    }
  }

  uint8_t ar[32];
  for (int z=0; z < 32; z++) {
    ar[z]=pgm_read_byte(&chars[num][z]);
  }
  mx.setBuffer(slide, widths[num], ar);
  mx.control(MD_MAX72XX::UPDATE, MD_MAX72XX::ON);
  delay(100);

  if (goingleft) {
    slide++;
    if (slide >= mx.getColumnCount() - 1) {
      goingleft = false;
    }
  } else {
    slide--;
    if (slide < widths[num]) {
      goingleft = true;
    }
  }

}