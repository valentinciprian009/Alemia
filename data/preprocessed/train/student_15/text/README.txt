Cum se joaca?

**toate actiunile sunt cu double click**
**jocul trebuie jucat de la inceput pana la sfarsit, fara pauze, din cauza suprapunerii slide-urilor**

Mai intai se scrie numele, apasand double click pe litera corespunzatoare.
Dupa se apasa pe > pentru a trece la scrierea parolei( se va muta si cursorul in dreptul casutei de password).
Dupa se apasa pe Login.
Exista posibilitatea stergerii caracterului scris prin <.

Apare ecranul, in stanga sus detaliile despre jucator,mai jos plantele cele 5 tipuri, iar bara de sus pentru soare.
Se apasa double click pe soare, dupa pe planta si de abia atunci apare chenarul pentru a arata pozitiile unde sa se puna plantele.
Se apasa double click pe pozitia din chenarul aparut, iar planta se va pune acolo. Dupa, chenarul dispare.

Jocul e structurat pe 3 nivele, intre fiecare nivel aparand meniul cu optiuni.

Programul functioneaza pe slide-uri. Un slide este un mod de a afisa informatii pe consola. Exemple de slide-uri sunt meniurile, ecranele de loading si jocul propriu-zis.
Clasa Slide virtuala are mai multi membrii:
* void update(); //functia care se apeleaza intr-un while constant. deseneaza si actualizeaza informatiile din slide
* void reinit(); //la inchiderea slide-ului de deasupra, slide-ului curent i se va apela functia de reinit
* bool active; //pentru a inchide slide-ul curent pui active=false
* Slide* next; //pentru a te transfera la un slide nou il pui in next
In clasa Slide mai sunt si cateva functii statice care ajuta la afisearea jocului.
In functia int main() se efectuaza toata logica pentru schimbarea si actualizarea Slide-urilor.

Jocul Plants vs Zombies facut de mine are urmatoare constructie
Loading Slide ---- doar un ecran de incarcare a jocului
  v
Login Slide ------ ofera jucatorului sa se logeze in contul lui
  v         ^
Arena Slide ^ ---- aici efectiv se afiseaza si se calculeaza jocul
  v    ^    ^
Status Slide ----- ecranul de game over / pauza / level cleared

Pentru afisaj am creat mai multe clase ajutatoare:
->Button - un simplu buton: 
* int x, y, width, height; //datele necesare despre modul in care este afisat butonul 
* void draw(ConsoleOutput); //afiseaza butonul pe consola
* void click(string action); //functia care trebuie apelata pentru a verifica daca butonul a fost apasat sau nu. Daca da, se apeleaza functia:
* void pushFunction(); //functia asta difera de la buton la buton, de aceea e virtuala

->ITickable - un ITickable repeta o actiune dupa o anumita perioada
* void updateTime(); //verifica daca a trecut o perioada
* virtual void tickAction(); //se apeleaza cand a trecut o perioda (din interiorul functiei de mai sus)

->ITimer - un ITimer va efectua o actiune dupa o anumita perioda si dupa se opreste
* void updateTime(); //verifica daca a trecut timpul necesar
* bool timerDone(); //returneaza daca timer-ul s-a terminat
* void timerAction(); //actiunea care trebuie efectuata la scurgerea timpului
* void restart(); //efectuaza din nou actiunea dupa timpul specificat

LOGIN SLIDE
-----------
Trebuie sa discutam despre clasa User.
Ficare user are cate un:
* int lvl, scor;
* string nume, pass;
Ca functii statice avem:
* vector<User*> getFromFile(); //returneaza o lista cu toti userii din fisier
* void printFile(vector<User*>); //scrie in fisier lista de useri data
Am implementat tastatura din LoginSlide printr-o matrice de butoane (LetterButton). Pentru a avansa la noul camp, trebuie sa apesi pe butonul ">". Mai exista butonul LoginButton, care avanseaza la urmatorul Slide.
La reinit(), LoginSlide salveaza si preogresul userului in fisier

ARENA SLIDE
-----------
* User* user; //userul curent care se joaca
* int suns; //numarul de sori din joc
* int state; //starea jocului determina reactia jocului la anumite clickuri
Stari:
100, 101, 102, 103 = este selectata planta state-100
0                  = jocul functioneaza normal

Mai intai trebuie sa introducem cum va functiona salvarea datelor din joc:

->Exista clasa virtuala IGameElement (planta sau zombie sau proiectil):
* void draw(); //deseneaza in consola elementul
* void update(); //se actualizeaza in fuctie de celelalte elemente
* bool active(); //returneaza daca ar mai trebui sa existe elementul (ex: a murit planta/proiectul a iesit din scena)

