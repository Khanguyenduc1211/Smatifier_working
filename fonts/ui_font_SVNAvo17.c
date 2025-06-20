/*******************************************************************************
 * Size: 17 px
 * Bpp: 1
 * Opts: --bpp 1 --size 17 --font Z:/Arduino/Squareline Studio/assets/SVN-Rounded.ttf -o Z:/Arduino/Squareline Studio/assets\ui_font_SVNAvo17.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_SVNAVO17
#define UI_FONT_SVNAVO17 1
#endif

#if UI_FONT_SVNAVO17

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0xff,

    /* U+0022 "\"" */
    0xff, 0xf0,

    /* U+0027 "'" */
    0xfc,

    /* U+0028 "(" */
    0x6b, 0x49, 0x24, 0x89, 0x10,

    /* U+0029 ")" */
    0x89, 0x12, 0x49, 0x29, 0x40,

    /* U+002C "," */
    0xfc,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x8, 0xc4, 0x62, 0x31, 0x18, 0x80,

    /* U+0030 "0" */
    0x7b, 0x38, 0x61, 0x86, 0x18, 0x73, 0x78,

    /* U+0031 "1" */
    0xd5, 0x55, 0x40,

    /* U+0032 "2" */
    0x7b, 0x38, 0x41, 0xc, 0x63, 0x10, 0xfc,

    /* U+0033 "3" */
    0x71, 0x20, 0x8e, 0xc, 0x18, 0x73, 0x78,

    /* U+0034 "4" */
    0x8, 0x63, 0x8a, 0x6b, 0x2f, 0xc2, 0x8,

    /* U+0035 "5" */
    0x7d, 0x84, 0x1e, 0xcc, 0x10, 0x73, 0x78,

    /* U+0036 "6" */
    0x10, 0xc2, 0x1e, 0xce, 0x18, 0x73, 0x78,

    /* U+0037 "7" */
    0xfc, 0x30, 0x86, 0x10, 0xc2, 0x18, 0x40,

    /* U+0038 "8" */
    0x31, 0x24, 0x9e, 0xce, 0x18, 0x73, 0x78,

    /* U+0039 "9" */
    0x7b, 0x38, 0x61, 0xcd, 0xe1, 0x8c, 0x20,

    /* U+003A ":" */
    0x84,

    /* U+003B ";" */
    0x86,

    /* U+003F "?" */
    0x3c, 0x7e, 0xe7, 0xc3, 0xc3, 0x3, 0x27, 0x7e,
    0x7c, 0x60, 0x60, 0x60, 0x60,

    /* U+0041 "A" */
    0x18, 0x1c, 0x1c, 0x34, 0x26, 0x7e, 0x43, 0x43,
    0xc1,

    /* U+0042 "B" */
    0xfc, 0x82, 0x82, 0x82, 0xfe, 0x81, 0x81, 0x81,
    0xfe,

    /* U+0043 "C" */
    0x3c, 0x30, 0x30, 0x10, 0x18, 0xc, 0x7, 0x6,
    0xc6, 0x3e, 0x0,

    /* U+0044 "D" */
    0xf8, 0x86, 0x83, 0x81, 0x81, 0x81, 0x83, 0x86,
    0xf8,

    /* U+0045 "E" */
    0xfc, 0x21, 0xf, 0xc2, 0x10, 0xf8,

    /* U+0046 "F" */
    0xfc, 0x21, 0xf, 0xc2, 0x10, 0x80,

    /* U+0047 "G" */
    0x3c, 0x30, 0x30, 0x70, 0x78, 0x6c, 0x67, 0x4,
    0xc6, 0x3e, 0x0,

    /* U+0048 "H" */
    0x81, 0x81, 0x81, 0x81, 0xff, 0x81, 0x81, 0x81,
    0x81,

    /* U+0049 "I" */
    0xff, 0x80,

    /* U+004A "J" */
    0x4, 0x10, 0x41, 0x4, 0x18, 0x73, 0x78,

    /* U+004B "K" */
    0x86, 0x8c, 0x98, 0xb0, 0xe0, 0xf0, 0x98, 0x8c,
    0x86,

    /* U+004C "L" */
    0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0xfc,

    /* U+004D "M" */
    0x80, 0xe0, 0xf0, 0x7c, 0x7b, 0x6d, 0xb6, 0x73,
    0x11, 0x88, 0x80,

    /* U+004E "N" */
    0x81, 0xc1, 0xe1, 0xb1, 0x99, 0x8d, 0x87, 0x83,
    0x81,

    /* U+004F "O" */
    0x3e, 0x31, 0xb0, 0x70, 0x18, 0xc, 0x7, 0x6,
    0xc6, 0x3e, 0x0,

    /* U+0050 "P" */
    0xfe, 0x83, 0x81, 0x83, 0xfe, 0x80, 0x80, 0x80,
    0x80,

    /* U+0051 "Q" */
    0x3e, 0x31, 0xb0, 0x70, 0x18, 0x4c, 0x37, 0xe,
    0xc7, 0x1e, 0x80,

    /* U+0052 "R" */
    0xfe, 0x83, 0x81, 0x83, 0xfe, 0x8c, 0x86, 0x82,
    0x83,

    /* U+0053 "S" */
    0x74, 0xe1, 0x87, 0xe, 0x31, 0x70,

    /* U+0054 "T" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,

    /* U+0055 "U" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xa2, 0x38,

    /* U+0056 "V" */
    0xc1, 0x43, 0x43, 0x62, 0x26, 0x34, 0x1c, 0x1c,
    0x18,

    /* U+0057 "W" */
    0xc9, 0x34, 0xf2, 0x6f, 0x66, 0x66, 0x26, 0x43,
    0x6c, 0x1f, 0x81, 0xf8, 0x19, 0x80,

    /* U+0058 "X" */
    0xc3, 0x66, 0x24, 0x3c, 0x18, 0x38, 0x24, 0x66,
    0xc3,

    /* U+0059 "Y" */
    0xc6, 0x89, 0xb1, 0xc1, 0x2, 0x4, 0x8, 0x10,

    /* U+005A "Z" */
    0xff, 0x3, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc0,
    0xff,

    /* U+005B "[" */
    0xff, 0xcc, 0xcc, 0xcc, 0xcc, 0xff,

    /* U+005C "\\" */
    0xc1, 0x81, 0x83, 0x3, 0x6, 0x6, 0xc, 0x1c,
    0x18, 0x38, 0x20,

    /* U+005D "]" */
    0xff, 0x33, 0x33, 0x33, 0x33, 0xff,

    /* U+0061 "a" */
    0x18, 0x1c, 0x1c, 0x34, 0x26, 0x7e, 0x43, 0x43,
    0xc1,

    /* U+0062 "b" */
    0xfc, 0x82, 0x82, 0x82, 0xfe, 0x81, 0x81, 0x81,
    0xfe,

    /* U+0063 "c" */
    0x3c, 0x30, 0x30, 0x10, 0x18, 0xc, 0x7, 0x6,
    0xc6, 0x3e, 0x0,

    /* U+0064 "d" */
    0xf8, 0x86, 0x83, 0x81, 0x81, 0x81, 0x83, 0x86,
    0xf8,

    /* U+0065 "e" */
    0xfc, 0x21, 0xf, 0xc2, 0x10, 0xf8,

    /* U+0066 "f" */
    0xfc, 0x21, 0xf, 0xc2, 0x10, 0x80,

    /* U+0067 "g" */
    0x3c, 0x30, 0x30, 0x70, 0x78, 0x6c, 0x67, 0x4,
    0xc6, 0x3e, 0x0,

    /* U+0068 "h" */
    0x81, 0x81, 0x81, 0x81, 0xff, 0x81, 0x81, 0x81,
    0x81,

    /* U+0069 "i" */
    0xff, 0x80,

    /* U+006A "j" */
    0x4, 0x10, 0x41, 0x4, 0x18, 0x73, 0x78,

    /* U+006B "k" */
    0x86, 0x8c, 0x98, 0xb0, 0xe0, 0xf0, 0x98, 0x8c,
    0x86,

    /* U+006C "l" */
    0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0xfc,

    /* U+006D "m" */
    0x80, 0xe0, 0xf0, 0x7c, 0x7b, 0x6d, 0xb6, 0x73,
    0x11, 0x88, 0x80,

    /* U+006E "n" */
    0x81, 0xc1, 0xe1, 0xb1, 0x99, 0x8d, 0x87, 0x83,
    0x81,

    /* U+006F "o" */
    0x3e, 0x31, 0xb0, 0x70, 0x18, 0xc, 0x7, 0x6,
    0xc6, 0x3e, 0x0,

    /* U+0070 "p" */
    0xfe, 0x83, 0x81, 0x83, 0xfe, 0x80, 0x80, 0x80,
    0x80,

    /* U+0071 "q" */
    0x3e, 0x31, 0xb0, 0x70, 0x18, 0x4c, 0x37, 0xe,
    0xc7, 0x1e, 0x80,

    /* U+0072 "r" */
    0xfe, 0x83, 0x81, 0x83, 0xfe, 0x8c, 0x86, 0x82,
    0x83,

    /* U+0073 "s" */
    0x74, 0xe1, 0x87, 0xe, 0x31, 0x70,

    /* U+0074 "t" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,

    /* U+0075 "u" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xa2, 0x38,

    /* U+0076 "v" */
    0xc1, 0x43, 0x43, 0x62, 0x26, 0x34, 0x1c, 0x1c,
    0x18,

    /* U+0077 "w" */
    0xc9, 0x34, 0xf2, 0x6f, 0x66, 0x66, 0x26, 0x43,
    0x6c, 0x1f, 0x81, 0xf8, 0x19, 0x80,

    /* U+0078 "x" */
    0xc3, 0x66, 0x24, 0x3c, 0x18, 0x38, 0x24, 0x66,
    0xc3,

    /* U+0079 "y" */
    0xc6, 0x89, 0xb1, 0xc1, 0x2, 0x4, 0x8, 0x10,

    /* U+007A "z" */
    0xff, 0x3, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc0,
    0xff,

    /* U+007B "{" */
    0x7b, 0xd8, 0xc6, 0x71, 0x8c, 0x63, 0x1e, 0x70,

    /* U+007C "|" */
    0xff, 0xff, 0xff,

    /* U+007D "}" */
    0xf7, 0x8c, 0x63, 0x1c, 0xc6, 0x31, 0xbd, 0xc0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 99, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 74, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 104, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 6, .adv_w = 74, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 7, .adv_w = 91, .box_w = 3, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 12, .adv_w = 91, .box_w = 3, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 17, .adv_w = 74, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 18, .adv_w = 72, .box_w = 4, .box_h = 1, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 19, .adv_w = 74, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 20, .adv_w = 80, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 26, .adv_w = 138, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 33, .adv_w = 65, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 36, .adv_w = 134, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 43, .adv_w = 134, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 50, .adv_w = 130, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 57, .adv_w = 133, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 64, .adv_w = 134, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 71, .adv_w = 121, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 78, .adv_w = 134, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 85, .adv_w = 134, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 92, .adv_w = 56, .box_w = 1, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 93, .adv_w = 56, .box_w = 1, .box_h = 7, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 94, .adv_w = 166, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 107, .adv_w = 142, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 116, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 125, .adv_w = 159, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 136, .adv_w = 138, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 145, .adv_w = 92, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 151, .adv_w = 91, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 157, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 168, .adv_w = 130, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 177, .adv_w = 29, .box_w = 1, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 179, .adv_w = 110, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 186, .adv_w = 132, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 195, .adv_w = 111, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 202, .adv_w = 149, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 213, .adv_w = 130, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 222, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 233, .adv_w = 132, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 242, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 253, .adv_w = 131, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 262, .adv_w = 92, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 268, .adv_w = 112, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 276, .adv_w = 121, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 284, .adv_w = 142, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 293, .adv_w = 198, .box_w = 12, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 307, .adv_w = 133, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 316, .adv_w = 133, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 324, .adv_w = 130, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 333, .adv_w = 99, .box_w = 4, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 339, .adv_w = 106, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 350, .adv_w = 99, .box_w = 4, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 356, .adv_w = 142, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 365, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 374, .adv_w = 159, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 385, .adv_w = 138, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 394, .adv_w = 92, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 400, .adv_w = 91, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 406, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 417, .adv_w = 130, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 426, .adv_w = 29, .box_w = 1, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 428, .adv_w = 110, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 435, .adv_w = 132, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 444, .adv_w = 111, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 451, .adv_w = 149, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 462, .adv_w = 130, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 471, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 482, .adv_w = 132, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 491, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 502, .adv_w = 131, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 511, .adv_w = 92, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 517, .adv_w = 112, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 525, .adv_w = 121, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 533, .adv_w = 142, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 542, .adv_w = 198, .box_w = 12, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 556, .adv_w = 133, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 565, .adv_w = 133, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 573, .adv_w = 130, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 582, .adv_w = 111, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 590, .adv_w = 74, .box_w = 2, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 593, .adv_w = 111, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_0[] = {
    0, 1, 2, 0, 0, 0, 0, 3,
    4, 5, 0, 0, 6, 7, 8, 9,
    10, 11, 12, 13, 14, 15, 16, 17,
    18, 19, 20, 21, 0, 0, 0, 22
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 32, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_0, .list_length = 32, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    },
    {
        .range_start = 65, .range_length = 29, .glyph_id_start = 24,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 29, .glyph_id_start = 53,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 3,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_SVNAvo17 = {
#else
lv_font_t ui_font_SVNAvo17 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 14,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_SVNAVO17*/

