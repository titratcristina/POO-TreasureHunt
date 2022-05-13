# Short description
Used C++ to create a console application to integrate object-oriented programming concepts. Treasure Hunt is a console game where three treasures are displayed on a map randomly and four seekers with predefined movements are searching for them if were found all three diamonds or if there are three stuck players and a winner (a seeker that found a diamond) the game is over.

# Treasure Hunt

Avem o harta pe care sunt plasate 3 comori pe poziții aleatorii și 4 căutătoride comori în cele 4 colturi. Fiecare căutător poate înainta o căsuță pe runda și nu poate trece peste căsuțele deja explorate de el sau de ceilalți căutători. La terminarea fiecărei runde, despre fiecare căutător se va ști dacă a găsit sau nu o comoară. Primul căutător care a găsit comoara va fi câștigător și va părăsi harta. Jocul continuă pană când nu mai sunt căsuțe de explorat sau nu mai exista mutări valide (toate căsuțele explorate) sau rămâne doar un căutător pe hartă fără nici o comoară.

## Cerințe:

- Crearea a 4 tipuri căutători de comori poziționați în colturile hărții;

- Crearea a 3 comori așezate aleatoriu pe harta, dar niciodată în unul din cele 4 colturi;

- Crearea unei hărți de cel puțin 15 x 15;

- Crearea unei clase care sa gestioneze harta și desfășurarea unei runde;

- Creare  unei  modalități  de  a  alege  simularea  succesiva  a  rundelor  sau oprirea simulării la stadiul curent cu afișarea configurației hărții la sfârșitul unei runde simulate;

- Afișarea detaliilor despre ce modificări au avut loc asupra hărții;


## Cerințe globale și obligatorii

- Alocare dinamică a memorie;

- Separarea declarației unei clase de implementare acesteia;

- Crearea de constructori (folosind lista de inițializare) și destructori;

- Utilizare supraîncărcării operatorilor, unde este cazul;

- Indentare și comentarea adecvată a codului;

- Utilizarea unei convenții de denumire a variabilelor, metodelor și claselor, cu specificarea acesteia;

- Utilizarea variabilelor și metodelor const, unde este cazul;

- Utilizarea claselor abstracte și metodelor virtuale în rezolvarea cerinței;

- Tema  trebuie  să  compileze  fără  a  utiliza  anumite  flag-uri  de  compilare (cu excepția cazurilor în care pentru compilare este necesară o anumită versiune de C++) și să respecte standardele C++ pentru sintaxă;

- Pentru punctaj maxim nu trebuie să se foleseacă verificări de tipuri. Pentru a genstiona mai multe tipuri de date în același bloc de instrucțiuni se vor folosi clase abstracte și metode virtuale;

- Strategia folosita pentru mutarea agentilor trebuie sa fie deterministă;

- Tipurile de agenți trebuie să difere cel puțin prin funcționalitățile oferite de suprascrierea metodelor virtuale;

## DEADLINE
~~1 mai 2020, ora 23:59~~
3 mai 2020, ora 23:59
