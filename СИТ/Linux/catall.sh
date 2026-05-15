#!/bin/bash

output="all_songs.txt"
> "$output"
cat people_in_the_air/*/*.txt >> "$output"
