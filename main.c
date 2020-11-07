const char* ARCHIVO_ARRECIFE;
const char* ARCHIVO_ACUARIO;
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
    if((pokemon->velocidad) >= velocidad_alta){
            es_rapido = true;
    }
    return es_rapido;
}




bool pokemones_azules(pokemon_t* pokemon){
    bool es_azul = false;
    if(strcmp(pokemon->color, "azul") == 0){
        es_azul = true;
        }
    return es_azul;
}

bool pokemones_rojos(pokemon_t* pokemon){
    bool es_rojo = false;
    if(strcmp(pokemon->color, "rojo") == 0){
        es_rojo = true;
     }
    return es_rojo;
}

bool pokemones_lentos(pokemon_t* pokemon){
    bool es_lento = false;
    int velocidad_baja = 30;
    if((pokemon->velocidad) >= velocidad_baja){
            es_lento = true;
    }
    return es_lento;
}

bool los_mejores_pokemones(pokemon_t* pokemon){
    // aquellos pokemon que la programadora considera "mejores de su especie": srápidos y rojos.
    bool es_rojo_y_rapido = false;
    int velocidad_alta = 80;
    if((pokemon->velocidad) >= velocidad_alta && strcmp(pokemon->color, "rojo") == 0){
            es_rojo_y_rapido = true;
        }
    return es_rojo_y_rapido;
}



//==================// FUNCIONES DE PARA MOSTRAR POKEMON //==================// 

void mostrar_lista(pokemon_t* pokemon){
    printf("✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩\n");
    printf("Especie: %s\nVelocidad: %i\nPeso: %i\nColor: %s\n",pokemon->especie,pokemon->velocidad,pokemon->peso,pokemon->color);
    printf("✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩✩\n");
}

void mostrar_cuadro(pokemon_t* pokemon){
    printf("-----------------------------------------------------------------\n");
    printf("ESPECIE          VELOCIDAD          PESO          COLOR          \n");
    printf("%s          %i                 %i            %s          \n",pokemon->especie,pokemon->velocidad,pokemon->peso,pokemon->color);
    printf("-----------------------------------------------------------------\n");
}


//==================// FUNCIONES DE MENU //==================// 

void opcion1(arrecife_t* arrecife_de_pokemones, acuario_t* acuario_de_pokemones){
    int valorMisty;

    printf("Elija una opción de visualización de los pokemon en el arrecife\n");
    printf("1 - Ver lista\n");
    printf("2 - Ver cuadro\n");
    printf("0 - Volver al menú principal\n");
    scanf("%i", &valorMisty);

    switch (valorMisty){
    case 1:
        censar_arrecife(arrecife_de_pokemones, mostrar_lista);
        break;
    case 2:
        censar_arrecife(arrecife_de_pokemones, mostrar_cuadro);
        break;
    case 0:
        break;
    default:
        printf("Hubo un error, intente nuevamente:\n");
        opcion1(arrecife_de_pokemones,acuario_de_pokemones);
    };
}


void opcion2(arrecife_t* arrecife_de_pokemones, acuario_t* acuario_de_pokemones, const char* archivo_acuario){
    int eleccionMisty;
    int cant_seleccion;
    int trasladar = 0;
    int guardar = 0;
    printf("Elija qué tipo de pokemon desea trasladar:\n");
    printf("1 - Pokemones rápidos\n");
    printf("2 - Pokemones azules\n");
    printf("3 - Pokemones rojos\n");
    printf("4 - Pokemones lentos\n");
    printf("5 - Pokemón favorito del día\n");
    printf("0 - Volver al menú principal\n");
    scanf("%i", &eleccionMisty);
    
    switch(eleccionMisty){
    case 1:
        printf("Elija la cantidad máxima de pokemon que serán trasladados:\n");
        scanf("%i", &cant_seleccion);
        trasladar = trasladar_pokemon(arrecife_de_pokemones, acuario_de_pokemones, pokemones_rapidos, cant_seleccion);
        break;
    case 2:
        printf("Elija la cantidad máxima de pokemon que serán trasladados:\n");
        scanf("%i", &cant_seleccion);
        trasladar = trasladar_pokemon(arrecife_de_pokemones, acuario_de_pokemones, pokemones_azules, cant_seleccion);
        break;
    case 3:
        printf("Elija la cantidad máxima de pokemon que serán trasladados:\n");
        scanf("%i", &cant_seleccion);
        trasladar = trasladar_pokemon(arrecife_de_pokemones, acuario_de_pokemones,pokemones_rojos , cant_seleccion);
        break;
    case 4:
        printf("Elija la cantidad máxima de pokemon que serán trasladados:\n");
        scanf("%i", &cant_seleccion);
        trasladar = trasladar_pokemon(arrecife_de_pokemones, acuario_de_pokemones, pokemones_lentos, cant_seleccion);
        break;
    case 5: 
        printf("Elija la cantidad máxima de pokemon que serán trasladados:\n");
        scanf("%i", &cant_seleccion);
        trasladar = trasladar_pokemon(arrecife_de_pokemones, acuario_de_pokemones, los_mejores_pokemones, cant_seleccion);
        break;
    case 0:
        break;
    default:
         printf("Hubo un error, intente nuevamente:\n");
         opcion2(arrecife_de_pokemones,acuario_de_pokemones,archivo_acuario);
    };
    if(trasladar == -1){
        printf("Hubo un error, intente nuevamente:\n");
        opcion2(arrecife_de_pokemones,acuario_de_pokemones,archivo_acuario);
    }else{
        guardar = guardar_datos_acuario(acuario_de_pokemones, archivo_acuario);
        if(guardar == -1){
            printf("No se pudo generar un archivo con los pokemon del acuario\n");
        }else{
            printf("Se generó un archivo con los pokemon del acuario\n");
        }
    }
     
}

