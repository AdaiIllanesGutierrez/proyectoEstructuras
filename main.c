#include "tdas/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
int id;
char* titulo[100];
char* descripcionTarea[200];
time_t fecha_creacion,fecha_limite;
int prioridad,dificultad;
List* list;
} Tarea;

void limpiarPantalla() { system("clear"); }
void presioneTeclaParaContinuar()
{
  puts("Presione una tecla para continuar...");
  getchar(); // Consume el '\n' del buffer de entrada
  getchar(); // Espera a que el usuario presione una tecla
}

void mostrarMenuPrincipal()
{
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
  puts("     Tarea");
  puts("========================================");
  puts("1) Mostrar tarea");
  puts("2) Modificar tarea");
  puts("3) Buscar tarea");
  puts("4) Salir");
  
*/

int main(void)
{
  char opcion;
  //List *tareas = createList();
  do
  {
    mostrarMenuPrincipal();
    printf("Ingrese su opción: ");
    scanf(" %c", &opcion); 

    switch (opcion)
    {
    case '1':
      //AgregarTareasPendientes();
      break;
    case '2':
      //AsignarPrioridad();
      break;
    case '3':
      //MostrarTareasPendientes();
      break;
    case '4':
      //ModificarTarea();
      break;
    case '5':
      //BuscarTareas();
      break;
    case '6':
      //EliminarTareaCompletada();
      break;
      case '7':
      printf("Saliendo...\n");
      break;
    default:
      printf("Opción no válida\n");
    }
    presioneTeclaParaContinuar();

  }while (opcion != '7');

  list_clean();

  return 0;
}