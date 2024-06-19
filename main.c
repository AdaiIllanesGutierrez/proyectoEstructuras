#include "tdas/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

typedef struct {
  int dia;
  int mes;   
  int anyo;
} FechaLimite;

typedef struct {
// int id; podriamos usar el titulo como clave 
char titulo[100];
char descripcionTarea[200];
time_t fecha_creacion;
FechaLimite fecha_limite;
int prioridad; // de 1 a 3, el 1(priridad maxima) y el 3 (como prioridad minima)
int dificultad; // de 1 a 5 referenciando la dificultad del 1 al 5
} tipoTarea;

void limpiarPantalla() { 
  system("clear"); 
}
void presioneTeclaParaContinuar() {
  puts("Presione una tecla para continuar...");
  getchar(); // Consume el '\n' del buffer de entrada
  getchar(); // Espera a que el usuario presione una tecla
}

void mostrarMenuPrincipal() {
  puts("========================================");
  puts("     Sistema de Gestor de tareas");
  puts("========================================");

  puts("1) Agregar tarea pendiente");
  puts("2) Asignar prioridad");
  puts("3) Mostrar tareas pendientes");
  puts("4) Modificar Tarea ");
  puts("5) Buscar tarea");
  puts("6) Eliminar tarea completada");
  puts("7) Salir");
}
/*SUBMENU MODO BETA

  puts("========================================");
  puts("     SubMenu");
  puts("========================================");
  puts("1) Mostrar tarea");
  puts("2) Modificar tarea");
  puts("3) Buscar tarea");
  puts("4) Salir");
//Para mostrat tarea

puts("========================================");
puts("     MostrarTarea");
puts("========================================");
puts("1) Mostrar por fecha de entrega");
puts("2) Mostrar por prioridad");

// PARA MODIFICAR TAREA
puts("========================================");
puts("     Modificar tarea");
puts("========================================");
puts("1) Modificar título");
puts("2) Modificar fecha");
puts("3) Modificar fecha");
puts("4) Modificar asignatura");

//para buscar tarea
puts("========================================");
puts("     Buscar tarea");
puts("========================================");
puts("1) Buscar por titulo");
puts("2) Buscar por fecha");
puts("3) Buscar por prioridad");
puts("4) Buscar por asignaturas");
  
*/
void AgregarTareasPendientes (List *tarea)
{
  tipoTarea *pendiente = (tipoTarea *)malloc(sizeof(tipoTarea));
  printf("=========================================\n");
  printf("Ingrese titulo de la tarea pendiente: ");
  scanf("%s", pendiente -> titulo);
  printf("Ingrese una descripcion de la tarea pendiente: ");
  scanf("%s", pendiente -> descripcionTarea);
  printf("Ingrese fecha limite de la tarea  formato dd/mm/aaaa pendiente: ");
  scanf("%d/%d/%d", &pendiente -> fecha_limite.dia,
                        &pendiente -> fecha_limite.mes,
                        &pendiente -> fecha_limite.anyo);
  printf("Ingrese dificultad de la tarea pendiente: ");
  scanf("%d", &pendiente -> dificultad);

  list_pushBack(tarea, pendiente);
  
  printf("====== Tarea registrado con éxito ======\n\n");
  printf("---- ¿Desea registrar una nueva tarea? ---\n");
  printf("(1) Si\n");
  printf("(2) No\n");
  printf("\n");

  int alternativa;
  scanf("%d", &alternativa);

  if (alternativa == 1)
  {
    AgregarTareasPendientes(tarea);
  }
  if(alternativa == 2)
  {
    limpiarPantalla();
    //mostrarMenuPrincipal();
  }
  if(alternativa != 1 && alternativa != 2)
  {
    printf("Opción invalida, intente nuevamente una opcion válida\n");
  }
  
}
/*
void AsignarPrioridad (List *tarea) {
  void *tareaActual = list_first(tarea);
  char titulo[100];
  int prioridadNueva;
  int contador = 0;

  printf("=========================================\n");
  printf("Ingrese titulo de la tarea a modificar: ");
  scanf(" %s", titulo);
  getchar();
  printf("=========================================\n");

  while (tareaActual != NULL) {
    tipoTarea *tarea = (tipoTarea *) tareaActual;
    if(strcmp(tarea -> titulo, titulo) == 0) {
      contador = 1;
      printf("Ingrese la nueva prioridad de la tarea: ");
      scanf(" %d", &prioridadNueva);
      getchar();
      tarea -> prioridad = prioridadNueva;
      printf("====== Tarea modificada con éxito ======\n\n");
    }
  } 
}
  */


//version 1 
//la prioridad no se guarda pendiente
void AsignarPrioridad (List *tarea)
{
  tipoTarea *prioridad = (tipoTarea *)malloc(sizeof(tipoTarea));
  
  printf("=========================================\n");
  printf("Ingrese el título de la tarea pendiente: ");
  scanf("%s", prioridad -> titulo);
  printf("Ingrese su prioridad a asignar de la tarea pendiente: ");
  scanf("%d" , &prioridad -> prioridad);
  printf("=========================================\n");
  printf("Prioridad asignada con éxito\n");
  printf("---- ¿Desea asignar una nueva prioridad? ---\n");
  printf("(1) Si\n");
  printf("(2) No\n");
  printf("\n");
  int alternativa;
  scanf("%d", &alternativa);
  if (alternativa == 1)
  {
    AsignarPrioridad(tarea);
  }
  if(alternativa == 2)
  {
    limpiarPantalla();
    //mostrarMenuPrincipal();
  }
  
}

void MostrarTareasPendientes(List *tarea) {
  if (list_first(tarea) == NULL) {
    printf("No hay tareas pendientes.\n");
    return;
  }

  printf("Tareas pendientes: \n");
  printf("=========================================\n");
  tipoTarea *tareaActual = list_first(tarea);
  while (tareaActual != NULL) {
    printf("Título: %s\n", tareaActual -> titulo);
    printf("Descripción: %s\n", tareaActual -> descripcionTarea);
    // printf("Fecha de creación: %d/%d/%d\n", tareaActual -> fecha_cracion);
    printf("Fecha de entrega: %d/%d/%d\n", tareaActual -> fecha_limite.dia,
                                           tareaActual -> fecha_limite.mes,
                                           tareaActual -> fecha_limite.anyo);
    printf("Prioridad: %d\n", tareaActual -> prioridad);
    printf("Dificultad: %d\n", tareaActual -> dificultad);
    printf("=========================================\n");
    tareaActual = list_next(tarea);
  }
}

int main() {
  char opcion;
  List *tareas = list_create();
  do
  {
    mostrarMenuPrincipal();
    printf("Ingrese su opción: ");
    scanf(" %c", &opcion); 

    switch (opcion)
    {
    case '1':
      limpiarPantalla();
      AgregarTareasPendientes(tareas);
      break;
    case '2':
      limpiarPantalla();
      //pendiente
      //implementar mapas paa hacer mas facil la busueda y cambiar la prioridad
      AsignarPrioridad(tareas);// con errores 
      break;
    case '3':
      limpiarPantalla();
      MostrarTareasPendientes(tareas);
      break;
    case '4':
      //ModificarTarea(tareas);
      break;
    case '5':
      //BuscarTareas(tareas);
      break;
    case '6':
      //EliminarTareaCompletada(tareas);
      break;
      case '7':
      puts("Saliendo...\n");
      break;
    default:
      puts("Opción no válida\n");
    }
   

  }while (opcion != '7');

  list_clean(tareas);

  return 0;
}

