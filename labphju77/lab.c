#include "lab.h"
int lab1() {
    // ���� �������� ������
    float V; // ����� ��������
    float v1; // �������� ���������
    float t; // ����� ����������� ��������
    float v2; // �������� ����������
    // ���� �������� ������
    // ����� �� ����� V =
    printf("V = ");
    // ���� � ���������� �������� V
    scanf("%f", &V);
    printf("v1 = ");
    scanf("%f", &v1);
    printf("t = ");
    scanf("%f", &t);
    // �������
    v2 = v1 - V / t;
    // ����� v2
    printf("v2 = %f\n", v2);
    return 0;
}
int lab2() {
    float S; // ����� ����
    float i; // ����� ���������� �������� ����
    int n; // ����� ��������� ����
    int k; // �����������, ����� �������� ������������������
    float a; // ���� ������������������
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
    int z = 0;//���������� �������� � ������� �����
    int m = 0;//���������� ����
    int sum = 0;//����� ���� ���� ����
    char c;
    printf("������� ������ ");
    c = getchar();
    while ((c = getchar()) != '\n') {
        stroka[i++] = c;
    }
    stroka[i] = '\0';// ��������� ������ ������� ��������
    char* y = stroka;
    // ������� ������� ����� �����
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
    printf("%d", (sum - m + 1) / m);// ���������� ������� ����� �����
    return 0;
}
int dzlab3() {
    char stroka[100];
    int i = 0;
    int z = 0; // ���������� �������� � ������� �����
    int m = 0; // ���������� ����
    int sum = 0; // ����� ���� ���� ����
    int max = 0; // ����� ������ �������� �����
    int c;
    printf("������� ������  ");
    c = getchar();
    while ((c = getchar()) != '\n') {
        stroka[i++] = c;
    }
    stroka[i] = '\0'; // ��������� ������ ������� ��������

    char* y = stroka;
    // ������� ������� ����� �����
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

    printf("������� ����� �����: %d\n", (sum - m + 1) / m);
    printf("����� ������ �������� �����: %d\n", max);

    return 0;
}

