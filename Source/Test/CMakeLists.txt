


add_executable(SIMPLibUnitTest)
target_sources(SIMPLibUnitTest
PUBLIC
  SIMPLibUnitTest.cpp
  )

target_include_directories(SIMPLibUnitTest PUBLIC ${ModernSIMPL_SOURCE_DIR}/Source)

target_link_libraries(SIMPLibUnitTest SIMPLib)
