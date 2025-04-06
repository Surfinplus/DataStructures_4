 Tum:derle bagla calistir 
 
 derle:
	g++ -g -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -g -c -I "./include" ./src/AgacIslemleri.cpp -o ./lib/AgacIslemleri.o
	g++ -g -c -I "./include" ./src/DosyaIslemleri.cpp -o ./lib/DosyaIslemleri.o
	g++ -g -c -I "./include" ./src/IkiliAramaAgaclari.cpp -o ./lib/IkiliAramaAgaclari.o
	g++ -g -c -I "./include" ./src/TekYonluBagliListe.cpp -o ./lib/TekYonluBagliListe.o
	g++ -g -c -I "./include" ./src/UIIslemleri.cpp -o ./lib/UIIslemleri.o
	g++ -g -c -I "./include" ./src/AnaMenu.cpp -o ./lib/AnaMenu.o

bagla:
	g++ -g ./lib/AgacIslemleri.o ./lib/DosyaIslemleri.o ./lib/IkiliAramaAgaclari.o ./lib/TekYonluBagliListe.o .\lib\UIIslemleri.o .\lib\AnaMenu.o .\lib\main.o -o ./bin/program
calistir:
	./bin/program