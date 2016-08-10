#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>



//AQUI VAMOS A COLOCAR TODOS LOS ESTRUCT PARA LOS COMANDOS QUE SE UTILIZARAN EN CONSOLA

typedef struct{
char part_status[20];
char part_type[5];
char part_fit[5];
int part_start;
int part_size;
char part_name[16];

}particion;

typedef struct{
int mbr_tam;
time_t tiempo;
char fecha_crea[128];
int mbr_asig;
//part1 particion;
particion part1;
particion part2;
particion part3;
particion part4;

}mbr;



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

char exec[200]="";

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

mbr mbrN;
mkdisk disk;
rmdisk rdisk;
char respuesta;

 char fech_hora[128];


int main()
{
  //
printf("\nPUEDE INICIAR INGRESE LOS COMANDOS QUE REQUIERA A CONTINUACION...\n");
while(strcmp(cadena1,"salir")!=0)
{

scanf(" %[^\n]", cadena1);
printf(cadena1);


char dato;
minusculas();
nimodo();

//inicio del proyecto de archivos
//primera prueba
//iniciando a hacer el analizador

}
    return 0;
}




//AQUI VAN LOS PROCEDIMIENTOS NECESARIO PARA QUE EL PROGRAMA FUNCIONE


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
            printf("orden 2\n");
            }
            else if(strcmp(token,"fdisk")==0){
            orden = 3;
            }
            else if(strcmp(token,"mount")==0){
            orden = 4;
            }
            else if(strcmp(token,"unmount")==0){
            orden = 5;
            }
            else if(strcmp(token,"exec")==0){
            orden = 6;
            }
            else if(strcmp(token,"salir")==0){
            orden = 0;
            }else if(orden == 10){
            return;}
            else{
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
//printf("HOLA JAI %d \n",texto.valuni);
    scad(disk.path);
    carpeta(sincomas);
    strcpy(disk.path,sincomas);
    sincomas = "";
    scad(disk.name);
    strcpy(disk.name,sincomas);
    sincomas = "";
    crearchivo(disk.path,disk.name,disk.sise,texto.valuni);
/*
char *pp = (char)disk.sise;
strcat(texto.tex,"\n mkdisk -size \n");
//printf();
printf(texto.tex);*/

}else if(orden == 2){

    if(oblichar(rdisk.path)==0){
    return;
    }
    scad(rdisk.path);
    strcpy(rdisk.path,sincomas);
    compdisco(rdisk.path);

}else if(orden == 6){
    if(oblichar(exec)==0){
    return;
    }
    scad(exec);
    strcpy(exec,sincomas);
    leerscript(exec);
}

