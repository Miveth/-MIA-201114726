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
int subt;
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
char unit[4];
char path[60];
char type[3];
char fit[6];
char dele[70];
char name[60];
int add;

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
fdisk fmdisk;


 char fech_hora[128];



char respuesta[3]="";

int main()

{

//char *ca;
/*char letra;
char cab2[4];
char cab[4] = "hola";
for(int i = 0; i<4; i++){

letra = cab[i];
//ca = cab[i]; creo q no funciona bien
cab2[i] = cab[i];
printf("%c \n",cab2[i]);
printf("%c \n",letra);
printf("%c \n",ca);
printf("%c \n",cab[i]);
}
printf("%c %s  ",letra,cab2);

*/

printf("\nPUEDE INICIAR INGRESE LOS COMANDOS QUE REQUIERA A CONTINUACION...\n");
while(strcmp(cadena1,"salir")!=0)
{

scanf(" %[^\n]", cadena1);
printf(cadena1);


char dato;
orden = 0;
indicativo = 0;
minusculas();
nimodo();

}
    return 0;
}




//AQUI VAN LOS PROCEDIMIENTOS NECESARIO PARA QUE EL PROGRAMA FUNCIONE


void minusculas(){
int i;


strcpy(disk.name,"");
strcpy(disk.unit,"");
strcpy(disk.name,"");

disk.sise = 0;

fmdisk.add = 0;
strcpy(fmdisk.name,"");
strcpy(fmdisk.dele,"");
strcpy(fmdisk.fit,"");
strcpy(fmdisk.path,"");
strcpy(fmdisk.unit,"");
strcpy(fmdisk.type,"");
strcpy(rdisk.path,"");

texto.subt =0;
texto.valuni = 0;

fmdisk.size = 0;
//if(cadena1[0]==1)

if(cadena1[0]==35 || cadena1==10 || cadena1 ==32){
    orden = 10;

    return; }
strcpy(cadecopia,cadena1);


for(i = 0; cadena1[i];i++)
cadena1[i]=tolower(cadena1[i]);




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
            }else if(token[0]==35){
            return;
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

    }else{
    cont = 0;
    }
 //  printf("ALFINAL DEL PRIMER WHILE %s \n",cadena1);

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
       printf("tiene continuacion....");
       cont = 1;
       break;
      }else if(cade1[i]=='\n' && i==strlen(cade1)-1){
       cade1 = cade4;
     //  printf("salto de linea encontrado y detectado yiji ");
       break;
      }
      /*else if(i == strlen(cade1)-1){
        orden = 0;
        }
       */ cade4[i]= cade1[i];


	}

	//printf("CADENA PRUEBA2 %s\n",cade1);

	  evorden(cade1);


}


