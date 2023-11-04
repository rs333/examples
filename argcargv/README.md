# argcargv
A program to examine what is contained in argv.  Note the line of
code that prints N bytes following argv[0] is unsafe since there is
no guarantee that the strings allocated and pointed to in argv
are in contiguous memory.

## Reference
Section 5.1.2.2.1 Program startup of ISO/IEC 9889:1999

## Usage
```bash
./argcargv 1arg 2arg 3arg
```

## Example output
```bash
user@machine:~/$ ./argcargv 1arg 2arg 3arg
&argv=0x7ffccaa52830
&argv[0]=0x7ffccaa52988 argv[0]=0x7ffccaa54416  *argv[0]=.
&argv[1]=0x7ffccaa52990 argv[1]=0x7ffccaa54421  *argv[1]=1
&argv[2]=0x7ffccaa52998 argv[2]=0x7ffccaa54426  *argv[2]=2
&argv[3]=0x7ffccaa529a0 argv[3]=0x7ffccaa5442b  *argv[3]=3
Length of data pointed to by argv=26
Printing 26 bytes as characters following argv[0]:
./argcargv[NULL]1arg[NULL]2arg[NULL]3arg[NULL]
^- 0x7ffccaa54416
                ^- 0x7ffccaa54421
                          ^- 0x7ffccaa54426
                                    ^- 0x7ffccaa5442b
```