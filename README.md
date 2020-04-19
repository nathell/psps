# PSPS

## English

This is PSPS, the Polish Scrabble Player’s Portable Dictionary.  This
program enables you to convert a file in OSPS format to a plain-text
word list.  Please note that the input file is not bundled with this
program, you must possess a legal copy of OSPS to be able to use it.

Quick HOWTO:
0. extract the tarball, cd to the psps directory
1. run `make`
2. run `./psps /path/to/osps/l.lxa` (or copy `l.lxa`
   to current directory and run `psps`)
3. you should now have a file named `words.txt`

Windows users: Copy `psps.exe` and `l.lxa` from OSPS to one directory,
then run `psps.exe`.  This should create a file named `words.txt`.

## Polish

To jest PSPS, Przenośny Słownik Polskiego Scrabblisty.  Ten program
umożliwia wydobycie listy słów z pliku w binarnym formacie OSPS.
Uwaga: dane wejściowe nie są dostarczone z tym programem; aby zrobić z
niego użytek, musisz być właścicielem legalnej kopii OSPS.

Szybkie HOWTO:
0. rozpakuj archiwum, zmieñ katalog na psps
1. uruchom `make`
2. uruchom `./psps /ścieżka/do/osps/l.lxa`
   (albo skopiuj `l.lxa` do bieżącego katalogu i uruchom psps)
3. powinien się utworzyć plik `words.txt`

Pod Windows: Skopiuj pliki `psps.exe` i `l.lxa` z OSPS do jednego
katalogu, a potem uruchom `psps.exe`. Powinien utworzyć się plik
`words.txt`.

## Licencja / License

GPLv3 (see `COPYING`).
