FROM debian:bullseye

WORKDIR /app


RUN apt update && apt install -y \
    build-essential \
    curl \
    git \
    && rm -rf /var/lib/apt/lists/*

CMD ["sleep","infinity"]