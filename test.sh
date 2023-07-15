#!/bin/bash

# Function to generate a random permutation of numbers
generate_random_permutation() {
    shuf -i 1-$1 | tr '\n' ' '
}

# Function to calculate the grade based on instruction count
calculate_grade() {
    local instruction_count=$1
    local grade=0

    if [[ $instruction_count -lt 700 ]]; then
        grade=5
    elif [[ $instruction_count -lt 900 ]]; then
        grade=4
    elif [[ $instruction_count -lt 1100 ]]; then
        grade=3
    elif [[ $instruction_count -lt 1300 ]]; then
        grade=2
    elif [[ $instruction_count -lt 1500 ]]; then
        grade=1
    fi

    echo $grade
}

# Test
NUM_ITERATIONS=5

for ((i=1; i<=$NUM_ITERATIONS; i++)); do
    ARG=$(generate_random_permutation 100)
    output=$(./push_swap $ARG | ./checker $ARG)
    instruction_count=$(./push_swap $ARG | wc -l)

    if [[ $output == "OK" ]]; then
        grade=$(calculate_grade $instruction_count)
        echo "Test - Iteration $i: Grade $grade"
    else
        echo "Test - Iteration $i: Failed"
    fi
done
