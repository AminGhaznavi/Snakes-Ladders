#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
struct map {
	char type;
	int data;
};
struct player p1, p2;
struct player {
	char name[30];
	int position;
	int skip;
	bool shiled;
	int coins;
};
int roll_dice() {
	return(rand() % 6) + 1;
}
void s_board(struct map board[100]) {
    for (int i = 0; i < 100; i++) {
        board[i].type = 'n';   
        board[i].data = 0;
    }
    board[5-1].type = 'C'; board[5-1].data = 3;  
    board[12-1].type = 'C'; board[12-1].data = 2;
    board[69-1].type = 'C'; board[69-1].data = 1;
    board[85-1].type = 'C'; board[85-1].data = 2;
    board[26-1].type = 'C'; board[26-1].data = 5;
    board[37-1].type = 'C'; board[37-1].data = 3;

    
    board[2-1].type = 'T'; board[2-1].data = 10;   
    board[14-1].type = 'T'; board[14-1].data = 5;
    board[54-1].type = 'T'; board[54-1].data = 15;
    board[10-1].type = 'T'; board[10-1].data = 23;  

    
    board[19-1].type = 's'; board[19-1].data = -10;
    board[47-1].type = 's'; board[47-1].data = -14;
    board[82-1].type = 's'; board[82-1].data = -26;
    board[27-1].type = 's'; board[27-1].data = -15;
    board[99-1].type = 's'; board[99-1].data = -7;


    board[7].type = 'E';
    board[22].type = 'E';
    board[45].type = 'E';
    board[73].type = 'E';
}
void event(struct player *p);
void move_player(struct player *p, struct player *p2, int dice, struct map board[100]) {
    int newpos = p->position + dice;

    if (newpos > 100) {
        printf("%s cant move\n", p->name);
        return;
    }

    p->position = newpos;
    printf("%s go %d  \n", p->name, p->position);

    struct map cell = board[p->position - 1]; 

    if (cell.type == 'C') {
    p->coins += cell.data;
    printf("%s you got coin and your coin is: %d\n", p->name, p->coins);
    }
    
    if (cell.type == 'T') {
    p->position += cell.data;
    printf("new position: %d\n", p->position);
    }

    if (cell.type == 's') {
        if (p->shiled == true) {
         printf("%s has shield! Snake has no effect.\n", p->name);
            p->shiled = false;
        } 
        else {
             p->position += cell.data;
            if (p->position < 1) p->position = 1;
            printf("new position: %d\n", p->position);
        }
    }
        if (cell.type == 'E') {
        printf("!\n");
        event(p);
        }
        if (p->position == p2->position){
            if(p->shiled == true){
                p->shiled = false;
            }
            else{
                p2->position = 1;
            }
        }
    
}
int mode;
void save_game() {
    FILE* f = fopen("save.dat", "wb");
    if (f == NULL) {
        printf("Save failed!\n"); 
        return;
    }

    fwrite(&p1, sizeof(struct player), 1, f);
    fwrite(&p2, sizeof(struct player), 1, f);

    fclose(f);
    printf("Game saved!\n");
}
void start_game() {
	p1.position = 1;
	p2.position = 1;
	p1.coins = 0;
	p2.coins = 0;
	p1.shiled = false;
	p2.shiled = false;
	p1.skip = 0;
	p2.skip = 0;
	
    
}

