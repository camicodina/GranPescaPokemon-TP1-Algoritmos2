# GranPescaPokemon -TP1 Algoritmos y Programación II

_Trabajo práctico Nº1 de Algoritmos y Programación II, Cátedra Mendez, Facultad de Ingeniería de la Universidad de Buenos Aires._


## Introducción 🚀 

En el trabajo presentado utiliza las funciones en evento_pesca.c para llamarlas desde el main.c.

## Modo de Uso 📝

_Una explicación de como compilarlo (línea de compilación) y como ejecutarlo (línea de ejecución)._

Si funcionara usaría estos comandos:

> $ gcc *.c -Wall -Werror -Wconversion -std=c99 -o evento_pesca
> $ gcc -g main.c evento_pesca.o -o main                
> $ ./main
> $ valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./main
s

## Contruido con... ⚙

    1. Punteros.

Los punteros son variables cuyo valor es una dirección de memoria representada como un entero. El compilador debe saber el tipo de data que vamos a almacenar en la cariable a la cual apunta por lo que es necesario especificarla.

    2. Aritmética de punteros.

Podemos operar con los punteros al acceder a los valores que contienen. Los utilizamos puesto que hacen más sencillo el uso de strings y arrays y nos permiten retornar multiples valores de una función entre otros beneficios.

    3. Punteros a funciones.

Los punteros a funciones almacenan la dirección de la función. Podemos llamar a esta función en cualquier momento a través del puntero.

    4. Malloc y Realloc.

Malloc y Realloc son dos funciones de la librería estándar de C.
Malloc retorna la dirección del primer byte de memoria que se busca reservar y en el argumento debemos especificar la cantidad de bytes requeridos. Se debe asignar a un puntero

### Enunciado 👩‍💻

La líder de gimnasio Misty organizó un evento de pesca que se llevará a cabo en su acuario, ubicado en Ciudad Celeste.
Para ello necesitará muchos y muy variados pokémon de tipo agua. El lugar indicado en Kanto para obtener a todos
estos pokémon es el arrecife que rodea a las Islas Espuma.

Para realizarlo, te pide que la ayudes a trasladar los pokémon seleccionados desde el arrecife a su acuario, donde será
realizado el evento.

A Misty le preocupa perjudicar la población de las especies más vulnerables, es por ello que te pide realizar una simulación
del arrecife, pudiendo ver como quedará su estado dependiendo de qué especies se elijan para el evento.
Las funcionalidades que se deben implementar se detallan a continuación:

    1) Función que dado un archivo carga los pokémon que viven en el arrecife
       reservando la memoria necesaria para el mismo. Se debe intentar leer la mayor
       cantidad posible de registros del archivo. Al encontrar el primer registro
       erróneo (o al llegar al final del archivo) se deben finalizar la lectura y
       crear el arrecife con los pokémon leídos exitosamente. En caso de no
       encontrar ningún registro con el formato correcto , se debe devolver error.
       Devuelve un puntero a un arrecife válido o NULL en caso de error.



    2) Función que crea un acuario vacío reservando la memoria necesaria para el mismo.
       Devuelve el acuario o NULL en caso de error.



    3) Función que deberá sacar del arrecife a todos los pokémon que satisfagan la
       condición dada por el puntero a función (que devuelvan true) y trasladarlos
       hacia el acuario. El parámetro cant_seleccion especifica la cantidad máxima
       de pokémon que serán trasladados. En caso de que haya menos pokémon trasladables en el
       arrecife que los pedidos , no se deberá mover ninguno para conservar los pocos existentes.
       El vector de pokemones del arrecife quedará solo con aquellos que no fueron
       trasladados (su tamaño se ajustará luego de cada traslado).
       El vector de pokemones del acuarió quedará con aquellos que fueron
       trasladados esta vez más los que ya había en el
       acuario (su tamaño se ajustará luego de cada traslado).
       Devuelve -1 en caso de error o 0 en caso contrario.



    4) Procedimiento que dado un arrecife deberá mostrar por pantalla a todos los pokemon que contiene.



    5) Función que dado un acuario guarda en un archivo de texto a los pokemones que contiene.
       Devuelve 0 si se realizo con éxito o -1 si hubo algun problema para guardar el archivo.



    6) Libera la memoria que fue reservada para el acuario.
    


    7) Libera la memoria que fue reservada para el arrecife.



A su vez, se cuenta con los siguientes registros a utilizar en el presente trabajo:

```
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
```

Los pokémon pertenecientes al arrecife se encontrarán en el archivo arrecife.txt cuya ruta llega como parámetro.
El archivo tendrá la siguiente información:
    | especie;velocidad;peso;color

Los pokémon que estén registrados en el acuario de Misty serán guardados en un archivo acuario.txt con el siguiente
formato:
    | especie;velocidad;peso;color





_Programado con amor ( ˘ ³˘)♥_