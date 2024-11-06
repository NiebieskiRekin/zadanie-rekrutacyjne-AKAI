# Rekrutacja akai

Zadanko konsolidacja na danych w c++

## Uruchomienie przez dockera

![workflow](https://github.com/NiebieskiRekin/zadanie-rekrutacyjne-AKAI/actions/workflows/docker-image.yml/badge.svg)

![hub.docker.com/r/niebieskirekin/cpp-akai](https://hub.docker.com/r/niebieskirekin/cpp-akai/tags)

```bash
docker build . -t cpp-akai
docker run --rm -v $PWD/dane:/app/dane/ cpp-akai
```

## Lokalnie

Zależności: nlohmann/json, cmake

```bash
vcpkg install nlohmann-json
```

Kompilacja

```bash
cd src
mkdir build
cd build
cmake ..
cmake --build . -j
mv main ../
cd ..
```

Uruchomienie

```bash
./main
```
