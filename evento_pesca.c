#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "evento_pesca.h"

#define MAX_ESPECIE 100
#define MAX_COLOR 50
#define FORMATO_LECTURA "%[^;];%i;%i;%[^\n]\n"
#define FORMATO_ESCRITURA "%s:%i;%i;%s\n"

/*
* Función que dado un archivo carga los pokémon que viven en el arrecife
* reservando la memoria necesaria para el mismo. Se debe intentar leer la mayor
* cantidad posible de registros del archivo. Al encontrar el primer registro
* erróneo (o al llegar al final del archivo) se deben finalizar la lectura y
* crear el arrecife con los pokémon leídos exitosamente. En caso de no
* encontrar ningún registro con el formato correcto , se debe devolver error.
* Devuelve un puntero a un arrecife válido o NULL en caso de error.
*/


arrecife_t* crear_arrecife(const char* ruta_archivo){
  arrecife_t* arrecife = malloc(sizeof(arrecife_t));
  if(arrecife == NULL) return NULL;
  pokemon_t **pokemon;
  arrecife->pokemon = (pokemon_t*)malloc(sizeof(pokemon_t));
  pokemon = &arrecife->pokemon;
  (*arrecife).cantidad_pokemon = 0;
  
  int i=0;

  char tipo_de_archivo[3];
  size_t largo_nombre_archivo = strlen(ruta_archivo);
  tipo_de_archivo[0] = ruta_archivo[largo_nombre_archivo -3];
  tipo_de_archivo[1] = ruta_archivo[largo_nombre_archivo -2];
  tipo_de_archivo[2] = ruta_archivo[largo_nombre_archivo -1];
  if (strcmp(tipo_de_archivo, "txt") == 0){
    FILE* archivo_pokemones_arrecife = fopen(ruta_archivo,"r");
    if(!archivo_pokemones_arrecife){
      printf("No se pudo abrir el archivo de pokemones que viven en el arrecife.\n");
      return NULL;
    }

    pokemon_t pokemon_leido;
    int leidos = fscanf(archivo_pokemones_arrecife, FORMATO_LECTURA, pokemon_leido.especie, &(pokemon_leido.velocidad), &(pokemon_leido.peso), pokemon_leido.color);
    if(!leidos){
      printf("No se pudo leer ninguna linea.\n");
      exit(0);
      return NULL;
    };
    while(leidos != EOF && !ferror(archivo_pokemones_arrecife)){
      **(pokemon+i) = pokemon_leido;
      i += 1;
      (*arrecife).cantidad_pokemon += 1;
      pokemon = realloc(pokemon,sizeof(pokemon_t)*((size_t)(*arrecife).cantidad_pokemon +1));
      if(pokemon == NULL) return NULL;
      leidos = fscanf( archivo_pokemones_arrecife, FORMATO_LECTURA, pokemon_leido.especie, &(pokemon_leido.velocidad), &(pokemon_leido.peso), pokemon_leido.color);
    }
    fclose(archivo_pokemones_arrecife);

  }else{
    return NULL;
  }

  
  return arrecife;
}

 /*
 * Función que crea un acuario vacío reservando la memoria necesaria para el mismo.
 * Devuelve el acuario o NULL en caso de error.
 */

acuario_t* crear_acuario(){
  acuario_t* acuario = malloc(sizeof(acuario_t));
  if(acuario == NULL){
    return NULL;
  } 
  acuario->pokemon = malloc(sizeof(pokemon_t));
  (*acuario).cantidad_pokemon = 0;
  if (!acuario) return NULL;
  return acuario;
}

 /*
 * Función que deberá sacar del arrecife a todos los pokémon que satisfagan la
 * condición dada por el puntero a función (que devuelvan true) y trasladarlos
 * hacia el acuario. El parámetro cant_seleccion especifica la cantidad máxima
 * de pokémon que serán trasladados. En caso de que haya menos pokémon trasladables en el
 * arrecife que los pedidos , no se deberá mover ninguno para conservar los pocos existentes.
 * El vector de pokemones del arrecife quedará solo con aquellos que no fueron
 * trasladados (su tamaño se ajustará luego de cada traslado).
 * El vector de pokemones del acuarió quedará con aquellos que fueron
 * trasladados esta vez más los que ya había en el
 * acuario (su tamaño se ajustará luego de cada traslado).
 * Devuelve -1 en caso de error o 0 en caso contrario.
 */

 int trasladar_pokemon (arrecife_t* arrecife , acuario_t* acuario , bool (* seleccionar_pokemon ) (pokemon_t *), int cant_seleccion){
   acuario->cantidad_pokemon = 0;
   if(cant_seleccion > ((*arrecife).cantidad_pokemon)){
     printf("Vamo a calmarno! No podes trasladar tantos pokemones...");
     return -1;
   }
   for(int i=0; i < (size_t)arrecife->cantidad_pokemon; i++){
     if(seleccionar_pokemon(&arrecife->pokemon[i]) && ((*acuario).cantidad_pokemon) < ((*arrecife).cantidad_pokemon)){
       ((*acuario).pokemon[i]) = ((*arrecife).pokemon[i]);
       acuario->cantidad_pokemon +=1;
       (*acuario).pokemon = realloc((*acuario).pokemon,sizeof(pokemon_t)*((size_t)(*acuario).cantidad_pokemon));
       
       for(int x= i+1; x<((*arrecife).cantidad_pokemon); x++){
         (*arrecife).pokemon[x-1] = (*arrecife).pokemon[x];
         (*arrecife).cantidad_pokemon -= 1;
         (*arrecife).pokemon = realloc((*arrecife).pokemon,sizeof(pokemon_t)*((size_t)(*arrecife).cantidad_pokemon));
       };
     }else{
       return -1;
     };
   }
   return 0; 
 }
 
 /*
 * Procedimiento que dado un arrecife deberá mostrar por pantalla a todos los pokemon que contiene.
 */


 void censar_arrecife(arrecife_t* arrecife , void (* mostrar_pokemon)(pokemon_t *)){
   printf("Pokemones en el arrecife:\n");
   for(int i=0; i < (size_t)arrecife->cantidad_pokemon; i++){
     mostrar_pokemon(&arrecife->pokemon[i]);
   }
 }

 /*
 * Función que dado un acuario guarda en un archivo de texto a los pokemones que contiene.
 * Devuelve 0 si se realizo con éxito o -1 si hubo algun problema para guardar el archivo.
 */

 int guardar_datos_acuario (acuario_t* acuario , const char* nombre_archivo){
   FILE* nuevo_acuario = fopen(nombre_archivo,"w");
   if(!nuevo_acuario){
     return -1;
    };
    int i=0;
    for(i=0; i<((*acuario).cantidad_pokemon); i++){
      fprintf(nuevo_acuario, FORMATO_ESCRITURA, (*acuario).pokemon[i].especie,(*acuario).pokemon[i].velocidad,(*acuario).pokemon[i].peso,(*acuario).pokemon[i].color);
    };
    fclose(nuevo_acuario);
    printf("Se generó un archivo con los pokemones del acuario");
   return 0;
 }

 /*
 * Libera la memoria que fue reservada para el acuario.
 */
 void liberar_acuario(acuario_t* acuario){
    if((*acuario).cantidad_pokemon>0){
     free((*acuario).pokemon);
   }
   free(acuario);
 }

 void liberar_arrecife(arrecife_t* arrecife){
    if((*arrecife).cantidad_pokemon>0){
     free((*arrecife).pokemon);
   }
   free(arrecife);
 }
 

