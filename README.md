# HatOfNames-cli

Un programa que selecciona nombres aleatoriamente desde un archivo de texto.

| Contenidos                                |
| ----------------------------------------- |
| [[README#Descripción\|Descripción]]       |
| [[README#Funcionamiento\|Funcionamiento]] |
| [[README#Precauciones\|Precauciones]]     |


## Descripción
"HatOfNames-cli" es un programa realizado en C para seleccionar un nombre de forma aleatoria 
![[img/imagen.jpg]]

## Funcionamiento

El programa empieza con un límite de 255 caracteres para cada línea por lo que el usuario no podrá agregar más de lo ya antes mencionado.
Seguido de esto se hace un ordenamiento de burbuja con la función *swap* para mover los nombres hacía el final de la lista y evitar que no se repitan o salgan de nuevo y así inicializamos el programa. 

Para la configuración inicial del programa primero se pide al usuario la ruta del archivo, en dado caso de que el usuario no inserte una ruta válida se enviará un mensaje pidiendo una ruta correcta y también a la hora de ejecutar el código se necesita como argumento o la ruta absoluta de donde están los nombres o relativa si se encuentra en la misma carpeta, en dado caso de que la ruta sea incorrecta el programa se cierra directamente mostrando en pantalla un mensaje de error (*0xF*), seguido a esto se creó un *while* en donde se guardan los nombres dentro de la lista.

Después comenzamos la interacción con el usuario declarando variables junto con éstas una de tipo *random* para ya que el objetivo del programa es lanzar un nombre aleatorio, aunque con ciertas especificaciones pues se declaró un *while* con 3 diferentes casos:

- **Caso "p":** Lanza el nombre aleatorio
- **Caso "r"**: Resetea el programa
- **Caso "x":** Salimos del programa

Para finalizar, el programa se despide con un mensaje cuando los nombres aleatorios se acabaron y por último se libera la memoria con free.

## Precauciones 

- Al utilizar una ruta relativa tiene que estar en la mismo directorio que el ejecutable.
- Al interactuar con el programa se debe de ingresar un único caracter como *input*.
- El archivo con los nombres debe de contener un nombre por cada línea de texto, no puede ser mayor a 255 caracteres y el documento debe finalizar con un salto de línea.