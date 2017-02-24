#include <stdlib.h>
#include <string.h>
#include <individu.h>


/*
 * VARIABLE LOCALE
 */

unsigned long int individu_cpt = 0 ; 

/* 
 * FONCTIONS
 */

extern 
booleen_t individu_existe( individu_t * const individu )
{
  if( individu == NULL ) 
    return(FAUX) ;
  else
    return(VRAI) ; 
}

static 
err_t individu_detruire( individu_t ** individu ) 
{
    free((*individu)->nom);
    free((*individu)->prenom);
    free(*individu);
    *individu=NULL;
  return(OK) ; 
}

static
void individu_afficher( individu_t * const individu ) 
{

  printf( "{" ) ; 
  if(  individu_existe(individu) ) 
    {
      printf( "%s %s" , individu->prenom , individu->nom ) ;
    }
  printf( "}" ) ; 
}

extern 
individu_t * individu_creer( char * const prenom , char * const nom ) 
{
  individu_t * individu = NULL ;
    individu=malloc(sizeof(individu_t));
    (individu->nom)=malloc(sizeof(char)*20);
    (individu->prenom)=malloc(sizeof(char)*20);
    strcpy((individu->nom),nom);
    strcpy((individu->prenom),prenom);
   
    (individu->afficher)=individu_afficher;
   
    (individu->detruire)=individu_detruire;
    
    
    
  return( individu ) ;
}
