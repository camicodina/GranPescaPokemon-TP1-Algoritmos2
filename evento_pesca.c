#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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

int leer_archivo(FILE* archivo_pokemones_arrecife){
  pokemon_t pokemon_arrecife;
  int leidos = fscanf( archivo_pokemones_arrecife, FORMATO_LECTURA, pokemon_arrecife.especie[MAX_ESPECIE], &pokemon_arrecife.velocidad, &pokemon_arrecife.peso, pokemon_arrecife.color[MAX_COLOR]);
  if(!leidos){
    printf("No se pudo leer ningunas linea.\n");
    return NULL;
  };
  while(leidos != EOF && leidos){
    fprintf(actualizado, FORMATO_ESCRITURA, actual.pais, actual.anio, actual.disciplina, actual.nombre, actual.puntos);
}

// voy a necesitar realloc para crear un array de pokemones dinamico

int crear_arrecife(char* ruta_archivo){
  FILE* archivo_pokemones_arrecife = fopen(ruta_archivo,"r");
  if(!archivo_pokemones_arrecife){
    printf("No se pudo abrir el archivo de pokemones que viven en el arrecife.\n");
    return NULL;
  };
  leer_archivo(archivo_pokemones_arrecife);

  fclose(archivo_pokemones_arrecife);

  return 0;
}

arrecife_t* crear_arrecife(char* ruta_archivo);


/*
* Función que crea un acuario vacío reservando la memoria necesaria para el mismo.
* Devuelve el acuario o NULL en caso de error.
*/
acuario_t* crear_acuario ();

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

int trasladar_pokemon (arrecife_t* arrecife , acuario_t* acuario , bool (* seleccionar_pokemon )
(pokemon_t *), int cant_seleccion);


/*
* Procedimiento que dado un arrecife deberá mostrar por pantalla a todos los pokemon que contiene.
*/

void censar_arrecife(arrecife_t* arrecife , void (* mostrar_pokemon)(pokemon_t *));


/*
* Función que dado un acuario guarda en un archivo de texto a los pokemones que contiene.
* Devuelve 0 si se realizo con éxito o -1 si hubo algun problema para guardar el archivo.
*/
int guardar_datos_acuario (acuario_t* acuario , const char* nombre_archivo);


/*
* Libera la memoria que fue reservada para el acuario.
*/
void liberar_acuario(acuario_t* acuario);

/*
* Libera la memoria que fue reservada para el arrecife.
*/
void liberar_arrecife(arrecife_t* arrecife);


