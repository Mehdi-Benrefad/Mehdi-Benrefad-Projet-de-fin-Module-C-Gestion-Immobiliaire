#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// les structures 
/**********************************************************Structure Villa****************************************/
typedef struct cl
	{
	
	float prix;
	char adresse[100];
	char  Ville[100] ;
	char superficie[50];
	int nbreEtage;
	int nbreCuis;
	int nbreBains;
	int nbreChambres;
	int nbreToilettes;
	struct cl* suiv;
	struct cl* prec;
	
	}VILLA;

/******************************************************Structure Appartement ************************************/
typedef struct ap
	{
	
	float prix;
	char adresse[100];
	char  Ville[100] ;
	char superficie[50];
	int nbreEtage;
	int nbreCuis;
	int nbreBains;
	int nbreChambres;
	int nbreToilettes;
	struct ap* suiv;
	struct ap* prec;
	
	}APPARTEMENT;
/*******************************************************Structure Maison*****************************************/

typedef struct ma
	{
	
	float prix;
	char adresse[100];
	char  Ville[100] ;
	char superficie[50];
	int nbreEtage;
	int nbreCuis;
	int nbreBains;
	int nbreChambres;
	int nbreToilettes;
	struct ma* suiv;
	struct ma* prec;
	
	}MAISON;
/**********************************************************Structure Terrain****************************************/

typedef struct te
	{
	
	float prix;
	char adresse[100];
	char  Ville[100] ;
	char superficie[50];
	char type[50];
	struct te* suiv;
	struct te* prec;
	
	}TERRAIN;
// les méthodes de villa

VILLA* creer_Maillon_Villa( )
{
    VILLA* p;
    
    p=(VILLA*)malloc(sizeof(VILLA));

	if(!p)
			{
				printf("mémoire pleine\n");
				exit(-1);
			}

	else
			{
				p->suiv=NULL;
			    p->prec=NULL;
			    return p;
			}
			
}

                         // *******************************************************************

VILLA* chargementVilla(VILLA*l)
{

	VILLA* p=NULL;
	VILLA* s=NULL;
	float prix;
	char Vl[100];
	char suprf[50];
	char adr[100];
	int nE;
	int nC;
	int nB;
	int nCham;
	int nToil;

FILE* f;
f=fopen("villa.txt","r");

				while(!feof(f))
				{
					fscanf(f,"%f %s %s %s %d %d %d %d %d" ,&prix,Vl,adr,suprf,&nE,&nC,&nB,&nCham,&nToil);
					p=creer_Maillon_Villa( );
				
					  if(l==NULL)
						    	
							     	{
									
										strcpy(p->superficie,suprf);
										strcpy(p->Ville,Vl);
									    strcpy(p->adresse,adr);
										p->nbreBains=nB;
										p->nbreChambres=nCham;
										p->nbreCuis=nC;
										p->nbreEtage=nE;
										p->nbreToilettes=nToil;
										p->prix=prix;
										l=p;
										
									}
									
					      else
									{
									    
										s=l;
									    while(s->suiv!=NULL)
												
											{
													            s=s->suiv;
											}
													
										strcpy(p->superficie,suprf);
										strcpy(p->Ville,Vl);
										strcpy(p->adresse,adr);
										p->nbreBains=nB;
										p->nbreChambres=nCham;
										p->nbreCuis=nC;
										p->nbreEtage=nE;
										p->nbreToilettes=nToil;
										p->prix=prix;
										p->suiv=NULL;
										p->prec=s;
										s->suiv=p;
								
									}
				}
fclose(f);
return l;

}

                        // *******************************************************************


VILLA*insererFinVilla(VILLA*l,float prix,char Vl[100],char adr[100],char suprf[50],int nE,int nC,int nB,int nCham,int nToil)
	{
		VILLA*nem=NULL,*p;
		nem=creer_Maillon_Villa();
		nem->prix=prix;
		strcpy(nem->Ville,Vl);
		strcpy(nem->superficie,suprf);
		strcpy(nem->adresse,adr);
		nem->nbreEtage=nE;
		nem->nbreCuis=nC;
		nem->nbreBains=nB;
		nem->nbreChambres=nCham;
		nem->nbreToilettes=nToil;
	
				 if(l==NULL)
					
								{
							        l=nem;
								}
								
			   	 else
							   
							    {
							        p=l;
							        
								        while(p->suiv!=NULL)
														        {
														            p=p->suiv;
														        }
														        
								    p->suiv=nem;
								    
							    }
	return l;
	}
             // *******************************************************************
void afficherTousLesVilla(VILLA*l)
	{
	    
		VILLA*p=l;
	    
			    while(p!=NULL)
			    {
					    printf("prix=%fdhs\nVille:%s\nAdresse:%s\nsuperficie:%s\nNombre Etages:%d\nNombre Cuisines:%d\nNombres Bains:%d\nNombres Chambres:%d\nNombres Toilettes:%d" ,p->prix,p->Ville,p->adresse,p->superficie,p->nbreEtage,p->nbreCuis,p->nbreBains,p->nbreChambres,p->nbreToilettes);
					    printf("\n                +++++++++++++++++++++                  \n");
					    p=p->suiv;
			    }
	}

           // *******************************************************************

void afficherVilla(VILLA*l)
	{
		
		VILLA*p=l;
		printf("%f %s %s %s %d %d %d %d %d" ,p->prix,p->Ville,p->adresse,p->superficie,p->nbreEtage,p->nbreCuis,p->nbreBains,p->nbreChambres,p->nbreToilettes);
		printf("\n");
	
	}

          // *******************************************************************
          
void ecrireVILLA(VILLA*l)
	{
	    VILLA*p=l;
	    FILE * f;
	    f=fopen("villa.txt","w");
	    
				    while(p!=NULL)
					{
					     fprintf(f,"%f %s %s %s %d %d %d %d %d\n" ,p->prix,p->Ville,p->adresse,p->superficie,p->nbreEtage,p->nbreCuis,p->nbreBains,p->nbreChambres,p->nbreToilettes);
					     p=p->suiv;
					}
				    fclose(f);
	
	}
	
         // *******************************************************************
void EnregistrerVILLA(VILLA*l,char*Nomfile)
	{
		FILE*F;
		VILLA*p;
		F=fopen(Nomfile,"w");
		
					if(F==NULL)
					{
					    printf("%s inexistant\n",Nomfile);
					    exit(-1);
					}
				    	p=l;
				    	
					while(p)
					{
					    fprintf(F,"%f %s %s %s %d %d %d %d %d\n" ,p->prix,p->Ville,p->adresse,p->superficie,p->nbreEtage,p->nbreCuis,p->nbreBains,p->nbreChambres,p->nbreToilettes);
					    p=p->suiv;
					}
					fclose(F);
	}
	        // *******************************************************************

VILLA* SuppressionVILLA(VILLA* l,VILLA A)
	{
	    VILLA* p=l,*y,*q;
				    if(l!=NULL)
				    {
				        if(strcmp(l->adresse,A.adresse)==0)
						
										{
								            y=l;
								            l=l->suiv;
								            l->prec=NULL;
								         	free(y);
								            printf("\nsuppression reussite\n");
								            return l;
								        }
				    }
	
	    y=p;
	    p=p->suiv;   //case2
	    q=p->suiv;   //case3
	
				    while(p!=NULL && q!=NULL)
				    {
				         if( strcmp(l->adresse,A.adresse)==0)
				         {
				            y->suiv=q;
				            q->prec=y;
				            free(p);
				            printf("\nsuppression reussite\n");
				            return l;
				         }
				         else
				         {
				            y=p;
				            p=p->suiv;
				            q=p->suiv;
				         }
				
				
				     }
	
	     y->suiv=q;
	     free(p);
	     return l;
	
	}
	    // *******************************************************************

