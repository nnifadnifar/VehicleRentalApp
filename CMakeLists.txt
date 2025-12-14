cmake_minimum_required(VERSION 3.16)

project(rental_motor VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        views/mainwindow.cpp
        views/mainwindow.h
        views/mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(rental_motor
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        models/motorcycle.h models/motorcycle.cpp
        models/IEntity.h
        utils/datahandler.h utils/datahandler.cpp
        utils/idgenerator.h utils/idgenerator.cpp
        models/customer.h models/customer.cpp
        models/vehicle.h models/vehicle.cpp
        models/car.h models/car.cpp
        models/transaction.h models/transaction.cpp
        models/transactiondays.h models/transactiondays.cpp
        controllers/Icontroller.h
        controllers/usercontroller.h controllers/usercontroller.cpp
        controllers/vehiclecontroller.h controllers/vehiclecontroller.cpp
        controllers/rentalcontroller.h controllers/rentalcontroller.cpp
        views/userview.h views/userview.cpp
        views/transactionview.h views/transactionview.cpp
        views/productview.h views/productview.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET rental_motor APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(rental_motor SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(rental_motor
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(rental_motor PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.rental_motor)
endif()
set_target_properties(rental_motor PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS rental_motor
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(rental_motor)
endif()
