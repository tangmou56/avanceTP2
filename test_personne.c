#include <stdio.h>
#include <personne.h>

int
main()
{
    /* err_t noerr = OK; */
    personne_t * perso_1 = NULL ;
    
    printf( "Debut du programme des test sur les objets de type personne_t\n" ) ;
    
    printf( "Test d'existance sur un personne_t inexistant\n" ) ;
    ( personne_existe(perso_1) ? printf("-->KO\n") : printf ("-->OK\n") )  ;
    
    printf( "Test creation personne_t\n" ) ;
    perso_1 = personne_creer( "Roger" , "Waters" ) ;
    
    printf( "Test affichage perso_1\n" ) ;
    (perso_1->afficher)(perso_1);
    printf( "\n");
    
    printf( "Test d'existance sur un personne_t existant\n" ) ;
    ( personne_existe(perso_1) ? printf("-->OK\n") : printf ("-->KO\n") )  ;
    
    printf( "Test destruction perso_1\n" ) ;
    (perso_1->detruire)(&perso_1);
    
    printf( "Fin du programme des test sur les objets de type personne_t\n" ) ;
    
    printf( "Nombre de personne_t  = %lu\n" , personne_cpt ) ;
    
    return(0) ; 
}
