

PROJECT( SIMPLib VERSION 0.0.1.0)

add_library(SIMPLib ${LIB_TYPE})

target_sources(SIMPLib 
  PUBLIC
    ${SIMPLib_SOURCE_DIR}/DataContainers/DataContainerArray.h
    ${SIMPLib_SOURCE_DIR}/DataContainers/DataContainerArray.cpp

    ${SIMPLib_SOURCE_DIR}/DataContainers/DataContainer.h
    ${SIMPLib_SOURCE_DIR}/DataContainers/DataContainer.cpp
    ${SIMPLib_SOURCE_DIR}/DataContainers/DataContainerModel.h
    ${SIMPLib_SOURCE_DIR}/DataContainers/DataContainerModel.cpp

    ${SIMPLib_SOURCE_DIR}/DataContainers/AttributeMatrix.h
    ${SIMPLib_SOURCE_DIR}/DataContainers/AttributeMatrix.cpp
    ${SIMPLib_SOURCE_DIR}/DataContainers/AttributeMatrixModel.h
    ${SIMPLib_SOURCE_DIR}/DataContainers/AttributeMatrixModel.cpp
    
    ${SIMPLib_SOURCE_DIR}/DataContainers/IDataArray.h
    ${SIMPLib_SOURCE_DIR}/DataContainers/IDataArray.cpp
    ${SIMPLib_SOURCE_DIR}/DataContainers/IDataArrayModel.h
    ${SIMPLib_SOURCE_DIR}/DataContainers/IDataArrayModel.cpp
                
    ${SIMPLib_SOURCE_DIR}/SIMPLibGlobal.h
  )
  target_include_directories(SIMPLib PUBLIC ${ModernSIMPL_SOURCE_DIR}/Source)
