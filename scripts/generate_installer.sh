#!/usr/bin/bash

# Expects current directory to be the build directory!

PBI_FILENAME=plop-reader.pbi
PBI_PASSWORD=">nD4Ar0CNc(#Gl/87A8q"

cd "${BUILD_PATH}" || exit 1
zip -e --password "${PBI_PASSWORD}" ${PBI_FILENAME} \
    _scriptInstall sinstall/plop-reader.app sinstall/icons/*
