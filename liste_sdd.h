#ifndef _LISTE_SDD_H_
#define _LISTE_SDD_H_

#include <commun.h>
#include <objet.h>


#define LISTE_NULL NULL
#define LISTE_ID_NULL -1

typedef struct liste_s liste_t ;
typedef struct liste_s
{
  void(*afficher)(void *,char);
  err_t(*detruire)(void **);
  int (*liste_nb_lire)(struct liste_s * const);
  objet_t * (*liste_elem_lire)( liste_t * const, const int);
  booleen_t (*liste_vide)( liste_t * const);
  err_t (*liste_elem_ecrire)( liste_t *, objet_t * const,const int);
  int nb ;		/* Nombre d'objets dans la liste  */
  objet_t ** liste ;	/* liste  des objets */
} liste_t ;

#endif
