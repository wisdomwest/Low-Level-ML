#!/bin/sh

set -xe

gcc -Wall -Werror -Wextra -pedantic  twice-model.c -o main
gcc -Wall -Werror -Wextra -pedantic  xor-model.c -o xor
