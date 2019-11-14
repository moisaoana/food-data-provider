#include <stdio.h>
#include <stdlib.h>
#define MAX_FOOD_NAME 10
#define MAX_TYPE_NAME 20
void readType(char * type);
double readPrice();

int main() {
    int noOfFoods, noOfDrinks;
    char ** foods, **drinks;
    int *noOfTypes=(int*)malloc(noOfFoods*sizeof(int));
    char *** types=(char ***)malloc(noOfFoods*sizeof(char**));
    double ** prices = (double**)malloc(noOfFoods* sizeof(double*));
    double * drinkPrices=(double *)malloc(noOfDrinks* sizeof(double));
    printf("Please input number of food types\n");
    scanf("%d", &noOfFoods);
    getchar();
    printf("Please input the food types (each on a new line, may contain spaces)\n");
    foods=(char**)malloc(noOfFoods*sizeof(char*));
    for(int i=0;i<noOfFoods;i++)
    {
        foods[i]=(char*)malloc(MAX_FOOD_NAME*sizeof(char));
        gets(foods[i]);
    }
    for(int i=0;i<noOfFoods;i++)
    {
        printf("Please input no of specific foods for food \"%s\"\n",foods[i]);
        scanf("%d",&noOfTypes[i]);
        getchar();
        types[i] = (char**)malloc(noOfTypes[i]* sizeof(char*));
        prices[i] = (double*)malloc(noOfTypes[i]* sizeof(double));
        printf("Please input specific foods &prices: each line in the format <specific food> (price):\n");
        for(int j=0;j<noOfTypes[i];j++){
           types[i][j] = (char*)malloc(MAX_TYPE_NAME* sizeof(char));
           readType(types[i][j]);
           prices[i][j]=readPrice();
        }
    }
    printf("Please input no of drinks\n");
    scanf("%d", &noOfDrinks);
    getchar();
    printf("Please input the drinks: each line in the format <drink> (price):\n");
    drinks=(char**)malloc(noOfDrinks*sizeof(char*));
    for(int i=0;i<noOfDrinks;i++)
    {
        drinks[i]=(char*)malloc(MAX_FOOD_NAME*sizeof(char));
        readType(drinks[i]);
        drinkPrices[i]=readPrice();
    }
    printf("The food data is:\n");
    for(int i=0;i<noOfFoods;i++) {
        printf("%s: ", foods[i]);
        for(int j=0;j<noOfTypes[i];j++) {
            printf("(%s - %.2lf) ",types[i][j],prices[i][j]);
        }
        printf("\n");
    }
    printf("The drinks data is:\n");
    printf("drinks: ");
    for(int i=0;i<noOfDrinks-1;i++)
    {
        printf("%s, ", drinks[i]);
    }
    printf("%s\n", drinks[noOfDrinks-1]);
    printf("prices: ");
    for(int i=0;i<noOfDrinks-1;i++)
    {
        printf("%.0lf, ",drinkPrices[i] );
    }
    printf("%.0lf", drinkPrices[noOfDrinks-1]);

    for(int i=0;i<noOfFoods;i++) {
        for(int j=0;j<noOfTypes[i];j++) {
            free(types[i][j]);
        }
        free(types[i]);
        free(prices[i]);
        free(foods[i]);
    }
    free(types);
    free(prices);
    free(foods);
    free(noOfTypes);
    for(int i=0; i<noOfTypes[i];i++)
    {
        free(drinks[i]);
    }
    free(drinks);
    free(drinkPrices);
    return 0;
}

void readType(char * type) {
    char c = getchar();
    int i=0;
    while(c!='(') {
        type[i] = c;
        c = getchar();
        i++;
    }
    type[i-1] = '\0';
}

double readPrice()
{
    double price=0;
    char c;
    c=getchar();
    while(c!=')')
    {
        price=price *10+ (c-'0');
        c=getchar();

    }
    getchar();
    return price;
}