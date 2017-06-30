CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

IF (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/../version)
  file(STRINGS "../version" PVDNP_VERSION)
  SET(PVDNP_VERSION_FILE ${CMAKE_CURRENT_SOURCE_DIR}/../version)
ELSEIF (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/version)
  file(STRINGS "version" PVDNP_VERSION)
  SET(PVDNP_VERSION_FILE ${CMAKE_CURRENT_SOURCE_DIR}/version)
ELSE()
  message(FATAL_ERROR "version number file not found. The version number must be provided in file called \"version\" in the sources root or one level higher.")
ENDIF()
message(STATUS "Building version ${PVDNP_VERSION}")


# Build options
SET(PROJECT_TYPE otu CACHE STRING "Project type. Choose \"otu\" or \"mrcod\"")

IF (${PROJECT_TYPE} STREQUAL otu)
  PROJECT(otu)
  ADD_DEFINITIONS(-DPROJECT_TYPE_OTU)

  SET(BIOMETRY_TYPE neurotec CACHE STRING "Biometry SDK type. Choose \"neurotec\" of \"papilon\"")
ELSE()
  PROJECT(mrcod)
  ADD_DEFINITIONS(-DPROJECT_TYPE_MRCOD)
ENDIF()


IF ((${CMAKE_BUILD_TYPE} STREQUAL Debug) OR (${CMAKE_BUILD_TYPE} STREQUAL RelWithDebInfo))
  ADD_DEFINITIONS(-DDEBUG_BUILD)
ENDIF()


# Unit testing
ENABLE_TESTING()

# Directories
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/CMake)

# Build settings
INCLUDE(CompilerFlags)

# Logger
ADD_SUBDIRECTORY(Logger)
INCLUDE_DIRECTORIES(BEFORE Logger/include)

# CuteIPC
SET(QT_DESIRED_VERSION 4)
ADD_SUBDIRECTORY(CuteIPC)
INCLUDE_DIRECTORIES(CuteIPC/include)

# TaskProcessor
ADD_SUBDIRECTORY(TaskProcessor)
INCLUDE_DIRECTORIES(TaskProcessor/include)

# ProcessManager
ADD_SUBDIRECTORY(ProcessManager)
INCLUDE_DIRECTORIES(ProcessManager/include)

# CertDecoder, ProgressIndicator, PvdnpCommon
INCLUDE_DIRECTORIES(
  src/utils/CertWidget/CertDecoder/include
  src/utils/ProgressIndicator/include
  src/utils/PvdnpCommon/include
)

# AuthModule
INCLUDE_DIRECTORIES(src/utils/AuthModule/include)
INCLUDE_DIRECTORIES(src/utils/AuthModule/eac/include)
INCLUDE_DIRECTORIES(src/utils/TLVProto/include)

ADD_SUBDIRECTORY(AuthModule)
INCLUDE_DIRECTORIES(AuthModule/include)

# Icons
ADD_SUBDIRECTORY(icons)

# Project sources
ADD_SUBDIRECTORY(src)


# Config file parser
INSTALL(FILES config-parser.py DESTINATION share)
