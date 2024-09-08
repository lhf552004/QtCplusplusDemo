1. Build docker image

```
docker build -t qtcreator-docker .
```

Allow X11 Forwarding

```
xhost +local:docker
```

2. Run the Docker Container with GPU Access

```
docker run -it --rm \
    --gpus all \
    --env="DISPLAY" \
    --env="QT_X11_NO_MITSHM=1" \
    --volume="/tmp/.X11-unix:/tmp/.X11-unix:rw" \
    --device /dev/dri \
    --mount src=/path/to/QtCplusplusDemo,target=/build,type=bind \
    qtcreator-docker qtcreator /build
```

```
--gpus all: This option grants access to all GPUs on your host. It requires the NVIDIA Container Toolkit to be installed if you are using an NVIDIA GPU.

--env="QT_X11_NO_MITSHM=1": Disables the MIT-SHM extension, which can sometimes cause issues with shared memory access in Docker.

--device /dev/dri: Provides direct access to the GPU's Direct Rendering Infrastructure (DRI) devices, needed for hardware-accelerated rendering.
```
