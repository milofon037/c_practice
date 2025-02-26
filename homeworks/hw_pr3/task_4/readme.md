## Компиляция файлов
```gcc -c file1.c file2.c main.c```

После этапа ассемблирования получилось три объектных файла file1.o, file2.o и main.o, соответственно
## Исследование таблицы символов
1) nm file1.o:
```
0000000000000000 D global_var
                 U printf
0000000000000000 T print_from_file1
0000000000000004 d static_var
```
Из вывода видно, что была объявлена глобальная переменная global_var (D), функция printf ещё не определена (U), также объявлена глобальная функция print_from_file1 (T) и локальная переменная static_var (d).

2) nm file2.o:
```
0000000000000000 D global_var
                 U printf
0000000000000000 T print_from_file2
                 U static_var
```
global_var была определена внутри file2, поэтому D, static_var определена не была (и в будущем тоже не будет, так как она статическая - возникнет ошибка) (U). Также была объявлена глобальная функция print_from_file2
3) nm main.o:
```
                 U global_var
0000000000000000 T main
                 U printf
                 U print_from_file1
                 U print_from_file2
```
На данном этапе в main не определено ничего, кроме main, так как остальное берётся из других файлов.
Можно заметить конфликт: и file1.o, и file2.o содержат определение глобальной переменной global_var. Кроме того, static_var не сможет быть определена в file2, так как в file1 объявлена только статическая переменная с этим именем. Это то, что на этапе линковки вызовет ошибки.

## Линковка
gcc file1.o file2.o main.o -o program:
```
/usr/bin/ld: file2.o:(.data+0x0): повторное определение «global_var»; file1.o:(.data+0x0): здесь первое определение
/usr/bin/ld: file2.o: warning: relocation against `static_var' in read-only section `.text'
/usr/bin/ld: file2.o: в функции «print_from_file2»:
file2.c:(.text+0x26): undefined reference to `static_var'
/usr/bin/ld: warning: creating DT_TEXTREL in a PIE
collect2: error: ld returned 1 exit status
```
Как и было сказано ранее, возникли ошибки из-за переменных global_var и static_var

## Исправление ошибок
Чтобы избавиться от ошибок, я удалила строку ```int global_var = 30;``` из file2, убрала ```extern int static_var``` и printf, который выводит static_var

Теперь nm выводит следующее:
1) nm file1.o:
```
0000000000000000 D global_var
                 U printf
0000000000000000 T print_from_file1
0000000000000004 d static_var
```
Вывод file1 не изменился, так как мы не меняли в нём переменные, которые были объявлены.

2) nm file2.o:
```
                 U global_var
                 U printf
0000000000000000 T print_from_file2
```
В file2 теперь совершенно отсутствует переменная static_var (так как о ней там теперь не идёт никакой речи). printf всё ещё не определена, а также определена глобальная функция print_from_file2. global_var не определена (U), поэтому теперь не возникнет конфликта: переменная уже определена в file1 и возьмётся именно оттуда.

3) nm main.o:
```
                 U global_var
0000000000000000 T main
                 U printf
                 U print_from_file1
                 U print_from_file2
```
В main всё ещё определена функция main, остальные функции и переменные будут взяты из других файлов.

## objdump и проверка, где хранятся переменные в памяти
1) objdump -t file1.o
```
file1.o:     формат файла elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*  0000000000000000 file1.c
0000000000000000 l    d  .text  0000000000000000 .text
0000000000000000 l    d  .data  0000000000000000 .data
0000000000000004 l     O .data  0000000000000004 static_var
0000000000000000 l    d  .rodata        0000000000000000 .rodata
0000000000000000 g     O .data  0000000000000004 global_var
0000000000000000 g     F .text  0000000000000043 print_from_file1
0000000000000000         *UND*  0000000000000000 printf
```
static_var, global_var хранятся в сегменте .data, объявленная функция print_from_file1 - в .text, printf всё ещё не определена.

2) objdump -t file2.o

