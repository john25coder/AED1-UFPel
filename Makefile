.PHONY: test clean

test:
	./tests/testar.sh
	$(MAKE) -C lista7_arvores test

clean:
	$(MAKE) -C lista3_tad_personagem clean
	$(MAKE) -C lista4_listas_encadeadas clean
	$(MAKE) -C lista7_arvores clean
