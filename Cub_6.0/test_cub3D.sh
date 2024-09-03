#!/bin/bash

# Define an associative array with commands
declare -A tool_commands
tool_commands[fgrind]="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --show-reachable=yes --error-limit=no --track-fds=yes -s"
tool_commands[fcheckall]="funcheck -aos"

# Check if the correct number of arguments is given
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 path_to_maps [additional_program [program_options]]"
    exit 1
fi

# Assign command line arguments to variables
map_path=$1
additional_program=$2
shift 2  # Shift the first two arguments to get additional program options
program_options="$@"

# Check if test_results directory exists, if not, create it
if [ ! -d test_results ]; then
    mkdir test_results
fi

# Function to run the program and check for errors
run_program() {
    local map_file=$1
    local result_file="test_results/test_result_$(basename "$map_file")"

    # Print a separator for better readability
    echo "=================================================="

    # Determine if an additional program is used
    local command="./cub3D $map_file"
    local display_command="$command"
    if [ -n "$additional_program" ]; then
        if [[ ${tool_commands[$additional_program]+_} ]]; then
            command="${tool_commands[$additional_program]} $program_options $command"
        else
            command="$additional_program $program_options $command"
        fi
        display_command="$additional_program ./cub3D $map_file"
    fi

    # Execute the command and redirect both stdout and stderr to the result file
    echo "Running: $display_command"
    #$command 2>&1 | sed 's/\x1B\[[0-9;]*[JKmsu]//g' > "$result_file"
    $command 2>&1 | perl -pe 's/\e\[[0-9;]*m//g' | tr -cd '\11\12\15\40-\176' > "$result_file"
    check_errors "$result_file" "$map_file"
}

# Function to check for errors based on the additional program used
check_errors() {
    local result_file=$1
    local map_file=$2

    # Determine which program to check for errors
    if [[ $command == *"valgrind"* ]]; then
        # Check Valgrind output for errors
        if ! grep -q "in use at exit: 0 bytes in 0 blocks" "$result_file" ||
           ! grep -q "All heap blocks were freed -- no leaks are possible" "$result_file" ||
           ! grep -q "ERROR SUMMARY: 0 errors from 0 contexts" "$result_file"; then
            echo -e "\033[0;31mError found in map file: $map_file\033[0m"
        else
            echo -e "\033[0;32mTest passed: $map_file\033[0m"
        fi
    elif [[ $command == *"funcheck"* ]]; then
        # Check Funcheck output for errors
        if grep -q "failed," "$result_file" || 
           ! awk '/Function tests:/ {if ($3 != $(NF-2)) exit 1}' "$result_file" ||
           grep -q "when this function" "$result_file" ||
           grep -q "allocations are not freed" "$result_file" ||
           grep -q "is not freed" "$result_file"; then
            echo -e "\033[0;31mError found in map file: $map_file\033[0m"
        else
            echo -e "\033[0;32mTest passed: $map_file\033[0m"
        fi
    fi
}

# Check if the input is a directory or a file
if [ -d "$map_path" ]; then
    # It's a directory, run for each .cub file in the directory
    for map_file in "$map_path"/*.cub; do
        run_program "$map_file"
    done
elif [ -f "$map_path" ]; then
    # It's a file, run the program for this file
    run_program "$map_path"
else
    echo "Error: $map_path is neither a directory nor a file"
    exit 2
fi

