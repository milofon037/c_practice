1) В какой секции ELF-файла будет находиться global_var? ```0000000000004010 g     O .data  0000000000000004              global_var``` - .data
2) В какой секции ELF-файла будет храниться uninitialized_global_var? ```0000000000004028 g     O .bss   0000000000000004              uninitialized_global_var``` - .bss
3) Где находится static_var? ```0000000000004014 l     O .data  0000000000000004              static_var``` - .data
4) Где будет размещена global_point? ```0000000000004018 g     O .data  0000000000000008              global_point``` - .data
5) Где будут расположены:
    1) local_var из функции print_message? **нигде**
    2) static_local_var из той же функции? **.data**
    3) Где будет храниться auto_var из функции main? **нигде**
    4) Где будет выделена память для dynamic_var? **.dynamic**
    5) Где будет создана stack_point? **на данном этапе нигде**