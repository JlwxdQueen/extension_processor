FROM alpine:3.18 AS builder

RUN apk update && apk add --no-cache build-base cmake git zip && rm -rf /var/cache/apk/*

WORKDIR /app

COPY CMakeLists.txt .
COPY include ./include
COPY src ./src
COPY tests ./tests

RUN mkdir build
RUN cmake -DCMAKE_BUILD_TYPE=Release -S . -B build && cmake --build build

FROM alpine:3.18 AS production

RUN apk update && apk add --no-cache libstdc++ && rm -rf /var/cache/apk/*

WORKDIR /app

COPY --from=builder /app/build/Processor /app/Processor

CMD ["./Processor"]