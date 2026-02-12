FROM ubuntu:24.04 AS build

RUN apt-get update && apt-get install -y build-essential cmake libssl-dev meson ninja-build git-all

WORKDIR /app

COPY ./external/cpr /app/external/cpr
COPY ./external/json /app/external/json
COPY ./scripts/build.sh /app/scripts/
COPY ./src /app/src
COPY ./CMakeLists.txt /app/

WORKDIR /app/scripts
RUN ./build.sh

FROM ubuntu:24.04 AS runtime
WORKDIR /app

COPY --from=build /app/build/app/* .
ENV LD_LIBRARY_PATH=/app/

CMD ["./HoHClient"]
