#pragma once
#include <M5Stack.h>

enum Expression {
  Smile,
  Laugh,
  Anger,
  Doubt,
  Sleep,
  Neutral
};

class DrawContext {
private:
  Expression expression;
  float breath;
public:
  DrawContext(void);
  DrawContext(Expression expression, float breath);
  Expression getExpression();
  float getBreath();
};

class Mouth
{
private:
  int x;
  int y;
  int minWidth;
  int maxWidth;
  int minHeight;
  int maxHeight;
  int lastX;
  int lastY;
  int lastW;
  int lastH;
  float openRatio;
  uint32_t primaryColor;
  uint32_t secondaryColor;
  void clear(void);
  void _draw(int x1, int y1, int x2, int y2);
public:
  // constructor
  Mouth();
  Mouth(int x, int y,
  int minWidth, int maxWidth,
  int minHeight, int maxHeight,
  uint32_t primaryColor, uint32_t secondaryColor);
  void setOpenRatio(float ratio);
  void draw(DrawContext drawContext);
};

class Eye
{
private:
  int x;
  int y;
  int r;
  int offsetX;
  int offsetY;
  int lastX;
  int lastY;
  int lastR;
  float openRatio;
  uint32_t primaryColor;
  uint32_t secondaryColor;
  void clear(void);
  void drawCircle(int x, int y, int r);
  void drawRect(int x, int y, int w, int h);
public:
  // constructor
  Eye();
  Eye(int x, int y, int r, uint32_t primaryColor, uint32_t secondaryColor);
  void setOpenRatio(float ratio);
  void setOffset(int offsetX, int offsetY);
  void draw(DrawContext drawContext);
};

class Avator
{
private:
  Mouth mouth;
  Eye eyeR;
  Eye eyeL;
  float breath;
  Expression expression;
  DrawContext drawContext;
  void drawLoop(void);
public:
  // constructor
  Avator(void);

  // TODO: getter
  void openMouth(int percent);
  void openEye(boolean isOpen);
  void setMouthOpen(float f);
  void setEyeOpen(float f);
  void setBreath(float f);
  void setGaze(float vertical, float horizontal);
  void setExpression(Expression exp); // TODO
  void init(void);
  void draw(void);
};