#include "tdas/list.h"
#include "tdas/map.h"
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
  char titulo[100]; // Clave del mapa
  char descripcionTarea[200];
  time_t fecha_creacion;
  FechaLimite fecha_limite;
  int prioridad; // de 1 a 3, el 1(prioridad máxima) y el 3 (como prioridad mínima)
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

int is_equal_str(void *key1, void *key2) {
  if (strcmp((char *)key1, (char *)key2) == 0)
    return 1;
  return 0;
}

int is_equal_int(void *key1, void *key2) {
  return (*(int *)key1 == *(int *)key2);
}

void mostrarMenuPrincipal() {
  puts("========================================");
  puts("|    Sistema de Gestor de tareas       |");
  puts("|======================================|");
  puts("| 1) Agregar tarea pendiente           |");
  puts("| 2) Asignar prioridad                 |");
  puts("| 3) Mostrar tareas pendientes         |");
  puts("| 4) Modificar Tarea                   |");
  puts("| 5) Buscar tarea                      |");
  puts("| 6) Eliminar tarea completada         |");
  puts("| 7) Salir                             |");
  puts("========================================");
}
void subMenuBuscar() {
  puts("==========================");
  puts("    Menu Buscar tarea ");
  puts("==========================");
  puts("1) Buscar por titulo");
  puts("2) Buscar por fecha");
  puts("3) Volver al menu principal");
  puts("==========================");
}
void subMenuModificar() {
puts("============================");
puts("     Modificar tarea");
puts("=============================");
puts("1) Modificar descripcion");
puts("2) Modificar fecha de entrega");
puts("3) Modificar Dificultad");
puts("4) Volver al menu principal");
puts("============================");
}

void AgregarTareasPendientes(Map *tareas, List *listaTareas) {
  tipoTarea *pendiente = (tipoTarea *)malloc(sizeof(tipoTarea));
  printf("=========================================\n");
  printf("Ingrese titulo de la tarea pendiente: ");
  scanf(" %[^\n]", pendiente->titulo);
  printf("Ingrese una descripcion de la tarea pendiente: ");
  scanf(" %[^\n]", pendiente->descripcionTarea);
  printf("Ingrese fecha limite de la tarea formato dd/mm/aaaa pendiente: ");
  scanf("%d/%d/%d", &pendiente->fecha_limite.dia,
                    &pendiente->fecha_limite.mes,
                    &pendiente->fecha_limite.anyo);
  printf("Ingrese dificultad de la tarea pendiente (1-3): ");
  scanf("%d", &pendiente->dificultad);
  if (pendiente->dificultad < 1 || pendiente->dificultad > 3) {
    printf("Dificultad invalida, debe ser un valor entre 1 y 3\n");
    mostrarMenuPrincipal();
  }
  pendiente->prioridad = 3; // Prioridad por defecto
  pendiente->fecha_creacion = time(NULL);

  map_insert(tareas, pendiente->titulo, pendiente);
  list_pushBack(listaTareas, pendiente);

  printf("======  Tarea registrada con éxito  ======\n\n");
  printf("---- ¿Desea registrar una nueva tarea? ---\n");
  printf("(1) Si\n");
  printf("(2) No\n");
  printf("\n");

  int alternativa;
  scanf("%d", &alternativa);

  if (alternativa == 1) {
    AgregarTareasPendientes(tareas, listaTareas);
  } else if (alternativa == 2) {
    limpiarPantalla();
  } else {
    printf("Opción inválida, intente nuevamente una opción válida\n");
  }
}

void AsignarPrioridad(Map *tareas) {
  char titulo[100];
  int nuevaPrioridad;

  printf("=========================================\n");
  printf("Ingrese el título de la tarea pendiente: ");
  scanf(" %[^\n]", titulo);
  printf("Ingrese la nueva prioridad de la tarea pendiente (1-3): ");
  scanf("%d", &nuevaPrioridad);
  printf("=========================================\n");

  tipoTarea *tarea = (tipoTarea *)map_search(tareas, titulo);
  if (tarea != NULL) {
    tarea->prioridad = nuevaPrioridad;
    printf("Prioridad asignada con éxito\n");
  } else {
    printf("Tarea no encontrada\n");
  }

  printf("---- ¿Desea asignar una nueva prioridad? ---\n");
  printf("(1) Si\n");
  printf("(2) No\n");
  printf("\n");

  int alternativa;
  scanf("%d", &alternativa);

  if (alternativa == 1) {
    AsignarPrioridad(tareas);
  } else if (alternativa == 2) {
    limpiarPantalla();
  }
}

