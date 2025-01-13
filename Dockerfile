FROM alpine:3.18 AS development

RUN apk update && apk add --no-cache \
    build-base \
    cmake \
    git \
    wget \
    && rm -rf /var/cache/apk/*

WORKDIR /app

COPY . .

RUN cmake -S . -B build && cmake --build build
RUN cd build && ctest --output-on-failure

FROM alpine:3.18 AS production

RUN apk update && apk add --no-cache \
    libstdc++ \
    && rm -rf /var/cache/apk/*

WORKDIR /app

COPY --from=development /app/build/Processor /app/Processor

CMD ["./Processor"]
