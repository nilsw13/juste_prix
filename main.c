#include <stdio.h>
#include <stdlib.h>

int main()
{
    int continue_choice = 0;
    int nombre_mystere = 0, nombre_utilisateur = 0;

    const int MIN_VAL = 1, MAX_VAL = 100;
    const int MAX_TENTATIVES = 0;







    // boucle du jeu

    do
    {
        // génération d'un nombre aléatoire
       srand(time(NULL));
       nombre_mystere = (rand()% (MAX_VAL-MIN_VAL +1)) + MIN_VAL;

       // Initialisation du nombre de tentatives autorisées
       int nb_tentatives = 10;




        // consignes
        printf("\t \t \t \t \t \t ----------Jouons au juste prix ----------\n \n");
        printf("\t \t\t  Entrez un nombre entre 1 et 100 si vous tombez sur le juste prix c'est gagner ! \n");
        printf("%d", nombre_mystere);
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
                 printf("Felicitations !!! Vous avez trouvé ! \n");
                 break;

            }

        }while (nombre_mystere != nombre_utilisateur);

        // Choix utilisateur de rejouer

        printf("Souhaitez vous rejouer ? 1 --> oui / 2 --> non \n");
        scanf("%d", &continue_choice);

    }
    while(continue_choice != 2);

    printf(" A bientot");



    return 0;
}


