#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"
int main()
	{
		char * Login=NULL;
		char * Password=NULL;
	
		Login=malloc(sizeof(char));
		Password=malloc(sizeof(char));
	
		int choix ;
	    APPARTEMENT  *liste = NULL;
	    APPARTEMENT b;
		goto Here;
	
	    Here: ;
	    TERRAIN *tete = NULL;
	    TERRAIN c;
	    int rep=1;
	    VILLA*l =NULL;
	
	    char*Vill,*superfici,*adress;
	    Vill = malloc(sizeof(char));
	    adress=malloc(sizeof(char));
	    superfici = malloc(sizeof(char));
	    float pri=0;
	    int nbreChambre=0,nbreBain=0,nbreToilette=0,nbreCui=0,nbreEtag=0;
	    VILLA A;
		MAISON*I=NULL;
	    MAISON B;
                           //*************************************************************	
	
	   int Menu;
			puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			puts("                                           choisissez une options");
		    puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			puts("************************************************************************************************************************");
			puts("connecter autant que administrateur                     :\t<<<<<< tapez 1>>>>>>");
			puts("connecter autant que client                             :\t<<<<<< tapez 2>>>>>>");
			puts("sortir du programme                                     :\t<<<<<< tapez 3>>>>>>");
			puts("************************************************************************************************************************");
			printf("                             =========>>>");
			scanf("%d",&Menu);
	
        	puts("");
	
	    switch(Menu)
			 {
			     case 1: goto affichageAdmin;break;
				 case 2: goto affichageClient;break;
			     case 3: exit(0);
				         break;
						 default:
						 	if(Menu>3);
						 		puts("*************************************************************************************************************");
						 		puts("SVP Ressayer autre option(1..3)");
						 		puts("*************************************************************************************************************");
			
			
			
			
				 }
			
		    affichageClient:
				 {
				        int choice;
			
			    do
				 
				 {
					    char ville[50];
					    float prix_min;
						float prix_max;
			
					    VILLA*l;
					    l=chargementVilla(l);
					    l=removeDuplicatesVILLA(l);
			
					
					    APPARTEMENT*m =NULL;
					    m=chargementAppartement(m);
					    m=removeDuplicatesAPPARTEMENT(m);
			
						MAISON*n =NULL;
					    n=chargementMaison(n);
					    n=removeDuplicatesMAISON(n);
			
			
						TERRAIN*o =NULL;
					    o=chargementTerrain(o);
					    o=removeDuplicatesTERRAIN(o);
				
					   char categorie[20];
					   puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
					   puts("                                Bienvenue dans notre Agence Immobiliere **RIMY**");
					   puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
						puts("************************************************************************************************************************");
						puts("pour la recherche par categorie                         :\t<<<<<< tapez 1>>>>>>");
						puts("pour la recherche par prix                              :\t<<<<<< tapez 2>>>>>>");
						puts("pour la recherche par ville                             :\t<<<<<< tapez 3>>>>>>");
						puts("pour la reherche personalisee                           :\t<<<<<< tapez 4>>>>>>");
						puts("pour sortir tapez                                       :\t<<<<<< tapez 5>>>>>>");
						puts("************************************************************************************************************************");
						printf("                             =========>>>");
						scanf("%d",&choice);
			            printf("\n");
				switch(choice)
				
						{
			
			         	//recherche par categorie
			        	case 1:
			    	    puts("************************************************************************************************************************");
			            puts("Entrez une de ces categories:\n");
						puts("pour villa                                              :\t<<<<<< tapez villa       >>>>>>");
						puts("pour appartement                                        :\t<<<<<< tapez appartement >>>>>>");
						puts("pour maison                                             :\t<<<<<< tapez maison      >>>>>>");
						puts("pour terrain                                            :\t<<<<<< tapez terrain     >>>>>>");
						printf("                                           =========>>>");
						
				    	scanf("%s",categorie);
				    	
				    	if(strcmp(categorie,"villa")==0)
						
							{
				                l=removeDuplicatesVILLA(l);
								afficherVILLA(l);
							}
			
						else if(strcmp(categorie,"appartement")==0)
							{
				                    m=removeDuplicatesAPPARTEMENT(m);
					   				afficherAPPARTEMENT(m);
							}
				
						else if (strcmp(categorie,"maison")==0)
							{
				                n=removeDuplicatesMAISON(n);
					 		    afficherMAISON(n);
							}
			
						else if(strcmp(categorie,"terrain")==0)
							{
								o=removeDuplicatesTERRAIN(o);
					   			afficherTERRAIN(o);
							}
						else
							{
						     	printf("\nchoix invalide\n");
							}
				    	break;
			
			
			
			
			
				    //recherche par prix
				    case 2:
					puts("*******************Le cout minimum de nos immeubles est generalement a partir de 250000.000DHS Pour Votre Visite**************************");
					printf("entrer le prix min:                         =========>>>");
					scanf("%f",&prix_min);
					printf("entrer le prix max:                         =========>>>");
					scanf("%f",&prix_max);
			
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Liste des Villas~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
						printf("\n");
						//l=removeDuplicatesVILLA(l);
						 while(l!=NULL)
							 
							  {
								 if(l->prix >= prix_min && l->prix<= prix_max)
								     {
										printf("prix:%f\nadresse:%s\nville:%s\nsuperficie:%s\nNombre Etages:%d\nNombre Cuisines:%d\nNombres Bains:%d\nNombres Chambres:%d\nNombres Toilettes:%d" ,l->prix,l->adresse,l->Ville,l->superficie,l->nbreEtage,l->nbreCuis,l->nbreBains,l->nbreChambres,l->nbreToilettes);
										printf("\n                   +++++++++++++++++++++                    \n");
									 }
								l=l->suiv;
							 }
				
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Liste des Appartements~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
						printf("\n");
						while(m!=NULL)
							{
								if(m->prix >= prix_min && m->prix<= prix_max)
									{
										printf("prix:%f\nadresse:%s\nVille:%s\nsuperficie:%s\nEtage:%d\nNombre Cuisines:%d\nNombre Bains:%d\nNombre Chambres:%d\nNombre Toilettes:%d" ,m->prix,m->adresse,m->Ville,m->superficie,m->nbreEtage,m->nbreCuis,m->nbreBains,m->nbreChambres,m->nbreToilettes);
										printf("\n                   +++++++++++++++++++++                    \n");
									}
								m=m->suiv;
							}
			
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Liste des Maisons~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
						printf("\n");
						while(n!=NULL)
							{
								
								if(n->prix >= prix_min && n->prix<= prix_max)
									{
									    printf("prix:%f\nadresse:%s\nVille:%s\nSuperficie:%s\nNombre Etages:%d\nNombre Cuisines:%d\nNombre Bains:%d\nNombre Chambres:%d\nNombre Toilettes:%d" ,n->prix,n->adresse,n->Ville,n->superficie,n->nbreEtage,n->nbreCuis,n->nbreBains,n->nbreChambres,n->nbreToilettes);
										printf("\n                   +++++++++++++++++++++                    \n");
									}
								n=n->suiv;
				
							}
			
			
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Liste des Terrains~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
						printf("\n");
						while(o!=NULL)
							{
								if(o->prix >= prix_min && o->prix<= prix_max)
									{
										printf("prix:%f\nadresse:%s\nVille:%s\nSuperficie:%s\ntype:%s",o->prix,o->adresse,o->Ville,o->superficie,o->type);
										printf("\n                   +++++++++++++++++++++                    \n");
									}
								o=o->suiv;
							}
						break ;
			
			
			
			
			
					//recherche par ville
					case 3:
					puts("************************************************************************************************************************");
					puts("Voici les Villes ou se trouvent nos Villas\n");
					puts("\n-------------------------------------------------------------------------------------------------------------------------\n");
					VILLA*W=NULL;
					int count=1;
					W=chargementVilla(W);
					W=removeDuplicatesVILLA_Ville_Version(W);
					
					while(W->suiv!=NULL)
						{
								printf("Ville N°%d:%s",count,W->Ville);
								printf("\n");
								W=W->suiv;
								count++;
						}
				puts("\n-------------------------------------------------------------------------------------------------------------------------");
				puts("\nVoici les Villes ou se trouvent nos appartements\n");
				puts("-------------------------------------------------------------------------------------------------------------------------\n");
				APPARTEMENT*X=NULL;
				int count1=1;
				X=chargementAppartement(X);
				X=removeDuplicatesAPPARTEMENT_Ville_Version(X);
				
				while(X->suiv!=NULL)
						{
							printf("Ville N°%d:%s",count1,X->Ville);
							printf("\n");
							X=X->suiv;
							count1++;
						}
				puts("\n-------------------------------------------------------------------------------------------------------------------------");
				puts("\nVoici les Villes ou se trouvent nos maisons\n");
				puts("-------------------------------------------------------------------------------------------------------------------------\n");
				MAISON*C=NULL;
				int count2=1;
				C=chargementMaison(C);
				C=removeDuplicatesMAISON_Ville_Version(C);
				
				while(C->suiv!=NULL)
						{
							printf("Ville N°%d:%s",count2,C->Ville);
							printf("\n");
							C=C->suiv;
							count2++;
						}
				puts("\nVoici les Villes ou se trouvent nos terrains\n");
				puts("-------------------------------------------------------------------------------------------------------------------------\n");
				TERRAIN*D=NULL;
				int count3=1;
				D=chargementTerrain(D);
				D=removeDuplicatesTERRAIN_Ville_Version(D);
				
				while(D->suiv!=NULL)
				       {
							printf("Ville N°%d:%s",count3,D->Ville);
							printf("\n");
							D=D->suiv;
							count3++;
				       }
				    	
				puts("\n-------------------------------------------------------------------------------------------------------------------------\n");
				printf("\nEntrer la Ville:                         =========>>>");
				scanf("%s",ville);
			
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Liste des Villas~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
						printf("\n");
						while(l!=NULL)
							{
				
								 if(strcmp(l->Ville,ville)==0)
									 {
										printf("prix:%f\nadresse:%s\nville:%s\nsuperficie:%s\nNombre Etages:%d\nNombre Cuisines:%d\nNombres Bains:%d\nNombres Chambres:%d\nNombres Toilettes:%d" ,l->prix,l->adresse,l->Ville,l->superficie,l->nbreEtage,l->nbreCuis,l->nbreBains,l->nbreChambres,l->nbreToilettes);
										printf("\n                   +++++++++++++++++++++                    \n");
									 }
								l=l->suiv;
							}
			
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Liste des Appartements~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
						printf("\n");
						while(m!=NULL)
							{
								if(strcmp(m->Ville,ville)==0)
									{
										printf("prix:%f\nadresse:%s\nVille:%s\nsuperficie:%s\nEtage:%d\nNombre Cuisines:%d\nNombre Bains:%d\nNombre Chambres:%d\nNombre Toilettes:%d" ,m->prix,m->adresse,m->Ville,m->superficie,m->nbreEtage,m->nbreCuis,m->nbreBains,m->nbreChambres,m->nbreToilettes);
										printf("\n                   +++++++++++++++++++++                    \n");
									}
								m=m->suiv;
							}
			
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Liste des Maisons~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
						printf("\n");
						while(n!=NULL)
							{
								if(strcmp(n->Ville,ville)==0)
									{
									    printf("prix:%f\nadresse:%s\nVille:%s\nSuperficie:%s\nNombre Etages:%d\nNombre Cuisines:%d\nNombre Bains:%d\nNombre Chambres:%d\nNombre Toilettes:%d" ,n->prix,n->adresse,n->Ville,n->superficie,n->nbreEtage,n->nbreCuis,n->nbreBains,n->nbreChambres,n->nbreToilettes);
										printf("\n                   +++++++++++++++++++++                    \n");
									}
								n=n->suiv;
				
							}
			
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Liste des Terrains~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
						printf("\n");
			
						while(o!=NULL)
						{
							if(strcmp(o->Ville,ville)==0)
							{
						    	printf("prix:%f\nadresse:%s\nVille:%s\nSuperficie:%s\ntype:%s",o->prix,o->adresse,o->Ville,o->superficie,o->type);
								printf("\n                   +++++++++++++++++++++                    \n");
							}
							o=o->suiv;
						}
						break ;
			
			
			
			
					//recherche personnalisee
					case 4:
					puts("************************************************************************************************************************");
					puts("Voici les Villes ou se trouvent nos Villas\n");
					puts("\n-------------------------------------------------------------------------------------------------------------------------\n");
					VILLA*WW=NULL;
					int countt=1;
					WW=chargementVilla(WW);
					WW=removeDuplicatesVILLA_Ville_Version(WW);
					
					while(WW->suiv!=NULL)
							{
								printf("Ville N°%d:%s",countt,WW->Ville);
								printf("\n");
								WW=WW->suiv;
								countt++;
							}
					puts("\n-------------------------------------------------------------------------------------------------------------------------");
					puts("\nVoici les Villes ou se trouvent nos appartements\n");
					puts("-------------------------------------------------------------------------------------------------------------------------\n");
					APPARTEMENT*XX=NULL;
					int countt1=1;
					XX=chargementAppartement(XX);
					XX=removeDuplicatesAPPARTEMENT_Ville_Version(XX);
					
						while(XX->suiv!=NULL)
							{
								printf("Ville N°%d:%s",countt1,XX->Ville);
								printf("\n");
								XX=XX->suiv;
								countt1++;
							}
					puts("\n-------------------------------------------------------------------------------------------------------------------------");
					puts("\nVoici les Villes ou se trouvent nos maisons\n");
					puts("-------------------------------------------------------------------------------------------------------------------------\n");
					MAISON*CC=NULL;
					int countt2=1;
					CC=chargementMaison(CC);
					CC=removeDuplicatesMAISON_Ville_Version(CC);
					
					while(CC->suiv!=NULL)
						{
							printf("Ville N°%d:%s",countt2,CC->Ville);
							printf("\n");
							CC=CC->suiv;
							countt2++;
						}
					puts("\nVoici les Villes ou se trouvent nos terrains\n");
					puts("-------------------------------------------------------------------------------------------------------------------------\n");
					TERRAIN*DD=NULL;
					int countt3=1;
					DD=chargementTerrain(DD);
					DD=removeDuplicatesTERRAIN_Ville_Version(DD);
					
						while(DD->suiv!=NULL)
						
							{
								printf("Ville N°%d:%s",countt3,DD->Ville);
								printf("\n");
								DD=DD->suiv;
								countt3++;
							}
					puts("\n-------------------------------------------------------------------------------------------------------------------------\n");
					printf("entrer la ville                                         :                =========>>>");
					scanf("%s",ville);
					puts("\n*******************Le cout minimum de nos immeubles est generalement a partir de 250000.000DHS Pour Votre Visite**************************\n");
					printf("entrer le prix min                                      :                =========>>>");
					scanf("%f",&prix_min);
					printf("entrer le prix max                                      :                =========>>>");
					scanf("%f",&prix_max);
					puts("\nEntrez une de ces categories                            :");
					printf("\n");
					puts("pour villa                                              :  <<<<<< tapez villa       >>>>>>");
					puts("pour appartement                                        :  <<<<<< tapez appartement >>>>>>");
					puts("pour maison                                             :  <<<<<< tapez maison      >>>>>>");
					puts("pour terrain                                            :  <<<<<< tapez terrain     >>>>>>");
					printf("                                             =========>>>");
					scanf("%s",categorie);
			
				    	if(strcmp(categorie,"villa")==0)
						
						{
							printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Liste des Villas~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
							printf("\n");
							while(l!=NULL)
							
								{
												 if(strcmp(l->Ville,ville )==0 && l->prix >= prix_min && l->prix<= prix_max)
													 {
														printf("prix:%f\nadresse:%s\nville:%s\nsuperficie:%s\nNombre Etages:%d\nNombre Cuisines:%d\nNombres Bains:%d\nNombres Chambres:%d\nNombres Toilettes:%d" ,l->prix,l->adresse,l->Ville,l->superficie,l->nbreEtage,l->nbreCuis,l->nbreBains,l->nbreChambres,l->nbreToilettes);
														printf("\n                   +++++++++++++++++++++                    \n");
								                   	 }
												l=l->suiv;
								}
						}
			
						else if(strcmp(categorie,"appartement")==0)
						
						{
		                	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Liste des Appartements~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			
							printf("\n");
								while(m!=NULL)
								
								{
									 if(strcmp(m->Ville,ville )==0 && m->prix >= prix_min && m->prix<= prix_max)
										 {
											printf("prix:%f\nadresse:%s\nVille:%s\nsuperficie:%s\nEtage:%d\nNombre Cuisines:%d\nNombre Bains:%d\nNombre Chambres:%d\nNombre Toilettes:%d" ,m->prix,m->adresse,m->Ville,m->superficie,m->nbreEtage,m->nbreCuis,m->nbreBains,m->nbreChambres,m->nbreToilettes);
											printf("\n                   +++++++++++++++++++++                    \n");
										 }
							            	m=m->suiv;
							   }
						}
			
						else if (strcmp(categorie,"maison")==0)
						
						{
		                	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Liste des Maisons~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
							printf("\n");
							
							while(n!=NULL)
								{
									
								 if(strcmp(n->Ville,ville )==0 && n->prix >= prix_min && n->prix<= prix_max)
									 
									 {
								    	printf("prix:%f\nadresse:%s\nVille:%s\nSuperficie:%s\nNombre Etages:%d\nNombre Cuisines:%d\nNombre Bains:%d\nNombre Chambres:%d\nNombre Toilettes:%d" ,n->prix,n->adresse,n->Ville,n->superficie,n->nbreEtage,n->nbreCuis,n->nbreBains,n->nbreChambres,n->nbreToilettes);
										printf("\n                   +++++++++++++++++++++                    \n");
									 }
								        n=n->suiv;
							    }
						}
			
						else if(strcmp(categorie,"terrain")==0)
						
							{
					                 printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Liste des Terrains~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
									printf("\n");
									
									while(o!=NULL)
									{
									  if(strcmp(o->Ville,ville )==0 && o->prix >= prix_min && o->prix<= prix_max)
										 {
										    printf("prix:%f\nadresse:%s\nVille:%s\nSuperficie:%s\ntype:%s",o->prix,o->adresse,o->Ville,o->superficie,o->type);
											printf("\n                   +++++++++++++++++++++                    \n");
										 }
									     	o=o->suiv;
									}
								}
						else printf("choix invalide\n");
				    	break;
			
					case 5:
						exit(-1);
			
				    default :
				    	printf("veuillez entrez un choix valide");
				    	break;
			
				}
				}while(choice!=5);
			
				           }
		  affichageAdmin:
		      {
		  do
			  {
				  printf("Entrer Votre Login       :\t");
				  scanf("%s",Login);
				  printf("\n");
				  getchar();
				  printf("Entrer Votre Mot de Passe:\t");
				  scanf("%s",Password);
				  getchar();
		
		      }while( strcmp(Login,"admin")!=0 || strcmp(Password,"admin")!=0 );
		  
		     do{
				    puts("******************************************connexion avec succes******************************************************************************");
				    puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
					puts("                                           remplissage");
					puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
					puts("inserer une appartements  dans la liste        :\t<<<<<< tapez 1>>>>>>");
					puts("inserer un terain dans la liste                :\t<<<<<< tapez 2>>>>>>");
					puts("inserer une villa  dans la liste               :\t<<<<<< tapez 3>>>>>>");
					puts("inserer une maison dans la liste               :\t<<<<<< tapez 4>>>>>>");
					puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
					puts("                                           modification");
					puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
					puts("modifier une appartement dans la liste         :\t<<<<<< tapez 5>>>>>>");
					puts("modifier un terain dans la liste               :\t<<<<<< tapez 6>>>>>>");
					puts("modifier une villa dans la liste               :\t<<<<<< tapez 7>>>>>>");
					puts("modifier une maison dans la liste              :\t<<<<<< tapez 8>>>>>>");
					puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
					puts("                                           suppression");
					puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
					puts("supprimer une appartement dans la liste        :\t<<<<<< tapez 9>>>>>>>");
				    puts("supprimer une terrain dans la liste            :\t<<<<<< tapez 10>>>>>>");
				   	puts("supprimer un villa dans la liste               :\t<<<<<< tapez 11>>>>>>");
					puts("supprimer une maison dans la liste             :\t<<<<<< tapez 12>>>>>>");
					puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
					puts("                                           aucun choix");
					puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
					puts("sortir du programme                            :\t<<<<<< tapez 13>>>>>>");
					puts("************************************************************************************************************************");
					printf("                             =========>>>");
					    scanf("%d",&choix);
	    switch(choix)
	        {
	
		         case 1:
		         liste =chargementAPPARTEMENT_Ver_Sup(liste);
				 liste=removeDuplicatesAPPARTEMENT(liste);
		         AfficherAppartement(liste);
				 AjoutAppartementFichier(liste);
	
	             rep=1;
	               while(rep==1)
			         {
			
						puts("************************************************************************************************************************");
						puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			            puts("                                           remplir les informations d'appartement");
			            puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
			            printf("tapez le nom de la ville                         \t: ==> ");
			            scanf("%s",b.Ville);
			            printf("tapez le nom du cartier                          \t: ==> ");
			            scanf("%s",b.adresse);
			            printf("tapez le nombre de chambres                      \t: ==> ");
			            scanf("%d",&b.nbreChambres);
			            printf("tapez le nombre de cuisines                      \t: ==> ");
			            scanf("%d",&b.nbreCuis);
			            printf("tapez le nombre de toilletes                     \t: ==> ");
			            scanf("%d",&b.nbreToilettes);
			            printf("tapez le nombre de  bains                        \t: ==> ");
			            scanf("%d",&b.nbreBains);
			            printf("tapez le numero d'etage                          \t: ==> ");
			            scanf("%d",&b.nbreEtage);
			            getchar();
			            printf("tapez la superficie                              \t: ==> ");
			            scanf("%s",b.superficie);
			            printf("tapez le prix                                    \t: ==> ");
			            scanf("%f",&b.prix);
			            printf("\n");
			           	puts("*********************************************************************************************************************");
			            liste = AjoutAppartementDebut(b,liste);
			            printf(" -voulez vous  remplir les imformation d'une autre appartement?\n si oui tapez 1, si non tapez 0 =========>>>");
						   scanf("%d",&rep);
			               printf("                               \n");
			         }
			     liste=removeDuplicatesAPPARTEMENT(liste);
	             AfficherAppartement(liste);
	             AjoutAppartementFichier(liste);
	             AfficherAppartement(liste);
	             break;
             	 case 2:
 	
	             tete=chargementTerrain(tete);
				 tete=removeDuplicatesTERRAIN(tete);
				 afficherTERRAIN(tete);
	
	
					puts("************************************************************************************************************************");
					puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		            puts("                                           remplir les informations du terrain");
		            puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	
	               printf("tapez le nom de la ville                         \t: ==> ");
				   scanf("%s",c.Ville);
				   getchar();
	               printf("tapez le nom du cartier                          \t: ==> ");
	               scanf("%s",c.adresse);
				   getchar();
	               printf("tapez la superficie                              \t: ==> ");
	               scanf("%s",c.superficie);
				   getchar();
	               printf("tapez le prix                                    \t: ==> ");
	               scanf("%f",&c.prix);
				   getchar();
	               printf("tapez  Type du Terrain                           \t: ==> ");
	               scanf("%s",c.type);
				   getchar();
				   tete=insererFinTerrain(tete,c);
				   tete=removeDuplicatesTERRAIN(tete);
				   afficherTERRAIN(tete);
					 EnregistrerTerain(tete,"char.txt");
					 remove("terrain.txt");
					 rename("char.txt","terrain.txt");
					 printf("reussie");
	
	           break;
	           case 3:
		            puts("************************************************************************************************************************");
					puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		            puts("                                           remplir les informations de Villa");
		            puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	
				    l=chargementVilla(l);
		            l=removeDuplicatesVILLA(l);
		            afficherTousLesVilla(l);
		            printf("tapez le nom de la ville                         \t: ==> ");
		            scanf("%s",Vill);
		            getchar();
		            printf("tapez la superficie                              \t: ==> ");
		            scanf("%s",superfici);
		            getchar();
		            printf("tapez le nom du cartier                          \t: ==> ");
		            scanf("%s",adress);
		            getchar();
		            printf("tapez le prix                                    \t: ==> ");
			        scanf("%f",&pri);
			        getchar();
			        printf("tapez le nombre de  bains                        \t: ==> ");
			        scanf("%d",&nbreBain);
			        getchar();
			        printf("tapez nombre de Chambres                         \t: ==> ");
			        scanf("%d",&nbreChambre);
			        getchar();
			        printf("tapez nombre de cuisine                          \t: ==> ");
			        scanf("%d",&nbreCui);
			        getchar();
			        printf("tapez nombre d'etages                            \t: ==> ");
			        scanf("%d",&nbreEtag);
			        getchar();
			        printf("tapez nombre de Toilettes                        \t: ==> ");
			        scanf("%d",&nbreToilette);
			        getchar();
	
				puts("*********************************************************************************************************************");
	           l=insererFinVilla(l,pri,Vill,adress,superfici,nbreEtag,nbreCui,nbreBain,nbreChambre,nbreToilette);
	           l=removeDuplicatesVILLA(l);
			   afficherTousLesVilla(l);
	
	            ecrireVILLA(l);
	           break;
	
	          case 4:
	            puts("************************************************************************************************************************");
				puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	            puts("                                           remplir les informations de Maison");
	            puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	            I=chargementMaison(I);
				I=removeDuplicatesMAISON(I);
	            afficherTousLesMaison(I);
	            printf("tapez le nom de la ville                         \t: ==> ");
	            scanf("%s",Vill);
	            getchar();
	            printf("tapez la superficie                              \t: ==> ");
	            scanf("%s",superfici);
	            getchar();
	            printf("tapez le nom du cartier                          \t: ==> ");
	            scanf("%s",adress);
	            getchar();
	            printf("tapez le prix                                    \t: ==> ");
		        scanf("%f",&pri);
		        getchar();
		        printf("tapez le nombre de  bains                        \t: ==> ");
		        scanf("%d",&nbreBain);
		        getchar();
		        printf("tapez nombre de Chambres                         \t: ==> ");
		        scanf("%d",&nbreChambre);
		        getchar();
		        printf("tapez nombre de cuisine                          \t: ==> ");
		        scanf("%d",&nbreCui);
		        getchar();
		        printf("tapez nombre d'etages                            \t: ==> ");
		        scanf("%d",&nbreEtag);
		        getchar();
		        printf("tapez nombre de Toilettes                        \t: ==> ");
		        scanf("%d",&nbreToilette);
		        getchar();
		        puts("*********************************************************************************************************************");
	            I=insererFinMaison(I,pri,Vill,superfici,adress,nbreBain,nbreChambre,nbreCui,nbreEtag,nbreToilette);
	            I=removeDuplicatesMAISON(I);
	            ecrire2(I);
	            break;
	 			case 5:
	            ModifierAppartement();
	            break;
				
	  			case 6:
		        ModifierTerrain();
	            break;
				
	           case 7: 
			   ModifierVilla();
	           break;
				
	           case 8: 
			   ModifierMaison();
	           break;
	           case 9:
			    liste=chargementAPPARTEMENT_Ver_Sup(liste);
				liste=removeDuplicatesAPPARTEMENT(liste);
				AfficherAppartement(liste);
			    printf("tapez l'adresse                         \t: ==> ");
	            scanf("%s",adress);
	            getchar();
				strcpy(b.adresse,adress);
				liste=SuppressionAppartement(liste,b);
				liste=removeDuplicatesAPPARTEMENT(liste);
				EnregistrerAppartement(liste,"appartement.txt");
				
				
		
			  break;
	          case 10:
				tete=chargementTerrain(tete);
				tete=removeDuplicatesTERRAIN(tete);
				AfficherTerain(tete);
			    printf("tapez l'adresse                          \t: ==> ");
	            scanf("%s",adress);
	            getchar();
				strcpy(c.adresse,adress);
				tete=SuppressionTerain(tete,c);
				tete=removeDuplicatesTERRAIN(tete);
				AfficherTerain(tete);
				SAVETERRAIN(tete,"terrain.txt");
				break;
	            case 11 :
		         l=chargementVilla(l);
				 l=removeDuplicatesVILLA(l);
		         afficherTousLesVilla(l);
	             printf("tapez l'adresse                          \t: ==> ");
		         scanf("%s",adress);
		         getchar();

	             strcpy(A.adresse,adress);
	
	
		         l=SuppressionVILLA(l,A);
		         l=removeDuplicatesVILLA(l);
	
	             EnregistrerVILLA(l,"villa.txt");
		         break;
	
	            case 12:
			    I=chargementMaison(I);
				I=removeDuplicatesMAISON(I);
		        AffichermaisonBis(I);
	            printf("tapez l'adresse                          \t: ==> ");
	            scanf("%s",adress);
	            getchar();
	
	
	           strcpy(B.adresse,adress);
	           I=SuppressionMaison(I,B);
			   I=removeDuplicatesMAISON(I);
			   AffichermaisonBis(I);
		       EnregistrerMaison(I,"maison.txt");
		       break;
		       case 13 : exit(-1);
		       break;
	
	
			   default : 
			   printf("ce numero n'existe pas reessayer un autre (1>>13) Merci!!!\n");
			   break;
	}
	}while(choix != 13);
	
	}
	return 0;
	}

