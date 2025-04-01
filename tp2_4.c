#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 5

struct compu {
  int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3)
  int anio; // Año de fabricación (valor entre 2015 y 2024)
  int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
  char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres)
};

void listarPCs(struct compu pcs[], int cantidad);
void mostrarMasVieja(struct compu pcs[], int cantidad);

int main(){
  srand(time(NULL));
  struct compu compus[N];
  char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

  for(int i = 0; i < N; i++){
    compus[i].velocidad = (rand() % (3 - 1 + 1)) + 1;
    compus[i].anio = (rand() % (2024 - 2015 + 1)) + 2015;
    compus[i].cantidad_nucleos = (rand() % (8 - 1 + 1)) + 1;

    compus[i].tipo_cpu = (char *)malloc(10 * sizeof(char));
    strcpy(compus[i].tipo_cpu, tipos[(rand() % 3) + 1]);
  }

  listarPCs(compus, N);
  mostrarMasVieja(compus, N);
  
  for(int i = 0; i < N; i++){
    free(compus[i].tipo_cpu);
  }
  return 0;
}

void listarPCs(struct compu pcs[], int cantidad){
  for (int i = 0; i < cantidad; i++) {
    printf("\n===== Computadora %d =====\n", i+1);
    printf("Velocidad de procesamiento (GHz): %d\n", pcs[i].velocidad);
    printf("Anio de fabricacion: %d\n", pcs[i].anio);
    printf("Cantidad de nucleos: %d\n", pcs[i].cantidad_nucleos);
    printf("Tipo de procesador: %s\n", pcs[i].tipo_cpu);
  }
}

void mostrarMasVieja(struct compu pcs[], int cantidad){
  int mas_vieja = 0;
  for (int i = 1; i < cantidad; i++) {
    if (pcs[i].anio < pcs[mas_vieja].anio) {
      mas_vieja = i;
    }
  }

  printf("\n===== Computadora mas vieja =====\n");
  printf("Velocidad de procesamiento (GHz): %d\n", pcs[mas_vieja].velocidad);
  printf("Anio de fabricacion: %d\n", pcs[mas_vieja].anio);
  printf("Cantidad de nucleos: %d\n", pcs[mas_vieja].cantidad_nucleos);
  printf("Tipo de procesador: %s\n", pcs[mas_vieja].tipo_cpu);
}