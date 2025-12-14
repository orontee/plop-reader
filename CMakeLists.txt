cmake_minimum_required(VERSION 3.22)
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
find_library(THREADS_LIBRARY pthread REQUIRED)

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
  src/libs/thpool/thpool.c
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
  ${THREADS_LIBRARY}
)

feature_summary(WHAT ALL)
