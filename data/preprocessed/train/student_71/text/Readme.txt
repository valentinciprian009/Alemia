Mod de implementare:
1. Terenul este alcatuit dintr-o matrice de pointeri de tipul GameObject, care vor lua diferite forme ( Plante, Zombie sau TerrainBlock - in cazul in care nu este nimic
pe teren).
2. Clasa GameSession reprezinta o sesiune a unui joc, acesta avand diferite caracteristici: ce nivel este, cati zombie avem alocati, etc.
3. Un GameSession reprezinta o bucla in care la fiecare parcurgere se apeleaza functia useSkill a fiecarei entitati de pe teren.
4. Timerul pentru cumpararea plantelor - un simplu timer care se reseta cand planta era pusa pe teren.
5. Datele despre utilizator sunt stocate pe un fisier txt in directorul Users. Am incercat initial sa le pun intr-un json ( am gasit o biblioteca pe GitHub pentru asta)
dar ar fi trebuit sa ma documentez mai mult si sincer ma presa timpul).

Ce lucruri mai trebuie implementate (nu prea am avut timp cu examenele astea, dar oricum nu sunt greu de implementat):
1. Deblocarea nivelelor - trebuie pusa o variabila ce retine levelul maxim al playerului in fisierul text aferent.
2. Sa se spawneze un singur SuperZombie la o anumita perioada - trebuie doar bagat un timer si cu un bool ( ca sa stim daca l-am spawnat).
3. Dezalocarea terenului dupa ce s-a terminat o sesiune de gaming - momentan da eroare deoarece trebuie facuta dezalocarea in functie nivel.
4. Salvarea starii level-ului daca iesim din joc. - trebuie generat un "bitstream" ce inglobeaza toate caracteristicile entitatilor de pe teren, scorul la acel moment, etc
( asociem secventa de biti 000 pentru sunflower, 001 pentru peashooter, etc); acesta trebuie parsat la login, ca sa stim daca vrem sa reluam jocul.
5. Sunetele: am bagat cateva sunete ca sa vad cum merge. Acest lucru se poate face prin 2 functii, insa pentru pentru a elimina acel delay cat continutul sunetului este
incarcat, iar mai apoi redat, se poate face o clasa Wave de exemplu, care retine toate sunetele jocului si le incarca la inceputul programului.

Sper ca va place jocul, am incercat sa il fac cat mai frumos. L-as fi facut si mai frumos daca nu aveam examenele, dar nu e problema, o sa il fac dupa ce termin sesiunea
si probabil o sa il pun pe GitHub. Multumesc!