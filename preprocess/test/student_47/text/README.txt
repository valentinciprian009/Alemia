Implementarea temei are la baza clasa Table, care contine toate campurile si 
metodele necesare desfasurarii jocului. Elementul central al acestei clase este
reprezentat de matricea de celule (Cell).
Clasa Cell defineste o celula din tabelul pe care se desfasoara jocul. Campurile
sale sunt coordonatele sale, flagul hasPlant (stabileste daca celula contine o
planta), vectorul zombies (contine eventualii zombii care se afla in ea), si 
obiectul projectile, instanta a clasei Projectile (va fi instantiat daca pe celula
respectiva se afla un proiectil.

Clasa Cell are drept copil clasa Plant. Aceasta are in plus campurile price si
resistance, precum si metodele necesare verificarii si modificarii acestor campuri.
Clasa Plant are drept copii 5 clase reprezentand tipurile de plante ce pot aparea:
Peashooter, Sunflower, CherryBomb, Wallnut si SnowPea. Dintre acestea, plantele
care provoaca daune zombiilor au un camp in plus, anume fireThreshold.

O alta clasa importanta este clasa abstracta Movable. Aceasta functioneaza ca o
interfata pentru toate obiectele de pe tabla care se pot deplasa (zombii si
proiectilele). Campurile acesteia sunt coordonatele obiectului, si un counter
numit moveThreshold.
Clasa Projectile, copil al clasei Movable, aduce in plus un camp bool care 
determina daca proiectilul este inghetat sau nu.
Clasa Zombie, de asemenea copil al clasei Movable, are campurile specifice
life, speed, si booleanul jump, care stabileste daca un zombie poate sari
peste o planta. Aceasta clasa are 4 copii ce reprezinta tipurile de zombii
ce pot aparea: Simple, PoleVaulting, BucketHead si Super. Intre acestia
difera valorile parametrilor ce caracterizeaza un zombie.


Interactiunea cu jocul se face preponderent prin clic in tabela. Cand un 
eveniment de tip clic este captat, se calculeaza in care celula a tabelei s-a facut.
In continuare se verifica anumiti parametrii pentru a stabili actiunea urmatoare.

Daca s-a facut clic in prima linie a tabelei, se va colecta soarele din casuta
respectiva, daca exista, si se va adauga la resurse.
Daca s-a facut clic in prima coloana a tabelei, se va trece in modul plantare,
se va verifica in ce casuta s-a facut clic si in functie de asta se va alege planta.
In continuare, aceasta se va planta in casuta in care se face clicul urmator

Zombii sunt generati aleator, in coloana cea mai din dreapta. Acestia se deplaseaza
folosind un counter intern, specific clasei Movable (care le e parinte). In momentul
in care acest contor atinge o anumita valoare, acestia sunt deplasati o casuta spre
stanga.

Proiectilele sunt generate in fata plantelor care le pot lansa, la anumite intervale
de timp, specifice plantei. Asemenea zombiilor, ele sunt deplasate folosind acelasi 
contor intern specific clasei Movable, dar un prag mai mic la care se declanseaza
mutarea. Astfel, ele se deplaseaza mult mai repede decat zombii.

Contoarele interne, atat ale zombiilor, cat si ale proiectilelor, sunt incrementate
folosind metodele updateZombies() si updateProjectiles().

Metoda processCollisions() parcurge tabela si verifica in ce casute se afla atat zombii
cat si proiectile. In cazul acestora, proiectilele sunt distruse si zombiilor li se
scade din viata. Daca viata acestora ajunge la 0, ei sunt eliminati de pe tabela.

Nivelele sunt in numar de 3, cu 1, 3, respectiv 5 randuri pe tabla de joc. Un nivel se 
incheie atunci cand au fost generati cel putin 10 * nr_randuri zombii, si nu se mai afla
niciunul in viata. De asemenea, jocul se incheie daca un zombii a ajuns pe prima coloana
a tablei, sau daca e apasata tasta ESC.