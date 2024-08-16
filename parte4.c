/*
* -------------------------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* Programación de Microprocesadores
* Descripción: programa que trabaja con dos arrays
* Autor:	   Leonardo Mejía
* Fecha:	   Agosto 15, 2024.
* -------------------------------------------------------------
*/

#include <stdio.h>
#include <omp.h> 
#include <math.h>

int hilos, a;

//Función que interactua con los usuarios. 
void useractions() 
{
    printf("Hola, bienvenido al programa\n");
    printf("A continuación ingrese la cantidad de hilos con los que desea trabajar\n");
    printf("Por favor ingrese 8, 16 o 32 hilos: ");
    
    scanf("%d", &hilos);
    while (hilos != 8 && hilos != 16 && hilos != 32)
    {
        printf("Por favor ingrese 8, 16 o 32 hilos: ");
        scanf("%d", &hilos);
    }
    printf("La cantidad de hilos que ha ingresado es: %d\n", hilos);
}

//Esta función crea los dos arrays que contendran los números dados. 
void arraycreation(int hilos){
    double x[hilos]; 
    double y[hilos];
    a = 5; //Condición en el documento
    printf("--------------------------------\n"); 
    printf("x               -              y\n"); 
    printf("--------------------------------\n");

    // Paralelización del bucle
    #pragma omp parallel for num_threads(hilos)
    for (int i = 0; i < hilos; i++){
        x[i] = 2 * (i + 1);  
        y[i] = (0.5) * a + pow(x[i], 2); 
        printf("%f | %f\n", x[i], y[i]);
    }

    printf("--------------------------------\n"); 
}

int main(){
    useractions();
    arraycreation(hilos);
    return 0; 
}
