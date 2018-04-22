caos.pdf:caos.txt
	python caos.py
	rm caos.txt
caos.txt:caos.x
	./caos.x > caos.txt
	rm caos.x
caos.x:
	c++ caos.cpp -o caos.x
clean:
	rm caos.pdf
