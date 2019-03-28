#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct moves{
  char name[256];
  int dmg;
}moves_t;

typedef struct pokemon{
  char name[256];
  int hp;
  int lvl;
  int atk;
  int def;
  moves_t moveset[2*(int)sizeof(moves_t)];
}pokemon_t;



pokemon_t player,comp;
moves_t move;

/*data*/
char name[3][256] = {"Pikachu", "Bulbasaur","Charmander"};
int health[3] = {50,55,53};
int attacks[3] = {6 ,5, 7};
int defence[3] = {4 ,5, 3};
char moveName[6][50] = {"Tackle", "Tackle","Scratch","Electrobolt", "Grasscut", "Fireball"};
int moveDmg[16] = {3,3,3,5,5,5};


void moveapplier(int i,moves_t* movesets){
    int k = 0;
    for(int x = i; x<6;x+=3){
      moves_t newmove;
      strcpy(newmove.name,moveName[x]);
      newmove.dmg = moveDmg[x];
      movesets[k] = newmove;
      k++;
  }
}



pokemon_t pokemonCreator(int i){
  pokemon_t pokemon;
  strcpy(pokemon.name,name[i]);
  pokemon.hp = health[i];
  pokemon.lvl = 10;
  pokemon.atk= attacks[i];
  pokemon.def = defence[i];
  moveapplier(i,pokemon.moveset);
  printf("Pokemon created....\n");
  return pokemon;
}

void print_stats(){
  printf("Player           Computer\n");
  printf("HP:%d            HP:%d\n",player.hp,comp.hp);
  printf("\n");
}

void print_attacks(){
  for(int i = 0; i<2;i++){
    printf("%d : %s Dmg:%d\n",i, player.moveset[i].name, player.moveset[i].dmg);
  }
}

int getdmg(int x, pokemon_t attacker,pokemon_t target){
  return attacker.moveset[x].dmg * (attacker.atk/target.def);
}

void takedmg(int dmg, pokemon_t* poke){
  poke->hp = poke->hp - dmg;
  printf("%s deals %d damage\n",poke->name,dmg);
}

void winnerDecider(){
  if(player.hp <= 0){
    printf("************* COMPUTER WINS!!***********\n");
  }else{
    printf("************* PLAYER WINS!!***********\n");
  }
}

int
main(){
  int choice,comp_choice;
  int move_p,move_c;

  srand(time(NULL));

  printf("Select your Pokemon: \n");
  for(int i = 0;i<3;i++){
    printf("%d: %s\n",i, name[i]);
  }
  scanf("%d",&choice);

  if(choice > 3){
     printf("Sorry not a choice.");
  }else{
    printf("%s selected\n",name[choice]);
    player = pokemonCreator(choice);
    printf("Computer picking pokemon...\n");
    comp_choice = rand()%3;
    comp = pokemonCreator(comp_choice);
    printf("Computer chose %s\n", name[comp_choice]);
    printf("Battle!!!\n\nPlayer start!\n\n");

    while(player.hp > 0 && comp.hp > 0){
      print_stats();

      printf("What will you do?\n");

      print_attacks();

      scanf("%d",&move_p);
      if(move_p<4 && move_p>=0){
        move_c = rand()%2;
        int p_dmg = getdmg(move_p,player,comp);
        takedmg(p_dmg, &comp);
        int c_dmg = getdmg(move_c,comp,player);
        takedmg(c_dmg,&player);
      }else{
        printf("Invalid move!\n\n");
      }

}
  print_stats();
  winnerDecider();
}
  return 0;
}
