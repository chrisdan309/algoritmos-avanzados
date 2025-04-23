# Pruebas unitarias

Se usa GoogleTest para las pruebas unitarias en c++

```
https://google.github.io/googletest/
```

Ejecuta el siguiente comando para configurar el proyecto en modo Debug (necesario para debugging con GDB):

```sh
cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build
```

Compila el proyecto

```sh
cmake --build build
```

Puedes correr todos los tests definidos con CMake y GoogleTest usando

```sh
cd build && ctest
```


Esto ejecutará todos los tests descubiertos automáticamente por ``gtest_discover_tests(new_test)`` del CMakeLists.txt

Si quieres debuggear usa 

```sh
gdb ./build/new_test
```

Dentro del ``gdb`` podemos correr los siguientes comandos

```sh
(gdb) break 19
(gdb) break math_utils.cpp:4
(gdb) run
(gdb) print x
(gdb) step
(gdb) continue
```


Para usar gprof debemos configurar el proyecto de la siguiente manera

```sh
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS="-pg" -S . -B build
```

Y luego guardamos el out en perfil.txt

```sh
gprof ./build/new_test gmon.out > perfil.txt
```
