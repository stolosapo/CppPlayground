#!/bin/bash

FILENAME=$1
DESTINATION=$2

curl -X POST -H "Content-Type: application/json" -d @"$FILENAME" "$DESTINATION"