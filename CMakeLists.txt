cmake_minimum_required(VERSION 3.15)
project(SequentialLibrary C CXX)

# 1. Definir los archivos fuente de la librería
set(LIB_SOURCES
    src/sequential.cpp
    src/internal/componentes/led/led.cpp
    src/internal/componentes/motors/motoreductor.cpp
    src/internal/logger/logger.cpp # Asegúrate de renombrar el archivo a doble 'g'
)

# 2. Crear la librería estática
add_library(sequential ${LIB_SOURCES})

# 3. Configurar las rutas de inclusión (Headers)
# Al incluir la raíz de 'src', las subcarpetas se pueden llamar de forma interna y limpia
target_include_directories(sequential PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# 4. Incluir el directorio de ejemplos
add_subdirectory(examples/BasicSequential)
