#include "lab.h"
int lab1() {
    // ввод исходных данных
    float V; // объём бассейна
    float v1; // скорость вытекания
    float t; // время опустошения бассейна
    float v2; // скорость наполнения
    // ввод исходных данных
    // вывод на экран V =
    printf("V = ");
    // ввод с клавиатуры значение V
    scanf("%f", &V);
    printf("v1 = ");
    scanf("%f", &v1);
    printf("t = ");
    scanf("%f", &t);
    // решение
    v2 = v1 - V / t;
    // вывод v2
    printf("v2 = %f\n", v2);
    return 0;
}
int lab2() {
    float S; // сумма ряда
    float i; // номер очередного элемента ряда
    int n; // число элементов ряда
    int k; // знаменатель, номер элемента последовательности
    float a; // Член последовательности
    printf("n=");
    scanf("%d", &n);
    S = 0;
    i = 0;
    k = 1;
    while (i < n)
    {
        a = (1 + i) / ((1 + k) * (1 + k));
        S = S + a;
        i = i + 1;
        k = k + 1;
    }
    printf("S = %f\n", S);
    return 0;
}
int lab3() {
    char stroka[100];
    int i = 0;
    int z = 0;//количество символов в текущем слове
    int m = 0;//количество слов
    int sum = 0;//сумма длин всех слов
    char c;
    printf("Введите строку ");
    c = getchar();
    while ((c = getchar()) != '\n') {
        stroka[i++] = c;
    }
    stroka[i] = '\0';// Завершаем строку нулевым символом
    char* y = stroka;
    // Подсчет средней длины слова
    while (1) {
        if (*y == ' ' || *y == '\0') {
            sum += z;
            m++;
            if (*y == '\0')break;
            z = 0;
        }
        y++;
        z++;
    }
    printf("%d", (sum - m + 1) / m);// Возвращаем среднюю длину слова
    return 0;
}
int dzlab3() {
    char stroka[100];
    int i = 0;
    int z = 0; // количество символов в текущем слове
    int m = 0; // количество слов
    int sum = 0; // сумма длин всех слов
    int max = 0; // длина самого длинного слова
    int c;
    printf("Введите строку  ");
    c = getchar();
    while ((c = getchar()) != '\n') {
        stroka[i++] = c;
    }
    stroka[i] = '\0'; // Завершаем строку нулевым символом

    char* y = stroka;
    // Подсчет средней длины слова
    while (1) {
        if (*y == ' ' || *y == '\0') {
            sum += z;
            m++;
            if (z > max) {
                max = z - 1;
            }
            if (*y == '\0')
                break;
            z = 0;
        }
        y++;
        z++;
    }

    printf("Средняя длина слова: %d\n", (sum - m + 1) / m);
    printf("Длина самого длинного слова: %d\n", max);

    return 0;
}

