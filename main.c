#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menu(int choix, int continue_choice, int continuer, int nombre_mystere, int nombre_utilisateur, int MIN_VAL, int MAX_VAL, int MAX_TENTATIVES, int nb_tentatives, int abandon);

void jeu_sans_limit(int choix, int continue_choice, int nombre_mystere, int nombre_utilisateur, int MIN_VAL, int MAX_VAL, int MAX_TENTATIVES, int nb_tentatives, int abandon, int continuer)
{

    nb_tentatives = 0;
    nombre_mystere = 0, nombre_utilisateur = 0;
    MIN_VAL = 1, MAX_VAL = 2000;
    MAX_TENTATIVES = 0;
    continuer = 0;

    printf("\t\t\t[MODE DE JEU SANS LIMITATIONS DE TENTATIVES] \n\n");

    do
    {
        // génération d'un nomnre aléatoire
       srand(time(NULL));
       nombre_mystere = (rand()% (MAX_VAL-MIN_VAL +1)) + MIN_VAL;


       printf("\t \t \t \t \t \t ----------Jouons au juste prix ----------\n \n");
       printf("\t \t\t  Entrez un nombre entre %d et %d si vous tombez sur le juste prix c'est gagner ! \n",MIN_VAL, MAX_VAL);

       do
       {
           if ((nombre_utilisateur < 0) || (nombre_utilisateur > 2000))
             {
                 printf("Veuillez entrer un nombre compris entre %d et %d \n", MIN_VAL, MAX_VAL);
                 continue;
             }

                 printf("Votre proposition : \n\n");
                 scanf("%d", &nombre_utilisateur);
                 nb_tentatives++;


             if (nombre_mystere < nombre_utilisateur)
                {
                    printf("C'est moins !\n\n");
             }
             else if (nombre_mystere > nombre_utilisateur)
             {
                 printf("C'est plus !\n\n");
             }
             else
            {
                 printf("\t\t\tFelicitations !!! mais y'avait rien a gagner dsl \n \n");
                 break;
            }

            if(nb_tentatives %10 == 0)
               {
                   printf("\t\t\tVous avez fait %d essais deja.\n \t\t\tSouhaitez-vous continuer ? [1-->OUI/2-->NON]\n\n", nb_tentatives);
                   scanf("%d", &abandon);
                   if (abandon !=1)
                   {
                       printf("\t\t\tDommage, le juste prix etait %d.\n\n", nombre_mystere);
                       break;
                   }
               }


       }while (nombre_mystere != nombre_utilisateur);

        printf("\t\t\tSouhaitez vous rejouer ? [1 --> OUI / 2--> NON] \n");
        scanf("%d", &continuer);
        if (continuer == 2)
        {
            menu(choix, continue_choice, nombre_mystere, nombre_utilisateur, MIN_VAL, MAX_VAL, MAX_TENTATIVES, nb_tentatives, abandon, continuer);
        }



    }while(continuer == 1);

}







