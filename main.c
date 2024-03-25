#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void game_init();

double health = 10.0;

void main_menu() {
    printf("------------------------------------------\n");
    printf("Vitej ve hre ORG GAME\n\n");
    printf("MENU:\n");
    printf("1. Nova hra\n");
    printf("2. Ukoncit\n");
    printf("------------------------------------------\n");
}

int battle() {
    printf("-----------------\n");
    printf("Vyber akci:\n");
    printf("1 - utok\n");
    printf("2 - obrana\n");
    printf("-----------------\n");

    int choice;
    scanf("%d", &choice);

    srand(time(0));
    int random = rand() % 2; // 0, 1

    if (random == 1) {
        printf("Souboj si vyhral :) !\n");
    } else {
        printf("Souboj si prohrál :( !\n");
    }

    return random;
}

void shop_init() {
    printf("Vitejte v obchode\n\n");

    printf("Vyber si danou akci.\n");
    printf("-------------------------------------\n");
    printf("1 - koupit zivot\n");
    printf("2 - koupit energii\n");
    printf("3 - zpet\n");
    printf("-------------------------------------\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (health >= 10) {
                printf("Mas plny pocet zivotu\n\n");
            } else {
                printf("Koupil jsi život\n\n");
                health++;
            }

            break;
        case 2:
            printf("Koupil jsi energii\n\n");
            break;
        case 3:
            game_init();
            break;
        default:
            shop_init();
    }
}

void game_init() {
    printf("Vitejte ve hre\n\n");

    printf("Jsi na krizovatce, rozhodni se, kam pujdes.\n");
    printf("-------------------------------------\n");
    printf("1 - cesta do lesa\n");
    printf("2 - cesta na skalu\n");
    printf("3 - cesta do obchodu\n");
    printf("-------------------------------------\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Potkal si pavouka, budes bojovat\n\n");
            int result = battle(); // 1 = vyhra, 0 = prohra
            // TODO: pokud vyhraje přidat XP, pokud prohraje, ubrat životy
            break;
        case 2:
            printf("Potkal jsi kostlivce, budeš bojovat\n\n");
            int result2 = battle(); // 1 = vyhra, 0 = prohra
            // TODO: pokud vyhraje přidat XP, pokud prohraje, ubrat životy
            break;
        case 3:
            shop_init();
            break;
        default:
            printf("Tato moznost neexistuje\n\n");
            game_init();
    }
}

int main() {
    main_menu();

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            game_init();
            break;
        case 2:
            printf("Hra ukoncena.");
            break;
        default:
            printf("Neznámá akce.");
    }

    return 0;
}
