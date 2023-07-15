#include <stdio.h>
#include <stdlib.h>


// fonction REGLES

void regles()
{
    int back_menu;

    printf("\t\t\t\t\t\t[Regles du jeu du Juste Prix]\n\n");
    printf("Objectif du jeu :\n\n");
    printf("Le jeu du Juste Prix consiste a deviner un nombre mystere en utilisant des indices donnes par le jeu.\n\n");
    printf("Modes de jeu : \n\na) Mode sans limites de tentatives : Le jeu genere un nombre mystere compris entre 1 et 2000.\nLe joueur peut faire autant de tentatives qu il le souhaite pour deviner le nombre mystere\n\nb) Mode avec limites de tentatives :\nLe jeu genere un nombre mystere compris entre 1 et 100.\nLe joueur dispose de 10 tentatives maximum pour deviner le nombre mystere\n\n");
    printf("Deroulement du jeu :\n\n");
    printf("Le joueur commence par entrer un nombre dans la console pour faire sa proposition.\n");
    printf("Le jeu fournit ensuite un indice au joueur pour l'aider a affiner sa prochaine proposition.\n\n");
    printf("Indices fournis par le jeu :\n\n");
    printf("Si la proposition du joueur est exacte et correspond au nombre mystere, le joueur a gagne !\n");
    printf("Si la proposition est moins elevee que le nombre mystère, le jeu indique \"c'est moins\" \n");
    printf("Si la proposition est plus elevee que le nombre mystère, le jeu indique \"c'est plus\" \n\n");
    printf("Continuite du jeu :\n\n");
    printf("Le joueur continue de faire des propositions jusqu'a ce qu'il trouve le nombre mystère, ou qu'il abandonne, car le programme propose a partir de 100 tentatives d'abandonner a chaque nouvelle mauvaise proposition(mode sans limites de tentatives) ou atteigne le nombre maximum de tentatives autorisees (mode avec limites de tentatives).\n\n");
    printf("Fin du jeu :\n\n");
    printf("a) Mode sans limites de tentatives :\n");
    printf("Le joueur gagne des qu'il trouve le nombre mystere.\n");
    printf("Le jeu affiche un message de félicitations au joueur.\n\n");
    printf("b) Mode avec limites de tentatives :\n\n");
    printf("Si le joueur épuise toutes ses tentatives sans trouver le nombre mystere, il perd.\n");
    printf("Le jeu affiche un message indiquant que le joueur a perdu et révèle le nombre mystere.\n\n");

    printf("\t\t\t Pour retourner au MENU entrez 1\n\n");
    scanf("%d", &back_menu);
    if(back_menu == 1)
    {
        main();
    }


}

// fonction JEU SANS LIMITE DE TENTATIVES

void jeu_sans_limit()
{
    int abandon;
    int nb_essai = 0;
    int continue_choice;
    int nombre_mystere = 0, nombre_utilisateur = 0;

    const int MIN_VAL = 1, MAX_VAL = 2000;




    printf("\t\t\t[MODE DE JEU SANS LIMITATIONS DE TENTATIVES]\n\n");



    // boucle du jeu

    do
    {
        // génération d'un nomnre aléatoire
       srand(time(NULL));
       nombre_mystere = (rand()% (MAX_VAL-MIN_VAL +1)) + MIN_VAL;






        // consignes
        printf("\t \t \t \t \t \t ----------Jouons au juste prix ----------\n \n");
        printf("\t \t\t  Entrez un nombre entre 1 et 2000 si vous tombez sur le juste prix c'est gagner ! \n");

        do
        {


            // Comparaisons du nombre de l'utilisateur avec le nombre mystère


             printf("Votre proposition : \n");
             scanf("%d", &nombre_utilisateur);
             nb_essai++;




             if ((nombre_utilisateur < 0) || (nombre_utilisateur > 2000))
             {
                 printf("Veuillez entrer un nombre compris entre 1 et 2000 \n");
                 continue;
             }



             if (nombre_mystere < nombre_utilisateur)
                {
                    printf("C'est moins !\n");

             }
             else if (nombre_mystere > nombre_utilisateur)
             {
                 printf("C'est plus !\n");
             }
             else
            {
                 printf("Felicitations !!! mais y'avait rien a gagner dsl \n");
                 break;

            }

            for (int i = 1; i<=nb_essai; i++)
            {
                if(i % 100 == 0)
                {
                    printf("vous avez fait %d essais deja.\n Souhaitez vous continuer ? [1-->OUI/2-->NON]\n", nb_essai);
                    scanf("%d", &abandon);
                    if(abandon == 2)
                    {
                        printf("Dommage, le juste prix etait %d \n A bientot", nombre_mystere);
                        main();

                    }
                }
            }

        }while (nombre_mystere != nombre_utilisateur);

        // Choix utilisateur de rejouer

        printf("Souhaitez vous rejouer ? 1 --> oui / 2 --> non / 3--> MENU \n");
        scanf("%d", &continue_choice);
        if(continue_choice == 3)
        {
            main();
        }




    }
    while(continue_choice == 1);

    printf(" A bientot");

}

