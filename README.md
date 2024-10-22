# Link a Repositorio

https://github.com/junx21/buen_ingeniero.git

# Cálculo de Movimientos Válidos del Caballo en un Teclado Numérico

Para encontrar una fórmula matemática que calcule el número de movimientos válidos del caballo en un teclado numérico, primero debemos reconocer que el problema es más adecuado para resolverse usando técnicas de programación dinámica o recursión. Sin embargo, podemos aproximarnos a una **relación de recurrencia**, que es una expresión matemática que define una secuencia en función de términos anteriores.

Dado que los movimientos del caballo dependen de la posición actual y el número de movimientos restantes, es difícil encontrar una fórmula cerrada que calcule el número exacto de movimientos válidos sin recurrir a un proceso iterativo o recursivo. Sin embargo, podemos definir el problema como sigue:

## Relación de recurrencia

Sea `M(i, k)` la cantidad de trayectorias válidas comenzando desde el número `i` y con `k` movimientos restantes.

- **Condición base**: Si `k = 0`, es decir, si no quedan movimientos por hacer, entonces hay exactamente 1 camino válido (el que no se mueve):

  \[
  M(i, 0) = 1
  \]

- **Relación recursiva**: Si quedan `k > 0` movimientos, la cantidad de trayectorias válidas desde `i` con `k` movimientos restantes es la suma de todas las trayectorias posibles desde los números a los que el caballo puede moverse, con `k-1` movimientos restantes. Esto se expresa como:

  \[
  M(i, k) = \sum_{j \in vecinos(i)} M(j, k - 1)
  \]

  donde `vecinos(i)` representa los números a los que el caballo puede moverse desde `i`.

## Definición de vecinos

Los vecinos de cada número en el teclado numérico están predefinidos como:

- `vecinos(1) = [6, 8]`
- `vecinos(2) = [7, 9]`
- `vecinos(3) = [4, 8]`
- `vecinos(4) = [3, 9, 0]`
- `vecinos(5) = []`
- `vecinos(6) = [1, 7, 0]`
- `vecinos(7) = [2, 6]`
- `vecinos(8) = [1, 3]`
- `vecinos(9) = [2, 4]`
- `vecinos(0) = [4, 6]`

## Cálculo total de movimientos válidos

La cantidad total de movimientos válidos para `k` movimientos es la suma de todas las trayectorias posibles comenzando desde cualquier número del teclado:

\[
T(k) = \sum_{i = 0}^{9} M(i, k)
\]

### Ejemplo con 1 movimiento:

Para `k = 1`:

\[
T(1) = M(0, 1) + M(1, 1) + ⋯ + M(9, 1)
\]

Ya que cada `M(i, 1)` es simplemente el número de vecinos de `i`, la suma da un total de 20 trayectorias válidas.


### Explicación matemática del ajuste polinómico

Dado que no conocemos una fórmula explícita para calcular la cantidad de movimientos válidos del caballo en el problema planteado, hemos usado un método de **interpolación polinómica**. Este método toma puntos conocidos de datos y ajusta una ecuación polinómica para aproximar los valores intermedios y extrapolar los faltantes.

### Procedimiento

1. **Puntos conocidos**: Tenemos los siguientes puntos de referencia para la cantidad de movimientos válidos (\( y \)) según el número de movimientos realizados (\( x \)):
   
   \[
   (1, 20), \quad (2, 46), \quad (3, 104)
   \]
   
2. **Ajuste polinómico**: Utilizamos estos puntos para ajustar un polinomio de grado 2 de la forma:
   
   \[
   P(x) = ax^2 + bx + c
   \]
   
   A partir de estos datos, el polinomio que mejor se ajusta es:

   \[
   P(x) = 22x^2 - 2x + 0
   \]

   Este polinomio describe de manera aproximada el crecimiento del número de movimientos válidos para cada \( x \).

3. **Cálculo de valores futuros**: Usamos este polinomio para estimar los valores de movimientos válidos cuando \( x = 5, 8, 10, 15, 18, 21, 23, 32 \).

### Tabla de resultados

Aquí está la tabla completa con la fórmula y los valores estimados:

# Movimientos


| Nº pasos | Simulación     |
|----------|----------------|
| 1        | 20             |
| 2        | 46             |
| 3        | 104            |
| 5        | 544            |
| 8        | 6576           |
| 10       | 34432          |
| 15       | 2140672        |
| 18       | 25881088       |
| 21       | 307302400      |
| 23       | 1609056256     |
| 32       | 2792668987392  |



### Fórmula general:

La fórmula matemática aproximada para estimar el número de posibilidades válidas en función del número de movimientos \( x \) es:

\[
P(x) = 22x^2 - 2x
\]

Esta fórmula permite estimar los valores futuros basándose en los datos conocidos y el ajuste polinómico que hemos realizado.


## Conclusión

No existe una fórmula cerrada simple para este problema porque el número de trayectorias válidas depende de las posiciones y movimientos del caballo, que forman una red interconectada. Sin embargo, la relación de recurrencia:

\[
M(i, k) = \sum_{j \in vecinos(i)} M(j, k - 1)
\]

es la clave para calcular el número de trayectorias válidas para cualquier cantidad de movimientos `k`.

Para resolver el problema de manera eficiente, es necesario implementar esta recurrencia utilizando **programación dinámica** o recursión con **memoización**.

# Descripción del Problema

Queremos calcular la cantidad de movimientos válidos que puede hacer el caballo de ajedrez en un teclado numérico (como el de un teléfono) con ciertas restricciones:

- El caballo se mueve como en el ajedrez, es decir, en forma de "L".
- El teclado está organizado así:

1 2 3
4 5 6
7 8 9
0


A partir de una posición inicial (cualquier número del teclado), debes contar cuántos movimientos válidos se pueden hacer con el caballo.

## Plan de Implementación

1. **Estructura del teclado numérico**: Definimos los posibles movimientos válidos del caballo en cada casilla.
2. **Entrada**: El número de movimientos permitidos.
3. **Recursividad o programación dinámica**: Implementamos una función que recorra el teclado numérico desde cada posición inicial, contando las combinaciones de movimientos válidos.

## Solución en C

# Explicación del Código

## Matriz de Movimientos

La matriz `movements` indica las posiciones válidas a las que el caballo puede moverse desde cada número del teclado. Si un número no tiene más movimientos válidos, usamos `-1` para marcarlo.

## Función Recursiva `valid_moves`

Esta función toma como entrada la posición actual (`start`) y el número de movimientos restantes (`moves_remaining`).

- Si no quedan movimientos, la función devuelve 1 porque hemos encontrado una secuencia válida.
- De lo contrario, la función suma los posibles movimientos recursivamente.

## Función `main`

- Itera a través de todas las posiciones del teclado (del 0 al 9) y llama a la función recursiva para contar los movimientos válidos desde cada número.
- El número de movimientos a realizar se define por la variable `moves`.

## Salida

Imprime el número total de movimientos válidos.

## Ejecución

Para ejecutar el programa:

1. Cambia el valor de la variable `moves` en el `main` para calcular los movimientos válidos con diferentes números de movimientos.
2. Compila y ejecuta el programa:

   ```bash
   gcc caballo_teclado.c -o caballo_teclado
   ./caballo_teclado