void ModifierVilla()
	  {
	      FILE *fichier;
	      FILE *fichier1;
	       VILLA *o=NULL;
	      int NBC =0;
	      int i=0;
	      int j;
	      char c;
	      int modifier=4;
	
	
	      fichier = fopen("villa.txt","r");
			      if(fichier != NULL)
			          {
			             fichier1 = fopen("Villa1.txt","a");
			             while(!feof(fichier))
					             {
					             	
								              o=realloc(o, (NBC+1)*sizeof(VILLA));
								              fscanf(fichier,"%f",&o[NBC].prix);
								              fscanf(fichier,"%s",o[NBC].Ville);
								              fscanf(fichier,"%s",o[NBC].adresse);
								              fscanf(fichier,"%s",o[NBC].superficie);
								              fscanf(fichier,"%d",&o[NBC].nbreChambres);
								              fscanf(fichier,"%d",&o[NBC].nbreToilettes);
								              fscanf(fichier,"%d",&o[NBC].nbreBains);
								              fscanf(fichier,"%d",&o[NBC].nbreCuis);
								              fscanf(fichier,"%d",&o[NBC].nbreEtage);
								
								              NBC++;
								              
					             }
			          while(i<NBC-1 && modifier!=3)
		                         {
		                         	
								       puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
									   puts("                                         voila les ancienne informations ");
									   puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
							           puts("************************************************************************************************************************");
								            printf("Prix              :%f\n",o[i].prix);
								            printf("la ville          :%s\n",o[i].Ville);
								            printf("Adresse           :%s\n",o[i].adresse);
								            printf("Superficie        :%s\n",o[i].superficie);
								            printf("Nombre chambre    :%d\n",o[i].nbreChambres);
								            printf("Nombre toilete    :%d\n",o[i].nbreToilettes);
								            printf("Nombre bains      :%d\n",o[i].nbreBains);
								            printf("Nombre cuisine    :%d\n",o[i].nbreCuis);
								            printf("Etage             :%d\n",o[i].nbreEtage);
								            puts("************************************************************************************************************************");
								            printf("est-ce que l'appartement que vous voulez modifier ?\n");
											puts("si oui  <<<<<< tapez 1>>>>>>      ");
											puts("si non  <<<<<< tapez 2>>>>>> pour passer au suivante       ");
								            scanf("%d",&modifier);
			            
						
						                switch(modifier)
					                                {
									                      case 1:
																    puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
																    puts("                                         les nouvelles informations ");
																    puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
															        puts("************************************************************************************************************************");
											                        printf("tapez le nouveau prix du villa                        \t: ==> ");
											                        scanf("%f",&o[i].prix);
											                        printf("tapez le nouveau nom de la ville de la villa          \t: ==> ");
											                        scanf("%s",o[i].Ville);
											                        printf("tapez la nouvelle adresse de la villa                 \t: ==> ");
											                        scanf("%s",o[i].adresse);
											                        printf("tapez la nouvelle superficie                          \t: ==> ");
											                        scanf("%s",o[i].superficie);
											                        printf("tapez le Nombre de chambres                           \t: ==> ");
											                        scanf("%d",&o[i].nbreChambres);
											                        printf("tapez le Nombre de Toilettes                          \t: ==> ");
											                        scanf("%d",&o[i].nbreToilettes);
											                        printf("tapez le Nombre de bains                              \t: ==> ");
											                        scanf("%d",&o[i].nbreBains);
											                        printf("tapez Nombre de cuisines                              \t: ==> ");
											                        scanf("%d",&o[i].nbreCuis);
											                        printf("tapez Nombre de bains                                 \t: ==> ");
											                        scanf("%d",&o[i].nbreEtage);
											                        i++;
									                                break;
											                 case 2:i++;
											                        break;
											                 case 3:printf("fin des modification\n");
											                         break;
											
											                  default : printf("ce numero n'existe pas\n");
											                        break;
									            }
			
						          }
						          
						          printf("             \n");
						          rewind(fichier);
						          if((c=fgetc(fichier))!= EOF)
						          printf("*****************Fin Modification*****************\n");
						          else
						          printf("echec,la liste des appartements est vide \n");
						          for( j=0;j<NBC-1;j++)
								          {
								              fprintf(fichier1,"%f ",o[j].prix);
											  fprintf(fichier1,"%s ",o[j].Ville);
								              fprintf(fichier1,"%s ",o[j].adresse);
								              fprintf(fichier1,"%s ",o[j].superficie);
								              fprintf(fichier1,"%d ",o[j].nbreChambres);
								              fprintf(fichier1,"%d ",o[j].nbreToilettes);
								              fprintf(fichier1,"%d ",o[j].nbreBains);
								              fprintf(fichier1,"%d ",o[j].nbreCuis);
								              fprintf(fichier1,"%d\n",o[j].nbreEtage);
								          }
						          fclose(fichier1);
						          fclose(fichier);
						          remove("villa.txt");
						          rename("Villa1.txt","villa.txt");
						      }
						
						      else
						      printf("echec,la liste des villas est vide \n");
     }
   // *******************************************************************
  
  VILLA* removeDuplicatesVILLA(VILLA* head)
	{
	
	   VILLA* current = head;
	
	    VILLA* next_next;
	
	    if (current == NULL)
	    return head;
	
	    while (current->suiv != NULL)
		    {
		    	
		    if (strcmp( current->adresse,current->suiv->adresse)==0  &&  current->nbreBains==current->suiv->nbreBains  &&  current->nbreChambres==current->suiv->nbreChambres && current->nbreCuis==current->suiv->nbreCuis && current->nbreEtage==current->suiv->nbreEtage && current->nbreToilettes==current->suiv->nbreToilettes && current->prix==current->suiv->prix && strcmp( current->superficie,current->suiv->superficie)==0 && strcmp( current->Ville,current->suiv->Ville)==0)
			    {
			        next_next = current->suiv->suiv;
			        free(current->suiv);
			        current->suiv = next_next;
			    }
		    else
			    {
			        current = current->suiv;
			    }
		    }
	
	    return head;
	}
	  // *******************************************************************
VILLA* removeDuplicatesVILLA_Ville_Version(VILLA* head)
	{
	
	   VILLA* current = head;
	
	    VILLA* next_next;
	
	    if (current == NULL)
	    return head;
	
	    while (current->suiv != NULL)
	      {
			    if (strcmp( current->Ville,current->suiv->Ville)==0)
				    {
				        next_next = current->suiv->suiv;
				        free(current->suiv);
				        current->suiv = next_next;
				    }
			    else
				    {
				        current = current->suiv;
				    }
	     }
	
	    return head;
	}
	// *******************************************************************
	// les méthodes de maison

MAISON* creerMaison( )
	{
		MAISON* p;
	
		p=( MAISON*)malloc(sizeof( MAISON));
	
		if(!p)
			{
				printf("mémoire plien\n");
				exit(-1);
			}
		else
			{
				p->suiv=NULL;
			    p->prec=NULL;
				return p;
			}
	}
// *******************************************************************

