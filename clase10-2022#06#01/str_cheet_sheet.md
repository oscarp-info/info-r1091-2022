# string.h

## strlen - calculate the length of a string

```c
int strlen(const char *s);
```


## strcpy - copy a string

```c
char* strcpy(char* destination, const char* source);
```

_When you use strcpy(), the size of the destination string should be large enough to store the copied string. Otherwise, it may result in undefined behavior._

## strcat - concatenate two strings

```c
char *strcat(char *destination, const char *source)
```

_When we use strcat(), the size of the destination string should be large enough to store the resultant string. If not, we will get the segmentation fault error._

## strcmp - compare two strings

```c
int strcmp (const char* str1, const char* str2);
```

|Return Value|Remarks                                                                             |
|------------|------------------------------------------------------------------------------------|
|0	         |if strings are equal                                                                |
|>0	         |if the first non-matching character in str1 is greater (in ASCII) than that of str2.| 
|<0	         |if the first non-matching character in str1 is lower (in ASCII) than that of str2.  |


## strchr - searches for the first occurrence of the character c 

```c
char *strchr(const char *str, int c)
```
_returns a pointer to the first occurrence of the character c in the string str, or NULL if the character is not found_


## strstr - finds the first occurrence of the substring needle in the string haystack

```c
char *strstr(const char *haystack, const char *needle)
```
_returns a pointer to the first occurrence in haystack of any of the entire sequence of characters specified in needle, or a null pointer if the sequence is not present in haystack_


# stdio.h

## sprintf - sends formatted output to a string pointed to, by str

```c
int sprintf(char *str, const char *format, ...);
```


# stdlib

## atoi - converts the string argument str to an integer

```c
int atoi(const char *str)
```
_returns the converted integral number as an int value. If no valid conversion could be performed, it returns zero_


## itoa - convert int into a string

### opcion (1) - no disponible en gcc linux
```c
char * itoa(int n, char * buffer, int radix);
```
_This is a non-standard function_

### opcion (2)
```c
sprintf(text, "%d", number);   
```

### opcion (3) - desarrollar nuestra propia funcion

```c
// a trabajar!
char * my_int_to_str(int n, char * buffer);
```





