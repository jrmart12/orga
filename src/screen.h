
#ifndef SCREEN_H_
#define SCREEN_H_

#ifndef __ASSEMBLER__

void clear_screen();
void set_cursor(uint8_t row, uint8_t column);
void get_cursor(uint8_t *row, uint8_t *column);
void set_color(uint8_t fgcolor, uint8_t bgcolor);
void get_color(uint8_t *fgcolor, uint8_t *bgcolor);
void put_char(uint8_t ch);
void puts(char *str);
void put_decimal(uint32_t n);

#define true  1
#define false 0

#define VGA_START_ADDR      ((vga_ptr_t)0xb800)
#define VGA_END_ADDR        ((vga_ptr_t)0xcabf)
#define BTN_STATE_REG_ADDR  ((volatile unsigned char *)0xffff0004)
#define MS_COUNTER_REG_ADDR ((volatile unsigned int  *)0xffff0008)

#else

#define VGA_START_ADDR      0xb800
#define VGA_END_ADDR        0xcabf
#define BTN_STATE_REG_ADDR  0xffff0004
#define MS_COUNTER_REG_ADDR 0xffff0008

#endif

#endif /* SCREEN_H_ */

