cmake_minimum_required(VERSION 3.5)

project(v3test LANGUAGES CXX)

# Für QT5-Entwicklung unter ubuntu muss noch
#    qt5-base
# installiert werden
#
# Einstellung für das Extra-Terminal befinden sich im QtCreator
#  1) links auf "Projekte" -> "Ausführen" -> "In Terminal starten"
#  2) falls sich das Terminal nicht öffnet, dann
#     im Menü "Extras" -> "Einstellungen" -> "Umgebung" -> "System" -> "Terminal"
#     das korrekt Terminalprogramm auswählen (z. B. /bin/gnome-terminal)
#     Standard ist der Terminal-Emulator, der unter Ubuntu/Debian Probleme macht.
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Threads REQUIRED)

### GoogleTest ###
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

#
# Nachfolgend werden die Quelldateien des Projekts festgelegt
#
set(PROJECT_SOURCES
        include/Bohrung.hpp src/Bohrung.cpp include/TElement.hpp include/IKomponente.hpp
        include/Fraesung.hpp src/Fraesung.cpp
        include/DeList.hpp include/DeList_impl.hpp
        include/Iterator.hpp include/Iterator_impl.hpp
        include/Serializer.hpp src/Serializer.cpp
        include/Komponente.hpp src/Komponente.cpp
        include/Werkstueck.hpp src/Werkstueck.cpp)

add_executable(v3test v3test_main.cpp v3test.h
        ${GTestFiles} ${PROJECT_SOURCES})
#[[add_executable(v3test p02Main.cpp
        ${GTestFiles} ${PROJECT_SOURCES})]]
add_test(NAME v3test COMMAND v3test)

target_link_libraries(v3test Threads::Threads)
target_link_libraries(v3test Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(v3test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(v3test)