MAISON* chargementMaison(MAISON*l)
	{
	
	MAISON* p=NULL;
	MAISON* s=NULL;
	float prix;
	char Vl[100];
	char suprf[50];
	char adr[100];
	int nE;
	int nC;
	int nB;
	int nCham;
	int nToil;
	
	FILE* f;
	f=fopen("maison.txt","r");
	while(!feof(f))
		{
			fscanf(f,"%f %s %s %s %d %d %d %d %d" ,&prix,Vl,adr,suprf,&nE,&nC,&nB,&nCham,&nToil);
			p=creerMaison( );
			
				if(l==NULL)
						{
							strcpy(p->superficie,suprf);
							strcpy(p->Ville,Vl);
						    strcpy(p->adresse,adr);
							p->nbreBains=nB;
							p->nbreChambres=nCham;
							p->nbreCuis=nC;
							p->nbreEtage=nE;
							p->nbreToilettes=nToil;
							p->prix=prix;
							l=p;
						}
			   else
						{
						    s=l;
						    while(s->suiv!=NULL)
								{
						            s=s->suiv;
							    }
							strcpy(p->superficie,suprf);
							strcpy(p->Ville,Vl);
							strcpy(p->adresse,adr);
							p->nbreBains=nB;
							p->nbreChambres=nCham;
							p->nbreCuis=nC;
							p->nbreEtage=nE;
							p->nbreToilettes=nToil;
							p->prix=prix;
							p->suiv=NULL;
							p->prec=s;
							s->suiv=p;
					
						}
		}
	fclose(f);
	return l;
	
	}


    // *******************************************************************
void EnregistrerMaison(MAISON*l,char*Nomfile)

	{
		FILE*F;
		MAISON*p;
		F=fopen(Nomfile,"w");
		if(F==NULL)
			{
			    printf("%s inexistant\n",Nomfile);
			    exit(-1);
			}
       p=l;
		while(p)
			{
			    fprintf(F,"%f %s %s %s %d %d %d %d %d\n",p->prix,p->Ville,p->adresse,p->superficie,p->nbreEtage,p->nbreCuis,p->nbreBains,p->nbreChambres,p->nbreToilettes);
			    p=p->suiv;
			}
	fclose(F);
	}
	     // *******************************************************************
MAISON* SuppressionMaison(MAISON* l,MAISON A)
	{
	    MAISON* p=l,*y,*q;
	    
			    if(l!=NULL)
				    {
				        if(strcmp(l->adresse,A.adresse)==0)
							{
					            y=l;
					            l=l->suiv;
					            l->prec=NULL;
					            free(y);
					            printf("\nsuppression reussite\n");
					            return l;
					        }
				    }
	
	    y=p;
	    p=p->suiv;   //case2
	    q=p->suiv;  //case3
	
				while(p!=NULL && q!=NULL)
				    {
				         if( strcmp(l->adresse,A.adresse)==0)
					         {
					            y->suiv=q;
					            q->prec=y;
					            free(p);
					            printf("\nsuppression reussite\n");
					            return l;
					         }
				         else
					         {
					            y=p;
					            p=p->suiv;
					            q=p->suiv;
					         }
				
				
	     }
	
	     y->suiv=q;
	     free(p);
	     return l;
	
	}

             // *******************************************************************
 MAISON*insererFinMaison( MAISON*l,float prix,char Vl[100],char adr[100],char suprf[50],int nE,int nC,int nB,int nCham,int nToil)
	{
		MAISON*nem=NULL,*p;
		nem=creerMaison();
		nem->prix=prix;
		strcpy(nem->Ville,Vl);
		strcpy(nem->superficie,suprf);
		strcpy(nem->adresse,adr);
		nem->nbreEtage=nE;
		nem->nbreCuis=nC;
		nem->nbreBains=nB;
		nem->nbreChambres=nCham;
		nem->nbreToilettes=nToil;
	
			if(l==NULL)
				{
			        l=nem;
				}
			else
			    {
			        p=l;
			        while(p->suiv!=NULL)
				        {
				            p=p->suiv;
				
				        }
			         p->suiv=nem;
			    }
	 return l;
	
	}
	           // *******************************************************************

 MAISON*RechercherMaison( MAISON*l,float prix,char Vl[100],char adr[100],char suprf[50],int nE,int nC,int nB,int nCham,int nToil)
	{
	
	    MAISON*p=l;
	    int found=0;
	    while(p!=NULL && !found)
			{
		        if(( strcmp(p->Ville,Vl)==0 && strcmp(p->superficie,suprf)==0 && strcmp(p->adresse,adr)==0 && p->prix==prix && p->nbreEtage==nE && p->nbreCuis==nC && p->nbreBains==nB && p->nbreChambres==nCham && p->nbreToilettes==nToil ))
					{
			            found =1;
			        }
		        else
					{
			            p=p->suiv;
			        }
		    }
	    return p;
	
	}
	        // *******************************************************************

void afficherTousLesMaison( MAISON*l)
	{
	    MAISON*p=l;
	    
	    while(p!=NULL)
		    {
			    printf("prix=%fdhs\nVille:%s\nadresse:%s\nsuperficie:%s\nNombre Etages:%d\nNombre Cuisines:%d\nNombres Bains:%d\nNombres Chambres:%d\nNombres Toilettes:%d" ,p->prix,p->Ville,p->adresse,p->superficie,p->nbreEtage,p->nbreCuis,p->nbreBains,p->nbreChambres,p->nbreToilettes);
			    printf("\n                     +++++++++++++++++++++                  \n");
			    p=p->suiv;
		    }
	}
             // *******************************************************************
void ecrire2( MAISON*l)
	{
	    MAISON*p=l;
	    FILE * f;
	    f=fopen("maison.txt","w");
	    
		    while(p!=NULL)
				{
			
				    fprintf(f,"%f %s %s %s %d %d %d %d %d\n",p->prix,p->Ville,p->adresse,p->superficie,p->nbreEtage,p->nbreCuis,p->nbreBains,p->nbreChambres,p->nbreToilettes);
				    p=p->suiv;
			
			    }
	    fclose(f);
	
	}
               // *******************************************************************
void Enregistrer1( MAISON*l,char*Nomfile)
	{
		FILE*F;
		MAISON*p;
		F=fopen(Nomfile,"a+");
	
			if(F==NULL)
				{
				    printf("%s inexistant\n",Nomfile);
				    exit(-1);
				}
     	p=l;
		    while(p)
				{
				    fprintf(F,"%f %s %s %s %d %d %d %d %d\n" ,p->prix,p->Ville,p->adresse,p->superficie,p->nbreEtage,p->nbreCuis,p->nbreBains,p->nbreChambres,p->nbreToilettes);
				    p=p->suiv;
				}
    	fclose(F);
	}
               // *******************************************************************
MAISON* Suppression1(MAISON * l,MAISON A)
	{
	    MAISON * p=l,*y,*q;
	    if(l!=NULL)
		    {
		        if(strcmp(l->adresse,A.adresse)==0 )
					{
			            y=l;
			            l=l->suiv;
			            l->prec=NULL;
			            free(y);
			            printf("\nsuppression reussite\n");
			            return l;
			        }
		    }
	
	    y=p;
	    p=p->suiv;   //case2
	    q=p->suiv;  //case3
	
	    while(p!=NULL && q!=NULL)
	    {
	         if( strcmp(l->adresse,A.adresse)==0 )
			         {
			            y->suiv=q;
			            q->prec=y;
			            free(p);
			            printf("\nsuppression reussite\n");
			            return l;
			         }
	         else
			         {
			            y=p;
			            p=p->suiv;
			            q=p->suiv;
			         }
	
	
	     }
	
	     y->suiv=q;
	     free(p);
	     return l;
	
	}
               // *******************************************************************