void MostrarTareasPendientes(List *listaTareas) {
  if (list_first(listaTareas) == NULL) {
    printf("No hay tareas pendientes.\n");
    return;
  }

  printf("Tareas pendientes: \n");
  printf("=========================================\n");
  tipoTarea *tareaActual = (tipoTarea *)list_first(listaTareas);
  while (tareaActual != NULL) {
    printf("Título: %s\n", tareaActual->titulo);
    printf("Descripción: %s\n", tareaActual->descripcionTarea);
    printf("Fecha de entrega: %d/%d/%d\n", tareaActual->fecha_limite.dia,
                                           tareaActual->fecha_limite.mes,
                                           tareaActual->fecha_limite.anyo);
    printf("Prioridad: %d\n", tareaActual->prioridad);
    printf("Dificultad: %d\n", tareaActual->dificultad);
    printf("=========================================\n");
    tareaActual = (tipoTarea *)list_next(listaTareas);
  }
}
// problema en el buscar 

void BuscarTareasTitulo(Map *tareas) {
  char titulo[100];
  printf("=========================================\n");
  printf("Ingrese el título de la tarea pendiente: ");
  scanf(" %[^\n]", titulo);
  printf("=========================================\n");

  tipoTarea *tarea = (tipoTarea *)map_search(tareas, titulo);
  if (tarea != NULL) {
    printf("Título: %s\n", tarea->titulo);
    printf("Descripción: %s\n", tarea->descripcionTarea);
    printf("Fecha de entrega: %d/%d/%d\n", tarea->fecha_limite.dia,
                                           tarea->fecha_limite.mes,
                                           tarea->fecha_limite.anyo);
    printf("Prioridad: %d\n", tarea->prioridad);
    printf("Dificultad: %d\n", tarea->dificultad);
    printf("=========================================\n");
  } else {
    printf("Tarea no encontrada\n");
  }
}

// falta da solo para el primero de lista
void ModificarTarea(Map *tareas) {
  char titulo[100];
  printf("Ingrese el título de la tarea a modificar: ");
  scanf(" %[^\n]", titulo);

  tipoTarea *tarea = (tipoTarea *)map_search(tareas, titulo); 
  if (tarea == NULL) {
    printf("Tarea no encontrada\n");
    return;
  }

  int opcion;
  printf("Seleccione el atributo a modificar:\n");
  printf("1) Título\n");
  printf("2) Descripción\n");
  printf("3) Fecha de entrega\n");
  printf("4) Dificultad\n");
  printf("Ingrese su opción: ");
  scanf("%d", &opcion);

  switch (opcion) {
    case 1:
      printf("Ingrese el nuevo título: ");
      scanf(" %[^\n]", tarea->titulo);
      break;
    case 2:
      printf("Ingrese la nueva descripción: ");
      scanf(" %[^\n]", tarea->descripcionTarea);
      break;
    case 3:
      printf("Ingrese la nueva fecha de entrega (dd/mm/aaaa): ");
      scanf("%d/%d/%d", &tarea->fecha_limite.dia,
                        &tarea->fecha_limite.mes,
                        &tarea->fecha_limite.anyo);
      break;
    case 4:
      printf("Ingrese la nueva dificultad: ");
      scanf("%d", &tarea->dificultad);
      break;
    default:
      printf("Opción no válida\n");
      break;
  }
}

/*
void EliminarTareaCompletada(Map *tareas, List *listaTareas) {
  char titulo[100];
  printf("Ingrese el título de la tarea a eliminar: ");
  scanf(" %[^\n]", titulo);

  tipoTarea *tarea = (tipoTarea *)map_search(tareas, titulo);
  if (tarea == NULL) {
    printf("Tarea no encontrada\n");
    return;
  }

  map_remove(tareas, titulo);

  tipoTarea *tareaActual = (tipoTarea *)list_first(listaTareas);
  while (tareaActual != NULL) {
    if (strcmp(tareaActual->titulo, titulo) == 0) {
      list_clean(listaTareas, tareaActual);
      break;
    }
    tareaActual = (tipoTarea *)list_next(listaTareas);
  }

  printf("Tarea eliminada con éxito\n");
}
*/

int main() {
  char opcion;
  Map *tareas = map_create(is_equal_str);
  List *listaTareas = list_create();

  do {
    mostrarMenuPrincipal();
    printf("Ingrese su opción: ");
    scanf(" %c", &opcion);

    switch (opcion) {
    case '1':
      limpiarPantalla();
      AgregarTareasPendientes(tareas, listaTareas);
      break;
    case '2':
      limpiarPantalla();
      AsignarPrioridad(tareas);
      break;
    case '3':
      limpiarPantalla();
      MostrarTareasPendientes(listaTareas);
      break;
    case '4':
      limpiarPantalla();
      ModificarTarea(tareas);
      break;
    case '5':
      limpiarPantalla();
      BuscarTareasTitulo(tareas);
      break;
    case '6':
      limpiarPantalla();
      //EliminarTareaCompletada(tareas, listaTareas);
      break;
    case '7':
      puts("Saliendo...\n");
      break;
    default:
      puts("Opción no válida\n");
    }
  } while (opcion != '7');

  list_clean(listaTareas);
  map_clean(tareas);

  return 0;
}
