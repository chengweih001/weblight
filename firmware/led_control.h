#if !defined(__LED_CONTROL_H__)
#define __LED_CONTROL_H__

#include <avr/io.h>

// Note that both of these structs use values ranging from 0 to
// 255. This is typical for RGB, but for HSV this means that the usual
// [0, 360) range for hue, and [0, 1] or percentage range for
// saturation and brightness all need to be scaled.
typedef struct RgbColor {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} RgbColor;

typedef struct HsvColor {
  unsigned char h;
  unsigned char s;
  unsigned char v;
} HsvColor;

uint8_t GetLEDCount();
void SetLED(uint8_t i, uint8_t r, uint8_t g, uint8_t b);
void SetLEDs(uint8_t r, uint8_t g, uint8_t b);
void SetLEDsToRgbColor(RgbColor rgb);
void LEDsOff();

void StatusBlink(uint8_t count);

// None of the other functions talk over the wire. This one does.
void UpdateLEDs();

RgbColor HsvToRgb(HsvColor hsv);
HsvColor RgbToHsv(RgbColor rgb);

void ClearSequence();
void SetSequenceFrame(uint8_t i, RgbColor c);
void SetSequenceCount(uint8_t n);
void SetLEDsToCurrentFrame();
void AdvanceToNextFrame();


void ResetTicks();
void SetTickCount(uint16_t count);
void DoAnimation();

#endif  // #if !defined(__LED_CONTROL_H__)
