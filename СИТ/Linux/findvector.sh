#!/bin/bash
grep --include="*.cpp" -l -r "#include <vector>" . 2>/dev/null
