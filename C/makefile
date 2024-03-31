hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/Uretim.o -c ./src/Uretim.c
	gcc -I ./include/ -o ./lib/Taktik.o -c ./src/Taktik.c
	gcc -I ./include/ -o ./lib/CiftUretim.o -c ./src/CiftUretim.c
	gcc -I ./include/ -o ./lib/TekUretim.o -c ./src/TekUretim.c
	gcc -I ./include/ -o ./lib/TekTaktik.o -c ./src/TekTaktik.c
	gcc -I ./include/ -o ./lib/CiftTaktik.o -c ./src/CiftTaktik.c
	gcc -I ./include/ -o ./lib/Koloni.o -c ./src/Koloni.c
	gcc -I ./include/ -o ./lib/Oyun.o -c ./src/Oyun.c
	gcc -I ./include/ -o ./bin/Test ./lib/Uretim.o ./lib/Taktik.o ./lib/CiftUretim.o ./lib/TekUretim.o ./lib/TekTaktik.o ./lib/CiftTaktik.o ./lib/Koloni.o ./lib/Oyun.o ./src/Test.c
		
calistir:
	./bin/Test