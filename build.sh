#!/bin/sh

set -xe

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c -o main
