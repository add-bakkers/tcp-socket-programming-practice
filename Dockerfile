FROM debian:bullseye

WORKDIR /app


RUN apt update && apt install -y \
    git \
    gcc \
    gdb \
    && rm -rf /var/lib/apt/lists/*

CMD ["sleep","infinity"]