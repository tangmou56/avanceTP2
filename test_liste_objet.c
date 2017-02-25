#include <stdio.h>
#include <individu.h>
#include <fraction.h>
#include <mystring.h>
#include <liste_objet.h>

int
main()
{
    printf( "Debut du programme des test sur les objets de type liste_objet_t\n" ) ;
    
    
    err_t noerr = OK;
    individu_t * indiv_1 = individu_creer( "Roger" , "Waters" ) ;
    individu_t * indiv_2 = individu_creer( "David" , "Gilmour" ) ;
    fraction_t * frac_1 = fraction_creer( 3 , 5 ) ;
    fraction_t * frac_2 = fraction_creer( 9 , 13 ) ;
    string_t * str_1 = string_creer( "azertyuiop" ) ;
    string_t * str_2 = string_creer( "qsdfghjklm" ) ;
    string_t * str_3 = string_creer( "wxcvbn" ) ;
    /*creer liste1*/
    liste_t * liste1 = NULL ;
    liste1 = liste_creer(2) ;
    liste_elem_ecrire( liste1 , (objet_t *)indiv_1 , 0 ) ;
    liste_elem_ecrire( liste1 , (objet_t *)frac_1  , 1 ) ;
    /*(liste1->liste[0])->afficher(liste1->liste[0]);*/
    /*creer liste1*/
    /*creer liste2*/
    liste_t * liste2 = NULL ;
    liste2= malloc(sizeof(liste_t));
    liste2->liste = malloc( sizeof(objet_t *) * 2 );
    liste2->nb=2;
    liste2->liste[0] = (objet_t *)indiv_2;
    liste2->liste[1] = (objet_t *)frac_1;
    /*creer liste2*/
    liste_objet_t * liste_objet=NULL;
    
    liste_objet=liste_objet_creer(2);
    liste_objet_elem_ecrire(liste_objet,liste1,0);
    liste_objet_elem_ecrire(liste_objet,liste2,1);
    printf( "Test affichage liste \n" ) ;
    
    printf("%i",liste_objet->nb);
    liste_objet->liste_objet[0]->liste[0]->afficher(liste_objet->liste_objet[0]->liste[0]);
    liste_objet->liste_objet[1]->liste[0]->afficher(liste_objet->liste_objet[1]->liste[0]);
    
    /*liste_objet->liste_objet[0]->afficher(liste_objet->liste_objet[0],' ');
    liste_objet_afficher( liste_objet , ' ' ) ;
    printf( "\n");
    
    printf( "Test d'existance sur une liste_objet_t existant\n" ) ;
    ( liste_objet_existe(liste_objet) ? printf("-->OK\n") : printf ("-->KO\n") )  ;
    
    printf( "Test destruction liste\n" ) ;
    if( ( noerr = liste_objet_detruire( &liste_objet) ) )
    {
        printf("Sortie avec code erreur = %d\n" , noerr ) ;
        return(noerr) ;
    }
    
    printf( "Fin du programme des test sur les objets de type liste_t\n" ) ;
    
    printf( "Nombre de liste_t  = %lu\n" , liste_objet_cpt ) ;
    
    return(0) ; */

    }
