#include <stdio.h>
#include <stdlib.h>
#include "methodes.c"

VILLA* creer_Maillon_Villa( );

VILLA* chargementVilla(VILLA*l);

VILLA*insererFinVilla(VILLA*l,float prix,char Vl[100],char adr[100],char suprf[50],int nE,int nC,int nB,int nCham,int nToil);

void afficherTousLesVilla(VILLA*l);

void afficherVilla(VILLA*l);

void ecrireVILLA(VILLA*l);

void EnregistrerVILLA(VILLA*l,char*Nomfile);

VILLA* SuppressionVILLA(VILLA* l,VILLA A);

void ModifierVilla();

VILLA* removeDuplicatesVILLA(VILLA* head);

VILLA* removeDuplicatesVILLA_Ville_Version(VILLA* head);

MAISON* creerMaison( );

MAISON* chargementMaison(MAISON*l);

void EnregistrerMaison(MAISON*l,char*Nomfile);

MAISON* SuppressionMaison(MAISON* l,MAISON A);

MAISON*insererFinMaison( MAISON*l,float prix,char Vl[100],char adr[100],char suprf[50],int nE,int nC,int nB,int nCham,int nToil);

MAISON*RechercherMaison( MAISON*l,float prix,char Vl[100],char adr[100],char suprf[50],int nE,int nC,int nB,int nCham,int nToil);

void afficherTousLesMaison( MAISON*l);

void ecrire2( MAISON*l);

void Enregistrer1( MAISON*l,char*Nomfile);

MAISON* Suppression1(MAISON * l,MAISON A);

void ModifierMaison();

MAISON* removeDuplicatesMAISON(MAISON* head);

MAISON* removeDuplicatesMAISON_Ville_Version(MAISON* head);

APPARTEMENT* Creer();

APPARTEMENT*chargementAppartement(APPARTEMENT*l);

APPARTEMENT* removeDuplicatesAPPARTEMENT(APPARTEMENT* head);

APPARTEMENT* removeDuplicatesAPPARTEMENT_Ville_Version(APPARTEMENT* head);

void EnregistrerAppartement(APPARTEMENT*l,char*Nomfile);

void EnregistrerAppart(APPARTEMENT*l,char*Nomfile);

APPARTEMENT* SuppressionAppartement(APPARTEMENT* l,APPARTEMENT A);

APPARTEMENT *AjoutAppartementDebut(APPARTEMENT a,APPARTEMENT*tete);

void AfficherAppartement(APPARTEMENT*tete);

void AjoutAppartementFichier(APPARTEMENT*tete);

void ModifierAppartement();

TERRAIN* CreerTerain();

TERRAIN* chargementTerrain(TERRAIN*l);

void EnregistrerTerain(TERRAIN*l,char*Nomfile);

TERRAIN* SuppressionTerain(TERRAIN* l,TERRAIN A);

TERRAIN*insererFinTerrain(TERRAIN*l,TERRAIN A);

TERRAIN* removeDuplicatesTERRAIN(TERRAIN* head);

TERRAIN* removeDuplicatesTERRAIN_Ville_Version(TERRAIN* head);

TERRAIN *AjoutTerainDebut(TERRAIN a,TERRAIN *tete);

void AfficherTerain(TERRAIN *tete);

void AjoutTerainFichier(TERRAIN *tete);

void ModifierTerrain();

void afficherAPPARTEMENT(APPARTEMENT*l);

void afficherMAISON(MAISON*l);

void afficherTERRAIN(TERRAIN*l);

void afficherVILLA(VILLA*l);

APPARTEMENT* CreerAPPARTEMENT2();

APPARTEMENT* chargementAPPARTEMENT_Ver_Sup(APPARTEMENT*l);

void SAVETERRAIN(TERRAIN*l,char*Nomfile);

void SAVEME(TERRAIN*l,char*Nomfile);

void AffichermaisonBis(MAISON*tete);
