#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> // Include string.h for string manipulation functions

int nbrTache = 0; // Initialize k to zero

struct tacheList
{
    int id;
    int status;
    int jour;
    int annee;
    int mois;
    char titre[100];
    char description[500];
};
struct tacheList taches[100]; // Define the global array with a specific size
struct tacheList nvtache;

void ajouter()
{

    nvtache.id = nbrTache + 1;

    printf("\nidentifiant:%d", nvtache.id); //identifiant
    printf("\nTitre:");                  //titre
    scanf(" %[^\n]s", nvtache.titre);
    printf("description:"); //description
    scanf(" %[^\n]s", nvtache.description);
    printf("deadline:");
    printf("\njour: ");
    scanf("%d",&nvtache.jour);
    printf("mois: ");
    scanf("%d",&nvtache.mois);
    printf("annee: ");
    scanf("%d",&nvtache.annee);
    printf(">>>> %d/%d/%d \n",nvtache.jour,nvtache.mois,nvtache.annee);

    printf("1.TODO        2.DOING        3.DONE");
    printf("\nstatus:");
    scanf("%d", &nvtache.status);
    taches[nbrTache] = nvtache;
    nbrTache++;
    printf("Task added successfully.\n");
printf("---------------------------------------");
}




void trierAlphabetique()
{
    // Function to sort tasks alphabetically by title
    int i, j;
    struct tacheList temp;

    for (i = 0; i < nbrTache - 1; i++)
    {
        for (j = 0; j < nbrTache - i - 1; j++)
        {
            if (strcmp(taches[j].titre, taches[j + 1].titre) > 0)
            {
                temp = taches[j];
                taches[j] = taches[j + 1];
                taches[j + 1] = temp;
            }
        }
    }
}

                                              //Afficher une tache

