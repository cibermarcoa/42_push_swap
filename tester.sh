#!/bin/bash

# Test 1
ARG="1 5 2 4 3"
output=$(./push_swap $ARG | ./checker $ARG)
instructions=$(echo "$output" | wc -l)
if [[ $output == "OK" && $instructions -le 12 ]]; then
  echo "Test 1: Passed"
  if [[ $instructions -le 8 ]]; then
    echo "Kudos! Size of instructions <= 8"
  fi
else
  echo "Test 1: Failed"
fi

# Test 2 (repeated multiple times)
for i in {1..5}; do
  ARG=$(shuf -i 1-100 -n 5 | tr '\n' ' ')
  output=$(./push_swap $ARG | ./checker $ARG)
  instructions=$(echo "$output" | wc -l)
  if [[ $output == "OK" && $instructions -le 12 && ! $ARG =~ ([0-9]+).*\1 ]]; then
    echo "Test 2 ($i): Passed"
  else
    echo "Test 2 ($i): Failed"
  fi
done