bool load_game() {
    FILE* f = fopen("save.dat", "rb");
    if (f == NULL) {
        printf("No save file found!\n");
        return false;
    }

    fread(&p1, sizeof(struct player), 1, f);
    fread(&p2, sizeof(struct player), 1, f);
    
    fclose(f);
    printf("Game loaded!\n");
    return true;
}
int shop(struct player *p, int dice) {
    int choice;
    printf("\n%s you have %d coin, pls choose:\n", p->name, p->coins);
    printf("1. Reroll (3 coin)\n");
    printf("2. +1 for dice ( 2 coin)\n");
    printf("3. -1 for dice (1 coin)\n");
    printf("4. buy shiled (4 coin)\n");
    printf("5. never mined\n");
    printf("6. Save&Exit");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            if (p->coins >= 3) {
                p->coins -= 3;
                dice = roll_dice();
                printf("Reroll! new dice is: %d\n", dice);
            } else printf("you dont have enugh coin!\n");
            break;
        case 2:
            if (p->coins >= 2 && dice < 6) {
                p->coins -= 2;
                dice++;
                printf("+1 for your dice  %d\n", dice);
            } else printf("its impossible!\n");
            break;
        case 3:
            if (p->coins >= 1 && dice > 1) {
                p->coins -= 1;
                dice--;
                printf("-1 for your dice  %d\n", dice);
} else printf("its impossible!\n");
            break;
        case 4:
            if (p->coins >= 4) {
                p->coins -= 4;
                p->shiled = true;
                printf("you bought shiled!\n");
            } else printf("you dont have enough coin!\n");
            break;
        case 5:
             printf("Leaving shop...\n");
            break;
     
        case 6: 
            save_game();
            exit(0);

    default:
        printf("Invalid choice!\n");
    }
    return dice;
}
void print_board(struct player p1, struct player p2) {
    for (int row = 9; row >= 0; row--) {   
        for (int col = 0; col < 10; col++) {

            int ind = row * 10 + col + 1;   

            if (ind == p1.position)
                printf("[P1]");
            else if (ind == p2.position)
                printf("[P2]");
            else
                printf("[%02d]", ind);
        }
        printf("\n");
    }
}
void event(struct player *p) {
    int r = rand() % 6;

    switch (r) {
        case 0:
            printf("event: Move forward 3 spaces. !\n");
            p->position += 3;
            break;

        case 1:
            printf("event: Move back 2 spaces.!\n");
            p->position -= 2;
            if (p->position < 1) p->position = 1;
            break;

        case 2:
            printf("event: +2 coin!\n");
            p->coins += 2;
            break;

        case 3:
            printf("event: -1 coin!\n");
            if (p->coins > 0) p->coins -= 1;
            break;

        case 4:
            printf("event: move forward 1 house!\n");
            p->position += 1;
            break;

        case 5:
            printf("event: you cant move in this turn!\n");
            p->skip = 1;
            break;
    }

    printf("new position: %d\n", p->position);
}

int main() {
    int sw=1;
    srand(time(NULL));
    int game;
    for (game = 3;game != 2 && game != 1;) {
        printf("(1)Load game\n(2)New game\nchoose:");
        scanf("%d", &game);
        if (game != 2 && game != 1) {
            printf("wrong number");
        }
        if (game == 1) {
            sw=0;
            load_game();
            
        }
        else {
            start_game();
        }
    }

    struct map board[100];
    s_board(board);

    

    if(sw==1){
    printf("Choose mode:\n");
    printf("1. Two players\n");
    printf("2. Play with computer\n");
    scanf("%d", &mode);


    printf("Enter name for Player 1: ");
    scanf("%s", p1.name);
    p1.position = 1; p1.skip = 0; p1.shiled = false; p1.coins = 0;

    if (mode == 1) {
        printf("Enter name for Player 2: ");
        scanf("%s", p2.name);
    }
    else {
        strcpy(p2.name, "Computer");
    }
    p2.position = 1; p2.skip = 0; p2.shiled = false; p2.coins = 0;
    }
    while (1) {

        if (p1.skip == 1) {
            printf("%s skip this turn!\n", p1.name);
            p1.skip = 0;
        }
        else {
            int dice = roll_dice();
            printf("%s rolling dice: %d\n", p1.name, dice);
            dice = shop(&p1, dice);
            move_player(&p1, &p2, dice, board);
            print_board(p1, p2);
            if (p1.position == 100) { 
                printf("%s won!\n", p1.name); 
                break; 
            }
        }

        if (p2.skip == 1) {
            printf("%s skip this turn!\n", p2.name);
            p2.skip = 0;
        } 
        else {
            int dice = roll_dice();
             if (mode == 2) {
                printf("%s rolling dice: %d\n", p2.name, dice);
            } 
            else {
                printf("%s rolling dice: %d\n", p2.name, dice);
                dice = shop(&p2, dice);
            }
            move_player(&p2, &p1, dice, board);
            print_board(p1, p2);
            if (p2.position == 100) { 
                printf("%s won!\n", p2.name); 
                break; 
            }
        }
    }
    return 0;
}