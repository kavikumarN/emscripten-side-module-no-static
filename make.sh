#!/bin/sh

ARGS="-s EMULATED_FUNCTION_POINTERS=1 -s EMULATE_FUNCTION_POINTER_CASTS=1 -s WASM=1 --memory-init-file 0 --minify 0"

emcc $ARGS -s SIDE_MODULE=1 mod1.c -s EXPORTED_FUNCTIONS='["_mod1func"]' -o mod1.js
mv mod1.wasm mod1.so
emcc $ARGS -s MAIN_MODULE=1 main.c -o EXPORTED_FUNCTIONS='["_main", "global.Math"]' -o main.html --preload-file mod1.so
