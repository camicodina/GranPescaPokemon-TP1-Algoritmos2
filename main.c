const char* ARCHIVO_ARRECIFE = "arrecife.txt";
const char* ARCHIVO_ACUARIO = "acuario.txt";
const int MAX_POKEMON = 100;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

pokemon_t* pokemones_rapidos(arrecife_t* arrecife, pokemon_t* pokemones_seleccionados){
    pokemon_t **pokemones_recibidos = &arrecife->pokemon;
    int i=0;
    int velocidad_alta = 80;
    if((*arrecife).pokemon->velocidad >= velocidad_alta){
        for(i=0; i<MAX_POKEMON; i++){
            *(pokemones_seleccionados+i) = **(pokemones_recibidos+i);
        }
    }
    return pokemones_seleccionados;
}

pokemon_t* pokemones_azules(arrecife_t* arrecife, pokemon_t* pokemones_seleccionados){
    pokemon_t **pokemones_recibidos = &arrecife->pokemon;
    int i=0;
    if(strcomp((*arrecife->pokemon->color), "azul") == 0){
        for(i=0; i<MAX_POKEMON; i++){
            *(pokemones_seleccionados+i) = **(pokemones_recibidos+i);
        }
     }
      
    return pokemones_seleccionados;
}

pokemon_t* pokemones_rojos(arrecife_t* arrecife, pokemon_t* pokemones_seleccionados){
    pokemon_t **pokemones_recibidos = &arrecife->pokemon;
    int i=0;
    if(strcomp((*arrecife->pokemon->color), "rojo") == 0){
        for(i=0; i<MAX_POKEMON; i++){
            *(pokemones_seleccionados+i) = **(pokemones_recibidos+i);
        }
     }
      
    return pokemones_seleccionados;
}

pokemon_t* pokemones_lentos(arrecife_t* arrecife, pokemon_t* pokemones_seleccionados){
    pokemon_t **pokemones_recibidos = &arrecife->pokemon;
    int i=0;
    int velocidad_baja = 50;
    if((*arrecife).pokemon->velocidad <= velocidad_baja){
        for(i=0; i<MAX_POKEMON; i++){
            *(pokemones_seleccionados+i) = **(pokemones_recibidos+i);
        }
    }
    return pokemones_seleccionados;
}

pokemon_t* los_mejores_pokemones(arrecife_t* arrecife, pokemon_t* pokemones_seleccionados){
    // aquellos pokemon que la programadora considera "mejores de su especie": srápidos y rojos.
    pokemon_t **pokemones_recibidos = &arrecife->pokemon;
    int i=0;
    int velocidad_alta = 80;
    if(((*arrecife).pokemon->velocidad >= velocidad_alta) && (strcomp((*arrecife->pokemon->color), "rojo") == 0)){
        for(i=0; i<MAX_POKEMON; i++){
            *(pokemones_seleccionados+i) = **(pokemones_recibidos+i);
        }
    }

    return pokemones_seleccionados;
}

// Opciones mostrar

pokemon_t* mostrar_lista(arrecife_t* arrecife){
    pokemon_t **pokemones_nadando_felices = &arrecife->pokemon;
    int **cantidad_de_pokemones_nadando_felices = &arrecife->cantidad_pokemon;
    int i=0;
    for(i=0; i<(**cantidad_de_pokemones_nadando_felices); i++){
        printf("✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩");
        printf("Especie: %c\nVelocidad: %i\nPeso: %i\nColor: %c\n",(**pokemones_nadando_felices).especie, (**pokemones_nadando_felices).velocidad,(**pokemones_nadando_felices).peso,(**pokemones_nadando_felices).color);
        printf("✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩");
        
    }
}

pokemon_t* mostrar_cuadro(arrecife_t* arrecife){
    pokemon_t **pokemones_nadando_felices = &arrecife->pokemon;
    int **cantidad_de_pokemones_nadando_felices = &arrecife->cantidad_pokemon;
    int i=0;
    printf("✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩");
    printf("Especie: %c\nVelocidad: %i\nPeso: %i\nColor: %c\n",(**pokemones_nadando_felices).especie, (**pokemones_nadando_felices).velocidad,(**pokemones_nadando_felices).peso,(**pokemones_nadando_felices).color);
    printf("✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩");
}


pokemon_t* mostrar_dibujo(arrecife_t* arrecife){
    pokemon_t **pokemones_nadando_felices = &arrecife->pokemon;
    int **cantidad_de_pokemones_nadando_felices = &arrecife->cantidad_pokemon;
    int i=0;
} 

//--------------------------------------//  

bool (*seleccionar_pokemon[5]) (pokemon_t*) = {pokemones_rapidos, pokemones_azules, pokemones_rojos, pokemones_lentos, los_mejores_pokemones};
void (*mostrar_pokemon[3])(pokemon_t* ) = {mostrar_lista, mostrar_cuadro, mostrar_dibujo};

//--------------------------------------// 

