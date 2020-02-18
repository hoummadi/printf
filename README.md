# printf

## Format Specifiers

A format specifier follows this prototype: `%[flags][width][.precision][length]type`
The following format specifiers are supported:


### Supported Types

| Type   | Output |
|--------|--------|
| d or i | Signed decimal integer |
| u      | Unsigned decimal integer	|
| b      | Unsigned binary |
| o      | Unsigned octal |
| x      | Unsigned hexadecimal integer (lowercase) |
| X      | Unsigned hexadecimal integer (uppercase) |
| f or F | Decimal floating point |
| e or E | Scientific-notation (exponential) floating point |
| g or G | Scientific or decimal floating point |
| c      | Single character |
| s      | String of characters |
| p      | Pointer address |
| %      | A % followed by another % character will write a single % |