void ModifierMaison()
  {
      FILE *fichier;
      FILE *fichier1;
      MAISON*o=NULL;
      int NBC =0;
      int i=0;
      int j;
      char c;
      int modifier=4;


      fichier = fopen("maison.txt","r");
	      if(fichier != NULL)
	      {
	             fichier1 = fopen("Maison1.txt","a");
	             while(!feof(fichier))
			             {
			             	
				              o=realloc(o, (NBC+1)*sizeof(MAISON));
				              fscanf(fichier,"%f",&o[NBC].prix);
				              fscanf(fichier,"%s",o[NBC].Ville);
				              fscanf(fichier,"%s",o[NBC].adresse);
				              fscanf(fichier,"%s",o[NBC].superficie);
				              fscanf(fichier,"%d",&o[NBC].nbreChambres);
				              fscanf(fichier,"%d",&o[NBC].nbreToilettes);
				              fscanf(fichier,"%d",&o[NBC].nbreBains);
				              fscanf(fichier,"%d",&o[NBC].nbreCuis);
				              fscanf(fichier,"%d",&o[NBC].nbreEtage);
				
				              NBC++;
			          }
	             while(i<NBC-1 && modifier!=3)
			          {
					       puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
						   puts("                                         voila les ancienne informations ");
						   puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
					       puts("************************************************************************************************************************");
					            printf("Prix              :%f\n",o[i].prix);
					            printf("la ville          :%s\n",o[i].Ville);
					            printf("Adresse           :%s\n",o[i].adresse);
					            printf("Superficie        :%s\n",o[i].superficie);
					            printf("Nombre chambre    :%d\n",o[i].nbreChambres);
					            printf("Nombre toilete    :%d\n",o[i].nbreToilettes);
					            printf("Nombre bains      :%d\n",o[i].nbreBains);
					            printf("Nombre cuisine    :%d\n",o[i].nbreCuis);
					            printf("Etage             :%d\n",o[i].nbreEtage);
					            puts("************************************************************************************************************************");
					            printf("est-ce que la maison que vous voulez modifier ?\n");
								puts("si oui  <<<<<< tapez 1>>>>>>      ");
								puts("si non  <<<<<< tapez 2>>>>>> pour passer au suivante       ");
					            scanf("%d",&modifier);
	            switch(modifier)
			            {
			                case 1:
								   puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
								   puts("                                         les nouvelles informations ");
								   puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
							       puts("************************************************************************************************************************");
			                        printf("tapez le nouveau prix de la maison                    \t: ==> ");
			                        scanf("%f",&o[i].prix);
			                        printf("tapez le nouveau  nom de la ville de la maison        \t: ==> ");
			                        scanf("%s",o[i].Ville);
			                        printf("tapez la nouvelle adresse de la maison                \t: ==> ");
			                        scanf("%s",o[i].adresse);
			                        printf("tapez la nouvelle superficie de la maison             \t: ==> ");
			                        scanf("%s",o[i].superficie);
			                        printf("tapez le Nombre de chambres                           \t: ==> ");
			                        scanf("%d",&o[i].nbreChambres);
			                        printf("tapez le Nombre de Toilettes                          \t: ==> ");
			                        scanf("%d",&o[i].nbreToilettes);
			                        printf("tapez Nombre de bains                                 \t: ==> ");
			                        scanf("%d",&o[i].nbreBains);
			                        printf("tapez Nombre de cuisines                              \t: ==> ");
			                        scanf("%d",&o[i].nbreCuis);
			                        printf("tapez Nombre de bains                                 \t: ==> ");
			                        scanf("%d",&o[i].nbreEtage);
			                        i++;
			                        break;
			                 case 2:i++;
			                        break;
			                 case 3:printf("fin des modification\n");
			                         break;
			
			                 default:printf("ce numero n'existe pas\n");
			                        break;
			            }
			
	          }
	          printf("             \n");
	          rewind(fichier);
	          if((c=fgetc(fichier))!= EOF)
	          printf("*****************Fin Modification*****************\n");
	          else
	          printf("echec,la liste des maison est vide \n");
			          for( j=0;j<NBC-1;j++)
					          {
					              fprintf(fichier1,"%f ",o[j].prix);
								  fprintf(fichier1,"%s ",o[j].Ville);
					              fprintf(fichier1,"%s ",o[j].adresse);
					              fprintf(fichier1,"%s ",o[j].superficie);
					              fprintf(fichier1,"%d ",o[j].nbreChambres);
					              fprintf(fichier1,"%d ",o[j].nbreToilettes);
					              fprintf(fichier1,"%d ",o[j].nbreBains);
					              fprintf(fichier1,"%d ",o[j].nbreCuis);
					              fprintf(fichier1,"%d\n",o[j].nbreEtage);
					          }
	          fclose(fichier1);
	          fclose(fichier);
	          remove("maison.txt");
	          rename("Maison1.txt","maison.txt");
	      }

      else
      printf("echec,la liste des maisons est vide \n");
  }
                // *******************************************************************
  MAISON* removeDuplicatesMAISON(MAISON* head)
	{
	
	    MAISON* current = head;
	
	    MAISON* next_next;
	
	    if (current == NULL)
	    return head;
	
	    while (current->suiv != NULL)
		    {
		    if ( strcmp( current->adresse,current->suiv->adresse)==0  &&  current->nbreBains==current->suiv->nbreBains  &&  current->nbreChambres==current->suiv->nbreChambres && current->nbreCuis==current->suiv->nbreCuis && current->nbreEtage==current->suiv->nbreEtage && current->nbreToilettes==current->suiv->nbreToilettes && current->prix==current->suiv->prix && strcmp( current->superficie,current->suiv->superficie)==0 && strcmp( current->Ville,current->suiv->Ville)==0)
			    {
			        next_next = current->suiv->suiv;
			        free(current->suiv);
			        current->suiv = next_next;
			    }
		    else
			    {
			        current = current->suiv;
			    }
		    }
	
	    return head;
	}
         // *******************************************************************
         
  MAISON* removeDuplicatesMAISON_Ville_Version(MAISON* head)
	{
	
	    MAISON* current = head;
	
	    MAISON* next_next;
	
	    if (current == NULL)
	    return head;
	
	    while (current->suiv != NULL)
		    {
		    if ( strcmp( current->Ville,current->suiv->Ville)==0 )
			    {
			        next_next = current->suiv->suiv;
			        free(current->suiv);
			        current->suiv = next_next;
			    }
		    else
			    {
			        current = current->suiv;
			    }
		    }
	
	    return head;
	}
                 // *******************************************************************
                 // les méthodes d'appartement
APPARTEMENT* Creer()
	{
	    APPARTEMENT *p;
	    p = (APPARTEMENT*)malloc(sizeof(APPARTEMENT));
	    
		    if(p == NULL)
			    {
			        printf("mémoire plien ");
			        exit(-1);
			    }
		
	        p->prec = NULL;
	        p->suiv = NULL;
	        return p;
	
	}
             // *******************************************************************
