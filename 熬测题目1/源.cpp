#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char name[50];
    float baseStrength;
    int baseVolume;
    int nonAlcoholicBeveragesVolume;
}Cocktail;
int compareCocktails(const void* a, const void* b)
{
    float pa = (((Cocktail*)a)->baseStrength) * (((Cocktail*)a)->baseVolume) / (((Cocktail*)a)->nonAlcoholicBeveragesVolume);
    float pb = (((Cocktail*)b)->baseStrength) * (((Cocktail*)b)->baseVolume) / (((Cocktail*)b)->nonAlcoholicBeveragesVolume);
     return pb-pa;
}//�ο���AI�ؼ���Ϊqsort�÷�

    int main()
{
         Cocktail cocktailList[] = {
             {"Cocktail0", 10.0f, 50, 120},
             {"Cocktail1", 30.0f, 100, 300},
             {"Cocktail2", 12.8f, 50, 150},
             {"Soda", 0.0f, 0, 330},
             {"Cocktail4", 43.2f, 80, 120}
         };

        int numCocktails = sizeof(cocktailList) / sizeof(cocktailList[0]);
        qsort(cocktailList, numCocktails, sizeof(Cocktail), compareCocktails); //�����������

        printf("%s, %.1f,%d,%d\n", cocktailList[4].name, cocktailList[4].baseStrength, cocktailList[4].baseVolume, cocktailList[4].nonAlcoholicBeveragesVolume);
        //�޾ƾ�ˮ����ʵ�������ض���4λ���ϵ��޾ƾ�ˮ
        for (int i = 0;i < numCocktails-1;i++)//�����������˳��-1��Ϊ�˱�������޾ƾ�ˮ
        {   
            
            printf("%s, %.1f,%d,%d\n", cocktailList[i].name, cocktailList[i].baseStrength, cocktailList[i].baseVolume, cocktailList[i].nonAlcoholicBeveragesVolume);
        }

         return EXIT_SUCCESS;
     }
   

