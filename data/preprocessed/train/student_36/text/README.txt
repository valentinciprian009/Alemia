	La rularea aplicatiei se va cere initial un nume de utilizator si o parola. Aceste vor fi stocate ca variabile de tip private in clasa Menu. In cazul in care numele are mai putin
de 3 sau mai mult de 10 caractere sau a mai fost folosit inainte, se va ridica o exceptie, iar programul va cere introducerea unui nou username. Acelasi lucru este valabil si pentru parola:
daca parola are mai putin de 3 sau mai mult de 10 caractere, programul va cere o noua parola care sa respecte conditia.

	Programul are doua parti:
	- partea in care jocul se afla intre runde, utilizatorul putand pune plante pe mapa si sa adune resursele
	- partea in care incep sa vina Zombie, utilizatorul putand pune in continuare plante si aduna resursele
	Trecerea din prima parte in a doua se face prin apasarea butonului "Next Round", iar revenirea la prima faza a jocului se face automat dupa fiecare runda. Aici jocul se blocheaza
atata timp cat utilizatorul nu misca mouse-ul; acest lucru fiind o metoda de verificare daca utilizatorul mai este in fata ecranului sau a plecat.

	Butonul "Exit" realizeaza inchiderea jocului si implicit salvarea datelor: nume, parola, ultima runda castigata si scorul pana in acel moment in fisierul login.log.

	Selectarea plantelor si punerea lor pe teren, colectarea resurselor si apasarea butoanelor se realizeaza doar prin dublu click pe acestea.

	Cat timp jocul se afla in prima parte, pe harta vor aparea niste delimitari pentru a "desena" fiecare zona pe care se poate afla cate o planta. Plantele pot fi plasate pe oricare
zona in afara de ultima coloana, pentru ca altfel ar bloca spawn-area entitatilor de tip Zombie. In cazul in care utilizatorul doreste sa plaseze o planta pe ultima coloana, va fi ridicata
o exceptie si se va afisa faptul ca nu se poate plasa o planta pe acea zona, urmand ca utilizatorul sa plaseze planta aleasa in alta parte. De asemenea, planta Cherry Bomb poate fi folosita
doar in partea a doua a jocului, pentru ca in prima nu ar avea niciun efect. Acest lucru va ridica o alta exceptie.

	Programul memoreaza toate entitatile in 4 matrici:
	- Lines, in care se retin toate instantele obiectelor si pozitia fiecaruia
	- fight_matrix, face acelasi lucru ca si matricea Lines numai ca in loc de instante retine numarul asociat fiecarui obiect
	- projectile_matrix, care memoreaza zonele in care se afla proiectile si damage-ul pe care ar trebui fiecare proiectul sa-l aiba
	- sun_matrix, in care se retin resursele de tip sun si cantitatea de resurse pe care utilizatorul o primeste atunci cand colecteaza rusursele

	Numarul de Zombie pe care programul ii spawneaza este in functie de runda, number_zombies = 3 * round. Atunci cand se spawneaza cate un Zombie, tipul acestuia va fi generat
aleatoriu, iar linia pe care se va afla va fi in functie de regulile impuse la primirea temei ( in primele doua runde, se foloseste doar o banda, iar incepand cu runda a treia, linia pe 
care apare fiecare Zombie va fi aleasa aleatoriu, acestia fiind initial pe ultima coloana a liniei stabilite). In momentul in care un Zombie este omorat se va incrementa punctajul cu un
numar prestabilit fiecarui tip de Zombie.

	Nu pot exista doua entitati pe aceeasi zona.

	In timpul luptei, dupa generarea entitatilor de tip Zombie si a proiectilelor, se va verifica daca se pot deplasa:
	- daca in fata unui Zombie este o zona goala, acesta va trece pe acea zona. In caz contrar, pe acea zona este o planta, si, prin urmare, Zombie-ul o va ataca. In cazul in care
Zombie-ul este de tip PoleVaulting se va verifica si daca in spatele plantei este o zona libera, iar in cazul in care zona este libera si Zombie-ul nu a mai sarit peste nicio planta, acesta
va "sari" (se va muta) pe acea zona, marcandu-se faptul ca a sarit.
	- daca in fata unui proiectil nu este nimic, acesta va inainta. Daca proiectilul se afla pe o zona pe care este o planta de tip Peashooter, proiectilului i se va adauga damage-ul
pe care l-ar fi avut proiectilul nou creat de planta, iar in cazul in care proiectilul s-ar muta pe o zona pe care este un Zombie, acestuia i s-ar scadea din viata valoarea pe care o are
proiectilul in variabila "damage", iar acesta se va sterge din matricea "projectile_matrix".

	La finalul fiecarei runde se sterg proiectilele de pe consola, acestea ramanand doar in matrici.

	In timpul executiei programului se verifica si daca exista vreun Zombie pe prima coloana a oricarei benzi, acest lucru ducand la pierderea jocului.

	Fisierul "login.log" se creaza in acelasi folder in care se gasesc si clasele proiectului. In acesta se memoreaza username-ul, parola, ultima runda castigata si scorul final al
fiecarui jucator.

