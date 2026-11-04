#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Russian");
    char ch;
    int n, str, stl;
    double x;
    double y;
    printf("Введите символ из которого будет строиться фигура\n");
    scanf("%c", &ch);
    printf("Введите размер фигуры в символах:\n");
    scanf("%d", &n);

    printf("Результат:\n");
    for (str=0; str<n; str++){
        y = -3.0 * (double)str / (double)(n-1);
        for(stl=0; stl<n; stl++){
            x = 3.0 * (double)stl / (double)(n-1);
            if (x >= 0.0 && y<=0.0 && x*x+y*y>=2 && y>=x-3.0){
                printf("%c", ch);
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }

}