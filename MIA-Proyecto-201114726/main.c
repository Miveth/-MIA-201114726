#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int n2 = 3;

int main()
{
int n = 2;
//inicio del proyecto de archivos
//primera prueba
//iniciando a hacer el analizador

printf("PUEDE INICIAR INGRESE LOS COMANDOS QUE REQUIERA A CONTINUACION...\n");

prueba(n);
printf("%d\n \n",funcion(n));
char cadena[] = "esto es una Prueba AA";
int i;
for(i = 0; cadena[i];i++)
cadena[i]=tolower(cadena[i]);
printf("%s\n",cadena);

    printf("Hello MIA!\n");
    return 0;
}

void prueba(int numero){
printf("esta es una prueba de procedimiento\n");
printf("%d\n",numero);
printf("%d\n",n2);
}
int funcion(int numero){
int na= numero*n2;
return na;
}
