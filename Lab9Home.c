#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(){
    setlocale(LC_ALL, "Russian");
    char ch;
    float alpha;
    int s;
    int H;
    int xs;
    int i;
    int j;
    int left;
    int right;
    double beta;
    double gamma;
    double radAlpha;
    double radBeta;
    double radGamma;
    double pi;
    double h;
    double xS;

    printf("Введите символ для рисования:\n");
    scanf(" %c", &ch);
    printf("Введите острый угол alpha (в градусах от 31 до 89):\n");
    scanf("%f", &alpha);
    printf("Введите длину стороны s (основания в символах):\n");
    scanf("%d", &s);

    if (alpha <= 30.0 || alpha >= 90.0 || s <= 1) {
        printf("Ошибка: угол alpha должен быть в диапазоне от 31 до 89 градусов, а сторона s > 1.\n");
        return 1;
    }

    beta = 60.0;
    gamma = 180.0 - (double)alpha - beta;
    pi = 3.14159265;
    radAlpha = (double)alpha * pi / 180.0;
    radBeta = beta * pi / 180.0;
    radGamma = gamma * pi / 180.0;

    h = (double)s * sin(radAlpha) * sin(radGamma) / sin(radBeta);
    xS = (double)s * cos(radAlpha) * sin(radGamma) / sin(radBeta);

    H = (int)(h + 0.5);
    xs = (int)(xS + 0.5);

    if (H < 2) {
        H = 2;
    }

    printf("\nРезультат:\n");
    for (i = 0; i < H; i++) {
        left = (int)((double)xs * (double)(H - 1 - i) / (double)(H - 1) + 0.5);
        right = (int)((double)xs + (double)(s - 1 - xs) * (double)i / (double)(H - 1) + 0.5);
        for (j = 0; j < left; j++) {
            printf(" ");
        }
        for (j = left; j <= right; j++) {
            printf("%c", ch);
        }
        printf("\n");
    }

    return 0;
}
