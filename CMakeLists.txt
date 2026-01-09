cmake_minimum_required(VERSION 3.10)
project(plop-reader VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FeatureSummary)
include(FindPkgConfig)

find_library(CURL_LIBRARY NAMES curl REQUIRED)
find_library(INKVIEW_LIBRARY NAMES inkview REQUIRED)
find_library(JSON_C_LIBRARY NAMES json-c REQUIRED)
find_library(SQLITE3_LIBRARY NAMES sqlite3 REQUIRED)
find_library(PTHREAD_LIBRARY pthread REQUIRED)

add_subdirectory(src/libs/thpool)

set(SOURCES
  src/api/wallabag_api.cpp
  src/api/wallabag_config.cpp
  src/api/wallabag_config_loader.cpp
  src/api/wallabag_entities_factory.cpp
  src/api/wallabag_oauth_token.cpp
  src/application.cpp
  src/database/database.cpp
  src/entities/entry.cpp
  src/entities/epub_download.cpp
  src/gui/gui.cpp
  src/gui/gui_button.cpp
  src/gui/gui_list_item_entry.cpp
  src/log.cpp
  src/main.cpp
  src/repositories/entry_repository.cpp
  src/repositories/epub_download_queue_repository.cpp
)

add_executable(plop-reader.app ${SOURCES})

target_link_libraries(plop-reader.app
  PRIVATE
  ${CURL_LIBRARY}
  ${INKVIEW_LIBRARY}
  ${JSON_C_LIBRARY}
  ${SQLITE3_LIBRARY}
  ${PTHREAD_LIBRARY}
  thpool
)

# Installer, archive and checksum targets

configure_file(packaging/_scriptInstall.in _scriptInstall @ONLY)

add_custom_target(populate_installer_tree
  COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/sinstall/icons"
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${CMAKE_BINARY_DIR}/plop-reader.app"
  "${CMAKE_BINARY_DIR}/sinstall"
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${CMAKE_SOURCE_DIR}/icons/icon_plop_reader.bmp"
  "${CMAKE_SOURCE_DIR}/icons/icon_plop_reader_f.bmp"
  "${CMAKE_BINARY_DIR}/sinstall/icons"
  COMMENT "Populate installer tree"
)
add_dependencies(populate_installer_tree plop-reader.app)

add_custom_target(installer
  COMMAND ${CMAKE_SOURCE_DIR}/scripts/generate_installer.sh
  COMMENT "Create installer"
)
add_dependencies(installer populate_installer_tree)

add_custom_target(archive
  COMMAND zip --recurse-paths ../plop-reader.zip .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/sinstall
  COMMENT "Create archive"
)
add_dependencies(archive populate_installer_tree plop-reader.app)

add_custom_target(checksum
  COMMAND ${CMAKE_SOURCE_DIR}/scripts/generate_checksum_file.sh
  COMMAND ${CMAKE_COMMAND} -E sha256sum plop-reader.app plop-reader.pbi plop-reader.zip
  COMMENT "Compute checksums"
)
add_dependencies(checksum archive installer plop-reader.app)

feature_summary(WHAT ALL)
