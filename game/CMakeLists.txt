# Путь к исходникам движка
set(DVIGLO_DIR "${CMAKE_SOURCE_DIR}/../engine")

# Указываем минимальную версию CMake
include(${DVIGLO_DIR}/cmake/cmake_min_version.cmake)
cmake_minimum_required(VERSION ${DV_CMAKE_MIN_VERSION})

# Название проекта
project(game)

# Подключаем директорию с движком
include(${DVIGLO_DIR}/cmake/common.cmake)
add_subdirectory(${DVIGLO_DIR} dviglo)

# Название таргета
set(TARGET_NAME game)

# Папка для скомпилированной игры
set(RESULT_DIR "${CMAKE_SOURCE_DIR}/result")

# Создаём список файлов
file(GLOB_RECURSE source_files src/*.cpp src/*.h)

# Папка для экзешника
dv_set_bin_dir(${RESULT_DIR})

# Создаём приложение
add_executable(${TARGET_NAME} ${source_files})

if(NOT DV_WIN32_CONSOLE)
    # Используем точку входа WinMain()
    set_property(TARGET ${TARGET_NAME} PROPERTY WIN32_EXECUTABLE TRUE)
endif()

# Отладочная версия приложения будет иметь суффикс _d
set_property(TARGET ${TARGET_NAME} PROPERTY DEBUG_POSTFIX _d)

# Подключаем библиотеку-движок к приложению
target_link_libraries(${TARGET_NAME} dviglo)

# Копируем динамические библиотеки в папку с приложением
dv_copy_shared_libs_to_bin_dir(${TARGET_NAME} ${RESULT_DIR} copy_shared_libs_to_app_dir)

# Копируем ресурсы к экзешнику, если нужно
file(MAKE_DIRECTORY ${RESULT_DIR})

if(NOT EXISTS ${RESULT_DIR}/CoreData)
    dv_create_symlink(${DVIGLO_DIR}/bin/CoreData ${RESULT_DIR}/CoreData)
endif()

if(NOT EXISTS ${RESULT_DIR}/Data)
    dv_create_symlink(${DVIGLO_DIR}/bin/Data ${RESULT_DIR}/Data)
endif()

# Заставляем Visual Studio отображать дерево каталогов
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/src FILES ${source_files})

# В Visual Studio таргет будет назначен стартовым вместо ALL_BUILD,
# чтобы потом не делать это вручную при отладке игры
set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${TARGET_NAME})
