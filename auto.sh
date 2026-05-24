#/bin/bash

cmake -B build -G Ninja
ninja -C build
cd build
./game
cd ..
