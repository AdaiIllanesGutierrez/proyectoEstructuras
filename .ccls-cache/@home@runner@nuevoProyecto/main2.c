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

void AgregarTareasPendientes(Map *tareas, List *listaTareas) {
  tipoTarea *pendiente = (tipoTarea *)malloc(sizeof(tipoTarea));
  printf("=========================================\n");
  printf("Ingrese titulo de la tarea pendiente: ");
  scanf("%[^\n]", pendiente -> titulo);
  printf("Ingrese una descripcion de la tarea pendiente: ");
  scanf("%s", pendiente -> descripcionTarea);
  printf("Ingrese fecha limite de la tarea formato dd/mm/aaaa pendiente: ");
  scanf("%d/%d/%d", &pendiente -> fecha_limite.dia,
                    &pendiente -> fecha_limite.mes,
                    &pendiente -> fecha_limite.anyo);
  printf("Ingrese dificultad de la tarea pendiente: ");
  scanf("%d", &pendiente -> dificultad);
  pendiente -> prioridad = 3; // Prioridad por defecto
  pendiente -> fecha_creacion = time(NULL);

  map_insert(tareas, pendiente->titulo, pendiente);
  list_pushBack(listaTareas, pendiente);

  printf("====== Tarea registrada con éxito ======\n\n");
  printf("---- ¿Desea registrar una nueva tarea? ---\n");
  printf("(1) Si\n");
  printf("(2) No\n");
  printf("\n");

  int alternativa;
  scanf("%d", &alternativa);

  if (alternativa == 1) {
    AgregarTareasPendientes(tareas, listaTareas);
  } else if(alternativa == 2) {
    limpiarPantalla();
    //mostrarMenuPrincipal();
  } else {
    printf("Opción invalida, intente nuevamente una opcion válida\n");
  }
}

void AsignarPrioridad(Map *tareas) {
  char titulo[100];
  int nuevaPrioridad;

  printf("=========================================\n");
  printf("Ingrese el título de la tarea pendiente: ");
  scanf("%s", titulo);
  printf("Ingrese la nueva prioridad de la tarea pendiente: ");
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
  } else if(alternativa == 2) {
    limpiarPantalla();
    //mostrarMenuPrincipal();
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

/*void ModificarTarea(Map *tareas) {
  char titulo[100];
  int nuevaPrioridad;

  printf("=========================================\n");
  printf("Ingrese el título de la tarea pendiente: ");
  scanf("%s", titulo);
  printf("Ingrese la nueva prioridad de la tarea pendiente: ");
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
  } else if(alternativa == 2) {
    limpiarPantalla();
    //mostrarMenuPrincipal();
  }  
}*/
void BuscarTareasTitulo(Map* tareas){

  char titulo[100];
  printf("=========================================\n");
  printf("Ingrese el título de la tarea pendiente: ");
  scanf("%s", titulo);
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

void ModificarTarea(Map *tareas) {
  char titulo[100];
  printf("Ingrese el título de la tarea a modificar: ");
  scanf("%s", titulo);

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
      scanf("%s", tarea->titulo);
      break;
    case 2:
      printf("Ingrese la nueva descripción: ");
      scanf("%s", tarea->descripcionTarea);
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
/*void EliminarTareaCompletada(Map *tareas, List *listaTareas) {
  char titulo[100];
  printf("Ingrese el título de la tarea a eliminar: ");
  scanf("%s", titulo);

  tipoTarea *tarea = (tipoTarea *)map_search(tareas, titulo);
  if (tarea == NULL) {
    printf("Tarea no encontrada\n");
    return;
  }

  map_remove(tareas, titulo);

  tipoTarea *tareaActual = (tipoTarea *)list_first(listaTareas);
  while (tareaActual != NULL) {
    if (strcmp(tareaActual->titulo, titulo) == 0) {
      list_remove(listaTareas, tareaActual);
      break; 
    }
    tareaActual = (tipoTarea *)list_next(listaTareas);
  }

  printf("Tarea eliminada con éxito\n");
}*/


//LAS FUNCIONES ESTAN FUNCIONANDO SOLO EN LA PRIMERA VERSION SOLO PARA UNA TAREA
int main() {
  char opcion;
  Map *tareas = map_create(is_equal_str);
  /*MAPAS PARA LA BUSQUEDA*/
  //Map *titulo = map_create(is_equal_str);
  // Map *prioridad = map_create(is_equal_int);
  //Map *dificultad = map_create(is_equal_int);
  // Map *mes = map_create(is_equal_int);
  
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
      ModificarTarea(tareas);
      break;
    case '5':
      BuscarTareasTitulo(tareas);
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
  } while (opcion != '7');

  list_clean(listaTareas);
  map_clean(tareas);

  return 0;
}