FROM centos:7.5.1804
MAINTAINER D. Grine
RUN echo "Install build-essential" \
        && yum install -y gcc gcc-c++
RUN mkdir -p /workspace/examples
COPY single_include /workspace/single_include
COPY examples /workspace/examples
COPY docker/run.sh /workspace/examples
WORKDIR /workspace/examples
CMD ["/workspace/examples/run.sh"]