APPARTEMENT*chargementAppartement(APPARTEMENT*l)
	{
	
	APPARTEMENT* p=NULL;
	APPARTEMENT* s=NULL;
	float prix;
	char Vl[100];
	char suprf[50];
	char adr[100];
	int nE;
	int nC;
	int nB;
	int nCham;
	int nToil;
	
	FILE* f;
	f=fopen("appartement.txt","r");
	
	while(!feof(f))
		{
			fscanf(f,"%f %s %s %s %d %d %d %d %d",&prix,Vl,adr,suprf,&nE,&nC,&nB,&nCham,&nToil);
			p=Creer();
		
			if(l==NULL)
					{
						strcpy(p->superficie,suprf);
						strcpy(p->Ville,Vl);
					    strcpy(p->adresse,adr);
						p->nbreBains=nB;
						p->nbreChambres=nCham;
						p->nbreCuis=nC;
						p->nbreEtage=nE;
						p->nbreToilettes=nToil;
						p->prix=prix;
						l=p;
					}
			else
					{
					    s=l;
					    while(s->suiv!=NULL)
							{
					            s=s->suiv;
						    }
								strcpy(p->superficie,suprf);
								strcpy(p->Ville,Vl);
								strcpy(p->adresse,adr);
								p->nbreBains=nB;
								p->nbreChambres=nCham;
								p->nbreCuis=nC;
								p->nbreEtage=nE;
								p->nbreToilettes=nToil;
								p->prix=prix;
								p->suiv=NULL;
								p->prec=s;
								s->suiv=p;
						
					}
		}
	fclose(f);
	return l;
	
	}

       // *******************************************************************
 APPARTEMENT* removeDuplicatesAPPARTEMENT(APPARTEMENT* head)
	{
	
	    APPARTEMENT* current = head;
	
	    APPARTEMENT* next_next;
	
	    if (current == NULL)
	    return head;
	
	    while (current->suiv != NULL)
			    {
			    	
			    if ( strcmp( current->adresse,current->suiv->adresse)==0  &&  current->nbreBains==current->suiv->nbreBains  &&  current->nbreChambres==current->suiv->nbreChambres && current->nbreCuis==current->suiv->nbreCuis && current->nbreEtage==current->suiv->nbreEtage && current->nbreToilettes==current->suiv->nbreToilettes && current->prix==current->suiv->prix && strcmp( current->superficie,current->suiv->superficie)==0 && strcmp( current->Ville,current->suiv->Ville)==0)
				    {
				        next_next = current->suiv->suiv;
				        free(current->suiv);
				        current->suiv = next_next;
				    }
			    else
				    {
				        current = current->suiv;
				    }
			    }
	
	    return head;
	}

       // *******************************************************************
	 APPARTEMENT* removeDuplicatesAPPARTEMENT_Ville_Version(APPARTEMENT* head)
	{
	
	    APPARTEMENT* current = head;
	
	    APPARTEMENT* next_next;
	
	    if (current == NULL)
	    return head;
	
		    while (current->suiv != NULL)
				{
				    if ( strcmp( current->Ville,current->suiv->Ville)==0 )
					    {
					        next_next = current->suiv->suiv;
					        free(current->suiv);
					        current->suiv = next_next;
					    }
				    else
					    {
					        current = current->suiv;
					    }
			    }
	
	    return head;
	}

            // *******************************************************************
void EnregistrerAppartement(APPARTEMENT*l,char*Nomfile)
	{
	FILE*F;
	APPARTEMENT*p;
	F=fopen(Nomfile,"w");
	if(F==NULL){
	    printf("%s inexistant\n",Nomfile);
	    exit(-1);
	}
	p=l;
	while(p)
	{
	    fprintf(F,"%f %s %s %s %d %d %d %d %d\n" ,p->prix,p->Ville,p->adresse,p->superficie,p->nbreEtage,p->nbreCuis,p->nbreBains,p->nbreChambres,p->nbreToilettes);
	    p=p->suiv;
	}
	fclose(F);
	}
	
	
	void EnregistrerAppart(APPARTEMENT*l,char*Nomfile){
	FILE*F;
	APPARTEMENT*p;
	F=fopen(Nomfile,"w");
	if(F==NULL){
	    printf("%s inexistant\n",Nomfile);
	    exit(-1);
	}
	p=l;
	while(p)
	{
	    fprintf(F,"%f %s %s %s %d %d %d %d %d\n" ,p->prix,p->Ville,p->adresse,p->superficie,p->nbreEtage,p->nbreCuis,p->nbreBains,p->nbreChambres,p->nbreToilettes);
	    p=p->suiv;
	}
	fclose(F);
	}
	            // *******************************************************************
	            
APPARTEMENT* SuppressionAppartement(APPARTEMENT* l,APPARTEMENT A)
	{
	    APPARTEMENT* p=l,*y,*q;
		    if(l!=NULL)
			    {
			        if(strcmp(l->adresse,A.adresse)==0)
						{
				            y=l;
				            l=l->suiv;
				            l->prec=NULL;
				            free(y);
				            printf("\nsuppression reussite\n");
				            return l;
				        }
			    }
			
	    y=p;
	    p=p->suiv;   //case2
	    q=p->suiv;  //case3
	
		    while(p!=NULL && q!=NULL)
		    {
		         if( strcmp(l->adresse,A.adresse)==0)
			         {
			            y->suiv=q;
			            q->prec=y;
			            free(p);
			            printf("\nsuppression reussite\n");
			            return l;
			         }
		         else
			         {
			            y=p;
			            p=p->suiv;
			            q=p->suiv;
			         }
		
		
		     }
		
		     y->suiv=q;
		     free(p);
		     return l;
		
	}

               // *******************************************************************
APPARTEMENT *AjoutAppartementDebut(APPARTEMENT a,APPARTEMENT*tete)
  {
      APPARTEMENT *f;
      f = Creer();
      f->prix = a.prix;
      strcpy(f->adresse,a.adresse);
      strcpy(f->superficie,a.superficie);
      strcpy(f->Ville,a.Ville);
      f->nbreBains = a.nbreBains;
      f->nbreChambres = a.nbreChambres;
      f->nbreCuis = a.nbreCuis;
	  f->nbreEtage= a.nbreEtage;
      strcpy(f->Ville,a.Ville);
      f->nbreToilettes = a.nbreToilettes;

      if(tete == NULL)

          tete = f;

      else
      {
          f->suiv = tete;
          tete->prec = f;
          tete = f;
      }
      return tete;
  }

 // *******************************************************************
   void AfficherAppartement(APPARTEMENT*tete)
  {
     APPARTEMENT *s = tete;

      while(s!=NULL)
	      {
	          printf("******************************\n");
	          printf("                               \n");
	          printf("Prix : %f\n",s->prix);
	          printf("la ville : %s\n",s->Ville);
	          printf("l'adresse: %s \n",s->adresse);
	          printf("superficie : %s\n",s->superficie);
	          printf("Nombre de chambre : %d\n",s->nbreChambres);
	          printf("Nombre de Bain : %d\n",s->nbreBains);
	          printf("Nombre de cuisine : %d\n",s->nbreCuis);
	          printf("Nombre de Toilette : %d\n",s->nbreToilettes);
	          printf("Etage: %d\n",s->nbreEtage);
	          printf("                               \n");
	          s = s->suiv;
	      }

  }
              // *******************************************************************
void AjoutAppartementFichier(APPARTEMENT*tete)
  {   FILE *fichier;
      APPARTEMENT *b=tete;
      fichier=fopen("appartement.txt","w");
      
      if(fichier == NULL)
       printf("ouverture echouer");
      else
         {
	          while(b!=NULL)
		          {
		
		              fprintf(fichier,"%f %s %s %s %d %d %d %d %d\n",b->prix,b->Ville,b->adresse,b->superficie,b->nbreEtage,b->nbreCuis,b->nbreBains,b->nbreChambres,b->nbreToilettes);
		              b=b->suiv;
		          }
	          fclose(fichier);
	      }
  }
  // *******************************************************************
