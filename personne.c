#include <stdlib.h>
#include <string.h>
#include <personne.h>


/*
 * VARIABLE LOCALE
 */

unsigned long int personne_cpt = 0 ;

/*
 * FONCTIONS
 */

extern
booleen_t personne_existe( personne_t * const personne )
{
    if( personne == NULL )
        return(FAUX) ;
    else
        return(VRAI) ;
}

static
err_t personne_detruire( personne_t ** personne )
{
    personne->individu->detruire(&(personne->individu));
    free(*personne);
    *personne=NULL;
    return(OK) ;
}

static
void personne_afficher( personne_t * const personne )
{
    
    printf( "{" ) ;
    if(  personne_existe(personne) )
    {
        personne->individu->afficher(personne->individu);
        
    }
    printf( "}" ) ;
}

extern
personne_t * personne_creer( char * const prenom , char * const nom )
{
    personne_t * personne = NULL ;
    personne=malloc(sizeof(personne_t));
    personne->individu=individu_creer(prenom,nom);
    (personne->afficher)=personne_afficher;
    (personne->detruire)=personne_detruire;
    

    return( personne ) ;
}
