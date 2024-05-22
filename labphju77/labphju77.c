#include <stdio.h>
#include "lab.h"

int main() {
    int task, add;
    printf("Введите номер программы:\n");
    scanf("%d", &add);
    if (add == 1)
        return lab1();
    else if (add == 2)
        return lab2();
    else if (add == 3)
        return lab3();
    else if (add == 4)
        return dzlab3();
    else if (add == 5)
        return lab5();
    else if (add == 6)
        return lab4();
    else if (add == 7)
        return dzlab5();
    else if (add == 8)
        return lab6();
    else if (add == 9)
        return dzlab6();
    else if (add == 10)
        return lab7();
    else {
        printf("can't show task");
        return 1;
    }
}