orden = 0;


}
void compdisco(char *path){

struct stat st = {0};
char info[500]="";
 strcat(info,path);

 char *ret;
   ret = strchr(path, '.');
   //printf("LA EXTENSION ES: \n %s \n",ret);
   if(ret ==NULL){
   printf("LA EXTENSION ES INCORRECTA (.dsk), NO SE PUEDE ELIMINAR ARCHIVO SIN EXTENSION \n");
   return;
   }

   if(strcmp(ret,".dsk")==0){
   printf("PARAMETROS DE BUSQUEDA CORRECTOS");
   }else{
   printf("LA EXTENSION ES INCORRECTA, EXTENSION VALIDA PARA ELIMINAR (.dsk) \n");
   return;
   }



    if (stat(info, &st) == -1) {
//direccion = copia;
    printf("\n EL ARCHIVO NO EXISTE \n");

//try{
/*}catch(exception e){
printf("ERROR, SU ARCHIVO NO TIENE EXTENSION\n" );
return;
}*/
   //  val = mkdir("carpeta/",O  0700);
}else{
printf("\n EL DISCO EXISTENTE, ESTA SEGURO DE ELIMINAR? S\N \n");

scanf(" %[^\n]", respuesta);

respuesta=tolower(respuesta);

printf(respuesta);
int valor =  remove("prueba/prueba1.dsk");
if(valor ==0){
printf("DISCO REMOVIDO CON EXITO \n");
}else{printf("NO SE PUDO ELIMINAR, VUELVA A INTENTARLO \n");}


//return;
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
//try{
char *ret;
   ret = strchr(nombre, '.');
   //printf("LA EXTENSION ES: \n %s \n",ret);
   if(ret ==NULL){
   printf("LA EXTENSION ES INCORRECTA (.dsk), NO SE PUEDE CREAR EL DISCO \n");
   return;
   }

   if(strcmp(ret,".dsk")==0){
   printf("LA EXTENSION ES CORRECTA :) ");
   }else{
   printf("LA EXTENSION ES INCORRECTA (.dsk), NO SE PUEDE CREAR EL DISCO \n");
   return;
   }
/*}catch(exception e){
printf("ERROR, SU ARCHIVO NO TIENE EXTENSION\n" );
return;
}*/
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

irmbr();
//llenarchivo();


FILE *fa = fopen(info,"r+b");


if(fa==NULL){
printf("error al escribir");

}else{
rewind(fa);
/*char *adentro = ("mkdisk -size:: %d");
printf(adentro);*/
fwrite(&mbrN,sizeof(mbrN),1,fa);

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

void leerscript(char *path){

struct stat st = {0};
char info[300]="";
 strcat(info,path);

    if (stat(info, &st) == -1) {

    printf("\n EL ARCHIVO NO EXISTE \n");

}else{

//leer script
FILE *script;

 	//char linea[200];

 	script = fopen(path,"r");

 	if (script == NULL)
 		exit(1);

    printf("\n ARCHIVO ENCONTRADO... \n");
 	int i = 0;
 	while (feof(script) == 0)
 	{
 		fgets(cadena1,200,script);
 		printf("linea %d :  ",i);
 		i++;
 		printf("%s",cadena1);
        orden = 0;
        indicativo = 0;

        minusculas();
        nimodo();

 	}
       // system("PAUSE");

        fclose(script);


//return;
}



}

void irmbr(){
if(orden ==1){

mbrN.mbr_tam =  disk.sise;
optHora();
strcpy(mbrN.fecha_crea,fech_hora);
mbrN.mbr_asig = 0;

strcpy(mbrN.part1.part_name,"PRIMARIA 1");
strcpy(mbrN.part1.part_status,"OFF");
strcpy(mbrN.part2.part_name,"PRIMARIA 2");
strcpy(mbrN.part2.part_status,"OFF");
strcpy(mbrN.part3.part_name,"PRIMARIA 3");
strcpy(mbrN.part3.part_status,"OFF");
strcpy(mbrN.part4.part_name,"EXTENDIDA");
strcpy(mbrN.part4.part_status,"OFF");


}

}

void optHora(){

        time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);

        strftime(fech_hora,128,"%d/%m/%y %H:%M:%S",tlocal);
        printf("%s\n",fech_hora);

}


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
            }
            else if(orden == 6){
            evexec(token2);
            }else{
            printf("EL COMANDO INGRESADO NO EXISTE, VERIFICA ANTES DE VOLVER A INTENTAR \n");
            orden = 10;

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

printf("estoy en el evrmdisk \n");
                if(strcmp(token,"-path")==0){
                    indicativo=1;
               }else if(indicativo == 1){

               strcpy(rdisk.path,token);
                 printf("prueba para el path %s \n",rdisk.path);

               }


}
void evfdisk(char *token){
}
void evmount(char *token){
}
void evunmount(char *token){
}

void evexec(char *token){

                printf("EVALUANDO EL SCRIP INGRESADO\n");
                if(strcmp(token,"-path")==0){
                    indicativo=1;
               }else if(indicativo == 1){

                 strcpy(exec,token);
                 printf("prueba para el path %s \n",exec);

               }


}






