#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void game_init();

double health = 10.0;

int energy = 100;

int xp = 0;

/**
 * Výpis základních statistik
 */
void stats() {
    // výpis statistik
    printf("-----------------------------------------------\n");
    // výpis statistik na řádek
    printf("HP: %lf  ENERGY: %d  XP: %d\n", health, energy, xp);
    printf("-----------------------------------------------\n\n");
}

/**
 * Výpis hlavního menu
 */
void main_menu() {
    // výpis menu
    printf("------------------------------------------\n");
    printf("Vitej ve hre ORBIS GAME\n\n");
    printf("MENU:\n");
    printf("1. Nova hra\n");
    printf("2. Ukoncit\n");
    printf("------------------------------------------\n");
}

/**
 * Soubojový systém s hláškai
 * @return
 */
int battle() {
    // výpis statistik uživatele
    stats();
    printf("\n");

    // menu soubojového systému
    printf("-----------------\n");
    printf("Vyber akci:\n");
    printf("1 - utok\n");
    printf("2 - obrana\n");
    printf("-----------------\n");

    // definice proměnné a získání dat od uživatele z klávesnice
    int choice;
    scanf("%d", &choice);

    // definice náhodné 1 nebo 0 při souboji
    srand(time(0));
    int random = rand() % 2; // 0, 1

    // reagování na výhru nebo prohru
    if (random == 1) {
        printf("Souboj si vyhral :) !\n");
        xp += 30; // TODO: random 10 - 50
    } else {
        printf("Souboj si prohrál :( !\n");
        health--; // TODO: přepsat na random - 1 - 2 životy v des. čísle
    }

    energy -= 25; // TODO: random 5 - 30

    // vrácení dat o výhře nebo prohře
    return random;
}

/**
 * Otevření menu obchodu s akcemi
 */
void shop_init() {
    printf("Vitejte v obchode\n\n");

    // výpis tabulky statistik
    stats();
    printf("\n");

    // výpis menu obchodu
    printf("Vyber si danou akci.\n");
    printf("-------------------------------------\n");
    printf("1 - koupit zivot\n");
    printf("2 - koupit energii\n");
    printf("3 - zpet\n");
    printf("-------------------------------------\n");

    // definice proměnné a získání dat od uživatele z klávesnice
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        // uživatel zvolil koupění živata
        case 1:
            // pokud je život větší než 9, nastav na 10, jinak přičti +1 k životu
            if (health >= 9) {
                printf("Mas plny pocet zivotu\n\n");
                health = 10;
            } else {
                printf("Koupil jsi život\n\n");
                health++;
            }
            // opětovné otevření shopu
            shop_init();
            break;
        case 2:
            printf("Koupil jsi energii\n\n");
            shop_init();
            break;
        case 3:
            game_init();
            break;
        default:
            shop_init();
    }
}

/**
 * Inicializace hry
 */
void game_init() {
    printf("Vitejte ve hre\n\n");

    // výpis statistik uživatele
    stats();
    printf("\n");

    // výpis menu hry
    printf("Jsi na krizovatce, rozhodni se, kam pujdes.\n");
    printf("-------------------------------------\n");
    printf("1 - cesta do lesa\n");
    printf("2 - cesta na skalu\n");
    printf("3 - cesta do obchodu\n");
    printf("-------------------------------------\n");

    // definice proměnné a získání dat od uživatele z klávesnice
    int choice;
    scanf("%d", &choice);

    // reakce na danou akci uživatele
    switch (choice) {
        case 1:
            printf("Potkal si pavouka, budes bojovat\n\n");
            battle(); // 1 = vyhra, 0 = prohra
            game_init();
            break;
        case 2:
            printf("Potkal jsi kostlivce, budeš bojovat\n\n");
            battle(); // 1 = vyhra, 0 = prohra
            game_init();
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
    // zapnutí menu
    main_menu();

    // definice proměnné a získání dat od uživatele z klávesnice
    int choice;
    scanf("%d", &choice);

    // reagování na uživatelovu volbu
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
