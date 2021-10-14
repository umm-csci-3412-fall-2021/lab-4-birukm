#!/bin/bash

# Passed Argument
DIR=$1

echo "There were "$(find "$DIR" -maxdepth 16 -type d -print | wc -l | xargs)" directories."

echo "There were "$(find "$DIR" -maxdepth 16 -type f -print | wc -l | xargs)" regular files."