void jeu_limit(int choix, int continue_choice, int nombre_mystere, int nombre_utilisateur, int MIN_VAL, int MAX_VAL, int MAX_TENTATIVES, int nb_tentatives, int abandon)
{
    nombre_mystere = 0, nombre_utilisateur = 0;

    MIN_VAL = 1, MAX_VAL = 100;
    MAX_TENTATIVES = 0;
    int continuer = 0;

    printf("\t\t\t[MODE DE JEU AVEC LIMITATIONS DE TENTATIVES] \n\n");



    do
    {
        // génération d'un nomnre aléatoire
       srand(time(NULL));
       nombre_mystere = (rand()% (MAX_VAL-MIN_VAL +1)) + MIN_VAL;

       nb_tentatives = 10;


       printf("\t \t \t \t \t \t ----------Jouons au juste prix ----------\n \n");
       printf("\t \t\t  Entrez un nombre entre 1 et 100 si vous tombez sur le juste prix c'est gagner ! \n");

       do
        {
            // Comparaisons du nombre de l'utilisateur avec le nombre mystère
             if (nb_tentatives <= MAX_TENTATIVES)
             {
                 printf("\t\t\tNombre de tentatives depassees ! \n \n ");
                 printf("\t\t\tLe nombre mystere etait : %d \n \n", nombre_mystere);
                 break;
             }
                 printf("Votre proposition : \n\n");
                 scanf("%d", &nombre_utilisateur);
                 nb_tentatives--;

             if ((nombre_utilisateur < 0) || (nombre_utilisateur > 100))
             {
                 printf("Veuillez entrer un nombre compris entre 1 et 100 \n\n");
                 continue;
             }
             if (nombre_mystere < nombre_utilisateur)
                {
                    printf("C'est moins ! tentatives restante : %d \n\n", nb_tentatives);
             }
             else if (nombre_mystere > nombre_utilisateur)
             {
                 printf("C'est plus ! tentatives restantes : %d \n \n", nb_tentatives);
             }
             else
            {
                 printf("\t\t\tFelicitations !!! mais y'avait rien a gagner dsl \n\n");
                 break;
            }
        }while (nombre_mystere != nombre_utilisateur);



        printf("\t\t\tSouhaitez vous rejouer ? [1 --> OUI / 2--> NON] \n\n");
        scanf("%d", &continuer);
        if (continuer == 2)
        {
            menu(choix, continue_choice, nombre_mystere, nombre_utilisateur, MIN_VAL, MAX_VAL, MAX_TENTATIVES, nb_tentatives, abandon, continuer);
        }



    }while(continuer < 2);

}








void regles(char continuer, int choix, int continue_choice, int nombre_mystere, int nombre_utilisateur, int MIN_VAL, int MAX_VAL, int MAX_TENTATIVES, int nb_tentatives, int abandon, int ocntinuer)
{

    continuer = '0';
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

    printf("\t\t\t Pour retourner au MENU apuyez sur une touche \n\n");

        while (getchar() == '\n')
        {

        }
        menu(choix, continue_choice, nombre_mystere, nombre_utilisateur, MIN_VAL, MAX_VAL, MAX_TENTATIVES, nb_tentatives, abandon, continuer);


}









int menu(int choix, int continue_choice, int continuer, int nombre_mystere, int nombre_utilisateur, int MIN_VAL, int MAX_VAL, int MAX_TENTATIVES, int nb_tentatives, int abandon)
{
    continue_choice = 1;
    printf("\t\t\t\t\t------------------------[LE JUSTE PRIX]-------------------------\n\n\n\n");
    printf("[MENU] : \n");
    printf("\t 1: Jouer AVEC nb tentatives limitees\n");
    printf("\t 2: Jouer SANS nb tentatives limitees\n");
    printf("\t 3: Regles du jeu\n");
    printf("\t 4: Quitter\n");
    scanf("%d", &choix);


    do
    {
      switch(choix)
        {
            case 1:
                jeu_limit(choix, continue_choice, nombre_mystere, nombre_utilisateur, MIN_VAL, MAX_VAL, MAX_TENTATIVES, continuer, abandon);
                break;

            case 2:
                jeu_sans_limit(choix, continue_choice, nombre_mystere, nombre_utilisateur, MIN_VAL, MAX_VAL, MAX_TENTATIVES, nb_tentatives, abandon, continuer);
                break;

            case 3:
                regles(continuer, choix, continue_choice, nombre_mystere, nombre_utilisateur, MIN_VAL, MAX_VAL, MAX_TENTATIVES, nb_tentatives, abandon, continuer);
                break;

            case 4:
                continue_choice = 1;
                break;

            default:
                return 0;

        }


    }
    while (continue_choice != 1);

     return 0;
    }



int main()
{
    int MIN_VAL = 1, MAX_VAL = 100;
    int MAX_TENTATIVES = 0;
    int continuer = 0;
    int continue_choice = 0;
    int nombre_mystere = 0, nombre_utilisateur = 0;
    int abandon = 0;
    int nb_tentatives = 0;
    int choix = 0;


        menu(choix, continue_choice, continuer, nombre_mystere, nombre_utilisateur, MIN_VAL, MAX_VAL, MAX_TENTATIVES, nb_tentatives, abandon);





    return 0;
}
