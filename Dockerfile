FROM ubuntu:22.04

# Set environment variables to avoid interactive prompts
ENV DEBIAN_FRONTEND=noninteractive

# Set the default time zone to prevent tzdata from prompting
RUN ln -fs /usr/share/zoneinfo/Etc/UTC /etc/localtime && \
    apt-get update && apt-get install -y tzdata

# Enable the universe and multiverse repositories
RUN apt-get update && apt-get install -y software-properties-common && \
    add-apt-repository universe && \
    add-apt-repository multiverse && \
    apt-get update

# Install necessary packages including Qt5, QML, and xcb dependencies
RUN apt-get update && apt-get install -y \
    qtcreator \
    qtbase5-dev \
    qt5-qmake \
    qttools5-dev-tools \
    qmlscene \
    qml-module-qtquick-controls2 \
    qml-module-qtquick2 \
    qml-module-qtquick-layouts \
    qml-module-qtgraphicaleffects \
    qml-module-qtqml-models2 \
    build-essential \
    libgl1-mesa-glx \
    libx11-xcb1 \
    libxcb-util1 \
    libxcb-keysyms1 \
    libxcb-xinerama0 \
    libxcb-icccm4 \
    libxcb-image0 \
    libxcb-randr0 \
    libxcb-render-util0 \
    libxcb-shape0 \
    libxcb-xfixes0 \
    libxcb-sync1 \
    libxcb-xkb1 \
    libxkbcommon-x11-0 \
    x11-apps \
    libboost-all-dev \
    nlohmann-json3-dev && \
    rm -rf /var/lib/apt/lists/*
