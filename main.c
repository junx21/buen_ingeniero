#include <stdio.h>

#define NUM_TECLAS 10

// Movimientos posibles del caballo para cada número en el teclado
int movimientos[NUM_TECLAS][4] = {
    {4, 6, -1, -1},   // 0
    {6, 8, -1, -1},   // 1
    {7, 9, -1, -1},   // 2
    {4, 8, -1, -1},   // 3
    {3, 9, 0, -1},    // 4
    {-1, -1, -1, -1}, // 5 no tiene movimientos válidos
    {1, 7, 0, -1},    // 6
    {2, 6, -1, -1},   // 7
    {1, 3, -1, -1},   // 8
    {2, 4, -1, -1}    // 9
};

// Función para calcular las posibilidades válidas de movimientos
long long contar_movimientos(int n) {
    long long dp[NUM_TECLAS], nuevo_dp[NUM_TECLAS];

    // Inicializar dp con 1 movimiento inicial desde cada número
    for (int i = 0; i < NUM_TECLAS; i++) {
        dp[i] = 1;
    }

    // Iterar n veces para calcular los movimientos válidos
    for (int m = 0; m < n; m++) {
        // Inicializar nuevo_dp a 0
        for (int i = 0; i < NUM_TECLAS; i++) {
            nuevo_dp[i] = 0;
        }

        // Actualizar nuevo_dp basado en los movimientos del caballo
        for (int i = 0; i < NUM_TECLAS; i++) {
            for (int j = 0; movimientos[i][j] != -1; j++) {
                nuevo_dp[i] += dp[movimientos[i][j]];
            }
        }

        // Copiar nuevo_dp a dp para la siguiente iteración
        for (int i = 0; i < NUM_TECLAS; i++) {
            dp[i] = nuevo_dp[i];
        }
    }

    // Sumar todas las posibilidades desde cualquier número
    long long total = 0;
    for (int i = 0; i < NUM_TECLAS; i++) {
        total += dp[i];
    }

    return total;
}

int main() {
    int n;

    // Pedir al usuario que introduzca la cantidad de movimientos
    printf("Introduce la cantidad de movimientos: ");
    scanf("%d", &n);

    // Calcular las posibilidades válidas para la cantidad de movimientos introducida
    long long resultado = contar_movimientos(n);

    // Mostrar el resultado
    printf("La cantidad de posibilidades válidas para %d movimientos es: %lld\n", n, resultado);

    return 0;
}