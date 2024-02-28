# ft_printf - @42Born2Code

## What's the goal of ft_printf?

Re-create the printf from the C Standard Library.

## Why would you do this?

To learn how variadic functions work and how to format strings properly.

### What did i learn from it?

- Variadic functions
- Structs and how to use them
- proper string handling
- Parsing
- Input handling

### Conversions

```
%                   (% character)
c    char           (character)
s    char *         (string)
p    void *         (pointer's address)
u    unsigned int   (unsigned decimal integer)
x/X: unsigned int   (hexadecimal)
d/i: int            (integer)
```


### Possible Flags

**Flags:**
```
-       Left alignment. (default rigth aligned)
0       Field is padded with 0's instead of space.
.       Precision
*       The width or precision is not specified in the format string, 
        but as an additional integer value argument (given by the next va_arg)
```
**Width:** Minumum number of characters to output (pads if necessary)

**Precision:** Maximum limit of characters to output (rounds if necessary)