->Informatiile legate de plante (id-ul plantei, numele ei, pretul, viata) si de zombie (id-ul, numele, viata, viteaza) sunt stocate in structuri:
* struct PlantInfo;
ID-uri:
0 Pea Shooter
1 Sunflower
2 Wallnut
3 Cherry Bomb
4 Frozen Pea Shooter
* struct ZombieInfo;
ID-uri:
0 Zombie
1 Bucket Head Zombie
2 Pole Vaulting Zombie
3 Super Zombie

->BasicPlant : IGameElement
* (static const) array<PlantInfo, 5> plants; //stocheaza informatiile plantelor 
* int id; //id-ul acelei plante
* void damage(); //raneste planta cu 1
|->SunflowerPlant : BasicPlant - schimba rata de aparitie a sorilor
|->Peashooter : BasicPlant, ITickable - la fiecare tick dispenseaza un Pea (se poate folosi si ca un Frozen Pea Shooter)
|->CherryBomb : BasicPlant, ITimer - la finalul timer-ului explodeazaza

->Pea : IGameElement, ITickable
* void tickAction(); //avanseaza cu o coordonata
* virtual affectZombie(BasicZombie* z); //afecteaza zombie-ul lovit
|->FrozenPea : Pea - la lovire, functia affectZombie(BasicZombie* z) il va si incetini pe z pentru un interval

->BasicZombie : IGameElement, ITickable - actioneaza si ca un Bucket Head Zombie
* (static const) array<ZombieInfo, 4> zombies; //stocheaza datele zombie-lor
* int id; //id-ul zombie-lor
* void tickAction(); //avanseaza zombie-ul cu 1
* bool insideCell(int x); //verifica daca zombie-ul este in a x-a celula de la stanga
* SlownessEffect* eff; //explic mai jos ce face
* void slowDown(); //incetineste zombie-ul un interval de timp
|->PoleZombie : BasicZombie - sare peste prima planta inatlnita (actioneaza si ca un Super Zombie)

Incetinirea zombie-ului se face prin clasa:
->SlownessEffect : ITimer
* SlownessEffect(BasicZombie* parent); //avem nevoie de zombie-ul care va fi incetinit
* void apply(); //pornim timer-ul si micsoram viteza zombie-ului
* void timerAction(); //la sfarsitul timpului, marim viteza la loc

Clase ajutatoare:
->ResourceManager : ITickable - gestioneaza crearea si preluarea sorilor din zona lor
* ResourceManager* getInstance(); //ResourceManager este Singleton
* void addToRate(int i); //mareste rata de aparitie a sorilor (cauzata de sunflowers)
* void click(string, int& suns, ConsoleOutput); //proceseaza ce actiune a facut utilizatorul, si daca a apasat pe un soare, crestem valoare lui suns
* void update(ConsoleOutput); //verifica daca a trecut suficient timp si daca da adauga un soare aleatoriu
* int rate=2; //intervalul intre generarea a 2 sori e invers proportionala cu rata. La fiecare Sunflower, rata creste cu 1

->GameManager - gestioneaza toata logica jocului
* BasicPlant* plants[][]; //vectorul de plante. cand pe locul i, j nu exista o planta, plants[i][j] este o instanta a BasicPlant cu id-ul -1
* vector<Pea*> peas[]; //un vector cu lista de proiectile de pe fiecare linie
* vector<BasicZombie*> zombies[]; //un vector cu lista de zombie de pe fiecare linie
* ofstream fout; //fisiserul de log
* void log(string); //scrie in fisierul log un mesaj
* void update(); //calculeaza tot ce trebuie facut: updateaza toate elementele si sterge elementele moarte
* void draw(ConsoleOutput); //deseneaza toate elementele
* void gameOver(); //functia care se apeleaza cand un zombie a ajuns pe pozitia 0

->ZombieDispenser : ITickable - dispenseaza zombie la intervale de timp alese
* void update(); //verifica daca e timpul sa dispenseze un zombie
* bool done(); //returneaza daca a fost dispensat ultimul zombie din nivel
* void reset(int lvl); //reseteaza timpul si numarul de zombie de dispensat in functie de nivel

Clasa de ArenaSlide contine si instante:
* GameManager* gman;
* ResourceManager* rman;
* ZombieDispenser* zman;
* vector<ArenaButton*> teren;
* vector<PlantButton*> menu;

-> ArenaButton : Button - un buton din zona de plante create pentru a selecta locul unde trebuie amplasata planta selectata (apar numai intr-un state>100)
-> PlantButton : Button - buton pentru selectarea plantelor (cele amplasate in partea stanga)
