#!/bin/bash

echo "main.cpp" | entr sh -c 'g++ main.cpp -o main && ./main'