void escribir(){
if(orden == 1){

    if(oblint(disk.sise)==0 || oblichar(disk.name)==0 || oblichar(disk.path)==0){
    printf("PARAMETRO CHAR OBLIGATORIO VACIO \n");

    return;
    }
  //  printf("/n este es el unit ahora /n %s",disk.unit);
    if(oblichar(disk.unit)==0){
//disk.unit = "m";
    printf("UNIT ES OPCIONAL SE PROPORCIONARA EL VALOR M \n");
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

//    disk.path = sincomas;

    buscpath();
    strcpy(rdisk.path,sincomas);
  //  scad(disk.path);
    carpeta(sincomas);
    strcpy(disk.path,sincomas);
    sincomas = "";
    scad(disk.name);
    strcpy(disk.name,sincomas);
    sincomas = "";
    crearchivo(disk.path,disk.name,disk.sise,texto.valuni);

}else if(orden == 2){

    buscpath();
    strcpy(rdisk.path,sincomas);
    if(oblichar(rdisk.path)==0){
    printf("PARAMETRO CHAR OBLIGATORIO VACIO \n");

    return;
    }

    strcpy(rdisk.path,sincomas);
    compdisco(rdisk.path);

}else if(orden == 3){

    if(oblichar(fmdisk.path)==0 || oblint(fmdisk.size)==0 || oblichar(fmdisk.name)==0){
    printf("PARAMETRO CHAR OBLIGATORIO VACIO \n");

    return;
    }

     if(oblichar(fmdisk.unit)==0){
//disk.unit = "m";
    printf("UNIT ES OPCIONAL SE PROPORCIONARA EL VALOR k \n");
    strcpy(disk.unit,"k");
    texto.valuni = 1000;
    }else{
    texto.valuni = evaluarunidad(fmdisk.unit);
        if((texto.valuni)==0){
        return;
        }
    }
    if(oblichar(fmdisk.type)==0){
    printf("TYPE DEFAULT P \n");
    strcpy(fmdisk.type,"p");

    }else{
    if(evaluartype(fmdisk.type)==0){
    return;}
    }
    if(oblichar(fmdisk.fit)==0){
    printf("FIT DEFAULT WF \n");
    strcpy(fmdisk.type,"wf");
    }else{
    if(evaluarfit(fmdisk.fit)==0){
    return;
    }
    }
    if(oblichar(fmdisk.dele)==0){
    }else{
    if(evaluardele(fmdisk.dele)==0){
    return;
    }
    }

particiones();


}else if(orden == 6){
    if(oblichar(exec)==0){
    return;
    }
    buscpath();
    strcpy(exec,sincomas);
    leerscript(exec);
}
orden = 0;


}

void particiones(){
printf("entre a particiones");
int total =  fmdisk.size*texto.valuni ;
buscpath();
strcpy(fmdisk.path,sincomas);
evarchivo(fmdisk.path);
int totd = tambr(fmdisk.path);
int totp = mbrN.part1.part_size+mbrN.part2.part_size+mbrN.part3.part_size+mbrN.part4.part_size;
int totdi=totd - totp;

if(fmdisk.add == 0){
}
//crear particion
if(totdi < fmdisk.size){
}

}

int evarchivo(char *path){
struct stat st = {0};
char info[500]="";
 strcat(info,path);

 char *ret;
   ret = strchr(path, '.');
   if(ret ==NULL){
   printf("LA EXTENSION ES INCORRECTA (.dsk) \n");
   return 0;
   }

   if(strcmp(ret,".dsk")==0){
  // printf("EXTENSION CORRECTA");
   }else{
   printf("LA EXTENSION ES INCORRECTA,(.dsk) \n");
   return 0;
   }

    if (stat(info, &st) == -1) {
   printf("\n EL ARCHIVO NO EXISTE \n");
    return 0;
}else{
printf("\n EL DISCO A SIDO ENCONTRADO CON EXITO!!! \n");
return 1;
}

}

int tambr(char *archivo){

int tam=0;
FILE* fe = fopen(archivo,"rb");
//printf("%s",disco.name);
//system("cls");
if(fe==NULL){
printf("otro grave error\n");

}else{
mbr mbrN2;
fread(&mbrN2,sizeof(mbrN2),1,fe);

printf("%d   %s   %d",mbrN2.mbr_tam,mbrN2.fecha_crea,mbrN2.mbr_asig);
tam = mbrN2.mbr_tam;
fclose(fe);
}

return tam;
}

int evaluardele(char *dele){
if(strcmp(dele,"fast")== 0 || strcmp(dele,"full")==0){
printf("TIPO DE ELIMINACION CORRECTO \n");
return 1;
}

printf("TIPO DE ELIMINACION INCORRECTO \n");
orden = 0;
indicativo = 0;
return 0;


}
int evaluarfit(char *fit){
printf("ESte es el fit");
if(strcmp(fit,"bf")== 0 || strcmp(fit,"wf")==0 || strcmp(fit,"ff")==0){
printf("TIPO DE AJUSTE CORRECTO \n");
return 1;
}

printf("TIPO DE AJUSTE INCORRECTO \n");
orden = 0;
indicativo = 0;
return 0;


}
int evaluartype(char *tipo){
if(strcmp(tipo,"p")== 0 || strcmp(tipo,"l")==0 || strcmp(tipo,"e")==0){
printf("TIPO DE PARTICION CORRECTA \n");
return 1;
}

printf("TIPO DE PARTICION INCORRECTA \n");
orden = 0;
indicativo = 0;
return 0;

}
void buscpath(){

   char *token;
 //   printf("cadena original %s \n",cadena1);
   /* get the first token */
//   token = strtok(cadena1," ");
  // printf("cadena de copia %s ",cadecopia);
            token=strtok(cadecopia,"\"");

    while (token !=NULL){
    if(token[0]==47){
    sincomas = token;
 //  printf("este es sin comas %s ",sincomas);
    return;
    }
 //   printf("este es sin comas %s ",token);
    token=strtok(NULL,"\"");
    }

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
//   printf("PARAMETROS DE BUSQUEDA CORRECTOS");
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

if(strcmp(respuesta,"s")==0 || strcmp(respuesta,"S")==0){
int valor =  remove(path);
if(valor ==0){
printf("DISCO REMOVIDO CON EXITO \n");
}else{printf("NO SE PUDO ELIMINAR, VUELVA A INTENTARLO \n");}
}
orden = 10;

return;
}


}

