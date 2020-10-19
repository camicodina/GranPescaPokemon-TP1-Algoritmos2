const char* ARCHIVO_ARRECIFE = "arrecife.txt";
const char* ARCHIVO_ACUARIO = "acuario.txt";
const int MAX_POKEMON = 100;
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "evento_pesca.h"


//==================// FUNCIONES DE SELECCION DE POKEMON //==================// 

bool pokemones_rapidos(pokemon_t* pokemon){
    bool es_rapido = false;
    int velocidad_alta = 80;
    if(((*pokemon).velocidad) >= velocidad_alta){
            es_rapido = true;
    }
    return es_rapido;
}




bool pokemones_azules(pokemon_t* pokemon){
    bool es_azul = false;
    if(strcmp((*pokemon).color, "azul") == 0){
        es_azul = true;
        }
    return es_azul;
}

bool pokemones_rojos(pokemon_t* pokemon){
    bool es_rojo = false;
    if(strcmp(((*pokemon).color), "rojo") == 0){
        es_rojo = true;
     }
    return es_rojo;
}

bool pokemones_lentos(pokemon_t* pokemon){
    bool es_lento = false;
    int velocidad_baja = 30;
    if(((*pokemon).velocidad) >= velocidad_baja){
            es_lento = true;
    }
    return es_lento;
}

bool los_mejores_pokemones(pokemon_t* pokemon){
    // aquellos pokemon que la programadora considera "mejores de su especie": srápidos y rojos.
    bool es_rojo_y_rapido = false;
    int velocidad_alta = 80;
    if(((*pokemon).velocidad) >= velocidad_alta && strcmp((*pokemon).color, "rojo") == 0){
            es_rojo_y_rapido = true;
        }
    return es_rojo_y_rapido;
}



//==================// FUNCIONES DE PARA MOSTRAR POKEMON //==================// 

void* mostrar_lista(pokemon_t* pokemon){
    printf("✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩");
    printf("Especie: %s\nVelocidad: %i\nPeso: %i\nColor: %s\n",pokemon->especie,pokemon->velocidad,pokemon->peso,pokemon->color);
    printf("✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩");
}

void* mostrar_cuadro(pokemon_t* pokemon){
    printf("-----------------------------------------------------------------\n");
    printf("ESPECIE          VELOCIDAD          PESO          COLOR          \n");
    printf("%s          %i          %i          %s          \n",pokemon->especie,pokemon->velocidad,pokemon->peso,pokemon->color);
    printf("-----------------------------------------------------------------\n");
}


//==================// FUNCIONES DE MENU //==================// 

void opcion1(arrecife_t* arrecife_de_pokemones, acuario_t* acuario_de_pokemones){
    int valorMisty;

    printf("Elija una opción de visualización de los pokemon en el arrecife\n");
    printf("1 - Ver lista\n");
    printf("2 - Ver cuadro\n");
    scanf("%i", &valorMisty);

    if(valorMisty == 1){
        void (*mostrar_pokemon)(pokemon_t*) = mostrar_lista((*arrecife_de_pokemones).pokemon);
        censar_arrecife(arrecife_de_pokemones, mostrar_pokemon);
    }else if(valorMisty == 2){
        void (*mostrar_pokemon)(pokemon_t*) = mostrar_cuadro((*arrecife_de_pokemones).pokemon);
        censar_arrecife(arrecife_de_pokemones, mostrar_pokemon);
    }else{
        printf("Hubo un error, intente nuevamente:");
        scanf("%i", &valorMisty);
    }
}

void opcion2(arrecife_t* arrecife_de_pokemones, acuario_t* acuario_de_pokemones){
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
        bool (*seleccionar_pokemon) (pokemon_t*) = pokemones_rapidos;
        trasladar_pokemon(arrecife_de_pokemones, acuario_de_pokemones, seleccionar_pokemon, cant_seleccion);
        guardar_datos_acuario(acuario_de_pokemones, ARCHIVO_ACUARIO);
    }else if(eleccionMisty == 2){
        bool (*seleccionar_pokemon) (pokemon_t*) = pokemones_azules;
        trasladar_pokemon(arrecife_de_pokemones, acuario_de_pokemones, seleccionar_pokemon , cant_seleccion);
        guardar_datos_acuario(acuario_de_pokemones, ARCHIVO_ACUARIO);
    }else if(eleccionMisty == 3){
        bool (*seleccionar_pokemon) (pokemon_t*) = pokemones_rojos;
        trasladar_pokemon(arrecife_de_pokemones, acuario_de_pokemones,seleccionar_pokemon , cant_seleccion);
        guardar_datos_acuario(acuario_de_pokemones, ARCHIVO_ACUARIO);
    }else if(eleccionMisty == 4){
        bool (*seleccionar_pokemon) (pokemon_t*) = pokemones_lentos;
        trasladar_pokemon(arrecife_de_pokemones, acuario_de_pokemones, seleccionar_pokemon , cant_seleccion);
        guardar_datos_acuario(acuario_de_pokemones, ARCHIVO_ACUARIO);
    }else if(eleccionMisty == 5){
        bool (*seleccionar_pokemon) (pokemon_t*) = los_mejores_pokemones;
        trasladar_pokemon(arrecife_de_pokemones, acuario_de_pokemones, seleccionar_pokemon , cant_seleccion);
        guardar_datos_acuario(acuario_de_pokemones, ARCHIVO_ACUARIO);
    }else{
        printf("Hubo un error, intente nuevamente:");
        scanf("%i", &eleccionMisty);
    }
}

void introduccion(arrecife_t* arrecife_de_pokemones, acuario_t* acuario_de_pokemones){
    int intro;
        printf("Elija qué operación quiere realizar:\n");
        printf("1 - Ver pokemon disponibles en el arrecife\n");
        printf("2 - Trasladar pokemon al acuario\n");
        scanf("%i", &intro);

        if(intro == 1){
            opcion1(arrecife_de_pokemones, acuario_de_pokemones);
        }else if(intro == 2){
            opcion2(arrecife_de_pokemones, acuario_de_pokemones);
        }else{
            printf("Hubo un error, intente nuevamente:");
            scanf("%i", &intro);
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

    introduccion(arrecife_de_pokemones, acuario_de_pokemones);

    liberar_acuario(acuario_de_pokemones);
    liberar_arrecife(arrecife_de_pokemones);
    
    return 0;
}