#Config por defecto
cmake_minimum_required(VERSION 3.23)
project(vecalculator)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Includes para no tener que escribir los path de los imports
INCLUDE_DIRECTORIES("src/lib")
INCLUDE_DIRECTORIES("src/include")
INCLUDE_DIRECTORIES("src/qt")

# Paquetes necesarios para la compilación
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        PrintSupport REQUIRED
        )

# Archivos a compilar
add_executable(vecalculator
        src/main.cpp
        src/lib/qcustomplot.cpp src/lib/qcustomplot.h
        src/include/vectores.cpp src/include/vectores.h
        src/include/vec_result.cpp src/include/vec_result.h
        src/qt/vecalculator.h src/qt/vecalculator.ui src/qt/vecalculator.cpp src/include/Vecalculator_vectores.cpp src/include/Vecalculator_vectores.h src/include/operaciones.cpp src/include/operaciones.h)

# Linkado de los paquetes
target_link_libraries(vecalculator
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::PrintSupport
        )

# Ubicación por defecto para computador de ayudante
IF(EXISTS /home/joaquin)
    set(CMAKE_PREFIX_PATH "/home/joaquin/Qt/5.15.2/gcc_64/lib/cmake")
    endif()

# Configuraciones al ejecutarse en windows (ubaciones de carpetas, copia de librerias, entre otros)
if (WIN32)
    IF(EXISTS "C:/Qt/5.15.2/mingw81_64/")
        set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/mingw81_64/")
    endif()
    IF(EXISTS "C:/Qt/5.15.2/mingw81_64/bin")
        set(CMAKE_PREFIX_PATH "D:/Qt/5.15.2/mingw81_64/")
    endif()
    ####################################################################################################################
    #set(CMAKE_PREFIX_PATH "D:/Qt/5.15.2/mingw81_64/") #-----> reemplazar por la ubicación de su instalación de Qt y descomentar
    #  En caso de errores comentar de la linea 46 a la 51 y luego descomentar el set con la instalacion personalizada
    ####################################################################################################################
    set(CMAKE_EXE_LINKER_FLAGS "-static")
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets PrintSupport)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()