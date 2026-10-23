if (NOT TARGET mcu-interactive-ui)

    add_library(mcu-interactive-ui STATIC
        src/interactive-ui/DisplayInterface.cpp
        src/interactive-ui/Screen.cpp
        src/interactive-ui/ScreenManager.cpp
        src/interactive-ui/Component.cpp
        src/interactive-ui/SelectableComponent.cpp
        src/interactive-ui/ComponentPack.cpp
        src/interactive-ui/components/PixelGridComponent.cpp
        src/interactive-ui/components/PixelMapComponent.cpp
        src/interactive-ui/components/PaddingComponent.cpp
        src/interactive-ui/components/BitmapComponent.cpp
        src/interactive-ui/components/TextComponent.cpp
        src/interactive-ui/components/DropDownBoxComponent.cpp
        src/interactive-ui/components/FunctionComponent.cpp
        src/interactive-ui/components/ProgressBarComponent.cpp
        src/interactive-ui/graphics/Rasterization.cpp
        src/interactive-ui/graphics/Font.cpp
    )

    add_subdirectory(lib/mcu-math)
    add_subdirectory(lib/mcu-event-hardware)
    add_subdirectory(lib/mcu-storage-device)

    target_include_directories(mcu-interactive-ui PUBLIC
        include
    )

    target_link_libraries(mcu-interactive-ui
        mcu-platform-interface
        mcu-math
        mcu-event-hardware
        mcu-storage-device
    )

endif()