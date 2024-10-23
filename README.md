# Rekrutacja akai

Zadanko konsolidacja na danych w c++

## Uruchomienie przez dockera

```bash
docker build . -t cpp-akai
docker run --rm -v $PWD/dane:/app/dane/ cpp-akai
```

## Lokalnie

Zależności: nhlohmann/json, cmake

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
