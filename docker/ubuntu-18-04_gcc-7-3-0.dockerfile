FROM ubuntu:18.04
MAINTAINER D. Grine
RUN echo "Installing build-essential" \
        && apt-get update \
        && apt-get install -y --no-install-recommends build-essential \
        && apt-get autoremove
RUN mkdir -p /workspace/examples
COPY single_include /workspace/single_include
COPY examples /workspace/examples
COPY docker/run.sh /workspace/examples
WORKDIR /workspace/examples
CMD ["/workspace/examples/run.sh"]
