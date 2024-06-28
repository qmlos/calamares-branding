qt6_add_executable(LiveWelcome
    MANUAL_FINALIZATION
    main.cpp
    runner.cpp runner.h
)
set_target_properties(LiveWelcome PROPERTIES OUTPUT_NAME "liri-live-welcome")

set_source_files_properties(qml/Main.qml PROPERTIES
    QT_RESOURCE_ALIAS Main.qml
)
qt6_add_qml_module(LiveWelcome
    URI io.liri.LiveWelcome
    VERSION 1.0
    QML_FILES qml/Main.qml
)

file(GLOB ts_files "${CMAKE_CURRENT_SOURCE_DIR}/translations/*_*.ts")
qt6_add_translations(LiveWelcome
    TS_FILE_BASE "liri-live-welcome"
    TS_FILE_DIR "translations"
    TS_FILES ${ts_files}
    RESOURCE_PREFIX "/qt/qml/io/liri/LiveWelcome/i18n"
)

target_compile_definitions(LiveWelcome PRIVATE VERSION="${PROJECT_VERSION}")

target_link_libraries(LiveWelcome PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::QuickControls2
)

qt6_finalize_target(LiveWelcome)

install(TARGETS LiveWelcome DESTINATION ${KDE_INSTALL_BINDIR})
install(FILES io.liri.LiveWelcome.desktop DESTINATION ${KDE_INSTALL_SYSCONFDIR}/xdg/autostart)
