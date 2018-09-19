

PROJECT( SIMPLib VERSION 0.0.1.0)

add_library(SIMPLib ${LIB_TYPE})

target_sources(SIMPLib 
  PUBLIC
    ${SIMPLib_SOURCE_DIR}/DataContainers/DataContainer.h
    ${SIMPLib_SOURCE_DIR}/DataContainers/DataContainer.cpp
    ${SIMPLib_SOURCE_DIR}/DataContainers/AttributeMatrix.h
    ${SIMPLib_SOURCE_DIR}/DataContainers/AttributeMatrix.cpp  
    ${SIMPLib_SOURCE_DIR}/SIMPLibGlobal.h
  )
  target_include_directories(SIMPLib PUBLIC ${ModernSIMPL_SOURCE_DIR}/Source)
