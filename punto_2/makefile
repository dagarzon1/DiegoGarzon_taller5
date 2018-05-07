cuerda.pdf:cuerda.txt
	python animacion.py
cuerda.txt:cuerda.x
	./cuerda.x > cuerda.txt
	rm cuerda.x
cuerda.x:
	c++ cuerda.cpp -o cuerda.x
clean:
	rm *.pdf
