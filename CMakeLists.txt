cmake_minimum_required(VERSION 3.16)

project(ZadanieProgramistyczneED VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Widgets)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appZadanieProgramistyczneED
    main.cpp
)

qt_add_qml_module(appZadanieProgramistyczneED
    URI ZadanieProgramistyczneED
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES UI/TopBar/TopBar.qml
        QML_FILES UI/Separator/Separator.qml
        QML_FILES UI/LeftScreen/LeftScreen.qml
        QML_FILES UI/LeftScreen/ConfusionMatrix_L.qml
        QML_FILES UI/LeftScreen/Metrics_L.qml
        QML_FILES UI/LeftScreen/ROCGraph_L.qml
        QML_FILES UI/RightScreen/RightScreen.qml
        QML_FILES UI/RightScreen/ROCGraph_R.qml
        QML_FILES UI/RightScreen/Metrics_R.qml
        QML_FILES UI/RightScreen/ConfusionMatrix_R.qml
        QML_FILES UI/LeftScreen/MetricsRegresion_L.qml
        QML_FILES UI/RightScreen/MetricsRegresion_R.qml
        SOURCES Backend/Csvreader.h Backend/Csvreader.cpp
        SOURCES Backend/modelanalysis.h Backend/modelanalysis.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appZadanieProgramistyczneED PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appZadanieProgramistyczneED
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appZadanieProgramistyczneED
    PRIVATE Qt6::Quick Qt6::Widgets
)

include(GNUInstallDirs)
install(TARGETS appZadanieProgramistyczneED
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
