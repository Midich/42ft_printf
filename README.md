*This project has been created as part of the 42 curriculum by msowinsk*

# Description

This project is a recreation of the `printf` function from C library.
It's goal is to learn how to use variadic arguments.

### supported conversions

```
%c - single character
%s - c formated string
%p - pointer address
%d, %i - signed base 10 integer
%u - unsigned base 10 integer
%x - unsigned integer in lowercase base 16 (hexadecimal)
%X - unsigned integer in upercase base 16 (hexadecimal)
%% - prints a percent sign (%) 
```

### supported flags
```
# - alternative forms for x and X conversion. Non zero rezult is prepended by 0x (or 0X for X).
0 - for i, o, u, x and X converted form is padded on left with 0 rather than blanks
- - left ajust value on the field boundry, if minus is present 0 flag is ignored
' ' - (space) a blank is produced before the positive number
+ - for i, d, a sign will always be placed before signed number, overrides ' ' space
```
### suprted options
Width - optional decimal digit string specifying a minimum field width
Precision - optional period sign followed by optional digit string, gives the minimum number of digit to appear for d, i, u, x and X, or maximum number of characters for string (s)

## About used algorithm and data structure
Data structure `t_spec` used in this project was used for ease of use, it is easier to work with formated data than every time going through parts of string to find out if some flags were used or not
```
typedef struct s_spec
{
	int		width;      // minimal width of field 
	int		minus;      // if minus flag was used
	int		zero;       // if zero flag was used
	int		precision;  // minimal precision or how much string to print
	int		hash;       // if hash flag was used
	int		space;      // if space flag was used
	int		plus;       // if plus flag was used  
	char	conversion; // conversion char
}	t_spec;
```
function first go through characters of string character by character looking for percent sign, If character is not a sign it is writen to stdout, if sign is found string goes to parser.

Parser then looks at next characters searching for posible flags width and precision noting them in `t_spec`, after that this data is send to the handle specifier whith will, will based on conversion char, get argument in chosen type and send it to specified printer function that will format and write it to stdout.

I choose this algorithm because in my mind it was the easiest way to do this project, with bonus.


# Instructions

To compile the library simply run `make`, if you want to revompile `make re` and to clean run `make clean` or `make fclean` if you want to also delete generated library

# Resources

- man pages for information on printf and other useful function

> AI wasn't used to create this project