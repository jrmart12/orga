#include 'screen.h'

uint8_t cursor_row;
uint8_t cursor_column;
uint8_t color_fgcolor;
uint8_t color_bgcolor;

void set_cursor(uint8_t row, uint8_t column){
    cursor_row=row;
    cursor_column=column;
}

void get_cursor(uint8_t *row, uint8_t *column){
    cursor_row=*row;
    cursor_column=*column;
}

void set_color(uint8_t fgcolor, uint8_t bgcolor){
    color_fgcolor=fgcolor;
    color_bgcolor=bgcolor;
}

void get_color(uint8_t *fgcolor, uint8_t *bgcolor){
    color_fgcolor=*fgcolor;
    color_bgcolor=*bgcolor;
}