void opcion1(arrecife_de_pokemones){
    int cant_seleccion = MAX_POKEMON;
    int valorMisty;

    printf("Elija una opción de visualización de los pokemon en el arrecife\n");
    printf("1 - Ver lista\n");
    printf("2 - Ver cuadro\n");
    printf("3 - Dibujo ASCII\n");
    scanf("%i", &valorMisty);

    if(valorMisty == 1){
        censar_arrecife(arrecife_de_pokemones, mostrar_lista(arrecife_de_pokemones));
    }else if(valorMisty == 2){
        censar_arrecife(arrecife_de_pokemones, mostrar_lista(arrecife_de_pokemones));
    }else if(valorMisty == 3){
        censar_arrecife(arrecife_de_pokemones, mostrar_lista(arrecife_de_pokemones));
    }else{
        printf("Hubo un error, intente nuevamente:");
        scanf("%i", &valorMisty);
    }
}

void opcion2(arrecife_de_pokemones, acuario_de_pokemones){
    int eleccionMisty;
    printf("Elija qué tipo de pokemon desea trasladar:\n");
    printf("1 - Pokemones rápidos\n");
    printf("2 - Pokemones azules\n");
    printf("3 - Pokemones rojos\n");
    printf("4 - Pokemones lentos\n");
    printf("5 - Pokemón favorito del día\n");
    scanf("%i", &eleccionMisty);

    
    int cant_seleccion;
    printf("Elija la cantidad máxima de pokemon que serán trasladados:\n");
    scanf("%i", &cant_seleccion);

    if(eleccionMisty == 1){
        trasladar_pokemon(arrecife_de_pokemones, acuario_de_pokemones, pokemones_rapidos, cant_seleccion);
        guardar_datos_acuario(acuario_de_pokemones, ARCHIVO_ACUARIO);
    }else if(eleccionMisty == 2){
        trasladar_pokemon(arrecife_de_pokemones, acuario_de_pokemones, pokemones_azules, cant_seleccion);
        guardar_datos_acuario(acuario_de_pokemones, ARCHIVO_ACUARIO);
    }else if(eleccionMisty == 3){
        trasladar_pokemon(arrecife_de_pokemones, acuario_de_pokemones, pokemones_rojos, cant_seleccion);
        guardar_datos_acuario(acuario_de_pokemones, ARCHIVO_ACUARIO);
    }else if(eleccionMisty == 4){
        trasladar_pokemon(arrecife_de_pokemones, acuario_de_pokemones, pokemones_lentos, cant_seleccion);
        guardar_datos_acuario(acuario_de_pokemones, ARCHIVO_ACUARIO);
    }else if(eleccionMisty == 5){
        trasladar_pokemon(arrecife_de_pokemones, acuario_de_pokemones, los_mejores_pokemones, cant_seleccion);
        guardar_datos_acuario(acuario_de_pokemones, ARCHIVO_ACUARIO);
    }else{
        printf("Hubo un error, intente nuevamente:");
        scanf("%i", &eleccionMisty);
    }
}

//==================// FUNCION PRINCIPAL //==================// 

int main (){
    printf("\033[1;31m");
    printf("                                       ,'|                           "); 
    printf("     _.----.        ____         ,'  _|   ___    ___     ____        ");    
    printf(" _,-'       `.     |    |  /`.   |,-'    |   |  /   |   |    |  |`.  ");   
    printf(" |      __    |    '-.  | /   `.  ___    |    |/    |   '-.   | |  | ");  
    printf("  |.    | |   |  __  |  |/    ,','_  `.  |          | __  |    ||  | ");   
    printf("    |    |/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  | ");  
    printf("     |     ,-'/  /   |    ,'   | |/ / ,`.|         /  /   |  |     | ");  
    printf("      |    | |   |_/  |   `-.  |    `'  /|  |    ||   |_/  | ||    | ");   
    printf("       |    | |      /       `-.`.___,-' |  ||  /| |      /  | |   | ");   
    printf("        |    | `.__,'|  |`-._    `|      |__| |/ |  `.__,'|  | |   | ");    
    printf("         |_.-'       |__|    `-._ |              '-.|     '-.| |   | ");   
    printf("                                 `'                            '-._| ");    
    printf("\033[0m;");

    printf("¡Bienvenida al sistema de monitoreo de pokemon!");

    arrecife_t* arrecife_de_pokemones = crear_arrecife(ARCHIVO_ARRECIFE);
    acuario_t* acuario_de_pokemones = crear_acuario();
    pokemon_t* pokemones_seleccionados = malloc(MAX_POKEMON * sizeof(pokemon_t));

    int intro;
    printf("Elija qué operación quiere realizar:\n");
    printf("1 - Ver pokemon disponibles en el arrecife\n");
    printf("2 - Trasladar pokemon al acuario\n");
    scanf("%i", &intro);

    if(intro == 1){
        opcion1(arrecife_de_pokemones);
    }else if(intro == 2){
        opcion2(arrecife_de_pokemones, acuario_de_pokemones);
    }else{
        printf("Hubo un error, intente nuevamente:");
        scanf("%i", &intro);
    }


    free(pokemones_seleccionados);
    liberar_acuario(acuario_de_pokemones);
    liberar_arrecife(acuario_de_pokemones);
    

    return 0;
}