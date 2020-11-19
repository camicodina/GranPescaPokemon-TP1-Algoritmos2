#include "evento_pesca.h"
#include "pa2mm.h"

void probar_creacion_acuario(){
    acuario_t* un_acuario = NULL;

    pa2m_afirmar((un_acuario=crear_acuario()) != NULL, "Puedo crear un acuario");
    pa2m_afirmar(un_acuario->cantidad_pokemon == 0, "Un acuario se crea vacio");
    pa2m_afirmar(un_acuario->pokemon == NULL, "Un acuario se crea con un vector nulo");

    liberar_acuario(un_acuario);
}

void probar_creacion_arrecife_con_archivo_valido_de_extesion_arbitraria(){
    arrecife_t* arrecife_dat = NULL;
    arrecife_t* arrecife_csv = NULL;
    arrecife_t* arrecife_h = NULL;

    pa2m_afirmar((arrecife_dat = crear_arrecife("arrecife_valido.dat")) != NULL, "Puedo crear un arrecife con un archivo válido de extension dat");
    pa2m_afirmar((arrecife_csv = crear_arrecife("arrecife_valido.csv")) != NULL, "Puedo crear un arrecife con un archivo válido de extension csv");
    pa2m_afirmar((arrecife_h = crear_arrecife("arrecife_valido.h")) != NULL, "Puedo crear un arrecife con un archivo válido de extension h");

    liberar_arrecife(arrecife_dat);
    liberar_arrecife(arrecife_csv);
    liberar_arrecife(arrecife_h);
}

void probar_liberar_arrecife_nulo(){
    liberar_arrecife(NULL);
}

int main(){

    pa2m_nuevo_grupo("PRUEBAS DE ACUARIO");
    probar_creacion_acuario();

    pa2m_nuevo_grupo("PRUEBAS DE ARRECIFE");
    //probar_creacion_arrecife_sin_archivo();
    //probar_creacion_arrecife_con_archivo_invalido();
    //probar_creacion_arrecife_con_archivo_de_un_pokemon();
    //probar_creacion_arrecife_con_archivo_de_varios_pokemon();
    //probar_creacion_arrecife_con_archivo_varios_pokemon_y_uno_invalido_en_medio();
    probar_creacion_arrecife_con_archivo_valido_de_extesion_arbitraria();
    probar_liberar_arrecife_nulo();

    pa2m_mostrar_reporte();
}
