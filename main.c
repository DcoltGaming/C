#include <stdio.h>
#include <malloc.h>
#include <mem.h>

int main() {

    struct animal
    {
        char animal_Type[11];
        int age;
        int numberOfLegs;
        int walksPerDay;
        char **favoriteFood;
        unsigned int favoriteFoodSize;
    };


    char buffer[100];
    char *token;
    FILE *fp;
    fp = fopen("C:\\Users\\Dan\\CLionProjects\\Animals\\animals.txt","r");
    struct animal *animals = malloc(sizeof(struct animal) * 108);
    int i=0;

    while(fgets(buffer,100,fp)) {
        token=strtok(buffer,",");
        strcpy(animals[i].animal_Type,token);

        token=strtok(NULL,",");
        animals[i].age = atoi(token);

        token=strtok(NULL,",");
        animals[i].numberOfLegs = atoi(token);

        token=strtok(NULL,",");
        animals[i].walksPerDay = atoi(token);

        token=strtok(NULL,",");
        if(token) {
            animals[i].favoriteFood=malloc(sizeof(char *));
            animals[i].favoriteFood[animals[i].favoriteFoodSize]=strdup(token);
            animals[i].favoriteFoodSize=1;

            token=strtok(NULL,",");
            while(token) {
                animals[i].favoriteFood=realloc(animals[i].favoriteFood,(animals[i].favoriteFoodSize+1)*sizeof(char *));
                animals[i].favoriteFood[animals[i].favoriteFoodSize]=strdup(token);
                animals[i].favoriteFoodSize++;

                token=strtok(NULL,",");
            }
        }
    }


    return 0;
}