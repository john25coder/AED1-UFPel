.PHONY: test clean

test:
	./tests/testar.sh

clean:
	$(MAKE) -C lista3_tad_personagem clean
	$(MAKE) -C lista4_listas_encadeadas clean
