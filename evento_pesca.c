#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "evento_pesca.h"

#define MAX_ESPECIE 100
#define MAX_COLOR 50
#define FORMATO_LECTURA "%[^;];%i;%i[^;];%\n"
#define FORMATO_ESCRITURA "%[^;];%i;%i[^;];%\n"

typedef struct pokemon{
  char especie[MAX_ESPECIE];
  int velocidad;
  int peso;
  char color[MAX_COLOR];
} pokemon_t;

typedef struct acuario{
  pokemon_t* pokemon;
  int cantidad_pokemon;
} acuario_t;

typedef struct arrecife{
  pokemon_t* pokemon;
  int cantidad_pokemon;
} arrecife_t;

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
  arrecife_t *arrecife = (arrecife_t*)malloc(sizeof(arrecife_t));
  pokemon_t **pokemon;
  arrecife->pokemon = malloc(sizeof(pokemon_t));
  arrecife->cantidad_pokemon = malloc(sizeof(int));
  pokemon = &arrecife->pokemon;
  int **cantidad_pokemon;
  arrecife->cantidad_pokemon = 0;
  cantidad_pokemon = &arrecife->cantidad_pokemon;
  int i=0;

  FILE* archivo_pokemones_arrecife = fopen(ruta_archivo,"r");
  if(!archivo_pokemones_arrecife){
    printf("No se pudo abrir el archivo de pokemones que viven en el arrecife.\n");
    return NULL;
  };
  pokemon_t pokemon_leido;
  int leidos = fscanf(archivo_pokemones_arrecife, FORMATO_LECTURA, pokemon_leido.especie[MAX_ESPECIE], &(pokemon_leido.velocidad), &(pokemon_leido.peso), pokemon_leido.color[MAX_COLOR]);
  if(!leidos){
    printf("No se pudo leer ninguna linea.\n");
    exit(0);
    return NULL;
  };
  while(leidos != EOF && !ferror(archivo_pokemones_arrecife)){
      **(pokemon+i) = pokemon_leido;
      i += 1;
      cantidad_pokemon += 1;
      pokemon = (pokemon_t*)realloc(pokemon,i);
      int leidos = fscanf( archivo_pokemones_arrecife, FORMATO_LECTURA, pokemon_leido.especie[MAX_ESPECIE], &(pokemon_leido.velocidad), &(pokemon_leido.peso), pokemon_leido.color[MAX_COLOR]);
  }
  fclose(archivo_pokemones_arrecife);
  return &arrecife;
}

 /*
 * Función que crea un acuario vacío reservando la memoria necesaria para el mismo.
 * Devuelve el acuario o NULL en caso de error.
 */

acuario_t* crear_acuario(){
  acuario_t *acuario = (acuario_t*)malloc(sizeof(acuario_t));
  acuario->pokemon = malloc(sizeof(pokemon_t));
  acuario->cantidad_pokemon = malloc(sizeof(int));
  if (!acuario) return NULL;
  return &acuario;
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
   pokemon_t **pokemones_seleccionados = &acuario->pokemon;
   pokemon_t **pokemones_existentes = &arrecife->pokemon;
   int **cantidad_pokemones_seleccionados = &acuario->cantidad_pokemon;
   int **cantidad_pokemones_existentes = &arrecife->cantidad_pokemon;
   int i=0;
   int n=1;
   for(int i=0; i < cant_seleccion; i++){
     if(seleccionar_pokemon && (**cantidad_pokemones_seleccionados) < (**cantidad_pokemones_existentes)){
       **(pokemones_seleccionados+i) = **(pokemones_existentes+i);
       pokemones_seleccionados = (pokemon_t*)realloc(pokemones_seleccionados,n);
       acuario->cantidad_pokemon +=1;
       n+=1;
       for(int x= i+1; x<(**cantidad_pokemones_existentes); x++){
         **(pokemones_existentes+(x-1)) = **(pokemones_existentes+x);
         cantidad_pokemones_existentes -= 1;
         pokemones_existentes = (pokemon_t*)realloc(pokemones_existentes,cantidad_pokemones_existentes);
       };
     }else{
       return -1;
     };
   };
   return 0; 
 }
 
 /*
 * Procedimiento que dado un arrecife deberá mostrar por pantalla a todos los pokemon que contiene.
 */

 void censar_arrecife(arrecife_t* arrecife , void (* mostrar_pokemon)(pokemon_t *)){
   pokemon_t **pokemones_nadando_felices = &arrecife->pokemon;
   int **cantidad_de_pokemones_nadando_felices = &arrecife->cantidad_pokemon;
   printf("Pokemones en el arrecife:\n");
   int i=0;
   for(int i=0; i<(**cantidad_de_pokemones_nadando_felices); i++){
     printf("-------------------");
     printf("Especie: %c\nVelocidad: %i\nPeso: %i\nColor: %c\n",(**pokemones_nadando_felices).especie[MAX_ESPECIE], (**pokemones_nadando_felices).velocidad,(**pokemones_nadando_felices).peso,(**pokemones_nadando_felices).color[MAX_COLOR]);
     printf("-------------------");
   };
 }

 /*
 * Función que dado un acuario guarda en un archivo de texto a los pokemones que contiene.
 * Devuelve 0 si se realizo con éxito o -1 si hubo algun problema para guardar el archivo.
 */

 int guardar_datos_acuario (acuario_t* acuario , const char* nombre_archivo){
   pokemon_t **datos_pokemones_en_acuario = &acuario->pokemon;
   int **cantidad_pokemones_acuario = &acuario->cantidad_pokemon;
   FILE* nuevo_acuario = fopen(nombre_archivo,"w");
   if(!nuevo_acuario){
     return -1;
    };
    int i=0;
    for(int i=0; i<(**cantidad_pokemones_acuario); i++){
      fprintf(nuevo_acuario, FORMATO_ESCRITURA, (**(datos_pokemones_en_acuario+i)).especie[MAX_ESPECIE],(**(datos_pokemones_en_acuario+i)).velocidad,(**(datos_pokemones_en_acuario+i)).peso,(**(datos_pokemones_en_acuario+i)).color[MAX_COLOR]);
    };
   return 0;
 }
 
 /*
 * Libera la memoria que fue reservada para el acuario.
 */
 void liberar_acuario(acuario_t* acuario){
   free(acuario);
   free(acuario->cantidad_pokemon);
   free(acuario->pokemon);
 }

 void liberar_arrecife(arrecife_t* arrecife){
   free(arrecife);
   free(arrecife->pokemon);
 }

