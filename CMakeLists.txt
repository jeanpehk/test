# Copyright 2020, 2021 Peter Dimov
# Distributed under the Boost Software License, Version 1.0.
# https://www.boost.org/LICENSE_1_0.txt

cmake_minimum_required(VERSION 3.5...3.16)

project(boost_test VERSION "${BOOST_SUPERPROJECT_VERSION}" LANGUAGES CXX)

function(boost_test_add_library name)

  add_library(boost_${name} ${ARGN})

  add_library(Boost::${name} ALIAS boost_${name})

  target_include_directories(boost_${name} PUBLIC include)

  target_link_libraries(boost_${name}
    PUBLIC
      Boost::algorithm
      Boost::assert
      Boost::bind
      Boost::config
      Boost::core
      Boost::detail
      Boost::exception
      Boost::function
      Boost::io
      Boost::iterator
      Boost::mpl
      Boost::numeric_conversion
      Boost::optional
      Boost::preprocessor
      Boost::smart_ptr
      Boost::static_assert
      Boost::type_traits
      Boost::utility
  )

  target_compile_definitions(boost_${name}
    PUBLIC BOOST_TEST_NO_LIB
    PRIVATE BOOST_TEST_SOURCE
  )

  if(BUILD_SHARED_LIBS)
    target_compile_definitions(boost_${name} PUBLIC BOOST_TEST_DYN_LINK)
  else()
    target_compile_definitions(boost_${name} PUBLIC BOOST_TEST_STATIC_LINK)
  endif()

  if(BOOST_SUPERPROJECT_VERSION AND NOT CMAKE_VERSION VERSION_LESS 3.13)

    boost_install(TARGETS boost_${name} VERSION ${BOOST_SUPERPROJECT_VERSION} HEADER_DIRECTORY include)

  endif()

endfunction()

boost_test_add_library(prg_exec_monitor
  src/cpp_main.cpp
  src/debug.cpp
  src/execution_monitor.cpp
)

set(SOURCES
  src/compiler_log_formatter.cpp
  src/debug.cpp
  src/decorator.cpp
  src/execution_monitor.cpp
  src/framework.cpp
  src/junit_log_formatter.cpp
  src/plain_report_formatter.cpp
  src/progress_monitor.cpp
  src/results_collector.cpp
  src/results_reporter.cpp
  src/test_framework_init_observer.cpp
  src/test_tools.cpp
  src/test_tree.cpp
  src/unit_test_log.cpp
  src/unit_test_main.cpp
  src/unit_test_monitor.cpp
  src/unit_test_parameters.cpp
  src/xml_log_formatter.cpp
  src/xml_report_formatter.cpp
)

if(NOT BUILD_SHARED_LIBS)

  boost_test_add_library(test_exec_monitor ${SOURCES} src/test_main.cpp)

endif()

boost_test_add_library(unit_test_framework ${SOURCES})
