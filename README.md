# PSPS

## English

This is PSPS, the Polish Scrabble Player’s Portable Dictionary.  This
program enables you to convert a file in OSPS format to a plain-text
word list.  Please note that the input file is not bundled with this
program, you must possess a legal copy of OSPS to be able to use it.

Quick HOWTO:

0. extract the tarball, cd to the `psps/src/c` directory
1. run `make`
2. run `./psps INPUT_FILE` (if no input file is provided, psps
   will by default look for `l.lxa` in the current directory)
3. you should now have a file named `words.txt`

The input file can be either `l.lxa` from the OSPS distribution, or
`updateXX.upd` as downloaded from [the PFS site][1]. Note that in
the latter case you technically don’t have to have OSPS installed,
but it’s still a legal obligation.

## Polish

To jest PSPS, Przenośny Słownik Polskiego Scrabblisty.  Ten program
umożliwia wydobycie listy słów z pliku w binarnym formacie OSPS.
Uwaga: dane wejściowe nie są dostarczone z tym programem; aby zrobić z
niego użytek, musisz być właścicielem legalnej kopii OSPS.

Ta wersja działa też z plikami update, do ściągnięcia ze [strony PFS][1].

Szybkie HOWTO:

0. rozpakuj archiwum, zmień katalog na `psps/src/c`
1. uruchom `make`
2. uruchom `./psps PLIK_WEJŚCIOWY` (jeśli nie podano pliku wejściowego,
   psps domyślnie poszuka `l.lxa` w bieżącym katalogu)
3. powinien się utworzyć plik `words.txt`

Plikiem wejściowym może być `l.lxa` z dystrybucji OSPS albo `updateXX.upd`
pobrany ze [strony PFS][1]. W tym drugim przypadku technicznie nie ma potrzeby,
żeby OSPS był zainstalowany, ale nadal należy posiadać nań licencję – jest to
wymóg prawny.

## Licencja / License

GPLv3 (see `COPYING`).

 [1]: http://www.pfs.org.pl/osps_aktualizacje.php