```
file2.o:     формат файла elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*  0000000000000000 file2.c
0000000000000000 l    d  .text  0000000000000000 .text
0000000000000000 l    d  .rodata        0000000000000000 .rodata
0000000000000000 g     F .text  0000000000000027 print_from_file2
0000000000000000         *UND*  0000000000000000 global_var
0000000000000000         *UND*  0000000000000000 printf
```
используемая в файле переменная global_var ещё не определена так же, как и printf, функция print_from_file2 в разделе .text.

3) objdump -t main.o
```
main.o:     формат файла elf64-x86-64

SYMBOL TABLE:
0000000000000000 l    df *ABS*  0000000000000000 main.c
0000000000000000 l    d  .text  0000000000000000 .text
0000000000000000 l    d  .rodata        0000000000000000 .rodata
0000000000000000 g     F .text  000000000000003f main
0000000000000000         *UND*  0000000000000000 global_var
0000000000000000         *UND*  0000000000000000 printf
0000000000000000         *UND*  0000000000000000 print_from_file1
0000000000000000         *UND*  0000000000000000 print_from_file2

```
main хранится в разделе .text, остальные переменные и функции не определены

## Линковка 2.0
(фрагмент вывода команды strings program)
```
go t
__libc_start_main
__cxa_finalize
printf
libc.so.6
GLIBC_2.2.5
GLIBC_2.34
_ITM_deregisterTMCloneTable
__gmon_start__
_ITM_registerTMCloneTable
PTE1
u+UH

file1.c -> global_var = %d
file1.c -> static_var = %d
file2.c -> global_var = %d
main.c -> global_var = %d

9*3$"
GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
```

В выводе видны строки из printf()

# Дополнительные шаги
## objdump -x program
(фрагмент)
```
0000000000000000 l    df *ABS*  0000000000000000              file1.c
0000000000004014 l     O .data  0000000000000004              static_var
0000000000000000 l    df *ABS*  0000000000000000              file2.c
0000000000000000 l    df *ABS*  0000000000000000              main.c
0000000000000000 l    df *ABS*  0000000000000000              crtstuff.c
00000000000021a0 l     O .eh_frame      0000000000000000              __FRAME_END__
0000000000000000 l    df *ABS*  0000000000000000              
0000000000003dc8 l     O .dynamic       0000000000000000              _DYNAMIC
0000000000002074 l       .eh_frame_hdr  0000000000000000              __GNU_EH_FRAME_HDR
0000000000003fb8 l     O .got   0000000000000000              _GLOBAL_OFFSET_TABLE_
0000000000000000       F *UND*  0000000000000000              __libc_start_main@GLIBC_2.34
0000000000000000  w      *UND*  0000000000000000              _ITM_deregisterTMCloneTable
0000000000004000  w      .data  0000000000000000              data_start
000000000000118c g     F .text  0000000000000027              print_from_file2
0000000000004018 g       .data  0000000000000000              _edata
00000000000011f4 g     F .fini  0000000000000000              .hidden _fini
0000000000000000       F *UND*  0000000000000000              printf@GLIBC_2.2.5
0000000000004010 g     O .data  0000000000000004              global_var
0000000000004000 g       .data  0000000000000000              __data_start
0000000000000000  w      *UND*  0000000000000000              __gmon_start__
0000000000004008 g     O .data  0000000000000000              .hidden __dso_handle
0000000000002000 g     O .rodata        0000000000000004              _IO_stdin_used
0000000000004020 g       .bss   0000000000000000              _end
0000000000001060 g     F .text  0000000000000026              _start
0000000000001149 g     F .text  0000000000000043              print_from_file1
0000000000004018 g       .bss   0000000000000000              __bss_start
00000000000011b3 g     F .text  000000000000003f              main
```
Из вывода видно, что теперь все объявленные в файлах программы переменные определены

## Статическая компиляция
При статической компиляции программы таблица символов намного больше, так как там хранятся абсолютно всё отовсюда.