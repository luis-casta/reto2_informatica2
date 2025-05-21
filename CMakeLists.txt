cmake_minimum_required(VERSION 3.16)

project(desafio2_informatica2 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(desafio2_informatica2
  main.cpp
  README.md
  alojamiento.h alojamiento.cpp

  anfitrion.h anfitrion.cpp
  alojamiento.h alojamiento.cpp
  fecha.h fecha.cpp
  reservacion.h reservacion.cpp
  huesped.h huesped.cpp

)
target_link_libraries(desafio2_informatica2 Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS desafio2_informatica2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
