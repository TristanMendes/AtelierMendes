#include <stdlib.h>
#include <stdio.h>

int int main(int argc, char const *argv[])
{
	int a; 
	int b,choix;
	printf("donner l'identifiant du prisonnier\n" );
	scanf("%d",&a);

	printf("entrer le numero du prisonnier\n");
	scanf("%d",&b);
do
{
  do
	{
		printf("menu\n");
		printf("1-afficher le background\n");
		printf("2-remplir la page du jeu type\n");
		printf("0-quitter\n");
		printf("faites votre choix\n");
		scanf("%d,&choix");
	}while(choix<0 || choix>2 );

	swicth(choix)
	{
		case 1:
		break;

		case 2:
		break;

		case 0:
		break;

	}
}while(choix!=0);
	
	return 0;
}