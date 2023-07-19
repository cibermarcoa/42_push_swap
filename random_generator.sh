#!/bin/bash


#  ARG="-673 -693 -290 -377 244 139 747 -466 -434 95 711 749 943 715 97"; ./push_swap $ARG | wc -l
#  ARG="-707 -60 -809 -849 -654 893 -560 -584 -329 -842 -78 -9 848 258 -752"; ./push_swap $ARG | wc -l
#  ARG="-945 -441 -494 -978 208 419 640 343 176 120 -167 203 316 882 -467"; ./push_swap $ARG | wc -l
#  ARG="126 -482 -788 -907 477 163 -448 276 -939 -262 829 -289 -459 112 -681"; ./push_swap $ARG | wc -l
#  ARG="-786 25 -564 191 -166 379 -768 673 830 -442 -122 907 769 354 846"; ./push_swap $ARG | wc -l
#  ARG="-695 211 -429 -139 973 -857 98 906 731 678 334 -861 -737 -311 530"; ./push_swap $ARG | wc -l

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
random_numbers=$(generate_unique_random_numbers -50000 50000 500)

# Imprimir los números aleatorios generados
echo "${random_numbers[@]}"