void affichagelist()
{
    printf("\nListe de toutes les taches:\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < nbrTache; i++)
    {
        printf("<<<<<<<<tache numero:%d>>>>>>>>\n", i + 1);
        printf("\nidentifiant:%d", taches[i].id); //identifiant
        printf("\nTitre:%s", taches[i].titre);   //titre
        printf("\ndescription:%s", taches[i].description); //description
        printf("\ndeadline:");
        printf("\njour:%d ",taches[i].jour);
        printf("\nmois:%d ",taches[i].mois);
        printf("\nannee:%d ",taches[i].annee);
        printf("\n1.TODO        2.DOING        3.DONE");
        switch (taches[i].status)
        {
        case 1:
            printf("\nstatut :TODO");
            break;
        case 2:
            printf("\nstatut :DOING");
            break;
        case 3:
            printf("\nstatut :DONE");
            break;
        default:
            printf("\nStatut : Inconnu");
            break;
        }
        printf("\n--------------------------------------\n");
    }


}



void modifier(){
    int n;
    int i;
    int idmodifier;
    printf("enter l'identifiant qui vous voulez modifier: ");
    scanf("%d",&idmodifier);
    for(i=0; i<nbrTache; i++)
    {
        if(taches[i].id == idmodifier)
        {

            printf(" -->1.description\n");
            printf(" -->2.status\n");
            printf(" -->3.deadline\n");
            printf("votre choix est: ");
            scanf("%d",&n);
            switch(n){
            case 1:
                printf("modifier la discreption:");
                scanf(" %[^\n]s",&taches[i].description);
                break;
            case 2:
                printf("modifier les status:(1.TODO     2.DOING     3.DONE) ");
                scanf("%d", &taches[i].status);
                break;
            case 3:
                printf("modifier les deadlines:");
                printf("\njour:");
                scanf("%d",&taches[i].jour);
                printf("mois:");
                scanf("%d",&taches[i].mois);
                printf("annee:");
                scanf("%d",&taches[i].annee);
                break;

            }
        }

    }

}


                                     //Supprimer une tache


void removelist() {

    int i;
    int idsupprimer;

    printf("Choisissez l'identifiant que vous voulez supprimer: ");
    scanf("%d", &idsupprimer);

    for (i = 0; i < nbrTache; i++) {

        if (taches[i].id == idsupprimer) {


            for (int j = i; j < nbrTache - 1; j++) {
                taches[j] = taches[j + 1];
            }
            nbrTache--;
            printf("L'identifiant %d a ete supprimé.\n", idsupprimer);
            break;
        }
    }

    if (idsupprimer>taches[i].id ){
        printf("L'identifiant %d n'a pas ete trouvé dans la liste.\n", idsupprimer);
    }
}



                                      // Rechercher les Tâches
void Rechercherlist() {
    int recherche1;
    char recherche2[100]; // Use an array to store the searched title
    int i;

    printf("Choisissez l'identifiant ou le titre que vous voulez chercher (1. l'identifiant 2. Titre): ");
    scanf("%d", &recherche1);

    if (recherche1 == 1) {
        printf("1. l'identifiant: ");
        scanf("%d", &recherche1);

        for (i = 0; i < nbrTache; i++) {
            if (recherche1 == taches[i].id) {
                // Print the task details here
                printf("<<<<<<<<tache numero:%d>>>>>>>>\n", i + 1);
                printf("\nidentifiant:%d", taches[i].id); //identifiant
                printf("\nTitre:%s", taches[i].titre);   //titre
                printf("\ndescription:%s", taches[i].description); //description
                printf("\ndeadline:");
                printf("\njour:%d ", taches[i].jour);
                printf("\nmois:%d ", taches[i].mois);
                printf("\nannee:%d ", taches[i].annee);
                printf("\n1.TODO        2.DOING        3.DONE");
                switch (taches[i].status) {
                    case 1:
                        printf("\nstatut :TODO");
                        break;
                    case 2:
                        printf("\nstatut :DOING");
                        break;
                    case 3:
                        printf("\nstatut :DONE");
                        break;
                    default:
                        printf("\nStatut : Inconnu");
                        break;
                }
                printf("\n--------------------------------------\n");
            }
        }
    } else if (recherche1 == 2) {
        printf("2. Titre: ");
        scanf(" %[^\n]s", recherche2);

        for (i = 0; i < nbrTache; i++) {
            if (strcmp(recherche2, taches[i].titre) == 0) {
                // Print the task details here
                printf("<<<<<<<<tache numero:%d>>>>>>>>\n", i + 1);
                printf("\nidentifiant:%d", taches[i].id); //identifiant
                printf("\nTitre:%s", taches[i].titre);   //titre
                printf("\ndescription:%s", taches[i].description); //description
                printf("\ndeadline:");
                printf("\njour:%d ", taches[i].jour);
                printf("\nmois:%d ", taches[i].mois);
                printf("\nannee:%d ", taches[i].annee);
                printf("\n1.TODO        2.DOING        3.DONE");
                switch (taches[i].status) {
                    case 1:
                        printf("\nstatut :TODO");
                        break;
                    case 2:
                        printf("\nstatut :DOING");
                        break;
                    case 3:
                        printf("\nstatut :DONE");
                        break;
                    default:
                        printf("\nStatut : Inconnu");
                        break;
                }
                printf("\n--------------------------------------\n");
            }
        }
    }
}



void calculateTaskStats(int completed, int incomplete)
{
    completed = 0;
    incomplete = 0;

    for (int i = 0; i < nbrTache; i++)
    {
        if (taches[i].status == 3) // Assuming status 3 represents "DONE"
        {
            (completed)++;
        }
        else
        {
            (incomplete)++;
        }
    }
}

// Function to display statistics
void displayStatistics()
{
    int totalTasks = nbrTache;
    int completedTasks = 0, incompleteTasks = 0;

    for (int i = 0; i < nbrTache; i++)
    {
        if (taches[i].status == 3) // Assuming status 3 represents "DONE"
        {
            completedTasks++;
        }
        else
        {
            incompleteTasks++;
        }
    }

    printf("\nTotal number of tasks: %d", totalTasks);
    printf("\nNumber of completed tasks: %d", completedTasks);
    printf("\nNumber of incomplete tasks: %d", incompleteTasks);
    printf("\n");

    // Add code to display the number of days remaining until the deadline for each task.
    // You can calculate the days remaining using the current date and the task's deadline.
    // Displaying days remaining requires additional code for date manipulation.
}














int main()
{
    int choix;

    puts("     \n/============================================================\\\n");
    puts("                              MENU                             ");
    puts("     \n\\============================================================/\n");

    puts("------------------>1. Ajouter une nouvelle tache");
    puts("------------------>2. Ajouter plusieurs nouvelles taches");
    puts("------------------>3. Afficher la liste de toutes les tâches"); // Added option for sorting
    puts("------------------>4. Modifier une tache:");
    puts("------------------>5. Supprimer une tache par identifiant");
    puts("------------------>6. Statistiques");
    puts("------------------>7. Rechercher les Taches");

    printf("-->> ");
    scanf("%d", &choix);

    while (true)
    {
        switch (choix)
        {
            int n;
        case 1:
            ajouter();
            main();
            return 0;
            break;
        case 2:
            printf("     combien de taches souhaitez-vous ajouter: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                ajouter();
            }
            main();
            return 0;
            break;
        case 3:
            printf("    3. Afficher la liste de toutes les taches:\n");
            trierAlphabetique(); // Call the sorting function
            affichagelist();
            main();
            return 0;
            break;
        case 4:
            printf("    4. Modifier une tache:\n");
            modifier();
            main();
            return 0;
            break;
        case 5:
            printf("    5. Supprimer une tache par identifiant:\n");
            removelist();
            main();
            return 0;
            break;
        case 6:
            printf("    6. Statistiques:\n");
            displayStatistics();
            main();
            return 0;
            break;
        case 7:
            printf("    7. Rechercher les Taches:\n");
            Rechercherlist();
             main();
            return 0;
            break;
        default:
            printf("Choix invalide. Veuillez reessayer.\n");
            main();
            return 0;
        }
    }

    return 0;
}
