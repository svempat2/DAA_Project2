CC = gcc

all:strassen tro lcs floyd 

vempati_pa2_stra.o: vempati_pa2_stra.c
	$(CC) -g -c vempati_pa2_stra.c

strassen: vempati_pa2_stra.o
	$(CC) -g vempati_pa2_stra.o -o strassen

vempati_pa2_tro.o: vempati_pa2_tro.c
	$(CC) -g -c vempati_pa2_tro.c

tro: vempati_pa2_tro.o
	$(CC) -g vempati_pa2_tro.o -o tro

vempati_pa2_lcs.o: vempati_pa2_lcs.c
	$(CC) -g -c vempati_pa2_lcs.c

lcs: vempati_pa2_lcs.o
	$(CC) -g vempati_pa2_lcs.o -o lcs

vempati_pa2_floyd.o: vempati_pa2_floyd.c
	$(CC) -g -c vempati_pa2_floyd.c

floyd: vempati_pa2_floyd.o
	$(CC) -g vempati_pa2_floyd.o -o floyd

clean:
	rm -f *.o strassen tro lcs floyd
