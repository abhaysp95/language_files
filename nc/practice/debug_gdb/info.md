# gdb commands

`NOTE: "info gdb"`

## list
* list
* list <line num>

## info
* info functions
* info functions <func name>
* info sources
* info variables
* info files( same as "info target" ), search "(gdb) help target"
* info registers

## symbol-file
* symbol-file <debug symbols file name>

## maintenance
* maintenance print symbols <file>
* maintenance info breakpoints
there are several of maintenance commands

## set
* set args <arguments>  # this way, you don't have to give args everytime

## breakpoints



# ripping symbols off binary

## objcopy

copy and translate object file

`NOTE: man objcopy`

```sh
$ objcopy --only--keep-debug <executable> <output_file>

# you can do something like this
$ objcopy --only-keep-debug foo foo.dbg
$ objcopy --strip-debug foo
# or
$ objcopy --strip-debug --strip-unneeded foo
$ objcopy --add-gnu-debuglink=foo.dbg foo
```

## strip

discard symbols and other data from object file( so, flags like --strip-debug
etc. are present here too )

`NOTE: man strip`

# inspecting symbols with nm

## nm

list symbols from object file

```sh
$ nm <exec/elf file>
```

generally, prints 3 columns which are `virtual address`, `symbol type` &
`symbol name` respectively.

`NOTE: man nm`

### meaning of the symbols

| symbol type | symbol name                                                 |
|-------------|-------------------------------------------------------------|
| A           | Absolute symbol                                             |
| B           | In the uninitialized section( BSS )                         |
| C           | The symbol is common                                        |
| D           | In the initialized data section                             |
| G           | The symbol is in initialized data section for small objects |
| I           | The symbol is an indirect reference to another symbol       |
| N           | Debugging symbol                                            |
| R           | The symbol is in a read only data section                   |
| S           | The symbol is in an uninitialized or zero-initialized data  |
|             | section for small object                                    |
| T           | In the text section                                         |
| U           | Symbol undefined right now                                  |
| V           | The symbol is a weak object                                 |
| W           | The symbol is a weak symbol that has not been specifically  |
|             | tagged as a weak object symbol                              |
| -           | The symbol is a stabs symbol in a.out object file           |
| ?           | The symbol type is unknown or object file format specific   |

* lower case symbol means, it is a local symbol
* upper case symbol means that it is an external symbol

```sh
$ nm -n <elf>  # --numeric-sort ( according to virtual address )
$ nm -g <elf>  # --extern-only ( display only external symbol )
$ nm -S <elf>  # --print-size ( print size of defined symbol )

$ nm <elf> | grep ' B '  # grep whatever symbol type you want( replace 'B' )

$ nm -a <elf>  # --debug-syms ( display debugger-only symbols )
```

# system call tracing

## strace

Trace system calls and signals. Helper tool to understand how your program
interacts with OS. It traces all system calls made by the program. Tells us
about arguments passed and have great filtering capabilities.

we are going to focus on syscalls here.

`NOTE: man strace`

```sh
# to pipe the output of strace you can use it like this
$ strace --output="| less" ./main 10 20
# you can provide file_name too, for --output
# there are also options like --follow-forks and --output-seperately

$ strace -r <file>  # --relative-timestamps, for relative timestamp
$ strace -t <file>  # --absolute-timestamps, acc. to wall clock time
$ strace -tt <file> # --absolute-timestamps, also prints microseconds

$ strace -e <syscall/s[with ,]> <file>  # to see only specific sys call
$ strace -p <pid>  # to trace running process

$ strace -c <exec> # for summary, -C for running summary
# some examples of syscall are write,read,open,openat,socket,recv etc.
```
