#!/bin/bash

# Script to create and write the acronym
# to a file within the .datfiles directory.

filename="$1" # filename variable.
path="../.datfiles/" # path variable.

# Create the file.
touch "$path""$filename"
# Write the acronym to the file.
echo "$1 :" | tr '[:lower:]' '[:upper:]'> "$path""$filename"
# Open the file with the system editor.
$EDITOR "$path""$filename"

