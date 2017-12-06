/*
 ============================================================================
 Name        : exer.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	char nom[21];
	float ds;
	float exa;
	float Moy;
}Etudiant;
void saisie(Etudiant classe[],int n);
void CalculeMoy(Etudiant classe[],int n);
float MoyClasse(Etudiant classe[],int n);
void ResClasse(Etudiant classe[],int n);
void ResEtudiant(Etudiant classe[],int n,char nom[]);
int menu();

int main(void) {
Etudiant classe[30];
int choix,n=0;
char nom[21];
setbuf(stdout, NULL);
setbuf(stdin, NULL);
while(1){
	choix=menu();
	switch (choix){
	case 1 :
		do{
		printf("\ntaper nbr Etudiant ");
		scanf("%d",&n);
		}while((n<0)&&(n>31));
		saisie(classe,n);
		break;
	case 2 :
		CalculeMoy(classe,n);
		break;
	case 3 :
		printf("\nla moy est : %f",MoyClasse(classe,n));
		break;
	case 4:
		printf("\ntaper le nom de la Etudiant");
	    scanf("%s",nom);
	    ResEtudiant(classe,n,nom);break;
	case 5:
		ResClasse(classe,n);
		break;
	case 6:
		printf("\n:)");
	}
	if(choix==6)
		break;
}
}
void saisie(Etudiant classe[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("entrer %d etudiant",i+1);
		scanf("%s",&classe[i].nom);
		do{
			printf("taper note Ds de la %d etudiant",i+1);
			scanf("%f",&classe[i].ds);
		}while((classe[i].ds<0)&&(classe[i].ds>20));
		do{
					printf("taper note exame de la %d etudiant",i+1);
					scanf("%f",&classe[i].exa);
				}while((classe[i].exa<0)&&(classe[i].exa>20));

	}

}

void CalculeMoy(Etudiant classe[],int n){
	int i;
	float Moy;
	if(n==0)
		printf("\nsaisir les etudiant");
	else
	for(i=0;i<n;i++)
		classe[i].Moy=classe[i].exa*0.8+classe[i].ds*0.2;


}
float MoyClasse(Etudiant classe[],int n){
	int i;
	float s=0;
	if(n==0)
			printf("\nsaisir les etudiant");
		else
	for(i=0;i<n;i++)
		s+=classe[i].Moy;

	return s/n;

}
void ResClasse(Etudiant classe[],int n){
	int i;
	if(n==0)
			printf("\nsaisir les etudiant");
		else
	for(i=0;i<n;i++){
		printf("\nNom:%s",classe[i].nom);
		printf("\nMoy:%.3f",classe[i].Moy);
		printf("\nObservation :");
		if(classe[i].Moy<10)
			printf("Faible");
		else if((classe[i].Moy>=10)&&(classe[i].Moy<12))
			printf("Passable");
		else if((classe[i].Moy>=12)&&(classe[i].Moy<14))
			printf("Bien");
		else if(classe[i].Moy>=14)
			printf("Trés bien");
}
}

void ResEtudiant(Etudiant classe[],int n,char nom[]){
	int i=-1;
	if(n==0)
			printf("\nsaisir les etudiant");
		else{
	do{
		i++;
		if(classe[i].nom==nom){
			printf("\nNom:%s",classe[i].nom);
					printf( "Nom:%f",classe[i].Moy);
					printf("Observation :");
					if(classe[i].Moy<10)
						printf("est Faible");
					else if((classe[i].Moy>10)&&(classe[i].Moy<12))
						printf(" est Passable");
					else if((classe[i].Moy>12)&&(classe[i].Moy<14))
						printf(" est Bien");
					else
						printf(" est Trés bien");

		}

	}while((i!=n)&&(classe[i].nom==nom));
	if(i==n)
		printf("Etudiant n'est existe pas");
		}

}

int menu() {
	int c;
	do {

		printf("\n===========================================");
		printf("\n|         Gestion des moyennes            |");
		printf("\n===========================================");
		printf("\n|   1- Saisir la liste des etudiants      |");
		printf("\n|   2- Calculer la moyenne                |");
		printf("\n|   3- Calculer la moyenne de la classe   |");
		printf("\n|   4- Afficher le resultat d'un etudiant |");
		printf("\n|   5- Resultat de la classe              |");
		printf("\n|   6- Quitter                            |");
		printf("\n|_________________________________________|");

		printf("\n\nEntrer votre choix(1-6): ");
		scanf("%d", &c);

	} while (c < 1 || c > 6);
	return c;
}