void crearchivo(char *path, char *nombre, int tam, int unid){

struct stat st = {0};

char info[500]="";


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
   return;

}else{
int tot = tam*unid;
texto.subt = tam*unid;
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
   return;

}else{
rewind(fa);
/*char *adentro = ("mkdisk -size:: %d");
printf(adentro);*/
fwrite(&mbrN,sizeof(mbrN),1,fa);

}
fclose(fa);

/*

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
int aument = 0;

void irmbr(){
if(orden ==1){

mbrN.mbr_tam =  texto.subt;
optHora();
strcpy(mbrN.fecha_crea,fech_hora);
mbrN.mbr_asig = aument;
aument++;


strcpy(mbrN.part1.part_name,"PRIMARIA 1");
strcpy(mbrN.part1.part_status,"OFF");
strcpy(mbrN.part1.part_type,"P");
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
strcat(direccion,"\'");

if (stat(carp, &st) == -1) {
printf("Se crearan nuevos directorios, CARPETA DEL PATH NO ENCONTRADA  %s\n ",carp);
  strcat(direccion,carp);
  strcat(direccion,"\'");
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
}
if(strcmp(parametro,"b")==0 && orden == 3){
return 1;
}
else{
return 0;}
}


int oblichar(char *parametro){
if(strcmp(parametro,"")==0){
return 0;
}
return 1;
}
int oblint(int parametro){
if(parametro<1){
printf("PARAMETRO ENTERO OBLIGATORIO VACIO\n");
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
            }
            else if(orden == 10){
            return;}
            else{
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
//                printf("ESTA ES LA PRUEBA DE SIZE: %d \n",disk.sise);
              break;
                case 2:
               // disk.unit = token;
                strcpy(disk.unit,token);
  //              printf("prueba para el unit %s \n",disk.unit);
                break;
                case 3:
                strcpy(disk.path,token);
    //             printf("prueba para el path %s \n",disk.path);
               // disk.path = token;
                break;
                case 4:
                strcpy(disk.name,token);
      //           printf("prueba para el nombre %s \n",disk.name);
                //disk.name = token;
                break;
                default:
                printf("PUEDE QUE TENGA ALGUN ERROR, VERIFIQUE  \n");
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
             //    printf("prueba para el path %s \n",rdisk.path);

               }


}
void evfdisk(char *token){

            if(strcmp(token,"-size")==0 ){
             indicativo=1;
            }else if(strcmp(token,"+unit")==0){
                indicativo=2;
            } else if(strcmp(token,"-path")==0){
              indicativo=3;
            } else if(strcmp(token,"-name")==0){
                indicativo =4;
            } else if(strcmp(token,"+type")==0){
                indicativo =5;
            } else if(strcmp(token,"+fit")==0){
                indicativo =6;
            } else if(strcmp(token,"+delete")==0){
                indicativo =7;
            } else if(strcmp(token,"+add")==0){
                indicativo =8;
            }
             else {

             lineafinal(token);
                switch(indicativo){

                case 1:
                fmdisk.size= atoi(token);
                printf("ESTA ES LA PRUEBA DE SIZE: %d \n",fmdisk.size);

               // printf("el indicativo %d la cadena %s orden %d\n",indicativo,cadena1,orden);
                break;
                case 2:
               // disk.unit = token;
                strcpy(fmdisk.unit,token);
                printf("prueba para el unit %s \n",fmdisk.unit);
                break;
                case 3:
                strcpy(fmdisk.path,token);
                 printf("prueba para el path %s \n",fmdisk.path);
               // disk.path = token;
                break;
                case 4:
                strcpy(fmdisk.name,token);
                 printf("prueba para el nombre %s \n",fmdisk.name);
                //disk.name = token;
                break;
                case 5:
                strcpy(fmdisk.type,token);
                 printf("prueba para el type %s \n",fmdisk.type);
                //disk.name = token;
                break;
                case 6:
                strcpy(fmdisk.fit,token);
                 printf("prueba para el fit %s \n",fmdisk.fit);
                //disk.name = token;
                break;
                case 7:
                strcpy(fmdisk.dele,token);
                 printf("prueba para el dele %s \n",fmdisk.dele);
                //disk.name = token;
                break;
                case 8:
                fmdisk.add= atoi(token);
                 printf("prueba para el add %d \n",fmdisk.add);
                //disk.name = token;
                break;
                default:
                printf("GRAVE ERROR");
                }
            // printf("EL TOKEN DE SIZE%s\n",token);
            indicativo = 0;
             }


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
           //      printf("prueba para el path %s \n",exec);

               }


}



