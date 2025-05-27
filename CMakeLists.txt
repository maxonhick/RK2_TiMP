cmake_minimum_required(VERSION 3.11)
project(TextRestricter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем GTest
find_package(GTest REQUIRED)
include(GoogleTest)

# Создаем исполняемый файл для тестов text_restricter_static
add_executable(text_restricter_static_tests
    tests/text_restricter_static_tests.cpp
)

# Создаем исполняемый файл для тестов text_restricter
add_executable(text_restricter_tests
    tests/text_restricter_tests.cpp
)

# Связываем с GTest
target_link_libraries(text_restricter_static_tests GTest::GTest GTest::Main)
target_link_libraries(text_restricter_tests GTest::GTest GTest::Main)

# Регистрируем тесты
gtest_discover_tests(text_restricter_static_tests)
gtest_discover_tests(text_restricter_tests)


# Настройка CPack
set(CPACK_PACKAGE_NAME "textrestricter")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_DESCRIPTION "Text Restricter Application")
set(CPACK_PACKAGE_CONTACT "Name email")
set(CPACK_PACKAGE_VENDOR "Company")
set(CPACK_PACKAGE_HOMEPAGE_URL "https://github.com/maxonhick")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "email")
set(CPACK_DEBIAN_PACKAGE_SECTION "utils")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libgtest-dev, libc6, libstdc++6")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "postinst;postrm")

# Включаем CPack
include(CPack)