#!/bin/bash

# Función para generar un número aleatorio
generate_random_number() {
    local min=$1
    local max=$2
    echo $(( RANDOM % (max - min + 1) + min ))
}

# Función para generar 500 números aleatorios sin repeticiones
generate_unique_random_numbers() {
    local min=$1
    local max=$2
    local count=$3

    if [[ $((max - min + 1)) -lt $count ]]; then
        echo "El rango de números no es suficiente para generar $count números únicos."
        exit 1
    fi

    local numbers=()
    local num

    while (( ${#numbers[@]} < count )); do
        num=$(generate_random_number $min $max)

        # Verificar que el número generado no esté en el array
        if ! [[ "${numbers[*]}" =~ (^|[[:space:]])"$num"($|[[:space:]]) ]]; then
            numbers+=($num)
        fi
    done

    echo "${numbers[@]}"
}

# Generar 500 números aleatorios entre -1000 y 1000 (puedes ajustar los rangos si es necesario)
random_numbers=$(generate_unique_random_numbers -1000 1000 500)

# Imprimir los números aleatorios generados
echo "${random_numbers[@]}"
