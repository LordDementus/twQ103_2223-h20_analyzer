#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define PARAMETROS 50
#define TAM_Datos 100

struct Tdatos{
	char parametros[50];
	float ph;
	int conductividad;
	int turbidez;
	int coliformes;
};

struct Tfichero{
	int anio;
	int mes;
	char lugar[50];
};

int main(){
	
	int opcion,dato,i,j,n;
	char nomArchivo[50];
	struct Tdatos datos[TAM_Datos];
	struct Tfichero nomFichero;
	FILE * datosin;
	FILE * datosout;
	
	
	printf("Bienvenido al menu de opciones de H20_ANALYZER \n\n");
	printf("Escoja una de las siguientes opciones:\n");
	printf(" Opcion 1): Comparar datos\n Opcion 2): Crear fichero de datos \n Opcion 3): Sacar datos de una fuente\n Opcion 4): Salir \n");
	scanf("%d", &opcion);
  		switch(opcion){
                case 1: do{
					printf("SELECCIONE EL DATO A COMPARAR:\n 1:pH\n 2:conductividad\n 3:turbidez\n 4:coliformes\n"); 
					scanf("%d", &dato); 
						}while (dato<1 || dato>4); 
						
						switch(dato){
							case 1: 
								break;
							case 2:
								break;
							case 3:
								break;
							case 4: 
								break;
							default : printf("Opcion desconocida\n");
					}	
						 break;
						 
                case 2 : 
				
				printf("INDIQUE A CONTINUACION LOS DATOS DEL FICHERO \n");
                		printf("Introduzca los cuatro numeros del anio del estudio:\n");
						scanf("%d", &nomFichero.anio);

						printf("Introduzca el mes (01-12):\n");
						scanf("%d", &nomFichero.mes);

						printf("Introduzca el nombre del lugar en minusculas empezando con mayuscula:\n");
						scanf("%s", &nomFichero.lugar);
	
						sprintf(nomArchivo, "%d%d_%s.txt",nomFichero.anio,nomFichero.mes,nomFichero.lugar);
						
						datosin= fopen(nomArchivo,"w");
						if (datosin== NULL){
						printf("\nERROR AL ABRIR EL ARCHIVO\n");
						return 1;
						}else{	printf("\nArchivo creado con exito\n8");
						}
						printf("Introduzca el numero de fuentes de su estudio:\n");
    					scanf("%d", &n);
						fprintf(datosin,"Parametros\t\tpH\t\tConductividad\t\tTurbidez\t\tColiformes\n");
						for(i=0;i<n;i++){
								printf("introduzca el PH de la fuente%d\n",i+1);
								scanf("%f",&datos[i].ph);
								printf("Introduzca la conductividad %d\n",i+1);
								scanf("%d",&datos[i].conductividad);
								printf("Introduzca la turbidez%d\n",i+1);
								scanf("%d",&datos[i].turbidez);
								printf("Introduzca los coliformes%d\n",i+1);
								scanf("%d",&datos[i].coliformes);
							fprintf(datosin,"fuente_%d\t\t%f\t\t%d\t\t%d\t\t%d\n",i+1,datos[i].ph,datos[i].conductividad,datos[i].turbidez,datos[i].coliformes);
							}
						fclose(datosin);
                       break;
                       
                case 3 : printf("Opcion 3\n");
                    	break;
                case 4 : printf("______Hasta la proxima_____\n");
                        return 0;
                default : printf("Opcion desconocida\n");
    }
 	


	
return 0;
}

    