void introduccion(arrecife_t* arrecife_de_pokemones, acuario_t* acuario_de_pokemones, const char* archivo_acuario){
    int intro;
    printf("Elija qué operación quiere realizar:\n");
    printf("1 - Ver pokemon disponibles en el arrecife\n");
    printf("2 - Trasladar pokemon al acuario\n");
    printf("0 - Salir\n");
    scanf("%i", &intro);

    switch(intro){
    case 1:
        opcion1(arrecife_de_pokemones, acuario_de_pokemones);
        introduccion(arrecife_de_pokemones, acuario_de_pokemones, archivo_acuario);
        break;
    case 2:
        opcion2(arrecife_de_pokemones, acuario_de_pokemones, archivo_acuario);
        introduccion(arrecife_de_pokemones, acuario_de_pokemones, archivo_acuario);
        break;
    case 0:
        break;
    default:
        printf("Hubo un error, intente nuevamente:\n");
        introduccion(arrecife_de_pokemones, acuario_de_pokemones, archivo_acuario); 
    };
}

//==================// FUNCION PRINCIPAL //==================// 

int main (int argc, char **argv){
    printf("\033[01;33m");
    printf("                                       ,'|                           \n"); 
    printf("     _.----.        ____         ,'  _|   ___    ___     ____        \n");    
    printf(" _,-'       `.     |    |  /`.   |,-'    |   |  /   |   |    |  |`.  \n");   
    printf(" |      __    |    '-.  | /   `.  ___    |    |/    |   '-.   | |  | \n");  
    printf("  |.    | |   |  __  |  |/    ,','_  `.  |          | __  |    ||  | \n");   
    printf("    |    |/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  | \n");  
    printf("     |     ,-'/  /   |    ,'   | |/ / ,`.|         /  /   |  |     | \n");  
    printf("      |    | |   |_/  |   `-.  |    `'  /|  |    ||   |_/  | ||    | \n");   
    printf("       |    | |      /       `-.`.___,-' |  ||  /| |      /  | |   | \n");   
    printf("        |    | `.__,'|  |`-._    `|      |__| |/ |  `.__,'|  | |   | \n");    
    printf("         |_.-'       |__|    `-._ |              '-.|     '-.| |   | \n");   
    printf("                                 `'                            '-._| \n");    
    printf("\033[0m");

    printf("¡Bienvenida al sistema de monitoreo de pokemon!\n");
    ARCHIVO_ARRECIFE = argv[1];
    ARCHIVO_ACUARIO = argv[2];
    arrecife_t* arrecife_de_pokemones = crear_arrecife(ARCHIVO_ARRECIFE);
    if(!arrecife_de_pokemones){
        printf("No se pudo generar el arrecife de pokemones. Saliendo del programa...\n");
        return -1;
    }
    acuario_t* acuario_de_pokemones = crear_acuario();
    if(!acuario_de_pokemones){
        printf("No se pudo generar el arrecife de pokemones. Saliendo del programa...\n");
        liberar_arrecife(arrecife_de_pokemones);
        return -1;
    }
    introduccion(arrecife_de_pokemones, acuario_de_pokemones, ARCHIVO_ACUARIO);
    liberar_acuario(acuario_de_pokemones);
    liberar_arrecife(arrecife_de_pokemones);
    return 0;
}