gcc tdas/*.c main.c -Wno-unused-result -o main
./main

# Sistema gestor de tareas. 

Este sistema gestor de tareas permite a los usuarios gestionar una base de datos al gusto, ofreciendo guardar títulos de tareas que tenga al pendiente y gestionarlas a su criterio para realizarlas, siendo así posible llevar una vida más organizada y responsable a través de un sistema amigable.  


## Cómo compilar y ejecutar el código: 
  

-Para ejecutar el main primero debemos compilar (en la carpeta raíz)  

``````
gcc tdas/*.c main4.c -Wno-unused-result -o main4
``````

Y luego ejecutar: 
``````
./main4 
``````
ya puedes seleccionar las opciones que necesites! 


## Funcionalidades 

### Opciones funcionales: 

1. Agregar Tarea Pendiente
La función de agregar tarea pendiente permite registrar una nueva tarea donde se debe ingresar su título, descripción, fecha límite y dificultad. La prioridad se asigna inicialmente por defecto a "3" (baja) y la fecha de creación se registra automáticamente utilizando la librería time.h.

2. Asignar Prioridad
Esta opción permite cambiar la prioridad de una tarea existente en la lista. Funciona ingresando el título de la tarea previamente registrada y asignando una nueva prioridad (1, 2 o 3). Se verifica que la tarea exista y que la prioridad ingresada sea válida.

3. Mostrar Tareas Pendientes
Esta opción muestra la lista de tareas pendientes, incluyendo título, descripción, fecha de entrega, prioridad y dificultad. Las tareas se muestran en el orden en que fueron agregadas.

4. Modificar Tarea
Permite modificar diferentes parámetros de una tarea existente (descripción, fecha de entrega, dificultad). Se debe ingresar el título de la tarea para identificarla y luego seleccionar qué parámetro se desea modificar.

5. Buscar Tarea
Permite buscar tareas por título o por fecha. Se muestra la información completa de la tarea encontrada.

6. Eliminar Tarea Completada
Permite eliminar una tarea completada de la lista. Se debe ingresar el título de la tarea que se desea eliminar. La tarea se elimina de la lista y de los mapas correspondientes. 

## Ejemplo de uso del código: 

- Comenzamos la ejecución del código al ejecutar el programa como se indicó al inicio.

``````````````````
======================================== 
|    Sistema de Gestor de tareas       | 
|======================================| 
| 1) Agregar tarea pendiente           | 
| 2) Asignar prioridad                 | 
| 3) Mostrar tareas pendientes         | 
| 4) Modificar Tarea                   | 
| 5) Buscar tarea                      | 
| 6) Eliminar tarea completada         | 
| 7) Salir                             | 
======================================== 
``````````````````

### 1. Agregar Tarea Pendiente
- Luego podemos comenzar a cargar nuestras tareas en el código utilizando la opción “1” reiteradas veces, tantas como el usuario necesite.
- Para esta opción del menú debes completar los siguientes campos de manera secuencial a medida que se le vaya pidiendo al usuario para que quede de esta forma:

``````````````````
   =========================================
   Ingrese título de la tarea pendiente: ejemplo
   Ingrese una descripción de la tarea pendiente: aca habra una descripcion
   Ingrese fecha límite de la tarea (dd/mm/aaaa): 29/07/2024
   Ingrese dificultad de la tarea pendiente (1-5): 1
   ======  Tarea registrada con éxito  ======

   Presione una tecla para continuar...
 
``````````````````
### 2. Asignar Prioridad
- Ya cuando hayamos cargado todas nuestras tareas, podemos utilizar la opción “2” para asignar una prioridad a una tarea en específico, por ejemplo, si añadí la tarea (Trabajo de artes) y quiero que su prioridad sea mayor, puedo utilizar esta función para cambiar su prioridad.

- Para el cual se pedira ingresar el título de la tarea y la nueva prioridad:

``````````````````
=========================================
Ingrese el título de la tarea pendiente: ejemplo
Ingrese la nueva prioridad de la tarea pendiente (1-3): 2
=========================================
Prioridad asignada con éxito
Presione una tecla para continuar...
``````````````````
### 3. Mostrar Tareas Pendientes
- Si el usuario desea saber qué tareas hay pendientes por realizar, puede utilizar la opción “3”, así se muestran por pantalla consecutivamente sus tareas pendientes. 

``````````````````
Tareas pendientes: 
=========================================
Título: ejemplo 
Descripción: aca habra una descripcion
Fecha de entrega: 29/7/2024
Prioridad: 2
Dificultad: 1
=========================================
Presione una tecla para continuar...
``````````````````
### 4. Modificar Tarea
- La opción “4” Permite modificar una tarea existente. Se ingresa el título de la tarea y se selecciona el parámetro a modificar:

````````````
=========================================
Ingrese el título de la tarea a modificar: ejemplo 
=========================================
````````````
````````````
    ("==============================="); 
    ("|      Modificar tarea        |"); 
    ("|=============================|"); 
    ("|1) Modificar descripción     |"); 
    ("|2) Modificar fecha de entrega|"); 
    ("|3) Modificar Dificultad      |"); 
    ("|4) Volver al menu principal  |"); 
    ("==============================="); 
    Ingrese su opción:
````````````
- para la primera opcion del sub menu 

````````````
Ingrese su opción: 1
Descripción actual: aca habra una descripcion
Ingrese la nueva descripción: aca se podra modificar la descripcion 
Tarea modificada con éxito
===============================
|      Modificar tarea        |
|=============================|
|1) Modificar descripcion     |
|2) Modificar fecha de entrega|
|3) Modificar Dificultad      |
|4) Volver al menu principal  |
===============================
Ingrese su opción:
````````````
- de la misma forma se continua modificando los demas campos si el usuario desea en caso de que no puede volver atras

### 5. Buscar Tarea
- En caso de que el usuario no recuerde bien o quiera corroborar si una tarea ya fue añadida a su base de datos, puede recurrir a la opción “5”, con esta opción puede buscar una tarea, esta va a aparecer en la base de datos y el usuario va a poder corroborar exitosamente la existencia de esta tarea, para luego poder manipularla a su criterio. 
````````````
    ("============================="); 
    ("|    Menu Buscar tarea      |"); 
    ("|===========================|"); 
    ("|1) Buscar por titulo       |"); 
    ("|2) Buscar por fecha        |"); 
    ("|3) Volver al menu principal|"); 
    ("============================="); 
````````````

````````````
Ingrese su opción: 2
Ingrese la fecha límite de la tarea a buscar (dd/mm/aaaa): 28/7/2024
=========================================
Título: ejemplo
Descripción: aca de podra modificar la descripcion
Fecha de entrega: 28/7/2024
Prioridad: 3
Dificultad: 5
=========================================
````````````
### 6. Eliminar Tarea Completada
- Cuando el usuario termine alguna de sus tareas, puede recurrir a la opción “6” para eliminar aquella tarea que desea y quitarla de sus tareas pendientes, para así no confundirse y ordenarse con ayuda del programa, por ejemplo, si el usuario elimina “Tarea de fisica”, la función 4 ya no va a poder encontrar a esta misma, en el caso de que con la función 5 se haya eliminado del programa, sino, esta va a aparecer en la base de datos. 

````````````
=========================================
Ingrese el título de la tarea a eliminar: ejemplo
=========================================
Tarea eliminada con éxito
Presione una tecla para continuar...
````````````

### 7. Salir 
- Para terminar la ejecución del programa, el usuario puede simplemente cerrar el programa como de costumbre o finalizarlo utilizando la opción “7”. 

Esta función finaliza la ejecución del programa limpiamente y el usuario deberá volver a seguir los pasos de ejecución enseñados previamente para volver a hacer uso del programa. 


## Contribuciones por integrante: 

### Aspectos Positivos a considerar
• Adai Illanes: organización, dominio del tema en su totalidad, esfuerzo,una gran responsabilidad a la hora de trabajar en la aplicacion, buena iniciativa, desarrollo las ideas y su implementacion en las funciones de la app, apartado del readme y con compromiso con el proyecto.


• Marcel Gutierrez: organización, buena inciativa y Disposición al equipo,buena responsabilidad y gran flexibilidad,sobre la implementacion de las funciones del codigo ayuda en ideas y parte del desarrollo con la agregacion y mejora de menus , ayuda en el apartado del readme, tester de la app.

• Juan Guzmán: Disposición al equipo, organización, flexibilidad horaria,ayudo en el desarrollo del menu y submenus,aporte del readme, aporte de ideas. 

• Kevin Alvarez : Esfuerzo, responsabilidad, compromiso con el trabajo, sobre la implementacion de las funcionalidades en el codigo ayudo en las funciones de ingresar tarea,mostrar tarea y asignar prioridad, aporte de ideas.

### Puntos
• -Adai Illanes : +4
• -Marcel Gutierrez : +3
• -Juan Guzmán: 1
• -Kevin Alvarez: +3