int lab5() {
    {
        int x[N]; // объявление массива из N элементов
        int positive = 0; // переменная для хранения суммы положительных элементов
        int negative = 0; // переменная для хранения суммы модулей отрицательных элементов
        int i; // счетчик цикла

        // ввод массива
        printf("Введите %d целых чисел:\n", N);
        for (i = 0; i < N; i++)
            scanf("%d", &x[i]);

        // вычисление сумм положительных и отрицательных элементов
        for (i = 0; i < N; i++) {
            if (x[i] > 0)
                positive += x[i]; // добавление положительных элементов к сумме положительных
            else
                negative += -x[i]; // добавление модулей отрицательных элементов к сумме отрицательных
        }

        // если сумма модулей отрицательных элементов меньше суммы положительных элементов
        if (negative < positive) {
            // выборочное обнуление элементов
            for (i = 0; i < N; i++) {
                if (x[i] < 0)
                    x[i] = 0; // обнуление отрицательных элементов
            }
        }

        // вывод массива
        printf("Измененный массив:\n");
        for (i = 0; i < N; i++)
            printf("%d ", x[i]);
        printf("\n");

        return 0;
    }
}
int lab4(void) {
    char ch;
    int ii = 0;
    char buffer[MAXLINE]; // Объявление массива символов для хранения строки
    printf("Enter a line of text: ");
    ch = getchar();
    while ((ch = getchar()) != '\n') {
        buffer[ii++] = ch;

    }  // Получение строки с клавиатуры

   // Вызов функции для обработки строки
      // Вывод обработанной строки
    char c; // Текущий символ
    int flag; // Признак слова
    int odd_length; // Признак нечетной длины слова
    int i; // Позиция текущего символа в исходной строке
    int pos; // Позиция текущего символа в результирующей строке
    int start; // Позиция начала слова
    flag = NO;  // Инициализация флага слова как "ложь"
    odd_length = NO;  // Инициализация признака нечетной длины как "ложь"
    start = 0;  // Инициализация позиции начала слова
    i = 0;  // Инициализация текущей позиции символа в исходной строке
    pos = 0;  // Инициализация текущей позиции символа в результирующей строке
    //int g;
    // Цикл обработки символов строки
    do {
        c = buffer[i]; // Получение текущего символа из буфера

        if (c == ' ' || c == '.' || c == ',' || c == '\n') {
            if (odd_length == YES) {
                int g;
                for (g = start; g < i; g++)
                {
                    buffer[pos] = ' ';
                    pos++;
                }
                buffer[pos] = ' ';
                pos++;
            }
            else {

                int g;
                for (g = start; g < i; g++)
                {
                    buffer[pos] = buffer[g];
                    pos++;
                }

                buffer[pos] = '\n';
                pos++;
            }
            flag = NO;
        }
        else {
            if (flag == NO)
            {
                flag = YES;
                start = i;
                odd_length = NO;
            }
            odd_length = !odd_length;
        }
        i++;

    } while (c != '\0');
    printf("Result: %s\n", buffer);
    return 0;
}
int dzlab5() {
    {
        int x[N]; // объявление массива из N элементов
        int positive = 0; // переменная для хранения суммы положительных элементов
        int negative = 0; // переменная для хранения суммы модулей отрицательных элементов
        int i; // счетчик цикла
        // ввод массива
        printf("Введите %d целых чисел:\n", N);
        for (i = 0; i < N; i++)
            scanf("%d", &x[i]);

        // вычисление сумм положительных и отрицательных элементов
        for (i = 0; i < N; i++) {
            if (x[i] > 0)
                positive += x[i];
            else
                negative -= x[i]; // используем отрицательное значение для модуля
        }

        // если сумма модулей отрицательных элементов меньше суммы положительных элементов
        if (negative < positive) {
            // обнуляем положительные элементы
            for (i = 0; i < N; i++) {
                if (x[i] > 0)
                    x[i] = 0;
            }
        }

        // вывод массива
        printf("Измененный массив:\n");
        for (i = 0; i < N; i++)
            printf("%d ", x[i]);
        printf("\n");

        return 0;
    }

}
int lab6() {
    {
        int x[K][Z]; // массив из K на N элементов
        int i, j;
        int is_progression; // флаг, указывающий, является ли строка геометрической прогрессией

        // ввод массива
        printf("Введите элементы массива:\n");
        for (i = 0; i < K; i++) {
            for (j = 0; j < Z; j++) {
                scanf("%d", &x[i][j]);
            }
        }

        // проверка каждой строки на геометрическую прогрессию
        for (i = 0; i < K; i++) {
            is_progression = 1; // предполагаем, что строка является прогрессией

            // вычисляем отношение между элементами в строке
            int ratio = x[i][1] / x[i][0];

            for (j = 1; j < Z; j++) {
                if (x[i][j] != x[i][j - 1] * ratio) {
                    is_progression = 0; // строка не является прогрессией
                    break;
                }
            }

            // вывод результата для текущей строки
            if (is_progression) {
                printf("Строка %d является геометрической прогрессией.\n", i + 1);
            }
            else {
                printf("Строка %d не является геометрической прогрессией.\n", i + 1);
            }
        }

        return 0;
    }
}
int dzlab6() {
    {
        int x[s][d]; // массив из s на d элементов
        int i, j;

        // ввод массива
        printf("введите массив %dx%d:\n", s, d);
        for (i = 0; i < s; i++) {
            for (j = 0; j < d; j++) {
                scanf("%d", &x[i][j]);
            }
        }

        int size = s * d;

        // Построение кучи
        for (int i = size / 2 - 1; i >= 0; i--) {
            int largest = i;
            while (largest < size / 2) {
                int left = 2 * largest + 1;
                int right = 2 * largest + 2;

                int largestRow = largest / d;
                int largestCol = largest % d;
                int leftRow = left / d;
                int leftCol = left % d;
                int rightRow = right / d;
                int rightCol = right % d;

                if (left < size && x[leftRow][leftCol] > x[largestRow][largestCol]) {
                    largest = left;
                    largestRow = leftRow;
                    largestCol = leftCol;
                }

                if (right < size && x[rightRow][rightCol] > x[largestRow][largestCol]) {
                    largest = right;
                    largestRow = rightRow;
                    largestCol = rightCol;
                }

                if (largest != i) {
                    int temp = x[i / d][i % d];
                    x[i / d][i % d] = x[largestRow][largestCol];
                    x[largestRow][largestCol] = temp;
                    i = largest;
                }
                else {
                    break;
                }
            }
        }

        // Извлечение элементов из кучи
        for (i = size - 1; i > 0; i--) {
            int temp = x[0][0];
            x[0][0] = x[i / d][i % d];
            x[i / d][i % d] = temp;

            int largest = 0;
            while (largest < i / 2) {
                int left = 2 * largest + 1;
                int right = 2 * largest + 2;

                int largestRow = largest / d;
                int largestCol = largest % d;
                int leftRow = left / d;
                int leftCol = left % d;
                int rightRow = right / d;
                int rightCol = right % d;

                if (left < i && x[leftRow][leftCol] > x[largestRow][largestCol]) {
                    largest = left;
                    largestRow = leftRow;
                    largestCol = leftCol;
                }

                if (right < i && x[rightRow][rightCol] > x[largestRow][largestCol]) {
                    largest = right;
                    largestRow = rightRow;
                    largestCol = rightCol;
                }

                if (largest != 0) {
                    int tempSub = x[0][0];
                    x[0][0] = x[largestRow][largestCol];
                    x[largestRow][largestCol] = tempSub;
                    largest = 0;
                }
                else {
                    break;
                }
            }
        }

        // вывод массива
        printf("отсортированный массив:\n");
        for (i = 0; i < s; i++) {
            for (j = 0; j < d; j++) {
                printf("%4d ", x[i][j]);
            }
            printf("\n");
        }

        return 0;
    }

}
int lab7() {
    {
        long z; // Объявление переменной для хранения введенного пользователем числа
        unsigned long y; // Объявление беззнаковой переменной для работы с битами числа
        int i; // Объявление переменной для использования в цикле

        printf("Введите число z : ");
        scanf("%ld", &z);
        y = (unsigned long)z; // Приведение типа переменной z к беззнаковому длинному целому

        // Проверка на симметричность двоичного представления числа
        unsigned long reversed = 0;
        unsigned long temp = y;
        while (temp) {
            reversed = (reversed << 1) | (temp & 1);
            temp >>= 1;
        }

        if (y == reversed) {
            printf("Двоичное представление числа %ld симметрично.\n", z);
        }
        else {
            printf("Двоичное представление числа %ld не симметрично.\n", z);
        }

        return 0;
    }
}