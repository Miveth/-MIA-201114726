#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>



//AQUI VAMOS A COLOCAR TODOS LOS ESTRUCT PARA LOS COMANDOS QUE SE UTILIZARAN EN CONSOLA

typedef struct {
char tex[600];
int valuni;
}cadenita;

typedef struct{

int sise;
char unit[2];
char path[70];
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

cadenita texto;

//variable para guardar y evaluar en el analizador
//estas son variables globales a las que cualquir metodo o funcion podran ingresar
char cadena1[300];
   int orden=0;

int indicativo = 0;
int cont =0;
char *sincomas = "";

char cadecopia[300];


//AQUI VA EL CODIGO DEL MAIN QUE EJECUTA EL PROGRAMA
int n2 = 3;
mkdisk disk;

int main()
{
  //  int valor =  remove("prueba/prueba1.dsk");

printf("\nPUEDE INICIAR INGRESE LOS COMANDOS QUE REQUIERA A CONTINUACION...\n");
scanf(" %[^\n]", cadena1);
printf(cadena1);

printf("esta es la cadena resultante: %s \n","fad");

char dato;
minusculas();
nimodo();

//dato = cadenas(cadena1);
//strcpy(dato, minuscu(cadena1));
// = minuscu(*cadena1);

//prueba(n);
//printf("%d\n \n",funcion(n));


//analizador("hola");
mkdisk disco;
disco.sise = 1455;
strcpy(disco.name,"Migdalia");


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


/*void analizador(char datos){
if(datos == "mkdisk"){
printf("es increhible si acepta en un if\n");
}else{
printf("q boba soy\n");
}

}*/

void minusculas(){
int i;

strcpy(cadecopia,cadena1);


for(i = 0; cadena1[i];i++)
cadena1[i]=tolower(cadena1[i]);

printf("MINUSCULAS: %s\n",cadena1);
}

//aqui es donde empiezo el analizador

void nimodo(){

   char *token;
 //   printf("cadena original %s \n",cadena1);
   /* get the first token */
   token = strtok(cadena1," ");
  // printf("cadena original %s \n",cadena1);
   /* walk through other tokens */
   while( token != NULL )
   {
     // printf( "%s\n", token );

            if(strcmp(token,"mkdisk")==0){
            orden = 1;
         //   printf("cadena original %s \n",cadena1);
            }
            else if(strcmp(token,"rmdisk")==0){
            orden = 2;
            }
            else if(strcmp(token,"fdisk")==0){
            orden = 3;
            }
            else if(strcmp(token,"mount")==0){
            orden = 4;
            }
            else if(strcmp(token,"unmount")==0){
            orden = 5;
            }else
            {
            evparametros(token);
            }

        /*  if(token == "mkdisk"){
            printf("esta es una PRUEBA %s\n",token);
            }
*/
      token = strtok(NULL, " ");
   }

    if(cont ==0){
   // evcont();
   escribir();

    }
   printf("ALFINAL DEL PRIMER WHILE %s \n",cadena1);

}

void escribir(){
if(orden == 1){

if(oblint(disk.sise)==0 || oblichar(disk.name)==0 || oblichar(disk.path)==0){
return;
}
if(oblichar(disk.unit)==0){
//disk.unit = "m";
printf("PERO UNIT ES OPCIONAL SE PROPORCIONARA EL VALOR M \n");
strcpy(disk.unit,"m");
texto.valuni = 1000000;
}else{
texto.valuni = evaluarunidad(disk.unit);
if((texto.valuni)==0){
return;
}
}


printf(texto.tex);


printf("HOLA JAI %d \n",texto.valuni);
scad(disk.path);
carpeta(sincomas);
strcpy(disk.path,sincomas);
sincomas = "";
scad(disk.name);
strcpy(disk.name,sincomas);
sincomas = "";
crearchivo(disk.path,disk.name,disk.sise,texto.valuni);
//char *wa = cad("fMIG");
char descrip[600]="mkdisk -size::";
//  strcat(descrip,carp);

//strcat(descrip,disk.sise);
/*strcat(descrip," +unit  ::");
strcat(descrip,disk.unit);
strcat(descrip," -patxh::");
strcat(descrip,disk.path);
strcpy(texto.tex,descrip);
printf(descrip);
*/
char *pp = (char)disk.sise;
strcat(texto.tex,"\n mkdisk -size \n");
//printf();
printf(texto.tex);



}

}
void crearchivo(char *path, char *nombre, int tam, int unid){

struct stat st = {0};

char info[500]="";
int tot=0;

 strcat(info,path);
 strcat(info,nombre);
 printf("la info es %s",info);

 if (stat(info, &st) == -1) {
//direccion = copia;
printf("\n EL DISCO NO EXISTE AUN, SE CREARA UNO NUEVO \n");
printf("VALIDANDO EXTENCION \n");
char *ret;
   ret = strchr(nombre, '.');
   printf("LA EXTENSION ES: \n %s \n",ret);

   if(strcmp(ret,".dsk")==0){
   printf("LA EXTENSION ES CORRECTA :) ");
   }else{
   printf("LA EXTENSION ES INCORRECTA (.dsk), NO SE PUEDE CREAR EL DISCO \n");
   return;
   }

   //  val = mkdir("carpeta/",O  0700);
}else{
printf("\n EL DISCO YA EXISTE, IMPOSIBLE VOLVER A CREAR\n");
return;
}


FILE* f = fopen(info,"wb");
if(f ==NULL){
printf("error en el archivo\n");
}else{
tot = tam*unid;
//fwrite(&n,4,100,f);
fseek(f,tot,SEEK_SET);
fputs("/0",f);
}
fclose(f);


FILE *fa = fopen(info,"r+b");


if(fa==NULL){
printf("error al escribir");

}else{
rewind(fa);
/*char *adentro = ("mkdisk -size:: %d");
printf(adentro);*/
fwrite(&cadecopia,sizeof(cadecopia),1,fa);

}
fclose(fa);

/*
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

}*/
}
/*char *cad(char *dato){
char *prueba = "fsafa";
return prueba;
}*/
void scad(char *cad){
sincomas = "";
    sincomas=strtok(NULL,"\"");
            sincomas=strtok(cad,"\"");

printf("EL NUEVO PATH ES: %s \n",sincomas);

}
void carpeta(char *carp){
struct stat st = {0};
char direccion[300]  = "mkdir -p ";

if (stat(carp, &st) == -1) {
printf("Se crearan nuevos directorios, CARPETA DEL PATH NO ENCONTRADA  %s\n ",carp);
  strcat(direccion,carp);
  system(direccion);

}else{
printf("CARPETA EXISTEN, Se guardaran archivos");
}

/*int valor = mkdir(carp,  S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
if(valor == 0){
printf("Directorio creado con exito%d \n",valor);}
else{
printf("ERROR, NO SE PUEDE CREAR EL DIRECTORIO REVISA TU PATH %d",valor);

}*/
}

int evaluarunidad(char *parametro){

if(strcmp(parametro,"m")==0){

return 1000000;
}
if(strcmp(parametro,"k")==0){
return 1000;
}else{
return 0;}
}


int oblichar(char *parametro){
if(strcmp(parametro,"")==0){
printf("PARAMETRO OBLIGATORIO VACIO, NO SE PUEDE ESCRIBIR EL ARCHIVO\n");
return 0;
}
return 1;
}
int oblint(int parametro){
if(parametro<1){
printf("PARAMETRO OBLIGATORIO VACIO, NO SE PUEDE ESCRIBIR EL ARCHIVO\n");
return 0;
}
return 1;
}

/*void evcont(){
if(orden == 1){
    if(disk.sise !=NULL || disk.sise >0 ){
    if(strcmp(disk.path,NULL)==0){
    printf("FALTAN PARAMENTROS NO SE ENCONTRO PATH\n");
    break;
    }else{
    if(strcmp(disk.name,NULL)==0){
     printf("FALTAN PARAMENTROS NO SE ENCONTRO NOMBRE \n");
    break;
    }else{
    if(disk.unit==NULL){
    disk.unit = 'k';
    }
    }
    }
    }
}

}*/

void evparametros(char *tok){

char *cade="";
char *cade1="";
char cade2[100]="";
char cade4[200]="";
char *cade3="";
int c1 = 0;


    for(int i =0; i<strlen(tok);i++){
        if(tok[i]==':'){
        c1++;}
        if(c1==1){
            cade3 = cade2;
            break;
        }
        cade2[i]= tok[i];
    }
  //   printf("CADENA PRUEBA2 %s \n",cade3);
     evorden(cade3);
   // printf("que esta pasando");
c1=0;
     while (*tok != '\0') {

        if(c1==2){
		cade = tok;
		cade1 = cade;
       // printf("CADENA PRUEBA2 %s \n",cade);
        cade = " ";
        c1=0;
        }

		if (*tok == ':'){
		c1++;}
		tok++;
	}


	for(int i=0;i<strlen(cade1);i++){

	   if(cade1[i]=='\\' && i==strlen(cade1)-1){
       cade1 = cade4;
       printf("tiene continuacion");
       cont = 1;
       break;
      }
      /*else if(i == strlen(cade1)-1){
        orden = 0;
        }
       */ cade4[i]= cade1[i];


	}

	printf("CADENA PRUEBA2 %s\n",cade1);

	  evorden(cade1);


}

void evorden(char *token2){

            if(orden == 1){
                //evparametros(token);
            evmkdisk(token2);
            }
            else if(orden ==2){
            evrmdisk(token2);
            }
            else if(orden ==3){
            evfdisk(token2);
            }
            else if(orden ==4){
            evmount(token2);
            }
            else if(orden ==5){
            evunmount(token2);
            }else{
            printf("EL COMANDO INGRESADO NO EXISTE, VERIFICA ANTES DE VOLVER A INTENTAR \n");

            }

}

void evmkdisk(char *token){
//printf("estoy dentro de los mkdisk \n");
//evparametros(token);
            if(strcmp(token,"-size")==0){
             indicativo=1;
            // printf("EL TOKEN DE SIZE%s\n",token);

            }
            else if(strcmp(token,"+unit")==0){
            indicativo=2;

            }
             else if(strcmp(token,"-path")==0){
              indicativo=3;
            }
             else if(strcmp(token,"-name")==0){
                indicativo =4;
            }
             else {
             lineafinal(token);
                switch(indicativo){

                case 1:
                disk.sise= atoi(token);
                /*if(disk.sise==0){
                }*/
                printf("ESTA ES LA PRUEBA DE SIZE: %d \n",disk.sise);

               // printf("el indicativo %d la cadena %s orden %d\n",indicativo,cadena1,orden);
                break;
                case 2:
               // disk.unit = token;
                strcpy(disk.unit,token);
                printf("prueba para el unit %s \n",disk.unit);
                break;
                case 3:
                strcpy(disk.path,token);
                 printf("prueba para el path %s \n",disk.path);
               // disk.path = token;
                break;
                case 4:
                strcpy(disk.name,token);
                 printf("prueba para el nombre %s \n",disk.name);
                //disk.name = token;
                break;
                default:
                printf("GRAVE ERROR");
                }
            // printf("EL TOKEN DE SIZE%s\n",token);
            indicativo = 0;
             }

}
void lineafinal(){
}
void evrmdisk(char *token){

}
void evfdisk(char *token){
}
void evmount(char *token){
}
void evunmount(char *token){
}
//AQUI VAN LAS FUNCIONES CORRESPONDIENTES PARA EL MAIN
 char* cadenas(char cade[]){
//char

char* cadena3="";
int i;

for(i = 0; cade[i];i++)
cade[i]=tolower(cade[i]);

//strncpy(cadena1, c, sizbuffer);
//printf("%s\n",cadena1);
//strcpy1(&cadena3,cadena1);

return cadena1;
}





