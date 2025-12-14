# Plop reader

[Wallabag](https://www.wallabag.org/) client for
[Pocketbook](https://pocketbook.ch/en-ch/catalog) devices.

ℹ️ This project is a fork of the obsolete [plop-reader by Pascal
Martin](https://github.com/pmartin/plop-reader/blob/master/Makefile).

# Build

### Using a container

To build in a container: 

``` bash
$ buildah build --build-arg DEVICE_FAMILY=B288 --tag pbsdk:6.8-B288 .
$ podman run --rm -ti \
             --volume ${PWD}:/src \
			 --hostname pbsdk-B288 \
			 --name pbsdk-B288 \
			 localhost/pbsdk:6.8-B288 \
             bash
roo@pb-build-env:/src$ source /opt/SDK-6.8/build_env.sh
roo@pb-build-env:/src$ cmake -S . -B build \
                             -DCMAKE_TOOLCHAIN_FILE=${SDK_ROOT_PATH}/share/cmake/arm_conf.cmake
roo@pb-build-env:/src$ cmake --build build
```
