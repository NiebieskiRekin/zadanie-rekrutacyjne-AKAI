// Z podanego zbioru danych wyselekcjonuj 5 o największej wartości na jednostkę,
// znając kategorię obiektu Dane znajdują się w folderze "dane" w pliku
// "zbiór_wejściowy.json" oraz "kategorie.json" Wynik przedstaw w czytelnej
// formie na standardowym wyjściu

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <vector>
using json = nlohmann::json;
using namespace std;

const string kategorie_sciezka = R"(../dane/kategorie.json)";
const string zbior_sciezka = R"(../dane/zbiór_wejściowy.json)";
const size_t n = 5;

const string typ = "Typ";
const string czystosc = "Czystość";
const string wartosc = "Wartość za uncję (USD)";

// ./main kategorie.json zbior_wejsciowy.json
int main(int argc, char **argv) {
  std::ifstream kategorie_plik;
  if (argc > 1) {
    kategorie_plik = std::ifstream(argv[1]);
  } else {
    kategorie_plik = std::ifstream(kategorie_sciezka);
  }

  std::ifstream zbior_plik;
  if (argc > 2) {
    zbior_plik = std::ifstream(argv[2]);

  } else {
    zbior_plik = std::ifstream(zbior_sciezka);
  }
  json kategorie = json::parse(kategorie_plik);
  json zbior = json::parse(zbior_plik);
  assert(n <= zbior.size());

  vector<json> wynik;

  for (const auto &element : zbior) {
    for (const auto &kategoria : kategorie) {
      const string &typ_elementu = element[typ];
      const string &czystosc_elementu = element[czystosc];
      if (typ_elementu == kategoria[typ] &&
          czystosc_elementu == kategoria[czystosc]) {
        json temp = element;
        temp[wartosc] = kategoria[wartosc];
        wynik.push_back(temp);
        break;
      }
    }
  }
  sort(wynik.begin(), wynik.end(),
       [](const json &a, const json &b) { return a[wartosc] > b[wartosc]; });

  cout << "5 wpisów o największej wartości na jednostkę:\n";
  for (size_t i = 0; i < n; i++) {
    cout << wynik[i].dump(2) << endl;
  }
}
