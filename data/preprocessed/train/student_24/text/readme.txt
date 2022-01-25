Cum se joaca??

Pentru a va putea juca Plants vs Zombies va trebui sa alegeti daca doriti sau nu sa creati un utilizator nou. 
Din cauza modului de preluare a datelor din stdin, nu veti putea aplica backspace si sa corectati o eventuala greseala facuta,
deoarece nu se va mai afisa corectura, iar numele userului va contine un /b. Pentru a alege optiunile apasati dublu click.
Pentru a iesi din joc exista butonul Exit in stanga jos care asigura iesirea corecta din program.(tot prin dublu click)
De la un nivel la altul se vor pastra resursele, insa valoarea soarelui generat va fi 10 in lipsa unei plante
Sunflower. Pentru a cumpara o planta dati dublu click in patratelul plantei dorite, apoi
dublu click in patratelul unde doriti sa o plantati, daca aveti destule resurse. Good luck!

Modalitatea de implementare

Totul porneste de la o interfata generala iDrawable care mai are supraincarcat operatorul <<. Zonele jocului le-am implementat prin intermediul unei
clase template ContainerRectangle<T> , derivata din clasa Rectangle. Preiau clickurile verificand in ce ContainerRectangle a fost apasat in cazul 
cumpararii de plante si la culesul resurselor care se genereaza la o anumita perioada de timp intr-o pozitie random. Daca utilizatorul cumpara
Sunflower, resursele vor fi generate mai des si vor avea valoarea 50. Pentru modelarea Plantelor si Zombie am folosit o interfata comuna iBattleEntity,
cu una din metode action pentru lupta propriu zisa, am creat zona de lupta printr-o matrice de ContainerRectangle<iBattleEntity*>, iar la un anumit nr de
 iteratii se declanseaza actiunile diferitelor entitati. 
"Motorul" jocului este o bucla for si cu ajutorul iteratiilor care cresc mereu, controlez ordinea de precedenta a instructiunilor si a declansarii
evenimentelor.