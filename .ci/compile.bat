cmake -DCMAKE_INSTALL_PREFIX=%cd%\inst .
cmake --build . --config Release
cmake --build . --config Debug
