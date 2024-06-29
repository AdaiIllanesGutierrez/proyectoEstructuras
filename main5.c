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
    char titulo[100];
    char descripcionTarea[200];
    time_t fecha_creacion;
    FechaLimite fecha_limite;
    int prioridad;
    int dificultad;
} tipoTarea;

void limpiarPantalla() {
    system("clear");
}
void presioneTeclaParaContinuar() {
    puts("Presione una tecla para continuar...");
    getchar();
    getchar();
}

int is_equal_str(void *key1, void *key2) {
    return strcmp((char *)key1, (char *)key2) == 0;
}
char* fecha_to_string(FechaLimite fecha) {
    char *fecha_str = (char *)malloc(11);
    sprintf(fecha_str, "%02d/%02d/%04d", fecha.dia, fecha.mes, fecha.anyo);
    return fecha_str;
}

void inicio (){
  puts("----------------------------------------------------------");
  puts("|  .88888.                      dP                       |");                    
  puts("| d8'   `88                     88                       |");                   
  puts("| 88        .d8888b. .d8888b. d8888P .d8888b. 88d888b.   |");  
  puts("| 88   YP88 88ooood8 Y8ooooo.   88   88'  `88 88'  `88   |");  
  puts("| Y8.   .88 88.  ...       88   88   88.  .88 88         |"); 
  puts("|  `88888'  `88888P' `88888P'   dP   `88888P' dP         |");  
  puts("|                                                        |");                                                  
  puts("|                                                        |");                                              
  puts("|                      dP                                |");                                             
  puts("|                      88                                |");                                           
  puts("|                .d888b88 .d8888b.                       |");                                      
  puts("|                88'  `88 88ooood8                       |");                                     
  puts("|                88.  .88 88.  ...                       |");                                     
  puts("|                `88888P8 `88888P'                       |");                                     
  puts("|                                                        |");                                       
  puts("|                                                        |");                                     
  puts("| d888888P                                               |");                                      
  puts("|    88                                                  |");                                     
  puts("|    88    .d8888b. 88d888b. .d8888b. .d8888b. .d8888b.  |");  
  puts("|    88    88'  `88 88'  `88 88ooood8 88'  `88 Y8ooooo.  |");  
  puts("|    88    88.  .88 88       88.  ... 88.  .88       88  |"); 
  puts("|    dP    `88888P8 dP       `88888P' `88888P8 `88888P'  |");
  puts("|                                                        |");  
  puts("----------------------------------------------------------");
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
void subMenuModificar() {
    puts("===============================");
    puts("|      Modificar tarea        |");
    puts("|=============================|");
    puts("|1) Modificar descripcion     |");
    puts("|2) Modificar fecha de entrega|");
    puts("|3) Modificar Dificultad      |");
    puts("|4) Volver al menu principal  |");
    puts("===============================");
}


void subMenuMostrarTareas() {
    puts("================================");
    puts("|      Menu Mostrar tareas     |");
    puts("|==============================|");
    puts("|1) Mostrar todas las tareas   |");
    puts("|2) Mostrar por fecha          |");
    puts("|3) Mostrar por prioridad      |");
    puts("|4) Volver al menu principal   |");
    puts("===============================");
}

void subMenuBuscar() {
    puts("=============================");
    puts("|    Menu Buscar tarea      |");
    puts("|===========================|");
    puts("|1) Buscar por titulo       |");
    puts("|2) Buscar por fecha        |");
    puts("|3) Volver al menu principal|");
    puts("=============================");
}

int esBisiesto(int anyo) {
    return (anyo % 4 == 0 && anyo % 100 != 0) || (anyo % 400 == 0);
}
int esFechaValida(int dia, int mes, int anyo) {
    if (dia < 1 || mes < 1 || mes > 12) {
        return 0;
    }

    int diasEnMes[] = {0, 31, esBisiesto(anyo) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (dia > diasEnMes[mes]) {
        return 0;
    }

    return 1;
}
void solicitarFecha(FechaLimite *fecha) {
    int dia, mes, anyo;
    while (1) {
        printf("Ingrese fecha límite de la tarea (dd/mm/aaaa): ");
        int result = scanf("%d/%d/%d", &dia, &mes, &anyo);
        if (result == 3 && esFechaValida(dia, mes, anyo)) {
            fecha->dia = dia;
            fecha->mes = mes;
            fecha->anyo = anyo;
            break;
        } else {
            printf("Fecha inválida. Por favor, intente nuevamente.\n");
            while (getchar() != '\n'); // Limpiar el buffer de entrada
        }
    }
}


void AgregarTareasPendientes(Map *tareasTitulo, Map *tareasFecha, List *listaTareas) {

    tipoTarea *pendiente = (tipoTarea *)malloc(sizeof(tipoTarea));

    printf("=========================================\n");
    printf("Ingrese título de la tarea pendiente: ");
    scanf(" %[^\n]", pendiente->titulo);
    printf("Ingrese una descripción de la tarea pendiente: ");
    scanf(" %[^\n]", pendiente->descripcionTarea);
    solicitarFecha(&pendiente->fecha_limite);
    printf("Ingrese dificultad de la tarea pendiente (1-5): ");
    scanf("%d", &pendiente->dificultad);
    if (pendiente->dificultad < 1 || pendiente->dificultad > 5) {
        printf("Dificultad inválida, debe ser un valor entre 1 y 5\n");
        free(pendiente);
        return;
    }
    pendiente->prioridad = 3; // Prioridad por defecto
    pendiente->fecha_creacion = time(NULL);

    map_insert(tareasTitulo, pendiente->titulo, pendiente);

    char *fecha_str = fecha_to_string(pendiente->fecha_limite);
    map_insert(tareasFecha, fecha_str, pendiente);
    free(fecha_str);
    list_pushBack(listaTareas, pendiente);
    printf("======  Tarea registrada con éxito  ======\n\n");

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

void AsignarPrioridad(Map *tareasTitulo, List *listaTareas) {
    char titulo[100];
    int nuevaPrioridad;

    printf("=========================================\n");
    printf("Ingrese el título de la tarea pendiente: ");
    scanf(" %[^\n]", titulo);
    printf("Ingrese la nueva prioridad de la tarea pendiente (1-3): ");
    scanf("%d", &nuevaPrioridad);
    printf("=========================================\n");

    tipoTarea *tarea = (tipoTarea *)map_search(tareasTitulo, titulo);
    if (tarea != NULL) {
        tarea->prioridad = nuevaPrioridad;
        printf("Prioridad asignada con éxito\n");

        tipoTarea *tareaLista = (tipoTarea *)list_first(listaTareas);
        while (tareaLista != NULL) {
            if (strcmp(tareaLista->titulo, titulo) == 0) {
                tareaLista->prioridad = nuevaPrioridad;
                break;
            }
            tareaLista = (tipoTarea *)list_next(listaTareas);
        }
    } else {
        printf("Tarea no encontrada\n");
    }
}

void ModificarTarea(Map *tareasTitulo, Map *tareasFecha, List *listaTareas) {
    char titulo[100];
    char opcionModificar;

    printf("=========================================\n");
    printf("Ingrese el título de la tarea a modificar: ");
    scanf(" %[^\n]", titulo);
    printf("=========================================\n");

    tipoTarea *tarea = (tipoTarea *)map_search(tareasTitulo, titulo);
    if (tarea != NULL) {
        while (1) {
            subMenuModificar();
            printf("Ingrese su opción: ");
            scanf(" %c", &opcionModificar);

            if (opcionModificar == '4') {
                break;
            }

            switch (opcionModificar) {
                case '1':
                    printf("Descripción actual: %s\n", tarea->descripcionTarea);
                    printf("Ingrese la nueva descripción: ");
                    scanf(" %[^\n]", tarea->descripcionTarea);
                    break;
                case '2': {
                    char *old_fecha_str = fecha_to_string(tarea->fecha_limite);
                    printf("Fecha límite actual: %d/%d/%d\n", tarea->fecha_limite.dia, tarea->fecha_limite.mes, tarea->fecha_limite.anyo);
                    printf("Ingrese la nueva fecha límite (dd/mm/aaaa): ");
                    //scanf("%d/%d/%d", &tarea->fecha_limite.dia, &tarea->fecha_limite.mes, &tarea->fecha_limite.anyo);
                    solicitarFecha(&tarea->fecha_limite);
                    char *new_fecha_str = fecha_to_string(tarea->fecha_limite);
                    map_insert(tareasFecha, new_fecha_str, tarea);
                    free(new_fecha_str);
                    map_insert(tareasFecha, old_fecha_str, NULL);
                    free(old_fecha_str);
                    break;
                }
                case '3':
                    printf("Dificultad actual: %d\n", tarea->dificultad);
                    printf("Ingrese la nueva dificultad (1-5): ");
                    scanf("%d", &tarea->dificultad);
                    if (tarea->dificultad < 1 || tarea->dificultad > 5) {
                        printf("Dificultad inválida, debe ser un valor entre 1 y 5\n");
                        tarea->dificultad = 3; // Restablecer a valor por defecto en caso de entrada inválida
                    }
                    break;
                default:
                    printf("Opción no válida\n");
                    break;
            }

            tipoTarea *tareaLista = (tipoTarea *)list_first(listaTareas);
            while (tareaLista != NULL) {
                if (strcmp(tareaLista->titulo, titulo) == 0) {
                    strcpy(tareaLista->descripcionTarea, tarea->descripcionTarea);
                    tareaLista->fecha_limite = tarea->fecha_limite;
                    tareaLista->dificultad = tarea->dificultad;
                    break;
                }
                tareaLista = (tipoTarea *)list_next(listaTareas);
            }

            printf("Tarea modificada con éxito\n");
        }
    } else {
        printf("Tarea no encontrada\n");
    }
}

void BuscarTarea(Map *tareasTitulo, Map *tareasFecha) {
    char opcionBuscar;
    char titulo[100];
    int dia, mes, anyo;

    while (1) {
        subMenuBuscar();
        printf("Ingrese su opción: ");
        scanf(" %c", &opcionBuscar);

        if (opcionBuscar == '3') {
            break;
        }

        switch (opcionBuscar) {
            case '1':
                printf("Ingrese el título de la tarea a buscar: ");
                scanf(" %[^\n]", titulo);
                tipoTarea *tareaTitulo = (tipoTarea *)map_search(tareasTitulo, titulo);
                if (tareaTitulo != NULL) {
                    printf("=========================================\n");
                    printf("Título: %s\n", tareaTitulo->titulo);
                    printf("Descripción: %s\n", tareaTitulo->descripcionTarea);
                    printf("Fecha de entrega: %d/%d/%d\n", tareaTitulo->fecha_limite.dia,
                                                            tareaTitulo->fecha_limite.mes,
                                                            tareaTitulo->fecha_limite.anyo);
                    printf("Prioridad: %d\n", tareaTitulo->prioridad);
                    printf("Dificultad: %d\n", tareaTitulo->dificultad);
                    printf("=========================================\n");
                } else {
                    printf("Tarea no encontrada\n");
                }
                break;
            case '2':
                printf("Ingrese la fecha límite de la tarea a buscar (dd/mm/aaaa): ");
                scanf("%d/%d/%d", &dia, &mes, &anyo);
                FechaLimite fechaBuscar = {dia, mes, anyo};
                char *fechaBuscarStr = fecha_to_string(fechaBuscar);
                tipoTarea *tareaFecha = (tipoTarea *)map_search(tareasFecha, fechaBuscarStr);
                free(fechaBuscarStr);
                if (tareaFecha != NULL) {
                    printf("=========================================\n");
                    printf("Título: %s\n", tareaFecha->titulo);
                    printf("Descripción: %s\n", tareaFecha->descripcionTarea);
                    printf("Fecha de entrega: %d/%d/%d\n", tareaFecha->fecha_limite.dia,
                                                            tareaFecha->fecha_limite.mes,
                                                            tareaFecha->fecha_limite.anyo);
                    printf("Prioridad: %d\n", tareaFecha->prioridad);
                    printf("Dificultad: %d\n", tareaFecha->dificultad);
                    printf("=========================================\n");
                } else {
                    printf("Tarea no encontrada\n");
                }
                break;
            default:
                printf("Opción no válida\n");
                break;
        }
    }
}

void EliminarTareaCompletada(Map *tareasTitulo, Map *tareasFecha, List *listaTareas) {
    char titulo[100];

    printf("=========================================\n");
    printf("Ingrese el título de la tarea a eliminar: ");
    scanf(" %[^\n]", titulo);
    printf("=========================================\n");

    // Buscar la tarea en el mapa de títulos
    tipoTarea *tarea = (tipoTarea *)map_search(tareasTitulo, titulo);
    if (tarea != NULL) {
        // Eliminar la tarea del mapa de títulos
        map_insert(tareasTitulo, titulo, NULL);

        // Eliminar la tarea del mapa de fechas
        char *fecha_str = fecha_to_string(tarea->fecha_limite);
        map_insert(tareasFecha, fecha_str, NULL);
        free(fecha_str);

        // Eliminar la tarea de la lista
        tipoTarea *tareaLista = (tipoTarea *)list_first(listaTareas);
        ListNode *prev = NULL;
        ListNode *current = listaTareas->head;
        while (tareaLista != NULL) {
            if (strcmp(tareaLista->titulo, titulo) == 0) {
                if (prev == NULL) {
                    listaTareas->head = current->next;
                } else {
                    prev->next = current->next;
                }
                if (current == listaTareas->tail) {
                    listaTareas->tail = prev;
                }
                free(current->data);
                free(current);
                break;
            }
            prev = current;
            current = current->next;
            tareaLista = (tipoTarea *)list_next(listaTareas);
        }

        printf("Tarea eliminada con éxito\n");
    } else {
        printf("Tarea no encontrada\n");
    }
}



int main() {
    char opcion;
    Map *tareasTitulo = map_create(is_equal_str);
    Map *tareasFecha = map_create(is_equal_str);
    List *listaTareas = list_create();

    limpiarPantalla();
    inicio();
    presioneTeclaParaContinuar();
    limpiarPantalla();

    do {
        //limpiarPantalla();
        mostrarMenuPrincipal();
        printf("Ingrese su opción: ");
        scanf(" %c", &opcion);

        switch (opcion) {
            case '1':
                limpiarPantalla();
                AgregarTareasPendientes(tareasTitulo, tareasFecha, listaTareas);
                break;
            case '2':
                limpiarPantalla();
                AsignarPrioridad(tareasTitulo, listaTareas);
                break;
            case '3':
                limpiarPantalla();
                MostrarTareasPendientes(listaTareas);
                break;
            case '4':
                limpiarPantalla();
                ModificarTarea(tareasTitulo, tareasFecha, listaTareas);
                break;
            case '5':
                limpiarPantalla();
                BuscarTarea(tareasTitulo, tareasFecha);
                break;
            case '6':
                limpiarPantalla();
                EliminarTareaCompletada(tareasTitulo, tareasFecha, listaTareas);
                break;
            case '7':
                puts("Saliendo...\n");
                break;
            default:
                puts("Opción no válida\n");
        }
    } while (opcion != '7');

    list_clean(listaTareas);
    map_clean(tareasTitulo);
    map_clean(tareasFecha);

    return 0;
}
