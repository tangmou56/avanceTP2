#ifndef _LISTE_OBJET_H_
#define _LISTE_OBJET_H_

extern unsigned long int liste_objet_cpt  ;


typedef struct liste_objet_s
{
    int nb ;		/* Nombre d'objets dans la liste  */
    liste_t ** liste ;	/* liste  des objets */
} liste_objet_t ;



/*
 * FONCTIONS
 */

/*!
 * \name Methodes d'acces
 * @{
 */

/*! Acces au nombre d'objets */
extern int liste_objet_nb_lire( liste_objet_t * const liste_objet );

/*! Acces a un objets de la liste_objet */
extern objet_t * liste_objet_elem_lire( liste_objet_t * const liste_objet , const int ind );

/*!
 * @}
 * \name Tests
 * @{
 */

/*! Teste si la liste_objet existe */
extern booleen_t liste_objet_existe( liste_objet_t * const liste_objet) ;

/*! Teste si la liste_objet est vide (aucun &eacute;l&eacute;ment dedans) */
extern booleen_t liste_objet_vide( liste_objet_t * const liste_objet) ;

/*!
 * @}
 * \name Methodes d'affectations
 * @{
 */

/*! Affectation d'un objet */
extern err_t liste_objet_elem_ecrire( liste_objet_t * liste_objet,
                               objet_t * const elem ,
                               const int ind ) ;

/*!
 * @}
 * \name Primitives
 * @{
 */

/*!
 * Creation d'une liste_objet
 */
extern liste_objet_t * liste_objet_creer( const int nb);

/*!
 * Destruction d'une liste_objet
 */

extern err_t liste_objet_detruire( liste_objet_t ** liste_objet );


/*!
 * \name Affichage
 * @{
 */

/*!
 * Affichage d'une liste_objet sur la sortie standard
 */

extern void liste_objet_afficher( liste_objet_t * const liste_objet ,
                           const char separateur );

/*!
 * @}
 */

/*! @} */


#endif