//fonction JEU AVEC LIMITE DE TENTATIVES

void jeu_avec_limit()
{
    int continue_choice;
    int nombre_mystere = 0, nombre_utilisateur = 0;

    const int MIN_VAL = 1, MAX_VAL = 100;
    const int MAX_TENTATIVES = 0;




    printf("\t\t\t[MODE DE JEU AVEC LIMITATIONS DE TENTATIVES] \n\n");


    // boucle du jeu

    do
    {
        // génération d'un nomnre aléatoire
       srand(time(NULL));
       nombre_mystere = (rand()% (MAX_VAL-MIN_VAL +1)) + MIN_VAL;

       // Initialisation du nombre de tentatives
       int nb_tentatives = 10;




        // consignes
        printf("\t \t \t \t \t \t ----------Jouons au juste prix ----------\n \n");
        printf("\t \t\t  Entrez un nombre entre 1 et 100 si vous tombez sur le juste prix c'est gagner ! \n");

        do
        {


            // Comparaisons du nombre de l'utilisateur avec le nombre mystère



             if (nb_tentatives <= MAX_TENTATIVES)
             {
                 printf("Nombre de tentatives depassees ! \n \n ");
                 printf("Le nombre mystere etait : %d \n \n", nombre_mystere);
                 break;
             }

             printf("Votre proposition : \n");
             scanf("%d", &nombre_utilisateur);
             nb_tentatives--;


             if ((nombre_utilisateur < 0) || (nombre_utilisateur > 100))
             {
                 printf("Veuillez entrer un nombre compris entre 1 et 100 \n");
                 continue;
             }



             if (nombre_mystere < nombre_utilisateur)
                {
                    printf("C'est moins ! tentatives restante : %d \n", nb_tentatives);

             }
             else if (nombre_mystere > nombre_utilisateur)
             {
                 printf("C'est plus ! tentatives restantes : %d \n", nb_tentatives);
             }
             else
            {
                 printf("Felicitations !!! mais y'avait rien a gagner dsl \n");
                 break;

            }

        }while (nombre_mystere != nombre_utilisateur);

        // Choix utilisateur de rejouer

        printf("Souhaitez vous rejouer ? 1 --> oui / 2 --> non / 3--> MENU \n");
        scanf("%d", &continue_choice);
        if(continue_choice == 3)
        {
            main();
        }




    }
    while(continue_choice == 1);

    printf(" A bientot");

}

// fonction MAIN

int main()
{
    int choix;

    printf("\t\t\t\t\t------------------------[LE JUSTE PRIX]-------------------------\n\n\n\n");

    printf("[MENU] : \n");
    printf("\t 1: Jouer AVEC nb tentatives limitees\n");
    printf("\t 2: Jouer SANS nb tentatives limitees\n");
    printf("\t 3: Regles du jeu\n");
    printf("\t 4: Quitter\n");
    scanf("%d", &choix);

    switch(choix)
    {
    case 1:

        jeu_avec_limit();
        break;

    case 2:

        jeu_sans_limit();
        break;

    case 3:
        printf("\t\t\t [REGLES DU JEU]");
        regles();
        break;

    case 4:
        return 0;

    default:
        printf("Faire un choix valide svp ");
        break;

    }




    return 0;
}


