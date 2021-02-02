Marghescu Bogdan
C112C
Tema 2: POO vs Zombies

La inceput, utilizatorul are posibilitatea de a crea un user nou, de a folosi deja unul creat sau de a parasi aplicatia din meniul principal.
Apoi, in urmatorul meniu, fie se creeaza un nou user, fie se logheaza altul nou, dar avem posibilitatea de a merge inapoi in meniul principal si de a parasi jocul.
Dupa crearea userului, se intra in joc(sau asa ar trebui, dar sunt buguri aici, testarea levelului se poate face din main prin decomentarea liniilor din main),
Se selecteaza planta, in functie de cost si cooldown, se plaseaza si ea isi va porni abilitatea, daca are.
Intre timp, pe fiecare rand va aparea cate un zombie aleator in valuri, urmand ca, dupa ce se termina valurile normale de zombie, sa apara SuperZombie.
Jocul fie se termina cand unul din zombie a atins SpawnGround, adica casa, fie cand vectorul de Zombie* are numai elemente nullptr, adica cand au fost eliminati
toti Zombie.
Daca jucatorul a pierdut, are posibilitatea de a relua levelul intorcandu se in meniul de start si logandu se din nou, deoarece fisierele de utilizatori retin ultimul level
completat si scorul total acumulat.
Daca jucatorul a terminat levelul, merge la urmatorul si se updateaza informatiile, iar la level 3 se termina jocul, nemaiavand mai departe posibilitatea de a relua jocul.
BUGURI:
*Polevaulting si Superzombie nu sar la runtime, ci doar cand dau debug cu breakpoints
*zombie si plantele nu dau si nici nu iau damage la runtime, ci doar cand dau debug cu breakpoints
*nu am reusit sa fac legatura cum trebuie dintre clasa Game si clasa Level