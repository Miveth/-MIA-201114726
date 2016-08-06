#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


//AQUI VAMOS A COLOCAR TODOS LOS ESTRUCT PARA LOS COMANDOS QUE SE UTILIZARAN EN CONSOLA


typedef struct{
int sise;
char unit[2];
char path[60];
char name[60];

}mkdisk;

typedef struct{
char path[60];

}rmdisk;

typedef struct{
int size;
int unit;
char path[60];
char type[2];
char fit[3];
char dele[70];
char name[60];
char add[3];

}fdisk;

typedef struct{
char path[70];
char name[60];

}mount;

typedef struct{
char idn[60];
}umount;


//variable para guardar y evaluar en el analizador
char cadena1[200];




//AQUI VA EL CODIGO DEL MAIN QUE EJECUTA EL PROGRAMA
int n2 = 3;

int main()
{

printf("\nPUEDE INICIAR INGRESE LOS COMANDOS QUE REQUIERA A CONTINUACION...\n");
scanf(" %[^\n]", cadena1);
printf(cadena1);

printf("esta es la cadena resultante: %s \n","fad");

char *dato;
mecaemal();
nimodo();

//dato = cadenas();
//strcpy(dato, minuscu(cadena1));
// = minuscu(*cadena1);

//prueba(n);
//printf("%d\n \n",funcion(n));


//analizador("hola");
mkdisk disco;
disco.sise = 1455;
strcpy(disco.name,"Migdalia");
//disco.path = "dasfsd";
//disco.unit = "k";
int n = 4;
char archivo[15] = "disco1.sdk";
FILE* f = fopen(archivo,"wb");
if(f ==NULL){
printf("error en el archivo\n");
//pausar();
}else{
//fwrite(&n,4,100,f);
fseek(f,1000000,SEEK_SET);
fputs("/0",f);
}
fclose(f);

FILE *fa = fopen(archivo,"r+b");
if(fa==NULL){
printf("error al escribir");

}else{
rewind(fa);
fwrite(&disco,sizeof(disco),1,fa);

}
fclose(fa);


FILE* fe = fopen(archivo,"rb");
printf("%s",disco.name);
//system("cls");
if(fe==NULL){
printf("otro grave error\n");

}else{
mkdisk disco2;
fread(&disco2,sizeof(disco),1,fe);

printf("%d   %s",disco2.sise,disco2.name);

fclose(fe);

}

//inicio del proyecto de archivos
//primera prueba
//iniciando a hacer el analizador

    return 0;
}




//AQUI VAN LOS PROCEDIMIENTOS NECESARIO PARA QUE EL PROGRAMA FUNCIONE


void prueba(int numero){
printf("esta es una prueba de procedimiento\n");
printf("%d\n",numero);
printf("%d\n",n2);
printf("ingrese un numero\n");

char entrada[50]="";
//puts("ingrese datos");
//gets(entrada);
//scanf("%s\n",entrada);
scanf(" %[^\n]", entrada);
printf(entrada);

/* char cadena [100];
  printf ("Introduzca una cadena: ");
  fgets (cadena, 100, stdin);
  printf ("La cadena leída es: %s \n", cadena);
//puts(entrada);*/

}


void analizador(char datos){
if(datos == "mkdisk"){
printf("es increhible si acepta en un if\n");
}else{
printf("q boba soy\n");
}

}

void mecaemal(){
int i;

for(i = 0; cadena1[i];i++)
cadena1[i]=tolower(cadena1[i]);

printf("JODER: %s\n",cadena1);
}


void nimodo(){

char cadena2[20]="";

for (int s=0;cadena1[s];s++){
printf("hola");
if(cadena1[s]!=" "){
cadena2 [s]= cadena1[s];
printf("%s\n",cadena2);
}else{
cadena2[0] = '/0';
printf("espacio");
strcpy( cadena2, "" );
free(cadena2);
}
}

analizador(cadena2);
//free(cadena2);//cadena2 = "                     ";

}
//AQUI VAN LAS FUNCIONES CORRESPONDIENTES PARA EL MAIN
 /*char* cadenas(){
//char

char* cadena3="";
int i;

for(i = 0; cadena1[i];i++)
cadena1[i]=tolower(cadena1[i]);

//strncpy(cadena1, c, sizbuffer);
//printf("%s\n",cadena1);

strcpy1(cadena3,cadena1);

return cadena3;
}
*/

/*bool mkdiskfunc(){
 bool respuesta =  false;

 return respuesta;

}*/

/*char *cadenas(){
char *cadena2="";
int i;
for (i=0;cadena1[i];i++){
if(cadena1[i]!= " "){
cadena2[i]=cadena1[i];
}else{
analizador(cadena2);
//cadena2 = "                     ";
}
}

return cadena2;
}
*/



int funcion(int numero){
int na= numero*n2;
return na;
}

