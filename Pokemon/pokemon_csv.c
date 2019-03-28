#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define FILENAME 1

typedef struct poke_t{
  int num;
  char name[150];
  char type1[10];
  char type2[10];
  int total;
  int hp;
  int attack;
  int defence;
  int spAttack;
  int spDefence;
  int speed;
  int gen;
  char legendary[5];
}


int
main(int argc, char* argv[]){
  char line[1024];
  char input[20];
  int pokeNum;
  strcpy(input, argv[FILENAME]);

  // Read the csv file
  FILE* fp = fopen(input, "r");
  printf("What Pokemon to select? ");
  scanf("%d",&pokeNum);
  if(fp != NULL){
    for(int i = 0;fgets(input, sizeof(input), fp);i++){
      if(i == pokeNum){
        break;
      }
      ///Should i make an array of pointers to structs?
    }
  }

}
