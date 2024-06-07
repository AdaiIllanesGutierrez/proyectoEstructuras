#include "tdas/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
int id;
char* titulo;
time_t hora_registro;
int prioridad;
List* list;
}Tarea;

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
  puts("4) Eliminar tarea completada ");
  puts("5) Buscar tarea");
  puts("6) Modificar Tarea");
  puts("7) Salir");
}
/*SUBMENU MODO BETA

  */

int main(void)
{
  
  char opcion;
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
      //EliminarTareaCompletada();
      break;
    case '5':
      //BuscarTareas();
      break;
    case '6':
      //ModificarTarea();
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