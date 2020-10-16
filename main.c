#include <stdio.h>
#include <stdbool.h>
#include "evento_pesca.h"

/*
* Funciones que determinan los Pokémon que serán movidos al acuario:
* - Como mínimo es necesario crear 5.
* - Ejemplos:
* - - Sólo pokémon pertenecientes a la especie "Magikarp ".
* - - Sólo pokémon que tengan color rojo y velocidad menor a 10.
* - - Etc. sean creativos!
*/

int main (){
    ruta_archivo = (char*)malloc(100*sizeof(char));
  for(int i=0; i<100; i++){
    ruta_archivo = &ruta[i];
    ++ruta_archivo;
  };
  arrecife_t* crear_arrecife(const char* ruta_archivo);
  acuario_t* crear_acuario ();
/* Crear las estructuras a utilizar */
/* Trasladar por 1ra vez con cierta función */
/* Listar a los pokémon que continúan en el arrecife */
/* Trasladar por 2da vez con cierta función */
/* Listar a los pokémon que continúan en el arrecife */
// ...
/* Trasladar por N-écima vez con cierta función */
/* Listar a los pokémon que continúan en el arrecife */
/* Guardar los pokémon del acuario */
/* Liberar memoria */
return 0;
}