void ModifierAppartement()
  {
      FILE *fichier;
      FILE *fichier1;
      APPARTEMENT *o=NULL;
      int NBC =0;
      int i=0;
      int j;
      char c;
      int modifier=4;


      fichier = fopen("appartement.txt","r");
      if(fichier != NULL)
	      {
	             fichier1 = fopen("appartement1.txt","a");
	             while(!feof(fichier))
		             {
		              o=realloc(o, (NBC+1)*sizeof(APPARTEMENT));
		              fscanf(fichier,"%f",&o[NBC].prix);
		              fscanf(fichier,"%s",o[NBC].Ville);
		              fscanf(fichier,"%s",o[NBC].adresse);
		              fscanf(fichier,"%s",o[NBC].superficie);
		              fscanf(fichier,"%d",&o[NBC].nbreChambres);
		              fscanf(fichier,"%d",&o[NBC].nbreToilettes);
		              fscanf(fichier,"%d",&o[NBC].nbreBains);
		              fscanf(fichier,"%d",&o[NBC].nbreCuis);
		              fscanf(fichier,"%d",&o[NBC].nbreEtage);
		
		              NBC++;
		             }
				    while(i<NBC-1 && modifier!=3)
					    {
					       puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
						   puts("                                         voila les ancienne informations ");
						   puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				           puts("************************************************************************************************************************");
					            printf("Prix              :%f\n",o[i].prix);
					            printf("la ville          :%s\n",o[i].Ville);
					            printf("Adresse           :%s\n",o[i].adresse);
					            printf("Superficie        :%s\n",o[i].superficie);
					            printf("Nombre chambre    :%d\n",o[i].nbreChambres);
					            printf("Nombre toilete    :%d\n",o[i].nbreToilettes);
					            printf("Nombre bains      :%d\n",o[i].nbreBains);
					            printf("Nombre cuisine    :%d\n",o[i].nbreCuis);
					            printf("Etage             :%d\n",o[i].nbreEtage);
					            puts("************************************************************************************************************************");
					            printf("est-ce que l'appartement que vous voulez modifier ?\n");
								puts("si oui  <<<<<< tapez 1>>>>>>      ");
								puts("si non  <<<<<< tapez 2>>>>>> pour passer au suivante       ");
					            scanf("%d",&modifier);
	              switch(modifier)
			            {
			                case 1:
								   puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
								    puts("                                         les nouvelles informations ");
								    puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
							        puts("************************************************************************************************************************");
			                        printf("tapez le nouveau prix de l'appartement                \t: ==> ");
			                        scanf("%f",&o[i].prix);
			                        printf("tapez le nouveau nom de la ville de l'appartement     \t: ==> ");
			                        scanf("%s",o[i].Ville);
			                        printf("tapez la nouvelle adresse de l'appartement            \t: ==> ");
			                        scanf("%s",o[i].adresse);
			                        printf("tapez la nouvelle superficie                          \t: ==> ");
			                        scanf("%s",o[i].superficie);
			                        printf("tapez le Nombre de chambres                           \t: ==> ");
			                        scanf("%d",&o[i].nbreChambres);
			                        printf("tapez Nombre de Toilettes                             \t: ==> ");
			                        scanf("%d",&o[i].nbreToilettes);
			                        printf("tapez Nombre de bains                                 \t: ==> ");
			                        scanf("%d",&o[i].nbreBains);
			                        printf("tapez Nombre de cuisines                              \t: ==> ");
			                        scanf("%d",&o[i].nbreCuis);
			                        printf("tapez Nombre de bains                                 \t: ==> ");
			                        scanf("%d",&o[i].nbreEtage);
			                        i++;
			                        break;
			                 case 2:i++;
			                        break;
			                 case 3:printf("fin des modification\n");
			                         break;
			
			                 default : printf("ce numero n'existe pas\n");
			                        break;
			            }
	
	          }
	          printf("             \n");
	          rewind(fichier);
	          if((c=fgetc(fichier))!= EOF)
	          
		          {
		          	printf("*****************Fin Modification*****************\n");
				  }
	          
	          else
		          {
		          	printf("echec,la liste des appartements est vide \n");  
				  }
			  
	          
	          for( j=0;j<NBC-1;j++)
		          {
		              fprintf(fichier1,"%f ",o[j].prix);
					  fprintf(fichier1,"%s ",o[j].Ville);
		              fprintf(fichier1,"%s ",o[j].adresse);
		              fprintf(fichier1,"%s ",o[j].superficie);
		              fprintf(fichier1,"%d ",o[j].nbreChambres);
		              fprintf(fichier1,"%d ",o[j].nbreToilettes);
		              fprintf(fichier1,"%d ",o[j].nbreBains);
		              fprintf(fichier1,"%d ",o[j].nbreCuis);
		              fprintf(fichier1,"%d\n",o[j].nbreEtage);
		          }
	          fclose(fichier1);
	          fclose(fichier);
	          remove("appartement.txt");
	          rename("Appartement1.txt","appartement.txt");
	      }

      else
      printf("echec,la liste des appartements est vide \n");
  }
       // *******************************************************************
       // les méthodes du terrain
TERRAIN* CreerTerain()
  {
    TERRAIN*p;
    p = (TERRAIN*)malloc(sizeof(TERRAIN));
    
    if(p == NULL)
	    {
	        printf("mémoire plien ");
	        exit(-1);
	    }
	else
		{
	
	        p->prec = NULL;
	        p->suiv = NULL;
	        return p;
		}

 }
      // *******************************************************************
TERRAIN* chargementTerrain(TERRAIN*l)
	{
	TERRAIN* p=NULL;
	TERRAIN* s=NULL;
	float price;
	char Vl[100];
	char suprf[50];
	char adr[100];
	char tp[200];
	
	FILE* f;
	f=fopen("terrain.txt","r");
		if(f==NULL)
			{
				printf("probleme de lecture du fichier terrain.txt");
			}
     	while(!feof(f))
			{
				fscanf(f,"%f %s %s %s %s" ,&price,Vl,adr,suprf,tp);
				p=CreerTerain();
					if(l==NULL)
						{
							strcpy(p->superficie,suprf);
							strcpy(p->Ville,Vl);
						    strcpy(p->adresse,adr);
							strcpy(p->type,tp);
							p->prix=price;
							l=p;
						}
			    	else
						{
						    s=l;
						    while(s->suiv!=NULL)
								{
						            s=s->suiv;
							    }
					
							strcpy(p->superficie,suprf);
							strcpy(p->Ville,Vl);
							strcpy(p->adresse,adr);
							strcpy(p->type,tp);
							p->prix=price;
							p->suiv=NULL;
							p->prec=s;
							s->suiv=p;
					
						}
	}
	fclose(f);
	return l;
	
	}

 // *******************************************************************
void EnregistrerTerain(TERRAIN*l,char*Nomfile)
	{
	FILE*F;
	TERRAIN*p;
	F=fopen(Nomfile,"a+");
		if(F==NULL)
			{
			    printf("%s inexistant\n",Nomfile);
			    exit(-1);
			}
		p=l;
		while(p)
			{
			    fprintf(F,"%f %s %s %s %s\n" ,p->prix,p->adresse,p->Ville,p->superficie,p->type);
			    p=p->suiv;
			}
	fclose(F);
	}

