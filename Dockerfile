FROM alpine:3.20.3 AS build
RUN apk add nlohmann-json libstdc++
RUN apk add g++ cmake make
WORKDIR /app
COPY src /app
WORKDIR /app/build
RUN cmake .. && \
  cmake --build . -j
FROM alpine:3.20.3 AS runner
RUN apk add nlohmann-json libstdc++
COPY --from=build /app/build/main /app/main
WORKDIR /app
CMD ["./main", "./dane/kategorie.json", "./dane/zbiór_wejściowy.json"]

