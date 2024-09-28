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
}//参考了AI关键词为qsort用法

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
        qsort(cocktailList, numCocktails, sizeof(Cocktail), compareCocktails); //对其进行排序

        printf("%s, %.1f,%d,%d\n", cocktailList[4].name, cocktailList[4].baseStrength, cocktailList[4].baseVolume, cocktailList[4].nonAlcoholicBeveragesVolume);
        //无酒精水例外故单独输出必定在4位置上的无酒精水
        for (int i = 0;i < numCocktails-1;i++)//输出最后排序的顺序，-1是为了避免输出无酒精水
        {   
            
            printf("%s, %.1f,%d,%d\n", cocktailList[i].name, cocktailList[i].baseStrength, cocktailList[i].baseVolume, cocktailList[i].nonAlcoholicBeveragesVolume);
        }

         return EXIT_SUCCESS;
     }
   

