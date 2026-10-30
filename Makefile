.PHONY: test clean

test:
	./tests/testar.sh
	$(MAKE) -C lista5_pilhas test
	$(MAKE) -C lista6_filas test
	$(MAKE) -C lista7_arvores test

clean:
	$(MAKE) -C lista3_tad_personagem clean
	$(MAKE) -C lista4_listas_encadeadas clean
	$(MAKE) -C lista5_pilhas clean
	$(MAKE) -C lista6_filas clean
	$(MAKE) -C lista7_arvores clean
