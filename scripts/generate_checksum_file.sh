#!/usr/bin/bash

# Expects current directory to be the build directory!

APPLICATION_FILENAME=plop-reader.app
INSTALLER_FILENAME=plop-reader.pbi
ARCHIVE_FILENAME=plop-reader.zip

SHA_FILE=plop-reader.sha256

if [[ ! -f "${APPLICATION_FILENAME}" ||
      ! -f "${INSTALLER_FILENAME}" ||
      ! -f "${ARCHIVE_FILENAME}" ]]; then
    echo "Error: Missing file"
fi

sha256sum ${APPLICATION_FILENAME} \
          ${INSTALLER_FILENAME} \
          ${ARCHIVE_FILENAME} > "${SHA_FILE}"
