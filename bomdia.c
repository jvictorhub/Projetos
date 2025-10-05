/*
    Desenvolvido por João Victor Rodrigues da Silva
    Estudante da Univerdade Estadual Vale do Rio Acaraú - UEVA
    Sugestão de compilação:
        gcc bomdia.c -o bomdia
*/

#include <stdio.h> // para os comandos: printf(), scanf(), getchar()
#include <string.h> //para o comando: strcmg(x1, x2)
#include <stdlib.h> //para o comando: system()

void options();
void help();
void version();
int error(int boole, int argc, int step);
void run(int argc, char **argv);

void options(){
    printf("\t%-13s %-13s %-13s\n", "Long option", "Short option", "Functionality");
    printf("\t%-13s %-13s %-13s\n", "--help", "-h", "Software documentation\n");
    printf("\t%-13s %-13s %-13s\n", "--version", "-v", "Software version\n");
    printf("\t%-13s %-13s %-13s\n", "--pt", "-1", "Portuguese language\n");
    printf("\t%-13s %-13s %-13s\n", "--en", "-2", "English language\n");
    printf("\t%-13s %-13s %-13s\n", "--es", "-3", "Spanish language\n");
    printf("\t%-13s %-13s %-13s\n", "--fr", "-4", "French language\n");
    printf("\t%-13s %-13s %-13s\n", "--it", "-5", "Italian language\n");
    printf("\t%-13s %-13s %-13s\n", "--co", "-6", "Korean language\n");
    printf("\t%-13s %-13s %-13s\n", "--ja", "-7", "Japanese language\n");
    printf("\t%-13s %-13s %-13s\n", "--ru", "-8", "Russian language\n");
}
void help(){
    printf("bomdia version 1.0.0\n");
    printf("A short program that translate \"Good moorning\" for others languages\n");
    printf("Usage:\n\tbomdia [option]\n");
    printf("Options:\n");
    options();
    printf("Example of usage:\n");
    printf("\t bomdia --en\n");
    printf("\t bomdia -2\n");
}

void version(){
    printf("bomdia version 1.0.0\n");
}

int error(int boole, int argc, int step){
    if ((argc == 1)&&(step == 1)){
        printf("Error: missing argument.\nSee the menu of options:\n");
        options();
        boole = 1;
    }else if ((argc > 2)&&(step == 1)){
        printf("Error: More than one option has been selected.\nPlease, check the option -h for more information\n");
        boole = 1;
    }else if ((boole == 0)&&(step == 2))
        printf("Error: invalid option. \nPlease, check the option -h for more information\n");
    return boole;
}

void run(int argc, char **argv){
    int boole = 0, step = 1;
    boole = error(boole, argc, step);
    step += 1;
    if (boole == 0)
        if ((strcmp(argv[1], "--help") == 0)||(strcmp(argv[1], "-h") == 0)){
            help();
            boole = 1;
        }else if ((strcmp(argv[1], "--version") == 0)||(strcmp(argv[1], "-v") == 0)){
            version();
            boole = 1;
        }else if ((strcmp(argv[1], "--pt") == 0)||(strcmp(argv[1], "-1") == 0)){
            printf("Bom Dia!\n"); // português
            boole = 1;
        }else if ((strcmp(argv[1], "--en") == 0)||(strcmp(argv[1], "-2") == 0)){
            printf("Good Morning!\n"); // inglês
            boole = 1;
        }else if ((strcmp(argv[1], "--es") == 0)||(strcmp(argv[1], "-3") == 0)){
            printf("Buen día!\n"); // espanhol
            boole = 1;
        }else if ((strcmp(argv[1], "--fr") == 0)||(strcmp(argv[1], "-4") == 0)){
            printf("Bonjour!\n"); // francês
            boole = 1;
        }else if ((strcmp(argv[1], "--it") == 0)||(strcmp(argv[1], "-5") == 0)){
            printf("Buongiorno!\n"); //italiano
            boole = 1;
        }else if ((strcmp(argv[1], "--co") == 0)||(strcmp(argv[1], "-6") == 0)){
            printf("좋은 아침이에요!\n"); // coreano
            boole = 1;
        }else if ((strcmp(argv[1], "--ja") == 0)||(strcmp(argv[1], "-7") == 0)){
            printf("おはよう!\n"); //japonês
            boole = 1;
        }else if ((strcmp(argv[1], "--ru") == 0)||(strcmp(argv[1], "-8") == 0)){
            printf("Доброе утро!\n"); //russo
            boole = 1;
        }else if (boole == 0)
            error(boole, argc, step);
}
int main(int argc, char **argv){
    system("clear");
    run(argc, argv);
    return 0;
}