TERRAIN* SuppressionTerain(TERRAIN* l,TERRAIN A)
	{
	    TERRAIN* p=l,*y,*q;
		    if(l!=NULL)
			    {
			        if(strcmp(l->adresse,A.adresse)==0)
						{
				            y=l;
				            l=l->suiv;
				            l->prec=NULL;
				            free(y);
				            printf("\nsuppression reussite\n");
				            return l;
				        }
			    }
	
	    y=p;
	    p=p->suiv;   //case2
	    q=p->suiv;  //case3
	
	    while(p!=NULL && q!=NULL)
		    {
		         if( strcmp(l->adresse,A.adresse)==0)
			         {
			            y->suiv=q;
			            q->prec=y;
			            free(p);
			            printf("\nsuppression reussite\n");
			            return l;
			         }
		         else
			         {
			            y=p;
			            p=p->suiv;
			            q=p->suiv;
			         }
			
		
		     }
	
	     y->suiv=q;
	     free(p);
	     return l;
	
	}

     // *******************************************************************
TERRAIN*insererFinTerrain(TERRAIN*l,TERRAIN A)
	{
		TERRAIN*nem=NULL,*p;
		nem=CreerTerain();
		nem->prix=A.prix;
		strcpy(nem->Ville,A.Ville);
		strcpy(nem->superficie,A.superficie);
		strcpy(nem->adresse,A.adresse);
		strcpy(nem->type,A.type);
	
			if(l==NULL)
				{
			        l=nem;
				}
			else
			    {
			        p=l;
			        while(p->suiv!=NULL)
				        {
				            p=p->suiv;
				
				        }
			         p->suiv=nem;
			    }
	 return l;
	
	}

     // *******************************************************************
TERRAIN* removeDuplicatesTERRAIN(TERRAIN* head)
	{
	
	    TERRAIN* current = head;
	
	    TERRAIN* next_next;
	
	    if (current == NULL)
	    return head;
	
	    while (current->suiv != NULL)
	    {
	    if ( strcmp( current->adresse,current->suiv->adresse)==0 && current->prix==current->suiv->prix && strcmp( current->superficie,current->suiv->superficie)==0 && strcmp( current->Ville,current->suiv->Ville)==0 && strcmp( current->type,current->suiv->type )==0)
	    {
	        next_next = current->suiv->suiv;
	        free(current->suiv);
	        current->suiv = next_next;
	    }
	    else
	    {
	        current = current->suiv;
	    }
	    }
	
	    return head;
	}
 // *******************************************************************
TERRAIN* removeDuplicatesTERRAIN_Ville_Version(TERRAIN* head)
	{
	
	    TERRAIN* current = head;
	
	    TERRAIN* next_next;
	
	    if (current == NULL)
	    return head;
	
	    while (current->suiv != NULL)
		   {
		    if (  strcmp( current->Ville,current->suiv->Ville)==0 )
			    {
			        next_next = current->suiv->suiv;
			        free(current->suiv);
			        current->suiv = next_next;
			    }
	       else
			    {
			        current = current->suiv;
			    }
	      }
	
	    return head;
	}
		// *******************************************************************

TERRAIN *AjoutTerainDebut(TERRAIN a,TERRAIN *tete)
  {
      TERRAIN *f;
      f = CreerTerain();
      f->prix = a.prix;
      strcpy(f->Ville,a.Ville);
      strcpy(f->adresse,a.adresse);
      strcpy(f->superficie,a.superficie);
      strcpy(f->type,a.type);

      if(tete == NULL)
		  {
	          tete = f;
		  }

      else
	      {
	          f->suiv = tete;
	          tete->prec = f;
	          tete = f;
	      }
      return tete;
  }
          // *******************************************************************
void AfficherTerain(TERRAIN *tete)
  {
      TERRAIN *s = tete;

      while(s!=NULL)
	      {
	          printf("******************************\n");
	          printf("                               \n");
	          printf("Prix : %f\n",s->prix);
	          printf("la ville : %s\n",s->Ville);
	          printf("l'adresse :  %s\n",s->adresse);
	          printf("Superficie : %s\n",s->superficie);
	          printf("TypeTerain: %s\n",s->type);
	         printf("                               \n");
	          s = s->suiv;
	      }

  }
      // *******************************************************************
void AjoutTerainFichier(TERRAIN *tete)
  {
      FILE *fichier;
      TERRAIN*b=tete;
      fichier=fopen("terrain.txt","w");
      if(fichier == NULL)
        printf("ouverture echouer");
      else
	      {
	          while(b!=NULL)
		          {
		              fprintf(fichier,"\n%f %s %s %s %s",b->prix,b->Ville,b->adresse,b->superficie,b->type);
		              b=b->suiv;
		          }
	          fclose(fichier);
	      }
  }
      // *******************************************************************