int lab5() {
    {
        int x[N]; // ���������� ������� �� N ���������
        int positive = 0; // ���������� ��� �������� ����� ������������� ���������
        int negative = 0; // ���������� ��� �������� ����� ������� ������������� ���������
        int i; // ������� �����

        // ���� �������
        printf("������� %d ����� �����:\n", N);
        for (i = 0; i < N; i++)
            scanf("%d", &x[i]);

        // ���������� ���� ������������� � ������������� ���������
        for (i = 0; i < N; i++) {
            if (x[i] > 0)
                positive += x[i]; // ���������� ������������� ��������� � ����� �������������
            else
                negative += -x[i]; // ���������� ������� ������������� ��������� � ����� �������������
        }

        // ���� ����� ������� ������������� ��������� ������ ����� ������������� ���������
        if (negative < positive) {
            // ���������� ��������� ���������
            for (i = 0; i < N; i++) {
                if (x[i] < 0)
                    x[i] = 0; // ��������� ������������� ���������
            }
        }

        // ����� �������
        printf("���������� ������:\n");
        for (i = 0; i < N; i++)
            printf("%d ", x[i]);
        printf("\n");

        return 0;
    }
}
int lab4(void) {
    char ch;
    int ii = 0;
    char buffer[MAXLINE]; // ���������� ������� �������� ��� �������� ������
    printf("Enter a line of text: ");
    ch = getchar();
    while ((ch = getchar()) != '\n') {
        buffer[ii++] = ch;

    }  // ��������� ������ � ����������

   // ����� ������� ��� ��������� ������
      // ����� ������������ ������
    char c; // ������� ������
    int flag; // ������� �����
    int odd_length; // ������� �������� ����� �����
    int i; // ������� �������� ������� � �������� ������
    int pos; // ������� �������� ������� � �������������� ������
    int start; // ������� ������ �����
    flag = NO;  // ������������� ����� ����� ��� "����"
    odd_length = NO;  // ������������� �������� �������� ����� ��� "����"
    start = 0;  // ������������� ������� ������ �����
    i = 0;  // ������������� ������� ������� ������� � �������� ������
    pos = 0;  // ������������� ������� ������� ������� � �������������� ������
    //int g;
    // ���� ��������� �������� ������
    do {
        c = buffer[i]; // ��������� �������� ������� �� ������

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
        int x[N]; // ���������� ������� �� N ���������
        int positive = 0; // ���������� ��� �������� ����� ������������� ���������
        int negative = 0; // ���������� ��� �������� ����� ������� ������������� ���������
        int i; // ������� �����
        // ���� �������
        printf("������� %d ����� �����:\n", N);
        for (i = 0; i < N; i++)
            scanf("%d", &x[i]);

        // ���������� ���� ������������� � ������������� ���������
        for (i = 0; i < N; i++) {
            if (x[i] > 0)
                positive += x[i];
            else
                negative -= x[i]; // ���������� ������������� �������� ��� ������
        }

        // ���� ����� ������� ������������� ��������� ������ ����� ������������� ���������
        if (negative < positive) {
            // �������� ������������� ��������
            for (i = 0; i < N; i++) {
                if (x[i] > 0)
                    x[i] = 0;
            }
        }

        // ����� �������
        printf("���������� ������:\n");
        for (i = 0; i < N; i++)
            printf("%d ", x[i]);
        printf("\n");

        return 0;
    }

}
int lab6() {
    {
        int x[K][Z]; // ������ �� K �� N ���������
        int i, j;
        int is_progression; // ����, �����������, �������� �� ������ �������������� �����������

        // ���� �������
        printf("������� �������� �������:\n");
        for (i = 0; i < K; i++) {
            for (j = 0; j < Z; j++) {
                scanf("%d", &x[i][j]);
            }
        }

        // �������� ������ ������ �� �������������� ����������
        for (i = 0; i < K; i++) {
            is_progression = 1; // ������������, ��� ������ �������� �����������

            // ��������� ��������� ����� ���������� � ������
            int ratio = x[i][1] / x[i][0];

            for (j = 1; j < Z; j++) {
                if (x[i][j] != x[i][j - 1] * ratio) {
                    is_progression = 0; // ������ �� �������� �����������
                    break;
                }
            }

            // ����� ���������� ��� ������� ������
            if (is_progression) {
                printf("������ %d �������� �������������� �����������.\n", i + 1);
            }
            else {
                printf("������ %d �� �������� �������������� �����������.\n", i + 1);
            }
        }

        return 0;
    }
}
int dzlab6() {
    {
        int x[s][d]; // ������ �� s �� d ���������
        int i, j;

        // ���� �������
        printf("������� ������ %dx%d:\n", s, d);
        for (i = 0; i < s; i++) {
            for (j = 0; j < d; j++) {
                scanf("%d", &x[i][j]);
            }
        }

        int size = s * d;

        // ���������� ����
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

        // ���������� ��������� �� ����
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

        // ����� �������
        printf("��������������� ������:\n");
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
        long z; // ���������� ���������� ��� �������� ���������� ������������� �����
        unsigned long y; // ���������� ����������� ���������� ��� ������ � ������ �����
        int i; // ���������� ���������� ��� ������������� � �����

        printf("������� ����� z : ");
        scanf("%ld", &z);
        y = (unsigned long)z; // ���������� ���� ���������� z � ������������ �������� ������

        // �������� �� �������������� ��������� ������������� �����
        unsigned long reversed = 0;
        unsigned long temp = y;
        while (temp) {
            reversed = (reversed << 1) | (temp & 1);
            temp >>= 1;
        }

        if (y == reversed) {
            printf("�������� ������������� ����� %ld �����������.\n", z);
        }
        else {
            printf("�������� ������������� ����� %ld �� �����������.\n", z);
        }

        return 0;
    }
}