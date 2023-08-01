#!/bin/bash

# Número de elementos para la lista aleatoria
NUM_ELEMENTS=5

# Rango de valores para los elementos de la lista aleatoria
MIN_VALUE=-100
MAX_VALUE=100

# Función para generar una lista aleatoria de números sin repetir
generate_random_list() {
    local generated_numbers=()
    while [ ${#generated_numbers[@]} -lt $NUM_ELEMENTS ]; do
        local new_num=$((RANDOM % ($MAX_VALUE - $MIN_VALUE + 1) + $MIN_VALUE))
        if [[ ! " ${generated_numbers[@]} " =~ " $new_num " ]]; then
            generated_numbers+=("$new_num")
        fi
    done

    echo "${generated_numbers[@]}"
}

# Convertir la lista generada a un string separado por espacios
ARG=$(generate_random_list | tr '\n' ' ')

# Mostrar el argumento generado
echo "Argumento generado: $ARG"

# Ejecutar push_swap con el argumento generado y redirigir la salida a checker
RESULT=$(./push_swap $ARG | ./checker $ARG)

# Comprobar el resultado
if [ "$RESULT" = "OK" ]; then
    echo "¡La secuencia es correcta (OK)!"
else
    echo "¡La secuencia NO es correcta!"
fi