void ModifierTerrain()
  {
      FILE *fichier;
      FILE *fichier1;
      TERRAIN *o=NULL;
      int NBC =0;
      int i=0;
      int j;
      char c;
      int modifier=4;


      fichier = fopen("terrain.txt","r");
      if(fichier != NULL)
	      {
	             fichier1 = fopen("Terrain1.txt","a");
	             while(!feof(fichier))
		             {
		              o=realloc(o, (NBC+1)*sizeof(TERRAIN));
		              fscanf(fichier,"%f",&o[NBC].prix);
		              fscanf(fichier,"%s",o[NBC].Ville);
		              fscanf(fichier,"%s",o[NBC].adresse);
		              fscanf(fichier,"%s",o[NBC].superficie);
		              fscanf(fichier,"%s",o[NBC].type);
		              NBC++;
		             }
	          while(i<NBC-1 && modifier!=3)
	          {
				   puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				   puts("                                         voila les ancienne informations ");
				   puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		           puts("************************************************************************************************************************");
			       printf("Prix:%f\n",o[i].prix);
			       printf("la ville : %s\n",o[i].Ville);
			       printf("L'adresse':%s \n",o[i].adresse);
			       printf("Superficie : %s\n",o[i].superficie);
			       printf("TypeTerrain: %s\n",o[i].type);
			       puts("************************************************************************************************************************");
			       printf("est-ce que le terrain que vous voulez modifier ?\n");
			
					puts("si oui  <<<<<< tapez 1>>>>>>      ");
					puts("si non  <<<<<< tapez 2>>>>>> pour passer au suivant       ");
			
			            scanf("%d",&modifier);
			            switch(modifier)
			            {
			                 case 1:
						       puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
							   puts("                                         voila les ancienne informations ");
							   puts("                      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
					           puts("************************************************************************************************************************");
						                        printf("tapez le nouveau prix du terrain                      \t: ==> ");
						                        scanf("%f",&o[i].prix);
						                        printf("tapez le nouveau nom de la ville du terrain           \t: ==> ");
						                        scanf("%s",o[i].Ville);
						                        printf("tapez la nouvelle adresse du terrain                  \t: ==> ");
						                        scanf("%s",o[i].adresse);
						                        printf("Donner la nouvelle superficie du terrain              \t: ==> ");
						                        scanf("%s",o[i].superficie);
						                        printf("Donner le nouveau Type du Terrain                     \t: ==> ");
						                        scanf("%s",o[i].type);
						                       i++;
			                       break;
			                 case 2: i++;
			                         break;
			                 case 3: printf("fin des modification\n");
			                         break;
			
			                default : printf("ce numero n'existe pas\n");
			                        break;
			            }
			
			          }
			          printf("             \n");
			          rewind(fichier);
			          if((c=fgetc(fichier))!= EOF)
			          printf("*****************Fin Modification*****************\n");
			          else
			          printf("il n y a aucunne donnée sur les terrains pour les modifier\n");
			          
			          for( j=0;j<NBC-1;j++)
				          {   
						      fprintf(fichier1,"%f ",o[j].prix);
				              fprintf(fichier1,"%s ",o[j].Ville);
				              fprintf(fichier1,"%s ",o[j].adresse);
				              fprintf(fichier1,"%s ",o[j].superficie);
				              fprintf(fichier1,"%s\n",o[j].type);
				          }
			          fclose(fichier1);
			          fclose(fichier);
			          remove("terrain.txt");
			          rename("Terrain1.txt","terrain.txt");
			      }

      else
      printf("l'ouverture a echouer car la liste des terrains est vide  \n");
  }
      // *******************************************************************
void afficherAPPARTEMENT(APPARTEMENT*l)
	{
     	APPARTEMENT*p=l;
		while(p!=NULL)
			{
				printf("prix:%f\nville:%s\nadresse:%s\nsuperficie:%s\nNumero Etage:%d\nNombre Cuisine:%d\nNombre Bains:%d\nNombre Chambres:%d\nNombre Toilettes:%d" ,p->prix,p->Ville,p->adresse,p->superficie,p->nbreEtage,p->nbreCuis,p->nbreBains,p->nbreChambres,p->nbreToilettes);
				printf("\n                     +++++++++++++++++++++                  \n");
				p=p->suiv;
			}
	}
   // *******************************************************************
void afficherMAISON(MAISON*l)
	{
		
		MAISON*p=l;
		while(p!=NULL)
			{
				printf("prix:%f\nville:%s\nadresse:%s\nsuperficie:%s\nNombre Etage:%d\nNombre Cuisine:%d\nNombre Bains:%d\nNombre Chambres:%d\nNombre Toilettes:%d" ,p->prix,p->Ville,p->adresse,p->superficie,p->nbreEtage,p->nbreCuis,p->nbreBains,p->nbreChambres,p->nbreToilettes);
				printf("\n                     +++++++++++++++++++++                  \n");
				
				p=p->suiv;
	    	}
	}

      // *******************************************************************
void afficherTERRAIN(TERRAIN*l)
	{
	TERRAIN*p=l;
	while(p!=NULL)
		{
			printf("prix:%f\nAdresse:%s\nVille:%s\nSuperficie:%s\nType:%s" ,p->prix,p->adresse,p->Ville,p->superficie,p->type);
			printf("\n                     +++++++++++++++++++++                  \n");
			p=p->suiv;
		}
	}

        // *******************************************************************
void afficherVILLA(VILLA*l)
	{
	    VILLA*p=l;
		while(p->suiv!=NULL)
			{
				printf("prix:%f\nville:%s\nadresse:%s\nsuperficie:%s\nNombre Etage:%d\nNombre Cuisine:%d\nNombre Bains:%d\nNombre Chambres:%d\nNombre Toilettes:%d" ,p->prix,p->Ville,p->adresse,p->superficie,p->nbreEtage,p->nbreCuis,p->nbreBains,p->nbreChambres,p->nbreToilettes);
				printf("\n                     ++++++++++++++++++++++                 \n");
				p=p->suiv;
			}
	}

         // *******************************************************************
APPARTEMENT* CreerAPPARTEMENT2()
	{
	    APPARTEMENT*p;
	    p = (APPARTEMENT*)malloc(sizeof(APPARTEMENT));
	    
		    if(p == NULL)
		       {
			        printf("mémoire plien ");
			        exit(-1);
			    }
		
	        else
				{
			
			        p->prec = NULL;
			        p->suiv = NULL;
			        return p;
				}
	}
	    // *******************************************************************
APPARTEMENT* chargementAPPARTEMENT_Ver_Sup(APPARTEMENT*l)
	{
	
		APPARTEMENT* p=NULL;
		APPARTEMENT* s=NULL;
		float prix=0;
		char Vl[100];
		char suprf[50];
		char adr[100];
		int nE=0;
		int nC=0;
		int nB=0;
		int nCham=0;
		int nToil=0;
	
		FILE* f;
		f=fopen("appartement.txt","r");
		while(!feof(f))
		
			{
				fscanf(f,"%f %s %s %s %d %d %d %d %d",&prix,Vl,adr,suprf,&nE,&nC,&nB,&nCham,&nToil);
				p=CreerAPPARTEMENT2();
			
				if(l==NULL)
					{
						strcpy(p->superficie,suprf);
						strcpy(p->Ville,Vl);
					    strcpy(p->adresse,adr);
						p->nbreBains=nB;
						p->nbreChambres=nCham;
						p->nbreCuis=nC;
						p->nbreEtage=nE;
						p->nbreToilettes=nToil;
						p->prix=prix;
						l=p;
					}
				else
					{
					    s=l;
					    while(s->suiv!=NULL)
							{
					            s=s->suiv;
						    }
						strcpy(p->superficie,suprf);
						strcpy(p->Ville,Vl);
						strcpy(p->adresse,adr);
						p->nbreBains=nB;
						p->nbreChambres=nCham;
						p->nbreCuis=nC;
						p->nbreEtage=nE;
						p->nbreToilettes=nToil;
						p->prix=prix;
						p->suiv=NULL;
						p->prec=s;
						s->suiv=p;
				
					}
			}
		fclose(f);
		return l;
		
	}
      // *******************************************************************
void SAVETERRAIN(TERRAIN*l,char*Nomfile)
	{
		FILE*F;
		TERRAIN*p;
		F=fopen(Nomfile,"w");
			if(F==NULL)
				{
				    printf("%s inexistant\n",Nomfile);
				    exit(-1);
				}
	    p=l;
		while(p)
				{
				    fprintf(F,"%f %s %s %s %s\n" ,p->prix,p->adresse,p->Ville,p->superficie,p->type);
				    p=p->suiv;
				}
		fclose(F);
	}
        // *******************************************************************
void SAVEME(TERRAIN*l,char*Nomfile)
	{
		FILE*F;
		TERRAIN*p;
		F=fopen(Nomfile,"w");
		if(F==NULL)
			{
			    printf("%s inexistant\n",Nomfile);
			    exit(-1);
			}
		p=l;
		while(p)
			{
			    fprintf(F,"%f %s %s %s %s\n" ,p->prix,p->adresse,p->Ville,p->superficie,p->type);
			    p=p->suiv;
			}
		fclose(F);
	}
	  // *******************************************************************
 void AffichermaisonBis(MAISON*tete)
  {
     MAISON *s = tete;

      while(s!=NULL)
      {
          printf("******************************\n");
          printf("                               \n");
          printf("Prix : %f\n",s->prix);
          printf("la ville : %s\n",s->Ville);
          printf("l'adresse: %s \n",s->adresse);
          printf("superficies : %s\n",s->superficie);
          printf("Nombre de chambres : %d\n",s->nbreChambres);
          printf("Nombre de Bains : %d\n",s->nbreBains);
          printf("Nombre de cuisines : %d\n",s->nbreCuis);
          printf("Nombre de Toilettes : %d\n",s->nbreToilettes);
          printf("Nombre Etages: %d\n",s->nbreEtage);
          printf("                               \n");
          s = s->suiv;
      }

  }


