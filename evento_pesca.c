#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "evento_pesca.h"

#define MAX_ESPECIE 100
#define MAX_COLOR 50
#define FORMATO_LECTURA "%30[^;];%i;%i;%30[^\n]\n"
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

  FILE* archivo_pokemones_arrecife = fopen(ruta_archivo,"r");
  if(!archivo_pokemones_arrecife){
	  printf("No se pudo abrir el archivo de pokemon que viven en el arrecife.\n");
      return NULL;
    }

  arrecife_t* arrecife = calloc(1, sizeof(arrecife_t));
  if(!arrecife) return NULL;

  pokemon_t pokemon_leido;
  int leidos = fscanf(archivo_pokemones_arrecife, FORMATO_LECTURA, pokemon_leido.especie, &pokemon_leido.velocidad, &pokemon_leido.peso, pokemon_leido.color);
  if(!leidos || leidos!=4){
	  printf("No se pudo leer ninguna linea.\n");
	  fclose(archivo_pokemones_arrecife);
    free(arrecife);
    return NULL;
    };

  while(leidos==4){
      pokemon_t* pokemon_a_agregar = realloc(arrecife->pokemon,sizeof(pokemon_t)*((size_t)arrecife->cantidad_pokemon+1));
		  if(!pokemon_a_agregar){
        free(arrecife->pokemon);
        free(arrecife);
        fclose(archivo_pokemones_arrecife);
        return NULL;
      };
      arrecife->pokemon = pokemon_a_agregar;
      arrecife->pokemon[arrecife->cantidad_pokemon] = pokemon_leido;
      (arrecife->cantidad_pokemon)++;
		  leidos = fscanf( archivo_pokemones_arrecife, FORMATO_LECTURA, pokemon_leido.especie, &(pokemon_leido.velocidad), &(pokemon_leido.peso), pokemon_leido.color);  
  };

  fclose(archivo_pokemones_arrecife);

  if(arrecife->cantidad_pokemon == 0){
    free(arrecife->pokemon);
    free(arrecife);
    return NULL;
  };
  
  return arrecife;
}

 /*
 * Función que crea un acuario vacío reservando la memoria necesaria para el mismo.
 * Devuelve el acuario o NULL en caso de error.
 */

acuario_t* crear_acuario(){
  acuario_t* acuario = calloc(1, sizeof(acuario_t));
  if(!acuario) return NULL;
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
  if(!arrecife) return -1;
  if(!(arrecife->pokemon)) return -1;
  if(!acuario) return -1;
  if(!seleccionar_pokemon) return -1;

  if(cant_seleccion==0){
    return 0;
  };

  if(arrecife->cantidad_pokemon < cant_seleccion){
      return -1;
  };

  int posicion_poke_a_trasladar[cant_seleccion];
  int cantidad_poke_a_trasladar = 0;
  int x=0;

  while((x<(arrecife->cantidad_pokemon)) && (cantidad_poke_a_trasladar < cant_seleccion)){
    if(seleccionar_pokemon(arrecife->pokemon+x)){
      posicion_poke_a_trasladar[cantidad_poke_a_trasladar] = x;
      cantidad_poke_a_trasladar++;
    }
    x++;
  }

  if(cantidad_poke_a_trasladar == 0) return 0;

  if(cantidad_poke_a_trasladar == cant_seleccion){

    for(int i=0; i < cant_seleccion; i++){
        pokemon_t* pokemon_agregado = realloc(acuario->pokemon,sizeof(pokemon_t)*((size_t)acuario->cantidad_pokemon+1));
				if(!pokemon_agregado) return -1;
				acuario->pokemon = pokemon_agregado;
        acuario->pokemon[acuario->cantidad_pokemon] = arrecife->pokemon[posicion_poke_a_trasladar[i]];
        (acuario->cantidad_pokemon)++;
    
    };

    for(int j=0; j<cant_seleccion; j++){
      int posicion_del_poke_trasladado = posicion_poke_a_trasladar[j]-j;
      for(int k=posicion_del_poke_trasladado+1; k<(arrecife->cantidad_pokemon); k++){
        arrecife->pokemon[k-1] = arrecife->pokemon[k];
      };
      pokemon_t* pokemon_sacado = realloc(arrecife->pokemon,sizeof(pokemon_t)*((size_t)arrecife->cantidad_pokemon-1));
			if(!pokemon_sacado && arrecife->cantidad_pokemon-1 != 0) return -1;
			arrecife->pokemon = pokemon_sacado;
			(arrecife->cantidad_pokemon)--;
    };

    return 0; 
  }

  return -1;
		
}

 
 /*
 * Procedimiento que dado un arrecife deberá mostrar por pantalla a todos los pokemon que contiene.
 */


 void censar_arrecife(arrecife_t* arrecife , void (* mostrar_pokemon)(pokemon_t *)){
   	for(int i=0; i < (arrecife->cantidad_pokemon); i++){
		   mostrar_pokemon(arrecife->pokemon+i);
   }
 }

 /*
 * Función que dado un acuario guarda en un archivo de texto a los pokemones que contiene.
 * Devuelve 0 si se realizo con éxito o -1 si hubo algun problema para guardar el archivo.
 */

 int guardar_datos_acuario (acuario_t* acuario , const char* nombre_archivo){
	if(!acuario) return -1;
  if(!nombre_archivo) return -1;

  FILE* nuevo_acuario = fopen(nombre_archivo,"w");
  if(!nuevo_acuario) return -1;
  int i=0;
  for(i=0; i<(acuario->cantidad_pokemon); i++){
    fprintf(nuevo_acuario, FORMATO_ESCRITURA, acuario->pokemon[i].especie,acuario->pokemon[i].velocidad,acuario->pokemon[i].peso,acuario->pokemon[i].color);
  };
  fclose(nuevo_acuario);
  return 0;
 }

 /*
 * Libera la memoria que fue reservada para el acuario.
 */
 void liberar_acuario(acuario_t* acuario){
   if(acuario){
     free(acuario->pokemon);
     free(acuario);
   }
   
 }

 void liberar_arrecife(arrecife_t* arrecife){
   if(arrecife){
      free(arrecife->pokemon);
      free(arrecife);
   }
   
 }
 

