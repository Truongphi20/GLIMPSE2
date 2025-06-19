FROM ubuntu:20.04

LABEL org.opencontainers.image.created="2022-11-30"
LABEL org.opencontainers.image.url="https://github.com/odelaneau/GLIMPSE"
LABEL org.opencontainers.image.version="2.0.0"
LABEL org.opencontainers.image.licences="MIT"
LABEL org.opencontainers.image.title="glimpse"
LABEL org.opencontainers.image.authors="simone.rubinacci@unil.ch"

WORKDIR /docker_build/

# Install required packages
RUN apt-get update && apt-get install -y build-essential libbz2-dev libcurl4-openssl-dev autoconf libssl-dev wget zlib1g-dev liblzma-dev libdeflate-dev

# Download and build boost program_options and iostreams
RUN wget https://archives.boost.io/release/1.78.0/source/boost_1_78_0.tar.gz && \
tar -xf boost_1_78_0.tar.gz && \
rm boost_1_78_0.tar.gz && \
cd boost_1_78_0/ && \
./bootstrap.sh --with-libraries=iostreams,program_options,serialization --prefix=../boost && \
./b2 install && \
cd .. && \
cp boost/lib/libboost_iostreams.a boost/lib/libboost_program_options.a boost/lib/libboost_serialization.a /usr/local/lib/ && \
cp -r boost/include/boost/ /usr/include/ && \
rm -r boost_1_78_0 boost

# Download and build htslib
RUN wget https://github.com/samtools/htslib/releases/download/1.16/htslib-1.16.tar.bz2 && \
tar -xf htslib-1.16.tar.bz2 && \
rm htslib-1.16.tar.bz2 && \
cd htslib-1.16 && \
autoheader && \
autoconf && \
./configure --enable-libcurl && \
make install && \
cd .. && \
rm -r htslib-1.16

# Install github
RUN apt-get install -y --no-install-recommends git

# Install cmake
RUN mkdir -p /usr/local
RUN cd /usr/local &&\
    wget https://github.com/Kitware/CMake/releases/download/v4.0.2/cmake-4.0.2-linux-x86_64.sh &&\
    chmod +x cmake-4.0.2-linux-x86_64.sh &&\
    ./cmake-4.0.2-linux-x86_64.sh --skip-license

# Install required packages to debug
ARG INSTALL_DEBUG_TOOLS=true
RUN if [ "$INSTALL_DEBUG_TOOLS" = "true" ]; then \
    apt-get install -y --no-install-recommends openssh-client &&\
    apt-get install -y --no-install-recommends gdb &&\
    apt-get install -y --no-install-recommends bcftools &&\
    apt-get install -y --no-install-recommends less &&\
    apt-get install -y --no-install-recommends bash-completion ;\
    fi

RUN if [ "$INSTALL_DEBUG_TOOLS" = "true" ]; then \
    echo '\
if [ -f /usr/share/bash-completion/bash_completion ]; then\n\
  . /usr/share/bash-completion/bash_completion\n\
elif [ -f /etc/bash_completion ]; then\n\
  . /etc/bash_completion\n\
fi' >> /root/.bashrc; \
fi 

# Set workspace
RUN mkdir -p /workspace
WORKDIR /workspace
