<p align="center"><img width=60% src="https://upload.wikimedia.org/wikipedia/commons/thumb/9/98/International_Pok%C3%A9mon_logo.svg/800px-International_Pok%C3%A9mon_logo.svg.png"></p>


<h1 align="center">Gran Pesca Pokémon</h1>
<h2 align="center">TP1 de Algoritmos y Programación II</h2><br>


_Trabajo práctico Nº1 de Algoritmos y Programación II, Cátedra Mendez, Facultad de Ingeniería de la Universidad de Buenos Aires._


## Introducción 🚀 

En el trabajo presentado se utilizan las funciones definidas en "**evento_pesca.h**" e implementadas en el archivo "**evento_pesca.c**" para poder generar un programa que, a partir de un archivo ("**arrecife.txt**") con una lista de especies de pokémon con sus características (velocidad, peso y color) y cuya ruta llega como parámetro, simule un arrecife y cómo sería el traslado de determinados pokémon solicitados por Misty (el usuario) a un nuevo acuario.

Permite visualizar los pokemones en el arrecife y aquellos pokémon registrados en el acuario de Misty serán guardados en un nuevo archivo ("**acuario.txt**") con los mismos campos que el archivo de arrecife. 


## Modo de Uso 📝

Comandos de compilación y ejecución:

> $ gcc *.c -Wall -Werror -Wconversion -std=c99 -o evento_pesca                
> $ ./evento_pesca arrecife.txt acuario.txt

Durante la elaboración del trabajo también se utilizó valgrind para la depuración de problemas de memoria utilizando el siguiente comando: 

> $ valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./evento_pesca arrecife.txt acuario.txt 


## Contruido con... ⚙

    1. Punteros.

Los punteros son la manera de manipular un valor a través del acceso a la memoria, dándonos una manera indirecta de acceder a un valor particular. 
Son variables cuyo valor es una dirección de memoria representada como un entero. El compilador debe saber el tipo de data que vamos a almacenar en la variable a la cual apunta por lo que es necesario especificarla.
Los identificamos con *

Ejemplo:
```C
pokemon_t pokemon;
pokemon.especie = "Magikarp"
pokemon.velocidad = 30;
pokemon.peso = 60;
pokemon.color = "azul";
pokemon_t *puntero_pokemon = &pokemon; //la variable puntero_pokemon contiene la dirección de la variable pokemon
```

    2. Aritmética de punteros.

Podemos operar con los punteros al acceder a los valores que contienen. Los utilizamos puesto que hacen más sencillo el uso de strings y arrays y nos permiten retornar multiples valores de una función entre otros beneficios.

    3. Punteros a funciones.

Los punteros a funciones almacenan la dirección de la función. Otra función podría recibir un puntero a función por parámetro y llamar a esta segunda función en cualquier momento.

Ejemplo: 
```C
void mostrar_lista(pokemon_t* pokemon){
    ...
}

void censar_arrecife(void (* mostrar_pokemon)(pokemon_t *)){
   	...
		   mostrar_pokemon(arrecife->pokemon+i);
    ...
}

int main(){
    censar_arrecife(mostrar_lista);
}
```



    4. Malloc y Realloc.

Malloc y Realloc son dos funciones de la librería estándar de C.

* **malloc()** reserva size bytes y retorna la dirección del primer byte de memoria que se busca reservar. Es por esto que en el argumento debemos especificar la cantidad de bytes requeridos y se debe asignar a un puntero.

Ejemplo: 

```C
arrecife_t* arrecife = malloc(sizeof(arrecife_t));
arrecife->pokemon= malloc(sizeof(pokemon_t));
```

Podemos liberar la memoria reservada empleando la función **free()**

> free(arrecife);

* **realloc()** nos permite modificar el tamaño del bloque de memoria apuntado por el puntero anterior en size bytes. Lo hace solicitando una nueva dirección de memoria de tamaño solicitado, copiando la información almacenada en la anterior y liberando este al traspasar los datos.

```C
pokemon_t* pokemon_nuevo = realloc(arrecife->pokemon,sizeof(pokemon_t)*((size_t)arrecife->cantidad_pokemon+1));
```


---

_Camila Codina_