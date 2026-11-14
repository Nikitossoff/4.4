#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include "dynamic_m.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    setlocale(LC_NUMERIC, "C");

    FILE *inA = fopen("t1_A.txt","r");
    FILE *inB = fopen("t1_B.txt","r");
    FILE *inC = fopen("t1_C.txt","r");
    int na, nb, nc;

    do {
        printf("Введите количество строк N массива А: ");
        scanf("%i", &na);
        if (na <= 1 || na > 100) {
            printf("Ошибка! N должно быть больше 1.\n");
        }
    } while (na <= 1 || na > 100);

    do {
        printf("Введите количество строк N массива B: ");
        scanf("%i", &nb);
        if (nb <= 1 || nb > 100) {
            printf("Ошибка! N должно быть больше 1.\n");
        }
    } while (nb <= 1 || nb > 100);

    do {
        printf("Введите количество строк N массива C: ");
        scanf("%i", &nc);
        if (nc <= 1 || nc > 100) {
            printf("Ошибка! N должно быть больше 1.\n");
        }
    } while (nc <= 1 || nc > 100);

    int *A = NULL, *B = NULL, *C = NULL;
    Create(&A, na);
    Create(&B, nb);
    Create(&C, nc);

    Vvod(inA, A, na);
    Vvod(inB, B, nb);
    Vvod(inC, C, nc);

    int sa = sum(A, na);
    int sb = sum(B, nb);
    int sc = sum(C, nc);

    // Защита
    int min_a = min_pos(A, na);
    int min_b = min_pos(B, nb);
    int min_c = min_pos(C, nc);

    FILE *out = fopen("output.txt", "w");

    // Блок if-else для защиты
    if (min_a < min_b && min_a < min_c)
        fprintf(out, "В A наименьший положительный элемент (%i)\n", min_a);
    else if (min_b < min_c && min_b < min_a)
        fprintf(out, "В B наименьший положительный элемент (%i)\n", min_b);
    else if (min_c < min_a && min_c < min_b)
        fprintf(out, "В C наименьший положительный элемент (%i)\n", min_c);
    else if (min_a == min_b && min_a < min_c)
        fprintf(out, "В A и B наименьший положительный элемент (%i)\n", min_a);
    else if (min_a == min_c && min_a < min_b)
        fprintf(out, "В A и C наименьший положительный элемент (%i)\n", min_a);
    else if (min_b == min_c && min_b < min_a)
        fprintf(out, "В B и C наименьший положительный элемент (%i)\n", min_b);
    else
        fprintf(out, "Во всех трёх массивах наименьшие положительные элементы равны (%i)\n", min_a);

    fprintf(out, "--------------------------------\n");

    if (sa < sb && sa < sc)
        fprintf(out, "В A наименьшая сумма\n");
    else if (sb < sc && sb < sa)
        fprintf(out, "В B наименьшая сумма\n");
    else if (sc < sa && sc < sb)
        fprintf(out, "В C наименьшая сумма\n");
    else if (sa == sb && sa < sc)
        fprintf(out, "В A и B наименьшая сумма\n");
    else if (sa == sc && sa < sb)
        fprintf(out, "В A и C наименьшая сумма\n");
    else if (sb == sc && sb < sa)
        fprintf(out, "В B и C наименьшая сумма\n");
    else if (sa == 0 && sb == 0 && sc == 0)
        fprintf(out, "Во всех массивах суммы равны нулю\n");
    else
        fprintf(out, "Во всех трёх массивах суммы равны\n");

    fclose(inA);
    fclose(inB);
    fclose(inC);
    fclose(out);

    printf("Результат успешно записан в output.txt!\n");

    Ochistka(&A);
    Ochistka(&B);
    Ochistka(&C);

    return 0;
}
