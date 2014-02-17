// $Id: fbtext.h 21207 2009-10-08 12:27:18Z henry $
#ifndef __FBTEXT_H__
#define __FBTEXT_H__

#include <stdint.h>

#ifndef WIDTH
#define WIDTH 320
#endif

#ifndef HEIGHT
#define HEIGHT 240
#endif

extern int g_width, g_height;

#define BYTES_PER_PIXEL 2

#if (WIDTH>320)

// 800x480, 800x600, etc.
#include "font_sun12x22.c"
#define FONT_TABLE fontdata_sun12x22
#define FONT_WIDTH 12
#define FONT_HEIGHT 22

#else

// Ironforge
#include "font_6x11.c"
#define FONT_TABLE fontdata_6x11
#define FONT_WIDTH 6
#define FONT_HEIGHT 11

#endif

#define ROWS ((g_height-FONT_HEIGHT+1)/FONT_HEIGHT)
#define COLS ((g_width-FONT_WIDTH+1)/FONT_WIDTH)

#define PIXELS_PER_ROW (FONT_HEIGHT*g_width)

void fbtext_init(void);
void fbtext_clear(void);
void fbtext_scroll(void);
void assure_fb(void);
void fbtext_putc(char c);
void fbtext_setcolor(uint16_t r, uint16_t g, uint16_t b);
void fbtext_puts(char *s);
void fbtext_gotoxy(short x,short y);
void fbtext_printf(char const* fmt, ...);

void fbtext_fillrect(unsigned int top,unsigned int left,
                     unsigned int bottom,unsigned int right,
                     uint16_t r, uint16_t g, uint16_t b);

void fbtext_eraserect(unsigned int top,unsigned int left,
                      unsigned int bottom,unsigned int right);

void fbtext_gotoxc( short x );
void fbtext_gotoyc( short y );
void fbtext_gotoxyc( short x, short y );

#endif // __FBTEXT_H__