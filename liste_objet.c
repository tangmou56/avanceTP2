#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <liste_objet.h>
/*
 * VARIABLE LOCALE
 */

unsigned long int liste_objet_cpt = 0 ;

/*
 * Methodes d'acces
 */

/* Nombre d'elements */

extern
int liste_objet_nb_lire( liste_objet_t * const liste_objet )
{
    return(liste_objet->nb );
}

/* -- Acces individuel a un element */

extern
liste_t * liste_objet_elem_lire( liste_objet_t * const liste_objet  , const int ind )
{
    if( (ind < 0) || (ind > liste_objet_nb_lire(liste_objet)-1 ) )
    {
        fprintf( stderr , "liste_objet_elem_lire: mauvais indice d'element [%d] (devrait etre dans [%d..%d])\n",
                ind , 0 , liste_objet_nb_lire(liste_objet)-1 );
        return(NULL);
    }
    
    return( liste_objet->liste_objet[ind] ) ;
}

/*
 * Tests
 */

extern
booleen_t liste_objet_existe( liste_objet_t * const liste_objet )
{
    if( liste_objet == NULL )
    {
        return(FAUX) ;
    }
    else
    {
        return(VRAI) ;
    }
}

extern
booleen_t liste_objet_vide( liste_objet_t * const liste_objet )
{
    if( liste_objet->nb == 0 )
    {
        return(VRAI) ;
    }
    else
    {
        return(FAUX) ;
    }
}

/*
 * Methodes d'affectation
 */


/* -- Acces individuel a un element */
extern
err_t liste_objet_elem_ecrire( liste_objet_t * liste_objet ,
                        liste_t * const elem ,
                        const int ind )
{
    
#ifdef _DEBUG_
    if( (ind < 0) || (ind > liste_objet_nb_lire(liste_objet) ) )
    {
        fprintf( stderr , "liste_objet_elem_ecrire: mauvais indice d'element [%d] (devrait etre dans [%d..%d]\n",
                ind , 0 , liste_objet_nb_lire(liste_objet) );
        return(ERR_LISTE_OBJET_IND_ELEM);
    }
#endif
    liste_objet->liste_objet[ind] = elem ;
    
    return(OK) ;
}


/*
 * Creation d'une liste_objet
 */
extern
liste_objet_t * liste_objet_creer( const int nb )
{
    liste_objet_t * liste_objet ;
    
    if(( liste_objet= malloc(sizeof(liste_objet_t))) == NULL )
    {
        fprintf( stderr , "liste_objet_creer: debordement memoire lors de la creation d'une liste_objet\n");
        return((liste_objet_t *)NULL);
    }
    
    liste_objet->nb = nb ;
    liste_objet->liste_objet = (liste_t**)NULL ;
    if( nb > 0 )
    {
        if( ( liste_objet->liste_objet = malloc( sizeof(liste_t *) * nb ) ) == NULL )
        {
            fprintf( stderr , "liste_objet_creer: debordement memoire lors de la creation d'une liste_objet\n");
            free( liste_objet ) ;
            return((liste_objet_t *)NULL);
        }
    }
    
    liste_objet_cpt++ ;
    
    return(liste_objet);
}

/*
 * Destruction d'une liste_objet
 */

extern
err_t liste_objet_detruire( liste_objet_t ** liste_objet )
{
    int n=(*liste_objet)->nb;
    int i;
    for(i=0;i<n;i++){
        if(((*liste_objet)->liste_objet[i])!=NULL){
            (((*liste_objet)->liste_objet[i])->detruire)(&((*liste_objet)->liste_objet[i]));
            
        }
        
    }
    free((*liste_objet)->liste_objet);
    free(*liste_objet);
    *liste_objet=NULL;
    
    return(OK) ;
}


/*
 * Affichage d'une liste_objet sur la sortie standard
 * avec un caractere de separation entre
 * l'affichage de 2 elements
 */

extern
void liste_objet_afficher( liste_objet_t * const liste_objet ,
                    const char separateur )
{
    int n=liste_objet->nb;
    int i;
    for(i=0;i<n;i++){
        if((liste_objet->liste_objet[i])!=NULL){
            ((liste_objet->liste_objet[i])->afficher)(liste_objet->liste_objet[i], ' ' );
            printf("%c",separateur);
        }
    } 
    
}

