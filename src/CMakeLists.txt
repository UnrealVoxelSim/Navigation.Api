add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/public>" "$<INSTALL_INTERFACE:include>")
target_link_libraries(
    ${PROJECT_NAME}
    INTERFACE
        UnrealVoxelSim.Math.Api
        UnrealVoxelSim.Movement.Api
        UnrealVoxelSim.Spatial.Api
)
UnrealVoxelSimConfigureTarget(${PROJECT_NAME})
