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
  
  for(int i = 0; i < N; i++){
    free(compus[i].tipo_cpu);
  }
  return 0;
}