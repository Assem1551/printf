#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - struct parameters
 * @unsign: unsigned value
 * @plus_flag: plus flag
 * @space_flag: hashtag flag
 * @hashtag_flag: hash flag
 * @zero_flag: zero flag
 * @minus_flag: - flag
 * @width: field width
 * @precision: field precision
 * @h_modifier: h modifier
 * @l_modifier: l modifier
 */
typedef struct parameters
{
	unsigned int plus_flag  :1;
	unsigned int minus_flag :1;
	unsigned int unsign     :1;
	unsigned int space_flag :1;
	unsigned int hashtag_flag :1;
	unsigned int zero_flag   :1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier  :1;
	unsigned int l_modifier  :1;
} params_t;


/**
 * struct specifier - specifier
 * @specifier: e1
 * @f: f1
 */

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;


/* put_char*/
int _puts(char *str);
int _putchar(int c);

/* print function modules*/
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);


/* number modules*/
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* specifier modules*/

int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/* convert number modules*/
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);

/* simple printers modules*/
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/* print number modules*/
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);



/* params module*/
void init_params(params_t *params, va_list ap);

/* string fields*/
char *get_precision(char *p, params_t *params, va_list ap);


/* my printf */
int _printf(const char *format, ...);


#endif
